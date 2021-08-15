//
//
//
// Ase Node Ŭ���� ����
// [2020/07/27 RUNSUMIN]

#pragma once

#include "DxDefine.h"
#include "D3DDevice.h"
#include <list>

typedef XMVECTOR QUATERNIONA;

// ���� ����ü �� ����.
struct VERTEX_ASE
{
	VECTOR3 vPos;
	COLOR   dwColor;

	// ��Ų ������
	VECTOR4 vbWeight;
	DWORD	m_Index[4];
};

// ���� ����ü �� ����(Normal �߰�)
struct VERTEX_ASE_NORMAL
{
	VECTOR3 vFcNormal;
	VECTOR3 vVtNormal_1;
	VECTOR3 vVtNormal_2;
	VECTOR3 vVtNormal_3;
};

// ���� ����ü(Ȯ��, FaceList�� ���� �븻�� �־��� ����ü) - ���� ����ü!
struct VERTEX_ASE_EXTEND
{

	VECTOR4 vbWeight;
	DWORD	m_Index[4];
	VECTOR3 vPos;
	VECTOR3 vNormal;
	VECTOR2 vUv;

};

// Face ����ü  
struct FACE_ASE
{
	DWORD A, B, C;		//32Bit..
};

// �ؽ��� ��ǥ ���� ����ü
struct TEX_UV
{
	VECTOR2 vVertexUV;
};

struct MATERIAL
{
	// ���� ����
	XMFLOAT4 m_Diffuse;			// Ȯ�걤
	XMFLOAT4 m_Ambient;			// �ֺ���
	XMFLOAT4 m_Specular;		// ����ŧ��
	FLOAT	 m_SpcePower;		// ����ŧ�� �Ŀ�
	BOOL	 m_bTexOn;			// �ؽ��� ����...
};

struct MATERIAL_ASE
{
	// ���� ����
	TCHAR	m_MtlTexName[256];	// ���� ���� �� �ؽ��� ���ϸ� 
	XMFLOAT4 m_Diffuse;			// Ȯ�걤
	XMFLOAT4 m_Ambient;			// �ֺ���
	XMFLOAT4 m_Specular;		// ����ŧ��
	FLOAT	 m_SpcePower;		// ����ŧ�� �Ŀ�

	int		m_Count;
};

struct ANIKEY_POS
{
	DWORD m_PosTickTime;
	float x, y, z;
};

struct ANIKEY_ROT
{
	DWORD m_RotTickTime;
	float x, y, z;
	float Angle;
	bool  MakeFrameZero;
};

struct KEY_POS
{
	DWORD		m_TickTime;
	VECTOR3		m_Pos;
};

struct KEY_ROT
{
	DWORD		m_TickTime;
	VECTOR3		m_RotAxis;
	float		m_Angle;
	QUATERNIONA m_RotQ;
};

struct SKIN_DATA
{
	int		m_Id;				// ī����..
	float	m_Weight[4];		// ����ġ
	DWORD	m_Index[4];			// 
	TCHAR	m_Bonename[4][256];	// �� �̸�
};

class AseNode
{
	friend class AseParser;

public:
	// �޽� ������.
	TCHAR	m_FileName[256];		// ���ϸ� 
	TCHAR   m_NodeName[256];		// ���(�޽�) �̸� 
	TCHAR   m_ParentNodeName[256];	// �θ� ���(�޽�) �̸� 
	UINT	m_VertexCnt;			// ���� ����
	UINT	m_FaceCnt;				// ���̽� ����
	UINT	m_IndexCnt;				// �ε����� �׷��� �� ��������. ���� Face * 3 ��

	UINT	m_VertexCnt_Ex;			// Ȯ�� ���ؽ� ���� ��������

	int m_MtlRef;					// ��� ������ �������...

	
	// ��� TM
	XMFLOAT4X4	m_mTM;					// ���� transform matrix
	XMFLOAT4X4	m_mTrans;				// �̵����
	XMFLOAT4X4	m_mScale;				// ũ�⺯ȯ ���
	XMFLOAT4X4	m_mRot;					// ȸ�����
	VECTOR3 m_vPos;					// ��ġ
	VECTOR3	m_vScale;				// ũ��
	VECTOR3 m_vRot;					// ȸ����

	// ���� ������ (�ӽ�) ����.
	VERTEX_ASE_NORMAL* m_pVerNormalList;	// ��� ����� ����Ʈ

	VERTEX_ASE* m_pVertList;				// ���� ����Ʈ : VB �� 
	FACE_ASE* m_pFaceList;					// FACE ����Ʈ: IB ��  
	COLOR* m_pCVertList;					// ���� ���� ����Ʈ
	FACE_ASE* m_pCFaceList;					// ���� ����-�ε��� ����Ʈ
	TEX_UV* m_pTexUvVertexList;				// �ؽ��� ��ǥ ���� ����Ʈ
	FACE_ASE* m_pTexUvFaceList;


