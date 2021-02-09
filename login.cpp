#include <bits/stdc++.h>
using namespace std;

void ClearScreen(){
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

int Register_login(){
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
				cout<<"\t\t\t\t\tsuccesfully logged\n";
				return flag;
			}
			else{
				cout<<"incorrect user_id and pass\n";
				Register_login();
				break;
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
			user<<user_id<<" "<<pass<<endl;
			Register_login();
			break;
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