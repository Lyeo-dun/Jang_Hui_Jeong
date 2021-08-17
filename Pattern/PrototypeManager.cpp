#include "PrototypeManager.h"
#include "Object.h"


PrototypeManager::PrototypeManager()
{
}

PrototypeManager::~PrototypeManager()
{
	Release();
}

void PrototypeManager::Initialize(string _Str)
{
	//�⺻���� �ʱ�ȭ(���� �ʱ�ȭ�� ���������� ����)
	Transform TransInfo;
	TransInfo.Position = Vector3(0.0f, 0.0f);

	PrototypeList[_Str] = new Object(TransInfo);//���� ����Ʈ�� �߰�
}

void PrototypeManager::Release()
{
	for (auto iter = PrototypeList.begin(); iter != PrototypeList.end(); ++iter)
	{
		SAFE_DELETE((*iter).second); //���� ���� ����Ʈ ���� ������ ����
	}

	PrototypeList.clear();//���� ����Ʈ ����
}

Object* PrototypeManager::FindObject(string _str)
{
	//���� ����Ʈ�� ���� ������Ʈ�� �ִ��� Ȯ��
	auto iter = PrototypeList.find(_str);

	//ã�� ������Ʈ�� ���ٸ� nullptr ��ȯ
	if (iter == PrototypeList.end())
		return nullptr;

	//�ƴ϶�� ã�� ������Ʈ ��ȯ
	return iter->second;
}