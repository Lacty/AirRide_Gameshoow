#pragma once
#include <iostream>

namespace ar {

	// ���ׂĂ̌�
	class Object {
	public:

		Object();
		Object(const std::string& name_);

		virtual void destory() {}

	public:

		void setName(const std::string& name_) { name = name_; }
		std::string getName() { return name; }

	protected:

		std::string name;

	};

}