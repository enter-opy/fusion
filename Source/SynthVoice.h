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
        
        envelope_0.trigger = 1;
    }

    void stopNote(float velocity, bool allowTailOff) override {
        envelope_0.trigger = 0;

        if (envelope_0.adsr(wave, envelope_0.trigger) == 0) {
            clearCurrentNote();
        }
    }

    void pitchWheelMoved(int newPitchWheelValue) override {

    }

    void controllerMoved(int controllerNumber, int newControllerValue) override {

    }

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override {
        for (int sample = 0; sample < numSamples; sample++) {
            wave_0 = oscilator_0.saw(frequency) * magnitude_0;
            wave_1 = oscilator_1.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_2 = oscilator_2.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_3 = oscilator_3.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_4 = oscilator_4.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_5 = oscilator_5.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_6 = oscilator_6.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_7 = oscilator_7.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_8 = oscilator_8.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_9 = oscilator_9.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_10 = oscilator_10.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_11 = oscilator_11.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_12 = oscilator_12.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_13 = oscilator_13.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_14 = oscilator_14.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_15 = oscilator_15.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_16 = oscilator_16.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_17 = oscilator_17.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_18 = oscilator_18.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_19 = oscilator_19.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_20 = oscilator_20.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_21 = oscilator_21.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_22 = oscilator_22.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_23 = oscilator_23.saw(frequency + inharmonicity_1) * magnitude_0;
            wave_24 = oscilator_24.saw(frequency + inharmonicity_1) * magnitude_0;

            wave_0 = envelope_0.adsr(wave_0, envelope_0.trigger);
            wave_1 = envelope_1.adsr(wave_1, envelope_1.trigger);
            wave_2 = envelope_2.adsr(wave_2, envelope_2.trigger);
            wave_3 = envelope_3.adsr(wave_3, envelope_3.trigger);
            wave_4 = envelope_4.adsr(wave_4, envelope_4.trigger);
            wave_5 = envelope_5.adsr(wave_5, envelope_5.trigger);
            wave_6 = envelope_6.adsr(wave_6, envelope_6.trigger);
            wave_7 = envelope_7.adsr(wave_7, envelope_7.trigger);
            wave_8 = envelope_8.adsr(wave_8, envelope_8.trigger);
            wave_9 = envelope_9.adsr(wave_9, envelope_9.trigger);
            wave_10 = envelope_10.adsr(wave_10, envelope_10.trigger);
            wave_11 = envelope_11.adsr(wave_11, envelope_11.trigger);
            wave_12 = envelope_12.adsr(wave_12, envelope_12.trigger);
            wave_13 = envelope_13.adsr(wave_13, envelope_13.trigger);
            wave_14 = envelope_14.adsr(wave_14, envelope_14.trigger);
            wave_15 = envelope_15.adsr(wave_15, envelope_15.trigger);
            wave_16 = envelope_16.adsr(wave_16, envelope_16.trigger);
            wave_17 = envelope_17.adsr(wave_17, envelope_17.trigger);
            wave_18 = envelope_18.adsr(wave_18, envelope_18.trigger);
            wave_19 = envelope_19.adsr(wave_19, envelope_19.trigger);
            wave_20 = envelope_20.adsr(wave_20, envelope_20.trigger);
            wave_21 = envelope_21.adsr(wave_21, envelope_21.trigger);
            wave_22 = envelope_22.adsr(wave_22, envelope_22.trigger);
            wave_23 = envelope_23.adsr(wave_23, envelope_23.trigger);
            wave_24 = envelope_24.adsr(wave_24, envelope_24.trigger);

            double sound = (
                wave_0 + wave_1 + wave_2 + wave_3 + wave_4
                + wave_5 + wave_6 + wave_7 + wave_8 + wave_9
                + wave_10 + wave_11 + wave_12 + wave_13 + wave_14
                + wave_15 + wave_16 + wave_17 + wave_18 + wave_19
                + wave_20 + wave_21 + wave_22 + wave_23 + wave_24
                ) / (
                    magnitude_0 + magnitude_1 + magnitude_2 + magnitude_3 + magnitude_4
                    + magnitude_5 + magnitude_6 + magnitude_7 + magnitude_8 + magnitude_9
                    + magnitude_10 + magnitude_11 + magnitude_12 + magnitude_13 + magnitude_14
                    + magnitude_15 + magnitude_16 + magnitude_17 + magnitude_18 + magnitude_19
                    + magnitude_20 + magnitude_21 + magnitude_22 + magnitude_23 + magnitude_24
                    );

            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++) {
                outputBuffer.addSample(channel, startSample, sound);
            }

            startSample++;
        }
    }
    
    void getEnvelope_0(float attack, float decay, float sustain, float release) { 
        envelope_0.setAttack(attack);
        envelope_0.setDecay(decay);
        envelope_0.setSustain(sustain);
        envelope_0.setRelease(release);
    }

