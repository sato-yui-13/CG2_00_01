#include<Windows.h>
#include<cstdint>

//ウィンドウプロシージャ
LRESULT CALLBACK WindoeProc(HWND hwnd, UINT msg, WPARAM wpaaram, LPARAM lparam) {
	//メッセージに大路手ゲーム固有の処理を行う
	switch (msg) {
		//ウィンドウが破棄された
	case WM_DESTROY:
		//OSに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}


	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wpaaram, lparam);

}

//Windowsアプリのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//出力ウィンドウへの文字出力
	OutputDebugStringA("Hello,DirectX!\n");

	WNDCLASS wc{};

	//ウィンドウプロシージャ
	wc.lpfnWndProc = WindoeProc;

	//ウィンドウクラス名
	wc.lpszClassName = L"CG2WindowClass";

	//インスタンスハンドル
	wc.hInstance = GetModuleHandle(nullptr);

	//カーソル
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	//ウィンドウクラス登録する
	RegisterClass(&wc);

	//クライアント領域のサイズ
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	//ウィンドウサイズを表す構造体にクライアント領域を入れる
	RECT wrc = { 0,0,kClientWidth ,kClientHeight };

	//クライアント領域をもとに実際のサイズにwrcを変更してもらう
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//ウィンドウの生成
	HWND hwnd = CreateWindow(
		wc.lpszClassName,   //利用するクラス名  
		L"CG2",             //タイルバーの文字
		WS_OVERLAPPEDWINDOW,//よく見るウィンドウスタイル
		CW_USEDEFAULT,      //表示X座標(Windowsに任せる)
		CW_USEDEFAULT,      //表示Y座標(WindowsOSに任せる)
		wrc.right-wrc.left, //ウィンドウ横幅
		wrc.bottom-wrc.top, //ウィンドウ縦幅
		nullptr,            //親ウィンドウハンドル
		nullptr,            //メニューハンドル
		wc.hInstance,       //インスタンスハンドル
		nullptr);           //オプション

	//ウィンドウを表示する
	ShowWindow(hwnd,SW_SHOW);

	MSG msg{};
    //ウィンドウの×ボタンが押されるまでループ
	while (msg.message!=WM_QUIT) {
		//Windowsにメッセージが来たら最優先で処理させる
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			//ゲームの処理
		}

	}
		return 0;
}