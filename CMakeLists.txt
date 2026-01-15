cmake_minimum_required(VERSION 4.1)
project(TestPlugin)

set(CMAKE_CXX_STANDARD 14)

include_directories(JuceLibraryCode)
include_directories(Source)

add_executable(
        TestPlugin
        JuceLibraryCode/JuceHeader.h
        JuceLibraryCode/JucePluginDefines.h
        Source/PluginEditor.cpp
        Source/PluginEditor.h
        Source/PluginProcessor.cpp
        Source/PluginProcessor.h
)
