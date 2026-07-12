#ifndef POLYSONG_H
#define POLYSONG_H
#include "Song.h"
 
class PolySong: public Song{
    private:
        string id;
    
    public: 
     PolySong(const string& temp_title,const string& temp_artist,
        const string& temp_album,int year, 
        const string& temp_duration,Genre genre,const string& id)
        : Song(temp_title,temp_artist,temp_album,year,temp_duration,genre),id(id)
        {}

        void print(ostream& os = cout) const override{
             Song::print(os);

             os<<"ID:" <<id<<endl;
        }
        const string& getID() const{
            return id;
        }
};
#endif