//-----------------------------------------------------------------------------
//!\file Main.cpp
//!
//!\date 2008-06-02
//!
//!\brief LoginServer �������
//-----------------------------------------------------------------------------


#include "stdafx.h"
#include "login_server.h"
#include <fstream>


//-----------------------------------------------------------------------------
// main entrance
//-----------------------------------------------------------------------------
INT APIENTRY _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR, INT)
{
	vEngine::InitNetwork();
	vEngine::InitEngine();

#ifdef DEBUG
	_set_se_translator( vEngine::SEH_Translation ); 

	try
	{
#endif
		if (g_login.Init(hInst) == TRUE)
		{
			g_login.Mainloop();
		}
		g_login.Destroy();

#ifdef DEBUG
	}
	catch( vEngine::Exception )
	{		
		ofstream wFileStream;
		wFileStream.open("log\\LoginError_Test2.txt",ios::out|ios::app/*|ios::trunc*/);
		if (wFileStream)
		{
			wFileStream.close();
		}

		throw;
	}
#endif

	vEngine::DestroyEngine();
	vEngine::DestroyNetwork();

	return 0;
}