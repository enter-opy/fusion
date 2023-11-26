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
    setSize (600, 730);

    attackValue_0 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_0, attackSlider_0);
    attackValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_1, attackSlider_1);
    attackValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_2, attackSlider_2);
    attackValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_3, attackSlider_3);
    attackValue_4 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_4, attackSlider_4);
    attackValue_5 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_5, attackSlider_5);
    attackValue_6 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_6, attackSlider_6);
    attackValue_7 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_7, attackSlider_7);
    attackValue_8 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ATTACK_ID_8, attackSlider_8);

    decayValue_0 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_0, decaySlider_0);
    decayValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_1, decaySlider_1);
    decayValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_2, decaySlider_2);
    decayValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_3, decaySlider_3);
    decayValue_4 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_4, decaySlider_4);
    decayValue_5 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_5, decaySlider_5);
    decayValue_6 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_6, decaySlider_6);
    decayValue_7 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_7, decaySlider_7);
    decayValue_8 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DECAY_ID_8, decaySlider_8);

    sustainValue_0 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_0, sustainSlider_0);
    sustainValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_1, sustainSlider_1);
    sustainValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_2, sustainSlider_2);
    sustainValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_3, sustainSlider_3);
    sustainValue_4 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_4, sustainSlider_4);
    sustainValue_5 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_5, sustainSlider_5);
    sustainValue_6 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_6, sustainSlider_6);
    sustainValue_7 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_7, sustainSlider_7);
    sustainValue_8 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SUSTAIN_ID_8, sustainSlider_8);

    releaseValue_0 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_0, releaseSlider_0);
    releaseValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_1, releaseSlider_1);
    releaseValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_2, releaseSlider_2);
    releaseValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_3, releaseSlider_3);
    releaseValue_4 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_4, releaseSlider_4);
    releaseValue_5 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_5, releaseSlider_5);
    releaseValue_6 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_6, releaseSlider_6);
    releaseValue_7 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_7, releaseSlider_7);
    releaseValue_8 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RELEASE_ID_8, releaseSlider_8);

    magnitudeValue_0 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_0, magnitudeSlider_0);
    magnitudeValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_1, magnitudeSlider_1);
    magnitudeValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_2, magnitudeSlider_2);
    magnitudeValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_3, magnitudeSlider_3);
    magnitudeValue_4 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_4, magnitudeSlider_4);
    magnitudeValue_5 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_5, magnitudeSlider_5);
    magnitudeValue_6 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_6, magnitudeSlider_6);
    magnitudeValue_7 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_7, magnitudeSlider_7);
    magnitudeValue_8 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, MAGNITUDE_ID_8, magnitudeSlider_8);

    pitchValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, PITCH_ID, pitchSlider);
    pitchDecayValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, PITCHDECAY_ID, pitchDecaySlider);

    driveValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DRIVE_ID, driveSlider);
    driveDecayValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DRIVEDECAY_ID, driveDecaySlider);

    gainValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, GAIN_ID, gainSlider);

    attackSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_0.setRange(0.0, 2000.0, 1.0);
    attackSlider_0.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_0.setLookAndFeel(&attackSlider0LookAndFeel);
    addAndMakeVisible(&attackSlider_0);

    attackSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_1.setRange(0.0, 2000.0, 1.0);
    attackSlider_1.setValue(audioProcessor.getTreeStateValues(1));
    attackSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_1.setLookAndFeel(&attackSlider1LookAndFeel);
    addAndMakeVisible(&attackSlider_1);

    attackSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_2.setRange(0.0, 2000.0, 1.0);
    attackSlider_2.setValue(audioProcessor.getTreeStateValues(2));
    attackSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_2.setLookAndFeel(&attackSlider2LookAndFeel);
    addAndMakeVisible(&attackSlider_2);

    attackSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_3.setRange(0.0, 2000.0, 1.0);
    attackSlider_3.setValue(audioProcessor.getTreeStateValues(3));
    attackSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_3.setLookAndFeel(&attackSlider3LookAndFeel);
    addAndMakeVisible(&attackSlider_3);

    attackSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_4.setRange(0.0, 2000.0, 1.0);
    attackSlider_4.setValue(audioProcessor.getTreeStateValues(4));
    attackSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_4.setLookAndFeel(&attackSlider4LookAndFeel);
    addAndMakeVisible(&attackSlider_4);

    attackSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_5.setRange(0.0, 2000.0, 1.0);
    attackSlider_5.setValue(audioProcessor.getTreeStateValues(5));
    attackSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_5.setLookAndFeel(&attackSlider5LookAndFeel);
    addAndMakeVisible(&attackSlider_5);

    attackSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_6.setRange(0.0, 2000.0, 1.0);
    attackSlider_6.setValue(audioProcessor.getTreeStateValues(6));
    attackSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_6.setLookAndFeel(&attackSlider6LookAndFeel);
    addAndMakeVisible(&attackSlider_6);

    attackSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_7.setRange(0.0, 2000.0, 1.0);
    attackSlider_7.setValue(audioProcessor.getTreeStateValues(7));
    attackSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_7.setLookAndFeel(&attackSlider7LookAndFeel);
    addAndMakeVisible(&attackSlider_7);

    attackSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_8.setRange(0.0, 2000.0, 1.0);
    attackSlider_8.setValue(audioProcessor.getTreeStateValues(8));
    attackSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    attackSlider_8.setLookAndFeel(&attackSlider8LookAndFeel);
    addAndMakeVisible(&attackSlider_8);

    decaySlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_0.setRange(0.0, 2000.0, 1.0);
    decaySlider_0.setValue(audioProcessor.getTreeStateValues(10));
    decaySlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_0.setLookAndFeel(&decaySlider0LookAndFeel);
    addAndMakeVisible(&decaySlider_0);

    decaySlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_1.setRange(0.0, 2000.0, 1.0);
    decaySlider_1.setValue(audioProcessor.getTreeStateValues(11));
    decaySlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_1.setLookAndFeel(&decaySlider1LookAndFeel);
    addAndMakeVisible(&decaySlider_1);

    decaySlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_2.setRange(0.0, 2000.0, 1.0);
    decaySlider_2.setValue(audioProcessor.getTreeStateValues(12));
    decaySlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_2.setLookAndFeel(&decaySlider2LookAndFeel);
    addAndMakeVisible(&decaySlider_2);

    decaySlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_3.setRange(0.0, 2000.0, 1.0);
    decaySlider_3.setValue(audioProcessor.getTreeStateValues(13));
    decaySlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_3.setLookAndFeel(&decaySlider3LookAndFeel);
    addAndMakeVisible(&decaySlider_3);

    decaySlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_4.setRange(0.0, 2000.0, 1.0);
    decaySlider_4.setValue(audioProcessor.getTreeStateValues(14));
    decaySlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_4.setLookAndFeel(&decaySlider4LookAndFeel);
    addAndMakeVisible(&decaySlider_4);

    decaySlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_5.setRange(0.0, 2000.0, 1.0);
    decaySlider_5.setValue(audioProcessor.getTreeStateValues(15));
    decaySlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_5.setLookAndFeel(&decaySlider5LookAndFeel);
    addAndMakeVisible(&decaySlider_5);

    decaySlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_6.setRange(0.0, 2000.0, 1.0);
    decaySlider_6.setValue(audioProcessor.getTreeStateValues(16));
    decaySlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_6.setLookAndFeel(&decaySlider6LookAndFeel);
    addAndMakeVisible(&decaySlider_6);

    decaySlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_7.setRange(0.0, 2000.0, 1.0);
    decaySlider_7.setValue(audioProcessor.getTreeStateValues(17));
    decaySlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_7.setLookAndFeel(&decaySlider7LookAndFeel);
    addAndMakeVisible(&decaySlider_7);

    decaySlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_8.setRange(0.0, 2000.0, 1.0);
    decaySlider_8.setValue(audioProcessor.getTreeStateValues(18));
    decaySlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider_8.setLookAndFeel(&decaySlider8LookAndFeel);
    addAndMakeVisible(&decaySlider_8);

    sustainSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_0.setRange(0.0, 1.0, 0.01);
    sustainSlider_0.setValue(audioProcessor.getTreeStateValues(20));
    sustainSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_0.setLookAndFeel(&sustainSlider0LookAndFeel);
    addAndMakeVisible(&sustainSlider_0);

    sustainSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_1.setRange(0.0, 1.0, 0.01);
    sustainSlider_1.setValue(audioProcessor.getTreeStateValues(21));
    sustainSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_1.setLookAndFeel(&sustainSlider1LookAndFeel);
    addAndMakeVisible(&sustainSlider_1);

    sustainSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_2.setRange(0.0, 1.0, 0.01);
    sustainSlider_2.setValue(audioProcessor.getTreeStateValues(22));
    sustainSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_2.setLookAndFeel(&sustainSlider2LookAndFeel);
    addAndMakeVisible(&sustainSlider_2);

    sustainSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_3.setRange(0.0, 1.0, 0.01);
    sustainSlider_3.setValue(audioProcessor.getTreeStateValues(23));
    sustainSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_3.setLookAndFeel(&sustainSlider3LookAndFeel);
    addAndMakeVisible(&sustainSlider_3);

    sustainSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_4.setRange(0.0, 1.0, 0.01);
    sustainSlider_4.setValue(audioProcessor.getTreeStateValues(24));
    sustainSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_4.setLookAndFeel(&sustainSlider4LookAndFeel);
    addAndMakeVisible(&sustainSlider_4);

    sustainSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_5.setRange(0.0, 1.0, 0.01);
    sustainSlider_5.setValue(audioProcessor.getTreeStateValues(25));
    sustainSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_5.setLookAndFeel(&sustainSlider5LookAndFeel);
    addAndMakeVisible(&sustainSlider_5);

    sustainSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_6.setRange(0.0, 1.0, 0.01);
    sustainSlider_6.setValue(audioProcessor.getTreeStateValues(26));
    sustainSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_6.setLookAndFeel(&sustainSlider6LookAndFeel);
    addAndMakeVisible(&sustainSlider_6);

    sustainSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_7.setRange(0.0, 1.0, 0.01);
    sustainSlider_7.setValue(audioProcessor.getTreeStateValues(27));
    sustainSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_7.setLookAndFeel(&sustainSlider7LookAndFeel);
    addAndMakeVisible(&sustainSlider_7);

    sustainSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_8.setRange(0.0, 1.0, 0.01);
    sustainSlider_8.setValue(audioProcessor.getTreeStateValues(28));
    sustainSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sustainSlider_8.setLookAndFeel(&sustainSlider8LookAndFeel);
    addAndMakeVisible(&sustainSlider_8);

    releaseSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_0.setRange(0.0, 2000.0, 1.0);
    releaseSlider_0.setValue(audioProcessor.getTreeStateValues(30));
    releaseSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_0.setLookAndFeel(&releaseSlider0LookAndFeel);
    addAndMakeVisible(&releaseSlider_0);

    releaseSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_1.setRange(0.0, 2000.0, 1.0);
    releaseSlider_1.setValue(audioProcessor.getTreeStateValues(31));
    releaseSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_1.setLookAndFeel(&releaseSlider1LookAndFeel);
    addAndMakeVisible(&releaseSlider_1);

    releaseSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_2.setRange(0.0, 2000.0, 1.0);
    releaseSlider_2.setValue(audioProcessor.getTreeStateValues(32));
    releaseSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_2.setLookAndFeel(&releaseSlider2LookAndFeel);
    addAndMakeVisible(&releaseSlider_2);

    releaseSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_3.setRange(0.0, 2000.0, 1.0);
    releaseSlider_3.setValue(audioProcessor.getTreeStateValues(33));
    releaseSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_3.setLookAndFeel(&releaseSlider3LookAndFeel);
    addAndMakeVisible(&releaseSlider_3);

    releaseSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_4.setRange(0.0, 2000.0, 1.0);
    releaseSlider_4.setValue(audioProcessor.getTreeStateValues(34));
    releaseSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_4.setLookAndFeel(&releaseSlider4LookAndFeel);
    addAndMakeVisible(&releaseSlider_4);

    releaseSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_5.setRange(0.0, 2000.0, 1.0);
    releaseSlider_5.setValue(audioProcessor.getTreeStateValues(35));
    releaseSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_5.setLookAndFeel(&releaseSlider5LookAndFeel);
    addAndMakeVisible(&releaseSlider_5);

    releaseSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_6.setRange(0.0, 2000.0, 1.0);
    releaseSlider_6.setValue(audioProcessor.getTreeStateValues(36));
    releaseSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_6.setLookAndFeel(&releaseSlider6LookAndFeel);
    addAndMakeVisible(&releaseSlider_6);

    releaseSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_7.setRange(0.0, 2000.0, 1.0);
    releaseSlider_7.setValue(audioProcessor.getTreeStateValues(37));
    releaseSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_7.setLookAndFeel(&releaseSlider7LookAndFeel);
    addAndMakeVisible(&releaseSlider_7);

    releaseSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_8.setRange(0.0, 2000.0, 1.0);
    releaseSlider_8.setValue(audioProcessor.getTreeStateValues(38));
    releaseSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    releaseSlider_8.setLookAndFeel(&releaseSlider8LookAndFeel);
    addAndMakeVisible(&releaseSlider_8);

    magnitudeSlider_0.setSliderStyle(Slider::LinearVertical);
    magnitudeSlider_0.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_0.setValue(audioProcessor.getTreeStateValues(40));
    magnitudeSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_0.setLookAndFeel(&magnitudeSlider0LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_0);

    magnitudeSlider_1.setSliderStyle(Slider::LinearHorizontal);
    magnitudeSlider_1.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_1.setValue(audioProcessor.getTreeStateValues(41));
    magnitudeSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_1.setLookAndFeel(&magnitudeSlider1LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_1);

    magnitudeSlider_2.setSliderStyle(Slider::LinearVertical);
    magnitudeSlider_2.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_2.setValue(audioProcessor.getTreeStateValues(42));
    magnitudeSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_2.setLookAndFeel(&magnitudeSlider2LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_2);

    magnitudeSlider_3.setSliderStyle(Slider::LinearVertical);
    magnitudeSlider_3.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_3.setValue(audioProcessor.getTreeStateValues(43));
    magnitudeSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_3.setLookAndFeel(&magnitudeSlider3LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_3);

    magnitudeSlider_4.setSliderStyle(Slider::LinearHorizontal);
    magnitudeSlider_4.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_4.setValue(audioProcessor.getTreeStateValues(44));
    magnitudeSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_4.setLookAndFeel(&magnitudeSlider4LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_4);

    magnitudeSlider_5.setSliderStyle(Slider::LinearVertical);
    magnitudeSlider_5.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_5.setValue(audioProcessor.getTreeStateValues(45));
    magnitudeSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_5.setLookAndFeel(&magnitudeSlider5LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_5);

    magnitudeSlider_6.setSliderStyle(Slider::LinearVertical);
    magnitudeSlider_6.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_6.setValue(audioProcessor.getTreeStateValues(46));
    magnitudeSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_6.setLookAndFeel(&magnitudeSlider6LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_6);

    magnitudeSlider_7.setSliderStyle(Slider::LinearHorizontal);
    magnitudeSlider_7.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_7.setValue(audioProcessor.getTreeStateValues(47));
    magnitudeSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_7.setLookAndFeel(&magnitudeSlider7LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_7);

    magnitudeSlider_8.setSliderStyle(Slider::LinearVertical);
    magnitudeSlider_8.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_8.setValue(audioProcessor.getTreeStateValues(48));
    magnitudeSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    magnitudeSlider_8.setLookAndFeel(&magnitudeSlider8LookAndFeel);
    addAndMakeVisible(&magnitudeSlider_8);

    pitchSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    pitchSlider.setRange(0.0, 36.0, 1.0);
    pitchSlider.setValue(audioProcessor.getTreeStateValues(100));
    pitchSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    pitchSlider.setLookAndFeel(&pitchSliderLookAndFeel);
    addAndMakeVisible(&pitchSlider);

    pitchDecaySlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    pitchDecaySlider.setRange(0.0, 5000.0, 0.01);
    pitchDecaySlider.setSkewFactorFromMidPoint(100.0);
    pitchDecaySlider.setValue(audioProcessor.getTreeStateValues(101));
    pitchDecaySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    pitchDecaySlider.setLookAndFeel(&pitchDecaySliderLookAndFeel);
    addAndMakeVisible(&pitchDecaySlider);

    driveSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    driveSlider.setRange(0.0, 48.0, 0.1);
    driveSlider.setValue(audioProcessor.getTreeStateValues(102));
    driveSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    driveSlider.setLookAndFeel(&driveSliderLookAndFeel);
    addAndMakeVisible(&driveSlider);

    driveDecaySlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    driveDecaySlider.setRange(0.0, 5000.0, 0.001);
    driveDecaySlider.setSkewFactorFromMidPoint(100.0);
    driveDecaySlider.setValue(audioProcessor.getTreeStateValues(103));
    driveDecaySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    driveDecaySlider.setLookAndFeel(&driveDecaySliderLookAndFeel);
    addAndMakeVisible(&driveDecaySlider);

    gainSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    gainSlider.setRange(-20.0, 20.0, 0.01);
    gainSlider.setValue(audioProcessor.getTreeStateValues(104));
    gainSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    gainSlider.setLookAndFeel(&gainSliderLookAndFeel);
    addAndMakeVisible(&gainSlider);

    attackSlider0Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider0Label.setJustificationType(Justification::centred);
    attackSlider0Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider0Label);

    attackSlider1Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider1Label.setJustificationType(Justification::centred);
    attackSlider1Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider1Label);

    attackSlider2Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider2Label.setJustificationType(Justification::centred);
    attackSlider2Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider2Label);

    attackSlider3Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider3Label.setJustificationType(Justification::centred);
    attackSlider3Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider3Label);

    attackSlider4Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider4Label.setJustificationType(Justification::centred);
    attackSlider4Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider4Label);

    attackSlider5Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider5Label.setJustificationType(Justification::centred);
    attackSlider5Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider5Label);

    attackSlider6Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider6Label.setJustificationType(Justification::centred);
    attackSlider6Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider6Label);

    attackSlider7Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider7Label.setJustificationType(Justification::centred);
    attackSlider7Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider7Label);

    attackSlider8Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    attackSlider8Label.setJustificationType(Justification::centred);
    attackSlider8Label.setText("Attack", dontSendNotification);
    addAndMakeVisible(&attackSlider8Label);

    decaySlider0Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider0Label.setJustificationType(Justification::centred);
    decaySlider0Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider0Label);

    decaySlider1Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider1Label.setJustificationType(Justification::centred);
    decaySlider1Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider1Label);

    decaySlider2Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider2Label.setJustificationType(Justification::centred);
    decaySlider2Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider2Label);

    decaySlider3Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider3Label.setJustificationType(Justification::centred);
    decaySlider3Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider3Label);

    decaySlider4Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider4Label.setJustificationType(Justification::centred);
    decaySlider4Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider4Label);

    decaySlider5Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider5Label.setJustificationType(Justification::centred);
    decaySlider5Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider5Label);

    decaySlider6Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider6Label.setJustificationType(Justification::centred);
    decaySlider6Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider6Label);

    decaySlider7Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider7Label.setJustificationType(Justification::centred);
    decaySlider7Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider7Label);

    decaySlider8Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    decaySlider8Label.setJustificationType(Justification::centred);
    decaySlider8Label.setText("Decay", dontSendNotification);
    addAndMakeVisible(&decaySlider8Label);

    sustainSlider0Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider0Label.setJustificationType(Justification::centred);
    sustainSlider0Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider0Label);

    sustainSlider1Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider1Label.setJustificationType(Justification::centred);
    sustainSlider1Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider1Label);

    sustainSlider2Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider2Label.setJustificationType(Justification::centred);
    sustainSlider2Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider2Label);

    sustainSlider3Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider3Label.setJustificationType(Justification::centred);
    sustainSlider3Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider3Label);

    sustainSlider4Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider4Label.setJustificationType(Justification::centred);
    sustainSlider4Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider4Label);

    sustainSlider5Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider5Label.setJustificationType(Justification::centred);
    sustainSlider5Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider5Label);

    sustainSlider6Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider6Label.setJustificationType(Justification::centred);
    sustainSlider6Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider6Label);

    sustainSlider7Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider7Label.setJustificationType(Justification::centred);
    sustainSlider7Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider7Label);

    sustainSlider8Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    sustainSlider8Label.setJustificationType(Justification::centred);
    sustainSlider8Label.setText("Sustain", dontSendNotification);
    addAndMakeVisible(&sustainSlider8Label);

    releaseSlider0Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider0Label.setJustificationType(Justification::centred);
    releaseSlider0Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider0Label);

    releaseSlider1Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider1Label.setJustificationType(Justification::centred);
    releaseSlider1Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider1Label);

    releaseSlider2Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider2Label.setJustificationType(Justification::centred);
    releaseSlider2Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider2Label);

    releaseSlider3Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider3Label.setJustificationType(Justification::centred);
    releaseSlider3Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider3Label);

    releaseSlider4Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider4Label.setJustificationType(Justification::centred);
    releaseSlider4Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider4Label);

    releaseSlider5Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider5Label.setJustificationType(Justification::centred);
    releaseSlider5Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider5Label);

    releaseSlider6Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider6Label.setJustificationType(Justification::centred);
    releaseSlider6Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider6Label);

    releaseSlider7Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider7Label.setJustificationType(Justification::centred);
    releaseSlider7Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider7Label);

    releaseSlider8Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    releaseSlider8Label.setJustificationType(Justification::centred);
    releaseSlider8Label.setText("Release", dontSendNotification);
    addAndMakeVisible(&releaseSlider8Label);

    attackSlider0Label.setFont(Font(customFont).withHeight(15));
    attackSlider1Label.setFont(Font(customFont).withHeight(15));
    attackSlider2Label.setFont(Font(customFont).withHeight(15));
    attackSlider3Label.setFont(Font(customFont).withHeight(15));
    attackSlider4Label.setFont(Font(customFont).withHeight(15));
    attackSlider5Label.setFont(Font(customFont).withHeight(15));
    attackSlider6Label.setFont(Font(customFont).withHeight(15));
    attackSlider7Label.setFont(Font(customFont).withHeight(15));
    attackSlider8Label.setFont(Font(customFont).withHeight(15));

    decaySlider0Label.setFont(Font(customFont).withHeight(15));
    decaySlider1Label.setFont(Font(customFont).withHeight(15));
    decaySlider2Label.setFont(Font(customFont).withHeight(15));
    decaySlider3Label.setFont(Font(customFont).withHeight(15));
    decaySlider4Label.setFont(Font(customFont).withHeight(15));
    decaySlider5Label.setFont(Font(customFont).withHeight(15));
    decaySlider6Label.setFont(Font(customFont).withHeight(15));
    decaySlider7Label.setFont(Font(customFont).withHeight(15));
    decaySlider8Label.setFont(Font(customFont).withHeight(15));

    sustainSlider0Label.setFont(Font(customFont).withHeight(15));
    sustainSlider1Label.setFont(Font(customFont).withHeight(15));
    sustainSlider2Label.setFont(Font(customFont).withHeight(15));
    sustainSlider3Label.setFont(Font(customFont).withHeight(15));
    sustainSlider4Label.setFont(Font(customFont).withHeight(15));
    sustainSlider5Label.setFont(Font(customFont).withHeight(15));
    sustainSlider6Label.setFont(Font(customFont).withHeight(15));
    sustainSlider7Label.setFont(Font(customFont).withHeight(15));
    sustainSlider8Label.setFont(Font(customFont).withHeight(15));

    releaseSlider0Label.setFont(Font(customFont).withHeight(15));
    releaseSlider1Label.setFont(Font(customFont).withHeight(15));
    releaseSlider2Label.setFont(Font(customFont).withHeight(15));
    releaseSlider3Label.setFont(Font(customFont).withHeight(15));
    releaseSlider4Label.setFont(Font(customFont).withHeight(15));
    releaseSlider5Label.setFont(Font(customFont).withHeight(15));
    releaseSlider6Label.setFont(Font(customFont).withHeight(15));
    releaseSlider7Label.setFont(Font(customFont).withHeight(15));
    releaseSlider8Label.setFont(Font(customFont).withHeight(15));

    oscillator0Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator0Label.setJustificationType(Justification::centred);
    oscillator0Label.setText("OSC 1", dontSendNotification);
    oscillator0Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator0Label);

    oscillator1Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator1Label.setJustificationType(Justification::centred);
    oscillator1Label.setText("OSC 2", dontSendNotification);
    oscillator1Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator1Label);

    oscillator2Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator2Label.setJustificationType(Justification::centred);
    oscillator2Label.setText("OSC 3", dontSendNotification);
    oscillator2Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator2Label);

    oscillator3Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator3Label.setJustificationType(Justification::centred);
    oscillator3Label.setText("OSC 4", dontSendNotification);
    oscillator3Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator3Label);

    oscillator4Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator4Label.setJustificationType(Justification::centred);
    oscillator4Label.setText("OSC 5", dontSendNotification);
    oscillator4Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator4Label);

    oscillator5Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator5Label.setJustificationType(Justification::centred);
    oscillator5Label.setText("OSC 6", dontSendNotification);
    oscillator5Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator5Label);

    oscillator6Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator6Label.setJustificationType(Justification::centred);
    oscillator6Label.setText("OSC 7", dontSendNotification);
    oscillator6Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator6Label);

    oscillator7Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator7Label.setJustificationType(Justification::centred);
    oscillator7Label.setText("OSC 8", dontSendNotification);
    oscillator7Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator7Label);

    oscillator8Label.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    oscillator8Label.setJustificationType(Justification::centred);
    oscillator8Label.setText("OSC 9", dontSendNotification);
    oscillator8Label.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&oscillator8Label);

    pitchLabel.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    pitchLabel.setJustificationType(Justification::left);
    pitchLabel.setText("Pitch", dontSendNotification);
    pitchLabel.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&pitchLabel);

    driveLabel.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    driveLabel.setJustificationType(Justification::left);
    driveLabel.setText("Drive", dontSendNotification);
    driveLabel.setFont(Font(customFont).withHeight(20));
    addAndMakeVisible(&driveLabel);

    volumeLabel.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    volumeLabel.setJustificationType(Justification::centred);
    volumeLabel.setText("Volume", dontSendNotification);
    volumeLabel.setFont(Font(customFont).withHeight(15));
    addAndMakeVisible(&volumeLabel);

    pitchSliderLabel.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    pitchSliderLabel.setJustificationType(Justification::centred);
    pitchSliderLabel.setText("Pitch", dontSendNotification);
    pitchSliderLabel.setFont(Font(customFont).withHeight(15));
    addAndMakeVisible(&pitchSliderLabel);

    pitchDecaySliderLabel.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    pitchDecaySliderLabel.setJustificationType(Justification::centred);
    pitchDecaySliderLabel.setText("Decay", dontSendNotification);
    pitchDecaySliderLabel.setFont(Font(customFont).withHeight(15));
    addAndMakeVisible(&pitchDecaySliderLabel);

    driveSliderLabel.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    driveSliderLabel.setJustificationType(Justification::centred);
    driveSliderLabel.setText("Drive", dontSendNotification);
    driveSliderLabel.setFont(Font(customFont).withHeight(15));
    addAndMakeVisible(&driveSliderLabel);

    driveDecaySliderLabel.setColour(Label::textColourId, Colour::fromRGB(0xFF, 0x90, 0xF0));
    driveDecaySliderLabel.setJustificationType(Justification::centred);
    driveDecaySliderLabel.setText("Decay", dontSendNotification);
    driveDecaySliderLabel.setFont(Font(customFont).withHeight(15));
    addAndMakeVisible(&driveDecaySliderLabel);
}

