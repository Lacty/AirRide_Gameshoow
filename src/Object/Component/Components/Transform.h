#pragma once
#include "cinder/app/AppNative.h"

class Transform {
public:

	Transform() {
		position = ci::Vec3f::zero();
		angle = ci::Vec3f::zero();
		rotation = ci::Quatf::identity();
		scale = ci::Vec3f(1.0f, 1.0f, 1.0f);
	}

protected:
	// ��ōX�V����

	// �I�C���[�p�ŉ�]
	void rotate(ci::Vec3f angle_) {}

	// �x�N�g���ňړ�
	void translation(ci::Vec3f vec_) {}
	// �ړ�
	void translate(ci::Vec3f translation_) {}

public:
	void console() {
		ci::app::console() << "Position : " << position << std::endl;
		ci::app::console() << "Rotation : " << rotation << std::endl;
	}

public:
	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Quatf rotation;
	ci::Matrix44f local_matrix;
	ci::Vec3f scale;

};
