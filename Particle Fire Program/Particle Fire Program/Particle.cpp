#include "Particle.h"
#include <stdlib.h>

namespace particlefire {

	Particle::Particle() {
		// random # between 0 and const max
		m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;
		// particle speed
		m_xspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
		m_yspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);

	}

	Particle::~Particle() {

	}

	// update position and color of particles
	void Particle::update() {
		m_x += m_xspeed;
		m_y += m_yspeed;

		if (m_x <= -1 || m_x >= 1.0) {
			m_xspeed = -m_xspeed;
		}

		if (m_y <= -1 || m_y >= 1.0) {
			m_yspeed = -m_yspeed;
		}
	}

}