#ifndef SONGDATABASE_H
#define SOUNGDATABASE_H

#include "Song.h"
#include <string>


 class songDatabase{
   private:
     Song** data;
     int length;
     int capacity;
      void resize();
       int songIndexbytitle(const string& title)const;
  public:
    songDatabase();
     songDatabase(int initcap);
       songDatabase(const songDatabase& other);
        songDatabase& operator=(const songDatabase& other);
           ~songDatabase();
      void addSong(Song* song);
   bool removeFromtitle(const string& title);
     bool editBytitle(const string& title);
      void listAll()const;
        void listByartist(const string& artist)const;
        void listFromalbum(const string&album)const;
         void listByyear(int year)const;
      void listBygenre(Genre genre)const;
       void search(const string& searchKey )const;
    bool saveTofile(const string& filename)const;
     bool loadFromfile(const string& filename);
       int getSize()const;
        bool isEmpty()const;
        template< typename Condition>
         void advancedSongs(Condition con) const{
           bool found = false;

              for(int i=0; i< length ; i++){
                if(con(*data[i])){
                  data[i]->print();
                   cout<<"**********************************\n";
                   found = true;
                }
              }
              if(!found){
                cout<<"no songs found\n"; 
              }
         }
 };
#endif
