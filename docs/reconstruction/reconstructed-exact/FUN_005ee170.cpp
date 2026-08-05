// =============================================================================
// FUN_005ee170
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee170
// Address:   0x005ee170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ee170 @ 0x005ee170
// Stable ID: aa_005ee170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_005ee170, free, malloc.
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

void __thiscall FUN_005ee170(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if ((uint)param_1[2] <= (uint)param_1[1]) {

    iVar2 = *param_1;

    uVar1 = ((param_1[1] - iVar2) / 0xc) * 2 + 2;

    if (iVar2 == 0) {

      uVar5 = 0;

    }

    else {

      uVar5 = (param_1[2] - iVar2) / 0xc;

    }

    if (uVar5 < uVar1) {

      puVar6 = malloc(uVar1 * 0xc);

      puVar3 = (uint32_t /* width from decompiler */ *)param_1[1];

      puVar4 = puVar6;

      for (puVar7 = (uint32_t /* width from decompiler */ *)*param_1; puVar7 != puVar3; puVar7 = puVar7 + 3) {

        *puVar4 = *puVar7;

        puVar4[1] = puVar7[1];

        puVar4[2] = puVar7[2];

        puVar4 = puVar4 + 3;

      }

      if ((void *)*param_1 != (void *)0x0) {

        free((void *)*param_1);

      }

      param_1[2] = (int)(puVar6 + uVar1 * 3);

      param_1[1] = (int)(puVar6 + ((param_1[1] - *param_1) / 0xc) * 3);

      *param_1 = (int)puVar6;

    }

  }

  puVar3 = (uint32_t /* width from decompiler */ *)param_1[1];

  *puVar3 = *param_2;

  puVar3[1] = param_2[1];

  puVar3[2] = param_2[2];

  param_1[1] = param_1[1] + 0xc;

  return;

}
