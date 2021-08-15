//
//
//
//
// [2020/07/28 RUNSUMIN]
#pragma once
#include "vector"
#include "list"
#include "DxDefine.h"
#include "AseModel.h"
#include "AseNode.h"
#include "string"
#include "locale.h"		
//
#include "D3DDevice.h"
#include "Collision2D.h"

using namespace std;
class AseNode;
class AseModel;

#define STATIC


class AseParser
{
public:
	AseParser();
	~AseParser();

public:
	int m_LineCount;							// �� �Ľ� ���� ī����
	TCHAR m_CurrLine[256];						// �о���� ������� �Ľ̿� �ӽù���

	FILE* m_fp;									// ASE ���� ������
	AseModel* m_pModelList;

public:
	int _ReadLine(TCHAR* buff);					// �Ѷ��ξ� ���� �Լ�
	// �ִϸ��̼� ����
	////////////////////////////////////////////////////////////////////////////

	int _LoadTM(AseNode* pnode);



	// �Ž� ����
	////////////////////////////////////////////////////////////////////////////
	// �ֻ��� ��ü �ε�
	int _LoadGeomObject();						//������Ʈ�� �Ľ�.

	// ���ؽ� , ���̽� ����
	int _LoadMesh(AseNode* pnode);
	int _LoadVertexList(AseNode* pnode);
	int _LoadFaceList(AseNode* pnode);
	int	_LoadCVertexList(AseNode* pnode);
	int	_LoadCFaceList(AseNode* pnode);

	// ���� ����
	int _LoadMaterialList();
	int _LoadMaterial();
	int _LoadMap_Reflect();
	int _LoadDiffuseMap(int count);

	// �븻 // �ؽ��� UV
	int _LoadNormal(AseNode* pnode);
	int _LoadTexUVVertex(AseNode* pnode);
	int _LoadTexUVVFace(AseNode* pnode);

	int _LoadTexture(TCHAR* fileName, ID3D11Device* pDev, ID3D11DeviceContext* pDeviceContext);

	// �ִϸ��̼�
	int _LoadAniData(AseNode* pnode);
	int _LoadPosData(AseNode* pnode);
	int _LoadRotData(AseNode* pnode);
	int _CreateAniKeySet(AseNode* pnode);
	int _CreateAniKey();

	int _LoadSceneData();

	// �浹
	int _LoadCollData(AseNode* pnode);

	// ��Ű��
	int _LoadSkinningData(AseNode* pnode);

	// ���ؽ� ���� �籸��
	int _MakeVertexSkinData();

	// ���ؽ� Ȯ��// Weld ���ܰ�
	int _ExtendVertexList();

	// ��� ���汸�� ������ֱ�...
	int SetHeirarchy();

public:
	// ������ , �Ҹ���

	int Load(ID3D11Device* pDev, TCHAR* filename, AseModel* pModel, ID3D11DeviceContext* pDeviceContext);

	HRESULT LoadTexture(TCHAR* filename, ID3D11ShaderResourceView** ppTexRV, ID3D11Device* pDev, ID3D11DeviceContext* pDeviceContext);

	STATIC

		static void GetFileName(const TCHAR* FullPath, TCHAR* FileName);		//���ϸ� ���
	static void GetPath(const TCHAR* FullPathName, TCHAR* Path);			//path ���

};

