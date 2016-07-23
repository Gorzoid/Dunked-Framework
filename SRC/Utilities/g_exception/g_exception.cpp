#include "../../sdk.h"

long g_exception::unhandledExceptionFilter(_EXCEPTION_POINTERS* ExceptionInfo)
{
	// Thanks s0beit for this godsend of a debug function

	g_utilList::console->Print("=================================\n");
	g_utilList::console->Print("Dunked-Framework has crashed.\n");
	g_utilList::console->Print("Please Report this to Github.\n");
	g_utilList::console->Print("=================================\n");
	g_utilList::console->Print("Base address: 0x%p\n", _G::hDLLModule);
	g_utilList::console->Print("Exception at address: 0x%p\n", ExceptionInfo->ExceptionRecord->ExceptionAddress);
	g_utilList::console->Print("Last Function Processed: %s\n", _G::szLastFuncSig);
	g_utilList::console->Print("Last Function Decorated Name: %s\n", _G::szLastFuncName);
	g_utilList::console->Print("=================================\n");
	g_utilList::console->Print("Cause Report\n");
	g_utilList::console->Print("=================================\n");

	int m_ExceptionCode = ExceptionInfo->ExceptionRecord->ExceptionCode;
	int m_exceptionInfo_0 = ExceptionInfo->ExceptionRecord->ExceptionInformation[0];
	int m_exceptionInfo_1 = ExceptionInfo->ExceptionRecord->ExceptionInformation[1];
	int m_exceptionInfo_2 = ExceptionInfo->ExceptionRecord->ExceptionInformation[2];
	switch (m_ExceptionCode)
	{
	case EXCEPTION_ACCESS_VIOLATION:
		g_utilList::console->Print("Cause: EXCEPTION_ACCESS_VIOLATION\n");
		if (m_exceptionInfo_0 == 0)
		{
			// bad read
			g_utilList::console->Print("Attempted to read from: 0x%08x\n", m_exceptionInfo_1);
		}
		else if (m_exceptionInfo_0 == 1)
		{
			// bad write
			g_utilList::console->Print("Attempted to write to: 0x%08x\n", m_exceptionInfo_1);
		}
		else if (m_exceptionInfo_0 == 8)
		{
			// user-mode data execution prevention (DEP)
			g_utilList::console->Print("Data Execution Prevention (DEP) at: 0x%08x\n", m_exceptionInfo_1);
		}
		else
		{
			// unknown, shouldn't happen
			g_utilList::console->Print("Unknown access violation at: 0x%08x\n", m_exceptionInfo_1);
		}
		break;

	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
		g_utilList::console->Print("Cause: EXCEPTION_ARRAY_BOUNDS_EXCEEDED\n");
		break;

	case EXCEPTION_BREAKPOINT:
		g_utilList::console->Print("Cause: EXCEPTION_BREAKPOINT\n");
		break;

	case EXCEPTION_DATATYPE_MISALIGNMENT:
		g_utilList::console->Print("Cause: EXCEPTION_DATATYPE_MISALIGNMENT\n");
		break;

	case EXCEPTION_FLT_DENORMAL_OPERAND:
		g_utilList::console->Print("Cause: EXCEPTION_FLT_DENORMAL_OPERAND\n");
		break;

	case EXCEPTION_FLT_DIVIDE_BY_ZERO:
		g_utilList::console->Print("Cause: EXCEPTION_FLT_DIVIDE_BY_ZERO\n");
		break;

	case EXCEPTION_FLT_INEXACT_RESULT:
		g_utilList::console->Print("Cause: EXCEPTION_FLT_INEXACT_RESUL\nT");
		break;

	case EXCEPTION_FLT_INVALID_OPERATION:
		g_utilList::console->Print("Cause: EXCEPTION_FLT_INVALID_OPERATION\n");
		break;

	case EXCEPTION_FLT_OVERFLOW:
		g_utilList::console->Print("Cause: EXCEPTION_FLT_OVERFLOW\n");
		break;

	case EXCEPTION_FLT_STACK_CHECK:
		g_utilList::console->Print("Cause: EXCEPTION_FLT_STACK_CHECK\n");
		break;

	case EXCEPTION_FLT_UNDERFLOW:
		g_utilList::console->Print("Cause: EXCEPTION_FLT_UNDERFLOW\n");
		break;

	case EXCEPTION_ILLEGAL_INSTRUCTION:
		g_utilList::console->Print("Cause: EXCEPTION_ILLEGAL_INSTRUCTION\n");
		break;

	case EXCEPTION_IN_PAGE_ERROR:
		g_utilList::console->Print("Cause: EXCEPTION_IN_PAGE_ERROR\n");
		if (m_exceptionInfo_0 == 0)
		{
			// bad read
			g_utilList::console->Print("Attempted to read from: 0x%08x\n", m_exceptionInfo_1);
		}
		else if (m_exceptionInfo_0 == 1)
		{
			// bad write
			g_utilList::console->Print("Attempted to write to: 0x%08x\n", m_exceptionInfo_1);
		}
		else if (m_exceptionInfo_0 == 8)
		{
			// user-mode data execution prevention (DEP)
			g_utilList::console->Print("Data Execution Prevention (DEP) at: 0x%08x\n", m_exceptionInfo_1);
		}
		else
		{
			// unknown, shouldn't happen
			g_utilList::console->Print("Unknown access violation at: 0x%08x\n", m_exceptionInfo_1);
		}

		// g_utilList::console->Print NTSTATUS
		g_utilList::console->Print("NTSTATUS: 0x%08x\n", m_exceptionInfo_2);

		/*
		NT_SUCCESS(Status)
		Evaluates to TRUE if the return value specified by Status is a success type (0 - 0x3FFFFFFF) or an informational type (0x40000000 - 0x7FFFFFFF).
		NT_INFORMATION(Status)
		Evaluates to TRUE if the return value specified by Status is an informational type (0x40000000 - 0x7FFFFFFF).
		NT_WARNING(Status)
		Evaluates to TRUE if the return value specified by Status is a warning type (0x80000000 - 0xBFFFFFFF).
		NT_ERROR(Status)
		Evaluates to TRUE if the return value specified by Status is an error type (0xC0000000 - 0xFFFFFFFF)
		*/
		break;

	case EXCEPTION_INT_DIVIDE_BY_ZERO:
		g_utilList::console->Print("Cause: EXCEPTION_INT_DIVIDE_BY_ZERO");
		break;

	case EXCEPTION_INT_OVERFLOW:
		g_utilList::console->Print("Cause: EXCEPTION_INT_OVERFLOW");
		break;

	case EXCEPTION_INVALID_DISPOSITION:
		g_utilList::console->Print("Cause: EXCEPTION_INVALID_DISPOSITION");
		break;

	case EXCEPTION_NONCONTINUABLE_EXCEPTION:
		g_utilList::console->Print("Cause: EXCEPTION_NONCONTINUABLE_EXCEPTION");
		break;

	case EXCEPTION_PRIV_INSTRUCTION:
		g_utilList::console->Print("Cause: EXCEPTION_PRIV_INSTRUCTION");
		break;

	case EXCEPTION_SINGLE_STEP:
		g_utilList::console->Print("Cause: EXCEPTION_SINGLE_STEP");
		break;

	case EXCEPTION_STACK_OVERFLOW:
		g_utilList::console->Print("Cause: EXCEPTION_STACK_OVERFLOW");
		break;

	case DBG_CONTROL_C:
		g_utilList::console->Print("Cause: DBG_CONTROL_C (WTF!)");
		break;

	default:
		g_utilList::console->Print("Cause: %08x", m_ExceptionCode);
	}

	g_utilList::console->Print("=================================\n");
	g_utilList::console->Print("DATA DUMP\n");
	g_utilList::console->Print("=================================\n");

	g_utilList::console->Print("EAX: 0x%08x || ESI: 0x%08x\n", ExceptionInfo->ContextRecord->Eax, ExceptionInfo->ContextRecord->Esi);
	g_utilList::console->Print("EBX: 0x%08x || EDI: 0x%08\nx", ExceptionInfo->ContextRecord->Ebx, ExceptionInfo->ContextRecord->Edi);
	g_utilList::console->Print("ECX: 0x%08x || EBP: 0x%08x\n", ExceptionInfo->ContextRecord->Ecx, ExceptionInfo->ContextRecord->Ebp);
	g_utilList::console->Print("EDX: 0x%08x || ESP: 0x%08x\n", ExceptionInfo->ContextRecord->Edx, ExceptionInfo->ContextRecord->Esp);

	g_utilList::console->Print("=================================\n");

	return EXCEPTION_CONTINUE_SEARCH;
}

void g_exception::traceLastFunction(const char* szFuncSig, const char* szFuncName)
{
	_G::szLastFuncSig = szFuncSig;
	_G::szLastFuncName = szFuncName;
}


g_exception* g_utilList::exception = new g_exception;