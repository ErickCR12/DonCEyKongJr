//
// Created by Jesica on 9/20/2019.
//
#include "Entities.h"

void pushEntity(Entity *entity) {
    entity->id = length;
    entities[length] = entity;
    length += 1;
}

void removeEntity(int id) {

}

json_value *serializeEntities(Junior *junior,
        Entity *donkey,
        Platform **platforms,
        Entity *key,
        Rope **ropes) {

    json_value *objEntities = json_object_new(5);

    json_object_push(objEntities, junior->entity->type, serialize(junior->entity));
    json_object_push(objEntities, donkey->type, serialize(donkey));
    json_object_push(objEntities, key->type, serialize(key));
    json_object_push(objEntities, "platforms", serializePlatforms(platforms));
    json_object_push(objEntities, "ropes", serializeRopes(ropes));

    return objEntities;
}

json_value *serializePlatforms(Platform **platforms) {
    int size = PLATFORMS_TOTAL;
    json_value *arrayPlatforms = json_array_new((size_t) size);
    for (int i = 0; i < size; i++) {
        updateRPoss(platforms[i]->entity);
        json_value *jsonEntity = serialize(platforms[i]->entity);
        json_array_push(arrayPlatforms, jsonEntity);
    }
    return arrayPlatforms;
}

json_value *serializeRopes(Rope **ropes) {
    int size = AMOUNT_OF_ROPES;
    json_value *arrayRopes = json_array_new((size_t) size);
    for (int i = 0; i < size; i++) {
        updateRPoss(ropes[i]->entity);
        json_value *jsonEntity = serialize(ropes[i]->entity);
        json_array_push(arrayRopes, jsonEntity);
    }
    return arrayRopes;
}


