#include <sound.hpp>
#include <thread>

void SoundManager::initSoundFiles()
{
    Storage<sf::SoundBuffer>::add("hit", {}).loadFromFile("assets/hit.wav");
}

std::vector<std::thread> sounds;

void SoundManager::play(const char* name)
{
    sounds.emplace_back([name](){
        sf::Sound sound;
        sound.setBuffer(Storage<sf::SoundBuffer>::get(name));
        sound.play();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    });
}
