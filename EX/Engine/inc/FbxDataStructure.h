///
///
///
/// Fbx �� �� ������ 
/// [2020/10/15 RUNSUMIN]
#pragma once
#include "DxDefine.h"
//#include <SimpleMath.h> // �� �ȵ�¡...
// ���ؽ� ����... -> ���ؽ� ���� ���� ������

struct Vertex
{
	Vector4 Pos;
	Vector4 Weight;
	DWORD   index[4];
	Vector3 Nor;
	Vector3 Binor;
	Vector3 Tangent;
	Vector2 Uv;
};

struct Bone
{
	string m_Name;
	string m_Parentname;
	unsigned int BoneIndex;
	Matrix LocalTm;
	Matrix GlobalTM;
	Matrix InvGlobalTm;
	Matrix GlobalBindingTm;

	Bone* pParentBone;
	vector<Bone*> pChildBoneList;
};

struct BoneOffset
{
	int BoneIndex;
	Matrix BoneOffSetMatrix;
};

struct BoneIndexWeight
{
	std::vector<std::pair<unsigned int, float>> boneIndexWeights;
};

struct Index
{
	DWORD A, B, C;
};

struct Fbx_Material
{
	Vector4 Diffuse;
	Vector4 Ambient;
	Vector4 Specular;
	int MaterialNum;						// �ؽ��� ��ȣ - �ؽ��Ŀ� ����
};
// �ִϸ��̼�

struct KeyFrameData
{
	float Time;
	Vector3 Scale;
	Vector4 Rot_Quat;
	Vector3 Trans;
};

struct OneFrameList
{
	OneFrameList* pParent;
	vector<OneFrameList*> pChildList;

	// ���� ������
	vector<KeyFrameData> FrmList;
};

struct AnimationData
{
	float FramesPerSecond;
	int	  TotalFrames;
	float StartTime;
	float EndTime;
	float TotalTime;
	string Name;

	Matrix BoneOffSet;

	vector<OneFrameList*> AnimationList;
};

