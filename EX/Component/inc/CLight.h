#pragma once
#include "Component.h"

namespace ComponentEngine
{
	class CLight : public Component
	{

	private:
		enum class eLightType
		{
			SPOT, DIRECTIONAL, POINT,
		};

		enum class eShadowType
		{
			NONE, SOFT, HARD,
		};

	private:
		GRAPHICENGINE::IDirectionLightInterface* m_Light;

		Color m_FogColor;				// �Ȱ� �÷�
		float m_FogDensity;				// �Ȱ� �е� (0�� �������� ������. 1�� �������� £������)
		bool m_FogActive;				// �Ȱ� ON / OFF (default ON)

		eLightType m_LightType;			// ���� Ÿ��
		int m_Range;					// ������ ����
		Color m_Color;					// ������ �÷�
		float m_Intensity;				// ���� ���. Unity ���� Directional 0.5 / ������ 1
		float m_IndirectMultiplier;		// ������ ����

		eShadowType m_ShadowType;		// �׸��� Ÿ�� (����, ����Ʈ, �ϵ�)

		//////////////////////////////////////////////////////////////////////////

		// Matrix	/		shadow matrix override
		//			/		light baking output
		// int		/		culling mask
		// int		/		rendering layer mask
		// enum		/		light shadow caster mode
		// float	/		shadow strength
		// enum		/		light shadow resolution
		// float	/		shadow softness
		// float	/		shadow softness fade
		//			/		flare
		// Texture	/		texture cookie
		//			/		light render mode
		// Vector2	/		area size
		//			/		lightmapping mode
		// float[]	/		layer shadow cull distances
		// float	/		range
		// bool		/		already light mapped
		// bool		/		use shadow matrix override
		
		// float	/		spot angle

	private:
		bool m_ActiveState;

	public:
		CLight();
		CLight(eLightType lightType);
		virtual ~CLight();

	public:
		void SetColor(Color col) { m_Color = col; }
		void SetRange(int range) { m_Range = range; }
		void SetIntensity(float value) { m_Intensity = value; }
		void SetAmbient(float value) { m_IndirectMultiplier = value; }

		void SetFogActive(bool state);
		void SetFogColor(Color col);
		void SetFogDensity(float value);

	public:
		virtual void Awake() override;

		virtual void LateUpdate(float dTime) override;

		virtual void DebugTextRender() override;

		virtual void OnQuit() override;
		virtual void OnDisable() override;
		virtual void OnDestroy() override;

		virtual void SetActive(bool value) override;
		virtual bool isActive() override { return m_ActiveState; }

	public:
		virtual void Bind(GameObject* obj) override;
	};
}

