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
            std::make_unique<AudioParameterFloat>(ATTACK_ID_0, ATTACK_NAME_0, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_1, ATTACK_NAME_1, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_2, ATTACK_NAME_2, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_3, ATTACK_NAME_3, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_4, ATTACK_NAME_4, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_5, ATTACK_NAME_5, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_6, ATTACK_NAME_6, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_7, ATTACK_NAME_7, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(ATTACK_ID_8, ATTACK_NAME_8, 0.0, 2000.0, 20.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_0, DECAY_NAME_0, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_1, DECAY_NAME_1, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_2, DECAY_NAME_2, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_3, DECAY_NAME_3, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_4, DECAY_NAME_4, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_5, DECAY_NAME_5, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_6, DECAY_NAME_6, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_7, DECAY_NAME_7, 0.0, 2000.0, 100.0),
            std::make_unique<AudioParameterFloat>(DECAY_ID_8, DECAY_NAME_8, 0.0, 2000.0, 100.0),

            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_0, SUSTAIN_NAME_0, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_1, SUSTAIN_NAME_1, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_2, SUSTAIN_NAME_2, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_3, SUSTAIN_NAME_3, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_4, SUSTAIN_NAME_4, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_5, SUSTAIN_NAME_5, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_6, SUSTAIN_NAME_6, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_7, SUSTAIN_NAME_7, 0.1, 1.0, 0.5),
            std::make_unique<AudioParameterFloat>(SUSTAIN_ID_8, SUSTAIN_NAME_8, 0.1, 1.0, 0.5),

            std::make_unique<AudioParameterFloat>(RELEASE_ID_0, RELEASE_NAME_0, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_1, RELEASE_NAME_1, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_2, RELEASE_NAME_2, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_3, RELEASE_NAME_3, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_4, RELEASE_NAME_4, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_5, RELEASE_NAME_5, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_6, RELEASE_NAME_6, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_7, RELEASE_NAME_7, 0.0, 2000.0, 1000.0),
            std::make_unique<AudioParameterFloat>(RELEASE_ID_8, RELEASE_NAME_8, 0.0, 2000.0, 1000.0),

            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_0, MAGNITUDE_NAME_0, 0.0, 1.0, 1.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_1, MAGNITUDE_NAME_1, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_2, MAGNITUDE_NAME_2, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_3, MAGNITUDE_NAME_3, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_4, MAGNITUDE_NAME_4, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_5, MAGNITUDE_NAME_5, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_6, MAGNITUDE_NAME_6, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_7, MAGNITUDE_NAME_7, 0.0, 1.0, 0.0),
            std::make_unique<AudioParameterFloat>(MAGNITUDE_ID_8, MAGNITUDE_NAME_8, 0.0, 1.0, 0.0),

            std::make_unique<AudioParameterFloat>(PITCH_ID, PITCH_NAME, 0.0, 36.0, 0.0),
            std::make_unique<AudioParameterFloat>(PITCHDECAY_ID, PITCHDECAY_NAME, 0.0, 5000.0, 10.0),

            std::make_unique<AudioParameterFloat>(DRIVE_ID, DRIVE_NAME, 0.0, 20.0, 0.0),
            std::make_unique<AudioParameterFloat>(DRIVEDECAY_ID, DRIVEDECAY_NAME, 0.0, 5000.0, 10.0),

            std::make_unique<AudioParameterFloat>(GAIN_ID, GAIN_NAME, -20.0, 20.0, 0.0)
        }),
    attack_0(20.0),
    attack_1(20.0),
    attack_2(20.0),
    attack_3(20.0),
    attack_4(20.0),
    attack_5(20.0),
    attack_6(20.0),
    attack_7(20.0),
    attack_8(20.0),
    decay_0(100.0),
    decay_1(100.0),
    decay_2(100.0),
    decay_3(100.0),
    decay_4(100.0),
    decay_5(100.0),
    decay_6(100.0),
    decay_7(100.0),
    decay_8(100.0),
    sustain_0(0.5),
    sustain_1(0.5),
    sustain_2(0.5),
    sustain_3(0.5),
    sustain_4(0.5),
    sustain_5(0.5),
    sustain_6(0.5),
    sustain_7(0.5),
    sustain_8(0.5),
    release_0(1000.0),
    release_1(1000.0),
    release_2(1000.0),
    release_3(1000.0),
    release_4(1000.0),
    release_5(1000.0),
    release_6(1000.0),
    release_7(1000.0),
    release_8(1000.0),
    magnitude_0(1.0),
    magnitude_1(0.0),
    magnitude_2(0.0),
    magnitude_3(0.0),
    magnitude_4(0.0),
    magnitude_5(0.0),
    magnitude_6(0.0),
    magnitude_7(0.0),
    magnitude_8(0.0),
    pitch(0.0),
    pitchDecay(10.0),
    drive(0.0),
    driveDecay(10.0),
    gain(0.0)

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
        return attack_0;
    }
    else if (token == 1) {
        return attack_1;
    }
    else if (token == 2) {
        return attack_2;
    }
    else if (token == 3) {
        return attack_3;
    }
    else if (token == 4) {
        return attack_4;
    }
    else if (token == 5) {
        return attack_5;
    }
    else if (token == 6) {
        return attack_6;
    }
    else if (token == 7) {
        return attack_7;
    }
    else if (token == 8) {
        return attack_8;
    }

    else if (token == 10) {
        return decay_0;
    }
    else if (token == 11) {
        return decay_1;
    }
    else if (token == 12) {
        return decay_2;
    }
    else if (token == 13) {
        return decay_3;
    }
    else if (token == 14) {
        return decay_4;
    }
    else if (token == 15) {
        return decay_5;
    }
    else if (token == 16) {
        return decay_6;
    }
    else if (token == 17) {
        return decay_7;
    }
    else if (token == 18) {
        return decay_8;
    }

    else if (token == 20) {
        return sustain_0;
    }
    else if (token == 21) {
        return sustain_1;
    }
    else if (token == 22) {
        return sustain_2;
    }
    else if (token == 23) {
        return sustain_3;
    }
    else if (token == 24) {
        return sustain_4;
    }
    else if (token == 25) {
        return sustain_5;
    }
    else if (token == 26) {
        return sustain_6;
    }
    else if (token == 27) {
        return sustain_7;
    }
    else if (token == 28) {
        return sustain_8;
    }

    else if (token == 30) {
        return release_0;
    }
    else if (token == 31) {
        return release_1;
    }
    else if (token == 32) {
        return release_2;
    }
    else if (token == 33) {
        return release_3;
    }
    else if (token == 34) {
        return release_4;
    }
    else if (token == 35) {
        return release_5;
    }
    else if (token == 36) {
        return release_6;
    }
    else if (token == 37) {
        return release_7;
    }
    else if (token == 38) {
        return release_8;
    }

    else if (token == 40) {
        return magnitude_0;
    }
    else if (token == 41) {
        return magnitude_1;
    }
    else if (token == 42) {
        return magnitude_2;
    }
    else if (token == 43) {
        return magnitude_3;
    }
    else if (token == 44) {
        return magnitude_4;
    }
    else if (token == 45) {
        return magnitude_5;
    }
    else if (token == 46) {
        return magnitude_6;
    }
    else if (token == 47) {
        return magnitude_7;
    }
    else if (token == 48) {
        return magnitude_8;
    }

    else if (token == 100) {
        return pitch;
    }
    else if (token == 101) {
        return pitchDecay;
    }

    else if (token == 102) {
        return drive;
    }
    else if (token == 103) {
            return driveDecay;
    }

    else if (token == 104) {
        return gain;
    }
}

void FusionAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;

    attack_0 = *treeState.getRawParameterValue(ATTACK_ID_0);
    attack_1 = *treeState.getRawParameterValue(ATTACK_ID_1);
    attack_2 = *treeState.getRawParameterValue(ATTACK_ID_2);
    attack_3 = *treeState.getRawParameterValue(ATTACK_ID_3);
    attack_4 = *treeState.getRawParameterValue(ATTACK_ID_4);
    attack_5 = *treeState.getRawParameterValue(ATTACK_ID_5);
    attack_6 = *treeState.getRawParameterValue(ATTACK_ID_6);
    attack_7 = *treeState.getRawParameterValue(ATTACK_ID_7);
    attack_8 = *treeState.getRawParameterValue(ATTACK_ID_8);

    decay_0 = *treeState.getRawParameterValue(DECAY_ID_0);
    decay_1 = *treeState.getRawParameterValue(DECAY_ID_1);
    decay_2 = *treeState.getRawParameterValue(DECAY_ID_2);
    decay_3 = *treeState.getRawParameterValue(DECAY_ID_3);
    decay_4 = *treeState.getRawParameterValue(DECAY_ID_4);
    decay_5 = *treeState.getRawParameterValue(DECAY_ID_5);
    decay_6 = *treeState.getRawParameterValue(DECAY_ID_6);
    decay_7 = *treeState.getRawParameterValue(DECAY_ID_7);
    decay_8 = *treeState.getRawParameterValue(DECAY_ID_8);
    
    sustain_0 = *treeState.getRawParameterValue(SUSTAIN_ID_0);
    sustain_1 = *treeState.getRawParameterValue(SUSTAIN_ID_1);
    sustain_2 = *treeState.getRawParameterValue(SUSTAIN_ID_2);
    sustain_3 = *treeState.getRawParameterValue(SUSTAIN_ID_3);
    sustain_4 = *treeState.getRawParameterValue(SUSTAIN_ID_4);
    sustain_5 = *treeState.getRawParameterValue(SUSTAIN_ID_5);
    sustain_6 = *treeState.getRawParameterValue(SUSTAIN_ID_6);
    sustain_7 = *treeState.getRawParameterValue(SUSTAIN_ID_7);
    sustain_8 = *treeState.getRawParameterValue(SUSTAIN_ID_8);

    release_0 = *treeState.getRawParameterValue(RELEASE_ID_0);
    release_1 = *treeState.getRawParameterValue(RELEASE_ID_1);
    release_2 = *treeState.getRawParameterValue(RELEASE_ID_2);
    release_3 = *treeState.getRawParameterValue(RELEASE_ID_3);
    release_4 = *treeState.getRawParameterValue(RELEASE_ID_4);
    release_5 = *treeState.getRawParameterValue(RELEASE_ID_5);
    release_6 = *treeState.getRawParameterValue(RELEASE_ID_6);
    release_7 = *treeState.getRawParameterValue(RELEASE_ID_7);
    release_8 = *treeState.getRawParameterValue(RELEASE_ID_8);

    magnitude_0 = *treeState.getRawParameterValue(MAGNITUDE_ID_0);
    magnitude_1 = *treeState.getRawParameterValue(MAGNITUDE_ID_1);
    magnitude_2 = *treeState.getRawParameterValue(MAGNITUDE_ID_2);
    magnitude_3 = *treeState.getRawParameterValue(MAGNITUDE_ID_3);
    magnitude_4 = *treeState.getRawParameterValue(MAGNITUDE_ID_4);
    magnitude_5 = *treeState.getRawParameterValue(MAGNITUDE_ID_5);
    magnitude_6 = *treeState.getRawParameterValue(MAGNITUDE_ID_6);
    magnitude_7 = *treeState.getRawParameterValue(MAGNITUDE_ID_7);
    magnitude_8 = *treeState.getRawParameterValue(MAGNITUDE_ID_8);

    pitch = *treeState.getRawParameterValue(PITCH_ID);
    pitchDecay = *treeState.getRawParameterValue(PITCHDECAY_ID);

    drive = *treeState.getRawParameterValue(DRIVE_ID);
    driveDecay = *treeState.getRawParameterValue(DRIVEDECAY_ID);

    gain = *treeState.getRawParameterValue(GAIN_ID);

    for (int i = 0; i < synth.getNumVoices(); i++) {
        if ((voice = dynamic_cast<SynthVoice*>(synth.getVoice(i)))) {
            voice->getPitchParameters(pitch, pitchDecay);
            voice->getDriveParameters(drive, driveDecay);
            voice->getParameters_0(attack_0, decay_0, sustain_0, release_0, magnitude_0);
            voice->getParameters_1(attack_1, decay_1, sustain_1, release_1, magnitude_1);
            voice->getParameters_2(attack_2, decay_2, sustain_2, release_2, magnitude_2);
            voice->getParameters_3(attack_3, decay_3, sustain_3, release_3, magnitude_3);
            voice->getParameters_4(attack_4, decay_4, sustain_4, release_4, magnitude_4);
            voice->getParameters_5(attack_5, decay_5, sustain_5, release_5, magnitude_5);
            voice->getParameters_6(attack_6, decay_6, sustain_6, release_6, magnitude_6);
            voice->getParameters_7(attack_7, decay_7, sustain_7, release_7, magnitude_7);
            voice->getParameters_8(attack_8, decay_8, sustain_8, release_8, magnitude_8);
        }
    }

    buffer.clear();

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

    buffer.applyGain(Decibels::decibelsToGain(gain));
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
