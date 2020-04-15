
#include <new>
#include <sstream>

#include "Recipe.h"
#include "ActionInRecipe.h"
#include "IngredientInRecipe.h"

Recipe::Recipe ( const Recipe& orig ): _components ( orig._components )
{  // We are going to solve it in a WRONG way. We will talk about this in
   // lesson 4
}


Recipe::~Recipe ( )
{ }


// Alternative version: passing a pointer as parameter
//Recipe& Recipe::operator+= ( Ingredient* ing )
//{  // Check that we have a pointer available for the new ingredient
//   if ( _nIngredients < MAX_INGREDIENTS )
//   {  _ingredients [ _nIngredients ] = ing;
//      _nIngredients++;
//   }
//
//   // Returns the reference (just in case)
//   return *this;
//}


Recipe& Recipe::addIngredient ( Ingredient& ing, float amount, std::string modifier )
{
   try
   {
      IngredientInRecipe aux ( ing, amount, modifier );
      _components.addElement ( aux );
   }
   catch ( std::length_error& e )
   {
      std::string aux = "[Recipe::addIngredient]: ";
      throw std::runtime_error ( aux + e.what () );
   }

   // Returns the reference (just in case)
   return *this;
}


Recipe& Recipe::addAction ( std::string description, std::string modifier )
{
   try
   {
      ActionInRecipe aux ( description, modifier );
      _components.addElement ( aux );
   }
   catch ( std::length_error& e )
   {
      std::string aux = "[Recipe::addAction]: ";
      throw std::runtime_error ( aux + e.what () );
   }

   // Returns the reference (just in case)
   return *this;
}


bool Recipe::operator== ( const Recipe& other )
{
   return _components == other._components;
}


Recipe& Recipe::operator= ( const Recipe& other )
{
   if ( this != &other )
   {
      _components = other._components;
   }

   return *this;
}


std::string Recipe::getAsText ( )
{
   std::stringstream aux;

   for ( int i = 0; i < _components.getNData (); i++ )
   {
      aux << _components[i].toText () << std::endl;
   }

   return aux.str ();
}
