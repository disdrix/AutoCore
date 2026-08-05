// =============================================================================
// FUN_00448ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00448ed0
// Address:   0x00448ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00448ed0 @ 0x00448ed0
// Stable ID: aa_00448ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: EnterCriticalSection×2, LeaveCriticalSection×2, FUN_00448ed0.
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

void __fastcall FUN_00448ed0(int *param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = param_1[1];

  if (iVar2 != 0) {

    if (*(char *)(iVar2 + 0x38) != '\0') {

      EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x20));

    }

    if (*(int *)(iVar2 + 0x10) != 0) {

      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;

    }

    if (*(char *)(iVar2 + 0x38) != '\0') {

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x20));

    }

    iVar2 = param_1[1];

    if (*(char *)(iVar2 + 0x38) != '\0') {

      EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x20));

    }

    iVar3 = *(int *)(iVar2 + 0x10);

    if (*(char *)(iVar2 + 0x38) != '\0') {

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x20));

    }

    if (iVar3 == 0) {

      param_1[1] = 0;

    }

  }

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    piVar1 = param_1 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x00448f4a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*param_1 + 8))();

      return;

    }

  }

  return;

}
