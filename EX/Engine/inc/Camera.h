 //
//
//
// ī�޶� Ŭ���� ����
// [2020/08/03 RUNSUMIN]
#pragma once
#include "DxDefine.h"
#include "D3DDevice.h"
#include "DrawText_Debug.h"
#include "EngineInterface.h"

class Camera : public GRAPHICENGINE::ICameraInterface
{
public:
	Camera(Vector3 pos, Vector3 rot);
	~Camera();

public:

	Vector3 m_Position;
	Vector3 m_Rotation;
	Vector3 m_Scale;

	// ���� ��ȯ ����
	float m_Fov;
	float m_AspectRatio;
	float m_Near;
	float m_Far;


private:
	// ���¿� ����
	Vector3 m_PosBk;
	Vector3 m_RoatationBk;
	Vector3 m_ScaleBk;


	// ����Ÿ�� ���� ����.
	Vector3 m_PosRtBk;
	Vector3 m_RoatationRtBk;
	Vector3 m_ScaleRtBk;
	float ViewW;
	float ViewH;
	// ī�޶�ӵ�
	float m_CameraSpeed;
	GRAPHICENGINE::ICameraInterface::Mode  m_CameraMode;
	// ���
	Matrix m_View;
	Matrix m_Proj;
	Matrix m_Transform;

public:
	void ResetCamera();
	void RestoreCamera();
	void BackUpCameraData();
	void SetCameraMatrixData();
	void GetCameraData_FromGameEngine(Matrix view, Matrix proj);
	void CameraInfo(int width, int height);


	///////////////////////////////////////////

	virtual void InitializeCamera()	override;
	virtual	void UpdateCamera(float dTime) override;
	virtual void SetCamerSRTData(Vector3 pos, Vector3 rot, Vector3 scl) override;
	virtual void ChangeCameraMode(ICameraInterface::Mode emode) override;
	virtual void SetCameraSpeed(float speed) override;
	virtual void CameraInfo() override;
	virtual void ReleaseCamera() override;
	virtual Matrix GetCameraViewMat() override;
	virtual Matrix GetCameraProjMat() override;
	virtual Vector3 GetCameraPos() override;
	virtual Vector3 GetCameraRot() override;
	virtual Vector3 GetCameraScl() override;

};



