#pragma once

#include <vector>
#include <iostream>

#include "../shader.h"
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"
#include "../../maths/maths.h"
#include "../renderer2d.h"
#include "../texture.h"
#include "../../physics/rigidbody2d.h"

namespace fireworks { namespace graphics {

    struct VertexData
    {
        maths::vec3 vertex;
        maths::vec2 uv;
        float       tid;
        maths::vec4 color;
    };

    enum class Primitive2D
    {
        Circle,
        Triangle,
        Quad
    };

    class Renderable2D
    {
    public:
        std::uint32_t                       objectID;
        Shader*                             shader;
		bool                                flippedX;
		bool                                flippedY;
        std::vector<components::Component*> components;
    protected:
		maths::vec2                         m_Size;
		maths::vec3                         m_Position;
		maths::vec4                         m_Color;
        float                               m_Rotation;
        Primitive2D                         m_Primitive2D;
mutable std::vector<maths::vec2>            m_UV;
		Texture*                            m_Texture;
    private:
 static std::uint32_t                       m_UniqueID;
    public:
		Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Primitive2D primitive2d)
			: m_Position(position), m_Size(size), m_Color(color), m_Primitive2D(primitive2d), shader(nullptr), m_Texture(nullptr), m_Rotation(0.0f)
		{
            objectID = ++m_UniqueID;
			setUVDefaults();
		}

        Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Primitive2D primitive2d, Shader* shader)
            : m_Position(position), m_Size(size), m_Color(color), m_Primitive2D(primitive2d), shader(shader), m_Texture(nullptr), m_Rotation(0.0f)
        { 
			objectID = ++m_UniqueID;
			shader->enable();
			GLint texIDs[] =
			{
				0, 1,  2,  3,  4,  5,  6,  7,
				8, 9, 10, 11, 12, 13, 14, 15
			};
			shader->setUniform1iv("textures", texIDs, 8);
			shader->disable();

            setUVDefaults();
        }

        virtual ~Renderable2D() { }

        virtual void submit(Renderer2D* renderer) const
        {
            renderer->submit(this);
        }

		template <typename T>
		void AddComponent(components::Component* component)
		{
			components.push_back(component);

			if ((dynamic_cast<physics::RigidBody2D*>(component)))
				std::cout << "Added a rigibody2d component" << std::endl;
		}

		template <>
		void AddComponent<physics::RigidBody2D>(components::Component* component)
		{
			components.push_back(component);
			//if ((dynamic_cast<physics::RigidBody2D*>(component)))
				std::cout << "Added a rigibody2d component in the rigidBody overload" << std::endl;

			this->addedRigidBody2D();
		}

        inline const maths::vec3& getPosition() const { const_cast<Renderable2D*>(this)->GetRigidBody2DPosition();  return m_Position; }
		inline const float& getRotation() const { const_cast<Renderable2D*>(this)->GetRigidBody2DRotation();  return m_Rotation; }
        inline const maths::vec2& getSize() const { return m_Size; }
        inline const maths::vec4& getColor() const { return m_Color; }
		inline const Primitive2D getPrimitive() const { return m_Primitive2D; }
        inline const std::vector<maths::vec2>& getUV() const { return m_UV; }
        inline const Texture* getTexture() const { return m_Texture; }
        inline const GLuint getTID() const { return m_Texture == nullptr ? 0 : m_Texture->getID(); }
        
        // Custom Methods
        void flipX() { flippedX = true; }
        void unflipX() { flippedX = false; }

        void flipY() { flippedY = true; }
        void unflipY() { flippedY = false; }

	protected:
		Renderable2D() : m_Texture(nullptr)
        {
			objectID = ++m_UniqueID;
			setUVDefaults();
		}

        /// Component callback functions
        virtual void addedRigidBody2D() { }
	private:
		void setUVDefaults()
		{
            if (m_Primitive2D == Primitive2D::Quad)
            {
			    m_UV.push_back(maths::vec2(0, 0));  // Bottom Left
			    m_UV.push_back(maths::vec2(0, 1));  // Top Left
                m_UV.push_back(maths::vec2(1, 1));  // Top Right
                m_UV.push_back(maths::vec2(1, 0));  // Bottom Right
            }
            else if (m_Primitive2D == Primitive2D::Triangle)
            {
                m_UV.clear();
				m_UV.push_back(maths::vec2(0, 0));      // Bottom Left
				m_UV.push_back(maths::vec2(0.5, 1));    // Top Middle
				m_UV.push_back(maths::vec2(1, 0));      // Bottom Right
            }
        }
        void GetRigidBody2DPosition()
        {
			for (int i = 0; i < components.size(); i++)
			{
                if (physics::RigidBody2D* rb = (dynamic_cast<physics::RigidBody2D*>(components[i])))
                {
                    m_Position = rb->GetPositionInPixels();
                }
                else
                    return;
			}
        }
        void GetRigidBody2DRotation()
        {
			for (int i = 0; i < components.size(); i++)
			{
				if (physics::RigidBody2D* rb = (dynamic_cast<physics::RigidBody2D*>(components[i])))
				{
					m_Rotation = rb->GetRotation();
				}
				else
					return;
			}
        }
    };

} }
 