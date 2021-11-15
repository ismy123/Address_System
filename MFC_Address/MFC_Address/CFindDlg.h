#pragma once
// CFindDlg 대화 상자

class CMFCAddressDlg;

class CFindDlg : public CDialog
{
	DECLARE_DYNAMIC(CFindDlg)

public:
	CFindDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CFindDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Find_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox _Sort;
	afx_msg void OnBnClickedFindbtn();

	CMFCAddressDlg *ParentDlg;

	CString _FindEdit;

	CString _username;
	CString _useraddress;
	CString _userdigit;
	CString _userbirth;
	int findsort;
	virtual BOOL OnInitDialog();
};
