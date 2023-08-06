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
        for (int sample = 0; sample < numSamples; sample++) {
            wave = osc.saw(frequency);

            double sound = env.adsr(wave, env.trigger) * 0.5;

            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++) {
                outputBuffer.addSample(channel, startSample, sound);
            }

            startSample++;
        }
    }
    
    void getEnvelope(float attack, float decay, float sustain, float release) { 
        env.setAttack(attack);
        env.setDecay(decay);
        env.setSustain(sustain);
        env.setRelease(release);
    }

private:
    double frequency;

    double wave;

    maxiOsc osc;

    maxiEnv env;
};