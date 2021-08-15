//
//
//
// �������̽� - ���µ� ������
// ���Ŀ� �ٸ� API ���� Ȯ������ ����Ͽ� ����
// [2020/12/07 RUNSUMIN]
#pragma once
#include <windows.h>	// ������ �ڵ�..
#include <SimpleMath.h>	// ���� ���
#include <string>
#include <vector>

namespace GRAPHICENGINE
{
	using namespace DirectX::SimpleMath;
	using namespace std;
	///
	// �׷��Ƚ� ���� ����̽�  ����
	/// Device
	enum class RenderState
	{
		CULLBACK, CULLFRONT, WIREFRAME, SOLID
	};

	// ������ ����.
	enum class RenderQueueSort
	{
		SORT_BACKGROUND = 100,	// ���� ���� �׷���
		SORT_OPAQUE = 200,		// ������ 
		SORT_ALPHATEST = 300,	// ���� �׽�Ʈ						// ���� O
		SORT_OPAQUELAST = 400,	// ������ ������
		SORT_TRANSPARENT = 500,	// ����(������ �ڿ��� ������)			// ���� X
		SORT_OVERLAY = 600,		// ��ø ȿ��
		SORT_UI = 700			// ���� �������̽�
	};

	// ���� ����
	bool EngineSetUp(HWND hwnd);
	// �׸��� ����
	void BeginRender(Vector4 backbuffercolor);
	// �׸��� ����
	void EndRender();
	// ���� ����
	void Release();
	// ���� Ÿ�� �޾ƿ���
	float GetEngineTime();
	// FPS
	float GetFramePerSecond();
	// ���� ��� ����
	void ChangeRenderState(RenderState renderstate);
	// ī�޶� ��Ʈ���� Getter
	void GetCameraMatrixOnce(Matrix view, Matrix proj);
	// �� ���� Getter
	void GetDirectionLightData(Vector4 Direction, Vector4 Diffuse, Vector4 Ambient);
	// ����Ʈ ����
	void SetViewport(float w, float h);
	// ��ü Draw
	void DrawAll(float time);
	// View Frustum Culling On/Off
	void SetViewFrustumCulling(bool b);
	// Shadow On, Off
	void SetShadow(bool b, Vector3 centerposition, float radious);

	/// FbxLoader(�׷��Ƚ� ���� ���� ����)
	bool FbxLoaderSetUp();										/// �� ����� �ϴ� �κ�
	void ReleaseFbxLoader();									/// �� ����� �ϴ� �κ�

	// ȭ�鿡 ���� ���...
	//void DrawText(int x , int y, const)

	/// Camera
	// 201211 ��� ���ҵ�
	class ICameraInterface abstract
	{
	public:
		enum class Mode
		{
			DEFAULT, AUTOROTATION, MOVE, FOLLOW, ORTHO, INPUT
		};
	public:
		// ī�޶� �ʱ�ȭ
		virtual void InitializeCamera() abstract;
		// ī�޶� ������Ʈ
		virtual void UpdateCamera(float dTime) abstract;
		// ī�޶� ��� ����
		virtual void ChangeCameraMode(Mode emode) abstract;
		// ī�޶� ������ ����
		virtual void SetCamerSRTData(Vector3 pos, Vector3 rot, Vector3 scl) abstract;
		// ī�޶� ���ǵ� ����
		virtual void SetCameraSpeed(float speed) abstract;
		// info
		virtual void CameraInfo() abstract;
		// delete
		virtual void ReleaseCamera() abstract;
		// Get,Set
		virtual Matrix GetCameraViewMat() abstract;
		virtual Matrix GetCameraProjMat() abstract;
		virtual Vector3 GetCameraPos() abstract;
		virtual Vector3 GetCameraRot() abstract;
		virtual Vector3 GetCameraScl() abstract;
	};

	/// Grid
	class IGridInterface abstract
	{
	public:
		virtual void InitializeGrid(int numx, int numy, float size) abstract;
		virtual void UpdateGrid() abstract;
		virtual void DrawGrid()	abstract;
		virtual void ReleaseGrid() abstract;
		virtual void ChangeGridSize(int numx, int numy, float size) abstract;
	};


