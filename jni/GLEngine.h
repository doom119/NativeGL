/*
 * GLEngine.h
 *
 *  Created on: 2015Äê1ÔÂ7ÈÕ
 *      Author: rayszhang
 */

#ifndef GLENGINE_H_
#define GLENGINE_H_

#include <jni.h>
#include <GLES2/gl2.h>
#include "Log.h"
#include <stdio.h>
#include <stdlib.h>

class GLEngine
{
public:
	GLEngine();
	GLuint createProgram(const GLchar* vShader, const GLchar* fShader);
	GLvoid useProgram(GLuint program);

	GLuint loadVertexShader(const GLchar* shader);
	GLuint loadFragmentShader(const GLchar* shader);
	GLvoid viewPort(GLint l, GLint t, GLsizei w, GLsizei h);
	GLvoid clearColor(GLclampf r, GLclampf g, GLclampf b, GLclampf a);
	GLvoid clear(GLbitfield mask);

	/************************************/
	GLuint getAttributeLocation(const GLuint program, const GLchar* attr);
	GLvoid vertexAttribPointer2f(const GLuint index, const GLfloat* pointer);
	GLvoid enableVertexAttribArray(GLuint index);

	/************************************/
	GLvoid drawArrays(GLenum mode, GLuint first, GLuint count);

	/************************************/
	GLvoid lineWidth(GLfloat width);
	GLvoid getLineWidthRange(GLfloat* rangeArray);
	GLvoid getPointSizeRange(GLfloat* sizeArray);

	/************************************/
	GLvoid enableCullFace(GLboolean enable);

	GLvoid cullFrontFace();
	GLvoid cullBackFace();
	GLvoid cullBothFace();

	GLvoid frontFaceCW();
	GLvoid frontFaceCCW();
	/************************************/

	GLvoid genBuffers(GLuint n, GLuint* buf);
	GLvoid bindArrayBuffer(GLuint index);
	GLvoid bindElementBuffer(GLuint index);
	virtual ~GLEngine();

	inline GLint getMaxVertexAttribs()
	{
		return mMaxVertexAttribs;
	}

	inline GLint getMaxVertexUniformVectors()
	{
		return mMaxVertexUniformVectors;
	}

	inline GLint getMaxVaryingVectors()
	{
		return mMaxVaryingVectors;
	}

	inline GLint getMaxTextureUnits()
	{
		return mMaxTextureUnits;
	}

private:
	GLuint loadShader(GLenum type, const GLchar* shader);
	static inline void checkGlError(const GLchar* op)
	{
	    for (GLint error = glGetError(); error; error = glGetError())
	    {
	        LOGE("after %s() glError (0x%x)\n", op, error);
	    }
	}

private:
	GLint mMaxVertexAttribs;
	GLint mMaxVertexUniformVectors;
	GLint mMaxVaryingVectors;
	GLint mMaxTextureUnits;
};

#endif /* GLENGINE_H_ */
