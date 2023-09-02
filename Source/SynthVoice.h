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
            wave = osc0.saw(frequency) * gain0
                + osc1.saw(2 * frequency + inharmonicity1) * gain1
                + osc2.saw(3 * frequency + inharmonicity2) * gain2
                + osc3.saw(4 * frequency + inharmonicity3) * gain3
                + osc4.saw(5 * frequency + inharmonicity4) * gain4
                + osc5.saw(6 * frequency + inharmonicity5) * gain5
                + osc6.saw(7 * frequency + inharmonicity6) * gain6
                + osc7.saw(8 * frequency + inharmonicity7) * gain7
                + osc8.saw(9 * frequency + inharmonicity8) * gain8
                + osc9.saw(10 * frequency + inharmonicity9) * gain9
                + osc10.saw(11 * frequency + inharmonicity10) * gain10
                + osc11.saw(12 * frequency + inharmonicity11) * gain11
                + osc12.saw(13 * frequency + inharmonicity12) * gain12
                + osc13.saw(14 * frequency + inharmonicity13) * gain13
                + osc14.saw(15 * frequency + inharmonicity14) * gain14
                + osc15.saw(16 * frequency + inharmonicity15) * gain15
                + osc16.saw(17 * frequency + inharmonicity16) * gain16
                + osc17.saw(18 * frequency + inharmonicity17) * gain17
                + osc18.saw(19 * frequency + inharmonicity18) * gain18
                + osc19.saw(20 * frequency + inharmonicity19) * gain19
                + osc20.saw(21 * frequency + inharmonicity20) * gain20
                + osc21.saw(22 * frequency + inharmonicity21) * gain21
                + osc22.saw(23 * frequency + inharmonicity22) * gain22
                + osc23.saw(24 * frequency + inharmonicity23) * gain23
                + osc24.saw(25 * frequency + inharmonicity24) * gain24;

            wave /= (gain0
                + gain1
                + gain2
                + gain3
                + gain4
                + gain5
                + gain6
                + gain7
                + gain8
                + gain9
                + gain10
                + gain11
                + gain12
                + gain13
                + gain14
                + gain15
                + gain16
                + gain17
                + gain18
                + gain19
                + gain20
                + gain21
                + gain22
                + gain23
                + gain24);

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

    float gain0;
    float gain1;
    float gain2;
    float gain3;
    float gain4;
    float gain5;
    float gain6;
    float gain7;
    float gain8;
    float gain9;
    float gain10;
    float gain11;
    float gain12;
    float gain13;
    float gain14;
    float gain15;
    float gain16;
    float gain17;
    float gain18;
    float gain19;
    float gain20;
    float gain21;
    float gain22;
    float gain23;
    float gain24;

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