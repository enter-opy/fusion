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

    attackSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider.setRange(0.0, 2000.0, 20.0);
    attackSlider.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider);

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
