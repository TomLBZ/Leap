#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{	
	// Application

public:
	/* Application Constructor */
	Application();

	/* Application Deconstructor */
	~Application();

public:
	/* Called to Setup Per-Game Settings */
	VOID SetupPerGameSettings();

	/* Called to Initialize the Application */
	VOID Initialize();

	/* Game Loop - Called on a loop while the Application is running */
	VOID Update();

};