#include "ai.h"
#include "../sdl2_utility/utility.h"

void initializeEntity(Entity *entities){
    entities->entity.rect.x = 0;
    entities->entity.rect.y = 0;
    entities->entity.rect.w = 50;
    entities->entity.rect.h = 50;

    entities->entity.direction.x = 0;
    entities->entity.direction.y = 0;

    entities->alive = 0;
    
}

void eat(Player *player, Entity *entities, int index, int *game_over){
    if(entities->alive == 0){
        if(collision(&player->rect,&entities->entity.rect) == 1){
            if(index == 0) entities->alive = 1;
            else *game_over = 1;
        }
    }
}

void aiMovement(Entity *entity, SDL_Point *destination){
    SDL_Point position;

    position.x = entity->entity.rect.x/50;
    position.y = entity->entity.rect.y/50;

    entity->entity.direction.x = 0;
    entity->entity.direction.y = 0;

    if(pathFinding(&entity->entity,*destination) == 0){
        destination->x = random(0,1000000)%(WIDTH-50);
        destination->y = random(0,1000000)%(HEIGHT-50);

        destination->x = destination->x - (destination->x%50);
        destination->y = destination->y - (destination->y%50);
    }

    movement(&entity->entity);

}