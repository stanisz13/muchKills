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
}
