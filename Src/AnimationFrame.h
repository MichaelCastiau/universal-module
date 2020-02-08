#include <stdint.h>

#include "definitions.h"
/*
 * AnimationFrame.h
 *
 *  Created on: 22 Jan 2020
 *      Author: michael
 */

#ifndef MODELS_ANIMATIONFRAME_H_
#define MODELS_ANIMATIONFRAME_H_

class AnimationFrame {
private:
	/**
	 * Functor that is called when animation frame will start
	 */
	callback *fnOnStart = nullptr;
public:
	AnimationFrame(callback *fnc);
	virtual ~AnimationFrame();

	void play(void);
};

#endif /* MODELS_ANIMATIONFRAME_H_ */
