char *get_interface_name(CliEntry *entry){
    CliFlag *name_flag = cli.entry.get_flag(entry,"name | n ",CLI_NOT_CASE_SENSITIVE);

    if(name_flag->exist == false){
        printf("name its required\n");
        return NULL;
    }
    if(name_flag->size == 0){
        printf("name flag its empty\n");
        return NULL;
    }
    return cli.flag.get_str(name_flag,1,CLI_CASE_SENSITIVE);

}