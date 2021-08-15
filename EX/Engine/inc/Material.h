///
///
/// �� �� ���� ���� 
/// �������� �� ������ ���� ���� ������ ���� �и����ش�.
/// [2021/05/06 RUNSUMIN]
#pragma once
#include "D3DDevice.h"
#include "EngineInterface.h"
#include "DxDefine.h"
class Material : public GRAPHICENGINE::IMaterialInterface
{
public:
	Material();
	~Material();
public:

private:
	// ��尡 ������ ���� �� ������...
	/// PBR - MainMap
	ID3D11ShaderResourceView* m_pAlbedoMap;		// == Diffuse , BaseColor
	ID3D11ShaderResourceView* m_pNormalMap;
	ID3D11ShaderResourceView* m_pORMMap;		// Occlusion, Roughness, Metallic
	ID3D11ShaderResourceView* m_MaskMap;
	/// Emissive
	ID3D11ShaderResourceView* m_pEmissiveMap;


	// �ε��� �ؽ��� ���� �ޱ�.
	string m_AlbedoFilepath;
	string m_NormalMapFilepath;
	string m_MaskMapFilepath;
	string m_ORMMapFilepath;
	string m_EmissiveMapFilepath;

public:
	bool m_TexOn;
	bool m_NorOn;
	bool m_MaskOn;
	bool m_PBROn;
	bool m_EmissiveOn;

	string m_LinkNodename;
public:
	virtual void SetTexturePath(string filename, TextureSort sort) override;
	void SetShaderRes(string filename, TextureSort sort);
	virtual string GetTexturePath(TextureSort sort) override;
	virtual void SetLinkNodename(string nodename) override;
	virtual string GetLinkNodename() override;

	ID3D11ShaderResourceView* GetShaderRes(TextureSort sort);
};

