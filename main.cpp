#include<Windows.h>
#include<cstdint>

//�E�B���h�E�v���V�[�W��
LRESULT CALLBACK WindoeProc(HWND hwnd, UINT msg, WPARAM wpaaram, LPARAM lparam) {
	//���b�Z�[�W�ɑ�H��Q�[���ŗL�̏������s��
	switch (msg) {
		//�E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		//OS�ɑ΂��āA�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}

	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wpaaram, lparam);

}

//Windows�A�v���̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�o�̓E�B���h�E�ւ̕����o��
	OutputDebugStringA("Hello,DirectX!\n");

	WNDCLASS wc{};

	//�E�B���h�E�v���V�[�W��
	wc.lpfnWndProc = WindoeProc;

	//�E�B���h�E�N���X��
	wc.lpszClassName = L"CG2WindowClass";

	//�C���X�^���X�n���h��
	wc.hInstance = GetModuleHandle(nullptr);

	//�J�[�\��
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	//�E�B���h�E�N���X�o�^����
	RegisterClass(&wc);

	//�N���C�A���g�̈�̃T�C�Y
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	//�E�B���h�E�T�C�Y��\���\���̂ɃN���C�A���g�̈������
	RECT wrc = { 0,0,kClientWidth ,kClientHeight };

	//�N���C�A���g�̈�����ƂɎ��ۂ̃T�C�Y��wrc��ύX���Ă��炤
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�̐���
	HWND hwnd = CreateWindow(
		wc.lpszClassName,   //���p����N���X��  
		L"CG2",             //�^�C���o�[�̕���
		WS_OVERLAPPEDWINDOW,//�悭����E�B���h�E�X�^�C��
		CW_USEDEFAULT,      //�\��X���W(Windows�ɔC����)
		CW_USEDEFAULT,      //�\��Y���W(WindowsOS�ɔC����)
		wrc.right-wrc.left, //�E�B���h�E����
		wrc.bottom-wrc.top, //�E�B���h�E�c��
		nullptr,            //�e�E�B���h�E�n���h��
		nullptr,            //���j���[�n���h��
		wc.hInstance,       //�C���X�^���X�n���h��
		nullptr);           //�I�v�V����

	//�E�B���h�E��\������
	ShowWindow(hwnd,SW_SHOW);

	MSG msg{};
    //�E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (msg.message!=WM_QUIT) {
		//Windows�Ƀ��b�Z�[�W��������ŗD��ŏ���������
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			//�Q�[���̏���
		}

	}
		return 0;
}