/**
 * Common objects for work with audio
 */

#ifndef AUDIO_H_
#define AUDIO_H_

#include <string>
#include <list>
#include <memory>
#include <cstdlib>
#include <stdint.h>
#include "../common.h"

namespace wtm {
namespace audio {

	/**
	 * Raw audio data type
	 */
	typedef int16_t raw_t;

	/**
	 * Raw audio data type
	 */
	typedef uint32_t length_t;


	/**
	 * Length of frame (ms)
	 */
	const length_t FRAME_LENGTH = 10;

	/**
	 * Percentage of overlap for frames (0 <= x < 1)
	 */
	const double FRAME_OVERLAP = 0.5;

	/**
	 * Amount (odd) of elements for moving average smoothing during words splitting
	 * Length of analysing fragment is FRAME_LENGTH * (1 - FRAME_OVERLAP) * MA_SIZE
	 */
	const unsigned short MOVING_AVERAGE_SIZE = 3;

	/**
	 * Minimal size of word (in frames)
	 * <p>
	 * Let's put that minimal length of word is 200ms.
	 */
	const unsigned short WORD_MIN_SIZE = (200 / FRAME_LENGTH) / (1 - FRAME_OVERLAP);

	/**
	 * Minimal amount of framer between two words
	 * <p>
	 * Let's put that minimal distance between two words is 50% of minimal size of word
	 */
	const unsigned short WORDS_MIN_DISTANCE = WORD_MIN_SIZE * 0.70;

} // namespace audio
} // namespace wtm

#endif /* AUDIO_H_ */
