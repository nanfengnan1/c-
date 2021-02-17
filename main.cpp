#include<iostream>
#include<list>
#include<string> 
#include<cstdio>
using namespace std;
//使用list(双向链表)容器对象实现简单的学生管理系统 
//list简单使用 

class Student{    //学生基本信息结构 
	public:
		char num[20]; //学号 
		char name[20];  //姓名 
		char sex[10];  //性别 
		int age; 	//年龄 
		
};
void menu(){
	cout<<"\n\n\n\n\n\n\n"; 
	cout<<"\t\t\t\t\t**********学生信息管理系统********"<<endl;
	cout<<"\t\t\t\t\t\t1.追加学生信息"<<endl;
	cout<<"\t\t\t\t\t\t2.删除最后一个学生的信息"<<endl;
	cout<<"\t\t\t\t\t\t3.显示学生信息"<<endl;
	cout<<"\t\t\t\t\t\t4.删除所有学生信息"<<endl;
	cout<<"\t\t\t\t\t\t5.统计学生个数"<<endl;
	cout<<"\t\t\t\t\t\t6.将学生信息保存到文件中"<<endl;
	cout<<"\t\t\t\t\t\t0.退出"<<endl;
	cout<<"\t\t\t\t\t请输入操作序号:";
} 
void fun1(list<Student> &L){
	system("cls");
	cout<<"\t\t\t\t\t************追加学生信息的界面************"<<endl;
	Student s;
	int n;
	cout<<"\t\t\t\t\t\t请输入要追加的学生个数:";
	cin>>n;
	if(n>0){
		cout<<"\t\t\t\t\t学号,学生姓名,学生性别,学生年龄:\n";
	}
	for(int i=0;i<n;i++){	
		cout<<"\t\t\t\t\t";
		cin>>s.num>>s.name>>s.sex>>s.age; 
		L.push_back(s);
	}
	cout<<"\t\t\t\t\t";
	system("pause");
	system("cls");
}
void fun2(list<Student> &L){
	system("cls");
	cout<<"\t\t\t\t*********删除最后一个学生的信息界面************"<<endl;
	if(!L.empty()){
		L.pop_back();
		cout<<"\t\t\t\t\t删除成功!"<<endl;
	}else{
		cout<<"\t\t\t\t\t数据库为空!"<<endl; 
	}
	cout<<"\t\t\t\t";
	system("pause");
	system("cls");
}
void fun3(list<Student> &L){
	system("cls");
	cout<<"\t\t\t\t\t*********显示学生信息的界面*********"<<endl;
	if(L.empty()){
		cout<<"\t\t\t数据库为空,无法显示!"<<endl;
	}else{
		int i=1;
		for(list<Student>::iterator it=L.begin();it!=L.end();it++,i++){
			cout<<"\t\t\t"<<i<<". 学号:"<<(*it).num<<"\t"<<"学生姓名:"<<(*it).name<<"\t\t"<<"学生性别:"<<(*it).sex<<"\t\t"<<"学生年龄:"<<(*it).age<<endl;
		}
	} 
	cout<<"\t\t\t";
	system("pause");
	system("cls");
}
void fun4(list<Student> &L){
	system("cls");
	cout<<"\t\t\t\t*********删除所有学生信息的界面*********"<<endl;
	if(L.empty()){
		cout<<"\t\t\t\t\t数据库为空!"<<endl;
	} else{
		L.clear();
		cout<<"\t\t\t\t\t删除成功!"<<endl; 
	}
	cout<<"\t\t\t\t";
	system("pause");
	system("cls");
}
void fun5(list<Student> &L){
	system("cls");
	cout<<"\t\t\t\t*********统计学生人数界面********"<<endl;
	cout<<"\t\t\t\t\t学生总人数为:"<<L.size()<<endl;
	cout<<"\t\t\t\t";
	system("pause");
	system("cls");
}
void fun6(list<Student> &L,FILE *fp){
	system("cls");
	cout<<"\t\t\t\t\t*********保存界面********"<<endl;
	fp=fopen("E:\\桌面存储位置\\a.txt","wb+");
	if(L.empty()){
		cout<<"\t\t\t\t数据库为空,保存无效!"<<endl;
	}else{
		for(list<Student>::iterator it=L.begin();it!=L.end();it++){
			fprintf(fp,"%s %s %s %d\n",(*it).num,(*it).name,(*it).sex,(*it).age);
		}
		cout<<"\t\t\t\t保存成功!"<<endl;
	} 
	fclose(fp);
	cout<<"\t\t\t\t"; 
	system("pause");
	system("cls");
} 
void fun0(){
	cout<<"\t\t\t\t\t是否退出?(y是,n不是):";
	char ch;
	cin>>ch;
	switch(ch){
		case 'y':{
			exit(0);
			break;
		}
		case 'n':{
			system("cls");
			break;
		}
	} 
}

int main()
{
	FILE *fp;	//定义一个文件结构体的指针 
	Student stu;
	list<Student> L;
	list<Student>::iterator pos;
	char ch;
	if((fp=fopen("E:\\桌面存储位置\\a.txt","r+"))==NULL){
		
	} 
	else{
		fscanf(fp,"%s%s%s%d",stu.num,stu.name,stu.sex,&stu.age);
		while(!feof(fp)){ //feof(fp)用于判断文件是否到结尾，是返回0 
		//使用feof一定要先读一次 
			L.push_back(stu);
			fscanf(fp,"%s%s%s%d",stu.num,stu.name,stu.sex,&stu.age);
		}
		fclose(fp);
	}
	while(1){
		menu();
		cin>>ch;
		switch(ch){
			case '1':{
				fun1(L);
				break;
			}
			case '2':{
				fun2(L);
				break;
			}
			case '3':{
				fun3(L);
				break;
			}
			case '4':{
				fun4(L);
				break;
			}
			case '5':{
				fun5(L);
				break;
			}
			case '6':{
				fun6(L,fp);
				break;
			}
			case '0':{ 
				fun0();
				break;
			}
			default:{
				system("cls");
				break;
			}
		} 
	}
	return 0;
} 
