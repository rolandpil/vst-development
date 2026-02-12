cmake_minimum_required(VERSION 3.22)

project(VolumeSlider VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

# JUCE path (set in CLion profile as environment variable)
set(JUCE_DIR $ENV{JUCE_DIR})
add_subdirectory(${JUCE_DIR} JUCE)

# ------------------- Plugin Target -------------------
juce_add_plugin(VolumeSlider
        PLUGIN_MANUFACTURER_CODE Juce
        PLUGIN_CODE Dem0
        FORMATS AU VST3 Standalone
        PRODUCT_NAME "VolumeSlider"
)

juce_generate_juce_header(VolumeSlider)

# ------------------- Plugin Sources -------------------
target_sources(VolumeSlider
        PRIVATE
        src/PluginProcessor.cpp
        src/PluginEditor.cpp
        src/Square.cpp
        src/SineWaveChannel.cpp
        src/CustomLookAndFeel.cpp
)

# ------------------- Compile Definitions -------------------
target_compile_definitions(VolumeSlider
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

# ------------------- Link JUCE modules -------------------
target_link_libraries(VolumeSlider
        PRIVATE
        juce::juce_audio_utils
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

# ------------------- BinaryData for Fonts -------------------
juce_add_binary_data(VolumeSlider_BinaryData
        SOURCES
        src/assets/fonts/helvetica-destru-pix.ttf
        src/assets/fonts/AIFRAGME.TTF
        src/assets/fonts/Metropolitan.ttf
        src/assets/fonts/sketchmajor.ttf
)

# Link BinaryData to your actual plugin target
target_link_libraries(VolumeSlider
        PRIVATE
        VolumeSlider_BinaryData
)
