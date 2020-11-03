#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace particlefire {

	Particle::Particle(): m_x(0), m_y(0) {
		m_direction = (2 * 3.14159265359 * rand()) / RAND_MAX;
		m_speed = (0.005 * rand()) / RAND_MAX;
	}

	Particle::~Particle() {

	}

	// update position of particles
	void Particle::update() {
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed;
		m_y += yspeed;
	}

}