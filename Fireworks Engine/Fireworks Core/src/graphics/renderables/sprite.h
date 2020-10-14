#pragma once

#include "renderable2d.h"
#include "../../utils/timer.h"

namespace fireworks { namespace graphics {

    enum class SpriteAnimationType
    {
        LOOP,
        REVERSE,
        PING_PONG
    };
    class Sprite : public Renderable2D
    {
    public:
        mutable uint32_t    frame;
        uint32_t            frameRate;
		maths::vec3&        position;
		maths::vec4&        color;
	private:
		maths::vec2         m_SpriteSheetDimension;
		utils::Timer*       m_AnimTimer;
        double              m_CurrentFrameRate;
    public:
        // To use with BatchRenderer
        Sprite(maths::vec3 position, maths::vec2 size, maths::vec4 color);
		Sprite(maths::vec3 position, maths::vec2 size, Texture* texture);

        // To use with a SimpleRenderer
		Sprite(maths::vec3 position, maths::vec2 size, maths::vec4 color, Shader* shader);
		Sprite(maths::vec3 position, maths::vec2 size, Shader* shader,Texture* texture);
		Sprite(maths::vec3 position, maths::vec2 size, Shader* shader, Texture* texture, maths::vec2 sheetDimension);

        void animateSprite(uint32_t frameRate, SpriteAnimationType animType);

		inline const uint32_t getTotalFrames() const { return (m_SpriteSheetDimension.x * m_SpriteSheetDimension.y); }
    private:    
        void submit(Renderer2D* renderer) const override;
        void setSpriteSheetUV() const;
    };
} }
