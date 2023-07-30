#include "Particle.h"
#include <stdlib.h>
#include <iostream>

Particle::Particle()
{
    xCord = (1.0 * rand()) / RAND_MAX; // number which rand function returns / max number which rand function can return
    yCord = (1.0 * rand()) / RAND_MAX; // between 0-1;

    xSpeed = 0.001 * ((2.0 * rand()) / RAND_MAX - 1);
    ySpeed = 0.001 * ((2.0 * rand()) / RAND_MAX - 1);
}

void Particle::update()
{
    xCord += xSpeed;
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
    }
}

Particle::~Particle()
{
}