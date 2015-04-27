package com.doom119.nativegl;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceHolder;
import android.view.SurfaceHolder.Callback;
import android.view.SurfaceView;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_main);
		if(!CameraControl.getInstance().openCamera())
			return;
		
		SurfaceView surfaceView = (SurfaceView)findViewById(R.id.surface_view);
		SurfaceHolder surfaceHolder = surfaceView.getHolder();
		surfaceHolder.addCallback(CameraControl.getInstance());
		
//		Log.d("rayszhang", "model="+Build.MODEL);
//		
//		GLSurfaceView view = new GLSurfaceView(this);
//		view.setEGLContextClientVersion(2);
//		view.setRenderer(new MyRenderer());
//		view.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
//		setContentView(view);
	}
	
	@Override
	protected void onDestroy() 
	{
		super.onDestroy();
		CameraControl.getInstance().close();
	}

}
