/*
  ==============================================================================

    DecibelSlider.h
    Created: 26 Apr 2019 3:21:14pm
    Author:  212

  ==============================================================================
*/

#pragma once
class DecibelSlider : public Slider
{
public:
    DecibelSlider() {}
    
    double getValueFromText (const String& text) override
    {
        auto minusInfinitydB = -100.0;
        
        auto decibelText = text.upToFirstOccurrenceOf ("dB", false, false).trim();    // [1]
        
        return decibelText.equalsIgnoreCase ("-INF") ? minusInfinitydB
        : decibelText.getDoubleValue();  // [2]
    }
    
    String getTextFromValue (double value) override
    {
        return Decibels::toString (value);
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DecibelSlider)
};
