#include "PrototypeManager.h"
#include "Object.h"


//Object* pObjList[3] 
//��������� �ٸ�. ������ �ٸ��� ������ ��!
list<Object*> pObjList;

void Init(string _str)
{
	//���� ��ü ã��
	Object* pObj = GETSINGLETON(PrototypeManager)->FindObject(_str);

	//ã�� ��ü�� ���ٸ� �����޼��� ��� �� �Լ� ����
	if (pObj == nullptr)
	{
		COORD Pos = { 50, 15 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

		cout << " ������ ���� ��ü�� ���� " << endl;
		return; //�Լ� ����
	}
	 //ã�� ��ü�� �ִٸ� ����
	for (int i = 0; i < 3; ++i)
	{
		Object* pTempObj = pObj->Clone();

		pTempObj->Initialize(); //���纻 �ʱ�ȭ
		pTempObj->SetIndex(i + 1); //���纻�� �ε������� ����

		pObjList.push_back(pTempObj); //������ ���� ��ü�� ���纻 �ѱ�
		//�ƹ��͵� ����� �ʾұ� ������ ������ ��� ��ü�� �־����
	}
}

int main(void)
{
	/*
	* �뷮 ������ ���� �������
	* objectpool�� ����� �����ϴ� �Ͱ� ����
	* ������ prototype�� ��� ��踦 �鿩���� �Ͱ� ����
	*/

	//Index 1, 2, 3���� ���

	//prototype manager �ʱ�ȭ
	GETSINGLETON(PrototypeManager)->Initialize();

	Init("Object"); //�׳� ������ ���� �� ��� ���ٸ� ������ �� ���̱� ������

	{
		for (list<Object*>::iterator iter = pObjList.begin(); iter != pObjList.end(); ++iter)
			if ((*iter))
			{
				(*iter)->Render();
			}
	}

	for (list<Object*>::iterator iter = pObjList.begin(); iter != pObjList.end(); ++iter)
	{
		SAFE_DELETE((*iter));
	}

	pObjList.clear();

	return 0;
}

/*
* �ʱⱸ��
* ������׿� ���� ����
* ��� ����
* ����
*/