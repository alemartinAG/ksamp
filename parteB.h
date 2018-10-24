void parteB();

void parteB(){
    
    //Maquina y fecha actuales
    printf("\n");
    system("hostname");
    system("date");
    printf("\n ________________ \n \n");


    //Tipo y modelo de CPU
    imprimirDatos("/proc/cpuinfo", "model name");
    printf("Cpu model name%s \n", datos);


    //Versión de Kernel
    imprimirDatos("/proc/version", "");
    char kernel[64];
    sscanf(datos, "%16s %16s %32s", kernel, kernel, kernel);
    printf("Kernel Version: %s \n", kernel);


    //Tiempo desde que se inició el sistema operativo
    imprimirDatos("/proc/uptime", "");

    int uptime;
    sscanf(datos, "%d", &uptime);
    printf("Uptime: %02dD %02d:%02d:%02d \n", (uptime / 60 / 60 / 24), (uptime / 60 / 60 % 24), (uptime / 60 % 60),
           (uptime % 60));


    //Cantidad de sistemas de archivo soportados por el kernel;
    imprimirLineas("/proc/filesystems");

}

