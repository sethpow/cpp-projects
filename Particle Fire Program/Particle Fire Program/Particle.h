#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_
using namespace std;

namespace particlefire {
struct Particle {
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	// update position and color of particles
	void update();

};
}

#endif // !PARTICLE_H_