DtwResource *get_account_resource(struct DtwResource *database){
    DtwResource *props=dtw.resource.sub_resource(database,"props");
    DtwResource *account=dtw.resource.sub_resource(props,"account.json");
    return account;
}


cJSON *get_account_json(struct DtwResource *database){
    DtwResource *element=get_account_resource(database);
    char *content=dtw.resource.get_string(element);
    if(content==NULL){
        cJSON_CreateObject();
    }
    return cJSON_Parse(content);
}


char *find_account_id_by_name(struct DtwResource *database,const char *name){
    cJSON *element=get_account_json(database);
    int size=cJSON_GetArraySize(element);
    for(int i=0;i<size;++i){
        cJSON *current=cJSON_GetArrayItem(element,i);
        if(current){
            if(!(strcmp(current->valuestring,name))){
                char *r=strdup(current->string);
                cJSON_Delete(element);
                return r;
            }
        }
    }
    cJSON_Delete(element);
    return NULL;
}

int rename_account_name(struct DtwResource *database,const char *id,const char *new_name){
    cJSON *element=get_account_json(database);
    int size=cJSON_GetArraySize(element);
    int k=0;
    for(int i=0;i<size;i++){
        cJSON *current=cJSON_GetArrayItem(element,i);
        if(!(strcmp(new_name,current->valuestring))){
            k=1;
           break;
        }
    }
    if(k!=1){
    cJSON_DeleteItemFromObject(element,id);
    cJSON_AddStringToObject(element,id,new_name);
    

    add_json_to_resource_and_delete_json(get_account_resource(database),element);
    return k;
    }
    return k;
}

void create_account(struct DtwResource *database,const char *name){
    cJSON *element=get_account_json(database);
    char *id=dtw_generate_sha_from_string(name);
    id[10]='\0';
    cJSON_AddStringToObject(element,id,name);
    free(id);
    add_json_to_resource_and_delete_json(get_account_resource(database),element);
    
}

void remove_account_by_id(struct DtwResource *database,const char *id){
    cJSON *element=get_account_json(database);
    cJSON_DeleteItemFromObject(element,id);
    add_json_to_resource_and_delete_json(get_account_resource(database),element);
}