#include <bits/stdc++.h>
using namespace std;

void ClearScreen(){
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

string Register_login(){
	cout<<"=>Press 1 for Signin\n=>Press 2 for Signup \nPress q to quit\n";
	char key;
	cin>>key;
	fstream user;
	user.open("user.txt",std::fstream::in | std::fstream::out | std::fstream::app);
	switch(key){
		case '1':{
			cout<<"Enter user id\n";
			string user_id;
			cin>>user_id;
			cout<<"Enter Password\n";
			string pass;
			cin>>pass;
			string _userid, _pass;
			string line=" ";
			int flag = 0;
			while(getline(user,line)){
				stringstream iss(line);
				iss >> _userid >> _pass;
				if(_userid==user_id && _pass==pass){
					flag=1;
					break;
				}
			}
			if(flag==1){
				ClearScreen();
				cout<<"\t\t\tsuccesfully logged as "<<user_id<<"\n";
				return user_id;
			}
			else{
				cout<<"\t\t\tincorrect user_id and pass\n\n";
				return "zzzzzzzzzzzzzzzzzzzzzzzzz";
			}
		}
		// while()
		case '2':{
			cout<<"Enter user id\n";
			string user_id;
			cin>>user_id;
			cout<<"Enter Password\n";
			string pass;
			cin>>pass;
			string _userid, _pass;
			string line=" ";
			int flag = 0;
			while(getline(user,line)){
				stringstream iss(line);
				iss >> _userid >> _pass;
				if(_userid==user_id && _pass==pass){
					flag=1;
					break;
				}
			}
			if(flag!=1){
				cout<<"\t\t\tsuccesfully Registered as " <<user_id<<"\n";
				user<<user_id<<" "<<pass<<endl;
				return user_id;
			}
			else{
				cout<<"\t User already exist\n";
				return "zzzzzzzzzzzzzzzzzzzzzzzzz";
			}
		}
		case 'q':{
			exit(0);
		}
		default:{
			Register_login();
		}
	}
	return 0;
}