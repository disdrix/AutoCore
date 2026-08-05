// =============================================================================
// FUN_005c6430
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6430
// Address:   0x005c6430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c6430 @ 0x005c6430
// Stable ID: aa_005c6430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: for×4, if×2, return×1.
//  - Notable callees: FUN_005c6430.
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

int __thiscall FUN_005c6430(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  uVar1 = *(int *)(param_1 + 4) + param_3;

  if (*(uint *)(param_1 + 8) < uVar1) {

    uVar1 = uVar1 + 0x1000;

    *(uint *)(param_1 + 8) = uVar1;

    puVar2 = operator_new__(uVar1);

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0xc) != (uint32_t /* width from decompiler */ *)0x0) {

      uVar1 = *(uint *)(param_1 + 4);

      puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

      puVar5 = puVar2;

      for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar5 = puVar5 + 1;

      }

      for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

        *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      }

      operator_delete__(*(void **)(param_1 + 0xc));

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xc) = puVar2;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4));

  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

    *puVar2 = *param_2;

    param_2 = param_2 + 1;

    puVar2 = puVar2 + 1;

  }

  for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

    *(uint8_t *)puVar2 = *(uint8_t *)param_2;

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

  }

  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_3;

  return param_1;

}
