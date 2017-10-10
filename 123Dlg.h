// 123Dlg.h : header file
//

#if !defined(AFX_123DLG_H__DC4D385A_4875_41FD_9DE0_3B26BB2AF275__INCLUDED_)
#define AFX_123DLG_H__DC4D385A_4875_41FD_9DE0_3B26BB2AF275__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy123Dlg dialog

class CMy123Dlg : public CDialog
{
// Construction
public:
	CMy123Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy123Dlg)
	enum { IDD = IDD_MY123_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy123Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy123Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnOutofmemorySlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOutofmemorySlider3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int n_Pos2;
	int n_Pos1;
	int n_Pos3;
	int n_Pos4;
	CSliderCtrl m_Slider1;
	CSliderCtrl m_Slider2;
	CSliderCtrl m_Slider3;
	CSliderCtrl m_Slider4;
	CButton	m_Radio1;
	CButton	m_Radio2;
	CEdit text;
	int t;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_123DLG_H__DC4D385A_4875_41FD_9DE0_3B26BB2AF275__INCLUDED_)
