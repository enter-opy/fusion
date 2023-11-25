/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "SynthVoice.h"

#define ATTACK_ID_0 "attack0"
#define ATTACK_NAME_0 "Attack"
#define ATTACK_ID_1 "attack1"
#define ATTACK_NAME_1 "Attack"
#define ATTACK_ID_2 "attack2"
#define ATTACK_NAME_2 "Attack"
#define ATTACK_ID_3 "attack3"
#define ATTACK_NAME_3 "Attack"
#define ATTACK_ID_4 "attack4"
#define ATTACK_NAME_4 "Attack"
#define ATTACK_ID_5 "attack5"
#define ATTACK_NAME_5 "Attack"
#define ATTACK_ID_6 "attack6"
#define ATTACK_NAME_6 "Attack"
#define ATTACK_ID_7 "attack7"
#define ATTACK_NAME_7 "Attack"
#define ATTACK_ID_8 "attack8"
#define ATTACK_NAME_8 "Attack"

#define DECAY_ID_0 "decay0"
#define DECAY_NAME_0 "Decay"
#define DECAY_ID_1 "decay1"
#define DECAY_NAME_1 "Decay"
#define DECAY_ID_2 "decay2"
#define DECAY_NAME_2 "Decay"
#define DECAY_ID_3 "decay3"
#define DECAY_NAME_3 "Decay"
#define DECAY_ID_4 "decay4"
#define DECAY_NAME_4 "Decay"
#define DECAY_ID_5 "decay5"
#define DECAY_NAME_5 "Decay"
#define DECAY_ID_6 "decay6"
#define DECAY_NAME_6 "Decay"
#define DECAY_ID_7 "decay7"
#define DECAY_NAME_7 "Decay"
#define DECAY_ID_8 "decay8"
#define DECAY_NAME_8 "Decay"

#define SUSTAIN_ID_0 "sustain0"
#define SUSTAIN_NAME_0 "Sustain"
#define SUSTAIN_ID_1 "sustain1"
#define SUSTAIN_NAME_1 "Sustain"
#define SUSTAIN_ID_2 "sustain2"
#define SUSTAIN_NAME_2 "Sustain"
#define SUSTAIN_ID_3 "sustain3"
#define SUSTAIN_NAME_3 "Sustain"
#define SUSTAIN_ID_4 "sustain4"
#define SUSTAIN_NAME_4 "Sustain"
#define SUSTAIN_ID_5 "sustain5"
#define SUSTAIN_NAME_5 "Sustain"
#define SUSTAIN_ID_6 "sustain6"
#define SUSTAIN_NAME_6 "Sustain"
#define SUSTAIN_ID_7 "sustain7"
#define SUSTAIN_NAME_7 "Sustain"
#define SUSTAIN_ID_8 "sustain8"
#define SUSTAIN_NAME_8 "Sustain"

#define RELEASE_ID_0 "release0"
#define RELEASE_NAME_0 "Release"
#define RELEASE_ID_1 "release1"
#define RELEASE_NAME_1 "Release"
#define RELEASE_ID_2 "release2"
#define RELEASE_NAME_2 "Release"
#define RELEASE_ID_3 "release3"
#define RELEASE_NAME_3 "Release"
#define RELEASE_ID_4 "release4"
#define RELEASE_NAME_4 "Release"
#define RELEASE_ID_5 "release5"
#define RELEASE_NAME_5 "Release"
#define RELEASE_ID_6 "release6"
#define RELEASE_NAME_6 "Release"
#define RELEASE_ID_7 "release7"
#define RELEASE_NAME_7 "Release"
#define RELEASE_ID_8 "release8"
#define RELEASE_NAME_8 "Release"

#define MAGNITUDE_ID_0 "magnitude0"
#define MAGNITUDE_NAME_0 "Magnitude"
#define MAGNITUDE_ID_1 "magnitude1"
#define MAGNITUDE_NAME_1 "Magnitude"
#define MAGNITUDE_ID_2 "magnitude2"
#define MAGNITUDE_NAME_2 "Magnitude"
#define MAGNITUDE_ID_3 "magnitude3"
#define MAGNITUDE_NAME_3 "Magnitude"
#define MAGNITUDE_ID_4 "magnitude4"
#define MAGNITUDE_NAME_4 "Magnitude"
#define MAGNITUDE_ID_5 "magnitude5"
#define MAGNITUDE_NAME_5 "Magnitude"
#define MAGNITUDE_ID_6 "magnitude6"
#define MAGNITUDE_NAME_6 "Magnitude"
#define MAGNITUDE_ID_7 "magnitude7"
#define MAGNITUDE_NAME_7 "Magnitude"
#define MAGNITUDE_ID_8 "magnitude8"
#define MAGNITUDE_NAME_8 "Magnitude"

#define PITCH_ID "pitch"
#define PITCH_NAME "Pitch"
#define PITCHDECAY_ID "pitchdecay"
#define PITCHDECAY_NAME "Decay"

#define DRIVE_ID "drive"
#define DRIVE_NAME "Drive"
#define DRIVEDECAY_ID "drivedecay"
#define DRIVEDECAY_NAME "Decay"

#define GAIN_ID "gain"
#define GAIN_NAME "Gain"

//==============================================================================
/**
*/
class FusionAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    FusionAudioProcessor();
    ~FusionAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    double getTreeStateValues(int);

    AudioProcessorValueTreeState treeState;

private:
    Synthesiser synth;
    SynthVoice* voice;

    double lastSampleRate;

    float attack_0;
    float attack_1;
    float attack_2;
    float attack_3;
    float attack_4;
    float attack_5;
    float attack_6;
    float attack_7;
    float attack_8;

    float decay_0;
    float decay_1;
    float decay_2;
    float decay_3;
    float decay_4;
    float decay_5;
    float decay_6;
    float decay_7;
    float decay_8;

    float sustain_0;
    float sustain_1;
    float sustain_2;
    float sustain_3;
    float sustain_4;
    float sustain_5;
    float sustain_6;
    float sustain_7;
    float sustain_8;

    float release_0;
    float release_1;
    float release_2;
    float release_3;
    float release_4;
    float release_5;
    float release_6;
    float release_7;
    float release_8;

    float magnitude_0;
    float magnitude_1;
    float magnitude_2;
    float magnitude_3;
    float magnitude_4;
    float magnitude_5;
    float magnitude_6;
    float magnitude_7;
    float magnitude_8;

    float pitch;
    float pitchDecay;

    float drive;
    float driveDecay;

    float gain;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessor)
};
