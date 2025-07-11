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
                cout<<"enter 'open' to continue"<<endl;
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
        { 
            attempts=3;
            string extract;//to check if file is empty
          ifstream file("pin.txt");
        if (file.is_open()) 
    {
        getline(file, extract);  // read first line from file into a
        file.close();
    }
     if (extract.empty()) 
        {
        initialpin="open";
        }
        else{
           initialpin=extract;
        }
        while(attempts>0)
            {
                string temp;
                cout<<"enter your 'old' password:"<<endl;
                cin>>temp;
                if(temp==initialpin && attempts!=0)
                {
                   cout<<"enter your 'new' password"<<endl;
                   cin>>newpin;
           
            ofstream file("pin.txt");  // overwrite in file
            if (file.is_open()) {
                file << newpin << endl;
                file.close();
                cout << "Password changed and saved successfully\n";
            } else {
                cout << "Failed to save password \n";
            }

                newcheck(); //new password check garna
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
        //check your new password
    void newcheck()
    { 
         attempts=3;
        string temp;
         string checkpin;//file ma vako pass checkpin ma rakhne
    ifstream file("pin.txt");

    if (file.is_open()) {
        getline(file, checkpin);  // read the first line into checkpin
        file.close();
    } else {
        cout << "Unknown error occured\n";
    }
         while(attempts>0)
            {
                cout<<"enter your password:"<<endl;
                cin>>temp;
                if(checkpin==temp && attempts!=0)
                {
                cout<<"acess granted"<<endl;
                break;
                }
                else if(attempts==0)
                {
                    cout<<"to many incoorect attempts \n acess denied....";
                    exit(0);

                }
                 attempts--;
                cout<<attempts<<" atempts are left"<<endl;
            }
        }

    };
    class person
    {
        protected:
        string name;
        int age;
        float height;
        public:
        void inputpersondata()
        {
            cout<<"enter your name:"<<endl;
            cin>>name;
            cout<<"enter your age:"<<endl;
            cin>>age;
            cout<<"enter your height in cm:"<<endl;
            cin>>height;
        }
    };
    int main()
    {
        pin pass;
        person per;
        string extract;//to check if file is empty
        int choice;
          ifstream file("pin.txt");
        if (file.is_open()) 
    {
        getline(file, extract);  // read first line from file into a
        file.close();
    }
    
        if (extract.empty()) 
        {
        pass.check();
        }
        else{
            pass.newcheck();
        }
        do
        {
            cout<<"\t1.Data"<<endl;
            cout<<"\t2.Display history"<<endl;
            cout<<"\t3.Personal goals"<<endl;
            cout<<"\t4.change password"<<endl;
            cout<<"\t5.exit"<<endl;
            cin>>choice;
            switch(choice)
            {
                case 1:
                int achoice;
                cout<<"\t1.Enter data"<<endl;
                cout<<"\t2.Show data"<<endl;
                 cin>>achoice;
                switch (achoice)
                {
                case 1:
                     per.inputpersondata();
                    break;
                
                    case 2:
                    break;

                default:
                    cout<<"incorrect option"<<endl;   
                  }
                break;

                case 2:
                break;

                case 3:
                int gchoice;
                cout<<"\t1.Show goal"<<endl;
                cout<<"\t2.Change goal"<<endl;
                 cin>>gchoice;
                switch (gchoice)
                {
                case 1:
                    break;
                case 2:
                break;

                default:
                 cout<<"incorrect option"<<endl;
                
                }
                break;
                
                case 4:
                pass.authentication();
                break; 

                case 5:
                cout<<"exiting the program.......";
                exit(0);

                default:
                cout<<"incorrect option"<<endl;

            }
        } while (choice!=5);
    }
