void parteC();

void parteC(){
	printf("\n ________________ \n \n");

        //Tiempo de CPU utilizado
        imprimirDatos("/proc/stat", "cpu");

        long MY_HZ = sysconf(_SC_CLK_TCK);
        long cpu_user;
        long cpu_syst;
        long cpu_idle;
        long x;
        sscanf(datos, "%ld %ld %ld %ld", &cpu_user, &x, &cpu_syst, &cpu_idle);
        printf("CPU usage [jiffies] =  User: %ld / System: %ld / Idle: %ld \n", cpu_user, cpu_syst, cpu_idle);
        printf("CPU usage [seconds] =  User: %ld / System: %ld / Idle: %ld \n", cpu_user/MY_HZ, cpu_syst/MY_HZ, cpu_idle/MY_HZ);

        //Cambios de contexto
        imprimirDatos("/proc/stat", "ctxt");
        printf("Cambios de contexto: %s \n", datos);

        //Fecha y hora de inicio de sistema
        imprimirDatos("/proc/stat", "btime");
        time_t c;
        c = strtoul(datos, NULL, 0);
        char *iniciosys;
        iniciosys = ctime(&c);
        printf("Hora y fecha del inicio del sistema: %s", iniciosys);
        //printf("BTIME: %s \n", datos);

        //Procesos creados
        imprimirDatos("/proc/stat", "processes");
        printf("Procesos creados: %s \n", datos);
}