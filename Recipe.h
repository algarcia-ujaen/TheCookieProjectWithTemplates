
#ifndef RECIPE_H
#define RECIPE_H

#include "RecipeComponent.h"
#include "Ingredient.h"
#include "myVector.h"

#define MAX_COMPONENTS 10

class Recipe
{  private:
      MyVector<RecipeComponent> _components;   ///< Pointers to ingredients
   public:
      Recipe ( ) = default;
      Recipe ( const Recipe& orig );
      virtual ~Recipe ( );
      Recipe& addIngredient ( Ingredient& ing, float amount, std::string modifier );
      Recipe& addAction ( std::string description, std::string modifier );
      bool operator== ( const Recipe& other );
      Recipe& operator= ( const Recipe& other );
      std::string getAsText ();
};

#endif /* RECIPE_H */

