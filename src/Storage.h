#pragma once

#include <juce_core/juce_core.h>

namespace fxtend
{

/** The folder FXtend keeps its user data in (presets and managed samples). */
inline juce::File getAppDataDirectory()
{
#if JUCE_WINDOWS
    // Windows: keep everything in the user's Documents folder (Documents\CHEEBOW\FXtend)
    return juce::File::getSpecialLocation (juce::File::userDocumentsDirectory)
        .getChildFile ("CHEEBOW")
        .getChildFile ("FXtend");
#else
    return juce::File::getSpecialLocation (juce::File::userApplicationDataDirectory)
   #if JUCE_MAC
        .getChildFile ("Application Support")
   #endif
        .getChildFile ("FXtend");
#endif
}

} // namespace fxtend
