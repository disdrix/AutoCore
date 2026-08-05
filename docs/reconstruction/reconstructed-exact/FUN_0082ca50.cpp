// =============================================================================
// FUN_0082ca50
// -----------------------------------------------------------------------------
// Stable ID: aa_0082ca50
// Address:   0x0082ca50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082ca50 @ 0x0082ca50
// Stable ID: aa_0082ca50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004113b0×2, FUN_004294f0, FUN_0082ca50, LeaveCriticalSection.
//  - Return sites: 1.

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

void FUN_0082ca50(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = (int)param_1;

  if (param_1 != (int *)0x0) {

    iVar1 = (int)param_1 + 8;

    param_1 = (int *)0x0;

    FUN_004294f0();

    iVar3 = FUN_004113b0(iVar1,&param_1);

    while (iVar3 == 0) {

      (**(code **)(*param_1 + 4))(0);

      iVar3 = FUN_004113b0(iVar1,&param_1);

    }

    if (*(char *)(iVar2 + 0x30) != '\0') {

      *(uint8_t *)(iVar2 + 0x30) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xc));

    }

  }

  return;

}