FusionAudioProcessorEditor::~FusionAudioProcessorEditor()
{
}

//==============================================================================
void FusionAudioProcessorEditor::paint (juce::Graphics& g)
{
    ColourGradient foregroundGradient(Colour::fromRGB(0xFF, 0x40, 0xB0), 0, 0, Colour::fromRGB(0x90, 0x00, 0xC0), 0, getHeight(), false);
    g.setGradientFill(foregroundGradient);
    g.fillAll();

    DropShadow oscillatorShadow(Colour::fromFloatRGBA(0.0, 0.0, 0.0, 0.25), 10, Point<int>(5, 5));
    DropShadow driveShadow(Colour::fromFloatRGBA(0.0, 0.0, 0.0, 0.25), 10, Point<int>(5, 5));

    oscillatorShadow.drawForRectangle(g, oscillatorRectangle0.toNearestInt());
    oscillatorShadow.drawForRectangle(g, oscillatorRectangle2.toNearestInt());
    oscillatorShadow.drawForRectangle(g, oscillatorRectangle4.toNearestInt());
    oscillatorShadow.drawForRectangle(g, oscillatorRectangle6.toNearestInt());
    oscillatorShadow.drawForRectangle(g, oscillatorRectangle8.toNearestInt());

    driveShadow.drawForRectangle(g, driveRectangle.toNearestInt());

    ColourGradient backgroundGradient(Colour::fromRGB(0xE5, 0x10, 0xB5), 0, 0, Colour::fromRGB(0x70, 0x28, 0xA0), 0, getHeight(), false);
    g.setGradientFill(backgroundGradient);

    g.fillRect(oscillatorRectangle0);
    g.fillRect(oscillatorRectangle2);
    g.fillRect(oscillatorRectangle4);
    g.fillRect(oscillatorRectangle6);
    g.fillRect(oscillatorRectangle8);

    g.fillRect(driveRectangle);

    DropShadow sliderShadow(Colour::fromFloatRGBA(0.0, 0.0, 0.0, 0.1), 5, Point<int>(2, 2));
    
    Path attackSlider1BorderPath;
    Path attackSlider3BorderPath;
    Path attackSlider5BorderPath;
    Path attackSlider7BorderPath;

    attackSlider1BorderPath.addEllipse(230, 30, 60, 60);
    attackSlider3BorderPath.addEllipse(30, 230, 60, 60);
    attackSlider5BorderPath.addEllipse(430, 230, 60, 60);
    attackSlider7BorderPath.addEllipse(230, 430, 60, 60);

    sliderShadow.drawForPath(g, attackSlider1BorderPath);
    sliderShadow.drawForPath(g, attackSlider3BorderPath);
    sliderShadow.drawForPath(g, attackSlider5BorderPath);
    sliderShadow.drawForPath(g, attackSlider7BorderPath);

    Path decaySlider1BorderPath;
    Path decaySlider3BorderPath;
    Path decaySlider5BorderPath;
    Path decaySlider7BorderPath;

    decaySlider1BorderPath.addEllipse(310, 30, 60, 60);
    decaySlider3BorderPath.addEllipse(110, 230, 60, 60);
    decaySlider5BorderPath.addEllipse(510, 230, 60, 60);
    decaySlider7BorderPath.addEllipse(310, 430, 60, 60);

    sliderShadow.drawForPath(g, decaySlider1BorderPath);
    sliderShadow.drawForPath(g, decaySlider3BorderPath);
    sliderShadow.drawForPath(g, decaySlider5BorderPath);
    sliderShadow.drawForPath(g, decaySlider7BorderPath);

    Path sustainSlider1BorderPath;
    Path sustainSlider3BorderPath;
    Path sustainSlider5BorderPath;
    Path sustainSlider7BorderPath;

    sustainSlider1BorderPath.addEllipse(230, 110, 60, 60);
    sustainSlider3BorderPath.addEllipse(30, 310, 60, 60);
    sustainSlider5BorderPath.addEllipse(430, 310, 60, 60);
    sustainSlider7BorderPath.addEllipse(230, 510, 60, 60);

    sliderShadow.drawForPath(g, sustainSlider1BorderPath);
    sliderShadow.drawForPath(g, sustainSlider3BorderPath);
    sliderShadow.drawForPath(g, sustainSlider5BorderPath);
    sliderShadow.drawForPath(g, sustainSlider7BorderPath);

    Path releaseSlider1BorderPath;
    Path releaseSlider3BorderPath;
    Path releaseSlider5BorderPath;
    Path releaseSlider7BorderPath;

    releaseSlider1BorderPath.addEllipse(310, 110, 60, 60);
    releaseSlider3BorderPath.addEllipse(110, 310, 60, 60);
    releaseSlider5BorderPath.addEllipse(510, 310, 60, 60);
    releaseSlider7BorderPath.addEllipse(310, 510, 60, 60);

    sliderShadow.drawForPath(g, releaseSlider1BorderPath);
    sliderShadow.drawForPath(g, releaseSlider3BorderPath);
    sliderShadow.drawForPath(g, releaseSlider5BorderPath);
    sliderShadow.drawForPath(g, releaseSlider7BorderPath);
}

