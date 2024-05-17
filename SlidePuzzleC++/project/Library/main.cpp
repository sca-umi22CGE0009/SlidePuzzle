#include <DxLib.h>
#include "App.h"
#include "../Source/config.h"
#include "../ImGui/imgui_impl_dxlib.hpp"

#define CoGVersion (2.2)

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetOutApplicationLogValidFlag(FALSE); // ���O���o���Ȃ�

	SetMainWindowText(WINDOW_NAME);
	SetWindowSizeExtendRate(WINDOW_EXTEND);
	ChangeWindowMode(WINDOW_MODE); // Window���[�h�̏ꍇ

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	// ���[�U�[�̓��͂�ImGui��������悤�ɂ���
	SetHookWinProc([](HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT /*CALLBACK*/
	{
		// DxLib��ImGui�̃E�B���h�E�v���V�[�W���𗼗�������
		SetUseHookWinProcReturnValue(FALSE);
		return ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
	});

	// imgui init
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui_ImplDXlib_Init();

	AppInit();

	int mStartTime = GetNowCount();

	int screen = MakeScreen(SCREEN_WIDTH, SCREEN_HEIGHT, true);

	while (true) {
		if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0)//ESCAPE�L�[���������ꂽ��Application���I��
			break;

		//120fps�΍�
		int cur = GetNowCount();
		if (cur < mStartTime + 16)
			continue;
		mStartTime = cur;

		ImGui_ImplDXlib_NewFrame();
		ImGui::NewFrame();

		AppUpdate();

//		SetDrawScreen(screen);
//		ClearDrawScreen();
//		AppDraw();

//		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		AppDraw();
		//�`��
//		DrawGraph(0, 0, screen, true);
//		SetDrawScreen(DX_SCREEN_BACK);

		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDXlib_RenderDrawData();


		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}
		RefreshDxLibDirect3DSetting();

		//����ʕ`��
		ScreenFlip();
	}
	AppRelease();

	//Imgui�̏I������
	ImGui_ImplDXlib_Shutdown();
	ImGui::DestroyContext();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}