private:
    double frequency;

    double wave;

    double wave_0;
    double wave_1;
    double wave_2;
    double wave_3;
    double wave_4;
    double wave_5;
    double wave_6;
    double wave_7;
    double wave_8;
    double wave_9;
    double wave_10;
    double wave_11;
    double wave_12;
    double wave_13;
    double wave_14;
    double wave_15;
    double wave_16;
    double wave_17;
    double wave_18;
    double wave_19;
    double wave_20;
    double wave_21;
    double wave_22;
    double wave_23;
    double wave_24;

    maxiOsc oscilator_0;
    maxiOsc oscilator_1;
    maxiOsc oscilator_2;
    maxiOsc oscilator_3;
    maxiOsc oscilator_4;
    maxiOsc oscilator_5;
    maxiOsc oscilator_6;
    maxiOsc oscilator_7;
    maxiOsc oscilator_8;
    maxiOsc oscilator_9;
    maxiOsc oscilator_10;
    maxiOsc oscilator_11;
    maxiOsc oscilator_12;
    maxiOsc oscilator_13;
    maxiOsc oscilator_14;
    maxiOsc oscilator_15;
    maxiOsc oscilator_16;
    maxiOsc oscilator_17;
    maxiOsc oscilator_18;
    maxiOsc oscilator_19;
    maxiOsc oscilator_20;
    maxiOsc oscilator_21;
    maxiOsc oscilator_22;
    maxiOsc oscilator_23;
    maxiOsc oscilator_24;

    maxiEnv envelope_0;
    maxiEnv envelope_1;
    maxiEnv envelope_2;
    maxiEnv envelope_3;
    maxiEnv envelope_4;
    maxiEnv envelope_5;
    maxiEnv envelope_6;
    maxiEnv envelope_7;
    maxiEnv envelope_8;
    maxiEnv envelope_9;
    maxiEnv envelope_10;
    maxiEnv envelope_11;
    maxiEnv envelope_12;
    maxiEnv envelope_13;
    maxiEnv envelope_14;
    maxiEnv envelope_15;
    maxiEnv envelope_16;
    maxiEnv envelope_17;
    maxiEnv envelope_18;
    maxiEnv envelope_19;
    maxiEnv envelope_20;
    maxiEnv envelope_21;
    maxiEnv envelope_22;
    maxiEnv envelope_23;
    maxiEnv envelope_24;

    float magnitude_0;
    float magnitude_1;
    float magnitude_2;
    float magnitude_3;
    float magnitude_4;
    float magnitude_5;
    float magnitude_6;
    float magnitude_7;
    float magnitude_8;
    float magnitude_9;
    float magnitude_10;
    float magnitude_11;
    float magnitude_12;
    float magnitude_13;
    float magnitude_14;
    float magnitude_15;
    float magnitude_16;
    float magnitude_17;
    float magnitude_18;
    float magnitude_19;
    float magnitude_20;
    float magnitude_21;
    float magnitude_22;
    float magnitude_23;
    float magnitude_24;

    float inharmonicity_1;
    float inharmonicity_2;
    float inharmonicity_3;
    float inharmonicity_4;
    float inharmonicity_5;
    float inharmonicity_6;
    float inharmonicity_7;
    float inharmonicity_8;
    float inharmonicity_9;
    float inharmonicity_10;
    float inharmonicity_11;
    float inharmonicity_12;
    float inharmonicity_13;
    float inharmonicity_14;
    float inharmonicity_15;
    float inharmonicity_16;
    float inharmonicity_17;
    float inharmonicity_18;
    float inharmonicity_19;
    float inharmonicity_20;
    float inharmonicity_21;
    float inharmonicity_22;
    float inharmonicity_23;
    float inharmonicity_24;
};