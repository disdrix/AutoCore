// =============================================================================
// FUN_0078be90
// -----------------------------------------------------------------------------
// Stable ID: aa_0078be90
// Address:   0x0078be90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078be90 @ 0x0078be90
// Stable ID: aa_0078be90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0078be90, FUN_007a7a70.
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

void __thiscall FUN_0078be90(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  char cVar4;

  

  cVar3 = (**(code **)(*param_1 + 0xd0))();

  cVar4 = (char)param_2;

  if (cVar3 != cVar4) {

    if (param_1[0xa9] != 0) {

      *(char *)(param_1[0xa9] + 400) = cVar4;

    }

    if (param_1[0xab] != 0) {

      iVar2 = *(int *)(param_1[0xab] + 0x8c);

      piVar1 = (int *)(iVar2 + 0xdc);

      *piVar1 = *piVar1 + 1;

      *(char *)(iVar2 + 0xd0) = cVar4;

    }

    if (param_1[0x127] != 0) {

      iVar2 = *(int *)(param_1[0x127] + 0x8c);

      piVar1 = (int *)(iVar2 + 0xdc);

      *piVar1 = *piVar1 + 1;

      *(char *)(iVar2 + 0xd0) = cVar4;

    }

  }

  FUN_007a7a70(param_2);

  return;

}
