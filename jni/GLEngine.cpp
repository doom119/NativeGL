/*
 * GLEngine.cpp
 *
 *  Created on: 2015Äê1ÔÂ7ÈÕ
 *      Author: rayszhang
 */

#include "GLEngine.h"

GLEngine::GLEngine()
{
	mMaxVertexAttribs = 0;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &mMaxVertexAttribs);
	checkGlError("glGetIntegerv");
	LOGD("Max Vertex Attribs=%d\n", mMaxVertexAttribs);

	mMaxVertexUniformVectors = 0;
	glGetIntegerv(GL_MAX_VERTEX_UNIFORM_VECTORS, &mMaxVertexUniformVectors);
	checkGlError("glGetIntegerv");
	LOGD("Max Vertex Uniforms=%d\n", mMaxVertexUniformVectors);

	mMaxVaryingVectors = 0;
	glGetIntegerv(GL_MAX_VARYING_VECTORS, &mMaxVaryingVectors);
	checkGlError("glGetIntegerv");
	LOGD("Max Varying Vectors=%d\n", mMaxVaryingVectors);

	mMaxTextureUnits = 0;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &mMaxTextureUnits);
	checkGlError("glGetIntegerv");
	LOGD("Max Texture Units=%d\n", mMaxTextureUnits);
}

GLEngine::~GLEngine() {
	// TODO Auto-generated destructor stub
}

GLuint GLEngine::createProgram(const char* vShaderSource, const GLchar* fShaderSource)
{
	GLuint vShaderHandle = loadVertexShader(vShaderSource);
	if(!vShaderSource)
		return 0;

	GLuint fShaderHandle = loadFragmentShader(fShaderSource);
	if(!fShaderHandle)
		return 0;

	GLuint program = glCreateProgram();
	if(program)
	{
		glAttachShader(program, vShaderHandle);
		checkGlError("glAttachShader");
		glAttachShader(program, fShaderHandle);
		checkGlError("glAttachShader");
		glLinkProgram(program);
		GLint linkStatus = GL_FALSE;
		glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
		if(linkStatus != GL_TRUE)
		{
			GLint bufLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
			if(bufLength)
			{
				GLchar* buf = (GLchar*)malloc(bufLength);
				if(buf)
				{
					glGetProgramInfoLog(program, bufLength, NULL, buf);
					LOGE("Could not link program:\n%s\n", buf);
					free(buf);
				}
			}
			glDeleteProgram(program);
			program = 0;
		}
	}
	LOGD("createProgram:%d\n", program);

	return program;
}

GLuint GLEngine::loadVertexShader(const GLchar* shaderSource)
{
	GLuint shader = loadShader(GL_VERTEX_SHADER, shaderSource);
	LOGD("loadVertexShader, shader=%d\n", shader);
	return shader;
}

GLuint GLEngine::loadFragmentShader(const GLchar* shaderSource)
{
	GLint shader = loadShader(GL_FRAGMENT_SHADER, shaderSource);
	LOGD("loadFragmentShader, shader=%d\n", shader);
	return shader;
}

GLuint GLEngine::loadShader(GLenum type, const GLchar* shaderSource)
{
	GLuint shader = glCreateShader(type);
	if(shader)
	{
		glShaderSource(shader, 1, &shaderSource, NULL);
		glCompileShader(shader);
		GLint compiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if(!compiled)
		{
			GLint infoLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLength);
			if(infoLength)
			{
				GLchar* buf = (GLchar*)malloc(infoLength);
				if(buf)
				{
					glGetShaderInfoLog(shader, infoLength, NULL, buf);
					LOGE("Could not compile shader %d\n%s\n", type, buf);
					free(buf);
				}
				glDeleteShader(shader);
				shader = 0;
			}
		}
	}

	return shader;
}

GLuint GLEngine::getAttributeLocation(GLuint program, const GLchar* attr)
{
	GLuint handle = glGetAttribLocation(program, attr);
	checkGlError("glGetAttribLocation");
	LOGD("getAttributeLocation:%d\n", handle);
	return handle;
}

void GLEngine::useProgram(GLuint program)
{
	glUseProgram(program);
	checkGlError("glUseProgram");
}

GLvoid GLEngine::viewPort(GLint l, GLint t, GLsizei w, GLsizei h)
{
	glViewport(l, t, w, h);
	checkGlError("glViewport");
}

GLvoid GLEngine::clearColor(GLclampf r, GLclampf g, GLclampf b, GLclampf a)
{
	glClearColor(r, g, b, a);
	checkGlError("clearColor");
}

GLvoid GLEngine::clear(GLbitfield mask)
{
	glClear(mask);
	checkGlError("glClear");
}

GLvoid GLEngine::vertexAttribPointer2f(const GLuint index, const GLfloat* pointer)
{
	glVertexAttribPointer(index, 2, GL_FLOAT, GL_FALSE, 0, pointer);
	checkGlError("glVertexAttribPointer");
}

GLvoid GLEngine::drawArrays(GLenum mode, GLuint first, GLuint count)
{
	glDrawArrays(mode, first, count);
	checkGlError("glDrawArrays");
}

GLvoid GLEngine::enableVertexAttribArray(GLuint index)
{
	glEnableVertexAttribArray(index);
	checkGlError("glEnableVertexAttribArray");
}

GLvoid GLEngine::lineWidth(GLfloat width)
{
	glLineWidth(width);
	checkGlError("glLineWidth");
}

GLvoid GLEngine::getLineWidthRange(GLfloat* rangeArray)
{
	glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, rangeArray);
	checkGlError("glGetFloatv");
}

GLvoid GLEngine::getPointSizeRange(GLfloat* sizeArray)
{
	glGetFloatv(GL_ALIASED_POINT_SIZE_RANGE, sizeArray);
	checkGlError("glGetFloatv");
}

GLvoid GLEngine::frontFaceCW()
{
	glFrontFace(GL_CW);
	checkGlError("glFrontFace");
}

GLvoid GLEngine::frontFaceCCW()
{
	glFrontFace(GL_CCW);
	checkGlError("glFrontFace");
}

GLvoid GLEngine::cullFrontFace()
{
	glCullFace(GL_FRONT);
	checkGlError("glCullFace");
}

GLvoid GLEngine::cullBackFace()
{
	glCullFace(GL_BACK);
	checkGlError("glCullFace");
}

GLvoid GLEngine::cullBothFace()
{
	glCullFace(GL_FRONT_AND_BACK);
	checkGlError("glCullFace");
}

GLvoid GLEngine::enableCullFace(GLboolean enable)
{
	if(enable)
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);
	checkGlError("glEnable");
}

GLvoid GLEngine::genBuffers(GLuint n, GLuint* buf)
{
	glGenBuffers(n, buf);
	checkGlError("glGenBuffers");
}

GLvoid GLEngine::bindArrayBuffer(GLuint index)
{
	glBindBuffer(GL_ARRAY_BUFFER, index);
	checkGlError("glBindBuffer");
}

GLvoid GLEngine::bindElementBuffer(GLuint index)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	checkGlError("glBindBuffer");
}
