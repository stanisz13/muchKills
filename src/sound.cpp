#include <sound.hpp>

void SoundManager::initSoundFiles()
{
    Storage<sf::SoundBuffer>::add("hit", {}).loadFromFile("hit.mp3");
}

void SoundManager::play(const char* name)
{
    sf::Sound sound;
    sound.setBuffer(Storage<sf::SoundBuffer>::get(name));
    sound.play();
}