	// ���� ���ؽ�
	VERTEX_ASE_EXTEND* m_pVerNrmList_Ex;	// ��� & ���ؽ� ����� ����Ʈ(Extend)
	FACE_ASE* m_pIndexList_EX;				// Ȯ��� �ε��� ���� �����

	// ������ (H/W) ����   
	ID3D11Buffer* m_pVB;
	ID3D11Buffer* m_pIB;

	////////////////////////////////////////////////////////////////////////////////////////
	// Animation ����
	AseNode* m_ParentNode;					// �θ� ������ �����
	std::vector<AseNode*> m_ChildNodelist;	// �ڽ� ��� ����� ����Ʈ
	BOOL	m_bParent;						// �θ� �ִ� ������� Ȯ�ο�

	// ���� ������
	std::vector<ANIKEY_POS> m_PosKey;		// pos ������ �����
	std::vector<ANIKEY_ROT> m_RotKey;		// Rot ������ �����

	// Ű ����
	int m_PosKeyCnt;							// �̵� ���� Ű ���� �����
	int m_RotKeyCnt;							// �̵� ���� Ű ���� �����

	// Ű ������ �ٸ� �� �־ �и�... �ٷ�� �����͵� �ٸ���
	KEY_POS* m_AniPosKeyList;						// �̵� ���� Ű ����Ʈ
	KEY_ROT* m_AniRotKeyList;						// ȸ�� ���� Ű ����Ʈ

	float m_AnimSpeed;
	float m_CurrTime;
	float m_RotCurrTime;

	DWORD m_CurrTickTime;
	DWORD m_CurrKey;

	DWORD m_RotCurrTickTime;
	DWORD m_RotCurrKey;

	/////
	XMMATRIX m_TTM;

	// �ִ� TM
	XMMATRIX m_mAniTM;
	XMMATRIX m_mAniTransM;
	XMMATRIX m_mAniRotM;
	XMMATRIX m_mAniScaleM;

	// ���� TM
	XMMATRIX m_mLocalTM;
	XMMATRIX m_mLocalTransM;
	XMMATRIX m_mLocalRotM;
	XMMATRIX m_mLocalScaleM;

	// ���� ��ȯ TM
	XMMATRIX m_mFinalTM;
	XMMATRIX m_mFinalTransM;
	XMMATRIX m_mFinalRotM;
	XMMATRIX m_mFinalScaleM;

	////////////////////////////////////////////////////////////////////////////////////////
	// Skinning ����
	std::vector<SKIN_DATA> m_SkinDataList;	// ��Ų ������ ����Ʈ

	// ����ó��
	bool m_bSkindata;	// ��Ų �����Ͱ� �ִ��� ������...
	bool m_bAniData;	// �ִϸ��̼� �����Ͱ� �ִ��� ������
	bool m_bTexData;	// �ؽ��İ� �ִ��� ������
	bool m_bSkin;
	bool m_AniEnd;		// ��ü �ִϸ��̼� ������ �� ���Ҵ���
public:
	int _CreateVFBuffers();			// ���� ���� �籸��

	HRESULT _CreateHWBuffers();		// ������ ���� ����

	int _ExtendVertexList();		// ���ؽ� ���� Ȯ��

	void PushChildNode(AseNode* pnode);

	XMMATRIX GetFinalTM();

public:
	int Generate();

public:
	//������ , �Ҹ���
	AseNode(/*LPDEVICE pDev*/);
	~AseNode();

	// ���� ���� ���� �żҵ�
	const XMFLOAT4X4& GetTM() const { return m_mTM; }
	const VECTOR3 GetPos() const { return m_vPos; }
	const VECTOR3 GetRot() const { return m_vRot; }
	const ID3D11Buffer* GetVB() const { return m_pVB; }
	const ID3D11Buffer* GetIB() const { return m_pIB; }
	const UINT GetVBStrideInByte() const { return sizeof(VERTEX_ASE_EXTEND); }
	const UINT GetFaceCnt() const { return m_FaceCnt; }
	const UINT GetVertexCnt() const { return m_VertexCnt; }
	const UINT GetIndexedCnt() const { return m_IndexCnt; }
	const TCHAR* GetFileName() const { return m_FileName; }
	const TCHAR* GetNodeName() const { return m_NodeName; }
	const TCHAR* GetParentNodeName() const { return m_ParentNodeName; }
	const int GetMtrlCount() const { return m_MtlRef; }
	const BOOL GetParentHave() const { return m_bParent; }
	//const XMMATRIX GetFinalTM() const { return m_mFinalTM; }

	void Release();

	XMFLOAT4X4 Xmfloat4x4Identity();
};

#ifndef EQUAL
#define EQUAL( a, b ) ( _tcsicmp((a), (b)) == 0)
#define NOT_EQUAL( a, b ) ( _tcsicmp((a), (b)) != 0)
#endif


