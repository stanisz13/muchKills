#include <enemy.hpp>
#include <cstdlib>
#include <ctime>

float max(const float a, const float b)
{
    if ( a > b)
    return a;
    else
    return b;
}

void Enemy::moveAccordingly(const vec2f& toPos, const std::vector<Enemy>& enemies,
const float deltaTime)
{
    vec2f fromOthers(0, 0), fromMed(0, 0);

    vec2f med(0, 0);
    for (auto&& e : enemies)
    {
        med += e.pos;
    }
    med /= enemies.size();

    float avgDist = 0.0f;

    for (auto&& e : enemies)
    {
        vec2f eToMe =  vec2f(e.pos - pos);
        eToMe *= -1.0f;
        float dEToMe = eToMe.lenght();
        eToMe.normalize();
        eToMe /= dEToMe;
        avgDist += eToMe.lenght();

        vec2f medToMe = med - pos;
        float dMed = medToMe.lenght();
        medToMe.normalize();
        medToMe /= dMed;

        fromOthers += eToMe;
        fromMed += medToMe;
    }
    avgDist /= enemies.size();

    fromOthers.normalize();
    fromOthers *= othersAffection;

    fromMed.normalize();
    fromMed *= medAffection;

    vec2f fromDestination = vec2f(toPos - pos).normalize();
    fromDestination *= destAffection;

    srand(time(0));
    float rAffVal = rand()%randAffection;
    vec2f fromRand = vec2f(toPos - pos) +  vec2f(med - pos) * rAffVal;
    fromRand.normalize();
    fromRand *= randAffection;

    vec2f result = fromOthers + fromDestination + fromMed+ fromRand * avgDist * max(avgDistAffection, 20.0);
    result *= deltaTime * speed;

    move(result);
}
