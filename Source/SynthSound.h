/*
  ==============================================================================

    SynthSound.h
    Created: 29 Jul 2023 7:14:13pm
    Author:  vivek

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class SynthSound : public SynthesiserSound {
public:
    bool appliesToNote(int midiNoteNumber) {
        return true;
    }

    bool appliesToChannel(int midiChannel) {
        return true;
    }
};