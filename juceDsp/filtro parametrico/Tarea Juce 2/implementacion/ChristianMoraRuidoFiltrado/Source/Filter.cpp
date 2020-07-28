/*
  ==============================================================================

    Filter.cpp
    Created: 4 Nov 2018 10:06:56pm
    Author:  Christian R. Mora P.
 
  ==============================================================================
*/

#include "Filter.h"

float Filter::process(float inputValue) {

    buf0 += cutoff * (inputValue - buf0 + feedbackAmount * (buf0 - buf1));
    buf1 += cutoff * (buf0 - buf1);
    switch (mode) {
        case FILTER_MODE_LOWPASS:
            return buf1;
        case FILTER_MODE_HIGHPASS:
            return inputValue - buf1;
        case FILTER_MODE_BANDPASS:
            return buf0 - buf1;
        default:
            return 0.0;
    }
}


/*
void Filter::setCutoff(float newCutoff){
    cutoff = newCutoff; calculateFeedbackAmount();
};
void Filter::setResonance(float newResonance){
    resonance = newResonance; calculateFeedbackAmount();
};
void Filter::setFilterMode(FilterMode newMode){
    mode = newMode;
}

float Filter::process(float inputValue) {
    buf0 += cutoff * (inputValue - buf0);
    buf1 += cutoff * (buf0 - buf1);
    switch (mode) {
        case FILTER_MODE_LOWPASS:
            return buf1;
        case FILTER_MODE_HIGHPASS:
            return inputValue - buf0;
        case FILTER_MODE_BANDPASS:
            return buf0 - buf1;
        default:
            return 0.0;
    }
}
*/
