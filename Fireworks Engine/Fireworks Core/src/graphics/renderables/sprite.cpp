#include "sprite.h"

namespace fireworks { namespace graphics {

    Sprite::Sprite(float x, float y, float width, float height, maths::vec4 color)
        : Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color), position(m_Position), color(m_Color), sprframe(m_Frame)
    {

    }

    Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
        : Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), maths::vec4(1, 0, 1, 1)), position(m_Position), color(m_Color), sprframe(m_Frame)
    {
        m_Texture = texture;
    }

	Sprite::Sprite(float x, float y, float width, float height, Texture* texture, int frame)
		: Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), maths::vec4(1, 0, 1, 1), frame), position(m_Position), color(m_Color), sprframe(m_Frame)
	{
		m_Texture = texture;
	}

} }
