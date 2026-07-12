#ifndef SONG_H
#define SONG_H

#include<iostream>
#include<string>
 using namespace std;
enum Genre {
    CLASSIC,
    ROCK,
    POP,
    RAP,
    JAZZ,
    TECHNO,
 };
 class Song{
   private: 
     string title;
     string artist;
      string album;
       int year;
        string duration;
         Genre genre;
       bool Validyear(int year) const;

   public:
     Song();
      Song(const string& title , const string& artist ,
      const string& album, int year, 
      const string& duration, Genre genre);
     void makeTitle(const string& title);
      void makeArtist(const string& artist);
       void makeAlbum(const string& album);
        void makeYear(int year);
      void makeDuration(const string& duration);
    void makeGenre(Genre genre);
     const string& getTitle()const;
       const string& getArtist()const;
         const string& getAlbum()const;
         int getYear()const;
       const string& getDuration()const;
      Genre getGenre() const;
       virtual void print(ostream& os=cout) const;
    static string genreBystring(Genre genre);
    static bool stringBygenre(const string& text, Genre& outgen);
    virtual ~Song(){}
 };
 #endif