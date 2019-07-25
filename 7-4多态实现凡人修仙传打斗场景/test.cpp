
#include<iostream>
#include"Hero.h"
#include"Monster.h"
#include"Weapon.h"
#include"Knife.h"
#include"DragonSword.h"
using namespace std;

void play()
{
	//创建怪物
	Monster * monster = new Monster;
	//创建英雄
	Hero *hero = new Hero;
	//创建武器
	Weapon * kinfe = new Knife;
	Weapon * dragon =new DragonSword;

	//让用户选择武器
	cout << "请选择武器：" << endl;
	cout << "1. 赤手空拳" << endl;
	cout << "2. 小刀" << endl;
	cout << "3. 屠龙刀" << endl;

	int oper;
	cin >> oper;
	switch (oper)
	{
	case 1:
		cout << "你真牛X,你还是太年轻了" << endl;
		break;
	case 2:
		hero->EquipWeapon(kinfe);
		break;
	case 3:
		hero->EquipWeapon(dragon);
		break;
	default:
		cout << "没有你要选择的武器" << endl;
		break;
	}

	getchar();//输入缓冲区里有个回车，多获取一次值

	int round = 1;
	while (true)
	{
		getchar();
		system("cls");
		cout << "--当前第" << round << "回合开始-----" << endl;
		if (hero->m_Hp <= 0)
		{
			cout << "英雄" << hero->m_Name << "已挂，游戏结束" << endl;
			break;
		}
		hero->Attack(monster);

		if (monster->m_Hp <= 0)
		{
			cout << "怪物" << monster->m_Name << "已挂，顺利通关" << endl;
			break;
		}
		monster->Attack(hero);

		if (hero->m_Hp <= 0)
		{
			cout << "英雄" << hero->m_Name << "已挂，游戏结束" << endl;
			break;
		}
		cout << "英雄" << hero->m_Name << "剩余血量" << hero->m_Hp << endl;
		cout << "怪物" << monster->m_Name << "剩余血量" << monster->m_Hp << endl;

		round++;
	}


	delete monster;
	delete hero;
	delete kinfe;
	delete dragon;


}





 



int main()
{
	play();
	system("pause");
	return 0;
}