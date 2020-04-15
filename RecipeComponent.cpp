#include "RecipeComponent.h"

RecipeComponent::RecipeComponent ( const std::string& m ): _modifier ( m )
{ }

RecipeComponent::RecipeComponent ( const RecipeComponent& orig ): _modifier ( orig._modifier )
{ }

RecipeComponent::~RecipeComponent ( )
{ }

RecipeComponent& RecipeComponent::setModifier ( std::string modifier )
{
   this->_modifier = modifier;
   return *this;
}

std::string RecipeComponent::getModifier ( ) const
{
   return _modifier;
}

std::string RecipeComponent::toText ( )
{
   return _modifier;
}

RecipeComponent& RecipeComponent::operator = ( const RecipeComponent& other )
{
   if ( this != &other )
   {
      _modifier = other._modifier;
   }

   return *this;
}

bool RecipeComponent::operator == ( const RecipeComponent& other )
{
   bool toRet = true;

   if ( this != &other )
   {
      if ( _modifier != other._modifier )
      {
         toRet = false;
      }
   }

   return toRet;
}

bool RecipeComponent::operator != ( const RecipeComponent& other )
{
   return !operator== ( other );
}
