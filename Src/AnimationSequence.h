#include "AnimationFrame.h"
#include <stdbool.h>
#include <stdint.h>
#include <map>
/*
 * AnimationSequence.h
 *
 *  Created on: 22 Jan 2020
 *      Author: michael
 */

#ifndef MODELS_ANIMATIONSEQUENCE_H_
#define MODELS_ANIMATIONSEQUENCE_H_

class AnimationSequence {
private:
	std::map<uint32_t, AnimationFrame*> frames = { };
	bool triggersRandomly = false;
	uint32_t currentTick = 0;
	bool isRunning = false;
public:
	AnimationSequence();
	virtual ~AnimationSequence();

	void start(void);
	void stop(void);
	void tick(void);
	void restart();

	void addFrame(uint32_t tick, AnimationFrame *frame);
	uint32_t getLengthMs(void);
};

#endif /* MODELS_ANIMATIONSEQUENCE_H_ */
