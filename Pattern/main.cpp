#include "ObjectpoolManager.h"
#include "PrototypeManager.h"

int main(void)
{
	GETSINGLETON(PrototypeManager)->Initialize("Object");
	GETSINGLETON(ObjectpoolManager)->Initialize();

	ULONGLONG Time = GetTickCount64();
	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			system("cls");

			GETSINGLETON(ObjectpoolManager)->Update();
			GETSINGLETON(ObjectpoolManager)->Render();

			Time = GetTickCount64();
		}
	}

	//** DesableList ���� ����
	//** EnableList ���� ����

	DESTROYSINGLETON(ObjectpoolManager);
	DESTROYSINGLETON(PrototypeManager);

	return 0;
}
