#include <sound.hpp>

void SoundManager::initSoundFiles()
{
    Storage<sf::SoundBuffer>::add("hit", {}).loadFromFile("assets/hit.wav");
}

std::vector<sf::Sound> sounds;

void SoundManager::play(const char* name)
{
    sf::Sound& sound = (sounds.emplace_back(), sounds.back());
    sound.setBuffer(Storage<sf::SoundBuffer>::get(name));
    sound.play();
    if (sounds.size() >= 100)
    {
        std::vector<sf::Sound> newSounds;
        for (unsigned i = sounds.size()- 1; i> sounds.size() - 11; --i)
            newSounds.emplace_back(sounds[i]);
        sounds = newSounds;
    }
}
