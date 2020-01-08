using System;
using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Runtime.InteropServices;

public class TestDll : MonoBehaviour
{
	//public int[] a;
	//public bool enableCam = false;
	//public RawImage camImage;
	//public bool showImg;
	////C:\Users\shubh\Pictures\OpenCVImg\lenna.png
	//public string imagePath;

	//[DllImport("OpenCVLib", EntryPoint = "TestSort")]
	//public static extern void TestSort(int[] a, int length);

	//[DllImport("OpenCVLib", EntryPoint = "UpdateFrame")]
	//public static extern void UpdateFrame(IntPtr texData, int width, int height);

	//[DllImport("OpenCVLib")]
	//public static extern void ShowImage(string filePath);

	//[DllImport("OpenCVLib")]
	//public static extern int DoubleInt(int a);

	//WebCamTexture camTex;
	//Texture2D cvTexture;
	////Color32[] cvTexCols;

	//private void Start()
	//{
	//	TestSort(a, a.Length);

	//	camImage.enabled = enableCam;

	//	print(DoubleInt(5));
	//}

	//public void ToggleCamera()
	//{
	//	enableCam = !enableCam;
	//	camImage.enabled = enableCam;
	//	if (enableCam)
	//	{
	//		camTex = new WebCamTexture();
	//		camTex.Play();
	//		camImage.texture = camTex;
	//	}
	//	else
	//	{
	//		if (camTex != null)
	//			camTex.Stop();
	//		Destroy(cvTexture);
	//	}
	//}

	//private void LateUpdate()
	//{
	//	if (showImg) ShowImage();

	//	if (!enableCam || camTex==null) return;
	//	if (cvTexture == null) { cvTexture = new Texture2D(camTex.width, camTex.height); return; }

	//	cvTexture.SetPixels32(camTex.GetPixels32());
	//	cvTexture.Apply();

	//	Texture2CVMat(cvTexture);

	//	camImage.texture = cvTexture;
	//}

	//void ShowImage()
	//{
	//	showImg = false;
	//	StartCoroutine(LoadImage());
	//}

	//IEnumerator LoadImage()
	//{
	//	//while(true)
	//	{
	//		yield return new WaitForEndOfFrame();

	//		ShowImage(imagePath);
	//	}
	//}

	//void Texture2CVMat(Texture2D tex)
	//{
	//	UpdateFrame(cvTexture.GetNativeTexturePtr(), cvTexture.width, cvTexture.height);
	//}
}
