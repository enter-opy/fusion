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

    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;
public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessorEditor)
};
