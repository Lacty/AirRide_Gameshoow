#pragma once
#include "Object/GameObject/GameObject.h"
#include "Object/Component/Components/Color.h"
#include "Input/InputEvent.h"

namespace ar {

	// サンプル（コンポーネントの使いかたの例）
	class SampleObject : public GameObject {
	public:

		SampleObject() {
			setup();
		}

		void setup()override {
			transform.position = ci::Vec3f(0.0f, 0.0f, 10.0f);

			addComponent<ar::Color>(ci::ColorA(1.0f, 1.0f, 1.0f));
			c_color = getComponent<Color>();
		}

		void update()override {
			if (env.isPush(ci::app::KeyEvent::KEY_1))
			{
				c_color->setColor(ci::ColorA(1.0f, 0.0f, 0.0f));
				changeangle = ci::Vec3f::zero();
			}
			else if (env.isPush(ci::app::KeyEvent::KEY_2))
			{
				c_color->setColor(ci::ColorA(0.0f, 1.0f, 0.0f));
			}

			transform.rotate(changeangle);

			if (env.isPress(ci::app::KeyEvent::KEY_3))
			{
				changeangle.x += 0.1f;
			}
			if (env.isPress(ci::app::KeyEvent::KEY_4))
			{
				changeangle.y += 0.1f;
			}
			if (env.isPress(ci::app::KeyEvent::KEY_5))
			{
				changeangle.z += 0.1f;
			}
			if (env.isPress(ci::app::KeyEvent::KEY_6))
			{
				changeangle += 0.1f;
			}
		}

		void draw()override {
			ci::gl::drawColorCube(ci::Vec3f::zero(), ci::Vec3f(1.0f, 1.0f, 1.0f));
		}

	private:

		std::shared_ptr<Color> c_color;

		ci::Vec3f changeangle;
	};

}