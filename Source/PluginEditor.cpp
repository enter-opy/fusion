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

    inharmonicityValue_0 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_0, inharmonicitySlider_0);
    inharmonicityValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_1, inharmonicitySlider_1);
    inharmonicityValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_2, inharmonicitySlider_2);
    inharmonicityValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_3, inharmonicitySlider_3);
    inharmonicityValue_4 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_4, inharmonicitySlider_4);
    inharmonicityValue_5 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_5, inharmonicitySlider_5);
    inharmonicityValue_6 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_6, inharmonicitySlider_6);
    inharmonicityValue_7 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_7, inharmonicitySlider_7);
    inharmonicityValue_8 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INHARMONICITY_ID_8, inharmonicitySlider_8);

    attackSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_0.setRange(0.0, 2000.0, 1.0);
    attackSlider_0.setValue(audioProcessor.getTreeStateValues(0));
    attackSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_0);

    attackSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_1.setRange(0.0, 2000.0, 1.0);
    attackSlider_1.setValue(audioProcessor.getTreeStateValues(1));
    attackSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_1);

    attackSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_2.setRange(0.0, 2000.0, 1.0);
    attackSlider_2.setValue(audioProcessor.getTreeStateValues(2));
    attackSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_2);

    attackSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_3.setRange(0.0, 2000.0, 1.0);
    attackSlider_3.setValue(audioProcessor.getTreeStateValues(3));
    attackSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_3);

    attackSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_4.setRange(0.0, 2000.0, 1.0);
    attackSlider_4.setValue(audioProcessor.getTreeStateValues(4));
    attackSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_4);

    attackSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_5.setRange(0.0, 2000.0, 1.0);
    attackSlider_5.setValue(audioProcessor.getTreeStateValues(5));
    attackSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_5);

    attackSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_6.setRange(0.0, 2000.0, 1.0);
    attackSlider_6.setValue(audioProcessor.getTreeStateValues(6));
    attackSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_6);

    attackSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_7.setRange(0.0, 2000.0, 1.0);
    attackSlider_7.setValue(audioProcessor.getTreeStateValues(7));
    attackSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_7);

    attackSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    attackSlider_8.setRange(0.0, 2000.0, 1.0);
    attackSlider_8.setValue(audioProcessor.getTreeStateValues(8));
    attackSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&attackSlider_8);

    decaySlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_0.setRange(0.0, 2000.0, 1.0);
    decaySlider_0.setValue(audioProcessor.getTreeStateValues(10));
    decaySlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_0);

    decaySlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_1.setRange(0.0, 2000.0, 1.0);
    decaySlider_1.setValue(audioProcessor.getTreeStateValues(11));
    decaySlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_1);

    decaySlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_2.setRange(0.0, 2000.0, 1.0);
    decaySlider_2.setValue(audioProcessor.getTreeStateValues(12));
    decaySlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_2);

    decaySlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_3.setRange(0.0, 2000.0, 1.0);
    decaySlider_3.setValue(audioProcessor.getTreeStateValues(13));
    decaySlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_3);

    decaySlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_4.setRange(0.0, 2000.0, 1.0);
    decaySlider_4.setValue(audioProcessor.getTreeStateValues(14));
    decaySlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_4);

    decaySlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_5.setRange(0.0, 2000.0, 1.0);
    decaySlider_5.setValue(audioProcessor.getTreeStateValues(15));
    decaySlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_5);

    decaySlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_6.setRange(0.0, 2000.0, 1.0);
    decaySlider_6.setValue(audioProcessor.getTreeStateValues(16));
    decaySlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_6);

    decaySlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_7.setRange(0.0, 2000.0, 1.0);
    decaySlider_7.setValue(audioProcessor.getTreeStateValues(17));
    decaySlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_7);

    decaySlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    decaySlider_8.setRange(0.0, 2000.0, 1.0);
    decaySlider_8.setValue(audioProcessor.getTreeStateValues(18));
    decaySlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&decaySlider_8);

    sustainSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_0.setRange(0.0, 1.0, 0.01);
    sustainSlider_0.setValue(audioProcessor.getTreeStateValues(20));
    sustainSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_0);

    sustainSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_1.setRange(0.0, 1.0, 0.01);
    sustainSlider_1.setValue(audioProcessor.getTreeStateValues(21));
    sustainSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_1);

    sustainSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_2.setRange(0.0, 1.0, 0.01);
    sustainSlider_2.setValue(audioProcessor.getTreeStateValues(22));
    sustainSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_2);

    sustainSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_3.setRange(0.0, 1.0, 0.01);
    sustainSlider_3.setValue(audioProcessor.getTreeStateValues(23));
    sustainSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_3);

    sustainSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_4.setRange(0.0, 1.0, 0.01);
    sustainSlider_4.setValue(audioProcessor.getTreeStateValues(24));
    sustainSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_4);

    sustainSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_5.setRange(0.0, 1.0, 0.01);
    sustainSlider_5.setValue(audioProcessor.getTreeStateValues(25));
    sustainSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_5);

    sustainSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_6.setRange(0.0, 1.0, 0.01);
    sustainSlider_6.setValue(audioProcessor.getTreeStateValues(26));
    sustainSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_6);

    sustainSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_7.setRange(0.0, 1.0, 0.01);
    sustainSlider_7.setValue(audioProcessor.getTreeStateValues(27));
    sustainSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_7);

    sustainSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    sustainSlider_8.setRange(0.0, 1.0, 0.01);
    sustainSlider_8.setValue(audioProcessor.getTreeStateValues(28));
    sustainSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&sustainSlider_8);

    releaseSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_0.setRange(0.0, 2000.0, 1.0);
    releaseSlider_0.setValue(audioProcessor.getTreeStateValues(30));
    releaseSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_0);

    releaseSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_1.setRange(0.0, 2000.0, 1.0);
    releaseSlider_1.setValue(audioProcessor.getTreeStateValues(31));
    releaseSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_1);

    releaseSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_2.setRange(0.0, 2000.0, 1.0);
    releaseSlider_2.setValue(audioProcessor.getTreeStateValues(32));
    releaseSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_2);

    releaseSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_3.setRange(0.0, 2000.0, 1.0);
    releaseSlider_3.setValue(audioProcessor.getTreeStateValues(33));
    releaseSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_3);

    releaseSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_4.setRange(0.0, 2000.0, 1.0);
    releaseSlider_4.setValue(audioProcessor.getTreeStateValues(34));
    releaseSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_4);

    releaseSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_5.setRange(0.0, 2000.0, 1.0);
    releaseSlider_5.setValue(audioProcessor.getTreeStateValues(35));
    releaseSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_5);

    releaseSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_6.setRange(0.0, 2000.0, 1.0);
    releaseSlider_6.setValue(audioProcessor.getTreeStateValues(36));
    releaseSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_6);

    releaseSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_7.setRange(0.0, 2000.0, 1.0);
    releaseSlider_7.setValue(audioProcessor.getTreeStateValues(37));
    releaseSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_7);

    releaseSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    releaseSlider_8.setRange(0.0, 2000.0, 1.0);
    releaseSlider_8.setValue(audioProcessor.getTreeStateValues(38));
    releaseSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&releaseSlider_8);

    magnitudeSlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_0.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_0.setValue(audioProcessor.getTreeStateValues(40));
    magnitudeSlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_0);

    magnitudeSlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_1.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_1.setValue(audioProcessor.getTreeStateValues(41));
    magnitudeSlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_1);

    magnitudeSlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_2.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_2.setValue(audioProcessor.getTreeStateValues(42));
    magnitudeSlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_2);

    magnitudeSlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_3.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_3.setValue(audioProcessor.getTreeStateValues(43));
    magnitudeSlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_3);

    magnitudeSlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_4.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_4.setValue(audioProcessor.getTreeStateValues(44));
    magnitudeSlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_4);

    magnitudeSlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_5.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_5.setValue(audioProcessor.getTreeStateValues(45));
    magnitudeSlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_5);

    magnitudeSlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_6.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_6.setValue(audioProcessor.getTreeStateValues(46));
    magnitudeSlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_6);

    magnitudeSlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_7.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_7.setValue(audioProcessor.getTreeStateValues(47));
    magnitudeSlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_7);

    magnitudeSlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    magnitudeSlider_8.setRange(0.0, 1.0, 0.01);
    magnitudeSlider_8.setValue(audioProcessor.getTreeStateValues(48));
    magnitudeSlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&magnitudeSlider_8);

    inharmonicitySlider_0.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_0.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_0.setValue(audioProcessor.getTreeStateValues(50));
    inharmonicitySlider_0.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_0);

    inharmonicitySlider_1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_1.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_1.setValue(audioProcessor.getTreeStateValues(51));
    inharmonicitySlider_1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_1);

    inharmonicitySlider_2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_2.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_2.setValue(audioProcessor.getTreeStateValues(52));
    inharmonicitySlider_2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_2);

    inharmonicitySlider_3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_3.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_3.setValue(audioProcessor.getTreeStateValues(53));
    inharmonicitySlider_3.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_3);

    inharmonicitySlider_4.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_4.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_4.setValue(audioProcessor.getTreeStateValues(54));
    inharmonicitySlider_4.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_4);

    inharmonicitySlider_5.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_5.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_5.setValue(audioProcessor.getTreeStateValues(55));
    inharmonicitySlider_5.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_5);

    inharmonicitySlider_6.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_6.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_6.setValue(audioProcessor.getTreeStateValues(56));
    inharmonicitySlider_6.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_6);

    inharmonicitySlider_7.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_7.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_7.setValue(audioProcessor.getTreeStateValues(57));
    inharmonicitySlider_7.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_7);

    inharmonicitySlider_8.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    inharmonicitySlider_8.setRange(-50.0, 50.0, 1.0);
    inharmonicitySlider_8.setValue(audioProcessor.getTreeStateValues(58));
    inharmonicitySlider_8.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&inharmonicitySlider_8);
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
    magnitudeSlider_0.setBounds(20, 20, 50, 50);
    inharmonicitySlider_0.setBounds(20, 80, 50, 50);
    attackSlider_0.setBounds(80, 20, 50, 50);
    decaySlider_0.setBounds(140, 20, 50, 50);
    sustainSlider_0.setBounds(80, 80, 50, 50);
    releaseSlider_0.setBounds(140, 80, 50, 50);

    magnitudeSlider_1.setBounds(220, 20, 50, 50);
    inharmonicitySlider_1.setBounds(220, 80, 50, 50);
    attackSlider_1.setBounds(280, 20, 50, 50);
    decaySlider_1.setBounds(340, 20, 50, 50);
    sustainSlider_1.setBounds(280, 80, 50, 50);
    releaseSlider_1.setBounds(340, 80, 50, 50);

    magnitudeSlider_2.setBounds(420, 20, 50, 50);
    inharmonicitySlider_2.setBounds(420, 80, 50, 50);
    attackSlider_2.setBounds(480, 20, 50, 50);
    decaySlider_2.setBounds(540, 20, 50, 50);
    sustainSlider_2.setBounds(480, 80, 50, 50);
    releaseSlider_2.setBounds(540, 80, 50, 50);

    magnitudeSlider_3.setBounds(20, 160, 50, 50);
    inharmonicitySlider_3.setBounds(20, 220, 50, 50);
    attackSlider_3.setBounds(80, 160, 50, 50);
    decaySlider_3.setBounds(140, 160, 50, 50);
    sustainSlider_3.setBounds(80, 220, 50, 50);
    releaseSlider_3.setBounds(140, 220, 50, 50);

    magnitudeSlider_4.setBounds(220, 160, 50, 50);
    inharmonicitySlider_4.setBounds(220, 220, 50, 50);
    attackSlider_4.setBounds(280, 160, 50, 50);
    decaySlider_4.setBounds(340, 160, 50, 50);
    sustainSlider_4.setBounds(280, 220, 50, 50);
    releaseSlider_4.setBounds(340, 220, 50, 50);

    magnitudeSlider_5.setBounds(420, 160, 50, 50);
    inharmonicitySlider_5.setBounds(420, 220, 50, 50);
    attackSlider_5.setBounds(480, 160, 50, 50);
    decaySlider_5.setBounds(540, 160, 50, 50);
    sustainSlider_5.setBounds(480, 220, 50, 50);
    releaseSlider_5.setBounds(540, 220, 50, 50);

    magnitudeSlider_6.setBounds(20, 300, 50, 50);
    inharmonicitySlider_6.setBounds(20, 360, 50, 50);
    attackSlider_6.setBounds(80, 300, 50, 50);
    decaySlider_6.setBounds(140, 300, 50, 50);
    sustainSlider_6.setBounds(80, 360, 50, 50);
    releaseSlider_6.setBounds(140, 360, 50, 50);

    magnitudeSlider_7.setBounds(220, 300, 50, 50);
    inharmonicitySlider_7.setBounds(220, 360, 50, 50);
    attackSlider_7.setBounds(280, 300, 50, 50);
    decaySlider_7.setBounds(340, 300, 50, 50);
    sustainSlider_7.setBounds(280, 360, 50, 50);
    releaseSlider_7.setBounds(340, 360, 50, 50);

    magnitudeSlider_8.setBounds(420, 300, 50, 50);
    inharmonicitySlider_8.setBounds(420, 360, 50, 50);
    attackSlider_8.setBounds(480, 300, 50, 50);
    decaySlider_8.setBounds(540, 300, 50, 50);
    sustainSlider_8.setBounds(480, 360, 50, 50);
    releaseSlider_8.setBounds(540, 360, 50, 50);
}
