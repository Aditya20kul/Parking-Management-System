#include<iostream>
#include<process.h>
#include<cstdlib>
#include <ctime>
#include<string.h>
#include<fstream>
#include<cstring>
using namespace std;
class parking
{
   int k,i,j,cnt,cnt3,s,m,type;
   char np[51][12],type1[5],pass[10],numb1[12],name_arr[51][25],no[12],name[12],numb[12],numb2[12],st[51][2],name1[25];
public:
//#####################################################################################################################
new_cust()
{
      fstream tstfile1("tstfile1.txt", ios::in | ios::out | ios::app);
      if(!tstfile1.is_open())
         {
            cout<<"ERROR IN OPENING FILE";

         }
      else
      {
   opt: cout<<"\n\tEnter the type of vechicle:-\n\n\t1. Bike\n\t2. Bus\n\t3. Car\n\n\t";
    cin>>type;
    switch(type)
    {
      case 1:
         strcpy(type1,"Bike");
         cout<<"\n\tType of vehicle entered is Bike\n";
         break;
      case 2:
         strcpy(type1,"Bus");
          cout<<"\n\tType of vehicle entered is Bus\n";
         break;
      case 3:
         strcpy(type1,"Car");
         cout<<"\n\tType of vehicle entered is Car\n";
        break;
      default:
         cout<<"\tPlease enter valid option\n";
         goto opt;
    }
    fflush(stdin);
    cout<<"\n\tEnter the name of customer\n\t";
    gets(name);
    cout<<"\n\tEnter the complete vechicle number without giving spaces and make sure that you type everything in lowercase:- \n\t";
    cin>>no;
    //BELOW LINES CONTAINS LOGIC FOR STORING DATA IN FILE
    s=allot_loc();
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    tstfile1<<"\n\n*****************************************************************************************************************************\n";
    tstfile1<<"\nNEW USER REGISTERED:- \n";
    tstfile1 << "\t\t\t\t\t\t\t\t\t\t\tDate     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
    tstfile1 << "\t\t\t\t\t\t\t\t\t\t\tTime     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
    tstfile1<<"Type of vechicle:-- "<<type1<<"\n"<<"Name of customer:-- "<<name<<"\n";
    //testfile1
    tstfile1<<"Number of vehicle:-- "<<no<<"\n";
    tstfile1<<"POSITION NUMBER "<<s<<" HAS BEEN ALLOTED TO THIS CUSTOMER";
    tstfile1<<"\n********************************************************************************************************************************\n\n";
    tstfile1.close();
    cout<<"\n\t***POSITION "<<s<<" SUCESSFULLY ALLOTED***\n\n";
     show_menu();
      }
}
int allot_loc()
   {
      int q,o;
          if(cnt!=50)
            {
               for(o=1;o<=50;o++)
               {
                  q=strcmp(np[o],"0");

                  if(q==0)
                  {
                     strcpy(np[o],no);
                     strcpy(st[o],"1");
                     strcpy(name_arr[o],name);
                     cnt++;
                     return o;
                     break;
                  }
               }
            }
         else
            {
               cout<<"\n\tSORRY, OUR PARKING LOT IS FULL\n\t";
            }
      show_menu();
   }
   //###################################################################################################################

   remove_veh()
   {
      int f;
      fstream tstfile1("tstfile1.txt", ios::in | ios::out | ios::app);
   if(!tstfile1.is_open())
   {
      cout<<"ERROR IN OPENING FILE";

   }
   else
   {
      if(cnt==0)
   {
      cout<<"\n\tOOPS,PARKING LOT IS EMPTY\n";
   }
   else
      {
      cout<<"\n\tPLEASE ENTER THE NUMBER PLATE OF THE CAR WHICH U WANT TO REMOVE FROM THE PARKING LOT:--\n\t";
      cin>>numb1;
      f=find_veh_for_removal();
      if(f==0)
         {
       cout<<"\n\tNO VEHICLE OF THE ABOVE ENTERED NUMBER IS PARKED IN THE PARKING LOT\n";
         }
      else
      {
         strcpy(np[f],"0");
         strcpy(st[f],"0");
      cout<<"\n\tVechicle sucessfully deleted from the parking lot database\n\n\t";
      //BELOW LINES CONTAINS LOGIC FOR STORING DATA IN FILE
      time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    tstfile1<<"\n\n********************************************************************************************************************************\n";
    tstfile1<<"!! VEHICLE REMOVED !! \n";
    tstfile1 << "\t\t\t\t\t\t\t\t\t\t\tDate     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
    tstfile1 << "\t\t\t\t\t\t\t\t\t\t\tTime     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
    tstfile1<<"Number of vehicle:-- "<<numb1<<"\n";
    tstfile1<<"POSITION NUMBER "<<f<<" HAS BEEN VACATED\n";
    tstfile1<<"\n**********************************************************************************************************************************\n\n\n";
    }
    tstfile1.close();

   }
   }
   show_menu();
   }
   //####################################################################################################################

