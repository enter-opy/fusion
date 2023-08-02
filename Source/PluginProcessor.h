/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "SynthVoice.h"

#define F0_ID "f0"
#define F0_NAME "Frequency0"

#define F1_ID "f1"
#define F1_NAME "Frequency1"

#define F2_ID "f2"
#define F2_NAME "Frequency2"

#define F3_ID "f3"
#define F3_NAME "Frequency3"

#define F4_ID "f4"
#define F4_NAME "Frequency4"

#define F5_ID "f5"
#define F5_NAME "Frequency5"

#define F6_ID "f6"
#define F6_NAME "Frequency6"

#define F7_ID "f7"
#define F7_NAME "Frequency7"

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

    double getTreeStateValues(char*);

    AudioProcessorValueTreeState treeState;

private:
    Synthesiser synth;
    SynthVoice* voice;

    double lastSampleRate;

    float f0Value;
    float f1Value;
    float f2Value;
    float f3Value;
    float f4Value;
    float f5Value;
    float f6Value;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessor)
};
