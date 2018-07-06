//Daniel Goodrum, May 2018
//Sprite Fonts

#ifndef _SpriteFont
#define _SpriteFont

#include <map>
#include <string>
class Sprite;
class Texture;




class SpriteFont
{
public:
	using Key = int;
	using Glyph = Sprite;
	

private:
	Texture* FontTexture;
	using FontMap = std::map<Key, Glyph*>;
	FontMap fontmap;

	void CreateGlyph();

public:
	SpriteFont(std::string path);
	Glyph* GetGlyph(char C);
};


#endif // !_SpriteFont
