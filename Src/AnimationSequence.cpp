/*
 * AnimationSequence.cpp
 *
 *  Created on: 22 Jan 2020
 *      Author: michael
 */

#include "AnimationSequence.h"

AnimationSequence::AnimationSequence() {

}

AnimationSequence::~AnimationSequence() {
}

void AnimationSequence::addFrame(uint32_t tick, AnimationFrame *frame) {
	this->frames.insert(
			std::pair<uint32_t, AnimationFrame*>(tick, frame));
}

void AnimationSequence::start(void) {
	this->isRunning = true;
}
void AnimationSequence::stop(void) {
	this->isRunning = false;
	this->currentTick = 0;
}

void AnimationSequence::tick(void) {
	if (!this->isRunning)
		return;

	++this->currentTick;
	if (this->currentTick > this->getLengthMs()) {
		return this->restart();
	}
	AnimationFrame *frame = this->frames[this->currentTick];
	if (frame) {
		frame->play();
	}

}
void AnimationSequence::restart() {
	this->currentTick = 0;
	this->start();
}

uint32_t AnimationSequence::getLengthMs(void) {
	uint32_t furthestTick = 0;
	std::map<uint32_t, AnimationFrame*>::iterator it;
	for (it = this->frames.begin(); it != this->frames.end(); ++it) {
		if (it->first > furthestTick) {
			furthestTick = it->first;
		}
	}
	return furthestTick;
}
