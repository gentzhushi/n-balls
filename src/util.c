#include "util.h"

Color getRandomColor(){
	return (Color){
		GetRandomValue(50,255),
		GetRandomValue(50,255),
		GetRandomValue(50,255),
		GetRandomValue(200,255)
	};
}
