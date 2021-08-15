//
//
//
// �Ľ��� �� �����͸� ���� Ŭ����
// [2020/07/30 RUNSUMIN]
#pragma once
#include "DxDefine.h"
#include "AseModel.h"
#include "D3DDevice.h"
#include "Shader.h"
#include <vector>

class ModelObject
{
public:
	ModelObject();
	~ModelObject();

	AseModel* m_pObj;
	Shader* m_pShader;

	// ������� ������
	CBDEFAULT	m_CbDef;	// ��� ����
	CBMATERIAL  m_CbMtl;	// ���� ����

	ID3D11Buffer* m_pCBDef;		//�⺻���� ���� �������.
	ID3D11Buffer* m_pCBMtl;		//�������� ���� �������

	ID3D11Device* m_pDeviceCopy;
	ID3D11DeviceContext* m_pDeviceCtCopy;

	// ���� �� ���ۿ�
	XMMATRIX m_UserTm;
	XMMATRIX m_Transm;
	XMMATRIX m_Rotm;
	XMMATRIX m_Scalem;

	Vector3 m_vPos;
	Vector3 m_vRot;
	Vector3 m_vScale;




public:
	int LoadModelFromFile(TCHAR* filename, ID3D11Device* pdevice , ID3D11DeviceContext* pDeviceContext);
	int initModel();								// �𵨿� �ʿ��� ����̽� ��ġ�� �����ɴϴ�.
	int initShader();								// �𵨿� �ʿ��� ���̴� ������ �����ɴϴ�.
	bool ModelUpdate(float dTime);
	bool ModelDraw(float dTime);

	void ModelRelease();
};

