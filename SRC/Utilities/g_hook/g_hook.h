#pragma once

class CVMTHookManager
{
public:
	CVMTHookManager(void)
	{
		memset(this, 0, sizeof(CVMTHookManager));
	}

	explicit CVMTHookManager(PDWORD* ppdwClassBase)
	{
		bInitialize(ppdwClassBase);
	}

	~CVMTHookManager(void)
	{
		UnHook();
	}

	bool bInitialize(PDWORD* ppdwClassBase)
	{
		m_ppdwClassBase = ppdwClassBase;
		m_pdwOldVMT = *ppdwClassBase;
		m_dwVMTSize = dwGetVMTCount(*ppdwClassBase);
		m_pdwNewVMT = new DWORD[m_dwVMTSize];
		memcpy(m_pdwNewVMT, m_pdwOldVMT, sizeof(DWORD)* m_dwVMTSize);
		*ppdwClassBase = m_pdwNewVMT;
		return true;
	}

	bool bInitialize(PDWORD** pppdwClassBase)
	{
		return bInitialize(*pppdwClassBase);
	}

	void UnHook(void) const
	{
		if (m_ppdwClassBase)
		{
			*m_ppdwClassBase = m_pdwOldVMT;
		}
	}

	void ReHook(void) const
	{
		if (m_ppdwClassBase)
		{
			*m_ppdwClassBase = m_pdwNewVMT;
		}
	}

	int iGetFuncCount(void) const
	{
		return static_cast<int>(m_dwVMTSize);
	}

	DWORD dwGetMethodAddress(int Index) const
	{
		if (Index >= 0 && Index <= static_cast<int>(m_dwVMTSize) && m_pdwOldVMT != nullptr)
		{
			return m_pdwOldVMT[Index];
		}
		return NULL;
	}

	PDWORD pdwGetOldVMT(void) const
	{
		return m_pdwOldVMT;
	}

	DWORD dwHookMethod(DWORD dwNewFunc, unsigned int iIndex) const
	{
		if (m_pdwNewVMT && m_pdwOldVMT && iIndex <= m_dwVMTSize && iIndex >= 0)
		{
			m_pdwNewVMT[iIndex] = dwNewFunc;
			return m_pdwOldVMT[iIndex];
		}
		return NULL;
	}

private:
	static DWORD dwGetVMTCount(PDWORD pdwVMT)
	{
		DWORD dwIndex = 0;

		for (dwIndex = 0; pdwVMT[dwIndex]; dwIndex++)
		{
			if (IsBadCodePtr(reinterpret_cast<FARPROC>(pdwVMT[dwIndex])))
			{
				break;
			}
		}
		return dwIndex;
	}
	PDWORD*	m_ppdwClassBase;
	PDWORD	m_pdwNewVMT, m_pdwOldVMT;
	DWORD	m_dwVMTSize;
};