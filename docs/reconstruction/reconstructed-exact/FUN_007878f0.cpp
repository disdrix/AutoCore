// =============================================================================
// FUN_007878f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007878f0
// Address:   0x007878f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007878f0 @ 0x007878f0
// Stable ID: aa_007878f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: for×8, if×4, return×2.
//  - Notable callees: FUN_007878f0.
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

void __thiscall FUN_007878f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int local_8;

  

  iVar1 = param_1[0x401];

  if (0x1000 < (int)(iVar1 + param_3)) {

    uVar5 = param_1[0x403] + iVar1 + param_3;

    local_8 = 0;

    puVar2 = operator_new__(uVar5);

    uVar4 = param_1[0x403];

    if (uVar4 != 0) {

      puVar6 = (uint32_t /* width from decompiler */ *)param_1[0x402];

      puVar7 = puVar2;

      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

      local_8 = param_1[0x403];

    }

    uVar4 = param_1[0x401];

    if (uVar4 != 0) {

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar2 + local_8);

      puVar6 = param_1;

      for (uVar3 = uVar4 >> 2; puVar6 = puVar6 + 1, uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar7 = *puVar6;

        puVar7 = puVar7 + 1;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

      local_8 = local_8 + param_1[0x401];

    }

    puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar2 + local_8);

    for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar6 = *param_2;

      param_2 = param_2 + 1;

      puVar6 = puVar6 + 1;

    }

    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {

      *(uint8_t *)puVar6 = *(uint8_t *)param_2;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    }

    param_1[0x401] = 0;

    if ((void *)param_1[0x402] != (void *)0x0) {

      operator_delete__((void *)param_1[0x402]);

    }

    param_1[0x403] = uVar5;

    param_1[0x402] = puVar2;

    return;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(iVar1 + 4 + (int)param_1);

  for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar2 = *param_2;

    param_2 = param_2 + 1;

    puVar2 = puVar2 + 1;

  }

  for (uVar4 = param_3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *(uint8_t *)puVar2 = *(uint8_t *)param_2;

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

  }

  param_1[0x401] = param_1[0x401] + param_3;

  return;

}
