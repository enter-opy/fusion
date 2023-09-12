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

    Slider attackSlider_0;
    Slider attackSlider_1;
    Slider attackSlider_2;
    Slider attackSlider_3;
    Slider attackSlider_4;
    Slider attackSlider_5;
    Slider attackSlider_6;
    Slider attackSlider_7;
    Slider attackSlider_8;

    Slider decaySlider_0;
    Slider decaySlider_1;
    Slider decaySlider_2;
    Slider decaySlider_3;
    Slider decaySlider_4;
    Slider decaySlider_5;
    Slider decaySlider_6;
    Slider decaySlider_7;
    Slider decaySlider_8;

    Slider sustainSlider_0;
    Slider sustainSlider_1;
    Slider sustainSlider_2;
    Slider sustainSlider_3;
    Slider sustainSlider_4;
    Slider sustainSlider_5;
    Slider sustainSlider_6;
    Slider sustainSlider_7;
    Slider sustainSlider_8;

    Slider releaseSlider_0;
    Slider releaseSlider_1;
    Slider releaseSlider_2;
    Slider releaseSlider_3;
    Slider releaseSlider_4;
    Slider releaseSlider_5;
    Slider releaseSlider_6;
    Slider releaseSlider_7;
    Slider releaseSlider_8;

    Slider magnitudeSlider_0;
    Slider magnitudeSlider_1;
    Slider magnitudeSlider_2;
    Slider magnitudeSlider_3;
    Slider magnitudeSlider_4;
    Slider magnitudeSlider_5;
    Slider magnitudeSlider_6;
    Slider magnitudeSlider_7;
    Slider magnitudeSlider_8;

    Slider inharmonicitySlider_0;
    Slider inharmonicitySlider_1;
    Slider inharmonicitySlider_2;
    Slider inharmonicitySlider_3;
    Slider inharmonicitySlider_4;
    Slider inharmonicitySlider_5;
    Slider inharmonicitySlider_6;
    Slider inharmonicitySlider_7;
    Slider inharmonicitySlider_8;
   
public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessorEditor)
};
