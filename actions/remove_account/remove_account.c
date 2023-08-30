bool remove_account(struct DtwResource *database,CliEntry *entry){
    char *name=get_interface_name(entry);

    if(!name){
        return true;
    }
    char *id=find_account_id_by_name(database,name);
    
    if(!id){
        printf("Account '%s' does not exist\n",name);
        return true;
    }
    remove_account_by_id(database,id);
    printf("Account '%s' removed\n",name);
    return false;
}