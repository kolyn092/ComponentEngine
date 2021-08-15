#pragma once

#include "DxDefine.h"
#include "vector"
#include "AseNode.h"
#include "AseParser.h"
#include "locale.h"	
#include "Collision2D.h"
struct MODEL_MATERIAL
{
	TCHAR	m_MtlTexName[256];	// ���� ���� �� �ؽ��� ���ϸ� 
	TCHAR	m_Texname[256];	// ���� ���� �� �ؽ��� ���ϸ� 
	XMFLOAT4 m_Diffuse;			// Ȯ�걤
	XMFLOAT4 m_Ambient;			// �ֺ���
	XMFLOAT4 m_Specular;		// ����ŧ��
	FLOAT	 m_SpcePower;		// ����ŧ�� �Ŀ�

	UINT	m_MtlCount;			// ���� ����

	ID3D11ShaderResourceView* m_pTexture;	// ���� �ؽ���

	BOOL	m_bTexOn;

};
class Collision2D;

class AseModel
{
public:
	// ������ & �Ҹ��� 
	AseModel();
	~AseModel();
public:

	TCHAR	m_FileName[256];	//���ϸ� 
	TCHAR	m_NodeName[256];	//���(�޽�) �̸� 

	MODEL_MATERIAL* m_ModelMtlList;		// ���� ���� ����Ʈ

	std::vector<AseNode*> m_NodeList;	// ��� ���� ����Ʈ
	std::vector<AseNode*> m_BoneList;	// ���� ���� ����Ʈ
	std::vector<AseNode*> m_CollList;	// �浹 ���� ����Ʈ
	AseNode* m_Weapon;


	AseNode* m_RootNode;				// ��Ʈ

	std::vector<AseNode*> m_RootNodeList;//

	int m_MtlCnt;						// ���� ����
	bool m_bAniEnd;						// �ִϸ��̼� ����

public:
	// ã������ �̸��� �θ�� ������ �ִ� ��带 �����Ѵ�.
	AseNode* FindParentNodeName(const TCHAR* name);
	int FindBoneindexbyName(const TCHAR* name);

	void MakeTM(AseNode* pnode);

	void MakeTM_Fors(std::vector<AseNode*> pnodeList);

	// �ִϸ��̼� ������ ���� �����Ͱ� ������Ʈ ��� ���ָ� ��
	void MakeFinalTm();
	// ����
	int m_FirstFrame;
	int m_LasrFrame;
	int m_FrameSpeed;
	int m_TickPerFrame;

	// ���� �ð� ����
	int m_CurrTime;
	float m_SaveTime;

	int GetCurrTime(float dTime);

public:
	int initializeModel();
	BOOL AseModelUpdate(float dTime , XMMATRIX usertm);
	void AseModelRelease();

	int ShowModelInfo();

public:
	int Generate();
};

// �� �ε�, ����
int  ModelCreateFromASE(ID3D11Device* pDev, TCHAR* filename, AseModel** ppModel , ID3D11DeviceContext* pDevContext);

// �� ����.
void ModelRelease(AseModel*& ppModel);