#pragma once

#include <string>
#include <fstream>

namespace 勤務時間管理ツール {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	

	/// <summary>
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		/* 変数の宣言----------------------------------------------------------------- */
		const int item = 7;				// 項目数
		const int head = 3;				// 実効データの前の行数

		const int totalDayLine	= 1;	// 合計日数の列	既定値:1		
		const int totalTimeLine	= 2;	// 合計時間の列	既定値:2	
		const int overTimeLine	= 4;	// 残業時間の列	既定値:4		
		const int lateLine		= 6;	// 遅刻回数の列	既定値:7		
		const int earlyLine		= 5;	// 早退回数の列	既定値:8	
		const int absenceLine	= 7;	// 欠勤回数の列	既定値:9		

		int line;						// 行数
		int record;						// データ件数
		array<array<String^>^>^ data;	// CSVファイルの内容を格納する2次元配列[record][item]
		array<String^>^ name;			// data[][]の中から名前を格納する配列
		array<array<int>^>^ dataNum;	// data[][]の中から名前以外の値を格納する配列

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			this->FileSelect->Click += gcnew
				System::EventHandler(this, &Form1::FileSelect_Click);
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^  FileSelect;
	private: System::Windows::Forms::Button^  Sort;
	private: System::Windows::Forms::Button^  FileExport;
	private: System::Windows::Forms::ComboBox^  SortSelect;

	private: System::Windows::Forms::TextBox^  FileAbsolutePath;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ListView^  listView1;

	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;



