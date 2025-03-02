#include <iostream>			//���������
#include <math.h>
using namespace std;			//���ռ�

typedef struct
{
	double real;				//������ʵ��
	double imag;				//�������鲿 
} Complex;

//��ʼ����������Ϊ��������洢�ռ�
void InitComplex(Complex *&z)
{
	z=new Complex;			//z=(Complex *)malloc(sizeof(Complex));
} 

//���츴��
void AssignComplex(Complex *&z,double v1,double v2) 				//�������β� 
{
	z->real=v1;
	z->imag=v2;
}

//�������
void DispComplex(Complex *z) 
{
	if(z->real!=0){
		if(z->imag>0) {
			cout<<z->real<<"+"<<z->imag<<"i";
		}
		else if(z->imag==0) {
			cout<<z->real;
		}
		else {
			cout<<z->real<<z->imag<<"i";
		}
	}
	else {
		if(z->imag!=0) {
			cout<<z->imag<<"i";
		}
		else {
			cout<<0;
		}
	}
}//��Ҫ�����������һ���Ż�������ȷ���  6��-i, 0,8+i......

//�����ĺ�
void AddComplex(Complex *v1,Complex *v2,Complex *&s) 
{
	s->real=v1->real+v2->real;
	s->imag=v1->imag+v2->imag;
}

void MinusComplex(Complex *v1,Complex *v2,Complex *&s) {
	s->real=v1->real-v2->real;
	s->imag=v1->imag-v2->imag;
}

void MultiplyComplex(Complex *v1,Complex *v2,Complex *&s) {
	s->real=v1->real*v2->real+v1->imag*v2->imag;
	s->imag=v1->real*v2->imag+v1->imag*v2->real;
}

int DivideComplex(Complex *v1,Complex *v2,Complex *&s) {
	if (v2->real == 0&& v2->imag==0) {
		return 0;
	}
	s->real=(v1->real*v2->real+v1->imag*v2->imag)/(v2->real*v2->real+v2->imag*v2->imag);
	s->imag=(v1->imag*v2->real+v1->real*v2->imag)/(v2->real*v2->real+v2->imag*v2->imag);
	return 1;
}

double ModComplex(Complex *z) {
	return sqrt(z->real*z->real+z->imag*z->imag);
}

//���ٸ���
void DestroyComplex(Complex *&z)
{
	delete z;
} 

int main()
{
	double a,b;
	cout<<"�������һ��������ʵ��:";cin>>a;
	cout<<"�������һ���������鲿:";cin>>b;
	
	Complex *z1;InitComplex(z1);
	AssignComplex(z1,a,b);
	cout<<"��һ������Ϊ:";DispComplex(z1);cout<<endl;
	cout<<"��һ��������ģΪ:"<<ModComplex(z1)<<endl;
	
	double c,d;
	cout<<"������ڶ���������ʵ��:";cin>>c;
	cout<<"������ڶ����������鲿:";cin>>d;
	
	Complex *z2;InitComplex(z2);
	AssignComplex(z2,c,d);
	cout<<"�ڶ�������Ϊ:";DispComplex(z2);cout<<endl;
	cout<<"�ڶ���������ģΪ:"<<ModComplex(z2)<<endl;
	
	Complex *sum;InitComplex(sum);
	AddComplex(z1,z2,sum);
	cout<<"�����ĺ�Ϊ:";DispComplex(sum);cout<<endl;
	MinusComplex(z1,z2,sum);
	cout<<"�����Ĳ�Ϊ:";DispComplex(sum);cout<<endl;
	MultiplyComplex(z1,z2,sum);
	cout<<"�����Ļ�Ϊ:";DispComplex(sum);cout<<endl;
	int flag = DivideComplex(z1,z2,sum);
	if (flag == 0) {
		cout<<"�������̲��Ϸ�";cout<<endl;
	} else {
		cout<<"��������Ϊ:";DispComplex(sum);cout<<endl;
	}
	
	return 0;
 } 
