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
        envelope_1.trigger = 1;
        envelope_2.trigger = 1;
        envelope_3.trigger = 1;
        envelope_4.trigger = 1;
        envelope_5.trigger = 1;
        envelope_6.trigger = 1;
        envelope_7.trigger = 1;
        envelope_8.trigger = 1;

        pitchEnvelope.trigger = 1;
        
        driveEnvelope.trigger = 1;
    }

    void stopNote(float velocity, bool allowTailOff) override {
        envelope_0.trigger = 0;
        envelope_1.trigger = 0;
        envelope_2.trigger = 0;
        envelope_3.trigger = 0;
        envelope_4.trigger = 0;
        envelope_5.trigger = 0;
        envelope_6.trigger = 0;
        envelope_7.trigger = 0;
        envelope_8.trigger = 0;
        
        pitchEnvelope.trigger = 0;

        driveEnvelope.trigger = 0;

        if (envelope_0.adsr(wave_0, envelope_0.trigger) == 0
            && envelope_1.adsr(wave_1, envelope_0.trigger) == 0
            && envelope_2.adsr(wave_2, envelope_1.trigger) == 0
            && envelope_3.adsr(wave_3, envelope_2.trigger) == 0
            && envelope_4.adsr(wave_4, envelope_3.trigger) == 0
            && envelope_5.adsr(wave_5, envelope_4.trigger) == 0
            && envelope_6.adsr(wave_6, envelope_5.trigger) == 0
            && envelope_7.adsr(wave_7, envelope_6.trigger) == 0
            && envelope_8.adsr(wave_8, envelope_7.trigger) == 0
            ) {
            clearCurrentNote();
        }
    }

    void pitchWheelMoved(int newPitchWheelValue) override {

    }

    void controllerMoved(int controllerNumber, int newControllerValue) override {

    }

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override {
        for (int sample = 0; sample < numSamples; sample++) {
            float currentPitch = pitchEnvelope.adsr(peakPitch, pitchEnvelope.trigger);

            wave_0 = envelope_0.adsr(oscilator_0.sinewave(frequency + currentPitch) * magnitude_0, envelope_0.trigger);
            wave_1 = envelope_1.adsr(oscilator_1.sinewave(2 * frequency + 2 * currentPitch) * magnitude_1, envelope_1.trigger);
            wave_2 = envelope_2.adsr(oscilator_2.sinewave(3 * frequency + 3 * currentPitch) * magnitude_2, envelope_2.trigger);
            wave_3 = envelope_3.adsr(oscilator_3.sinewave(4 * frequency + 4 * currentPitch) * magnitude_3, envelope_3.trigger);
            wave_4 = envelope_4.adsr(oscilator_4.sinewave(5 * frequency + 5 * currentPitch) * magnitude_4, envelope_4.trigger);
            wave_5 = envelope_5.adsr(oscilator_5.sinewave(6 * frequency + 6 * currentPitch) * magnitude_5, envelope_5.trigger);
            wave_6 = envelope_6.adsr(oscilator_6.sinewave(7 * frequency + 7 * currentPitch) * magnitude_6, envelope_6.trigger);
            wave_7 = envelope_7.adsr(oscilator_7.sinewave(8 * frequency + 8 * currentPitch) * magnitude_7, envelope_7.trigger);
            wave_8 = envelope_8.adsr(oscilator_8.sinewave(9 * frequency + 9 * currentPitch) * magnitude_8, envelope_8.trigger);

            double sound = (wave_0 + wave_1 + wave_2 + wave_3 + wave_4 + wave_5 + wave_6 + wave_7 + wave_8) / (magnitude_0 + magnitude_1 + magnitude_2 + magnitude_3 + magnitude_4 + magnitude_5 + magnitude_6 + magnitude_7 + magnitude_8 + FLT_EPSILON);

            float currentDrive = Decibels::decibelsToGain(driveEnvelope.adsr(peakDrive, driveEnvelope.trigger));
            sound *= currentDrive;

            if (sound > 1) sound = 1;
            else if (sound < -1) sound = -1;
            

            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++) {
                outputBuffer.addSample(channel, startSample, sound);
            }

            startSample++;
        }
    }

    void getPitchParameters(float pitch, float pitchDecay) {
        pitchEnvelope.setAttack(0);
        pitchEnvelope.setDecay(pitchDecay);
        pitchEnvelope.setSustain(0.1);
        pitchEnvelope.setRelease(100.0);

        peakPitch = frequency * pow(2, pitch / 12.0) - frequency;
    }

    void getDriveParameters(float drive, float driveDecay) {
        driveEnvelope.setAttack(0);
        driveEnvelope.setDecay(driveDecay);
        driveEnvelope.setSustain(0.1);
        driveEnvelope.setRelease(100.0);

        peakDrive = drive;
    }
    
    void getParameters_0(float attack, float decay, float sustain, float release, float magnitude) { 
        envelope_0.setAttack(attack);
        envelope_0.setDecay(decay);
        envelope_0.setSustain(sustain);
        envelope_0.setRelease(release);

        magnitude_0 = magnitude;
    }

    void getParameters_1(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_1.setAttack(attack);
        envelope_1.setDecay(decay);
        envelope_1.setSustain(sustain);
        envelope_1.setRelease(release);

        magnitude_1 = magnitude;
    }

    void getParameters_2(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_2.setAttack(attack);
        envelope_2.setDecay(decay);
        envelope_2.setSustain(sustain);
        envelope_2.setRelease(release);

        magnitude_2 = magnitude;
    }

    void getParameters_3(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_3.setAttack(attack);
        envelope_3.setDecay(decay);
        envelope_3.setSustain(sustain);
        envelope_3.setRelease(release);

        magnitude_3 = magnitude;
    }

    void getParameters_4(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_4.setAttack(attack);
        envelope_4.setDecay(decay);
        envelope_4.setSustain(sustain);
        envelope_4.setRelease(release);

        magnitude_4 = magnitude;
    }

    void getParameters_5(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_5.setAttack(attack);
        envelope_5.setDecay(decay);
        envelope_5.setSustain(sustain);
        envelope_5.setRelease(release);

        magnitude_5 = magnitude;
    }

    void getParameters_6(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_6.setAttack(attack);
        envelope_6.setDecay(decay);
        envelope_6.setSustain(sustain);
        envelope_6.setRelease(release);

        magnitude_6 = magnitude;
    }

    void getParameters_7(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_7.setAttack(attack);
        envelope_7.setDecay(decay);
        envelope_7.setSustain(sustain);
        envelope_7.setRelease(release);

        magnitude_7 = magnitude;
    }

    void getParameters_8(float attack, float decay, float sustain, float release, float magnitude) {
        envelope_8.setAttack(attack);
        envelope_8.setDecay(decay);
        envelope_8.setSustain(sustain);
        envelope_8.setRelease(release);

        magnitude_8 = magnitude;
    }

private:
    double frequency;

    double wave_0;
    double wave_1;
    double wave_2;
    double wave_3;
    double wave_4;
    double wave_5;
    double wave_6;
    double wave_7;
    double wave_8;

    maxiOsc oscilator_0;
    maxiOsc oscilator_1;
    maxiOsc oscilator_2;
    maxiOsc oscilator_3;
    maxiOsc oscilator_4;
    maxiOsc oscilator_5;
    maxiOsc oscilator_6;
    maxiOsc oscilator_7;
    maxiOsc oscilator_8;

    maxiEnv envelope_0;
    maxiEnv envelope_1;
    maxiEnv envelope_2;
    maxiEnv envelope_3;
    maxiEnv envelope_4;
    maxiEnv envelope_5;
    maxiEnv envelope_6;
    maxiEnv envelope_7;
    maxiEnv envelope_8;

    float magnitude_0;
    float magnitude_1;
    float magnitude_2;
    float magnitude_3;
    float magnitude_4;
    float magnitude_5;
    float magnitude_6;
    float magnitude_7;
    float magnitude_8;

    float peakPitch;
    maxiEnv pitchEnvelope;

    float peakDrive;
    maxiEnv driveEnvelope;
};