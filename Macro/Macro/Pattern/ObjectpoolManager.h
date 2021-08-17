#pragma once
#include "Headers.h"
#include "Define.h"

class Object;
class ObjectpoolManager
{
public:
	DECLARE_SINGLETON(ObjectpoolManager)

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	list<Object*> EnableList; //Ȱ��ȭ ������Ʈ ����Ʈ
	list<Object*> DesableList; //��Ȱ��ȭ ������Ʈ ����Ʈ
	
public:
	list<Object*>* GetDesableList() { return &DesableList; }
	void AddEnalbeList(string, Vector3);//Ȱ��ȭ ����Ʈ�� �߰�
	list<Object*>* GetEnableList() { return &EnableList; }
	
private:
	void AddDesObjList(string);//��Ȱ��ȭ ����Ʈ�� �߰�
	void Output(float _x, float _y, string _str);

public:
	ObjectpoolManager();
	~ObjectpoolManager();
};

