#include "Level.h"

    Level::Level(stateID id):
    Ente(CoordF(- 300.0f, 0.0f)),//tirar posicao da construtora da Ente pq n faz sentido por no level ?
    State(id),
    list_o(),
    list_c(),
    collision_manager(&list_c,&list_o),
    body()
    {    
        events_manager = EventsManager::getInstance();
        create_enemy();
        create_scenario();
    }

    Level::~Level(){

    }

    void Level::draw()
    {
        pGM->render(&(this->body));
    }

    void Level::add_enemy(Entities::Entity* enemy)
    {
        if (enemy)
        {
            list_c.addEntity(enemy);
        }
    }

    void Level::add_obstacle(Entities::Entity *obstacle)
    {
        if (obstacle)
        {
            list_o.addEntity(obstacle);
        }
    }

    void Level::add_player(Entities::Entity *player)
    {
        if (player)
        {
            list_c.addEntity(player);
        }
    }

    void Level::create_enemy()
    {
        std::srand(std::time(NULL));

        Entities::Entity* aux = NULL;
        int nextPos = 50;
        int numE = 0;

        while(numE<3){
            numE = rand()%7;
        }
        for(int i=0;i<numE;i++){
            aux = new Entities::Creature::Chick(CoordF((i*nextPos)+100.0f, 100.f));
            add_enemy(static_cast<Entities::Entity*>(aux));
        }

        while(numE<3){
            numE = rand()%7;
        }

        for(int i=0;i<numE;i++){
            aux = new Entities::Creature::Chicken(CoordF((i*nextPos)+1100.0f, 100.f));
            add_enemy(static_cast<Entities::Entity*>(aux));
        }

        //aux = new Entities::Creature::Player(CoordF(300.f,250.f), &pp1); //criar um create_players quando parar de dar segfau
        //add_player(static_cast<Entities::Entity*>(aux));
    }

    void Level::create_scenario()
    {
        Entities::Entity* aux = nullptr;
        std::srand(std::time(NULL)); //aleatorio
        int numO = 0;
        int nextP = 60;

        while(numO<10){
            numO = rand()%20;
        }

        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Ground(CoordF((i*nextP)+0.0f,300.0f), CoordF(600.0f,50.0f));
            add_obstacle(static_cast<Entities::Entity*>(aux));
        }

        while(numO<3){
            numO = rand()%7;
        }

        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Petroleum(CoordF((i*nextP)+600.0f,300.0f), CoordF(150.0f,50.0f));
            add_obstacle(static_cast<Entities::Entity*>(aux));
        }


    }