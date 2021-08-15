//
//
//
// �������̽� - ���µ� ������
// ���Ŀ� �ٸ� API ���� Ȯ������ ����Ͽ� ����
// [2020/12/07 RUNSUMIN]
#pragma once
#include <windows.h>	// ������ �ڵ�..
#include <SimpleMath.h>	// ���� ���

// ���� ���
enum class RenderState
{
	e_CullBack, //Default
	e_CullFront,
	e_WireFrame,
	e_Solid
};

namespace GRAPHICENGINE
{
	// �̱��� ������ ���Ŀ� ���
	class IDevInterface abstract
	{
	public:
		/// Device
		// ���� ����
		virtual bool EngineSetUp(HWND hwnd)	abstract;	
		// �׸��� ����
		virtual void BeginRend(Vector4 backbuffercolor)	abstract;
		// �׸��� ����
		virtual void EndRend() abstract;
		// ���� ����
		virtual void Release() abstract;
		// ���� Ÿ�� �޾ƿ���
		virtual float GetEngineTime() abstract;
		// ���� ��� ����
		virtual void ChangeRenderState(RenderState renderstate) abstract;
		// â ũ�� ����

		// â ��� ����

		/// Camera
	};

	class ICameraInterface abstract
	{

	};

}