void FusionAudioProcessorEditor::resized()
{
    magnitudeSlider_0.setBounds(0, 0, 10, 200);
    attackSlider_0.setBounds(30, 30, 60, 60);
    decaySlider_0.setBounds(110, 30, 60, 60);
    sustainSlider_0.setBounds(30, 110, 60, 60);
    releaseSlider_0.setBounds(110, 110, 60, 60);

    magnitudeSlider_1.setBounds(200, 190, 200, 10);
    attackSlider_1.setBounds(230, 30, 60, 60);
    decaySlider_1.setBounds(310, 30, 60, 60);
    sustainSlider_1.setBounds(230, 110, 60, 60);
    releaseSlider_1.setBounds(310, 110, 60, 60);

    magnitudeSlider_2.setBounds(590, 0, 10, 200);
    attackSlider_2.setBounds(430, 30, 60, 60);
    decaySlider_2.setBounds(510, 30, 60, 60);
    sustainSlider_2.setBounds(430, 110, 60, 60);
    releaseSlider_2.setBounds(510, 110, 60, 60);

    magnitudeSlider_3.setBounds(0, 200, 10, 200);
    attackSlider_3.setBounds(30, 230, 60, 60);
    decaySlider_3.setBounds(110, 230, 60, 60);
    sustainSlider_3.setBounds(30, 310, 60, 60);
    releaseSlider_3.setBounds(110, 310, 60, 60);

    magnitudeSlider_4.setBounds(200, 390, 200, 10);
    attackSlider_4.setBounds(230, 230, 60, 60);
    decaySlider_4.setBounds(310, 230, 60, 60);
    sustainSlider_4.setBounds(230, 310, 60, 60);
    releaseSlider_4.setBounds(310, 310, 60, 60);

    magnitudeSlider_5.setBounds(590, 200, 10, 200);
    attackSlider_5.setBounds(430, 230, 60, 60);
    decaySlider_5.setBounds(510, 230, 60, 60);
    sustainSlider_5.setBounds(430, 310, 60, 60);
    releaseSlider_5.setBounds(510, 310, 60, 60);

    magnitudeSlider_6.setBounds(0, 400, 10, 200);
    attackSlider_6.setBounds(30, 430, 60, 60);
    decaySlider_6.setBounds(110, 430, 60, 60);
    sustainSlider_6.setBounds(30, 510, 60, 60);
    releaseSlider_6.setBounds(110, 510, 60, 60);

    magnitudeSlider_7.setBounds(200, 590, 200, 10);
    attackSlider_7.setBounds(230, 430, 60, 60);
    decaySlider_7.setBounds(310, 430, 60, 60);
    sustainSlider_7.setBounds(230, 510, 60, 60);
    releaseSlider_7.setBounds(310, 510, 60, 60);

    magnitudeSlider_8.setBounds(590, 400, 10, 200);
    attackSlider_8.setBounds(430, 430, 60, 60);
    decaySlider_8.setBounds(510, 430, 60, 60);
    sustainSlider_8.setBounds(430, 510, 60, 60);
    releaseSlider_8.setBounds(510, 510, 60, 60);

    oscillatorRectangle0.setBounds(0, 0, 200, 200);
    oscillatorRectangle2.setBounds(400, 0, 200, 200);
    oscillatorRectangle4.setBounds(200, 200, 200, 200);
    oscillatorRectangle6.setBounds(0, 400, 200, 200);
    oscillatorRectangle8.setBounds(400, 400, 200, 200);

    driveRectangle.setBounds(200, 600, 200, 130);

    attackSlider0Label.setBounds(10, 90, 100, 20);
    attackSlider1Label.setBounds(210, 90, 100, 20);
    attackSlider2Label.setBounds(410, 90, 100, 20);
    attackSlider3Label.setBounds(10, 290, 100, 20);
    attackSlider4Label.setBounds(210, 290, 100, 20);
    attackSlider5Label.setBounds(410, 290, 100, 20);
    attackSlider6Label.setBounds(10, 490, 100, 20);
    attackSlider7Label.setBounds(210, 490, 100, 20);
    attackSlider8Label.setBounds(410, 490, 100, 20);

    decaySlider0Label.setBounds(90, 90, 100, 20);
    decaySlider1Label.setBounds(290, 90, 100, 20);
    decaySlider2Label.setBounds(490, 90, 100, 20);
    decaySlider3Label.setBounds(90, 290, 100, 20);
    decaySlider4Label.setBounds(290, 290, 100, 20);
    decaySlider5Label.setBounds(490, 290, 100, 20);
    decaySlider6Label.setBounds(90, 490, 100, 20);
    decaySlider7Label.setBounds(290, 490, 100, 20);
    decaySlider8Label.setBounds(490, 490, 100, 20);

    sustainSlider0Label.setBounds(10, 170, 100, 20);
    sustainSlider1Label.setBounds(210, 170, 100, 20);
    sustainSlider2Label.setBounds(410, 170, 100, 20);
    sustainSlider3Label.setBounds(10, 370, 100, 20);
    sustainSlider4Label.setBounds(210, 370, 100, 20);
    sustainSlider5Label.setBounds(410, 370, 100, 20);
    sustainSlider6Label.setBounds(10, 570, 100, 20);
    sustainSlider7Label.setBounds(210, 570, 100, 20);
    sustainSlider8Label.setBounds(410, 570, 100, 20);

    releaseSlider0Label.setBounds(90, 170, 100, 20);
    releaseSlider1Label.setBounds(290, 170, 100, 20);
    releaseSlider2Label.setBounds(490, 170, 100, 20);
    releaseSlider3Label.setBounds(90, 370, 100, 20);
    releaseSlider4Label.setBounds(290, 370, 100, 20);
    releaseSlider5Label.setBounds(490, 370, 100, 20);
    releaseSlider6Label.setBounds(90, 570, 100, 20);
    releaseSlider7Label.setBounds(290, 570, 100, 20);
    releaseSlider8Label.setBounds(490, 570, 100, 20);

    oscillator0Label.setBounds(50, 5, 100, 20);
    oscillator1Label.setBounds(250, 5, 100, 20);
    oscillator2Label.setBounds(450, 5, 100, 20);
    oscillator3Label.setBounds(50, 205, 100, 20);
    oscillator4Label.setBounds(250, 205, 100, 20);
    oscillator5Label.setBounds(450, 205, 100, 20);
    oscillator6Label.setBounds(50, 405, 100, 20);
    oscillator7Label.setBounds(250, 405, 100, 20);
    oscillator8Label.setBounds(450, 405, 100, 20);

    pitchSliderLabel.setBounds(10, 690, 100, 20);
    pitchDecaySliderLabel.setBounds(90, 690, 100, 20);
    driveSliderLabel.setBounds(210, 690, 100, 20);
    driveDecaySliderLabel.setBounds(290, 690, 100, 20);

    pitchLabel.setBounds(10, 605, 100, 20);
    driveLabel.setBounds(210, 605, 100, 20);
    volumeLabel.setBounds(450, 690, 100, 20);

    pitchSlider.setBounds(30, 630, 60, 60);
    pitchDecaySlider.setBounds(110, 630, 60, 60);

    driveSlider.setBounds(230, 630, 60, 60);
    driveDecaySlider.setBounds(310, 630, 60, 60);

    gainSlider.setBounds(470, 630, 60, 60);
}
