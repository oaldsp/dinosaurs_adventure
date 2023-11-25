#include "Level.h"

    Level::Level(stateID id):
    Ente(CoordF(0.0f, 0.0f)),//tirar posicao da construtora da Ente pq n faz sentido por no level ?
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
        float nextPos = 0;
        int numE = 0;

        while(numE<4 && nextPos<5){
            numE = rand()%8;
            nextPos = rand()%15;
        }

        nextPos=5000/nextPos;

        for(int i=0;i<numE;i++){
            aux = new Entities::Creature::Chick(CoordF((i*nextPos)+371.0f, 300.f));
            add_enemy(static_cast<Entities::Entity*>(aux));
        }
    }

    void Level::create_scenario()
    {
        Entities::Entity* aux = nullptr;
        std::srand(std::time(NULL)); //aleatorio

        int numO = 15;
        float nPos = 0.0;
        
        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Ground(CoordF((i*600)+0.0f,600.0f), CoordF(600.0f,50.0f));
            add_obstacle(static_cast<Entities::Entity*>(aux));
        }
        
        numO=0;
        nPos=0;
        
        while(numO<5 || nPos<5.0){
            numO = rand()%7;
            nPos = rand()%10;
        }
        
        nPos = 8000/nPos;
        
        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Ground(CoordF((i*nPos)+0.0f,195.0f), CoordF(50.0f,400.0f));
            add_obstacle(static_cast<Entities::Entity*>(aux));
        }

    }