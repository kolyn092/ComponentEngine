//
//
//
// 
// [2020/07/26 RUNSUMIN]
#pragma once

#include "DxDefine.h"
#include "D3DDevice.h"

class Shader
{
public:
	Shader();
	~Shader();

public:
	// ���������
	ID3D11VertexShader* m_pVS;			// ���� ���̴� �������̽�
	ID3D11PixelShader* m_pPS;			// �ȼ� ���̴� �������̽�
	ID3DBlob* m_pVSCode;				// ������ �ڵ� ��ü
	ID3D11InputLayout* m_pVBLayout;		// ���� �Է� ���̾ƿ�

public:
	// ���� ���̴� �ε� �Լ�
	HRESULT ShaderLoad(const TCHAR* fxname, ID3D11Device* pDevice);

	// ���� �Է±��� ����
	HRESULT CreateVBLayOut(D3D11_INPUT_ELEMENT_DESC layout[], UINT layoutsize, ID3D11Device* pDevice);

	// ���� ������� ����
	HRESULT CreateDynamicConstantBuffer(UINT size, LPVOID pdata, ID3D11Buffer** ppConstantbuff,
		ID3D11Device* pDevice);

	// ���� ������� ����
	HRESULT UpdateDynamicConstantBuffer(ID3D11DeviceContext* pDXDC, ID3D11Resource* pBuff, LPVOID pData,
		UINT size);

public:
	void ShaderRelease();


};

