bool add_account(struct DtwResource *database,CliEntry *entry){
    char *name=get_interface_name(entry);
    if(!name){
        return true;
    }

    char *possible_id=find_account_id_by_name(database,name);
    if(possible_id){
        printf("Account '%s' already exists\n",name);
        free(possible_id);
        return true;
    }
    create_account(database,name);
    printf("Account '%s' added",name);

    return false;
}