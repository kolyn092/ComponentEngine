///
///
///
/// �⺻ �ͷ��� ���� Ŭ����
/// [2020/11/11 RUNSUMIN]
#pragma once

#include "DxDefine.h"
#include "Shader.h"
#include "EngineInterface.h"

class Terrain : public GRAPHICENGINE::ITerrain_Interface
{
public:
	Terrain(string filename, float width, float height, float slice);
	~Terrain();

	struct _VTXTERRAIN
	{
		//float r, g, b, a;
		float x, y, z;
		// �븻
		float nx, ny, nz;
		// �ؽ��� ��ǥ
		float u, v;
	};

	/// ������� (16����Ʈ ����)
	_declspec(align(16)) struct CBTERRAIN
	{
		XMMATRIX mWorld;
		XMMATRIX mView;
		XMMATRIX mProj;
		XMMATRIX mWVP;
		XMMATRIX mLightVP;
		XMMATRIX mTextm;
	};

	/// ������� (16����Ʈ ����)
	_declspec(align(16)) struct CBState
	{
		bool ShadowOnOff;
	};

public:
	string m_Filename;
	ID3D11Device* m_pDevCopy;					// ����̽� ī��
	ID3D11DeviceContext* m_pDevConCopy;			// ����̽� ���ؽ�Ʈ ī��
	Shader* m_pShader;

	///////////
	_VTXTERRAIN m_TerrainData;

	CBTERRAIN m_cbTerrain;

	ID3D11ShaderResourceView* g_pTexTerrain;
	CBLIGHT		m_CbLight;					// FBX ���� ���� ����
	CBState		m_State;
	CBFOG		m_CBFog;					// �Ȱ� ����

	ID3D11Buffer* m_pCbFogBuf;
	ID3D11Buffer* m_pTerrainbuf;
	ID3D11Buffer* m_pVb;
	ID3D11Buffer* m_pCbLightBuf;
	ID3D11Buffer* m_pStateBuf;
	/// ���� ����� �ȼ� ���̴�(�ӽ�...)
	ID3D11PixelShader* m_pPsDepth;

	float m_Width;
	float m_Height;
	float m_Slice;

public:
	virtual void InitTerrain() override;
	virtual void Update() override;
	virtual void Render(GRAPHICENGINE::ITerrain_Interface::RenderPath path, Matrix shadow, bool b) override;
	virtual void Release() override;


	void TerrainDraw_Depth(Matrix lightvpmat);
};