	protected:
	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Sort = (gcnew System::Windows::Forms::Button());
			this->FileExport = (gcnew System::Windows::Forms::Button());
			this->SortSelect = (gcnew System::Windows::Forms::ComboBox());
			this->FileAbsolutePath = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->FileSelect = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Sort
			// 
			this->Sort->Location = System::Drawing::Point(488, 50);
			this->Sort->Name = L"Sort";
			this->Sort->Size = System::Drawing::Size(75, 23);
			this->Sort->TabIndex = 1;
			this->Sort->Text = L"ソート適用";
			this->Sort->UseVisualStyleBackColor = true;
			this->Sort->Click += gcnew System::EventHandler(this, &Form1::Sort_Click);
			// 
			// FileExport
			// 
			this->FileExport->Location = System::Drawing::Point(488, 298);
			this->FileExport->Name = L"FileExport";
			this->FileExport->Size = System::Drawing::Size(75, 23);
			this->FileExport->TabIndex = 2;
			this->FileExport->Text = L"ファイル出力";
			this->FileExport->UseVisualStyleBackColor = true;
			this->FileExport->Click += gcnew System::EventHandler(this, &Form1::FileExport_Click);
			// 
			// SortSelect
			// 
			this->SortSelect->FormattingEnabled = true;
			this->SortSelect->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"名前", L"合計日数", L"合計時間", L"残業時間", L"遅刻", L"早退",
					L"欠勤"
			});
			this->SortSelect->Location = System::Drawing::Point(228, 52);
			this->SortSelect->Name = L"SortSelect";
			this->SortSelect->Size = System::Drawing::Size(121, 20);
			this->SortSelect->TabIndex = 3;
			this->SortSelect->Text = L"ソート項目を選択";
			// 
			// FileAbsolutePath
			// 
			this->FileAbsolutePath->BackColor = System::Drawing::SystemColors::Window;
			this->FileAbsolutePath->Location = System::Drawing::Point(22, 14);
			this->FileAbsolutePath->Name = L"FileAbsolutePath";
			this->FileAbsolutePath->ReadOnly = true;
			this->FileAbsolutePath->Size = System::Drawing::Size(444, 19);
			this->FileAbsolutePath->TabIndex = 5;
			// 
			// listView1
			// 
			this->listView1->Alignment = System::Windows::Forms::ListViewAlignment::Default;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7
			});
			this->listView1->Font = (gcnew System::Drawing::Font(L"メイリオ", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(22, 91);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(541, 189);
			this->listView1->TabIndex = 7;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"名前";
			this->columnHeader1->Width = 120;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"合計日数";
			this->columnHeader2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"合計時間";
			this->columnHeader3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader3->Width = 80;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"残業時間";
			this->columnHeader4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader4->Width = 80;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"遅刻";
			this->columnHeader5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"早退";
			this->columnHeader6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"欠勤";
			this->columnHeader7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(366, 53);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(47, 16);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->Text = L"昇順";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(419, 53);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(47, 16);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"降順";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// FileSelect
			// 
			this->FileSelect->Location = System::Drawing::Point(488, 12);
			this->FileSelect->Name = L"FileSelect";
			this->FileSelect->Size = System::Drawing::Size(75, 23);
			this->FileSelect->TabIndex = 0;
			this->FileSelect->Text = L"ファイル選択";
			this->FileSelect->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(585, 335);
			this->Controls->Add(this->FileSelect);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->FileAbsolutePath);
			this->Controls->Add(this->SortSelect);
			this->Controls->Add(this->FileExport);
			this->Controls->Add(this->Sort);
			this->Name = L"Form1";
			this->Text = L"勤怠管理システム";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		/* メソッドくん---------------------------------------------------------*/

		// 条件に応じて項目に色をつける
		void itemColor(){
			
			for (int i = 0; i < record; i++){
				if (dataNum[i][3] >= 40*60){
					listView1->Items[i]->BackColor = Color::FromArgb(0x78FF0000);
				}
				if (dataNum[i][4] + dataNum[i][5] + dataNum[i][6] >= 10){
					listView1->Items[i]->BackColor = Color::FromArgb(0x78FFFF00);
				}
				if (dataNum[i][3] >= 40*60 && dataNum[i][4] + dataNum[i][5] + dataNum[i][6] >= 10){
					listView1->Items[i]->BackColor = Color::FromArgb(0x78FF8800);
				}
			}
			return;
		}

		// エラーを表示 いらないかな…
		void errorComment(int e){
			switch (e)

			{
			default:
				break;
			}
			return;
		}

		// .csv open
		void csvOpen(){

			/* 変数 */
			int freq = 0;			// ループ回数
			StreamReader^ sr;		// StreamReader
			String^ fileName;		// 選択するファイル名

			/* ダイアログの設定 */
			openFileDialog1->Filter = "CSV Files|*.csv";
			openFileDialog1->Title = "CSVファイルを選択してください";

			// ダイアログを表示する
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){

				// 選択したファイル名を格納
				fileName = openFileDialog1->FileName;
				
				// 選択したファイル名をテキストボックスに
				FileAbsolutePath->Text = fileName;
				
				// 選択したファイルをStreamReaderへ
				sr = gcnew StreamReader(fileName);
				
				// 行数を数える(数えた行数はint lineへ)
				countLine(fileName);
				
				// data[record][item]の確保
				data = gcnew array<array<String^>^>(line);
				for (int i = 0; i < line; i++){
					data[i] = gcnew array<String^>(item);
				}
				
				// StreamReaderを行ごとにStringの配列へ
				do
				{
					// 1行読み込む
					String^ srLine = sr->ReadLine();

					/* 分割 */
					// 区切り記号は ","
					array<String^>^ sepStr = gcnew array <String^> {","};

					// data[freq][item]に分割した文字列を入れ込む
					data[freq] = srLine->Split(sepStr, StringSplitOptions::RemoveEmptyEntries);
					freq++;

				// 読み込む文字がなくなるまでループ
				} while (sr->Peek() != -1);
			}
			sr->Close();

			// 名前の配列とデータの配列を作成
			nameArray();
			dataNumArray();

			return;
		}

		// 行数を数える
		void countLine(String^ name){
			int n;
			StreamReader^ a = gcnew StreamReader(name);
			do{
				a->ReadLine();
				n++;
			} while (a->Peek() != -1);
			line = n;
			record = line - head;
			a->Close();
			return;
		}

		// 名前の配列
		void nameArray(){
			// name[record]の確保
			name = gcnew array<String^>(record);

			// dataの値を代入
			for (int i = 0; i < record; i++){
				name[i] = data[i + head][0];
			}
			return;
		}

		// データの配列
		void dataNumArray(){
			// dataNum[record - head][item]の確保
			dataNum = gcnew array<array<int>^>(record);
			for (int i = 0; i < record; i++){
				dataNum[i] = gcnew array<int>(item);
			}
			// dataの値の代入
			for (int i = 0; i < record; i++){
				dataNum[i][0] = i;
				dataNum[i][1] = strToInt(data[i + head][totalDayLine]);
				dataNum[i][2] = strToInt(data[i + head][totalTimeLine]);
				dataNum[i][3] = strToInt(data[i + head][overTimeLine]);
				dataNum[i][4] = strToInt(data[i + head][lateLine]);
				dataNum[i][5] = strToInt(data[i + head][earlyLine]);
				dataNum[i][6] = strToInt(data[i + head][absenceLine]);
			}
			return;
		}

		// Stringをintで返す
		int strToInt(String^ s){
			int a;
			if (s->IndexOf(":") != -1){
				a = timeToMin(s);
			}else{
				a = int::Parse(s);
			}
			return a;
		}

		// String h:m:sをint sに
		int timeToMin(String^ s){
			int a;
			array<String^>^ colon = gcnew array < String^ > {":"};
			array<String^>^ time = s->Split(colon, StringSplitOptions::None);
			for (int i = 0; i < 2; i++){
				int sec = pow(60, 1 - i);
				sec = sec * int::Parse(time[i]);
				a = a + sec;
			}
				return a;
		}

		// int sをString h:mmに
		String^ minToTime(int s){
			String^ a;
			for (int i = 0; i < 2; i++){
				int unit = pow(60, 1 - i);
				int loop = 0;
				while (s >= unit){
					s -=  unit;
					loop++;
				}
				if (loop < 10 && i != 0){
					a += "0" + loop;
				}else{
					a += loop + "";
				}
				if (i < 1){
					a += ":";
				}
			}
			return a;
		}

		void sort(){
			int a;
			Boolean b = radioButton1->Checked;
			int c = SortSelect->SelectedIndex;
			array<String^>^ sName;
			sName = gcnew array<String^>(record);
			for (int nameRecord = 0; nameRecord < record; nameRecord++){
				sName[nameRecord] = name[nameRecord];
			}
			if (c != -1){
				for (int i = 0; i < record-1; i++){
					for (int j = record -1; j > i; j--){
						for (int k = 0; k < item; k++){
							if (b){
								if (dataNum[j][c] < dataNum[j - 1][c]){
									a = dataNum[j][k];
									dataNum[j][k] = dataNum[j - 1][k];
									dataNum[j - 1][k] = a;
								}
							}else{
								if (dataNum[j][c] > dataNum[j - 1][c]){
									a = dataNum[j - 1][k];
									dataNum[j - 1][k] = dataNum[j][k];
									dataNum[j][k] = a;
								}
							}
						}
					}
				}
				for (int nameRecord = 0; nameRecord < record; nameRecord++){
					name[nameRecord] = sName[dataNum[nameRecord][0]];
				}
			}
			return;
		}

		// ListView1にnameとdataNumを追加
		void insert(){
			// ListView1のクリア
			listView1->Items->Clear();
			// データを追加
			for (int i = 0; i < record; i++){
				// アイテムを追加
				ListViewItem^ nameCol = gcnew ListViewItem(name[i]);
				array<ListViewItem^>^temp = { nameCol };
				listView1->Items->AddRange(temp);
				// サブアイテムを追加
				for (int j = 1; j < item; j++){
					if (j == 2 || j == 3){
						nameCol->SubItems->Add(minToTime(dataNum[i][j]));
					}else{
						nameCol->SubItems->Add(dataNum[i][j] + "");
					}
				}
			}
			// 色つける
			itemColor();
			return;
		}
		void insert2(int a[][10]){

			for (int i = 0; i < 10; i++){
				// 名前を追加
				ListViewItem^ name = gcnew ListViewItem(a[i][0] + "");
				array<ListViewItem^>^temp = { name };
				listView1->Items->AddRange(temp);
				// サブアイテムを追加
				for (int j = 1; j <= 7; j++){
					name->SubItems->Add(a[i][j] + "");
				}
				// 色つける
				itemColor();
			}
			return;
		}

		/* メソッドくん---------------------------------------------------------*/

