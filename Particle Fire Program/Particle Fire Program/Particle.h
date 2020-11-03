#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_
using namespace std;

namespace particlefire {
struct Particle {
	double m_x;
	double m_y;
	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();
	// update position and color of particles
	void update();

};
}

#endif // !PARTICLE_H_