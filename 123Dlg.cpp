// 123Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "123.h"
#include "123Dlg.h"
#include <afx.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 3.1415926
#define BO double[10240]
float fl[20482]; 

/*afx_msg void OnCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult); 
afx_msg void OnCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult); 
afx_msg void OnCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult); 
afx_msg void OnCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult); */
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
	//滑块
	//ON_NOTIFY(NM_CUSTOMDRAW,IDC_SLIDER2,OnCustomdrawSlider2)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy123Dlg dialog

CMy123Dlg::CMy123Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy123Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy123Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy123Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy123Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX,IDC_SLIDER2,m_Slider1);
	DDX_Control(pDX,IDC_SLIDER3,m_Slider2);
	DDX_Control(pDX,IDC_SLIDER4,m_Slider3);
	DDX_Control(pDX,IDC_SLIDER5,m_Slider4);
	DDX_Control(pDX, IDC_RADIO2, m_Radio2);
	DDX_Control(pDX, IDC_RADIO1, m_Radio1);
	DDX_Control(pDX, IDC_EDIT1, text);
}

BEGIN_MESSAGE_MAP(CMy123Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy123Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER2, OnOutofmemorySlider2)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER3, OnOutofmemorySlider3)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, OnReleasedcaptureSlider2)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy123Dlg message handlers

BOOL CMy123Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_Slider1.SetRange(0,1200);
	m_Slider2.SetRange(0,420);
	m_Slider3.SetRange(1,9);
	m_Slider4.SetRange(0,400);
	m_Slider1.SetPos(0);
	m_Slider2.SetPos(0);
	m_Slider3.SetPos(5);
	m_Slider4.SetPos(200);
	n_Pos1=0;
	n_Pos2=0;
	n_Pos3=5;
	n_Pos4=200;
	m_Radio1.SetCheck(TRUE);
	t=0;
	CWnd *m_pMainWnd; 
	m_pMainWnd = AfxGetMainWnd(); 
	m_pMainWnd->SetWindowText(_T("假如我是张路"));
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy123Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy123Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
	}
		CClientDC dc(this);
		CRect rect;
		GetClientRect(rect); 
		CBrush brush(RGB(0,0,0));//黑画刷
		CPen pen(PS_SOLID,1,RGB(255,255,255));//画笔
		CPen gpen(PS_SOLID,1,RGB(0,255,0));//绿
		CPen rpen(PS_DASH,1,RGB(255,0,0));//红
		CString s,sxl;
		double d,xl;
		int i,l;
		CDialog::OnPaint();

		/*xl=0;
		for(i=1;i<=100;i++)
		{
			if(fl[i]<fl[i-1])
				xl++;
		}
		sxl.Format("%.0f",xl);
		text.SetWindowText(sxl);*/

		dc.SelectObject(&brush);
		dc.Rectangle(0,0,540,500);
		dc.SelectObject(&pen);
		for(i=0;i<11;i++) //x
		{
			MoveToEx(dc,30,20+42*i,NULL);//1,9  0,400
			LineTo(dc,480,20+42*i);
			l=n_Pos3;
			if(l>=5)
			{
				l=1/(l-4);
			}
			else
			{
				l=6-l;
			}
			d=(1300-35*i+n_Pos4)/(l+0.01);
			s.Format(_T("%.0f"),d);//y坐标
			TextOut(dc,0,20+42*i,s,s.GetLength());
		}
		for(i=0;i<11;i++) //y
		{
			MoveToEx(dc,30+i*45,20,NULL);
			LineTo(dc,30+i*45,440);  //(255,230)
			d=0.45*i+(double)(n_Pos1)/450;
			s.Format(_T("%.2f"),d);   //x坐标
			TextOut(dc,25+i*45,450,s,s.GetLength());  //1200
		}
	
}
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy123Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy123Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg( TRUE , NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
                 _T("TXT Files(*.txt)|*.txt||"),AfxGetMainWnd());
	CString strPath;
	CString strRead;
	CString a;
	CStdioFile mfile;
	int i=0;
	float f;
	if(dlg.DoModal() == IDOK)
	{
		strPath=dlg.GetPathName();//取得文件路径
	}
	if(mfile.Open(strPath,CFile::modeRead))
	{
		while(mfile.ReadString(strRead))
		{
			f = _wtof(strRead.GetBuffer());
			fl[i++]=f;
			//a.Format("%f",fl[i-1]);
			//MessageBox(a);
			//if(i==11) break;
		}
	}
	else
	{
		MessageBox(_T("fail"));
	}
	Invalidate();
    mfile.Close();
	SetTimer(1,10,NULL);
}

