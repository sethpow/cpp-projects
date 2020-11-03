#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particlefire {
struct Particle {
	double m_x;
	double m_y;
	double m_xspeed;
	double m_yspeed;

public:
	Particle();
	virtual ~Particle();
	// update position and color of particles
	void update();

};
}

#endif // !PARTICLE_H_