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
        float nextPos = 8000/(rand()%10 + 5);
        int numE = rand()%4 + 6;

        for(int i=0;i<numE;i++){
            aux = new Entities::Creature::Chick(CoordF((i*nextPos) + 371.0f + rand()%10, 300.f));
            add_enemy(static_cast<Entities::Entity*>(aux));
        }
    }

    void Level::create_scenario()
    {
        Entities::Entity* aux = nullptr;
        std::srand(std::time(NULL)); //aleatorio

        int numO = 13;
        float nPos = 0.0;
       
       //chao	
        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Ground(CoordF((i*600)+0.0f,600.0f), CoordF(600.0f,168.0f));
            add_obstacle(static_cast<Entities::Entity*>(aux));
        }
        
        numO= rand()%2 + 7;
        nPos= 8000/(rand()%5 + 4);
        
        /*while(numO<5 || nPos<5.0){
            numO = rand()%7;
            nPos = rand()%10;
        }
        
        nPos = 8000/nPos;*/
        
	//parede
        for(int i=0;i<numO;i++){
            aux = new Entities::Obstacles::Ground(CoordF((i*nPos) + rand()%10, 195.0f), CoordF(50.0f,400.0f));
            add_obstacle(static_cast<Entities::Entity*>(aux));
        }
	
	//Para não cair no final do mapa
	aux = new Entities::Obstacles::Ground(CoordF(7740.0f + rand()%10, 195.0f), CoordF(50.0f,400.0f));
        add_obstacle(static_cast<Entities::Entity*>(aux));

    }
