//HW01.cpp
#include <iostream>
#include<string>
using namespace std;


void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	 *p_HPPotion = count;
	 *p_MPPotion = count;
}
int main(void)
{
	int HP, MP, ATK, DEF;
	int Status[4] = { 0, };
	
	cout << "스탯을 입력하세요(HP MP):"<<endl;
	cout << "#두 스탯모두 50을 초과해야합니다."<<endl;
	cin >> HP >> MP ;
	
	while(HP <= 50 || MP <= 50)
	{
		cout << "다시 입력해주세요." << endl;
		cout << "#두 스탯모두 50을 초과해야합니다." << endl;
		cin >> HP >> MP;
	}

	cout<<"스탯을 입력하세요(ATK DEF):" << endl;
	cout << "#두 스탯모두 0을 초과해야합니다." << endl;
	cin >> ATK >> DEF;

	while (ATK <= 0 || DEF <= 0)
	{
		cout << "다시 입력해주세요." << endl;
		cout << "#두 스탯모두 0을 초과해야합니다." << endl;
		cin >> ATK >> DEF;
	}
	Status[0] = HP;
	Status[1] = MP;
	Status[2] = ATK;
	Status[3] = DEF;

	int choice=7;
	int HPPotion = 0;
	int MPPotion = 0;

	setPotion(5, &HPPotion, &MPPotion);

	cout << "케릭터 생성완료 포션을 지급합니다.(HP & MP 5개씩)" << endl;

	while (choice != 0)
	{
		cout << "케릭터의 스텟을 설정하세요." << endl;
		cout << "1.HP 회복(+20) / 2.MP 회복(+20) / 3.ATK UP(2X) / 4.DEF UP(2X)" << endl;
		cout << "5.현재 능력치 / 6.Level up 0.Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (HPPotion <= 0)
			{
				cout << "포션이 부족합니다." << endl;
				break;
			}
			--HPPotion;
			Status[0] += 20;
			cout << "HP +20 현재HP:" << Status[0] << endl;
			cout << "남은 포션 수:" << HPPotion << endl;
			break;

		case 2:
			if (MPPotion <= 0)
			{
				cout << "포션이 부족합니다." << endl;
				break;
			}
			--MPPotion;
			Status[1] += 20;
			cout << "MP +20 현재MP:" << Status[1] << endl;
			cout << "남은 포션 수:" << MPPotion << endl;
			break;

		case 3:
			Status[2] = 2 * Status[2];
			cout << "ATK X 2 / 현재ATK:" << Status[2] << endl;
			break;

		case 4:
			Status[3] = 2 * Status[3];
			cout << "DEF X 2 / 현재DEF:" << Status[3] << endl;
			break;

		case 5:
			cout << "HP:" << Status[0] << " MP:" << Status[1] << endl;
			cout << "ATK:" << Status[2] << " DEF:" << Status[3] << endl;
			break;

		case 6:
			for (int i = 0; i < 2; ++i)
			{
				Status[i] += 50;
			}
			for (int j = 2; j < 4; ++j)
			{
				Status[j] += 10;
			}
			++HPPotion;
			++MPPotion;
			cout << "HP & MP 물약 +1" << endl;
			cout << "LEVEL UP ^_^b 모든 능력치 크게상승" << endl;
			break;

		case 0:
			cout << "스텟 설정창에서 나갑니다." << endl;
			break;
		
		default:
			cout << "선택지 내에서 번호를 골라주세요" << endl;
			break;

		}
	}
	
	
	return 0;
}