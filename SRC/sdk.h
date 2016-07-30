#pragma once

/*
****************************
      Dunked-Framework
****************************
*/

static const char* BUILDDATE = __DATE__;
static const char* BUILDTIME = __TIME__;

#define _CRT_SECURE_NO_WARNINGS
#define VC_EXTRALEAN

using byte = unsigned char;

// Windows Includes
#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <process.h>
#include <string>
#include <Psapi.h>

// Namespace
namespace Dunked
{
	extern unsigned int __stdcall Init(void*);
	extern void DeInit();
}

// Local Includes
// Valve Shit
#include "Valve/bspflags.h"
#include "Valve/dt_recv.h"

// Utilities
#include "Utilities/g_utillist.h"

// CUserCmd
struct CUserCmd
{
	byte _pad1[4];
	float command_number;
	float tick_count;
	Vector viewangles;
	float forwardmove;
	float sidemove;
	float upmove;
	int buttons;
	byte _pad2[12];
	int random_seed;
	__int16 mousedx;
	__int16 mousey;
	byte _pad3[288];
};

class CVerifiedUserCmd
{
public:
	CUserCmd m_cmd;
	unsigned int m_crc;
};

class CCMDInput
{
public:
	void*				pvftable;						//0x00
	bool				m_fTrackIRAvailable;			//0x04
	bool				m_fMouseInitialized;			//0x05
	bool				m_fMouseActive;					//0x06
	bool				m_fJoystickAdvancedInit;		//0x07
	char				pad_0x08[0x2C];					//0x08
	void*				m_pKeys;						//0x34
	char				pad_0x38[0x64];					//0x38
	bool				m_fCameraInterceptingMouse;		//0x9C
	bool				m_fCameraInThirdPerson;			//0x9D
	bool				m_fCameraMovingWithMouse;		//0x9E
	Vector				m_vecCameraOffset;				//0xA0
	bool				m_fCameraDistanceMove;			//0xAC
	int					m_nCameraOldX;					//0xB0
	int					m_nCameraOldY;					//0xB4
	int					m_nCameraX;						//0xB8
	int					m_nCameraY;						//0xBC
	bool				m_CameraIsOrthographic;			//0xC0
	Angle				m_angPreviousViewAngles;		//0xC4
	Angle				m_angPreviousViewAnglesTilt;	//0xD0
	float				m_flLastForwardMove;			//0xDC
	int					m_nClearInputState;				//0xE0
	char				pad_0xE4[0x8];					//0xE4
	CUserCmd*			m_pCommands;					//0xEC
	CVerifiedUserCmd*	m_pVerifiedCommands;			//0xF0
};

class IConCommandBaseAccessor;
typedef void* CVarDLLIdentifier_t;

class ConCommandBase
{
	friend class CCvar;
	friend class ConVar;
	friend class ConCommand;
	friend void ConVar_Register(int nCVarFlag, IConCommandBaseAccessor *pAccessor);
	friend void ConVar_PublishToVXConsole();

	// FIXME: Remove when ConVar changes are done
	friend class CDefaultCvar;

public:

	virtual						~ConCommandBase(void) {};
	virtual	bool				IsCommand(void) { return true; };
	// Check flag
	virtual bool				IsFlagSet(int flag) { return (m_nFlags & flag) != 0; }
	// Set flag
	virtual void				AddFlags(int flags) { m_nFlags |= flags; };
	// Return name of cvar
	virtual const char			*GetName(void) const { return m_pszName; };
	// Return help text for cvar
	virtual const char			*GetHelpText(void) const { return m_pszHelpString; };
	virtual bool				IsRegistered(void) const { return m_bRegistered; };
	// Returns the DLL identifier
	virtual CVarDLLIdentifier_t	GetDLLIdentifier() const { return NULL; };

protected:
	virtual void				Create(const char *pName, const char *pHelpString = 0,
		int flags = 0) {};

	// Used internally by OneTimeInit to initialize/shutdown
	virtual void				Init() {};

private:
	ConCommandBase				*m_pNext;
	bool						m_bRegistered;
	const char 					*m_pszName;
	const char 					*m_pszHelpString;
	int							m_nFlags;
};

class CCommand
{
public:
	enum
	{
		COMMAND_MAX_ARGC = 64,
		COMMAND_MAX_LENGTH = 512,
	};

	int		m_nArgc;
	int		m_nArgv0Size;
	char	m_pArgSBuffer[COMMAND_MAX_LENGTH];
	char	m_pArgvBuffer[COMMAND_MAX_LENGTH];
	const char*	m_ppArgv[COMMAND_MAX_ARGC];

};

typedef void(*FnCommandCallbackVoid_t)(void);
typedef void(*FnCommandCallback_t)(const CCommand &command);

#define COMMAND_COMPLETION_MAXITEMS		64
#define COMMAND_COMPLETION_ITEM_LENGTH	64
typedef int(*FnCommandCompletionCallback)(const char *partial, char commands[COMMAND_COMPLETION_MAXITEMS][COMMAND_COMPLETION_ITEM_LENGTH]);

template<class T>
class CUtlVector;
class CUtlString;
class ICommandCallback;
class ICommandCompletionCallback;


class ConCommand : public ConCommandBase
{
	friend class CCvar;

public:
	typedef ConCommandBase BaseClass;

	ConCommand(const char* name) {
		this->m_pszName = name;
	}

	virtual ~ConCommand(void) {};

	virtual	bool IsCommand(void) const { return true; };

	virtual int AutoCompleteSuggest(const char *partial, CUtlVector< CUtlString > &commands) { return 0; };

	virtual bool CanAutoComplete(void) { return false; };

	// Invoke the function
	virtual void Dispatch(const CCommand &command) = 0;

	// NOTE: To maintain backward compat, we have to be very careful:
	// All public virtual methods must appear in the same order always
	// since engine code will be calling into this code, which *does not match*
	// in the mod code; it's using slightly different, but compatible versions
	// of this class. Also: Be very careful about adding new fields to this class.
	// Those fields will not exist in the version of this class that is instanced
	// in mod code.

	// Call this function when executing the command
	union
	{
		FnCommandCallbackVoid_t m_fnCommandCallbackV1;
		FnCommandCallback_t m_fnCommandCallback;
		ICommandCallback *m_pCommandCallback;
	};

	union
	{
		FnCommandCompletionCallback	m_fnCompletionCallback;
		ICommandCompletionCallback *m_pCommandCompletionCallback;
	};

	bool m_bHasCompletionCallback : 1;
	bool m_bUsingNewCommandCallback : 1;
	bool m_bUsingCommandCallbackInterface : 1;
};

// Interfaces
#include "Interfaces/g_interfacelist.h"

