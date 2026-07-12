#include "Song.h"
Song::Song()
  :title("not specified"), artist("Unknown"), album("not specified"), year(0), duration("00:00"), genre(POP)
  {}
  Song::Song(const string& title , const string& artist ,
      const string& album, int year, 
      const string& duration, Genre genre)
      :title("not specified"), artist("Unknown"), album("not specified"), year(0), duration("00:00"), genre(POP)
        {
            makeTitle(title);
            makeArtist(artist);
            makeAlbum(album);
            makeYear(year);
            makeDuration(duration);
            makeGenre(genre);
        }
     bool Song::Validyear(int year) const{
       return year>=0 && year<=2027;

        }
      void Song::makeTitle(const string& title){
        if(!title.empty()){
            this->title=title;
        }
      }
      void Song::makeArtist(const string& artist){
        if(!artist.empty()){
            this->artist=artist;
        }
      }
      void Song::makeAlbum(const string& album){
        if(!album.empty()){
            this->album=album;
        }
      }

      void Song::makeYear(int year){
        if(Validyear(year)){
            this->year=year;
        }
      }
      void Song::makeDuration(const string& duration){
         if(!duration.empty()){
            this->duration=duration;
         }
      }
     void Song::makeGenre(Genre genre){
        if (genre>=CLASSIC && genre<=TECHNO){
            this->genre=genre;
        }
     }
   const string& Song::getTitle() const{
      return title;
   }
   const string& Song::getArtist() const{
      return artist;
   }
   const string& Song::getAlbum() const{
    return album;
   }
   int Song::getYear() const{
     return year;
   }
   const string& Song::getDuration() const{
         return duration;
   }
   Genre Song::getGenre() const{
      return genre;
   }
  void Song::print(ostream& os) const{
    os<<"title:"<<title<<"\n"<<"artist:"<<artist<<"\n"<<"album:"<<album<<"\n"<<"year:"<<year<<"\n"<<"duration:"<<duration<<"\n"<<"genre:"<<genreBystring(genre)<<"\n"<<endl;
  } 
  string Song::genreBystring(Genre genre){
    switch(genre){
      case CLASSIC:
             return  "CLASSIC";
      case ROCK:
             return "ROCK";
      case POP:
            return  "POP";
      case RAP:
            return "RAP";
      case JAZZ:
             return "JAZZ";
      case TECHNO:
            return "TEHCNO";
      default :
         return "POP";
    }
  }
  bool Song::stringBygenre(const string& text,Genre& outgen){
      if(text=="CLASSIC"){
        outgen = CLASSIC;
        return true;
      }
      if (text=="ROCK")
      {
        outgen= ROCK;
        return true;
      }
      if(text=="POP"){
        outgen=POP;
        return true;
      }
      if(text=="RAP"){
        outgen=RAP;
         return true;
      }
      if(text=="JAZZ"){
        outgen=JAZZ;
          return true;
      }
      if(text=="TECHNO"){
        outgen=TECHNO;
          return true;
      }
   return false;
}