// CFindDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Address.h"
#include "CFindDlg.h"
#include "afxdialogex.h"
#include "MFC_AddressDlg.h"

// CFindDlg 대화 상자

IMPLEMENT_DYNAMIC(CFindDlg, CDialog)

CFindDlg::CFindDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Find_DIALOG, pParent)
	, _username(_T(""))
	, _useraddress(_T(""))
	, _userdigit(_T(""))
	, _userbirth(_T(""))

{
	ParentDlg = (CMFCAddressDlg *)pParent;
}


CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Sort, _Sort);

	DDX_Text(pDX, IDC_FindEDIT, _FindEdit);
	DDX_Text(pDX, IDC_FindName, _username);
	DDX_Text(pDX, IDC_FindAddress, _useraddress);
	DDX_Text(pDX, IDC_FindDigit, _userdigit);
	DDX_Text(pDX, IDC_FindBirth, _userbirth);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	ON_BN_CLICKED(IDC_FindBTN, &CFindDlg::OnBnClickedFindbtn)
END_MESSAGE_MAP()


// CFindDlg 메시지 처리기

void CFindDlg::OnBnClickedFindbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	finduser found;

	UpdateData(TRUE);

	findsort = _Sort.GetCurSel();

	if (_Sort.GetCurSel() == -1)
	{
		MessageBox(TEXT("검색할 대상을 골라주세요."));
		return;
	}
	else
	{
		CString _uname;
		_uname = _FindEdit;

		found = ParentDlg->FindUser(&findsort, &_uname);

		_username = found.name;
		_useraddress = found.address;
		_userdigit = found.digit;
		_userbirth = found.birth;
	}
		
		
	UpdateData(FALSE);
}



BOOL CFindDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	_Sort.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
