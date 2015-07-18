// 勤務時間管理ツール.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include "Form1.h"
#include <fstream>
// #include <iostream>
#include <string>
#include <sstream> 
#include <iostream>


using namespace 勤務時間管理ツール;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew Form1());
	return 0;
}


