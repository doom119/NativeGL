package com.doom119.nativegl;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

public class MyRenderer implements Renderer 
{
	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) 
	{

	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) 
	{
		OpenGL.init(width, height);
	}

	@Override
	public void onDrawFrame(GL10 gl) 
	{
		OpenGL.draw();
	}

}
