#include "Particle.h"
#include <stdlib.h>
#include <math.h>

Particle::Particle() : xCord(0.5), yCord(0.5)
{
    direction = (2 * M_PI * rand())/RAND_MAX;
    speed = (0.0005 * rand()) / RAND_MAX;
}

void Particle::update(int deltaTime)
{
    double xSpeed = speed * cos(direction); // cos(direction) gives us x component of direction
    double ySpeed = speed * sin(direction); // sin(direction) gives us y component of direction

    xCord += xSpeed * deltaTime;
    yCord += ySpeed * deltaTime;

    /*xCord += xSpeed;
    yCord += ySpeed;

    // 0 and 1 is border check values. We have checked in here,
    // We checked if the particle crossed the border.
    if (xCord <= 0 || xCord >= 1.0)
    {
        xSpeed = -xSpeed;
    }

    if (yCord <= 0 || yCord >= 1.0)
    {
        ySpeed = -ySpeed;
    }*/
}

Particle::~Particle()
{
}