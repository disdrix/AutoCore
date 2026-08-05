// =============================================================================
// FUN_0048c020
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c020
// Address:   0x0048c020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048c020 @ 0x0048c020
// Stable ID: aa_0048c020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: for×2, do×1, while×1, if×1, return×1.
//  - Notable callees: FUN_0048c020.
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

int * __thiscall FUN_0048c020(int *param_1,uint *param_2)



{

  uint *puVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  uint uVar5;

  

  puVar1 = param_2;

  do {

    uVar5 = *puVar1;

    puVar1 = (uint *)((int)puVar1 + 1);

  } while ((char)uVar5 != '\0');

  iVar2 = (int)puVar1 - (int)((int)param_2 + 1);

  if (iVar2 == 0) {

    *param_1 = (int)&DAT_00b03504;

  }

  else {

    piVar3 = operator_new(iVar2 + 0xfU & 0xfffffffc);

    *param_1 = (int)piVar3;

    *piVar3 = iVar2;

    *(uint8_t *)(*param_1 + 8 + iVar2) = 0;

    *(int *)(*param_1 + 4) = iVar2;

  }

  uVar5 = *(uint *)*param_1;

  puVar1 = (uint *)*param_1 + 2;

  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar1 = *param_2;

    param_2 = param_2 + 1;

    puVar1 = puVar1 + 1;

  }

  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(char *)puVar1 = (char)*param_2;

    param_2 = (uint *)((int)param_2 + 1);

    puVar1 = (uint *)((int)puVar1 + 1);

  }

  return param_1;

}
