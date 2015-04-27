#include <jni.h>
#include "com_doom119_nativegl_OpenGL.h"
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLEngine.h>

static const char vShader[] =
		"precision highp float;\n"
		"attribute vec4 vPosition;\n"
		"void main() {\n"
		"gl_Position=vPosition;\n"
		"}\n";

static const char fShader[] =
		"void main(){\n"
		"gl_FragColor=vec4(1.0, 1.0, 0.0, 1.0);\n"
		"}\n";

static const float vertices[] = {-0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f};

GLEngine* gEngine;
GLuint gProgram;
GLuint gPosition;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	LOGD("JNI_OnLoad");
	JNIEnv* env = NULL;
	jint result = -1;
	if(vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK)
	{
		LOGE("JNI_OnLoad Failed");
		return result;
	}

	return JNI_VERSION_1_4;
}
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
{
	LOGD("JNI_OnUnload");
	if(gEngine)
		delete gEngine;
}

JNIEXPORT void JNICALL Java_com_doom119_nativegl_OpenGL_init
  (JNIEnv *, jclass, jint w, jint h)
{
	gEngine = new GLEngine();
	gProgram = gEngine->createProgram(vShader, fShader);
	if(gProgram)
	{
		gPosition = gEngine->getAttributeLocation(gProgram, "vPosition");
	}
	gEngine->enableCullFace(true);
	gEngine->viewPort(0, 0, w, h);
}

JNIEXPORT void JNICALL Java_com_doom119_nativegl_OpenGL_draw
  (JNIEnv *, jclass)
{
	gEngine->clearColor(0, 0, 0, 1);
	gEngine->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gEngine->useProgram(gProgram);
	gEngine->vertexAttribPointer2f(gPosition, vertices);
	gEngine->enableVertexAttribArray(gPosition);
	gEngine->drawArrays(GL_TRIANGLES, 0, 6);
}
