#ifndef SDL_PARTICLEFIRESIMULATION_PARTICLE_H
#define SDL_PARTICLEFIRESIMULATION_PARTICLE_H


class Particle {

private:
    double xCord;
    double yCord;

    double speed;
    double direction;

    void init();

public:

    double getX() { return xCord; };
    double getY() { return yCord; };

    void update(int deltaTime);

    Particle();
    ~Particle();
};


#endif //SDL_PARTICLEFIRESIMULATION_PARTICLE_H