void CMy123Dlg::OnOutofmemorySlider2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CMy123Dlg::OnOutofmemorySlider3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CMy123Dlg::OnReleasedcaptureSlider2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//DEL void CMy123Dlg::OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult) 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 
//DEL 	*pResult = 0;
//DEL }

//DEL void CMy123Dlg::OnCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult) 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	*pResult = 0;
//DEL }

//DEL void CMy123Dlg::OnCustomdrawSlider4(NMHDR* pNMHDR, LRESULT* pResult) 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 
//DEL 	*pResult = 0;
//DEL }

//DEL void CMy123Dlg::OnCustomdrawSlider5(NMHDR* pNMHDR, LRESULT* pResult) 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 
//DEL 	*pResult = 0;
//DEL }

//DEL void CMy123Dlg::OnLButtonUp(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	CDialog::OnLButtonUp(nFlags, point);
//DEL }


void CMy123Dlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	n_Pos3=m_Slider3.GetPos();
	n_Pos4=m_Slider4.GetPos();
	Invalidate();
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CMy123Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) //横
{
	// TODO: Add your message handler code here and/or call default
	n_Pos1=m_Slider1.GetPos();
	n_Pos2=m_Slider2.GetPos();
	/*CString str="";
	str.Format("%d%%",n_Pos1);
	SetDlgItemText(IDC_EDIT1,str);
	n_Pos2=m_Slider2.GetPos();*/
	Invalidate();
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMy123Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CBrush brush(RGB(0,0,0));
	CPen gpen(PS_SOLID,1,RGB(0,255,0));
	CPen rpen(PS_SOLID,1,RGB(255,0,0));
	int i;
	double l=1,y,xl;
	CString sxl;
	CClientDC dc(this);
	dc.SelectObject(&rpen);

	MoveToEx(dc,30+n_Pos2,20,NULL);
	LineTo(dc,30+n_Pos2,440);//红线
	
	for(xl=0,i=1+(t+n_Pos1*10);i<=(t+n_Pos1*10)+160;i++) //计算心率
		{
			if(fl[i]<fl[i-1])
				xl++;
		}

	sxl.Format(_T("%.0f"),xl);

	text.SetWindowText(sxl);
	

	dc.SetViewportOrg(30,272+n_Pos4-200); //定义逻辑坐标
	
	MoveToEx(dc,0,0,NULL);
	dc.SelectObject(&gpen);
	if(m_Radio1.GetCheck()==1)
	{
	
		for(i=0;i<450;i++)
		{
			//MoveToEx(dc,i,-(int)fl[i]/10,NULL);
			l=n_Pos3;
			if(l>=5)
			{
				l=1/(l-4);
			}
			else
			{
				l=6-l;
			}
			y=(int)((fl[(i+n_Pos1)*10]-1000)*l);
			LineTo(dc,i,-y);
			if(n_Pos2==i)
			{
				dc.SelectObject(&rpen);
				dc.Ellipse(i-4,-y-4,i+4,-y+4);//dian
				dc.SelectObject(&gpen);
			}
			
		}
	}
	if(m_Radio2.GetCheck()==1)
	{
		t++;
		for(i=0;i<450;i++)
		{
			//MoveToEx(dc,i,-(int)fl[i]/10,NULL);
			l=n_Pos3;
			if(l>=5)
			{
				l=1/(l-4);
			}
			else
			{
				l=6-l;
			}
			y=(int)((fl[(i+n_Pos1+t)*10]-1000)*l);
			LineTo(dc,i,-y);
				if(n_Pos2==i)
			{
				dc.SelectObject(&rpen);
				dc.Ellipse(i-4,-y-4,i+4,-y+4);//dian
				dc.SelectObject(&gpen);
			}
			Invalidate(FALSE);
		}
	}
	
	
	CDialog::OnTimer(nIDEvent);
}

void CMy123Dlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here

}


void CMy123Dlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,10,NULL);
}
