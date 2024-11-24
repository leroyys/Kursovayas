
// MFCApplication1Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Создание
public:
	bool IsNumeric(const CString& str);
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	CEdit Five;
	CEdit Six;
	CEdit Seven;
	CEdit Eight;
	CEdit Three;
	CListBox Result1;
	afx_msg void OnBnClickedButton4();
	CEdit Eleven;
	CEdit twelwe;
	CEdit one;
	CEdit nine;
	CEdit ten;
	CEdit two;
	CEdit trinad;
	CEdit chetarnad;
	CEdit fifteen;
	CEdit sixteen;
	CEdit gen2;
	CListBox res2;
	afx_msg void OnBnClickedButton6();
};
