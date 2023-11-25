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
class SliderLookAndFeelOdd : public LookAndFeel_V4 {
public:
    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotatoryStartAngle, float rotatoryEndAngle, juce::Slider& slider) override {
        float diameter = jmin(width - 5, height - 5);
        float radius = diameter / 2;
        float centerX = x + width / 2;
        float centerY = y + height / 2;
        float rx = centerX - radius;
        float ry = centerY - radius;
        float angle = rotatoryStartAngle + sliderPos * (rotatoryEndAngle - rotatoryStartAngle);

        Rectangle<float> area(rx, ry, diameter, diameter);

        g.setColour(Colour::fromFloatRGBA(0.0, 0.0, 0.0, 0.25));
        g.fillEllipse(area);

        // Inner shadow workaround by https://forum.juce.com/u/crushedpixel/summary
        Path shadowPath;
        shadowPath.addEllipse(area);
        shadowPath.setUsingNonZeroWinding(false);

        Rectangle<float> clipArea(rx - 3.0, ry - 3.0, diameter + 5.0, diameter + 5.0);
        Path clipPath;
        clipPath.addEllipse(clipArea);
        g.reduceClipRegion(clipPath);

        DropShadow sliderShadow(Colour::fromRGBA(0xFF, 0x40, 0xE0, 0x40), 10, Point<int>(5, 5));
        sliderShadow.drawForPath(g, shadowPath);

        Path thumb;
        thumb.addEllipse(0, -radius + 10.0, 10.0f, 10.0f);

        g.setColour(Colour::fromRGB(0xFF, 0x40, 0xE0));
        g.fillPath(thumb, AffineTransform::rotation(angle).translated(centerX, centerY));
        g.drawEllipse(area, 4.0f);
    }
};

class SliderLookAndFeelEven : public LookAndFeel_V4 {
public:
    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotatoryStartAngle, float rotatoryEndAngle, juce::Slider& slider) override {
        float diameter = jmin(width - 5, height - 5);
        float radius = diameter / 2;
        float centerX = x + width / 2;
        float centerY = y + height / 2;
        float rx = centerX - radius;
        float ry = centerY - radius;
        float angle = rotatoryStartAngle + sliderPos * (rotatoryEndAngle - rotatoryStartAngle);

        Rectangle<float> area(rx, ry, diameter, diameter);

        g.setColour(Colour::fromRGBA(0xFF, 0xFF, 0xFF, 0x40));
        g.fillEllipse(area);

        Path thumb;
        thumb.addEllipse(0, -radius + 10.0, 10.0f, 10.0f);

        g.setColour(Colour::fromRGB(0xFF, 0xA0, 0xF0));
        g.fillPath(thumb, AffineTransform::rotation(angle).translated(centerX, centerY));
        g.drawEllipse(area, 4.0f);
    }
};

class SliderLookAndFeelLinearVertical : public LookAndFeel_V4 {
public:
    void drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, Slider::SliderStyle sliderStyle, Slider& slider) override {
        Rectangle<float> area(0, 0, width + 2 * x, height + 2 * y);

        g.setColour(Colour::fromRGBA(0xFF, 0xFF, 0xFF, 0x40));
        g.fillRect(area);

        float mappedSliderPos = (sliderPos - y) * (height + 2 * y) / (height);

        Rectangle<float> barArea(0, mappedSliderPos, width + 2 * x, height + 2 * y);

        g.setColour(Colour::fromRGBA(0xFF, 0xFF, 0xFF, 0xA0));
        g.fillRect(barArea);
    }
};

