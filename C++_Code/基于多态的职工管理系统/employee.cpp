#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

Employee::~Employee()
{
	

}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����: " << this->m_Id << "\t"
		<< "\tְ������: " << this->m_Name << "\t"
		<< "\t��λ: " << this->getDeptName() << "\t" 
		<< "\t��λְ��: ��ɾ�����������" << endl;

}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("��ͨԱ��");
}