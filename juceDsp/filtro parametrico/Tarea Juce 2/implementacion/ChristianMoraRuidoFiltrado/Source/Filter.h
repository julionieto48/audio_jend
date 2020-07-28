/*
  ==============================================================================

    Filter.h
    Created: 4 Nov 2018 10:06:22pm
    Author:  Christian R. Mora P.
 
  ==============================================================================
*/

#pragma once
#include <iostream>
using namespace std;

class Filter {
public:
    enum FilterMode {
        FILTER_MODE_LOWPASS = 0,
        FILTER_MODE_HIGHPASS,
        FILTER_MODE_BANDPASS,
        kNumFilterModes
    };
    Filter() :
    cutoff(0.99), resonance(0.5), mode(FILTER_MODE_LOWPASS),
    buf0(0.0), buf1(0.0)
    {
        calculateFeedbackAmount();
    };
    
    float process(float inputValue);
    
    inline void setCutoff(float newCutoff){
        cutoff = newCutoff; calculateFeedbackAmount();
    };
    inline void setResonance(float newResonance) {
        resonance = newResonance; calculateFeedbackAmount();
    };
    inline void setFilterMode(FilterMode newMode) {
        mode = newMode;
    }
private:
    float cutoff;
    float resonance;
    FilterMode mode;
    double feedbackAmount;
    inline void calculateFeedbackAmount() {
        feedbackAmount = resonance + resonance/(1.0 - cutoff);
    }
    float buf0;
    float buf1;
};

/*
enum FilterMode {
    FILTER_MODE_LOWPASS = 0,
    FILTER_MODE_HIGHPASS,
    FILTER_MODE_BANDPASS,
    kNumFilterModes
};

class Filter {
private:
    FilterMode mode;
    float cutoff;
    float resonance;
    float feedbackAmount;
    inline void calculateFeedbackAmount() {
        feedbackAmount = resonance + resonance/(1.0 - cutoff);
    }
    float buf0;
    float buf1;

public:
    void setFilterMode(FilterMode newMode);
    void setCutoff(float newCutoff);
    void setResonance(float newResonance);
    float process(float inputValue);
    
    Filter() :
    mode(FILTER_MODE_LOWPASS),
    cutoff(0.99),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0)
    {
        calculateFeedbackAmount();
    };
};
 */
