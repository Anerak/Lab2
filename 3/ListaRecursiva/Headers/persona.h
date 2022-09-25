#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct stPersona
{
    int id;
    char nombre[10];
    int edad;
    char genero;
} stPersona;

void mostrarPersona(stPersona p);
stPersona personaRandom();

#endif