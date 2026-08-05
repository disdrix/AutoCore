// =============================================================================
// FUN_00643480
// -----------------------------------------------------------------------------
// Stable ID: aa_00643480
// Address:   0x00643480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00643480 @ 0x00643480
// Stable ID: aa_00643480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00643480, GetCurrentProcess, GetCurrentThread, GetThreadContext.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int FUN_00643480(int param_1,int param_2)



{

  HANDLE pvVar1;

  HANDLE hThread;

  int iVar2;

  int iVar3;

  CONTEXT *pCVar4;

  DWORD *pDVar5;

  DWORD local_380 [6];

  DWORD local_368;

  uint32_t /* width from decompiler */ local_360;

  CONTEXT local_2d8;

  

  pvVar1 = GetCurrentProcess();

  hThread = GetCurrentThread();

  pCVar4 = &local_2d8;

  for (iVar3 = 0xb3; iVar3 != 0; iVar3 = iVar3 + -1) {

    pCVar4->ContextFlags = 0;

    pCVar4 = (CONTEXT *)&pCVar4->Dr0;

  }

  local_2d8.ContextFlags = 0x10007;

  GetThreadContext(hThread,&local_2d8);

  pDVar5 = local_380;

  for (iVar3 = 0x29; iVar3 != 0; iVar3 = iVar3 + -1) {

    *pDVar5 = 0;

    pDVar5 = pDVar5 + 1;

  }

  iVar3 = -1;

  local_380[0] = local_2d8.Eip;

  local_380[2] = 3;

  local_368 = local_2d8.Ebp;

  local_360 = 3;

  if (-1 < param_2) {

    do {

      iVar2 = (*DAT_00d03100)(0x14c,pvVar1,hThread,local_380,&local_2d8,0,DAT_00d030fc,DAT_00d030f8,

                              0);

      if (iVar2 == 0) {

        return iVar3;

      }

      if (-1 < iVar3) {

        *(DWORD *)(param_1 + iVar3 * 4) = local_380[0];

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < param_2);

  }

  return iVar3;

}
