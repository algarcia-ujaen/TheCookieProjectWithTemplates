#ifndef ACTIONINRECIPE_H
#define ACTIONINRECIPE_H

#include "RecipeComponent.h"


class ActionInRecipe: public RecipeComponent
{
   private:
      std::string _description = "";
   public:
      ActionInRecipe ( ) = default;
      ActionInRecipe ( std::string description, std::string modifier );
      ActionInRecipe ( const ActionInRecipe& orig );
      virtual ~ActionInRecipe ( );
      ActionInRecipe& setDescription ( std::string description );
      std::string getDescription ( ) const ;
      virtual std::string toText () override;
      
      ActionInRecipe& operator= ( const ActionInRecipe& other );
      bool operator== ( const ActionInRecipe& other );
      bool operator!= ( const ActionInRecipe& other );
} ;

#endif /* ACTIONINRECIPE_H */

