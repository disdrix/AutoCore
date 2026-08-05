// =============================================================================
// FUN_0071ddd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071ddd0
// Address:   0x0071ddd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071ddd0 @ 0x0071ddd0
// Stable ID: aa_0071ddd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: CONCAT31×2, FUN_0044cbd0×2, FUN_00767160×2, FUN_00718d10, FUN_0071ddd0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0071ddd0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  uint8_t *puVar4;

  undefined *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  puVar1 = param_2;

  FUN_0044cbd0();

  if (*(int *)(param_1 + 0x14) == 0) {

    param_2 = (uint32_t /* width from decompiler */ *)((uint)param_2._1_3_ << 8);

  }

  else {

    iVar3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);

    param_2 = (uint32_t /* width from decompiler */ *)

              CONCAT31(param_2._1_3_,

                       ((char)(iVar3 / 0xc) + (char)(iVar3 >> 0x1f)) -

                       (char)((longlong)iVar3 * 0x2aaaaaab >> 0x3f));

  }

  FUN_0044cbd0();

  puVar4 = *(uint8_t **)(param_1 + 0x14);

  if (puVar4 != *(uint8_t **)(param_1 + 0x18)) {

    do {

      if (puVar1[7] == 0) {

        uVar7 = 1;

        puVar6 = &param_2;

        param_2 = (uint32_t /* width from decompiler */ *)CONCAT31(param_2._1_3_,*puVar4);

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d718,*puVar4);

        puVar1[1] = puVar1[1] | uVar2;

        uVar7 = 2;

        puVar1[8] = 0;

        puVar6 = (uint32_t /* width from decompiler */ *)&DAT_00a97b84;

      }

      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(puVar6,uVar7);

      puVar1[1] = puVar1[1] | uVar2;

      if (puVar1[7] == 0) {

        uVar7 = 4;

        puVar5 = &stack0xfffffffc;

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d718,*(uint32_t /* width from decompiler */ *)(puVar4 + 4));

        puVar1[1] = puVar1[1] | uVar2;

        uVar7 = 2;

        puVar1[8] = 0;

        puVar5 = &DAT_00a97b84;

      }

      uVar2 = (**(code **)(*(int *)*puVar1 + 0x18))(puVar5,uVar7);

      puVar1[1] = puVar1[1] | uVar2;

      FUN_00718d10(puVar1,*(uint32_t /* width from decompiler */ *)(puVar4 + 8));

      puVar4 = puVar4 + 0xc;

    } while (puVar4 != *(uint8_t **)(param_1 + 0x18));

  }

  return 0;

}
