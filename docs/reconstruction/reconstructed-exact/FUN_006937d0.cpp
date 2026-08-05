// =============================================================================
// FUN_006937d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006937d0
// Address:   0x006937d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006937d0 @ 0x006937d0
// Stable ID: aa_006937d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, do×2, return×2.
//  - Notable callees: FUN_00691d80×2, FUN_00691720, FUN_006937d0.
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

void FUN_006937d0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int local_4c;

  int local_48;

  int local_44;

  int local_40;

  uint8_t local_3c [4];

  void *local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aa8e8;

  local_c = ExceptionList;

  iVar1 = (param_3 - param_1) / 0x30;

  iVar2 = (param_2 - param_1) / 0x30;

  iVar5 = iVar2;

  local_4c = iVar1;

  while (iVar3 = iVar5, iVar3 != 0) {

    iVar5 = local_4c % iVar3;

    local_4c = iVar3;

  }

  if ((local_4c < iVar1) && (0 < local_4c)) {

    param_2 = iVar2 * 0x30;

    puVar7 = (uint32_t /* width from decompiler */ *)(local_4c * 0x30 + 0x14 + param_1);

    ExceptionList = &local_c;

    do {

      iVar1 = param_2;

      local_4 = 0xffffffff;

      puVar9 = puVar7 + -5;

      FUN_00691720(puVar7 + -5);

      local_2c = puVar7[-1];

      local_28 = *puVar7;

      local_24 = *(uint8_t *)(puVar7 + 1);

      local_20 = puVar7[2];

      local_1c = puVar7[3];

      local_18 = puVar7[4];

      local_14 = puVar7[5];

      local_10 = puVar7[6];

      iVar1 = iVar1 + -0x14 + (int)puVar7;

      local_4 = 0;

      if (iVar1 == param_3) {

        piVar6 = &param_1;

      }

      else {

        local_48 = iVar1;

        piVar6 = &local_48;

      }

      puVar8 = puVar9;

      puVar4 = (uint32_t /* width from decompiler */ *)*piVar6;

      if ((uint32_t /* width from decompiler */ *)*piVar6 != puVar9) {

        do {

          puVar9 = puVar4;

          FUN_00691d80(puVar9);

          puVar8[4] = puVar9[4];

          puVar8[5] = puVar9[5];

          *(uint8_t *)(puVar8 + 6) = *(uint8_t *)(puVar9 + 6);

          puVar8[7] = puVar9[7];

          puVar8[8] = puVar9[8];

          puVar8[9] = puVar9[9];

          puVar8[10] = puVar9[10];

          puVar8[0xb] = puVar9[0xb];

          iVar1 = (param_3 - (int)puVar9) / 0x30;

          if (iVar2 < iVar1) {

            local_44 = param_2 + (int)puVar9;

            piVar6 = &local_44;

          }

          else {

            local_40 = (iVar2 - iVar1) * 0x30 + param_1;

            piVar6 = &local_40;

          }

          puVar8 = puVar9;

          puVar4 = (uint32_t /* width from decompiler */ *)*piVar6;

        } while ((uint32_t /* width from decompiler */ *)*piVar6 != puVar7 + -5);

      }

      FUN_00691d80(local_3c);

      puVar9[4] = local_2c;

      puVar9[5] = local_28;

      puVar9[7] = local_20;

      *(uint8_t *)(puVar9 + 6) = local_24;

      puVar9[8] = local_1c;

      puVar9[10] = local_14;

      puVar9[9] = local_18;

      puVar9[0xb] = local_10;

      local_4 = 0xffffffff;

      if (local_38 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_38);

      }

      puVar7 = puVar7 + -0xc;

      local_4c = local_4c + -1;

      local_38 = (void *)0x0;

      local_34 = 0;

      local_30 = 0;

    } while (local_4c != 0);

  }

  ExceptionList = local_c;

  return;

}
