//Arman Farhangi
//May 7, 2015
//Pong Game
//Standard C++ and SDL Libraries

#include "collider.h"

/******* COLLIDER CLASS DEFS *******/

//get x coordinate
int Collider::get_x()
{
    return hitbox.x;
}

//get y coordinate
int Collider::get_y()
{
    return hitbox.y;
}

//get width
int Collider::get_width()
{
    return hitbox.w;
}

//get height
int Collider::get_height()
{
    return hitbox.h;
}

//check to see if objects collide (using the separate axes test)
bool Collider::collided(Collider* object2)
{
    //if object one is to the right of object 2, can't collide
    if ( get_x() >= object2->get_x() + object2->get_width() )
        return false;
    
    //if object one is to the left of object 2, can't collide
    if ( get_x() <= object2->get_x() - get_width() )
        return false;
    
    //if object one is below object 2, can't collide
    if ( get_y() >= object2->get_y() + object2->get_height() )
        return false;
    
    //if object one is above object 2, can't collide
    if ( get_y() <= object2->get_y() - get_height() )
        return false;
    
    return true;
}


//check to see if object1 collided at top or bottom of object 2
bool Collider::top_or_bottom_collision(Collider* object2)
{
    //true or false variable
    bool top_bottom_collided = false;
    
    //if the objects didn't collide, then false
    if ( collided(object2) == false) return top_bottom_collided;
    
    //if part of object1 is above the top of object2
    else if ( get_y() < object2->get_y() ) top_bottom_collided = true;
    
    //if part of object1 is below bottom of object2
    else if ( get_y() + get_height() > object2->get_y() + object2->get_height() )
        top_bottom_collided = true;
    
    //return top/bottom collision tracker
    return top_bottom_collided;
}
