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

    f0Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, F0_ID, f0Slider);
    f1Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, F1_ID, f1Slider);
    f2Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, F2_ID, f2Slider);
    f3Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, F3_ID, f3Slider);
    f4Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, F4_ID, f4Slider);
    f5Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, F5_ID, f5Slider);
    f6Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, F6_ID, f6Slider);

    f0Slider.setSliderStyle(Slider::LinearVertical);
    f0Slider.setRange(0.0, 1.0, 0.1);
    f0Slider.setValue(audioProcessor.getTreeStateValues("f0"));
    f0Slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&f0Slider);

    f1Slider.setSliderStyle(Slider::LinearVertical);
    f1Slider.setRange(0.0, 1.0, 0.1);
    f1Slider.setValue(audioProcessor.getTreeStateValues("f1"));
    f1Slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&f1Slider);

    f2Slider.setSliderStyle(Slider::LinearVertical);
    f2Slider.setRange(0.0, 1.0, 0.1);
    f2Slider.setValue(audioProcessor.getTreeStateValues("f2"));
    f2Slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&f2Slider);

    f3Slider.setSliderStyle(Slider::LinearVertical);
    f3Slider.setRange(0.0, 1.0, 0.1);
    f3Slider.setValue(audioProcessor.getTreeStateValues("f3"));
    f3Slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&f3Slider);

    f4Slider.setSliderStyle(Slider::LinearVertical);
    f4Slider.setRange(0.0, 1.0, 0.1);
    f4Slider.setValue(audioProcessor.getTreeStateValues("f4"));
    f4Slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&f4Slider);

    f5Slider.setSliderStyle(Slider::LinearVertical);
    f5Slider.setRange(0.0, 1.0, 0.1);
    f5Slider.setValue(audioProcessor.getTreeStateValues("f5"));
    f5Slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&f5Slider);

    f6Slider.setSliderStyle(Slider::LinearVertical);
    f6Slider.setRange(0.0, 1.0, 0.1);
    f6Slider.setValue(audioProcessor.getTreeStateValues("f6"));
    f6Slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&f6Slider);
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
    f0Slider.setBounds(10, 10, 10, 100);
    f1Slider.setBounds(40, 10, 10, 100);
    f2Slider.setBounds(70, 10, 10, 100);
    f3Slider.setBounds(100, 10, 10, 100);
    f4Slider.setBounds(130, 10, 10, 100);
    f5Slider.setBounds(160, 10, 10, 100);
    f6Slider.setBounds(190, 10, 10, 100);
}
