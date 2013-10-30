#pragma once
#include "util_tiempo.h"

namespace hw
{
namespace sensor
{
/**
 * Enum para representar los lados en los cuales están
 * los sensores ultrasónicos.
 */
enum class ultrason_lado : unsigned int
{
	ad = 0, atr = 1, izq = 2, der = 3
};

/**
 * Clase que representa los 4 sensores.
 * La constante interrupt indica donde esta
 * el interrupt del sensor 'ad', los demas deben
 * estar conectados siguiendo el orden en el que están
 * en la unión. Lo mismo para el ping donde se emite
 * la señal. La constante timeout representa la
 * cantidad de tiempo después del que se considera que
 * la respuesta no llegará y se deberá enviar otro pulso.
 * no_data es lo que se devuelve si no se tiene informacion
 * porque terminó el timeout o por otra razón.
 */
class sensores_ultrasonicos
{
friend class ayuda_act;
static const int interrupt;
static const int pin_in;
static const unsigned int timeout;
static const util::micros_t no_data;
util::micros_t comienzo_ping_[4];
volatile util::micros_t tiempos_[4];
volatile bool esperando_[4];
public:
	/**
	 * Constructor.
	 */
	sensores_ultrasonicos();
	
	/**
	 * Funcion que emite un pulso desde los sensores que no están esperando
	 * la respuesta.
	 */
	void actualizar();
	
	/**
	 * Funcion que retorna el tiempo que demora, o está demorando, la respuesta en
	 * llegar a un sensor determinado. Debe dividirse por 2 porque está considerada
	 * tanto la ida como la vuelta.
	 */
	util::micros_t tiempo(ultrason_lado) const;
};
}
}