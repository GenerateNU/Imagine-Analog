#include "stdafx.h"
#include "DistortionVol.h"
#include "DistortionVolDlg.h"
#include "DownloadManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// The one and only DistortionVolApp object
DistortionVolApp theApp;

BEGIN_MESSAGE_MAP(DistortionVolApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


DistortionVolApp::DistortionVolApp()
{

}

BOOL DistortionVolApp::InitInstance()
{
	// InitCommonControls() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();

   // Set the key for MFC uses to read\write the registry.  The final location will be
   //   HKEY_CURRENT_USER\Software\YourCompany\DistortionVol\ 
   SetRegistryKey("YourCompany");

   // Read port settings from the registry.
   DownloadManager::Instance()->LoadPortSettings(CString(m_pszRegistryKey) + "\\" + m_pszProfileName);

   // Show the main dialog window
	DistortionVolDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

   // Save port settings to the registry.
   DownloadManager::Instance()->SavePortSettings(CString(m_pszRegistryKey) + "\\" + m_pszProfileName);

   // The window has closed, so we return FALSE here to go ahead and
   // terminate the application.
   return FALSE;
}
