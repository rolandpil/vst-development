cmake_minimum_required(VERSION 3.22)

project(VolumeSlider VERSION 0.0.1)

# SET IN YOUR CLION PROFILE [ENVIRONMENT: JUCE_DIR=/path_to_your_application"
set(JUCE_DIR $ENV{JUCE_DIR})
add_subdirectory(${JUCE_DIR} JUCE)

juce_add_plugin(VolumeSlider
        PLUGIN_MANUFACTURER_CODE Juce
        PLUGIN_CODE Dem0
        FORMATS AU VST3 Standalone
        PRODUCT_NAME "VolumeSlider"
)

juce_generate_juce_header(VolumeSlider)

target_sources(VolumeSlider
        PRIVATE
        src/PluginEditor.cpp
        src/PluginProcessor.cpp
)

target_compile_definitions(VolumeSlider
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(VolumeSlider
        PRIVATE
        juce::juce_audio_utils
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)