   int find_veh_for_removal()//THIS FUNCTION IS CALLED IN THE FUNCTION NAMED "REMOVE VEHICLE"
   {
      strcpy(numb2,numb1);
      int q=0,c;
      for(k=1;k<=50;k++)
      {
         c=strcmp(np[k],numb2);
         if(c==0)
         {
           return k;
           break;
         }
         else
         {
            q++;
         }

      }
      if(q==50)
      {
         return 0;
      }
   }

   //##########################################################################################

   find_veh_by_num()
   {
      int l=0,var;
      if(cnt==0)
      {
         cout<<"\n\tOOPS, PARKING LOT IS EMPTY\n";
      }
      else
      {
            cout<<"\n\tEnter the valid number\n\t";
              cin>>numb;
      for(k=1;k<=50;k++)
      {
         var=strcmp(np[k],numb);
         if(var==0)
         {
            cout<<"\n\tTHE VECHICLE WITH THE ABOVE ENTERED NUMBER IS PARKED AT POSITION NO. "<<k<<"\n\n\t";
            break;
         }
         else
           {
            l++;
           }

      }
      if(l==50)
      {
         cout<<"\tINVALID NUMBER\n";
      }
      }
       show_menu();
   }

   //##########################################################################################


    disp_status()
   {
      int cnt3=0,var1;
     cout<<"\n\tTHE STATUS OF THE PARKING LOT IS AS FOLLOWS:--\n\n";
     cout<<"\n\tMatrix grid view of number plates:--\n\n";
     for(j=1;j<=50;j++)
     {
      cout<<"\t"<<st[j]<<"\t";
      if(j%5==0)
      {
         cout<<"\n\n";
      }
      var1=strcmp(np[j],"0");
      if(var1==0)
      {
         cnt3++;
      }
     }
     cout<<"\n\n\tTOTAL "<<cnt3<<" PLACES ARE EMPTY\n\n\t";
     show_menu();
   }

   //##########################################################################################
   find_veh_by_name()
   {
      int op,cnnt=0;
      if(cnt==0)
      {
          cout<<"\n\tOOPS, PARKING LOT IS EMPTY\n";
      }
      else
      {
            cout<<"\n\tEnter the name of customer\n\t";
      cin>>name1;
      for(i=1;i<=50;i++)
      {
         op=strcmp(name_arr[i],name1);
         if(op==0)
         {
            cout<<"\n\tThe vehicle associated with the above entered name is parked at position no. "<<i<<"\n";
            break;
         }
         else
         {
            cnnt++;
         }
      }
      if(cnnt==50)
      {
            cout<<"\n\tNo vehicle found !\n";
      }
      }
      show_menu();

   }
   //##########################################################################################
   warning()
   {
      char passin[10];
      int dec;
     cout<<"\n\tPLEASE ENTER THE CORRECT PASSWORD FOR QUITING THE PROGRAM--\n\t";
     cin>>passin;
      dec=strcmp(passin,pass);
      if(dec==0)
      {
         exit(0);
      }
      else
      {
         cout<<"\n\tINCORRECT PASSWORD !!\n";
         show_menu();
      }
   }

//#############################################################################################
   void show_menu()
   {

      int choice;
      again:
         cout<<"\n\t*****************************************************************************\n";
          cout<<"\n\t# Enter your choice :--\n\n\n";
      cout<<"\t1. Register the new vechicle\n\n\t2. Delete the entry of vechicle\n\n\t3. Find the vechicle by entering its number\n\n\t"
     <<"4. Display the status of parking lot\n\n\t5. Find vehicle by name of owner\n\n\t6. Exit the  program\n\n\t";
      cin>>choice;
      cout<<"\n\t*****************************************************************************\n\t";
      if(choice==1)
         new_cust();

      if(choice==2)
        remove_veh();

      if(choice==3)
       find_veh_by_num();

      if(choice==4)
        disp_status();
      if(choice==5)
         find_veh_by_name();
      if(choice==6)
         warning();
         //exit(1);
      if(choice>6||choice<1)
      {
         cout<<"\nPlease provide valid input\n\t";
         goto again;
      }
  }
  init()
  {
         for(i=1;i<=50;i++)
         {
            strcpy(np[i],"0");
            strcpy(name_arr[i],"0");
            strcpy(st[i],"0");
            strcpy(pass,"aditya20");
            cnt=0;
            cnt3=0;
         }
  }
  display_time_date()
{
   time_t t = time(NULL);
  tm* timePtr = localtime(&t);
  cout << "\t\t\t\t\t\t\t\t\t\t\tDate     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\tTime     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;

}
};
//#############################################################################################################
int main()
{
   parking a1;
   a1.init();
   cout<<"\n\n\t\t****************************************************************************************\n";
   cout<<"\n\t\t\t\t\t WELCOME TO PARKING MANAGEMENT SYSTEM \n\n";
   cout<<"\t\t****************************************************************************************\n\n\n";
    //a1.display_time_date();
   a1.show_menu();
}
