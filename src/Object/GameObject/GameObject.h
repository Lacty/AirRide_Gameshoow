#pragma once

#include "cinder/app/AppNative.h"

#include "../Object.h"
#include "../Component/Component.h"
#include "../Component/Components/Transform.h"
#include <unordered_map>
#include <string>
#include <typeinfo>

namespace ar {

	// 描画されるものに継承されるクラス
	class GameObject : public Object {
	public:

		GameObject();
		GameObject(const std::string& name_);

		void setIsActive(const bool& is_active_) { is_active = is_active_; }
		bool getIsActive() { return is_active; }

		virtual void setup() {};
		virtual void update() {};
		virtual void laterUpdate() {};
		virtual void draw() {};
		virtual void transDraw() {};
		virtual void laterDraw() {};
		virtual void transLaterDraw() {};

		void componentsUpdate();

		void drawBegin();
		void drawEnd();
		void componentsDraw();

		void componentsDestroy();

	public:

		void pushModelView();
		void popModelView();

	public:

		Transform transform;

	private:
		bool is_active;

	public:

		// コンポーネントの追加
		template<typename T>
		void addComponent() {
			std::string componentname = createComponentName<T>();

			if (components.find(componentname) == components.end())
				components.insert(std::make_pair(componentname, std::make_shared<T>()));
		}

		// コンポーネントの追加(コンストラクタあり)
		template<typename T>
		void addComponent(const T& component_) {
			std::string componentname = createComponentName<T>();

			if (components.find(componentname) == components.end())
				components.insert(std::make_pair(componentname, std::make_shared<T>(component_)));
		}

		// コンポーネントの取得
		template<typename T>
		std::shared_ptr<T> getComponent() {
			int script_size = sizeof(T);

			std::string componentname = createComponentName<T>();
			if (components.find(componentname) == components.end())
			{
				assert(!"Component Not Finded");
			}

			if (script_size > 128)
			{
				return std::dynamic_pointer_cast<T>(components.find(componentname)->second);
			}
			else
			{
				return std::static_pointer_cast<T>(components.find(componentname)->second);
			}
		}

	private:
		template<typename T>
		static std::string createComponentName() {
			const type_info& id = typeid(T);

			std::string class_name = id.name();
			class_name.erase(0, 6);

			return class_name;
		}

	private:

		std::unordered_map<std::string, std::shared_ptr<Component>> components;
	};

}