//
//
// 
// ȭ�鿡 �ѷ��� �ؽ��� ������ Ŭ����
// ȸ���� ���� �߰� ����... ��������� ����.
// [2021/02/06 RUNSUMIN]
#pragma once
#include "DxDefine.h"
#include "D3DDevice.h"
#include "Shader.h"

struct _VTX
{
	Vector3 pos;
	Vector2 tex;
};

struct OVERLAYCOLOR
{
	Vector4 color;
};
class Sprite
{
public:
	Sprite(Vector3 pos);
	/// interface
	Sprite(Vector3 pos, Vector3 scl, string TexFileName);	
	/// RenderTarget
	Sprite(Vector3 pos, Vector3 scl, ID3D11ShaderResourceView* ptex);
	~Sprite();

private:

	string m_Filename;
	Shader* m_pShader;							// ���̴� ����
	CBDEFAULT   m_CbDef;						// �⺻ ��� ��� ����
	OVERLAYCOLOR  m_CbMtl;						// ���� ����

	ID3D11Buffer* m_pCbDefBuf;					// �⺻ ������� ����
	ID3D11Buffer* m_pCbMtlBuf;					// ���� ���� ����

	ID3D11Device* m_pDevCopy;					// ����̽� ī��
	ID3D11DeviceContext* m_pDevConCopy;			// ����̽� ���ؽ�Ʈ ī��

	ID3D11ShaderResourceView* m_pTex;			// �ؽ��� ����
	D3D11_TEXTURE2D_DESC	m_TexDesc;		// ����ũ 

	// ȭ�鿡 �浹 �ؾ� �� ���� ������ ��������(���콺 X)
	ID3D11Buffer* m_pVB;

	/// ���� �ȼ� ���̴�
	ID3D11PixelShader* m_pPsDepth;
	ID3D11PixelShader* m_pPsBloom;
	ID3D11PixelShader* m_pPsFinal;
	ID3D11PixelShader* m_pPsSampling;
	ID3D11PixelShader* m_pPsBlur;

public:
	Matrix m_View;
	Matrix m_Porj;

	Vector3 m_Pos;
	Vector3 m_Scl;
	Vector3 m_Rot;

	float	m_Width;		// ����
	float	m_Height;		// ����
	Vector4 m_OverRayCol;	// ��������Ʈ ���� ���� ����.

	float m_ChangeSizeX;
	float m_ChangeSizeY;

public:
	int InitSprite();
	int InitShader();
	void UpdateSprite(Vector3 pos, Vector3 scl);
	int DrawSprite();
	int ReleaseSprite();
	void SetChangeSize(float x, float y);

	/// RenderTarget ����
	void DrawSprite_Rt(ID3D11ShaderResourceView* ptex, float drawsizeX, float drawsizeY);
	void DrawSprite_Bloom(ID3D11ShaderResourceView* ptex, float drawsizeX, float drawsizeY);
	void DrawSprite_FINAL(ID3D11ShaderResourceView* pResult, ID3D11ShaderResourceView* pAddTex, float drawsizeX, float drawsizeY);
	void DrawSprite_Blur_ACC(ID3D11ShaderResourceView* pResult, ID3D11ShaderResourceView* pAddTex, float drawsizeX, float drawsizeY);
	void DrawSprite_Blur(ID3D11ShaderResourceView* pResult, float drawsizeX, float drawsizeY, float SampleCount);

};

