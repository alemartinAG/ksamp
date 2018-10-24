//Autores: Arce Giacobbe Aleandro
//         Drudi Leandro

#include <stdio.h>
#include <memory.h>
#include <getopt.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//Incluyo archivos .h
#include "imprimirDatos.h"
#include "imprimirLineas.h"
#include "paramError.h"

#include "parteB.h"
#include "parteC.h"
#include "parteD.h"

int  system(const char *command);

int main(int argc, char *argv[]) {

    //declaro booleans para los argumentos
    bool flag_s = false;
    bool flag_l = false;

    //declaro cantidad de iteraciones y el tiempo entre estas para la parte D
    int delay_time = 1;
    int iterations = 0;


    int opt;

    while (1) {
        
        //Este while parsea todos los argumentos de argv con la función getopt_long()
        
        int option_index = 0;

        static struct option long_options[] = {
                {"s", no_argument, 0, 's'},
                {"l", required_argument, 0, 'l'},
                {0, 0, 0, 0}
        };
        
        //La cadena "sl:" indica que s no tiene argumentos, y l tiene un argumento requerido
        opt = getopt_long (argc, argv, "sl:", long_options, &option_index);
        
        if (opt == -1){
            break; //c es -1 cuando se terminan todos los argumentos, entonces sale del while
        }   

        switch (opt) {
            
            //si se paso tambien el parametro l me tirara error, si no levanto el flag
            case 's':
                if(flag_l){
                    paramError();
                }

                flag_s = true;
                break;

            //si se paso tambien el parametro s me tirara error, si no levanto el flag
            case 'l':
                if(flag_s){
                    paramError();
                }

                flag_l = true;

                //parseo los dos argumentos adicionales
                delay_time = (int) (*optarg) - 48;

                if (optind < argc) {
                    iterations = (int) (*argv[optind++]) -48;
                }
                else{
                    paramError();
                }

                //establezco límites a los valores de los parametros
                if(delay_time < 0 || iterations < 0){
                    paramError();
                }

                break;

            default:
                paramError();
        }
    }

    if (optind < argc) {
        paramError();
    }

    //se ejecuta la parte B
    parteB();

    //si se paso algun parametro, ejecuto la parte C
    if(flag_s || flag_l){

        parteC();

    }

    //si se paso el parametro l, ejecuto la parte D
    if(flag_l){

        //la ejecuto la cantidad de veces requeridas
        for(int i=0; i<iterations; i++){

            parteD();

            unsigned int dt = (unsigned) delay_time;
            //printf("DT = %u\n", dt);

            //cada cierto intervalo de tiempo requerido
            sleep(dt);
        }

    }

    printf("\n \n");

    return 0;
}

