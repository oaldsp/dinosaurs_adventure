#pragma once

#include "Ente.h"
#include "Entity.h"
#include "Player.h"
#include "Projectile.h"
#include "Meteor.h"
#include "Petroleum.h"
#include "Ground.h"
#include "Chick.h"
#include "Chicken.h"
#include "Rooster.h"
#include "EntityList.h"
#include "CollisionManager.h"
#include "GraphicsManager.h"
#include "EventsManager.h"
#include "StateMachine.h"
#include "State.h"

#include <fstream>
#include <string>
#include <iostream>

class Level: public Ente, public State
    {
    protected:

        List::EntityList list_o;
        List::EntityList list_c;
        
        Managers::CollisionManager collision_manager;
        EventsManager* events_manager;
        
        sf::RectangleShape body;
    public:
        Level(stateID id);
        ~Level();
        void draw();

        void add_enemy(Entities::Entity* enemy);
        void add_obstacle(Entities::Entity* obstacle);
        void add_player(Entities::Entity* player);

        void create_enemy();
        void create_scenario();
    };