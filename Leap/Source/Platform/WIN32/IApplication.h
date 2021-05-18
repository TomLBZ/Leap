#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class LEAP_API IApplication
{
	// Application

public:
	/* Application Constructor */
	IApplication();

	/* Application Deconstructor */
	virtual ~IApplication() {};

public:
	/* Called to Setup Per-Game Settings */
	virtual VOID SetupPerGameSettings() = 0;

	/* Called to Initialize the Application */
	virtual VOID Initialize() = 0;

	/* Game Loop - Called on a loop while the Application is running */
	virtual VOID Update() = 0;

};

IApplication* EntryApplication();