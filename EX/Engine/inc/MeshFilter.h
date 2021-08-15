///
///
///
/// Mesh Renderer ���� �޽� ����
/// SKinnedMesh, Static Mesh ����.
/// [2021/04/07 RUNSUMIN]
#pragma once
#include "EngineInterface.h"
using namespace std;
using namespace DirectX::SimpleMath;

class MeshFilter : public GRAPHICENGINE::IModelInterface
{
public:
	enum class eMeshfiltersort
	{
		SkinnedMesh, StaticMesh
	};
public:
	MeshFilter();
	~MeshFilter();
public:
	// ������ �����Ϳ��� �޽������� �Ǿ�������... �۾��� �ʹ� Ŀ���� ���� �������� ����
	eMeshfiltersort m_MeshFilterSort;
	// ȭ�鿡 �׸��� ����...
	bool m_Draw;

protected:
	virtual void InitFbxModel() abstract;
	virtual void InitModelTexture() abstract;
	virtual void FbxModelUpdate(float time) abstract;
	virtual void FbxModelDraw(float time, int nodecount, RenderPath path, Matrix shadow) abstract;
	virtual void FbxModelInfo() abstract;
	virtual void ReleaseFbxModel() abstract;
	virtual void SetUserMatrix(Matrix usertm) abstract;
	virtual Matrix GetUserMatrix() abstract;
	virtual string GetModelName() abstract;
	virtual string GetNodeName(int nodecount) abstract;
	virtual int GetModelNodeCount() abstract;
	virtual GRAPHICENGINE::RenderQueueSort GetModelNodeRendersort(int nodecount) abstract;
	virtual void SetModelNodeRenderQueuesort(int nodecount, GRAPHICENGINE::RenderQueueSort sort) abstract;		// �� ���� ���� ���� ����
	virtual void SetDrawScreen(bool draw) abstract;
	virtual bool GetDrawScreen() abstract;
	virtual void SetModelRenderState(GRAPHICENGINE::RenderState state) abstract;
	virtual Vector3 GetWorldModelPosition() abstract;
	virtual float GetCollSphereRadious() abstract;
	virtual GRAPHICENGINE::IModelInterface::ModelSort GetModelSort() abstract;


	// �ִϸ��̼� ����... �и� �ʿ�
	virtual void SetAnimationSpeed(float speed) abstract;			// ���ǵ� ����
	virtual void ChangeAnimation(int count) abstract;				// �ִϸ��̼� ��ȯ
	virtual float GetAniTotalTime() abstract;						// �ִϸ��̼� �� �ð�
	virtual bool GetAniEndTimeing() abstract;						// �ִϸ��̼� ������ Ÿ�� �޾ƿ�
	virtual int GetAniTotalKeyCount() abstract;						// �ִϸ��̼� �� ������
	virtual int GetAniNowKeyCount()	abstract;						// �ִϸ��̼� ��ä 
	virtual void SetNowKeyCount(int key) abstract;					// ���� Ű ����
	virtual void SetAniOn() abstract;								// �ִϸ��̼� ON;
	virtual void SetAniOff() abstract;								// �ִϸ��̼� OFF
	virtual void SetAnimationLoop(bool loop) abstract;				// Loop ����
	virtual Matrix GetHiearchyMatrixByName(string name) abstract;	// �� ���� Get
	virtual vector<string> GetBoneOffSetName() abstract;		// BoneOffSet

	// Material
	virtual void SetMaterialData(GRAPHICENGINE::IMaterialInterface* pobj, string nodename, GRAPHICENGINE::IMaterialInterface::TextureSort sort) abstract;
	virtual void SetEmissiveMapOnOff(bool b) abstract;
	virtual void AddEmissiveMap(string filename) abstract;
	virtual void ChangeApplyEmissiveMap(int index) abstract;

	//Light Info
	virtual void SetDirectionLightData(GRAPHICENGINE::IDirectionLightInterface::IDirectrionLitData data) abstract;
	virtual void SetPointLightData(GRAPHICENGINE::IPointLightInterface::IPointLitData data) abstract;



/// Mesh Information
public:

};

