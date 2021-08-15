///
///
///
/// FBX_MeshData class
/// [2020/10/14 RUNSUMIN]
#pragma once
#include "FbxDataStructure.h"
#include "FbxData.h"
#include "D3DDevice.h"
#include "Shader.h"
#include "Camera.h"
#include "Light.h"
#include "EngineInterface.h"
#include "Geometry_Generater.h"
#include "DxDefine.h"
#include "MeshFilter.h"
#include "Material.h"

template <typename T>
void deletevector(vector<T*> temp)
{
	int size = temp.size();

	for (int i = 0; i < size; i++)
	{
		delete temp[i];
	}
}

// �� Ŭ����
class Fbx_MeshData
{
public:
	Fbx_MeshData();
	~Fbx_MeshData();
private:
	// �� ������ Ŭ����
	class FbxModelData
	{
	public:
		FbxData_Mesh* m_pFbxData;
		ID3D11Buffer* m_pVB;
		ID3D11Buffer* m_pIB;
		GRAPHICENGINE::RenderQueueSort m_QueueSrot;
	};

public:
	/////////////////////////////////	������...
	vector<FbxData_Mesh*> m_pFbxDataList;	// �̺κ��� ��ü �������� ��ȯ �ʿ�... // mesh 
	vector<Bone*> m_pBoneList_Hierarchy;	// �̺κ��� ��ü �������� ��ȯ �ʿ�... // bone_Hierarchy
	vector<Bone*> m_pAllBoneList;			// �̺κ��� ��ü �������� ��ȯ �ʿ�... // bone_All
	vector<AnimationData*> m_pAniDataList;	// �̺κ��� ��ü �������� ��ȯ �ʿ�... // animation

	// Texture Name
	vector<string> m_Texfilename;
	vector<string> m_Norfilename;
	vector<string> m_MaskMapfilename;
	vector<string> m_ORMfilename;
	vector<string> m_LinkNodeNameList;

	// Texture Path
	string m_TexPath;

	// �ؽ��� ���� ���� ����Ʈ - �ؽ��� ������ŭ ����...
	vector<Material*> m_pMaterialList;
	bool m_AutoTextureSet; // - ������ �ȿ� �ؽ��� ��ΰ� ���������� ���õǾ� ���� ���� true

	/// Loader ������ ���Ǵ� ������
	int m_BoneCount;
	int m_TexCount;
	int m_NorCount;
	int m_MaskCount;
	int m_ORMCount;

	/// �浹 ó����...
	float m_BiggstX;
	float m_BiggstY;
	float m_BiggstZ;

	float m_leastX;
	float m_leastY;
	float m_leastZ;

public:
	// �� �̸�
	string m_ModelName;
	// �� ��ü��...
	Matrix m_AxisChange;
	// ��Ų ���� ���� Ȯ��
	bool m_SKinOn;
	//
	MeshFilter::eMeshfiltersort m_MeshFilterSort;

public:
	void SetMaterialDataAuto();
	void ReleaseModelData();

};
