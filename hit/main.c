#include <stdio.h>
#include <windows.h>
#define MAX_TARGET_NUM 32
#define MAX_BULLET_NUM 64
#define TOTAL_OBJECT_NUM ( MAX_TARGET_NUM + MAX_BULLET_NUM + 2 )

typedef struct _COMMON_OBJECT_
{
	bool isExist; //このオブジェクトが存在していればTRUE
	bool isChanging; //オブジェクトの中身が変更中であればTRUE この構造体の変数を書き換えるときはTRUEにし、書き換えが終了すればFALSEに戻す
	dword x; //オブジェクトの左上端のX座標
	dword y; //オブジェクトの左上端のY座標
	size_t size_x; //オブジェクトの横幅
	size_t size_y; //オブジェクトの縦幅
	int type; //オブジェクトの種類(弾の場合：敵(0)/自分(1)、的の場合：的の種類指定(物によってサイズが違う)
} CommonObject;

int Add_Point(int point, int type)//得点追加関数(急いで作ったから使えるか分からんから参考程度で)
{
	int E_point, S_point;
	
	if(type == 0)
	{
		E_point = point;
		return E_point;
	}
	else if(type == 1)
	{
		S_point = point;
		return S_point;
	}
}

/*敵の弾とメインキャラが重なった→弾を削除、敵に得点を追加(10点くらい)
自分の弾と敵のキャラが重なった→弾を削除、自分に得点を追加(10点くらい)
敵の弾と自分の弾が重なった→両方の弾を削除
自分の弾と的が重なった→弾を削除、的も削除し自分の得点を追加
敵の弾と的が重なった→弾を削除、的も削除し敵の得点を追加
自分のキャラと的が重なった→何もしない
敵のキャラと的が重なった→何もしない*/

CommonObject self, enemy;
CommonObject target[ MAX_TARGET_NUM ];
CommonObject bullet[ MAX_BULLET_NUM ];

void main()
{
	int i, j, Enemy_Point, Self_Point;
	
	for(i = 0; i < MAX_TARGET_NUM; i++) //ターゲットの配列0から31を順番に確認
	{
		for(j = 0; j < MAX_BULLET_NUM; j++)//弾の配列0から63を順番に確認
		{
			if(self.isExist == true && bullet[j].isExist == true && self.isChanging == false && bullet[j].isChanging == false && self.x == bullet[j].x && self.y == bullet[j].y && bullet[j].type == 0)//敵の弾とメインキャラが当たった場合
			{
				bullet[j].isChanging = true;
				bullet[j].size_x = 0; bullet[j].size_y = 0; Enemy_Point = 10; bullet[j].isChanging = false; //ここはbulletのisChangingがtrueになる時、弾を消して敵に10点追加する自作関数作ってもらって
			}
			else if(enemy.isExist == true && bullet[j].isExist == true && enemy.isChanging == false && bullet[j].isChanging == false && enemy.x == bullet[j].x && enemy.y == bullet[j].y && bullet[j].type == 1)//自分の弾と敵キャラが当たった場合
			{
				
				bullet[j].isChanging = true;
				bullet[j].size_x = 0; bullet[j].size_y = 0; Self_Point = 10; bullet[j].isChanging = false; //ここはbulletのisChangingがtrueになる時、弾を消してメインキャラに10点追加する自作関数作ってもらって		
			}
		}
	}
	
	return 0;
}