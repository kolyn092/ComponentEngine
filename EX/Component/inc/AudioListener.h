#pragma once
#include "Component.h"

namespace ComponentEngine
{
	class AudioListener : public Component, public DirectX::AudioListener
	{

	public:
		float m_Volume;
		bool m_isPause;

	private:
		bool m_ActiveState;

	public:
		AudioListener();
		virtual ~AudioListener();

	public:
		virtual void Awake() override;

		virtual void Update(float dTime) override;

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

