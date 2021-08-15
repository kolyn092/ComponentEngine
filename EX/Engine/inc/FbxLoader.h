///
///
///
/// FBX SDK�� �̿��� �δ�
/// [2021/02/08] �̱������� ����
/// [2021/04/01] �̱��Ͽ��� �ٽ� ������Ʈ�� ����
/// [2020/10/12 RUNSUMIN]
#pragma once
#include "FbxData.h"
#include "Fbx_MeshData.h"
#include "EngineInterface.h"
#include <map>


class Fbx_MeshData;

class FbxLoader
{
	friend class FbxData_Mesh;

public:
	FbxLoader();
	~FbxLoader();

	// �ѹ� �ε��� �����ʹ� �������.. key, value
	std::map<std::string, Fbx_MeshData*> m_ImportDatalist;


	///  �ϳ��� ���� �ҷ� �� ��.... �������� ����� �ҷ� �� ���� ������
	FbxManager* m_fbxMgr;			// Fbx �Ŵ���
	FbxScene* m_Scene;				// FBX ��
	FbxDocumentInfo* m_SceneInfo;	// �� ����
	FbxIOSettings* m_Ios;			// I/O ���� ��ä(���������� ���� �������ų� ������ ���� ����). �̱������� ����
	FbxImporter* m_FbxImporter;
	FbxAxisSystem m_AxisSystem;

	///
	Matrix m_AxisChange;

public:
	/// �δ� ����
	bool InitializeFbxLoader();
	void SceneSetting(FbxScene* Scene);
	void ReleaseFbxLoader();


	/// ������ �ε�(���)
	Fbx_MeshData* LoadModel(string Filename);
	Fbx_MeshData* SetModel(string Filename);
	void SetTextrueDate();

	/// �ִϸ��̼Ǹ� �ε�
	AnimationData* LoadAnimationDataStack(string Filename);
	void GetHierarchydata(FbxNode* rootnode, vector<Bone*>& bonelist, Bone* parentbone);

	/// ������ �ε�(���)
	void LoadNode(FbxNode* pNode, Fbx_MeshData* pmodel, FbxPose* pose);		// �� �������� �ε�
	void LoadSkeletone(FbxNode* pNode, Fbx_MeshData* pmodel, Bone* parentbone, FbxPose* pose);		// �� �������� �ε�
	void GetTexturePath(string filename, FbxScene* scene, Fbx_MeshData* pmodel);
	void CalAxisMaxToDirectX(FbxAxisSystem maxAxisSystem);

	/// �ִϸ��̼�
	AnimationData* LoadAnimationData(FbxScene* pscene, vector<Bone*> HirearchyData);
	void GetAnimationData_Recur(FbxNode* prootnode, AnimationData* panidata, vector<Bone*> HirearchyData);
	void GetAnimationMatrix(FbxNode* pNode, AnimationData* panidata, vector<Bone*> HirearchyData);

	/// ���ؽ� ����
	void GetVertex_List(FbxNode* pNode, FbxData_Mesh* pdata, Fbx_MeshData* pmodel);
	Vector2 GetUV(FbxMesh* pmesh, int i, int j);
	Vector3 GetNormal(FbxMesh* pmesh, int i, int j);
	Vector3 GetNormaldata(FbxMesh* pmesh, int indexcount, int vertexcount);
	Vector3 GetBiNormal(FbxMesh* pmesh, int indexcount, int vertexcount);
	Vector3 GetTangent(FbxMesh* pmesh, int indexcount, int vertexcount);
	void LoadBoneIndexWeight(FbxNode* pnode, vector<BoneIndexWeight>& dummybonelist, FbxData_Mesh* pdata, Fbx_MeshData* pmodel);
	void GetWorldMatrix(FbxNode* pnode, FbxData_Mesh* pdata, FbxPose* pose);

	/// ���� ����
	void GetMaterials(FbxNode* pnode, FbxData_Mesh* pdata, Fbx_MeshData* pmodel);
	void GetMaterialAttribute(FbxSurfaceMaterial* pmat, Fbx_Material* matdata);
	void GetMaterialTexture(FbxSurfaceMaterial* pmat, FbxData_Mesh* pdata, Fbx_MeshData* pmodel);

	/// �� ����
	void GetSkeletonData(FbxNode* pnode, Bone* pBonedata, FbxNodeAttribute::EType type, int BoneIndex);
	int FindBoneIndex(string name, vector<Bone*> HirearchyData);

	/// ����׿�
	void GetFileName(const TCHAR* FullPath, TCHAR* FileName);
	void GetPath(const TCHAR* FullPathName, TCHAR* Path);
	Matrix ConvertFbxMattoDirxMat(FbxMatrix fbxmat);
	TCHAR* ConvertStringToTCHAR(string& s);
	string ConvertTCharToString(const TCHAR* ptsz);
	FbxAMatrix GetGeometryTransformation(FbxNode* pnode);
	Vector2 ConvertVec2(FbxVector2 vec2);
	Vector3 ConvertVec3(FbxVector4 vec3);
	Vector4 ConvertVec4(FbxVector4 vec4);

	void SortWeightData(vector<BoneIndexWeight>& bonelist);

public:
	string GetNodeName(FbxNode* pNode);
	int GetPolygonCnt(FbxNode* pNode);
	void SetModelInfo();
};
