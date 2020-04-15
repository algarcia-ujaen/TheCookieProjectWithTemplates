#ifndef RECIPECOMPONENT_H
#define RECIPECOMPONENT_H

#include <string>

class RecipeComponent
{
   private:
      std::string _modifier = "";
  
   public:
      RecipeComponent ( ) = default;
      RecipeComponent ( const std::string& m );
      RecipeComponent ( const RecipeComponent& orig );
      virtual ~RecipeComponent ( );
      RecipeComponent& setModifier ( std::string modifier );
      std::string getModifier ( ) const ;
      std::string toText ();
      
      RecipeComponent& operator= ( const RecipeComponent& other );
      bool operator== ( const RecipeComponent& other );
      bool operator!= ( const RecipeComponent& other );
} ;

#endif /* RECIPECOMPONENT_H */

