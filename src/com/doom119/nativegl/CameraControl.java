package com.doom119.nativegl;

import java.io.IOException;

import android.hardware.Camera;
import android.hardware.Camera.PreviewCallback;
import android.view.SurfaceHolder;

public class CameraControl implements PreviewCallback, SurfaceHolder.Callback
{
	private Camera mCamera;
	private CameraPreview mCameraPreview;
	
	private static CameraControl instance = new CameraControl();
	public static CameraControl getInstance()
	{
		return instance;
	}
	
	private CameraControl(){}
	
	public boolean openCamera()
	{
		try
		{
			mCamera = Camera.open();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			mCamera = null;
		}
		return mCamera != null;
	}


	@Override
	public void onPreviewFrame(byte[] data, Camera camera) 
	{
		
	}

	@Override
	public void surfaceCreated(SurfaceHolder holder) 
	{
		try {
			mCamera.setPreviewDisplay(holder);
			mCamera.setPreviewCallback(this);
		} catch (IOException e) {
			e.printStackTrace();
		}
		mCamera.startPreview();
	}

	@Override
	public void surfaceChanged(SurfaceHolder holder, int format, int width,
			int height) {
		
	}

	@Override
	public void surfaceDestroyed(SurfaceHolder holder) 
	{
		mCamera.stopPreview();
		try {
			mCamera.setPreviewDisplay(null);
		} catch (IOException e) {
			e.printStackTrace();
		}
		mCamera.setPreviewCallback(null);
	}
	
	public void setCameraPreview(CameraPreview preview)
	{
		mCameraPreview = preview;
	}

	public void close() 
	{
		mCamera.stopPreview();
		mCamera.release();
	}
}
