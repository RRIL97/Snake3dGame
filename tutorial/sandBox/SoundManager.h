#include <irrKlang.h>
#include <string>


using namespace irrklang;

class SoundManager {
public:
	SoundManager();
	
	void playGameSound();
	void playGameNextLevel();
	void playGameHit();
	void playGameLose();
	void playGameProgress();
	void playGameHealth();
	ISoundEngine * engine;


};