
// MFCApplication1Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <random>
#include<math.h>
#pragma once

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	static bool IsAllNumeric(const CString& str);
	bool IsNumeric(const CString& str);
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT5, Five);
	DDX_Control(pDX, IDC_EDIT6, Six);
	DDX_Control(pDX, IDC_EDIT7, Seven);
	DDX_Control(pDX, IDC_EDIT8, Eight);
	DDX_Control(pDX, IDC_EDIT3, Three);
	DDX_Control(pDX, IDC_LIST3, Result1);
	DDX_Control(pDX, IDC_EDIT11, Eleven);
	DDX_Control(pDX, IDC_EDIT12, twelwe);
	DDX_Control(pDX, IDC_EDIT1, one);
	DDX_Control(pDX, IDC_EDIT9, nine);
	DDX_Control(pDX, IDC_EDIT10, ten);
	DDX_Control(pDX, IDC_EDIT2, two);
	DDX_Control(pDX, IDC_EDIT13, trinad);
	DDX_Control(pDX, IDC_EDIT14, chetarnad);
	DDX_Control(pDX, IDC_EDIT15, fifteen);
	DDX_Control(pDX, IDC_EDIT16, sixteen);
	DDX_Control(pDX, IDC_EDIT4, gen2);
	DDX_Control(pDX, IDC_LIST2, res2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


double f(double x, double y) {
	// Здесь вы можете определить свою собственную функцию
	return (x * y) / (sin(x) + 1);
}

// Вспомогательная функция для проверки, что строка содержит числовое значение
bool CMFCApplication1Dlg::IsNumeric(const CString& str)
{
	TCHAR* end;
	_tcstod(str, &end);
	return end != str;
}

void CMFCApplication1Dlg::OnBnClickedButton5()
{
	CString strXMax, strXMin, strYMax, strYMin, strNumPoints;
	GetDlgItemText(IDC_EDIT5, strXMax);
	GetDlgItemText(IDC_EDIT6, strXMin);
	GetDlgItemText(IDC_EDIT7, strYMax);
	GetDlgItemText(IDC_EDIT8, strYMin);
	GetDlgItemText(IDC_EDIT3, strNumPoints);

	if (strXMax.IsEmpty() || strXMin.IsEmpty() || strYMax.IsEmpty() || strYMin.IsEmpty() || strNumPoints.IsEmpty()) {
		MessageBox(L"Поле ввода пустое!", L"Ошибка", MB_OK | MB_ICONERROR);
		return; // Останавливаем выполнение кода здесь
	}

	double f(double x, double y);
	double xMin, xMax, yMin, yMax;
	int numPoints;
	CArray<double, double> xValues;
	CArray<double, double> yValues;
	double area;


	xMin = _ttof(strXMin);
	xMax = _ttof(strXMax);
	yMin = _ttof(strYMin);
	yMax = _ttof(strYMax);
	numPoints = _ttoi(strNumPoints);

	// Проверяем, что введенные значения являются числами
	if (!IsNumeric(strXMin) || !IsNumeric(strXMax) || !IsNumeric(strYMin) || !IsNumeric(strYMax) || !IsNumeric(strNumPoints)) {
		MessageBox(L"Поля ввода должны содержать числовые значения!", L"Ошибка", MB_OK | MB_ICONERROR);
		return; // Останавливаем выполнение кода здесь
	}

	// Проверяем, что количество точек не превышает миллион
	if (numPoints > 100000000) {
		MessageBox(L"Количество точек не может превышать 1 миллион!", L"Ошибка", MB_OK | MB_ICONERROR);
		return; // Останавливаем выполнение кода здесь
	}

	xValues.SetSize(numPoints);
	yValues.SetSize(numPoints);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> xDist(xMin, xMax);
	std::uniform_real_distribution<double> yDist(yMin, yMax);

	for (int i = 0; i < numPoints; ++i) {
		xValues[i] = xDist(gen);
		yValues[i] = yDist(gen);
	}

	double sum = 0.0;
	for (int i = 0; i < numPoints; ++i) {
		sum += f(xValues[i], yValues[i]);
	}

	double xRange = xMax - xMin;
	double yRange = yMax - yMin;
	area = sum * (xRange * yRange) / numPoints;

	CString strArea;
	strArea.Format(_T(" %.3f"), area);

	// Получаем указатель на список
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST3);
	if (pListBox)
	{
		// Добавляем строку в список
		pListBox->AddString(strArea);

		// Или устанавливаем выбранный элемент
		// pListBox->SetCurSel(index);
	}
}



