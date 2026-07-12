#include "SongDatabase.h"
#include "Helper.h"
#include "PolySong.h"
#include <exception>
#include <iostream>
#include <limits>


   using namespace std;

int main() {
    songDatabase s;
      while(true){
        cout << "\n******MAIN MENU******\n";
        cout << "1) List\n2) Add\n3) Edit\n4) Remove\n5) Save\n6) Load\n";
        cout << "Enter your selection number: ";
           
           int choice;
           cin>>choice;
               if(!cin){
                cin.clear();
                 cin.ignore(1000, '\n');
                 continue;
               }
               if(choice==-9){
                cout<<"This is the base menu(there is no going back)\n";
                continue;
               }

               try{

                switch (choice) {
             case -1:{
               cout<< "exiting the program...\n";
             return 0;
             }
             case 1: 
                    s.listAll();
                    break;
             case 2:{
                cout<<"How your next Song want to be?\n"<<
                "1) Normal song\n"<<"2) PolySong\n"<<
                "please choose: ";
                 int type=get_int_input();
                
                    cout << "Enter title: ";
                string new_title = get_string_input();

                cout<<"Enter artist: ";
                string new_artist = get_string_input();

                cout << "Enter album: ";
                string new_album = get_string_input();

                cout << "Enter year: ";
                int new_year = get_int_input();

                cout << "Enter duration: ";
                string new_duration = get_string_input();
                 
                cout << "enter Genre:\n"
                   <<"1) CLASSIC\n2) ROCK\n3) POP\n4) RAP\n5) JAZZ\n6) TECHNO\n";
                
                int ng=get_int_input();
                ng-=1;

                if(ng<0 || ng>5){
                 cout<<"invalid entery";
                 break;
                }
                if(type==1){

                
             Song* newsong=new Song(new_title,new_artist,new_album,new_year,new_duration,static_cast<Genre>(ng));   
             s.addSong(newsong);
                
                cout<<"added successfully";
                }
                else if(type==2){
                   cout<<"WELCOME\n"<<"ENTER ID: ";
                   string temp_id=get_string_input();

                   Song* newSong= new PolySong(new_title,new_album,
                    new_artist,new_year,new_duration,
                    static_cast<Genre>(ng),temp_id);

                    s.addSong(newSong);
                }
                else{
                    cout<<"INVALID ENTERY SORRY...\n";
                     break;
                }
                 cout<<"ADDED SUCCESSFULLY\n"<<"CONGRAGULATIONS!\n";
                 break;
            }
            case 3:{
                cout<< "enter the title: ";
                 string temp=get_string_input();
                   if(!s.editBytitle(temp)){
                      cout<<"invalid entery\n";
                      cout<<temp<<"not found!\n";
                   }
                   break;
             }
            case 4:{
                cout << "enter title: ";
                string temp=get_string_input();
                  
                     if(!s.removeFromtitle(temp)){
                        cout<<temp<<" NOT FOUND\n";
                     }else{
                        cout<<"Removed\n";
                     }
                        break;
            } 
            case 5:
                       if (s.saveTofile("songs.txt")){
                    cout << "Saved successfully\n";
                    } else{
                    cout << "Error saving file\n";
            }
                    break;

            case 6 :
                if(s.loadFromfile("SONGS.txt")){
                        cout<<"loaded successfully"<<endl;
                     }else{
                        cout<<"error loading from file\n";
                     }
                     break;

                    default:
                    cout<<"invalid option\n";
                    }
                }
                catch (BacktoMenuException&){
                    cout << "back to main menu...";
                }
                catch(exception& s){
                    cout<< s.what()<< endl;
                }
      }
    
    }
