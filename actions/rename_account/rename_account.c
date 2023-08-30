bool rename_account(struct DtwResource *database,CliEntry *entry){
    char *name=get_interface_name(entry);
    if(!name){
        return true;
    }   
    char *id=find_account_id_by_name(database,name);
    if(!id){
        printf("Account '%s' missing\n",name);
        return true;
    }
    char *new_name=get_new_name(entry);
    if(!new_name){
        return true;
    }
    if(!(strcmp(name,new_name))){
        printf("The names are identical\n");
        return false;
    }
    int k=rename_account_name(database,id,new_name);
    if(k==0){
     printf("Account '%s' renamed to '%s'\n",name,new_name);
     return false;
    }
    printf("An account with the name '%s' already exists\n",new_name);
    return false;
}