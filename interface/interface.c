char *get_interface_name(CliEntry *entry){
    CliFlag *name_flag = cli.entry.get_flag(entry,"name | n ",CLI_CASE_SENSITIVE);

    if(name_flag->exist == false){
        printf("name its required\n");
        return NULL;
    }
    if(name_flag->size == 0){
        printf("name flag its empty\n");
        return NULL;
    }
    return cli.flag.get_str(name_flag,0,CLI_CASE_SENSITIVE);

}

char *get_new_name(CliEntry *entry){
    CliFlag *new_name_flag = cli.entry.get_flag(entry,"new_name | n ",CLI_CASE_SENSITIVE);

    if(new_name_flag->exist == false){
        printf("new name is required\n");
        return NULL;
    }
    if(new_name_flag->size == 0){
        printf("new name flag is empty\n");
        return NULL;
    }
    return cli.flag.get_str(new_name_flag,0,CLI_CASE_SENSITIVE);

}