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
            wave = osc0.saw(frequency)
                + osc1.saw(2 * frequency + inharmonicity1)
                + osc2.saw(3 * frequency + inharmonicity2)
                + osc3.saw(4 * frequency + inharmonicity3)
                + osc4.saw(5 * frequency + inharmonicity4)
                + osc5.saw(6 * frequency + inharmonicity5)
                + osc6.saw(7 * frequency + inharmonicity6)
                + osc7.saw(8 * frequency + inharmonicity7)
                + osc8.saw(9 * frequency + inharmonicity8)
                + osc9.saw(10 * frequency + inharmonicity9)
                + osc10.saw(11 * frequency + inharmonicity10)
                + osc11.saw(12 * frequency + inharmonicity11)
                + osc12.saw(13 * frequency + inharmonicity12)
                + osc13.saw(14 * frequency + inharmonicity13)
                + osc14.saw(15 * frequency + inharmonicity14)
                + osc15.saw(16 * frequency + inharmonicity15)
                + osc16.saw(17 * frequency + inharmonicity16)
                + osc17.saw(18 * frequency + inharmonicity17)
                + osc18.saw(19 * frequency + inharmonicity18)
                + osc19.saw(20 * frequency + inharmonicity19)
                + osc20.saw(21 * frequency + inharmonicity20)
                + osc21.saw(22 * frequency + inharmonicity21)
                + osc22.saw(23 * frequency + inharmonicity22)
                + osc23.saw(24 * frequency + inharmonicity23)
                + osc24.saw(25 * frequency + inharmonicity24);

            wave /= 25;

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

    maxiOsc osc0;
    maxiOsc osc1;
    maxiOsc osc2;
    maxiOsc osc3;
    maxiOsc osc4;
    maxiOsc osc5;
    maxiOsc osc6;
    maxiOsc osc7;
    maxiOsc osc8;
    maxiOsc osc9;
    maxiOsc osc10;
    maxiOsc osc11;
    maxiOsc osc12;
    maxiOsc osc13;
    maxiOsc osc14;
    maxiOsc osc15;
    maxiOsc osc16;
    maxiOsc osc17;
    maxiOsc osc18;
    maxiOsc osc19;
    maxiOsc osc20;
    maxiOsc osc21;
    maxiOsc osc22;
    maxiOsc osc23;
    maxiOsc osc24;

    maxiEnv env;

    float inharmonicity0;
    float inharmonicity1;
    float inharmonicity2;
    float inharmonicity3;
    float inharmonicity4;
    float inharmonicity5;
    float inharmonicity6;
    float inharmonicity7;
    float inharmonicity8;
    float inharmonicity9;
    float inharmonicity10;
    float inharmonicity11;
    float inharmonicity12;
    float inharmonicity13;
    float inharmonicity14;
    float inharmonicity15;
    float inharmonicity16;
    float inharmonicity17;
    float inharmonicity18;
    float inharmonicity19;
    float inharmonicity20;
    float inharmonicity21;
    float inharmonicity22;
    float inharmonicity23;
    float inharmonicity24;
};