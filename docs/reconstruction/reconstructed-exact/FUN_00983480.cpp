// =============================================================================
// FUN_00983480
// -----------------------------------------------------------------------------
// Stable ID: aa_00983480
// Address:   0x00983480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983480 @ 0x00983480
// Stable ID: aa_00983480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: EnterCriticalSection, FUN_00983480, LeaveCriticalSection.
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

int FUN_00983480(void)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if (*(char *)(in_EAX + 0x50) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x38));

  }

  iVar2 = 0;

  for (piVar3 = *(int **)(in_EAX + 0x2c); piVar3 != *(int **)(in_EAX + 0x30); piVar3 = piVar3 + 1) {

    iVar1 = *(int *)(*piVar3 + 0x34);

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(*piVar3 + 0x38) - iVar1) / 0x1c;

    }

    iVar2 = iVar2 + iVar1;

  }

  if (*(char *)(in_EAX + 0x50) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x38));

  }

  return iVar2;

}
