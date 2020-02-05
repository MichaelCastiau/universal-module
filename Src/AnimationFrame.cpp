/*
 * AnimationFrame.cpp
 *
 *  Created on: 22 Jan 2020
 *      Author: michael
 */

#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(callback *fnc) {
	this->fnOnStart = fnc;
}

AnimationFrame::~AnimationFrame() {
}

void AnimationFrame::play() {
	this->fnOnStart();
}
