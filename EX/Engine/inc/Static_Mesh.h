///
///
///
/// Static Mesh
/// [2021/04/13 RUNSUMIN]
#pragma once
#include "Fbx_MeshData.h"
#include "EngineInterface.h"
#include "MeshFilter.h"
#include "ShaderMgr.h"
#include <Effects.h>

class Static_Mesh : public MeshFilter
{
public:
	Static_Mesh();
	~Static_Mesh();
private:
	// �� ���� ������...
	Fbx_MeshData* m_pModelData;
private:
	// �� ������ Ŭ����
	class FbxModelData
	{
	public:
		FbxData_Mesh* m_pFbxData;
		ID3D11Buffer* m_pVB;
		ID3D11Buffer* m_pIB;
		ID3D11Buffer* m_InsB;
		GRAPHICENGINE::RenderQueueSort m_QueueSrot;
	};
	// Instance Draw
	struct Instancetype
	{
		Vector3 Pos;
		Vector3 Rot;
		Vector3 Scl;
	};
	vector<Instancetype> m_InstanceList;
public:
	// ���� ������Ʈ ���ۿ�
	Matrix m_UserTm;

private:
	vector<FbxModelData*> m_pFinalDatalist;	// ��ü ���� �簡��...

	ID3D11Device* m_pDevCopy;				// ����̽� ī��
	ID3D11DeviceContext* m_pDevConCopy;		// ����̽� ���ؽ�Ʈ ī��

	/// Shader
	Shader* m_pShader;
	ID3D11PixelShader* m_pPsDepth;	/// ���� �ȼ� ���̴�

	CBFBXDEF    m_CbDef;					// �⺻ ��� ��� ����
	CBFBXMAT	m_CbMat;					// FBX ���� ���� ����
	CBLIGHT		m_CbLight;					// FBX ���� ���� ����
	CBFOG		m_CBFog;					// �Ȱ� ����

	ID3D11Buffer* m_pCbDefBuf;
	ID3D11Buffer* m_pCbMatBuf;
	ID3D11Buffer* m_pCbLightBuf;
	ID3D11Buffer* m_pCbFogBuf;

	Matrix m_CamViewMat;
	Matrix m_CamProjMat;
	Matrix m_LightVP;

	vector<ID3D11ShaderResourceView*> m_AlbedoMapList;
	vector<ID3D11ShaderResourceView*> m_NormalMapList;
	vector<ID3D11ShaderResourceView*> m_MaskMapList;
	vector<ID3D11ShaderResourceView*> m_ORMMapList;
	vector<ID3D11ShaderResourceView*> m_EmissiveMapList;

	// RenderState
	GRAPHICENGINE::RenderState m_ModelRenderState;

	// Collision
	float m_Radious;
private:
	Matrix m_Trans;
	Matrix m_Rot;
	Matrix m_Scale;

	Vector3 m_vPos;
	Vector3 m_vRot;
	Vector3 m_vScl;
	int m_NowNodeCount;

	bool m_EmssiveprevState;

	int m_EmissiveMapCount;

	///PBR
private:
	std::unique_ptr<PBREffect> effect;

	GRAPHICENGINE::IGeoMetry_InterFace* m_CollBox;

private:
	// �� Init
	void CreateHWBuffer();
	// material ���� Textrue ������ �޾ƿ���
	void GetShaderResource();

	// �� Update

	// �� Draw
	void SetPrimitiveData(int nodecount);
	void SetTextrueData(int nodecount);
	void SetMaterialData(int nodecount);
	void SetConstantBuffer(int nodecount);
	void SetConstantBuffer_Depth(int nodecount, Matrix shadow);
	void Draw(int nodecount);

public:
	// �ν��Ͻ� ������ �ֱ�.
	void AddInstanceData(Vector3 pos, Vector3 rot, Vector3 scl);
	bool SetModelData(Fbx_MeshData* pdata);

	virtual void InitFbxModel() override;
	virtual void InitModelTexture() override;
	virtual void FbxModelUpdate(float time) override;
	virtual void FbxModelDraw(float time, int nodecount, RenderPath path, Matrix shadow) override;
	virtual void FbxModelInfo() override;
	virtual void ReleaseFbxModel() override;
	virtual void SetUserMatrix(Matrix usertm) override;
	virtual Matrix GetUserMatrix() override;
	virtual string GetModelName() override;
	virtual string GetNodeName(int nodecount) override;
	virtual int GetModelNodeCount() override;
	virtual GRAPHICENGINE::RenderQueueSort GetModelNodeRendersort(int nodecount) override;
	virtual void SetModelNodeRenderQueuesort(int nodecount, GRAPHICENGINE::RenderQueueSort sort) override;
	virtual void SetDrawScreen(bool draw) override;
	virtual bool GetDrawScreen() override;
	virtual void SetModelRenderState(GRAPHICENGINE::RenderState state) override;
	virtual Vector3 GetWorldModelPosition() override;
	virtual GRAPHICENGINE::IModelInterface::ModelSort GetModelSort() override;

	/// �ִϸ��̼� ����... ���X 
	virtual void SetAnimationSpeed(float speed) override;		// ���ǵ� ����
	virtual void ChangeAnimation(int count) override;			// �ִϸ��̼� ��ȯ
	virtual float GetAniTotalTime() override;					// �ִϸ��̼� �� �ð�
	virtual bool GetAniEndTimeing() override;					// �ִϸ��̼� ������ Ÿ�� �޾ƿ�
	virtual int GetAniTotalKeyCount() override;					// �ִϸ��̼� �� ������
	virtual int GetAniNowKeyCount()	override;					// �ִϸ��̼� ��ä 
	virtual void SetNowKeyCount(int key) override;				// ���� Ű ����
	virtual void SetAniOn() override;							// �ִϸ��̼� ON;
	virtual void SetAniOff() override;							// �ִϸ��̼� OFF
	virtual void SetAnimationLoop(bool loop) override;
	virtual Matrix GetHiearchyMatrixByName(string name) override;
	virtual vector<string> GetBoneOffSetName() override;		// BoneOffSet
	virtual float GetCollSphereRadious() override;

	// Material
	virtual void SetMaterialData(GRAPHICENGINE::IMaterialInterface* pobj, string nodename, GRAPHICENGINE::IMaterialInterface::TextureSort sort) override;
	virtual void SetEmissiveMapOnOff(bool b) override;
	virtual void AddEmissiveMap(string filename) override;
	virtual void ChangeApplyEmissiveMap(int index) override;

	//Light Info
	virtual void SetDirectionLightData(GRAPHICENGINE::IDirectionLightInterface::IDirectrionLitData data) override;
	virtual void SetPointLightData(GRAPHICENGINE::IPointLightInterface::IPointLitData data) override;


};

