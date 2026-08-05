// =============================================================================
// FUN_00656a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00656a20
// Address:   0x00656a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00656a20 @ 0x00656a20
// Stable ID: aa_00656a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_00656690, FUN_00656a20.
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

void __fastcall FUN_00656a20(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  

  puVar3 = operator_new(0x18);

  iVar6 = 0;

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = 0;

    puVar3[1] = 0;

    puVar3[2] = 0x80000000;

    puVar3[3] = 0;

    puVar3[4] = 0;

    puVar3[5] = 0x80000000;

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x50) = puVar3;

  FUN_00656690(puVar3);

  piVar4 = *(int **)(param_1 + 0x50);

  if (piVar4[1] == (piVar4[2] & 0x7fffffffU)) {

    FUN_005b3370(piVar4,0x10);

  }

  iVar2 = piVar4[1];

  piVar4[1] = iVar2 + 1;

  puVar3 = (uint32_t /* width from decompiler */ *)(iVar2 * 0x10 + *piVar4);

  *puVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x80);

  puVar3[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x84);

  puVar3[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x88);

  puVar3[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c);

  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 4);

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 0x9c)) {

    do {

      piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar6);

      iVar1 = iVar5 + 1;

      piVar4[2] = iVar5;

      *piVar4 = iVar2 + -1;

      piVar4[1] = iVar1;

      iVar6 = iVar6 + 0xc;

      iVar5 = iVar1;

    } while (iVar1 < *(int *)(param_1 + 0x9c));

  }

  return;

}
