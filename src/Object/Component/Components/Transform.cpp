#include "Transform.h"
using namespace ci;
using namespace ci::app;


void ar::Transform::lookAt(const Transform & target_)
{
	Vec3f target_vec = target_.position - position;

	target_vec.normalize();

	Vec3f cross = direction.cross(target_vec);

	if (cross.lengthSquared() > 0.0f)
	{
		Quatf rotate(cross.normalized(), cross.length());

		rotation = rotation * rotate;
		direction = rotation * Vec3f(0.0f, 0.0f, 1.0f);
	}
}

void ar::Transform::lookAt(const ci::Vec2f & position_)
{

}

void ar::Transform::rotate(const ci::Vec3f& angle_)
{
	Quatf quat_x, quat_y, quat_z;

	quat_x = Quatf(Vec3f(1.0f, 0.0f, 0.0f), angle_.x);
	quat_y = Quatf(Vec3f(0.0f, 1.0f, 0.0f), angle_.y);
	quat_z = Quatf(Vec3f(0.0f, 0.0f, 1.0f), angle_.z);
	
	//rotation = quat_x * quat_y * quat_z;
	rotation = quat_x.toMatrix44() * quat_y.toMatrix44() * quat_z.toMatrix44();
}

void ar::Transform::rotate(ci::Vec3f axis_, float angle_)
{
	rotation = Quatf(axis_, angle_);
}

void ar::Transform::rotate(float angle_x_, float angle_y_, float angle_z_)
{

}

void ar::Transform::translate(const ci::Vec3f& translation_)
{
	position += translation_;
}

void ar::Transform::translate(float x, float y, float z)
{

}

ci::Vec3f ar::Transform::rotateMatrix(const ci::Vec3f & angle_, float z_)
{

	Matrix44f mx = Matrix44f(1, 0, 0, 0,
							 0, cos(angle_.x), -sin(angle_.x), 0,
							 0, sin(angle_.x), cos(angle_.x), 0,
							 0, 0, 0, 1);

	Matrix44f my = Matrix44f(cos(angle_.y), 0, sin(angle_.y), 0,
							 0, 1, 0, 0,
							 -sin(angle_.y), 0, cos(angle_.y), 0,
							 0, 0, 0, 1);

	Vec3f r = Vec3f(0, 0, z_);
	Matrix44f matrix = my * mx;

	return matrix * r;
}