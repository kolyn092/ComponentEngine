///
///
/// �׷��Ƚ� ���� ���� ���̴� ���� Ŭ����
/// ���� : ���� ���ξּ� ����� ���̴����� �̸� �ε� �� ���� 
///			���������� ����ϱ� ����...
/// 
/// [2020/12/30 RUNSUMIN]
#include "Shader.h"
#include "Fog.h"
#pragma once
class ShaderMgr
{
public:
	// ���� ���ο��� ������ �ʿ䰡 �ִ�.
	ShaderMgr();
	~ShaderMgr();
	// �Ŵ����� ���� ���ο��� �̱������� �����Ѵ�.
	static ShaderMgr* m_Instance;
	static ShaderMgr* GetInstance();

public:
	enum class ShaderSort
	{
		AXIS, TERRAIN, BUILDING, CHARACTER, UI
	};

	// Static Mesh
	Shader* m_pStatic;
	// SKinned Mesh
	Shader* m_pSkinned;
	//// UI
	Shader* m_pUI;

	/// ���� �ȼ� ���̴�
	ID3D11PixelShader* m_pPsDepth;
	ID3D11PixelShader* m_pPsDepth_Static;
	ID3D11PixelShader* m_pPsShadow;
	ID3D11PixelShader* m_pPsDepth_UI;
	ID3D11PixelShader* m_pPsBloom;
	ID3D11PixelShader* m_pPsFinal;
	ID3D11PixelShader* m_pPsSampling;
	ID3D11PixelShader* m_pPsBlur;
	//Depth ���� ���̴� ���ҽ�...
	ID3D11ShaderResourceView* m_pShadow;

	// Skybox texture
	ID3D11ShaderResourceView* m_pSkybox;
	ID3D11ShaderResourceView* m_pSkybox_irradiance;

	// Direction Light ViewProjMatrix
	Matrix m_LightViewProjMat;
	CBFOG m_Fog;

private:
	ID3D11Device* m_pDevCopy;				// ����̽� ī��
	ID3D11DeviceContext* m_pDevConCopy;		// ����̽� ���ؽ�Ʈ ī��

public:
	void InitShaderMgr();
	void ReleaseShaderMgr();

};

