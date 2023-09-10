/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FusionAudioProcessorEditor::FusionAudioProcessorEditor (FusionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (800, 600);

    attackValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID, attackSlider);
    decayValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID, decaySlider);
    sustainValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID, sustainSlider);
    releaseValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID, releaseSlider);

    attackSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_0.setRange(0.0, 2000.0, 20.0);
    attackSlider_0.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_0);

    attackSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_1.setRange(0.0, 2000.0, 20.0);
    attackSlider_1.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_1);

    attackSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_2.setRange(0.0, 2000.0, 20.0);
    attackSlider_2.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_2);

    attackSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_3.setRange(0.0, 2000.0, 20.0);
    attackSlider_3.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_3);

    attackSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_4.setRange(0.0, 2000.0, 20.0);
    attackSlider_4.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_4);

    attackSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_5.setRange(0.0, 2000.0, 20.0);
    attackSlider_5.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_5);

    attackSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_6.setRange(0.0, 2000.0, 20.0);
    attackSlider_6.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_6);

    attackSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_7.setRange(0.0, 2000.0, 20.0);
    attackSlider_7.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_7);

    attackSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_8.setRange(0.0, 2000.0, 20.0);
    attackSlider_8.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_8);

    attackSlider_9.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_9.setRange(0.0, 2000.0, 20.0);
    attackSlider_9.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_9.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_9);

    attackSlider_10.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_10.setRange(0.0, 2000.0, 20.0);
    attackSlider_10.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_10.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_10);

    attackSlider_11.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_11.setRange(0.0, 2000.0, 20.0);
    attackSlider_11.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_11.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_11);

    attackSlider_12.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_12.setRange(0.0, 2000.0, 20.0);
    attackSlider_12.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_12.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_12);

    attackSlider_13.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_13.setRange(0.0, 2000.0, 20.0);
    attackSlider_13.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_13.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_13);

    attackSlider_14.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_14.setRange(0.0, 2000.0, 20.0);
    attackSlider_14.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_14.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_14);

    attackSlider_15.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_15.setRange(0.0, 2000.0, 20.0);
    attackSlider_15.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_15.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_15);

    attackSlider_16.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_16.setRange(0.0, 2000.0, 20.0);
    attackSlider_16.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_16.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_16);

    attackSlider_17.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_17.setRange(0.0, 2000.0, 20.0);
    attackSlider_17.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_17.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_17);

    attackSlider_18.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_18.setRange(0.0, 2000.0, 20.0);
    attackSlider_18.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_18.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_18);

    attackSlider_19.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_19.setRange(0.0, 2000.0, 20.0);
    attackSlider_19.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_19.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_19);

    attackSlider_20.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_20.setRange(0.0, 2000.0, 20.0);
    attackSlider_20.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_20.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_20);

    attackSlider_21.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_21.setRange(0.0, 2000.0, 20.0);
    attackSlider_21.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_21.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_21);

    attackSlider_22.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_22.setRange(0.0, 2000.0, 20.0);
    attackSlider_22.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_22.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_22);

    attackSlider_23.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_23.setRange(0.0, 2000.0, 20.0);
    attackSlider_23.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_23.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_23);

    attackSlider_24.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_24.setRange(0.0, 2000.0, 20.0);
    attackSlider_24.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_24.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_24);

    decaySlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider.setRange(0.0, 2000.0, 40.0);
    decaySlider.setValue(audioProcessor.getTreeStateValues(1));
    decaySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider);

    sustainSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider.setRange(0.0, 1.0, 0.0);
    sustainSlider.setValue(audioProcessor.getTreeStateValues(2));
    sustainSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider);

    releaseSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider.setRange(0.0, 2000.0, 100.0);
    releaseSlider.setValue(audioProcessor.getTreeStateValues(3));
    releaseSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider);
}

FusionAudioProcessorEditor::~FusionAudioProcessorEditor()
{
}

//==============================================================================
void FusionAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void FusionAudioProcessorEditor::resized()
{
    attackSlider.setBounds(10, 10, 100, 100);
    decaySlider.setBounds(120, 10, 100, 100);
    sustainSlider.setBounds(230, 10, 100, 100);
    releaseSlider.setBounds(340, 10, 100, 100);
}
