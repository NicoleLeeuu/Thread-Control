#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<queue>
#include<vector>
#include<time.h> 
using namespace std;
struct thread{
	int pid,priority,time;
	bool operator <(const thread &b) const{
		return priority==b.priority?pid>b.pid:priority<b.priority; 
	} 
};
priority_queue<thread> pq;
vector<thread> v;
void print(){
	printf("Ŀǰ�������еĽ��̣�\n");
	if(v.size()==0) printf("��\n");
	for(int i=0;i<v.size();i++){
		printf("pidΪ%d�Ľ���\n",v[i].pid);
	}
	priority_queue<thread> now=pq;
	printf("ĿǰΪ����̬�Ľ��̣�\n");
	if(now.empty()) printf("��\n");
	while(!now.empty()){
		thread top=now.top();
		now.pop();
		printf("pidΪ%d�Ľ���:  Ŀǰ���ȼ�Ϊ%d, ����ҪCPUʱ��Ϊ%d\n",top.pid,top.priority,top.time);
	} 
	cout<<endl;
}
int main(){
	int n,mode;
	cout<<"��ѡ����̵��ȷ���������1ѡ������Ȩ��������2ѡ����ת����";
	cin>>mode; 
	while(1){
		if(mode==1){
			printf("��ѡ������Ȩ��\n");
			break;
		} 
    	else if(mode==2){
    		printf("��ѡ����ת��\n");
    		break;
		} 
    	else{
    		printf("Error��������ѡ��");
    		cin>>mode;
		} 
	} 
	cout<<"�������������";
	cin>>n; 
	srand((unsigned)time(NULL));
	for(int i=1;i<=n;i++){
	    thread now={i,mode==1?rand()%100+1:10000,rand()%20+1};
	    printf("������%d�����̣�  Ŀǰ���ȼ�Ϊ%d����Ҫ��CPUʱ��Ϊ%d\n",i,now.priority,now.time);
    	pq.push(now);
    }
    printf("�Ѵ���%d�����̲��ѷ����������\n",n);
   	printf("��ʼ����\n");
   	int m=rand()%5+1,time=0;
   	while(!pq.empty()){
    	thread top=pq.top();
    	printf("���ε���ѡ��pidΪ%d�Ľ���\n",top.pid);
    	pq.pop();
    	top.time--;
    	if(mode==1)	top.priority-=3;
    	else time++;
    	if(top.time==0) v.push_back(top);
     	else{
     		if(mode==2&&time==m){
			    printf("����pidΪ%d�Ľ���ӵ�е�ʱ��Ƭ�ľ�\n\n",top.pid);
			    time=0;
			    top.priority-=m;
			}
		    pq.push(top);
		 } 
    	print();
   	}
    printf("���н�������ɣ�\n");
	return 0;
}
