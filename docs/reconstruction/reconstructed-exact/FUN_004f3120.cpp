// =============================================================================
// FUN_004f3120
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3120
// Address:   0x004f3120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f3120 @ 0x004f3120
// Stable ID: aa_004f3120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×5, for×4, return×3.
//  - Notable callees: FUN_004f2ec0, FUN_004f3120, free, malloc.
//  - Return sites: 3.

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

int __thiscall FUN_004f3120(int param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ *puVar8;

  

  FUN_004f2ec0(param_2);

  piVar7 = (int *)(param_2 + 0x50);

  piVar1 = (int *)(param_1 + 0x50);

  if (piVar1 == piVar7) {

    return param_1;

  }

  puVar8 = (uint32_t /* width from decompiler */ *)*piVar1;

  puVar2 = (uint32_t /* width from decompiler */ *)*piVar7;

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x54);

  uVar4 = *(int *)(param_1 + 0x54) - (int)puVar8 >> 2;

  uVar5 = (int)puVar3 - (int)puVar2 >> 2;

  if (uVar4 < uVar5) {

    if (puVar8 == (uint32_t /* width from decompiler */ *)0x0) {

      uVar6 = 0;

    }

    else {

      uVar6 = *(int *)(param_1 + 0x58) - (int)puVar8 >> 2;

    }

    if (uVar6 < uVar5) {

      if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

        free(puVar8);

      }

      puVar3 = malloc((*(int *)(param_2 + 0x54) - *piVar7 >> 2) * 4);

      *piVar1 = (int)puVar3;

      puVar8 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x54);

      for (puVar2 = (uint32_t /* width from decompiler */ *)*piVar7; puVar2 != puVar8; puVar2 = puVar2 + 1) {

        *puVar3 = *puVar2;

        puVar3 = puVar3 + 1;

      }

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x54) = puVar3;

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x58) = puVar3;

      return param_1;

    }

    puVar3 = puVar2 + uVar4;

    for (; puVar2 != puVar3; puVar2 = puVar2 + 1) {

      *puVar8 = *puVar2;

      puVar8 = puVar8 + 1;

    }

    puVar8 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x54);

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

    for (; puVar3 != puVar8; puVar3 = puVar3 + 1) {

      *puVar2 = *puVar3;

      puVar2 = puVar2 + 1;

    }

  }

  else {

    for (; puVar2 != puVar3; puVar2 = puVar2 + 1) {

      *puVar8 = *puVar2;

      puVar8 = puVar8 + 1;

    }

  }

  *(int *)(param_1 + 0x54) = *piVar1 + (*(int *)(param_2 + 0x54) - *piVar7 >> 2) * 4;

  return param_1;

}
