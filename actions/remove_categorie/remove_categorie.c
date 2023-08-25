bool remove_categorie(struct DtwResource *database,const char *name){
    cJSON *element=get_categorie_json(database);
    int size=cJSON_GetArraySize(element);
    for(int i=0;i<size;i++){
        cJSON *current=cJSON_GetArrayItem(element,i);
        if(!(strcmp(current->valuestring,name))){
            cJSON_DeleteItemFromObject(current,current->string);
            return false;
        }
    }
    cJSON_free(element);
    return true;
}