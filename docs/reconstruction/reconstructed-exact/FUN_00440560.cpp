// =============================================================================
// FUN_00440560
// -----------------------------------------------------------------------------
// Stable ID: aa_00440560
// Address:   0x00440560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00440560 @ 0x00440560
// Stable ID: aa_00440560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00440560, FUN_00440b60, FUN_00441230, FUN_004413c0, FUN_00441f20.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00440560(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_2c [4];

  uint8_t local_28 [4];

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  int local_1c;

  uint8_t local_18 [4];

  uint32_t /* width from decompiler */ *local_14;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bf030;

  local_c = ExceptionList;

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar3[1] + 0x1d) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      if ((int)puVar1[3] < *param_2) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar3 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x1d) == '\0');

  }

  if ((puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) && ((int)puVar3[3] <= *param_2)) {

    return puVar3 + 4;

  }

  ExceptionList = &local_c;

  local_24 = FUN_00441f20();

  *(uint8_t *)(local_24 + 0x3d) = 1;

  *(int *)(local_24 + 4) = local_24;

  *(int *)local_24 = local_24;

  *(int *)(local_24 + 8) = local_24;

  local_20 = 0;

  local_4 = 0;

  local_1c = *param_2;

  FUN_00441230(local_18,local_28);

  local_4._0_1_ = 1;

  FUN_00440b60(puVar3);

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_004413c0(local_2c,*local_14,local_14);

                    /* WARNING: Subroutine does not return */

  operator_delete(local_14);

}
