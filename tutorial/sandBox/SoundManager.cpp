#include "SoundManager.h"

SoundManager::SoundManager() {
	engine = createIrrKlangDevice();

	if (!engine)
		return;
}

void SoundManager::playGameSound() {
	engine->play2D("C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\music\\Game.mp3", true);
}
void SoundManager::playGameNextLevel () {
	engine->play2D("C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\music\\success.mp3");
}
void SoundManager::playGameHit() {
	engine->play2D("C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\music\\hit.mp3");
}
void SoundManager::playGameLose() {
	engine->play2D("C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\music\\fail.mp3");
}
void SoundManager::playGameHealth() {
	engine->play2D("C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\music\\Health.mp3");
}
void SoundManager::playGameProgress() {
	engine->play2D("C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\music\\progress.mp3");
}