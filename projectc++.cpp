    #include<iostream>
    #include<string>
    using namespace std;
    class pin
    {
        private:
        string initialpin;
        string pn;
        int attempts=3;
        public:
        pin()
        {
            initialpin="open";
        }
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
        void authentication()
        {
            attempts=3;
        
        cout<<"enter your new password:"<<endl;
        cin>>pn;
        initialpin=pn;
            while(attempts>0)
            {
                attempts--;
                if(pn==initialpin && attempts!=0)
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
