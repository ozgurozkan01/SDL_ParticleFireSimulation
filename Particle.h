#ifndef SDL_PARTICLEFIRESIMULATION_PARTICLE_H
#define SDL_PARTICLEFIRESIMULATION_PARTICLE_H


class Particle {

private:
    double xCord;
    double yCord;

    double xSpeed;
    double ySpeed;

public:

    double getX() { return xCord; };
    double getY() { return yCord; };

    void update();

    Particle();
    ~Particle();
};


#endif //SDL_PARTICLEFIRESIMULATION_PARTICLE_H
