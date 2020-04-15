/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   myVector.h
 * Author: algarcia
 *
 * Created on 2 de abril de 2020, 12:07
 */

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdexcept>


#define MAX_DATA 10

template<typename T>
class MyVector
{
   private:
      T* myData[MAX_DATA];
      int nData = 0;
   public:
      MyVector();
      MyVector ( const MyVector& orig );
      virtual ~MyVector ();
      MyVector& addElement ( T& el );
      bool operator== ( const MyVector& other );
      MyVector& operator= ( const MyVector& other );
      T& getElement ( int which );
      T& operator[] ( int which );
      int getNData () const;
};

template<typename T>
MyVector<T>::MyVector ()
{
   for ( int i = 0; i < MAX_DATA; i++ )
   {
      myData[i] = nullptr;
   }
}

template<typename T>
MyVector<T>::MyVector ( const MyVector& orig ): nData ( orig.nData )
{
   for ( int i = 0; i < nData; i++ )
   {
      myData[i] = new T ( *orig.myData[i] );
   }

   for ( int i = nData; i < MAX_DATA; i++ )
   {
      myData[i] = nullptr;
   }
}

template<typename T>
MyVector<T>::~MyVector ()
{
   for ( int i = 0; i < nData; i++ )
   {
      delete myData[i];
      myData[i] = nullptr;
   }
}

template<typename T>
MyVector<T>& MyVector<T>::addElement (T& el)
{
   if ( nData >= MAX_DATA )
   {
      throw std::length_error ( "[MyVector::addElement]: no room" );
   }

   myData[nData] = new T ( el );
   nData++;
   
   return *this;
}

template<typename T>
bool MyVector<T>::operator== ( const MyVector& other )
{
   bool toRet = true;
   
   if ( nData != other.nData )
   {
      toRet = false;
   }
   else
   {
      for ( int i = 0; i < nData; i++ )
      {
         if ( *myData[i] != *other.myData[i] )
         {
            toRet = false;
         }
      }
   }

   return toRet;   
}

template<typename T>
MyVector<T>& MyVector<T>::operator= ( const MyVector& other )
{
   if ( this != &other )
   {
      for ( int i = 0; i < nData; i++ )
      {
         delete myData[i];
         myData[i] = nullptr;
      }
   
      nData = other.nData;
      for ( int i = 0; i < other.nData; i++ )
      {
         myData[i] = new T ( *other.myData[i] );
      }
   }

   return *this;
}

template<typename T>
T& MyVector<T>::getElement ( int which )
{
   if ( ( 0 > which ) || ( which >= nData ) )
   {
      throw std::invalid_argument ( "wrong position!" );
   }

   return *myData[which];
}

template<typename T>
T& MyVector<T>::operator [] ( int which )
{
   if ( ( 0 > which ) || ( which >= nData ) )
   {
      throw std::invalid_argument ( "wrong position!" );
   }

   return *myData[which];
}


template<typename T>
int MyVector<T>::getNData () const
{
   return nData;
}


#endif /* MYVECTOR_H */

