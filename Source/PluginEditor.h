/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class FusionAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FusionAudioProcessorEditor (FusionAudioProcessor&);
    ~FusionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    FusionAudioProcessor& audioProcessor;

    Slider f0Slider;
    Slider f1Slider;
    Slider f2Slider;
    Slider f3Slider;
    Slider f4Slider;
    Slider f5Slider;
    Slider f6Slider;
public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> f0Value;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> f1Value;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> f2Value;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> f3Value;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> f4Value;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> f5Value;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> f6Value;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessorEditor)
};
