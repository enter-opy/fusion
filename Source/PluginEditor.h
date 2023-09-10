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
    Slider attackSlider_9;
    Slider attackSlider_10;
    Slider attackSlider_10;
    Slider attackSlider_11;
    Slider attackSlider_12;
    Slider attackSlider_13;
    Slider attackSlider_14;
    Slider attackSlider_15;
    Slider attackSlider_16;
    Slider attackSlider_17;
    Slider attackSlider_18;
    Slider attackSlider_19;
    Slider attackSlider_20;
    Slider attackSlider_20;
    Slider attackSlider_21;
    Slider attackSlider_22;
    Slider attackSlider_23;
    Slider attackSlider_24;

    Slider decaySlider_0;
    Slider decaySlider_1;
    Slider decaySlider_2;
    Slider decaySlider_3;
    Slider decaySlider_4;
    Slider decaySlider_5;
    Slider decaySlider_6;
    Slider decaySlider_7;
    Slider decaySlider_8;
    Slider decaySlider_9;
    Slider decaySlider_10;
    Slider decaySlider_10;
    Slider decaySlider_11;
    Slider decaySlider_12;
    Slider decaySlider_13;
    Slider decaySlider_14;
    Slider decaySlider_15;
    Slider decaySlider_16;
    Slider decaySlider_17;
    Slider decaySlider_18;
    Slider decaySlider_19;
    Slider decaySlider_20;
    Slider decaySlider_20;
    Slider decaySlider_21;
    Slider decaySlider_22;
    Slider decaySlider_23;
    Slider decaySlider_24;

    Slider sustainSlider_0;
    Slider sustainSlider_1;
    Slider sustainSlider_2;
    Slider sustainSlider_3;
    Slider sustainSlider_4;
    Slider sustainSlider_5;
    Slider sustainSlider_6;
    Slider sustainSlider_7;
    Slider sustainSlider_8;
    Slider sustainSlider_9;
    Slider sustainSlider_10;
    Slider sustainSlider_10;
    Slider sustainSlider_11;
    Slider sustainSlider_12;
    Slider sustainSlider_13;
    Slider sustainSlider_14;
    Slider sustainSlider_15;
    Slider sustainSlider_16;
    Slider sustainSlider_17;
    Slider sustainSlider_18;
    Slider sustainSlider_19;
    Slider sustainSlider_20;
    Slider sustainSlider_20;
    Slider sustainSlider_21;
    Slider sustainSlider_22;
    Slider sustainSlider_23;
    Slider sustainSlider_24;

    Slider releaseSlider_0;
    Slider releaseSlider_1;
    Slider releaseSlider_2;
    Slider releaseSlider_3;
    Slider releaseSlider_4;
    Slider releaseSlider_5;
    Slider releaseSlider_6;
    Slider releaseSlider_7;
    Slider releaseSlider_8;
    Slider releaseSlider_9;
    Slider releaseSlider_10;
    Slider releaseSlider_10;
    Slider releaseSlider_11;
    Slider releaseSlider_12;
    Slider releaseSlider_13;
    Slider releaseSlider_14;
    Slider releaseSlider_15;
    Slider releaseSlider_16;
    Slider releaseSlider_17;
    Slider releaseSlider_18;
    Slider releaseSlider_19;
    Slider releaseSlider_20;
    Slider releaseSlider_20;
    Slider releaseSlider_21;
    Slider releaseSlider_22;
    Slider releaseSlider_23;
    Slider releaseSlider_24;
public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> decayValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sustainValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessorEditor)
};
