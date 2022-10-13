#include "stdafx.h"
#include "DistortionVol.h"
#include "DistortionVolDlg.h"
#include "AboutDlg.h"
#include "DownloadManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//crs 10/4/2007
#define AUTO_EXEC	1
#define ZERO_CROSS	0
//crs 10/4/2007 end

// Dave Lovell added these defines
#define RESET_FIRST		0
#define NO_RESET		1


BEGIN_MESSAGE_MAP(DistortionVolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED(IDC_PORT, OnPort)
   ON_BN_CLICKED(IDC_ABOUT, OnAbout)
   ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
   ON_BN_CLICKED(IDC_RESET, OnReset)
   ON_WM_HSCROLL()
   ON_EN_KILLFOCUS(IDC_SAMPLE_EDIT, OnSampleEditChanged)

END_MESSAGE_MAP()

DistortionVolDlg::DistortionVolDlg(CWnd* pParent)
	: CDialog(DistortionVolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void DistortionVolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
   DDX_Control(pDX, IDC_SAMPLE_SLIDER, m_sampleSlider);
   DDX_Control(pDX, IDC_SAMPLE_EDIT, m_sampleEdit);
}

BOOL DistortionVolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

   // Setup application icon
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

   // Add the "About..." menu item
   ConfigureAboutMenu();

   // Initialize the sample slider\edit controls
   m_sampleMin = 2.0;
   m_sampleMax = 8.5;
   m_sampleValue = 5.0;

   // The range [0, 100] will be percent.  The slider control cannot use
   // floating point values, so we map [0, 100] on to our desired scale
   // to achieve floating point results.
   m_sampleSlider.SetRange(0, 100);

   // Initial update of the sample controls
   UpdateSampleControls();
	
	// return TRUE  unless you set the focus to a control
   return TRUE;
}

void DistortionVolDlg::ConfigureAboutMenu()
{
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
}

void DistortionVolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		AboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
// to draw the icon.  For MFC applications using the document/view model,
// this is automatically done for you by the framework.
void DistortionVolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
// the minimized window.
HCURSOR DistortionVolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void DistortionVolDlg::OnPort()
{
   DownloadManager::Instance()->ShowPortDlg();
}

void DistortionVolDlg::OnAbout()
{
   AboutDlg dlg;
   dlg.DoModal();
}

void DistortionVolDlg::OnDownload()
{
   m_FPAA1.ExecutePrimaryConfig(RESET_FIRST);
}

void DistortionVolDlg::OnReset()
{
   m_FPAA1.ExecuteReset();
}

void DistortionVolDlg::UpdateSampleControls()
{
   // Map the actual sample value to the range [0, 100] for the slider
   int percent = (int) (100.0 * (m_sampleValue - m_sampleMin) / (m_sampleMax - m_sampleMin));

   // Update the slider position
   m_sampleSlider.SetPos(percent);
   m_sampleSlider.Invalidate();

   // Format the text for the edit control
   CString value;
   value.Format("%.2f Units", m_sampleValue);

   // Update the edit control text
   m_sampleEdit.SetWindowText(value);

   // NOTE: 
   // 
   // This would be the spot to perform C Code updates 
   // based on m_sampleValue.
   //
   // At this point, m_sampleValue holds the value that is 
   // displayed on the sample slider and edit box.
   //
   // To change the range of values of the slider change the
   // following lines found in the OnInitialUpdate function above:
   //
   //   m_sampleMin = 2.0;
   //   m_sampleMax = 8.5;
   //
   // EXAMPLE:
   //
   //   m_chip1.GainHalf1.setGain(m_sampleValue);
   //   m_chip1.ExecuteReconfig(AUTO_EXEC);

}

// This function is used to handle the Enter key when the focus is on
// an edit control.
BOOL DistortionVolDlg::PreTranslateMessage(MSG* pMsg)
{
   bool eatMessage = true;

   if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
   {
      if (GetFocus() == &m_sampleEdit)
      {
         OnSampleEditChanged();
      }
      else
      {
         eatMessage = false;
      }
   }
   else
   {
      eatMessage = false;
   }

   if (eatMessage)
   {
      return true;
   }
   else
   {
      return CDialog::PreTranslateMessage(pMsg);
   }
}

// This function handles ALL horizontal sliders on the window.  If you need
// to handle vertical sliders, that should go in the OnVScroll message handler.
void DistortionVolDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
   // This switch determines which horizontal slider is changing
   switch (pScrollBar->GetDlgCtrlID())
   {
      case IDC_SAMPLE_SLIDER: 
      {
         // Get the current position of the slider
         int percent = ((CSliderCtrl*) pScrollBar)->GetPos();
         
         // Map the percent onto the actual sample value
         m_sampleValue = m_sampleMin + (percent / 100.0) * (m_sampleMax - m_sampleMin);

         // Synchronize the slider and the edit control
         UpdateSampleControls();

         break;
      }

      default:
         // Nothing to do
         break;
   }
   
   CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

// This function is called by MFC when the edit control loses focus.
void DistortionVolDlg::OnSampleEditChanged()
{
   // Get the value in the edit box
   CString text;
   m_sampleEdit.GetWindowText(text);

   // Convert to a double
   m_sampleValue = atof(text);

   // Ensure the value is within the allowable range
   m_sampleValue = max(min(m_sampleValue, m_sampleMax), m_sampleMin);

   // Synchronize the slider and the edit control
   UpdateSampleControls();
}

