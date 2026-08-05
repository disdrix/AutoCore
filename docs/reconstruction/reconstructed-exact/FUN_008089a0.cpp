// =============================================================================
// FUN_008089a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008089a0
// Address:   0x008089a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008089a0 @ 0x008089a0
// Stable ID: aa_008089a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00525cc0, FUN_008089a0.
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

void FUN_008089a0(int param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  int in_EAX;

  

  if (*(char *)(in_EAX + 0x11) != '\0') {

    iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    if ((*(int *)(iVar1 + 0x164 + DAT_00d1b6d8) == *(int *)(in_EAX + 8)) &&

       (*(int *)(iVar1 + 0x168 + DAT_00d1b6d8) == *(int *)(in_EAX + 0xc))) {

      FUN_00525cc0((int)*(char *)(in_EAX + 0x10),0);

    }

    piVar2 = *(int **)(param_1 + 0x10f0);

    if ((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar2 + 0x3d8))(), cVar3 != '\0')) {

      (**(code **)(*piVar2 + 0x448))();

      (**(code **)(*piVar2 + 0x34c))();

    }

  }

  return;

}
