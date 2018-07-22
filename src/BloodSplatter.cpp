#include "BloodSplatter.hpp"


BloodSplatter::BloodSplatter(vec2f position, vec2f force, int dropsNum)
{
    pos = position;

    drops.reserve(dropsNum);

    sf::Texture* texts[] = {
        &Storage<sf::Texture>::get("blood0"),
        &Storage<sf::Texture>::get("blood1"),
        &Storage<sf::Texture>::get("blood2"),
        &Storage<sf::Texture>::get("blood3"),
        &Storage<sf::Texture>::get("blood4")
    };


    for(int i = 0; i < dropsNum; i++)
    {
        //float angleFract = (float)i/dropsNum;

        vec2f Pos = pos;
        vec2f dir = vec2f(rand()%(2*dropsNum+1)-dropsNum, rand()%(2*dropsNum+1)-dropsNum);
        dir.normalize();

        dir += force;

        float maxSpeed = 100.f;
        float minSpeed = 60.f;

        float speed = minSpeed + rand()%((int)maxSpeed-(int)minSpeed);
        float lifeTime = 0.5 + float(rand()%100+1)/100.f;

        //auto& tex = Storage<sf::Texture>::get("blood0");
        
        drops.emplace_back(Pos, dir, speed, lifeTime, *texts[rand()%5]);
    }
}

void BloodSplatter::update(float deltaTime)
{
    bool allFinished = true;

    for(auto& drop : drops)
    {
        drop.update(deltaTime);

        if(!drop.isFinished())
            allFinished = false;
    }

    if(allFinished)
    {
        drops.clear();
    }
}

void BloodSplatter::draw(sf::RenderWindow& window)
{
    for(auto& drop : drops)
        drop.draw(window);
}



BloodSplatter::BloodDrop::BloodDrop(vec2f position, vec2f direction, float sped, float LifeTime, sf::Texture& tex)
{
    pos = position;
    dir = direction;
    speed = sped;
    initialSpeed = sped;
    lifeTime = LifeTime;
    timeLived = 0;

    sprite.setTexture(tex);
    sprite.setOrigin(tex.getSize().x/2, tex.getSize().y/2);
}

void BloodSplatter::BloodDrop::update(float deltaTime)
{
    pos += vec2f(
        dir.x * speed * deltaTime, 
        dir.y * speed * deltaTime
        );

    //speed = speed * pow(0.9, 10001/deltaTime);
    //speed = initialSpeed * pow(0.9, lifeTime/time);
    speed = speed * pow(0.1, deltaTime/0.5);

    timeLived += deltaTime;
}

void BloodSplatter::BloodDrop::draw(sf::RenderWindow& window)
{
    sprite.setPosition(pos);
    float fract = (float)timeLived/lifeTime;
    sprite.setRotation(fract * speed);

    float minBright = 120;
    int curColor = minBright + (1.0-fract)*(255-minBright);
    sprite.setColor(sf::Color(curColor, curColor, curColor, 255)); // green

    float minScale = 0.4;

    float scale = minScale + (1.0-fract*fract*fract) * (1.f-minScale);
    sprite.setScale(sf::Vector2f(scale, scale));

    if(!isFinished())
        window.draw(sprite);
}
