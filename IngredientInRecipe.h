#ifndef INGREDIENTINRECIPE_H
#define INGREDIENTINRECIPE_H

#include "Ingredient.h"
#include "RecipeComponent.h"

class IngredientInRecipe: public RecipeComponent
{
   private:
      Ingredient* _ingredient = nullptr;
      float _amount = 0;
   public:
      IngredientInRecipe ( ) = default;
      IngredientInRecipe ( Ingredient& i, float am, std::string modifier );
      IngredientInRecipe ( const IngredientInRecipe& orig );
      virtual ~IngredientInRecipe ( );
      IngredientInRecipe& setAmount ( float a );
      IngredientInRecipe& setIngredient ( Ingredient& i );
      float getAmount () const;
      Ingredient* getIngredient ();
      virtual std::string toText () override;
      
      IngredientInRecipe& operator= ( const IngredientInRecipe& other );
      bool operator== ( const IngredientInRecipe& other );
      bool operator!= ( const IngredientInRecipe& other );
      
      virtual RecipeComponent* copyMe () override;
} ;

#endif /* INGREDIENTINRECIPE_H */

