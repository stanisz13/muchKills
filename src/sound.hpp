#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <Storage.hpp>

struct SoundManager
{
    static void initSoundFiles();
    static void play(const char* name);
};
