#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

Boss::~Boss()
{


}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����: " << this->m_Id << "\t"
		<< "\tְ������: " << this->m_Name << "\t"
		<< "\t��λ: " << this->getDeptName() << "\t"
		<< "\t��λְ��: ����˾��������" << endl;

}

//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}