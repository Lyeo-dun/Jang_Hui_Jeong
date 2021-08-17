#include <iostream>
#include <string>

using namespace std;

//#define
/*
* ��ũ�μ� Ű����
* ����� ������ �� ���� ��ũ��
* (ex. ���� ���콺 or ������ �� �� ��)
* �� �״�� ��ũ��
* define�� ó�� #�� ������ ��ó������ ��
* ��ó���⸦ ���� ���� �о� ��
* define�� ���ٷ� �����ϰ� �Ǿ�����
*/

//#define MAX 128
////�����̸� ���
////���𰡸� ���ȭ �����ش�
////����ƽ���� Ȯ���� �ٸ�
//
//#define Output(x, y) cout << (x + y) <<endl
//�� �ڿ� �����ݷ��� �ٿ��ָ� �����Լ� ������ ����� �� �����ݷ��� ����� �ʿ䰡 ������
//������ �����ݷ��� �ٿ����� ������ �鿩���Ⱑ �Ǳ⵵ �ϰ� �򰥸��� ������ ������ �����ݷ��� ������ �ʴ´�.
//define�� �� ������ �����ݷ��� ����

//#define Output(x, y)\
//{\
//	cout << (x + y) << endl;\
//} // \ => ���� ���ΰ� ���� ������ �̾���, ������ ���ΰ� ���� ������ �ϳ��� �������� �νĽ�Ŵ
////�̷� ������� define���� ��ġ �Լ�ó�� ����� �����ϴ�
////������ �� ���� ����

template<typename T>
inline void Safe_Release(T & _rObj)
{
	if (_rObj)
	{
		delete _rObj;
		_rObj = nullptr;
	}
}

#define SAFE_DELETE(obj) Safe_Release(obj)

//Singleton
#define DECLARE_SINGLETON(type)\
static type** GetInstance()\
{\
	static type* pInstance = new type;\
\
	if(pInstance == nullptr)\
		pInstance = new type;\
\
	return &pInstance;\
}\
static void DestroyInstance()\
{\
	type** ppInstance = GetInstance();\
\
	if ((*ppInstance) != nullptr)\
	{\
		delete *ppInstance; \
		ppInstance = nullptr; \
	}\
}

#define GETSINGLETON(type) (*type::GetInstance())
#define DESTROYSINGLETON(type) (*type::GetInstance())->DestroyInstance()

class Object
{
public:
	DECLARE_SINGLETON(Object)

public:
	int Number;

	void Render()
	{
		cout << "Object" << endl;
	}
public:
	Object() {}
	~Object() {}
};

int main(void)
{
	//�迭�� ���̴� �����̸鼭 ���(������ ����)�θ� ���ǵȴ�
	//�迭�� ���̴� ����� ���� �� ���� ������ �����ϴ� ��쿡�� �ʱⰪ���� ��밡��
	//int Array[MAX];

	//int Num1 = 10;
	//int Num2 = 20;
	//Output(Num1, Num2);

	//string str1 = "Hello ";
	//string str2 = "World!!";
	//Output(str1, str2)
	////���ڿ��� ���� �˰����� ����Ѵٸ� ����� �ͺ��� string�� ���°� ����
	
	/*
	Object* pObj = new Object(3);
	pObj->Render();
	
	SAFE_DELETE(pObj);
	*/

	//pObj->Output();

	//if (pObj == NULL)
	//{
	//	cout << "null!" << endl;
	//}

	GETSINGLETON(Object)->Render();
	GETSINGLETON(Object)->Number = 10;

	cout << GETSINGLETON(Object)->Number << endl;

	DESTROYSINGLETON(Object);

	return 0;
}