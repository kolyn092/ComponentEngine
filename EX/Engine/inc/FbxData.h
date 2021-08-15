///
///
///
/// 1���� ����� ������...
/// [2021/01/21 RUNSUMIN]
#pragma once
#include "FbxDataStructure.h"

class FbxData_Mesh
{
public:
	FbxData_Mesh();
	~FbxData_Mesh();
public:
	vector<Vertex> m_pVertexList;
	vector<Index> m_pIndexList;
	/// Ver_1.1 -> ��庰�� �� ������ ����
	vector<Matrix> m_BoneOffSet;


	Fbx_Material* m_pMaterial;	// ��� �ϳ��� ���� ����

	string m_NodeName;

	Matrix m_Worldm;
	Matrix m_GlobalBindPos;

	bool m_isBinding;
	bool m_TextureOn;
	bool m_NormalMapOn;
	bool m_MaskMapOn;
	bool m_ORMMapOn;

	int m_TextureCount;				// �δ����� �ο��ϴ� �ؽ��� ��ȣ
	int m_NormalCount;				// �δ����� �ο��ϴ� ��� ��ȣ
	int m_MaskMapCount;				// �δ����� �ο��ϴ� ����ũ�� ��ȣ
	int m_ORMapCount;				// �δ����� �ο��ϴ� ORM�� ��ȣ
	int m_PolygonCount;			    // �� ����� ������ ����
	int m_VertexCount;
	int m_IndexCount;


public:
	void CreateBiNorNTangent();
	void CalBinormalNTangent(int index1, int index2, int index3);
	void ReleaseFbxData();
};

