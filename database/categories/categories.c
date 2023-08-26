

DtwResource * get_categories_resource(struct DtwResource *database){
    DtwResource *props = dtw.resource.sub_resource(database,"props");
    DtwResource *categories = dtw.resource.sub_resource(props,"categories.json");
    return categories;
}


cJSON * get_categorie_json(struct DtwResource *database){
    DtwResource *categories = get_categories_resource(database);
    char * element = dtw.resource.get_string(categories);
    if(element == NULL){
        return cJSON_CreateObject();
    }
    return  cJSON_Parse(element);
}

char * find_categorie_id_by_name(DtwResource *database,const char *name){
    cJSON *categories = get_categorie_json(database);
    int size = cJSON_GetArraySize(categories);
    for(int i = 0; i <size; i++){
        cJSON *current = cJSON_GetArrayItem(categories,i);
    
        if(!strcmp(current->valuestring,name)){
            char *result = strdup(current->string);          
            cJSON_Delete(categories);
            return result;
        }
    }
    cJSON_Delete(categories);
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

void remove_categorie_by_id(DtwResource *database, const char *id){
    cJSON *element = get_categorie_json(database);
    cJSON_DeleteItemFromObject(element,id);
    
    add_json_to_resource_and_delete_json(
         get_categories_resource(database),
         element
    );
}

void create_categorie(DtwResource *database,const char *name){
    cJSON *element = get_categorie_json(database);
    char *id = dtw_generate_sha_from_string(name);
    id[10] = '\0';
    cJSON_AddStringToObject(element,id,name);
    free(id);
    add_json_to_resource_and_delete_json(
         get_categories_resource(database),
         element
    );
    
}
