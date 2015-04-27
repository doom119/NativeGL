/*
 * Log.h
 *
 *  Created on: 2015Äê1ÔÂ7ÈÕ
 *      Author: rayszhang
 */

#ifndef LOG_H_
#define LOG_H_

#include <android/log.h>

#define LOG_TAG "native_gl"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


#endif /* LOG_H_ */
