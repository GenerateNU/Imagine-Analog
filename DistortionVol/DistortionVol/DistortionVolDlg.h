#pragma once

#include "resource.h"
#include "FPAA1.h"

class DistortionVolDlg : public CDialog
{
public:
	DistortionVolDlg(CWnd* pParent = NULL);

	enum { IDD = IDD_DISTORTIONVOL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

   // This is used to handle the Enter key when the focus is on an edit control.
   virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

   afx_msg void OnPort();
   afx_msg void OnDownload();
   afx_msg void OnReset();
   afx_msg void OnAbout();

   afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
   afx_msg void OnSampleEditChanged();


private:
   void ConfigureAboutMenu();
   void UpdateSampleControls();

	HICON m_hIcon;
   FPAA1 m_FPAA1;

   CEdit m_sampleEdit;
   CSliderCtrl m_sampleSlider;

   double m_sampleValue;
   double m_sampleMin;
   double m_sampleMax;

	DECLARE_MESSAGE_MAP()
};
