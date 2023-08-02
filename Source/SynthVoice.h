/*
  ==============================================================================

    SynthVoice.h
    Created: 29 Jul 2023 7:14:23pm
    Author:  vivek

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "SynthSound.h"
#include <maximilian.h>

class SynthVoice :public SynthesiserVoice {
public:
    bool canPlaySound(SynthesiserSound* sound) override {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }

    void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override {
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        
        env.trigger = 1;
    }

    void stopNote(float velocity, bool allowTailOff) override {
        env.trigger = 0;

        if (env.adsr(wave, env.trigger) == 0) {
            clearCurrentNote();
        }
    }

    void pitchWheelMoved(int newPitchWheelValue) override {

    }

    void controllerMoved(int controllerNumber, int newControllerValue) override {

    }

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override {
        env.setAttack(20);
        env.setDecay(200);
        env.setSustain(0.5);
        env.setRelease(100);

        for (int sample = 0; sample < numSamples; sample++) {
            wave = osc0.sinewave(frequency) * f0Gain
                + osc1.sinewave(frequency * 2) * f1Gain
                + osc2.sinewave(frequency * 3) * f2Gain
                + osc3.sinewave(frequency * 4) * f3Gain
                + osc4.sinewave(frequency * 5) * f4Gain
                + osc5.sinewave(frequency * 6) * f5Gain
                + osc6.sinewave(frequency * 7) * f6Gain;

            double sound = env.adsr(wave / 7,
                env.trigger) * 0.5;

            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++) {
                outputBuffer.addSample(channel, startSample, sound);
            }

            startSample++;
        }
    }
    
    void getFrequencies(float f0, float f1, float f2, float f3, float f4, float f5, float f6) {
        f0Gain = f0;
        f1Gain = f1;
        f2Gain = f2;
        f3Gain = f3;
        f4Gain = f4;
        f5Gain = f5;
        f6Gain = f6;
    }

private:
    double f0Gain{ 1.0 };
    double f1Gain{ 0.0 };
    double f2Gain{ 0.0 };
    double f3Gain{ 0.0 };
    double f4Gain{ 0.0 };
    double f5Gain{ 0.0 };
    double f6Gain{ 0.0 };

    double frequency;

    double wave;

    maxiOsc osc0;
    maxiOsc osc1;
    maxiOsc osc2;
    maxiOsc osc3;
    maxiOsc osc4;
    maxiOsc osc5;
    maxiOsc osc6;

    maxiEnv env;
};