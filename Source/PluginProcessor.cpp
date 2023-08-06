/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FusionAudioProcessor::FusionAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
    treeState(*this, nullptr, "PARAMETER",
        {
            std::make_unique<AudioParameterFloat>(ATTACK_ID, ATTACK_NAME, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID, DECAY_NAME, 0.0, 2000.0, 40.0),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID, SUSTAIN_NAME, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID, RELEASE_NAME, 0.0, 2000.0, 100.0)
        }
    ),
    attack(20.0),
    decay(40.0),
    sustain(0.0),
    release(100.0)

#endif
{
    treeState.state = ValueTree("savedParams");

    synth.clearVoices();

    for (int i = 0; i < 5; i++) {
        synth.addVoice(new SynthVoice());
    }

    synth.clearSounds();
    synth.addSound(new SynthSound());
}

FusionAudioProcessor::~FusionAudioProcessor()
{
}

//==============================================================================
const juce::String FusionAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FusionAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FusionAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FusionAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FusionAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FusionAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FusionAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FusionAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String FusionAudioProcessor::getProgramName (int index)
{
    return {};
}

void FusionAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void FusionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    synth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void FusionAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FusionAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

double FusionAudioProcessor::getTreeStateValues(int token) {
    if (token == 0) {
        return attack;
    }
    else if (token == 1) {
        return decay;
    }
    else if (token == 2) {
        return sustain;
    }
    else if (token == 3) {
        return release;
    }
}

void FusionAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;

    attack = *treeState.getRawParameterValue(ATTACK_ID);
    decay = *treeState.getRawParameterValue(DECAY_ID);
    sustain = *treeState.getRawParameterValue(SUSTAIN_ID);
    release = *treeState.getRawParameterValue(RELEASE_ID);

    for (int i = 0; i < synth.getNumVoices(); i++) {
        if ((voice = dynamic_cast<SynthVoice*>(synth.getVoice(i)))) {
            voice->getEnvelope(attack, decay, sustain, release);
        }
    }

    buffer.clear();

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool FusionAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* FusionAudioProcessor::createEditor()
{
    return new FusionAudioProcessorEditor (*this);
}

//==============================================================================
void FusionAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    std::unique_ptr <XmlElement> xml(treeState.state.createXml());
    copyXmlToBinary(*xml, destData);
}

void FusionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr <XmlElement> params(getXmlFromBinary(data, sizeInBytes));

    if (params != nullptr) {
        if (params->hasTagName(treeState.state.getType())) {
            treeState.state = ValueTree::fromXml(*params);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FusionAudioProcessor();
}
