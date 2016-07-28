#include "UIManager.h"
std::shared_ptr<UIBase> selectUIType(const int& type) {
	switch (type)
	{
	case 0:
		return std::make_shared<CollisionUI>(des::Vec2f(0, 0), des::Vec2f(0, 0));
		break;
	case 1:
		return std::make_shared<FontUI>(des::Vec2f(0, 0), des::Vec2f(0, 0));
		break;
	case 2:
		return std::make_shared<GaugeUI>(des::Vec2f(0, 0), des::Vec2f(0, 0));
		break;
	case 3:
		return std::make_shared<BarCollisionUI>(des::Vec2f(0, 0), des::Vec2f(0, 0));
		break;
	case 4:
		return std::make_shared<TextureUI>(des::Vec2f(0, 0), des::Vec2f(0, 0));
		break;
	}
	return std::make_shared<CollisionUI>(des::Vec2f(0, 0), des::Vec2f(0, 0));
}

UIManager::UIManager() {
	//��ރf�[�^��json�f�[�^�Ŏ擾���邽�߂̃R���X�g���N�^
	UIType::UIType();
	UIObjects::UIObjects();

	//json�f�[�^�̃t�@�C���ǂݍ���
	std::ifstream fs;
	fs.open("../assets/UI/UI.json", std::ios::binary);
	assert(fs);
	picojson::value val;
	fs >> val;
	fs.close();
	std::vector<std::shared_ptr<UIBase>> ui_type_buf;

	//���炩����UI�^�C�v���v�b�V���o�b�N
	//pushBackBuf(ui_type_buf);
	
		
	for (auto it = UIObjects::get().begin(); it != UIObjects::get().end(); it++) {
		//json�f�[�^�̃I�u�W�F�N�g�l�[����UI�^�C�v�ɉ�����
		//ui��insert
		picojson::object player_data(val.get<picojson::object>()["UI"].get<picojson::object>());
		ui_data[*it] = selectUIType(UIType::get()[player_data[(*it)].get<picojson::object>()["UIType"].get<std::string>()]);
		
		//����Pos��json����Z�b�g
		ui_data[(*it)]->setPos(player_data[(*it)].get<picojson::object>()["Pos_x"].get<double>(),
			player_data[(*it)].get<picojson::object>()["Pos_y"].get<double>());

		//����Size��json����Z�b�g
		ui_data[(*it)]->setSize(player_data[(*it)].get<picojson::object>()["Size_x"].get<double>(),
			player_data[(*it)].get<picojson::object>()["Size_y"].get<double>());
		/*for (int i = 0; i < player_data[(*it)].get<picojson::object>()["Number"].get<double>(); i++) {

		}
*/
	}

	
}

void UIManager::update() {
	
	
}