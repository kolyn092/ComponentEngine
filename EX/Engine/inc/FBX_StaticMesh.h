///
///
///
/// FBX �� Ŭ����
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
//template <typename T>
//void deletevector(vector<T*> temp)
//{
//	int size = temp.size();
//
//	for (int i = 0; i < size; i++)
//	{
//		delete temp[i];
//	}
//}

// �� Ŭ����
class FBX_StaticMesh : public MeshFilter
{
public:
	FBX_StaticMesh();
	~FBX_StaticMesh();
private:
	// �� ������ Ŭ����
	class FbxModelData
	{
	public:
		FbxData_Mesh* m_pFbxData;
		ID3D11Buffer* m_pVB;
		ID3D11Buffer* m_pIB;
	};

public:
	/////////////////////////////////	������...
	vector<FbxData_Mesh*> m_pFbxDataList;	// �̺κ��� ��ü �������� ��ȯ �ʿ�... // mesh 
	vector<Bone*> m_pBoneList_Hierarchy;	// �̺κ��� ��ü �������� ��ȯ �ʿ�... // bone
	vector<Bone*> m_pAllBoneList;			// �̺κ��� ��ü �������� ��ȯ �ʿ�... // bone
	vector<AnimationData*> m_pAniDataList;	// �̺κ��� ��ü �������� ��ȯ �ʿ�... // animation

	//vector<Fbx_Texture*> m_pFbxTexure;
	vector<string> m_Texfilename;
	vector<string> m_Norfilename;
	vector<string> m_MaskMapfilename;
	vector<ID3D11ShaderResourceView*> m_FbxModelTexture;
	vector<ID3D11ShaderResourceView*> m_FbxModelNormal;
	vector<ID3D11ShaderResourceView*> m_FbxModelMaskMap;
	string m_TexPath;
	int m_TexCount;
	int m_NorCount;
	int m_MaskCount;
	int m_BoneCount;

	virtual void InitFbxModel() override;
	virtual void FbxModelUpdate(float time) override;
	virtual void FbxModelDraw(float time) override;
	virtual void FbxModelInfo() override;
	virtual void ReleaseFbxModel() override;
	virtual void SetUserMatrix(Matrix usertm) override;
	virtual string GetModelName() override;
	
	/// Animation
	virtual void SetAnimationSpeed(float speed) override;
	virtual void ChangeAnimation(int count) override;
	virtual void SetAnimationLoop(bool loop) override;
	virtual float GetAniTotalTime() override;
	virtual bool GetAniEndTimeing() override;
	virtual int GetAniTotalKeyCount() override;				
	virtual int GetAniNowKeyCount()	override;				
	virtual void SetNowKeyCount(int key) override;
	virtual void SetAniOn() override;
	virtual void SetAniOff() override;

	// �� ���� Ȯ�ο� �ڽ�
	//vector<Geometry_Generater*> m_pBonedebugList;

private:
	// �� Init
	void CreateHWBuffer();
	void InitShader();
	void SetTextureDateInit();
	// �� Update
	void ModelAniUpdate(float time, int anicount, int keycount);
	void ModelAnimationUpdate_Recur_Temp(int anicount, Bone* pbone, float currtime, Matrix parenttm, vector<Matrix>& bonematdata, int nowframecount);
	int CalAniFrame(float Time);
	// �� Draw
	void SetPrimitiveData(int nodecount);
	void SetTextrueData(int nodecount);
	void SetMaterialData(int nodecount);
	void SetConstantBuffer(int nodecount);
	void Draw(int nodecount);

public:
	// �� �̸�
	string m_ModelName;
	// ���� ������Ʈ ���ۿ�
	Matrix m_UserTm;

	// �� ��ü��...
	Matrix m_AxisChange;

	// �ִϸ��̼� ���� �ӵ�
	float m_AnimationSpeed;

	// ����ó��
	bool m_bNorOn;
	bool m_TexOn;
	bool m_AniOn;
	bool m_SKinOn;
	bool bLightWind;

private:
	vector<FbxModelData*> m_pFinalDatalist;	// ��ü ���� �簡��...

	ID3D11Device* m_pDevCopy;				// ����̽� ī��
	ID3D11DeviceContext* m_pDevConCopy;		// ����̽� ���ؽ�Ʈ ī��
	Shader* m_pShader;

	CBFBXDEF    m_CbDef;					// �⺻ ��� ��� ����
	CBFBXMAT	m_CbMat;					// FBX ���� ���� ����
	CBLIGHT		m_CbLight;					// FBX ���� ���� ����

	ID3D11Buffer* m_pCbDefBuf;
	ID3D11Buffer* m_pCbMatBuf;
	ID3D11Buffer* m_pCbLightBuf;

	Matrix m_CamViewMat;
	Matrix m_CamProjMat;
	Matrix m_LightVP;

private:
	Matrix m_Trans;
	Matrix m_Rot;
	Matrix m_Scale;

	Vector3 m_vPos;
	Vector3 m_vRot;
	Vector3 m_vScl;

	// �ִϸ��̼�
	float m_AniTime;			// ������
	float m_CurrTime;			// ���簪;
	bool m_AniOnOff;
	int m_NowAniCount;
	bool m_Aniloop;
	int m_NowFrameCount;

	bool m_AniDown;

};
