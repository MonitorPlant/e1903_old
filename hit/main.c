#include <stdio.h>
#include <windows.h>
#define MAX_TARGET_NUM 32
#define MAX_BULLET_NUM 64
#define TOTAL_OBJECT_NUM ( MAX_TARGET_NUM + MAX_BULLET_NUM + 2 )

typedef struct _COMMON_OBJECT_
{
	bool isExist; //���̃I�u�W�F�N�g�����݂��Ă����TRUE
	bool isChanging; //�I�u�W�F�N�g�̒��g���ύX���ł����TRUE ���̍\���̂̕ϐ�������������Ƃ���TRUE�ɂ��A�����������I�������FALSE�ɖ߂�
	dword x; //�I�u�W�F�N�g�̍���[��X���W
	dword y; //�I�u�W�F�N�g�̍���[��Y���W
	size_t size_x; //�I�u�W�F�N�g�̉���
	size_t size_y; //�I�u�W�F�N�g�̏c��
	int type; //�I�u�W�F�N�g�̎��(�e�̏ꍇ�F�G(0)/����(1)�A�I�̏ꍇ�F�I�̎�ގw��(���ɂ���ăT�C�Y���Ⴄ)
} CommonObject;

int Add_Point(int point, int type)//���_�ǉ��֐�(�}���ō��������g���邩������񂩂�Q�l���x��)
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

/*�G�̒e�ƃ��C���L�������d�Ȃ������e���폜�A�G�ɓ��_��ǉ�(10�_���炢)
�����̒e�ƓG�̃L�������d�Ȃ������e���폜�A�����ɓ��_��ǉ�(10�_���炢)
�G�̒e�Ǝ����̒e���d�Ȃ����������̒e���폜
�����̒e�ƓI���d�Ȃ������e���폜�A�I���폜�������̓��_��ǉ�
�G�̒e�ƓI���d�Ȃ������e���폜�A�I���폜���G�̓��_��ǉ�
�����̃L�����ƓI���d�Ȃ������������Ȃ�
�G�̃L�����ƓI���d�Ȃ������������Ȃ�*/

CommonObject self, enemy;
CommonObject target[ MAX_TARGET_NUM ];
CommonObject bullet[ MAX_BULLET_NUM ];

void main()
{
	int i, j, Enemy_Point, Self_Point;
	
	for(i = 0; i < MAX_TARGET_NUM; i++) //�^�[�Q�b�g�̔z��0����31�����ԂɊm�F
	{
		for(j = 0; j < MAX_BULLET_NUM; j++)//�e�̔z��0����63�����ԂɊm�F
		{
			if(self.isExist == true && bullet[j].isExist == true && self.isChanging == false && bullet[j].isChanging == false && self.x == bullet[j].x && self.y == bullet[j].y && bullet[j].type == 0)//�G�̒e�ƃ��C���L���������������ꍇ
			{
				bullet[j].isChanging = true;
				bullet[j].size_x = 0; bullet[j].size_y = 0; Enemy_Point = 10; bullet[j].isChanging = false; //������bullet��isChanging��true�ɂȂ鎞�A�e�������ēG��10�_�ǉ����鎩��֐�����Ă������
			}
			else if(enemy.isExist == true && bullet[j].isExist == true && enemy.isChanging == false && bullet[j].isChanging == false && enemy.x == bullet[j].x && enemy.y == bullet[j].y && bullet[j].type == 1)//�����̒e�ƓG�L���������������ꍇ
			{
				
				bullet[j].isChanging = true;
				bullet[j].size_x = 0; bullet[j].size_y = 0; Self_Point = 10; bullet[j].isChanging = false; //������bullet��isChanging��true�ɂȂ鎞�A�e�������ă��C���L������10�_�ǉ����鎩��֐�����Ă������		
			}
		}
	}
	
	return 0;
}