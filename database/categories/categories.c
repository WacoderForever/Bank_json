

DtwResource * get_categories_resource(struct DtwResource *database){
    DtwResource *props = dtw.resource.sub_resource(database,"props");
    DtwResource *categories = dtw.resource.sub_resource(props,"categories.json");
    return categories;
}


cJSON * get_categorie_json(struct DtwResource *database){
    DtwResource *categories = get_categories_resource(database);
    char * element = dtw.resource.get_string(categories);
    return  cJSON_Parse(element);
}

char * find_categorie_id_by_name(DtwResource *database,const char *name){
    cJSON *categories = get_categorie_json(database);
    int size = cJSON_GetArraySize(categories);
    for(int i = 0; i <size; i++){
        cJSON *current = cJSON_GetArrayItem(categories,i);
    
        if(!strcmp(current->valuestring,name)){
            char *result = strdup(current->string);          
            cJSON_free(current);
            return result;
        }
    }
    return NULL;
}

void rename_categorie_by_id(DtwResource *database, const char *id, const char *new_name){
    cJSON *element = get_categorie_json(database);
    cJSON_DeleteItemFromObject(element,id);
    cJSON_AddStringToObject(element,id,new_name);
    
    add_json_to_resource_and_delete_json(
         get_categories_resource(database),
         element
    );
}

void create_categorie(DtwResource *database,const char *name){
    cJSON *element = get_categorie_json(database);
    int size = cJSON_GetArraySize(element);
    char new_id[30] = {0};
    sprintf(new_id,"id_%d",size);
    cJSON_AddStringToObject(element,new_id,name);

    add_json_to_resource_and_delete_json(
         get_categories_resource(database),
         element
    );
    
}