double n(double x, double y, double z, double q, double w) {
	// Здесь вы можете определить свою собственную функцию
	return sqrt(x*y*z*q*w)/(sin(x)+1);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{

	CString strXMax, strXMin, strYMax, strYMin, strNumPoints, strZMax, strZMin, strQMax, strQMin, strWMax, strWMin;
	GetDlgItemText(IDC_EDIT11, strXMax);
	GetDlgItemText(IDC_EDIT12, strXMin);
	GetDlgItemText(IDC_EDIT1, strYMax);
	GetDlgItemText(IDC_EDIT9, strYMin);
	GetDlgItemText(IDC_EDIT10, strZMax);
	GetDlgItemText(IDC_EDIT2, strZMin);
	GetDlgItemText(IDC_EDIT13, strQMax);
	GetDlgItemText(IDC_EDIT14, strQMin);
	GetDlgItemText(IDC_EDIT15, strWMax);
	GetDlgItemText(IDC_EDIT16, strWMin);
	GetDlgItemText(IDC_EDIT4, strNumPoints);

	if (strXMax.IsEmpty() || strXMin.IsEmpty() || strYMax.IsEmpty() || strYMin.IsEmpty() || strNumPoints.IsEmpty()
		|| strZMax.IsEmpty() || strZMin.IsEmpty() || strQMax.IsEmpty() || strQMin.IsEmpty() || strWMax.IsEmpty()
		|| strWMin.IsEmpty())
	{
		MessageBox(L"Поле ввода пустое!", L"Ошибка", MB_OK | MB_ICONERROR);
		return; // Останавливаем выполнение кода здесь
	}

	// Проверяем, что введенные значения являются числами
	if (!IsNumeric(strXMax) || !IsNumeric(strXMin) || !IsNumeric(strYMax) ||
		!IsNumeric(strYMin) || !IsNumeric(strNumPoints) ||
		!IsNumeric(strZMax) || !IsNumeric(strZMin) || !IsNumeric(strQMax) || !IsNumeric(strQMin)
		|| !IsNumeric(strWMax) || !IsNumeric(strWMin)) 
	{
		MessageBox(L"Поля ввода должны содержать числовые значения!", L"Ошибка", MB_OK | MB_ICONERROR);
		return; // Останавливаем выполнение кода здесь
	}


	double n(double x, double y, double z, double q, double w);
	double xMin, xMax, yMin, yMax, zMin, zMax, qMin, qMax, wMin, wMax;
	int numPoints;
	CArray<double, double> xValues;
	CArray<double, double> yValues;
	CArray<double, double> zValues;
	CArray<double, double> qValues;
	CArray<double, double> wValues;

	double area;


	xMin = _ttof(strXMin);
	xMax = _ttof(strXMax);
	yMin = _ttof(strYMin);
	yMax = _ttof(strYMax);
	zMin = _ttof(strZMin);
	zMax = _ttof(strZMax);
	qMin = _ttof(strQMin);
	qMax = _ttof(strQMax);
	wMin = _ttof(strWMin);
	wMax = _ttof(strWMax);
	numPoints = _ttoi(strNumPoints);

	// Проверяем, что количество точек не превышает миллион
	if (numPoints > 100000000) {
		MessageBox(L"Количество точек не может превышать 1 миллион!", L"Ошибка", MB_OK | MB_ICONERROR);
		return; // Останавливаем выполнение кода здесь
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> x1Dist(xMin, xMax);
	std::uniform_real_distribution<double> y1Dist(yMin, yMax);
	std::uniform_real_distribution<double> z1Dist(zMin, zMax);
	std::uniform_real_distribution<double> q1Dist(qMin, qMax);
	std::uniform_real_distribution<double> w1Dist(wMin, wMax);

	std::vector<double> x1Values(numPoints);
	std::vector<double> y1Values(numPoints);
	std::vector<double> z1Values(numPoints);
	std::vector<double> q1Values(numPoints);
	std::vector<double> w1Values(numPoints);

	for (int i = 0; i < numPoints; ++i) {
		x1Values[i] = x1Dist(gen);
		y1Values[i] = y1Dist(gen);
		z1Values[i] = z1Dist(gen);
		q1Values[i] = q1Dist(gen);
		w1Values[i] = w1Dist(gen);
	}

	// Вычисление значения подинтегральной функции для каждой точки и суммирование
	double sum = 0.0;
	for (int i = 0; i < numPoints; ++i) {
		sum += n(x1Values[i], y1Values[i], z1Values[i], q1Values[i], w1Values[i]);
	}

	// Вычисление объема интеграла
	double xRange = xMax - xMin;
	double yRange = yMax - yMin;
	double zRange = zMax - zMin;
	double wRange = qMax - qMin;
	double vRange = wMax - wMin;
	area = sum * (xRange * yRange * zRange * wRange * vRange) / numPoints;

	CString strArea;
	strArea.Format(_T(" %.3f"), area);

	// Получаем указатель на список
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST2);
	if (pListBox)
	{
		// Добавляем строку в список
		pListBox->AddString(strArea);

		// Или устанавливаем выбранный элемент
		// pListBox->SetCurSel(index);
	}
}

void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// Генерация уникального имени файла
	SYSTEMTIME st;//Получения даты 
	GetLocalTime(&st);//Получаем время
	CString defaultFileName;
	defaultFileName.Format((L"screenshot %04d-%02d-%02d %02d.%02d.%02d.bmp"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

	// Создание структуры для диалога выбора сохранения файла
	CFileDialog dlg(FALSE, (L"bmp"), defaultFileName, OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST, (L"Bitmap Files (*.bmp)|*.bmp||"), this);

	// Открытие диалога выбора файла
	if (dlg.DoModal() == IDOK)
	{
		// Получение выбранного пути и имени файла
		CString filePath = dlg.GetPathName();

		// Получение контекста устройства для диалогового окна
		CDC* pDC = GetDC();

		// Получение размеров диалогового окна
		CRect rect;
		GetClientRect(&rect);
		// Создание совместимого контекста устройства
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		// Создание битмапа
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		// Выбор битмапа в контексте устройства
		CBitmap* pOldBmp = memDC.SelectObject(&bmp);
		// Копирование содержимого диалогового окна в битмап
		memDC.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);
		// Создание объекта CImage и загрузка битмапа
		CImage image;
		image.Attach(bmp);
		// Сохранение битмапа в выбранном файле
		image.Save(filePath);
		// Освобождение ресурсов
		image.Detach();
		memDC.SelectObject(pOldBmp);
		ReleaseDC(pDC);
		// Отображение сообщения с выбранным путем сохранения файла
		CString message;
		message.Format((L"Картинка сохранена по пути:\n\n%s"), filePath);
		MessageBox(message, (L"Создание картинки"), MB_OK);
		}
}