	/// Light - Direction
	class IDirectionLightInterface abstract
	{
	public:
		struct IDirectrionLitData
		{
			Vector4 Direction;
			Vector4 Diffuse;
			Vector4 Ambient;
		};
	public:
		virtual void InitializeDirectrionLight(Vector4 dir, Vector4 dif, Vector4 amb) abstract;
		virtual void SetDirectrionLightDirection(Vector4 dir) abstract;
		virtual void SetDirectrionLightDiffuse(Vector4 dif) abstract;
		virtual void SetDirectrionLightAmbient(Vector4 amb) abstract;
	};

	/// Light - Point
	class IPointLightInterface abstract
	{
	public:
		struct IPointLitData
		{
			Vector4 Diffuse;
			Vector4 Ambient;
			Vector3 Position;
			float Range;
		};
	public:
		virtual void InitializePointLight(Vector4 dif, Vector4 amb, Vector3 pos, float range) abstract;
		virtual void SetPointLightDIffuse(Vector4 dif) abstract;
		virtual void SetPointLightAmbient(Vector4 amb) abstract;
		virtual void SetPointLightPosition(Vector3 pos) abstract;
		virtual void SetPointLightRange(float range) abstract;
	};

	/// Material
	class IMaterialInterface abstract
	{
	public:
		enum class TextureSort
		{
			ALBEDO, NORMAL, ORM, MASKMAP, EMISSIVE
		};
	public:
		virtual void SetTexturePath(string filename, TextureSort sort) abstract;
		virtual string GetTexturePath(TextureSort sort) abstract;
		virtual void SetLinkNodename(string nodename) abstract;
		virtual string GetLinkNodename() abstract;
	};

 	/// UI Material
	//class IMaterialInterface abstract
	//{
	//public:
	//	enum class TextureSort
	//	{
	//		ALBEDO, NORMAL, ORM, MASKMAP, EMISSIVE
	//	};
	//public:
	//	virtual void InitMaterial() abstract;
	//	virtual void SetTexture(string filename, TextureSort sort) abstract;
	//};


	/// Model
	class IModelInterface abstract
	{
	public:
		enum class ModelSort
		{
			SKINNED_MESH, STATIC_MESH
		};

		enum class RenderPath
		{
			Default, Depth
		};

	public:
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
		virtual RenderQueueSort GetModelNodeRendersort(int nodecount) abstract;
		virtual void SetModelNodeRenderQueuesort(int nodecount, RenderQueueSort sort) abstract;		// �� ���� ���� ���� ����
		virtual void SetDrawScreen(bool draw) abstract;
		virtual bool GetDrawScreen() abstract;
		virtual void SetModelRenderState(RenderState state) abstract;
		virtual Vector3 GetWorldModelPosition() abstract;
		virtual float GetCollSphereRadious() abstract;
		virtual ModelSort GetModelSort() abstract;

		// �ִϸ��̼� ����... �и� �ʿ�
		virtual void SetAnimationSpeed(float speed) abstract;		// ���ǵ� ����
		virtual void ChangeAnimation(int count) abstract;			// �ִϸ��̼� ��ȯ
		virtual float GetAniTotalTime() abstract;					// �ִϸ��̼� �� �ð�
		virtual bool GetAniEndTimeing() abstract;					// �ִϸ��̼� ������ Ÿ�� �޾ƿ�
		virtual int GetAniTotalKeyCount() abstract;					// �ִϸ��̼� �� ������
		virtual int GetAniNowKeyCount()	abstract;					// �ִϸ��̼� ��ä 
		virtual void SetNowKeyCount(int key) abstract;				// ���� Ű ����
		virtual void SetAniOn() abstract;							// �ִϸ��̼� ON;
		virtual void SetAniOff() abstract;							// �ִϸ��̼� OFF
		virtual vector<string> GetBoneOffSetName() abstract;		// BoneOffSet

		// �ִϸ��̼��� �⺻������ �ѹ��� ����. loop�� true �����ָ� loop��
		virtual void SetAnimationLoop(bool loop) abstract;
		// Bone Matrix ���� �޾ƿ���(�̸�)
		virtual Matrix GetHiearchyMatrixByName(string name) abstract;

		// Material
		virtual void SetMaterialData(IMaterialInterface* pobj, string nodename, IMaterialInterface::TextureSort sort) abstract;
		virtual void SetEmissiveMapOnOff(bool b) abstract;
		virtual void AddEmissiveMap(string filename) abstract;
		virtual void ChangeApplyEmissiveMap(int index) abstract;

		//Light Info
		virtual void SetDirectionLightData(IDirectionLightInterface::IDirectrionLitData data) abstract;
		virtual void SetPointLightData(IPointLightInterface::IPointLitData data) abstract;
	};

