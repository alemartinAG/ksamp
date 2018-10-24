void parteD();

void parteD(){

	printf("\n ________________ \n \n");

            //Peticiones al disco
            imprimirDatos("/proc/diskstats", "sda");
            char pet_num[32];
            sscanf(datos, "%16s", pet_num);
            printf("Peticiones a disco: %s\n", pet_num);

            //Cantidad de memoria
            imprimirDatos("/proc/meminfo", "MemTotal:");
            printf("Memoria Total: %s \n", datos);

            //Memoria disponible
            imprimirDatos("/proc/meminfo", "MemFree:");
            printf("Memoria Disponible: %s \n", datos);

            //Promedio de carga
            imprimirDatos("/proc/loadavg", "");
            char avg_min[32];
            sscanf(datos, "%16s", avg_min);
            printf("Promedio de carga en el ultimo minuto: %s", avg_min);

}