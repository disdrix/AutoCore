// =============================================================================
// FUN_006efd90
// -----------------------------------------------------------------------------
// Stable ID: aa_006efd90
// Address:   0x006efd90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006efd90 @ 0x006efd90
// Stable ID: aa_006efd90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3370×2, FUN_006cde50, FUN_006efd90.
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

void __thiscall FUN_006efd90(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  iVar1 = param_2;

  FUN_006cde50(param_2);

  if (0 < *(int *)(param_1 + 0x14)) {

    piVar4 = (int *)(param_2 + 4);

    iVar3 = 0;

    param_2 = *(int *)(param_1 + 0x14);

    do {

      puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + iVar3);

      if (*(uint *)(iVar1 + 8) == (*(uint *)(iVar1 + 0xc) & 0x7fffffff)) {

        FUN_005b3370(piVar4,0x10);

      }

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) * 0x10 + *piVar4);

      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;

      *puVar2 = *puVar5;

      puVar2[1] = puVar5[1];

      puVar2[2] = puVar5[2];

      puVar2[3] = puVar5[3];

      puVar5 = (uint32_t /* width from decompiler */ *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10));

      if (*(uint *)(iVar1 + 8) == (*(uint *)(iVar1 + 0xc) & 0x7fffffff)) {

        FUN_005b3370(piVar4,0x10);

      }

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) * 0x10 + *piVar4);

      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;

      *puVar2 = *puVar5;

      puVar2[1] = puVar5[1];

      puVar2[2] = puVar5[2];

      puVar2[3] = puVar5[3];

      iVar3 = iVar3 + 0x20;

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  return;

}
