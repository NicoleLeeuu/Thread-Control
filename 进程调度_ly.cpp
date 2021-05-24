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
	printf("目前结束运行的进程：\n");
	if(v.size()==0) printf("无\n");
	for(int i=0;i<v.size();i++){
		printf("pid为%d的进程\n",v[i].pid);
	}
	priority_queue<thread> now=pq;
	printf("目前为就绪态的进程：\n");
	if(now.empty()) printf("无\n");
	while(!now.empty()){
		thread top=now.top();
		now.pop();
		printf("pid为%d的进程:  目前优先级为%d, 还需要CPU时间为%d\n",top.pid,top.priority,top.time);
	} 
	cout<<endl;
}
int main(){
	int n,mode;
	cout<<"请选择进程调度方法，输入1选择优先权法，输入2选择轮转法：";
	cin>>mode; 
	while(1){
		if(mode==1){
			printf("已选择优先权法\n");
			break;
		} 
    	else if(mode==2){
    		printf("已选择轮转法\n");
    		break;
		} 
    	else{
    		printf("Error！请重新选择：");
    		cin>>mode;
		} 
	} 
	cout<<"请输入进程数：";
	cin>>n; 
	srand((unsigned)time(NULL));
	for(int i=1;i<=n;i++){
	    thread now={i,mode==1?rand()%100+1:10000,rand()%20+1};
	    printf("创建第%d个进程：  目前优先级为%d，需要的CPU时间为%d\n",i,now.priority,now.time);
    	pq.push(now);
    }
    printf("已创建%d个进程并已放入就绪队列\n",n);
   	printf("开始调度\n");
   	int m=rand()%5+1,time=0;
   	while(!pq.empty()){
    	thread top=pq.top();
    	printf("本次调度选用pid为%d的进程\n",top.pid);
    	pq.pop();
    	top.time--;
    	if(mode==1)	top.priority-=3;
    	else time++;
    	if(top.time==0) v.push_back(top);
     	else{
     		if(mode==2&&time==m){
			    printf("本轮pid为%d的进程拥有的时间片耗尽\n\n",top.pid);
			    time=0;
			    top.priority-=m;
			}
		    pq.push(top);
		 } 
    	print();
   	}
    printf("所有进程已完成！\n");
	return 0;
}
