#include "stdafx.h"
#include "FPAA1.h"
#include "DownloadManager.h"
#include "ChipRamHelper.h"

FPAA1::FPAA1()
{
   m_instance = ot_FPAA1;
}

ot_Byte FPAA1::GetDeviceID()
{
   return ot_apiAddress1[m_instance];
}

void FPAA1::ExecutePrimaryConfig(bool Reset)	// Dave Lovell added bool Reset
{
   int dataSize = 0;
	const ot_Byte* data = ot_GetPrimaryConfigData(m_instance, &dataSize);

   //DownloadManager::Instance()->DownloadBits(data, dataSize, false);
	DownloadManager::Instance()->DownloadBits(data, dataSize, Reset);	// Dave Lovell replaced false with Reset
}

void FPAA1::ExecuteReconfig(bool EndExecute)
{
   int dataSize = 0;
   const ot_Byte* data = ot_GetApexReconfigData(m_instance, &dataSize);

   
	//crs 10/3/2007 crs
   if (EndExecute)
	   ot_SetApexReconfigControlFlags(m_instance, ot_ApexControlByte_PUs_UpClks_Ex);
   else
	   ot_SetApexReconfigControlFlags(m_instance, ot_ApexControlByte_PUs_UpClks);
   //crs 10/3/2007 end


   DownloadManager::Instance()->DownloadBits(data, dataSize);

   // Clear the buffer now that its been sent
   ot_ClearApexReconfigData(m_instance);
}

void FPAA1::ExecuteReset()
{
//   int dataSize = 0;						//10/3/2007 comment out
//	const ot_Byte* data = ot_GetResetData(m_instance, &dataSize); //10/3/2007 comment out

   //DownloadManager::Instance()->DownloadBits(data, dataSize); //10/3/2007 comment out
   	DownloadManager::Instance()->ResetChips();    //crs 10/3/2007
}

void FPAA1::AppendFullReconfig()
{
   ChipRamHelper ramHelper;

   int dataSize = 0;
	const ot_Byte* data = ot_GetPrimaryConfigData(m_instance, &dataSize);

   // Load the chip configuration with all the data
   ramHelper.FillRamBanks(data, dataSize);

   // Now get the full reconfiguration stream, all zero's included
   int fullDataSize = 0;
   const ot_Byte* fullData = ramHelper.GetConfigurationData(&fullDataSize);

   // Get the internal C Code reconfig structure
   ot_apiReconfigInfo* pInfo = ot_apiReconfigData[m_instance];

   // Allocate memory in the reconfig stream for the full chip config
   pInfo->data = (ot_Byte*) realloc(pInfo->data, fullDataSize);
   CopyMemory(pInfo->data, fullData, fullDataSize);

   // Manually update the internal reconfig info
   pInfo->capacity = (short) fullDataSize;
   pInfo->length = (short) fullDataSize;
   pInfo->lastUpdateIndex = 331;
}

