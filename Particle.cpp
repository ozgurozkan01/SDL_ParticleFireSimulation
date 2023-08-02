#include "Particle.h"
#include <stdlib.h>
#include <math.h>

Particle::Particle()
{
    init();
}

void Particle::init()
{
    xCord = 0.5;
    yCord = 0.5;
    direction = (2 * M_PI * rand())/RAND_MAX;
    speed = (0.02 * rand()) / RAND_MAX;

    // this makes ore disordered burst of particles.
    speed *= speed;
}

void Particle::update(int deltaTime)
{
    // Increase the radion (angle), so direction will change in every frame
    direction += deltaTime * 0.0003;

    double xSpeed = speed * cos(direction); // cos(direction) gives us x component of direction
    double ySpeed = speed * sin(direction); // sin(direction) gives us y component of direction

    xCord += xSpeed * deltaTime;
    yCord += ySpeed * deltaTime;

    if (xCord < -.5 || yCord < -.25 || xCord > 1.5 || yCord > 1.25)
    {
        init();
    }

    if (rand() < RAND_MAX / 100)
    {
        init();
    }

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