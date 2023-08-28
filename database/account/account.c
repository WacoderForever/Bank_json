DtwResource *get_account_resource(struct DtwResource *database){
    DtwResource *props=dtw.resource.sub_resource(database,"props");
    DtwResource *account=dtw.resource.sub_resource(database,"account.json");
    return account;
}


cJSON *get_account_json(struct DtwResource *database){
    cJSON *element=get_account_resource(database);
    char *content=dtw_load_string_file_content(element);
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
                cJSON_Delete(element);
                return current->string;
            }
        }
    }
    cJSON_Delete(element);
    return NULL;
}

void rename_account(struct DtwResource *database,const char *id,const char *new_name){
    cJSON *element=get_account_json(database);
    cJSON_DeleteItemFromObject(element,id);
    cJSON_AddItemToObject(element,id,new_name);

    add_json_to_resource_and_delete_json(get_account_resource(database,element));
}

void create_account(struct DtwResource *database,const char *name){
    cJSON *element=get_account_json(database);
    char *id=dtw_generate_sha_from_string(name);
    id[11]='\0';
    cJSON_AddItemToObject(element,id,name);
    add_json_to_resource_and_delete_json(get_account_resource(database),element);
}
char *find_account_id_by_name(struct DtwResource *database,const char *name){
    cJSON *element=get_account_json(database);
    int size=cJSON_GetArraySize(element);
    for(int i=0;i<size;++i){
        cJSON *current=cJSON_GetArrayItem(element,i);
        if(current){
            if(!(strcmp(current->valuestring,name))){
                cJSON_Delete(element);
                return current->string;
            }
        }
    }
    cJSON_Delete(element);
    return NULL;
}

void remove_account(struct DtwResource *database,const char *name){
    cJSON *element=get_account_json(database);
    cJSON_DeleteItemFromObject(element,name);
    add_json_to_resource_and_delete_json(get_account_resource(database),element);
}