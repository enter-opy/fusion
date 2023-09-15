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
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_0;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_1;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_2;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_3;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_4;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_5;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_6;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_7;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue_8;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_0;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_1;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_2;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_3;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_4;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_5;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_6;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_7;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue_8;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_0;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_1;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_2;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_3;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_4;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_5;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_6;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_7;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue_8;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_0;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_1;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_2;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_3;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_4;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_5;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_6;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_7;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue_8;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_0;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_1;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_2;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_3;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_4;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_5;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_6;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_7;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> magnitudeValue_8;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_0;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_1;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_2;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_3;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_4;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_5;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_6;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_7;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inharmonicityValue_8;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessorEditor)
};
