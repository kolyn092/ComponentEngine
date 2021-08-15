///
///
///
/// FBX �� ��ü ���� ���� Ŭ����
/// [2021/02/09 RUNSUMIN]
#pragma once
#include "DxDefine.h"
#include "FbxData.h"
#include "Fbx_MeshData.h"
#include "MeshData_FBX_generated.h"

// serialize, deserialize
#include <flatbuffers/flexbuffers.h>
#undef min	//define������������ undef���������� �����Ͽ����� �߻��Ѵ�
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"

class FbxDataExporter
{
public:
	FbxDataExporter();
	~FbxDataExporter();
public:
	// �ѹ� �ε��� �����ʹ� �������.. key, value
	std::map<std::string, Fbx_MeshData*> m_ImportDatalist;

public:
	void ExportFbxData(string filename, Fbx_MeshData* inputdata);	
	void ExportFbxData_Flex(string filename, Fbx_MeshData* inputdata);	
	Fbx_MeshData* ImportFbxMetafile(string filename);
	Mat_Meta ChangeMatrixdataToMat(Matrix mat);

	string detachstring_fbx(string name);

	bool FindBinaryfile(string filename);

	Fbx_MeshData* SetFbxBinFile(string filename);

	void DeleteImportDataList();

	void SetTextrueDate();

};

