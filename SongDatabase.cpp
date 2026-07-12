#include "SongDatabase.h"
#include "Helper.h"
#include "PolySong.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

  songDatabase::songDatabase()
: data(0), length(0), capacity(10)
{
    data = new Song*[capacity];
}
 songDatabase::songDatabase(int innitcap)
   :data(0),length(0),capacity(innitcap>0 ? innitcap: 10)
   {
     data=new Song*[capacity];
   }
   songDatabase::songDatabase(const songDatabase& other)
   : data(0),length(other.length),capacity(other.capacity)
   {
    data=new Song*[capacity];

       for(int i=0;i<length; i++){
        data[i]=other.data[i];
       }
   }
   songDatabase& songDatabase::operator=(const songDatabase& other){
     if(this!=&other){
        Song* pNew=new Song[other.capacity];
          
             for (int i=0;i<other.length;i++){
                pNew[i]=*other.data[i];
             }
        delete [] data;
        *data=pNew;
        length=other.length;
        capacity=other.capacity;
     }
     return *this;
   }
   songDatabase::~songDatabase(){
      for(int i=0; i<length; i++){
         delete data[i];
      }
      delete[] data;
   }
   void songDatabase::resize(){
      capacity*=2;
          Song** pNew=new Song*[capacity];

             for (int i=0;i < length ;i++){

                    pNew[i]= data[i];
             }

               delete [] data;
                data = pNew;
   }
   int songDatabase::songIndexbytitle(const string& title)const{
         
                  for (int i=0;i < length ;i++){
                       if(data[i]->getTitle()==title){
                           
                               return i;
                       }
                  }
                  return -1;
   }
   void songDatabase::addSong(Song* song){
         
            if(length+1 >= capacity){
                resize();
            }
            data[length]=song;
            ++length;
    }
   bool songDatabase::removeFromtitle(const string& title){
         
          int num=songIndexbytitle(title);
             
              if(num==-1){
               return false;
              }

              for(int i=num;i<length-1;i++){
                     data[i]=data[i+1];
              }
              --length;
               return true;
          
   }

  bool songDatabase::editBytitle(const string& title) {
      int num=songIndexbytitle(title);
         
            if(num==-1){
               return false;
            }

           try{
            cout<<"1)edit title\n"<<"2)edit artist\n"<<"3)edit album\n"
            <<"4)edit year\n"<<"5)edit duration\n"<<"6)edit genre\n"
            <<"please choose(1->6):";
             int choose=get_int_input();
            
            string text;
            int yngc=0;
            switch(choose){
               case 1:
                cout<<"enter new title:";
                 text=get_string_input();
                  data[num]->makeTitle(text);
                  return true;
               case 2:
                cout<<"enter new artist: ";
                  text=get_string_input();
                 data[num]->makeArtist(text);
                  return true;
               case 3:
                cout<<"enter new album: ";
                 text=get_string_input();
                data[num]->makeAlbum(text);
                return true;
               case 4:
                cout<<"enter new year: ";
                  yngc=get_int_input();
                    data[num]->makeYear(yngc);
                    return true;
               case 5:
               cout<<"enter new duration: ";
                text=get_string_input();
                  data[num]->makeDuration(text);
                  return true;
               case 6:
                cout<<"enter new genre:\n1)for CLASSIC\n2)for ROCK\n,3)for POP\n,4)for RAP\n,5)for JAZZ\n,6)for TECHNO\nplease choose:";
                     yngc=get_int_input();
                      yngc=yngc-1;
                    if(yngc>=0&&yngc<=5){
                     data[num]->makeGenre(static_cast<Genre>(yngc));
                      return true;
                    }
                    return false;
               default:
                 return false;
            }
      }
        catch(BacktoMenuException&){
           cout<<"backing to last menu....\n";
            return false;
        }
        catch(exception& e){
         cout<< e.what()<< endl;
          return false;
        }
  }
      bool songDatabase:: isEmpty() const{
         return length ==0;
      }
      int songDatabase:: getSize() const{
          return length;
      }

  void songDatabase::listAll() const{
     if(isEmpty()){
      cout<<"there is no song in memory!\n";
       return;
     }
       for(int i=0;i<length;i++){
         cout<<i+1<<")\n";
         data[i]->print();
          cout<<"~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n";
       }
  }
  void songDatabase::listByartist(const string& artistname)const{
       advancedSongs([&](const Song& s){
         return s.getArtist()==artistname;
       });
       }

  void songDatabase::listFromalbum(const string& albumname) const{
     bool flag=false;
      for(int i=0;i<length;i++){
         if(data[i]->getAlbum()==albumname){
            data[i]->print();
             cout<<"~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n";
             flag=true;
         }
      }
    
    if(!flag){
      cout<<"no "<<albumname<<"found!\nsorry\n";
    }

  }
  void songDatabase::listByyear(int year) const{
        advancedSongs([&](const Song& s){
         return s.getYear()== year;
        });

  }

  void songDatabase::listBygenre(Genre genre) const{
   {
      bool founded=false;
        for(int i=0; i< length;i++){
         if (data[i]->getGenre()==genre){
            data[i]->print();
            cout<<"~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n";
            founded=true;
         }
        }
        if(!founded){
         cout<<"no such a song exists with this genre"<<endl;
        }
   }
}
  void songDatabase::search(const string& searchKey) const{
     
        advancedSongs([&](const Song& s){
         return s.getArtist()==searchKey || s.getAlbum()== searchKey;
        });

  }

   bool songDatabase::saveTofile(const string& filename)const{
       std::ofstream file(filename.c_str());
       if(!file){
         return false;
       }
       for(int i=0;i<length;i++){
         PolySong* poly=dynamic_cast<PolySong*>(data[i]);

         file << data[i]->getTitle()  <<';'
              << data[i]->getArtist() <<';'
              << data[i]->getAlbum()<<';'
              << data[i]->getYear()<< ';'
              << data[i]->getDuration()<<';'
              << Song::genreBystring(data[i]->getGenre())<<'\n';

              if(poly){
               file << ';' << poly->getID();
              }
          file<<'\n';
       }
       return true;
   }
  bool songDatabase::loadFromfile(const string& filename){
    std::ifstream file(filename.c_str());
    
       if(!file){
         return false;
       }
       length=0;
       string line;
          while(std::getline(file, line)){
            if(line.empty()){
               continue;
            }
          stringstream ss(line);
          string title;
          string artist;
          string album;
          string texted_year;
          string duration;
          string texted_Genre;
          string texted_ID;

       if (!getline(ss, title, ';')) continue;
        if (!getline(ss, artist, ';')) continue;
        if (!getline(ss, album, ';')) continue;
        if (!getline(ss, texted_year, ';')) continue;
        if (!getline(ss, duration, ';')) continue;
        if (!getline(ss, texted_Genre)) continue;
               getline(ss,texted_ID);
          
            Genre genre;
             if(!Song::stringBygenre(texted_Genre,genre)){
               genre= POP;
             }
             int year=0;
              stringstream yearstream(texted_year);
              yearstream >> year;
                
                 if(!texted_ID.empty()){
                  Song* song=new PolySong(title,artist,album,year,duration,genre,texted_ID);
                 }
                 else{
                 Song* song= new Song(title, artist, album , year , duration, genre);
                  addSong(song);
                 }
            
          }
          return true;
  }
  