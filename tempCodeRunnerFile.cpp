    #include<iostream>
    #include<string>
    #include<fstream>
    using namespace std;
    class pin
    {
        private:
        string initialpin;
        string newpin;
        int attempts=3;
        public:
        //initial pin lai intialize
        pin()
        {
            initialpin="open";
        }
        //check initialpin
        void check()
        { 
            while(attempts>0)
            {
                string t;
                cout<<"enter open to continue"<<endl;
                cin>>t;
                if(t==initialpin && attempts!=0)
                {
                cout<<"acess granted"<<endl;
                break;
                }
                else if(attempts==0)
                {
                    cout<<"too many incorect attempts \n acess denied.......";
                    exit(0);
                }
                attempts--;
                cout<<attempts<<" atempts are left"<<endl;
            }
        }
        //change pin
        void authentication()
        { attempts=3;
        while(attempts>0)
            {
                string temp;
                cout<<"enter your old password:"<<endl;
                cin>>temp;
                if(temp==initialpin && attempts!=0)
                {
                   cout<<"enter your new password"<<endl;
                   cin>>newpin;
               ofstream file("pin.txt", ios::app);
            if (file.is_open())
            {
                file << "New PIN: " << newpin << endl;
                file.close();
                cout << "Password changed and saved successfully\n";
            }

                newcheck(); //new password check garna
                break;
            }
                }
                else if(attempts==0)
                {
                    cout<<"too many incorect attempts \n acess denied.......";
                    exit(0);
                }
                attempts--;
                cout<<attempts<<" atempts are left"<<endl;
            }
        }
        //check your new password
    void newcheck()
    { 
        string temp;
        attempts=3;
         while(attempts>0)
            {
                attempts--;
                cout<<"enter your password:"<<endl;
                cin>>temp;
                if(newpin==temp && attempts!=0)
                {
                cout<<"acess granted"<<endl;
                break;
                }
                else
                {
                    cout<<"to many incoorect attempts \n acess denied....";
                    exit(0);

                }
            }
    }
 
    };
    int main()
    {
        int choice;
        pin p;
        p.check();
        do
        {
            cout<<"1.change password"<<endl;
            cout<<"2.exit"<<endl;
            cin>>choice;
            switch(choice)
            {
                case 1:
                p.authentication();
                break;
                case 2:
                exit(0);
                default:
                cout<<"incorrect option"<<endl;
                break;
            }
        } while (choice!=2);
    }