#pragma endregion
	private: System::Void FileSelect_Click(System::Object^  sender, System::EventArgs^  e) {

		// ファイル開く
		csvOpen();
		// listViewに追加
		insert();

		/*
		// ダイアログの設定
		openFileDialog1->Filter = "CSV Files|*.csv";
		openFileDialog1->Title = "CSVファイルを選択してください";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::IO::StreamReader ^ sr = gcnew
				System::IO::StreamReader(openFileDialog1->FileName, System::Text::Encoding::UTF8);

			// TextBoxにファイルの絶対パスを表示
			FileAbsolutePath->Text = openFileDialog1->FileName;

			// ループ回数をカウントする変数
			int freq = 0;
			// 選択したCSVファイルを読み込む
			do
			{
				// 3行目以降から処理
				if (freq < 3){
					// 最初の3行はスルー
					sr->ReadLine();
				}
				else{
					// 1行読み込む
					System::String^ line = sr->ReadLine();
					// 分割 
					// 区切り記号は","
					array< System::String^ > ^sepStr = gcnew array < System::String^ > {","};
					// data[freq - 3][item]に分割した文字列を入れ込む
					data[freq - 3] = line->Split(sepStr, StringSplitOptions::None);
				}
				freq++;
			// 読み込む文字がなくなるまでループ
			} while (sr->Peek() != -1);

			// 氏名	合計(日)	合計(時)	残業(日)	残業(時)	休出(日)	休出(時)	遅刻	早退	欠勤	慶弔	有休	代休	その他	未入力
			sr->Close();
			

		}*/


	}

	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void FileExport_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int j = 0; j < item; j++){
			if (j == 0){
				MessageBox::Show("a");
			}
			else if (j == 1,2,4,7,8,9){
				MessageBox::Show("b"+j);
			}
			else{
				MessageBox::Show("c" + j);
			}
			MessageBox::Show("d" + j);
		
		}
	}

	private: System::Void Sort_Click(System::Object^  sender, System::EventArgs^  e) {
		// ソート実行
		sort();
		// ソート後のアイテムを追加
		insert();
		}
	
	};
}


