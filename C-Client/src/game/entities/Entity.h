//
// Created by José Acuña on 18/09/2019.
//

#ifndef C_CLIENT_ENTITY_H
#define C_CLIENT_ENTITY_H

#include <stdlib.h>
#include "../../util/var.h"
#include <allegro5/allegro.h>
#include "../../lib/json.h"
#include "../../lib/json-builder.h"

typedef struct {
    int id;
    float x;
    float y;
    float rx;
    float ry;
    ALLEGRO_BITMAP *bitmap;
} Entity;

void drawBitmap(Entity *entity);

int collide(Entity);

void kill();

void updateRPoss(Entity *entity);

char *serialize(Entity *);

void parse(char *, Entity *);

#endif //C_CLIENT_ENTITY_H
