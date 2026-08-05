// =============================================================================
// FUN_00746f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00746f90
// Address:   0x00746f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746f90 @ 0x00746f90
// Stable ID: aa_00746f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00767160×4, CONCAT31×2, FUN_00439870, FUN_00746f90, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint32_t /* width from decompiler */ __fastcall FUN_00746f90(uint32_t /* width from decompiler */ *param_1)



{

  uint uVar1;

  int unaff_EBX;

  int iVar2;

  uint8_t *puStack_30;

  uint uStack_2c;

  uint8_t local_1c [8];

  int local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad890;

  local_c = ExceptionList;

  uStack_2c = 2;

  puStack_30 = (undefined *)0x4445434c;

  ExceptionList = &local_c;

  local_10 = param_1;

  stoChunkWriter_BeginChunk();

  local_4 = 0;

  if (*(int *)(unaff_EBX + 4) == 0) {

    local_14 = 0;

  }

  else {

    local_14 = *(int *)(unaff_EBX + 8) - *(int *)(unaff_EBX + 4) >> 3;

  }

  local_14 = local_14 + -1;

  uStack_2c = 0x746fe6;

  FUN_00439870();

  iVar2 = 0;

  if (0 < local_14) {

    do {

      if (param_1[7] == 0) {

        local_1c[0] = *(uint8_t *)(*(int *)(unaff_EBX + 4) + 4 + iVar2 * 8);

        uStack_2c = 1;

        puStack_30 = local_1c;

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))();

        param_1[1] = param_1[1] | uVar1;

      }

      else {

        uStack_2c = (uint)*(byte *)(*(int *)(unaff_EBX + 4) + 4 + iVar2 * 8);

        puStack_30 = &DAT_00a9d718;

        uVar1 = FUN_00767160();

        param_1[1] = param_1[1] | uVar1;

        uStack_2c = 2;

        puStack_30 = &DAT_00a97b84;

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))();

        param_1[8] = 0;

        param_1[1] = uVar1 | param_1[1];

      }

      if (param_1[7] == 0) {

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&stack0xffffffdc,1);

        param_1[1] = param_1[1] | uVar1;

      }

      else {

        uVar1 = FUN_00767160(&DAT_00a9d718,*(uint8_t *)(*(int *)(unaff_EBX + 4) + 5 + iVar2 * 8))

        ;

        param_1[1] = param_1[1] | uVar1;

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        param_1[1] = uVar1 | param_1[1];

      }

      if (param_1[7] == 0) {

        uStack_2c = CONCAT31(uStack_2c._1_3_,

                             *(uint8_t *)(*(int *)(unaff_EBX + 4) + 6 + iVar2 * 8));

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&uStack_2c,1);

        param_1[1] = param_1[1] | uVar1;

      }

      else {

        uVar1 = FUN_00767160(&DAT_00a9d718,*(uint8_t *)(*(int *)(unaff_EBX + 4) + 6 + iVar2 * 8))

        ;

        param_1[1] = param_1[1] | uVar1;

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        param_1[1] = uVar1 | param_1[1];

      }

      if (param_1[7] == 0) {

        puStack_30 = (uint8_t *)

                     CONCAT31(puStack_30._1_3_,

                              *(uint8_t *)(*(int *)(unaff_EBX + 4) + 7 + iVar2 * 8));

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&puStack_30,1);

        param_1[1] = param_1[1] | uVar1;

      }

      else {

        uVar1 = FUN_00767160(&DAT_00a9d718,*(uint8_t *)(*(int *)(unaff_EBX + 4) + 7 + iVar2 * 8))

        ;

        param_1[1] = param_1[1] | uVar1;

        uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        param_1[1] = uVar1 | param_1[1];

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < local_14);

  }

  local_4 = 0xffffffff;

  uStack_2c = 0x747166;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return 0;

}
