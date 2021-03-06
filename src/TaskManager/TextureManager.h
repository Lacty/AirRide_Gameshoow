#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/imageIo.h"
#include "cinder/Json.h"

#include <unordered_map>

namespace ar
{
	class TextureManager {
	public:

		static TextureManager& get() {
			static TextureManager texturenamager;
			return texturenamager;
		}

		void setup() {
			loadTextTexture(ci::app::getAssetPath("TextureData/TextureData.txt").string());
		}

		ci::gl::TextureRef find(const std::string& findname_) {
			if (texture.find(findname_) == texture.end())
			{
				assert(!"Find Texture Missing");
			}
			return texture.find(findname_)->second;
		}


		void loadTextTexture(const std::string& filepath_) {
			std::ifstream ifs(filepath_);
			std::string key, path;
			while (!ifs.eof())
			{
				ifs >> key;
				ifs >> path;
				registerTexture(key, path);
			}
		}

		void loadJsonTexture(const std::string& filepath_) {
			ci::JsonTree json(filepath_);
			std::string key, path;


		}

		void registerTexture(const std::string& key_, const std::string& filepath_) {
			ci::DataSourceRef data_source = ci::app::loadAsset(filepath_);
			ci::ImageSourceRef image_source = loadImage(data_source);
			texture.insert(std::make_pair(key_, ci::gl::TextureRef(std::make_shared<ci::gl::Texture>(image_source))));
		}

	private:

		std::unordered_map<std::string, ci::gl::TextureRef> texture;
	};
}

#define TextureGet ar::TextureManager::get()
