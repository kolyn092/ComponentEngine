//
//
//
// 
// [2020/07/23 RUNSUMIN]
#pragma once
#pragma warning(disable:4996)

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.

#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <fbxsdk.h>
// include
#include <D3D11.h>
#include <d3dcompiler.h>				//	shader �����Ϸ� ���
//#include "directxmath.h"
#include <stdio.h>
#include <Tchar.h>
#include <windows.h>
#include <SimpleMath.h>
#include <DirectXTex.h>	
#include <DDSTextureLoader.h> 
#include <WICTextureLoader.h>


using namespace DirectX::SimpleMath;
using namespace std;

// linking
#pragma comment(lib,"D3D11")
#pragma comment(lib,"dxgi")
#pragma comment(lib,"d3dcompiler")
#pragma comment(lib, "flatbuffers")

#ifdef _DEBUG 
#ifdef _WIN64
#pragma comment(lib, "DirectXTex64d")	//����� ����.(64bit)
#elif _WIN32
#pragma comment(lib, "DirectXTexd")		//����� ����.
#endif
#else
#ifdef _WIN64 
#pragma comment(lib, "DirectXTex64")	//������ ���� (64bit)
#elif _WIN32 
#pragma comment(lib, "DirectXTex")		//������ ����.
#endif
#endif




//////////////////////////////////////////////////////////////////////////



//DrawText
#include <DirectXTK.h>
using namespace DirectX;

// define
#include "Define.h"

// warning
//#include "AlignedAllocationPolicy.h"


#ifndef SAFE_RELEASE
#define SAFE_RELEASE(pBuff) if((pBuff)){ (pBuff)->Release(); (pBuff) = NULL; }
#define SAFE_DELETE(pBuff)	if((pBuff)){ delete (pBuff); (pBuff) = NULL; }
#define SAFE_DELARRY(pBuff) if((pBuff)){ delete [] (pBuff); (pBuff) = NULL; }
#endif

#define OK_SIGN	0x00000000
#define FAIL_SIGN	-1

typedef XMMATRIX		MATRIXA;
typedef XMFLOAT4X4		MATRIX;
typedef XMVECTOR		VECTOR;
typedef XMFLOAT4		VECTOR4;
typedef XMFLOAT3		VECTOR3;
typedef XMFLOAT2		VECTOR2;

//���� Ÿ��: 2����.
//typedef XMCOLOR		COLOR;	
typedef XMFLOAT4		COLOR;

// ����, ���ٽ� �׽�Ʈ ����

enum eDepthStencilSet
{
	DS_DEPTH_ON,		
	DS_DEPTH_OFF,		
	DS_DEPTH_WRITE_OFF,	

	//���ٽ� ���� �����.
	DS_DEPTH_ON_STENCIL_ON,
	DS_DEPTH_ON_STENCIL_EQUAL_KEEP,
	DS_DEPTH_ON_STENCIL_NOTEQUAL_KEEP,

	DS_DEPTH_WRITE_OFF_STENCIL_ON,
	DS_DEPTH_OFF_STENCIL_EQUAL_INCR,


	//���� ��� �ִ밪.
	DS_MAX_,

	//��� ������. MAX �� ���ʿ� �����ؾ� ��. ����.
	DS_DEPTH_ON_STENCIL_OFF = DS_DEPTH_ON,			//���̹��� ON, ���ٽǹ��� OFF
	DS_DEPTH_ONLY = DS_DEPTH_ON_STENCIL_OFF,		//���̹��� ON, ���ٽǹ��� OFF
};

enum eObjectRasterizerState 
{
	RS_SOLID,				//�ﰢ�� ä��� : Fill Mode - Soild.
	RS_WIREFRM,				//�ﰢ�� ä��� : Fill Mode - Wireframe.
	RS_CULLBACK,			//�޸� �ø� (ON) : Back-Face Culling - "CCW" 
	RS_CULLFRONT,			//���� �ø� (ON) : Front-Face Culling - "CW" 	
	RS_WIRECULLBACK,		//���̾� ������ + �޸� �ø� (ON) 
	RS_WIRECULLFRONT,		//���̾� ������ + �ո� �ø� (ON) 	

	//���� ��� �ִ밪.
	RS_MAX_,

	//��� ������. MAX �� ���ʿ� �����ؾ� ��. ����.
	RS_CULL_CCW = RS_CULLBACK,
	RS_CULL_CW = RS_CULLFRONT,
	RS_WIRE_CULL_CCW = RS_WIRECULLBACK,
	RS_WIRE_CULL_CW = RS_WIRECULLFRONT,

};

enum eObjectBlendingState
{
	BS_DEFAULT,				//�⺻ȥ�� ��ü.
	BS_ALPHA_BLEND,			//���� ����. (Src.a + (1-Src.a))
	BS_COLOR_BLEND,			//���� ����. ( Src.Color + (1-Src.Color))
	BS_COLOR_BLEND_ONE,		//1:1 ����. ( Src.Color + Dest.Color) 

	BS_MAX_,

	BS_AB_OFF = BS_DEFAULT,
	BS_AB_ON = BS_ALPHA_BLEND,
	//BS_AB_ALPHA = BS_ALPHA_BLEND,
	//BS_AB_COLOR = BS_COLOR_BLEND,
};

enum eTextureSamplerState
{
	SS_CLAMP,			//�ؽ�ó ��巹�� ��� : Ŭ���� (DX �⺻��) 
	SS_WRAP,			//�ؽ�ó ��巹�� ��� : ���� 
	SS_BOARDER,
	SS_SHADOW,
	//SS_MIRROR,
	//SS_MIRRROONCE,

	SS_MAX,
	SS_DEFAULT = SS_WRAP,	//�⺻ ���÷�

};
