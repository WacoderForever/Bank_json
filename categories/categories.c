


cJSON * get_categorie_json(struct DtwResource *database){
    DtwResource *props = dtw.resource.sub_resource(database,"props");
    DtwResource *categories = dtw.resource.sub_resource(props,"categories.json");
    char * element = dtw.resource.get_string(categories);
    return  cJSON_Parse(element);
}

char * find_categorie_id_by_name(DtwResource *database,const char *name){
    cJSON *categories = get_categorie_json(database);
    int size = cJSON_GetArraySize(categories);
    for(int i = 0; i <size; i++){
        cJSON *current = cJSON_GetArrayItem(categories,i);
        printf("pego uaqui %s\n",current->valuestring);
        if(!strcmp(current->valuestring,name)){

            char *result = strdup(current->valuestring);
            cJSON_free(current);
            return result;
        }
    }
    return NULL;
}
