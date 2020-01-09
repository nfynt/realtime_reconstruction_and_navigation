using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Runtime.InteropServices;

public class CameraStream : MonoBehaviour
{
	public RawImage imageCanvas;
	public Button cameraBtn;
	public bool cvtGray;
	public int camInd = 0;
	public List<string> camsFound = new List<string>();

	[DllImport("OpenCVLib")]
	public static extern void ConvertTexToGray(ref Color32[] texData, int width, int height);

	[DllImport("OpenCVLib")]
	public static extern void CannyEdgeFilter(ref Color32[] texData, int width, int height);

	private bool streaming;
	private WebCamTexture camTex;
	private Texture2D streamingTex;

	private void Start()
	{
		streaming = false;

		cameraBtn.onClick.RemoveAllListeners();
		cameraBtn.onClick.AddListener(ToggleCamera);

		foreach (WebCamDevice wd in WebCamTexture.devices)
			camsFound.Add(wd.name);
	}

	void ToggleCamera()
	{
		streaming = !streaming;

		if(streaming)
		{
			camTex = new WebCamTexture(camsFound[camInd]);
			camTex.Play();
			imageCanvas.texture = streamingTex;
		}
		else
		{
			camTex.Stop();
			Destroy(streamingTex);
		}
	}

	private void Update()
	{
		if (!streaming || camTex == null) return;
		if (streamingTex == null)
		{
			streamingTex = new Texture2D(camTex.width, camTex.height);
			imageCanvas.texture = streamingTex;
		}


		if(camTex.isPlaying)
		{
			var texData = camTex.GetPixels32();
			if (cvtGray)
				ConvertTexToGray(ref texData, camTex.width, camTex.height);
			else
				CannyEdgeFilter(ref texData, camTex.width, camTex.height);
			streamingTex.SetPixels32(texData);
			streamingTex.Apply();
		}
	}
}
