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

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号: " << this->m_Id << "\t"
		<< "\t职工姓名: " << this->m_Name << "\t"
		<< "\t岗位: " << this->getDeptName() << "\t"
		<< "\t岗位职责: 管理公司所有事物" << endl;

}

//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}