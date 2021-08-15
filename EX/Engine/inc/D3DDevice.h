//
//
//
// Dx11 �ʱ�ȭ
// [2020/07/23 RUNSUMIN]
#pragma once

#include "DxDefine.h"
#include "Camera.h"
#include "EngineInterface.h"

/// ��������Ʈ���� ������ε� ���� ���� ����...
/// ������� (16����Ʈ ����)
_declspec(align(16)) struct CBDEFAULT
{
	XMMATRIX mTm;
	XMMATRIX mView;
	XMMATRIX mProj;
	XMMATRIX mWV;
	XMMATRIX mWVP;

	XMMATRIX m_BoneTm[100];
	XMMATRIX mUserTm;
	BOOL	 bSkin;
};

/// ��������
_declspec(align(16)) struct CBMATERIAL
{
	COLOR mDiffuse;
	COLOR mAmbient;
	COLOR mSpecular;
	FLOAT mSpecPower;
	BOOL  bTexOn;

};

/////////////////////////////////////////////////////////////////

/// �������_FBX ����
_declspec(align(16)) struct CBFBXDEF
{
	Matrix mTm;
	Matrix mWorld;
	Matrix mView;
	Matrix mProj;
	Matrix mWV;
	Matrix mWVP;
	Matrix m_BoneTm[100];
	Matrix m_AxisChange;
	Matrix m_LightViewProj;
	Vector3 CamWorldPos;
};

_declspec(align(16)) struct CBFUPDATEONCE
{
	Matrix mView;
	Matrix mProj;
	Matrix m_AxisChange;
	///etc....
};

/// ��������_FBX ����...
_declspec(align(16)) struct CBFBXMAT
{
	Vector4 Diffuse;
	Vector4 Ambient;
	Vector4 Specular;
	BOOL TexOn;
	BOOL NormalOn;
	BOOL SkinOn;
	BOOL MaskOn;
	BOOL BumpMappingOn;
	BOOL PBROn;
	BOOL EmissiveOn;
};

/// ��������_FBX ����
_declspec(align(16)) struct CBLIGHT
{
	Vector4 direction;
	Vector4	diffuse;
	Vector4 ambient;
};

/// ����������_
_declspec(align(16)) struct CBPOINTLIGHT
{
	Vector4 diffuse;
	Vector4	ambient;
	Vector3 position;
	float range;
};

/// �Ȱ� ����
_declspec(align(16)) struct CBFOG
{
	Vector4 Color;
	float Density;
	BOOL OnOff;
};

class D3DDevice
{
public:
	D3DDevice();
	~D3DDevice();
	// ����̽��� ���� ���ο��� �̱������� �����Ѵ�.
	static D3DDevice* m_Instance;
	static D3DDevice* GetInstance();

public:
	// ��ġ �ʱ�ȭ ����
	IDXGISwapChain* m_SwapChain;
	ID3D11Device* m_Device;
	ID3D11DeviceContext* m_DeviceContect;
	ID3D11RenderTargetView* m_RendertargetView;
	DXGI_MODE_DESC	m_Mode;
	D3D_FEATURE_LEVEL m_FeatureLevels;
	ID3D11Texture2D* m_pDS;					//����-���ٽ� ����.
	ID3D11DepthStencilView* m_pDSView;		//����-���ٽ� ��.

	
	// ���� ���ٽ� ���� ���� ��ü
	ID3D11DepthStencilState* m_DSState[eDepthStencilSet::DS_MAX_];
	// ������ ���� ��ü
	ID3D11RasterizerState* m_RState[eObjectRasterizerState::RS_MAX_];
	// ���� ȥ��(����) ���� ��ü
	ID3D11BlendState* m_BState[eObjectBlendingState::BS_MAX_];
	// �ؽ��� ���÷� ���� ��ü
	ID3D11SamplerState* m_pSampler[eTextureSamplerState::SS_MAX];

public:
	// ȭ�� �ػ�
	float m_ScreenWidth;
	float m_ScreenHeight;

