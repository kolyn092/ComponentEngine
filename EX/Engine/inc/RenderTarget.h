///
/// ���� Ÿ�� ���� Ŭ����
/// [2020/11/09 RUNSUMIN]
///
/// ����Ÿ�� Ŭ���� ����
/// [2021/04/13 RUNSUMIN]
#pragma once

#include "DxDefine.h"
#include "D3DDevice.h"

class RenderTarget
{
public:
	RenderTarget();
	~RenderTarget();

	ID3D11Device* m_pDevCopy;					// ����̽� ī��
	ID3D11DeviceContext* m_pDevConCopy;			// ����̽� ���ؽ�Ʈ ī��

	ID3D11Texture2D* m_pRtTex;					// ����Ÿ�ٿ� �׷��� ������
	ID3D11RenderTargetView* m_pRtView;			// ����Ÿ�� ��
	ID3D11ShaderResourceView* m_pRtShaderTex;	// ���̴� ���ҽ�

	/////
	ID3D11Texture2D* m_pRtTexBuff;				// ����/���ٽ� ����(�ؽ���)
	ID3D11DepthStencilView* m_pRtViewScene;		// ����/���ٽ� ��

public:
	void CreateRenderTarget(SIZE size, DXGI_FORMAT fmt , DXGI_FORMAT dsfmt);
	void UpdataRt(Vector4 col);
	void RestoreRt();

private:
	// ����Ÿ�ٿ� �� �ؽ���.
	HRESULT CreateRtTexture(UINT width, UINT height, DXGI_FORMAT format);
	// ����Ÿ�ٿ� ���ҽ���.
	HRESULT CreateRtView(DXGI_FORMAT format);
	// ����Ÿ�ٿ� ���̴� ���ҽ� ��.
	HRESULT CreateRtShaderView(DXGI_FORMAT format);
	// ����Ÿ�ٿ� ����/���ٽ� ��.
	HRESULT CreateRtDepthStencil(UINT width, UINT height, DXGI_FORMAT format);

	void ReleaseRt();

protected:
};

