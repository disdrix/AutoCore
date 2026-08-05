// =============================================================================
// FUN_008eb970
// -----------------------------------------------------------------------------
// Stable ID: aa_008eb970
// Address:   0x008eb970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008eb970 @ 0x008eb970
// Stable ID: aa_008eb970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: EnterCriticalSection×2, FUN_0040e490×2, LeaveCriticalSection×2, FUN_0040e230, FUN_008eb970.
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

int * FUN_008eb970(int param_1)



{

  int in_EAX;

  int *piVar1;

  int iVar2;

  int iVar3;

  int *local_8;

  int local_4;

  

  iVar3 = in_EAX + 0x5b0;

  local_8 = (int *)0x0;

  EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x5d8));

  if (*(int *)(in_EAX + 0x5b4) == 0) {

    local_4 = 0;

  }

  else {

    local_4 = *(int *)(*(int *)(in_EAX + 0x5b4) + 4);

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x5d8));

  piVar1 = (int *)FUN_0040e490(iVar3);

  if (piVar1 != (int *)0x0) {

    do {

      iVar2 = (**(code **)(*piVar1 + 0x78))();

      if (iVar2 == param_1) {

        local_8 = piVar1;

      }

      FUN_0040e230(iVar3);

      EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x5d8));

      if (*(int *)(in_EAX + 0x5b4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(*(int *)(in_EAX + 0x5b4) + 4);

      }

      LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x5d8));

    } while ((iVar2 != local_4) && (piVar1 = (int *)FUN_0040e490(iVar3), piVar1 != (int *)0x0));

    return local_8;

  }

  return (int *)0x0;

}