	// AA, AF �ɼ�
	DWORD m_AA;
	DWORD m_Af;

	// ���� ����ȭ
	bool m_Vsync;

	// ī�޶� ��Ʈ����(�ӽ�).. ���� ���� �Ͽ�...
	Matrix m_View;
	Matrix m_Proj;

	// ����Ʈ(�ӽ�)
	CBLIGHT m_DirectionLight;

public:
	/// ����
	bool SetDXGI_Mode(HWND hwnd);
	HRESULT CreateDeviceSwapChain(HWND hwnd);
	HRESULT CreateRenderTarget();
	HRESULT CreateDepthStencil();
	HRESULT LoadTexture(string filename, ID3D11ShaderResourceView** ppTexRV);
	HRESULT LoadCubeTexture(string filename, ID3D11ShaderResourceView** ppTexRV);
	HRESULT CreateVB(void* pBuff, UINT size, ID3D11Buffer** ppVB);
	HRESULT CreateIB(void* pBuff, UINT size, ID3D11Buffer** ppIB);
	HRESULT CreateVB_Dynamic(void* pBuff, UINT size, ID3D11Buffer** ppVB);
	HRESULT CreateIB_Dynamic(void* pBuff, UINT size, ID3D11Buffer** ppIB);
	HRESULT UpdateDynamicBuffer(ID3D11Resource* pBuff, LPVOID pData, UINT size);
	HRESULT GetTextureDesc(ID3D11ShaderResourceView* pRV, D3D11_TEXTURE2D_DESC* pDesc);

	/// ���� �ۿ��� ������ �κ�
	bool EngineSetUp(HWND hwnd); // Dx device �ʱ�ȭ
	void BeginRend(Vector4 backbuffercolor);// Draw ����
	void EndRend();	// Draw ��
	float GetEngineTime();
	float GetFramePerSecond();
	void Release();
	void ChangeRenderState(GRAPHICENGINE::RenderState renderstate);
	void GetCameraMatrixOnce(Matrix view, Matrix proj);
	void GetDirectionLightData(Vector4 Direction, Vector4 Diffuse, Vector4 Ambient);
	
	CBLIGHT GiveDirectionLightData();

	///
	/// ���� ���ο��� ������ �κ�
	void ClearBackBufer(UINT flag, float depth, UINT stencil, Vector4 col);
	void Flip();
	void SetViewport();
	void SetViewport(float Screenwidth, float screenheight);

	void CreateDepthStencilState();
	void CreateRasterState();
	void CreateBlenderState();
	void CreateSamplerState();

	/// Shader

	HRESULT ShaderCompile(const TCHAR* filename, const char* entrypoint, const char* shadermodel,
		ID3DBlob** ppcode);

	// ���ؽ� ���̴� �ε�
	HRESULT VertexShaderLoad(const TCHAR* filename, const char* entrypoint, const char* shadermodel,
		ID3D11VertexShader** pvs, ID3DBlob** pvscode);

	// �ȼ� ���̴� �ε�
	HRESULT PixelShaderLoad(const TCHAR* filename, const char* entrypoint, const char* shadermodel,
		ID3D11PixelShader** pps);

	/// ���ڿ�
	TCHAR* ConvertStringToTCHAR(string& s);
	string ConvertTCharToString(const TCHAR* ptsz);

/// Get, Set
public:
	ID3D11Device* GetDevice() { return m_Device; }
	ID3D11DeviceContext* GetDeviceContext() { return m_DeviceContect; }
	// ����
	void SetDepthStencilState(ID3D11DepthStencilState* state, int refcnt);
	void SetRenderingState(ID3D11RasterizerState* state);
	void SetBlendingState(ID3D11BlendState* state);
	void SetSamplerState(ID3D11SamplerState* state);


};