class SliderLookAndFeelLinearHorizontal : public LookAndFeel_V4 {
public:
    void drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, Slider::SliderStyle sliderStyle, Slider& slider) override {
        Rectangle<float> area(0, 0, width + 2 * x, height + 2 * y);

        g.setColour(Colour::fromRGBA(0xFF, 0xFF, 0xFF, 0x40));
        g.fillRect(area);

        float mappedSliderPos = (sliderPos - x) * (width + 2 * x) / (width);

        Rectangle<float> barArea(0, 0, mappedSliderPos, height + 2 * y);

        g.setColour(Colour::fromRGBA(0xFF, 0xFF, 0xFF, 0xA0));
        g.fillRect(barArea);
    }
};

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

    Slider pitchSlider;
    Slider pitchDecaySlider;

    Slider driveSlider;
    Slider driveDecaySlider;

    Slider gainSlider;

    Rectangle<float> oscillatorRectangle0;
    Rectangle<float> oscillatorRectangle2;
    Rectangle<float> oscillatorRectangle4;
    Rectangle<float> oscillatorRectangle6;
    Rectangle<float> oscillatorRectangle8;

    SliderLookAndFeelOdd attackSlider0LookAndFeel;
    SliderLookAndFeelEven attackSlider1LookAndFeel;
    SliderLookAndFeelOdd attackSlider2LookAndFeel;
    SliderLookAndFeelEven attackSlider3LookAndFeel;
    SliderLookAndFeelOdd attackSlider4LookAndFeel;
    SliderLookAndFeelEven attackSlider5LookAndFeel;
    SliderLookAndFeelOdd attackSlider6LookAndFeel;
    SliderLookAndFeelEven attackSlider7LookAndFeel;
    SliderLookAndFeelOdd attackSlider8LookAndFeel;

    SliderLookAndFeelOdd decaySlider0LookAndFeel;
    SliderLookAndFeelEven decaySlider1LookAndFeel;
    SliderLookAndFeelOdd decaySlider2LookAndFeel;
    SliderLookAndFeelEven decaySlider3LookAndFeel;
    SliderLookAndFeelOdd decaySlider4LookAndFeel;
    SliderLookAndFeelEven decaySlider5LookAndFeel;
    SliderLookAndFeelOdd decaySlider6LookAndFeel;
    SliderLookAndFeelEven decaySlider7LookAndFeel;
    SliderLookAndFeelOdd decaySlider8LookAndFeel;

    SliderLookAndFeelOdd sustainSlider0LookAndFeel;
    SliderLookAndFeelEven sustainSlider1LookAndFeel;
    SliderLookAndFeelOdd sustainSlider2LookAndFeel;
    SliderLookAndFeelEven sustainSlider3LookAndFeel;
    SliderLookAndFeelOdd sustainSlider4LookAndFeel;
    SliderLookAndFeelEven sustainSlider5LookAndFeel;
    SliderLookAndFeelOdd sustainSlider6LookAndFeel;
    SliderLookAndFeelEven sustainSlider7LookAndFeel;
    SliderLookAndFeelOdd sustainSlider8LookAndFeel;

    SliderLookAndFeelOdd releaseSlider0LookAndFeel;
    SliderLookAndFeelEven releaseSlider1LookAndFeel;
    SliderLookAndFeelOdd releaseSlider2LookAndFeel;
    SliderLookAndFeelEven releaseSlider3LookAndFeel;
    SliderLookAndFeelOdd releaseSlider4LookAndFeel;
    SliderLookAndFeelEven releaseSlider5LookAndFeel;
    SliderLookAndFeelOdd releaseSlider6LookAndFeel;
    SliderLookAndFeelEven releaseSlider7LookAndFeel;
    SliderLookAndFeelOdd releaseSlider8LookAndFeel;

    SliderLookAndFeelLinearVertical magnitudeSlider0LookAndFeel;
    SliderLookAndFeelLinearHorizontal magnitudeSlider1LookAndFeel;
    SliderLookAndFeelLinearVertical magnitudeSlider2LookAndFeel;
    SliderLookAndFeelLinearVertical magnitudeSlider3LookAndFeel;
    SliderLookAndFeelLinearHorizontal magnitudeSlider4LookAndFeel;
    SliderLookAndFeelLinearVertical magnitudeSlider5LookAndFeel;
    SliderLookAndFeelLinearVertical magnitudeSlider6LookAndFeel;
    SliderLookAndFeelLinearHorizontal magnitudeSlider7LookAndFeel;
    SliderLookAndFeelLinearVertical magnitudeSlider8LookAndFeel;

    SliderLookAndFeelEven pitchSliderLookAndFeel;
    SliderLookAndFeelEven pitchDecaySliderLookAndFeel;

    SliderLookAndFeelOdd driveSliderLookAndFeel;
    SliderLookAndFeelOdd driveDecaySliderLookAndFeel;

    SliderLookAndFeelEven gainSliderLookAndFeel;

    Label attackSlider0Label;
    Label attackSlider1Label;
    Label attackSlider2Label;
    Label attackSlider3Label;
    Label attackSlider4Label;
    Label attackSlider5Label;
    Label attackSlider6Label;
    Label attackSlider7Label;
    Label attackSlider8Label;

    Label decaySlider0Label;
    Label decaySlider1Label;
    Label decaySlider2Label;
    Label decaySlider3Label;
    Label decaySlider4Label;
    Label decaySlider5Label;
    Label decaySlider6Label;
    Label decaySlider7Label;
    Label decaySlider8Label;

    Label sustainSlider0Label;
    Label sustainSlider1Label;
    Label sustainSlider2Label;
    Label sustainSlider3Label;
    Label sustainSlider4Label;
    Label sustainSlider5Label;
    Label sustainSlider6Label;
    Label sustainSlider7Label;
    Label sustainSlider8Label;

    Label releaseSlider0Label;
    Label releaseSlider1Label;
    Label releaseSlider2Label;
    Label releaseSlider3Label;
    Label releaseSlider4Label;
    Label releaseSlider5Label;
    Label releaseSlider6Label;
    Label releaseSlider7Label;
    Label releaseSlider8Label;

    Typeface::Ptr customFont = juce::Typeface::createSystemTypefaceFor(BinaryData::MuseoModernoSemiBold_ttf, BinaryData::MuseoModernoSemiBold_ttfSize);
   
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

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> pitchValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> pitchDecayValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> driveValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> driveDecayValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> gainValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FusionAudioProcessorEditor)
};
