package com.doom119.nativegl;

public class OpenGL 
{
	static
	{
		System.loadLibrary("NativeGL");
	}
	
	native public static void init(int width, int height);
	native public static void draw();
}
