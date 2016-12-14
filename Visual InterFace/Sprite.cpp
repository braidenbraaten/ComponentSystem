#include "Sprite.h"
#include "sfwdraw.h"

namespace bab
{
	Sprite::Sprite()
	{
		//should add a default texture that says no texture on it, so you know you have to change it
	}


	//good for init normal sprites
	Sprite::Sprite(std::string file_path){handle = sfw::loadTextureMap(file_path.c_str());}

	//good for init  sprite grids
	Sprite::Sprite(std::string file_path, int row, int col){sfw::loadTextureMap(file_path.c_str(), row, col);}

	void Sprite::setSpritePath(std::string newFile_path) { handle = sfw::loadTextureMap(newFile_path.data()); filePath = newFile_path; }

	//                                 //GET SETS\\

	unsigned int Sprite::getWidth  (                     ) { return sfw::getTextureWidth(handle); }
	void         Sprite::setWidth  (float new_width      ) { Width = new_width;                   }

	unsigned int Sprite::getHeight (                     ) { return sfw::getTextureHeight(handle);}
	void         Sprite::setHeight (float new_height     ) { Height = new_height;                 }

	float Sprite::getRotation      (                     ) { return rotation;                     }
	void  Sprite::setRotation      (float new_rotation   ) { rotation = new_rotation;             }

	unsigned int Sprite::getTint   (                     ) { return tint;                         }
	void         Sprite::setTint   (unsigned int new_tint) { tint = new_tint;                     }

	Vec2 Sprite::getScale          (                     ) { return scale;                        }
	void Sprite::setScale          (Vec2 new_scale       ) { scale = new_scale;                   }

	Vec2 Sprite::getPos            (                     ) { return pos;                          }
	void Sprite::setPos            (Vec2 new_pos         ) { pos = new_pos;                       }

	std::string Sprite::getFilePath(                     ) { return filePath;                     }
	//setSpritePath will count as the set function for the file path

	//should update this individual sprite
	void Sprite::Update()
	{
		sfw::drawTexture(handle, pos.x, pos.y, sfw::getTextureWidth(handle) * scale.x, sfw::getTextureHeight(handle) * scale.y, rotation, false);


	}
}

														/*   UNWANTED CODE    */


/*void Sprite::setSpriteName(std::string new_name)
{
SpriteName = new_name;
}

std::string Sprite::getSpriteName()
{
return SpriteName;
}*/