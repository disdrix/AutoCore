// =============================================================================
// FUN_00972460
// -----------------------------------------------------------------------------
// Stable ID: aa_00972460
// Address:   0x00972460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00972460 @ 0x00972460
// Stable ID: aa_00972460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, while×1, if×1.
//  - Notable callees: ExitThread, FUN_00972140, FUN_00972460, InterlockedIncrement, WaitForSingleObject.
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

void __fastcall FUN_00972460(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0xc);

  InterlockedIncrement((LONG *)(iVar1 + 0xc));

  do {

    FUN_00972140(iVar1);

    WaitForSingleObject(*(HANDLE *)(iVar1 + 4),0xffffffff);

  } while (0 < *(LONG *)(iVar1 + 0xc));

  if (*(int *)(param_1 + 8) != 0) {

                    /* WARNING: Subroutine does not return */

    ExitThread(0);

  }

  return;

}
