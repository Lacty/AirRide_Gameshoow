#pragma once
#include "Obstacle.h"
#include "cinder/gl/Material.h"


namespace ar {
	class ObstaclePopArea : public ar::GameObject {
	public:

		// �N���ʒu �͈� �@���̔��a ��
		ObstaclePopArea(const ci::Vec3f& position_,
						float pop_range_,
						float radius_,
						int count_);

		void update()override;
		void draw()override;
		void transDraw()override;

		std::list<Obstacle> getObstacles() {
			return obstacles;
		}

	private:

		std::list<Obstacle> obstacles;

		// �N���͈͒��a
		float pop_range;

		void obstaclePop(float radius_, int count_);


	private:// �f�o�b�O�p�͈̔�
		void testObstaclePopArea();
		ci::gl::Material test_mt;

	};
}