	/// UI
	class IUiInterface abstract
	{
	public:
		virtual	void UpdateUI(Vector3 pos, Vector3 vScl) abstract;
		virtual	void DrawUI() abstract;
		virtual	DWORD GetTextureWidth() abstract;
		virtual	DWORD GetTextureHeight() abstract;
		virtual void SetOverlayColorOnUI(Vector4 color) abstract;
		virtual void SetUISize(float x, float y) abstract;
		virtual	void ReleaseUI() abstract;
		virtual	void OnUi() abstract;
		virtual	void OffUi() abstract;
	};

	/// Geometry
	enum class Geomerty_Sort
	{
		BOX, SPHERE, CYLINDER, LINE
	};
	class IGeoMetry_InterFace abstract
	{
	public:
		virtual void Initialize() abstract;
		virtual void Update(Matrix World) abstract;
		virtual void Draw() abstract;
		virtual void Release() abstract;
		virtual void ChangeColor(Vector4 color) abstract;
	};



	/// Gizmno
	class IGizmo_InterFace abstract
	{
	public:
		virtual int InitAxis() abstract;
		virtual int Update(Matrix world) abstract;
		virtual int Render() abstract;
		virtual void Release() abstract;
	};

	/// Terrain
	class ITerrain_Interface abstract
	{
	public:
		enum class RenderPath
		{
			Default, Depth, Shadow
		};
	public:
		virtual void InitTerrain() abstract;
		virtual void Update() abstract;
		virtual void Render(RenderPath path, Matrix shadow, bool b) abstract;
		virtual void Release() abstract;
	};


	/// SkyBox
	class ISkyBoxInterface abstract
	{
	public:
		virtual void InitSkybox() abstract;
		virtual void ChangeSkyboxColor(Vector4 Color) abstract;
		virtual void DrawSkybox() abstract;
		virtual void ReleaseSkybox() abstract;
	};

	/// Create
	// Camera
	void CreateCamera(ICameraInterface** pobj, Vector3 pos, Vector3 rot);

	// Grid
	void CreateGird_Debug(IGridInterface** pobj);

	/// Mesh Low data Load
	// FBX ���Ͽ��� ������ �ε� �� ����Ʈ�� ����
	void CreateModelObject(string filename);		/// �� ������ fbxloader���� �ε�

	// �ִϸ��̼� ����Ʈ�� �߰��ϴ� �Լ�. ������ ����ڰ� �˾ƾ� �ϴ� �������� �ִ�.
	void CreateModelObject_List(vector<string> filenamelist);	/// �� �ִϸ��̼� ����

	//////////////////////////////////////////////////////////////////////////

	///Material - Texture
	void CreateModelMaterial_Texture();

	/// Inputer - interface to GameObject
	// ������ ����Ʈ���� �̸����� ���� �ε�.
	void SetModelObject(IModelInterface** pobj, string filename);

	// �ִϸ��̼� ����Ʈ�� �߰��ϴ� �Լ�. ������ ����ڰ� �˾ƾ� �ϴ� �������� �ִ�.
	/// ����
	//void SetModelObject_List(IModelInterface** pobj, vector<string> filenamelist);

	// UI
	void SetUiObject(IUiInterface** pobj, Vector3 pos, Vector3 vScl, string filename);

	// Geometry
	void CreateGeometry(IGeoMetry_InterFace** pobj, Geomerty_Sort sort, float width, float height, float depth, Vector4 color);

	// Gizmo
	void CreateGizmo(IGizmo_InterFace** pobj);

	// Terrain
	void CreateTerrain_Obj(ITerrain_Interface** obj, string filename, float width, float height, float slice);

	// Skybox
	void CreateSkybox_Obj(ISkyBoxInterface** obj, string filename);

	// Material
	void CreateMaterial_Mesh(IMaterialInterface** obj);


	/// Light
	void CreateDirectionLight(IDirectionLightInterface** pobj);

	void CreatePointLight(IPointLightInterface** pobj);

	///RenderQueue
	//
	void ClearRenderQueue_Model();
	void ClearRenderQueue_UI();
	void DeleteQueueListcertainindex(int index);

	/// FOG
	void SetFogOnOff(bool b);	// OnOff
	void SetFogColor(Vector4 col);
	void SetFogDensity(float f);	// Max - 1 

	///BLoom
	void BloomOnOff(bool b);
}


