// =============================================================================
// CVOGCreature_UpdateGraphics
// -----------------------------------------------------------------------------
// Stable ID: aa_004c7490
// Address:   0x004c7490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias CVOGCreature_UpdateGraphics for FUN_004c7490 @ 0x004c7490
// Stable ID: aa_004c7490
// Embedded strings (evidence for future rename):
//   - "CVOGCreature::UpdateGraphics"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_0053e0b0×2, CVOGCreature_UpdateGraphics, FUN_004e87d0, FUN_004e8830, FUN_004e8860, FUN_004e88e0, FUN_00567ce0, FUN_005d5360.
//  - Strings: "CVOGCreature::UpdateGraphics".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGCreature::UpdateGraphics"
 * Domain alias of FUN_004c7490 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall CVOGCreature_UpdateGraphics(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  uint32_t /* width from decompiler */ local_7c;

  float local_78;

  uint32_t /* width from decompiler */ local_74;

  float fStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  float fStack_40;

  uint8_t auStack_34 [4];

  uint8_t auStack_30 [20];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a1bff;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_0076cf00("CVOGCreature::UpdateGraphics");

  local_14 = 0;

  FUN_005d5360();

  iVar2 = *(int *)(param_1 + 8);

  if ((iVar2 != 0) && (*(int **)(param_1 + 0x48) != (int *)0x0)) {

    iVar4 = *(int *)(param_1 + 4);

    if (*(int *)(*(int *)(*(int *)(iVar4 + 4) + 0xac + param_1) + 0x38) == 0x12) {

      if (iVar2 == 0) {

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 4) + 0x84 + param_1);

      }

      else {

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x3c) + 0xb0);

      }

      local_7c = *puVar1;

      local_78 = (float)puVar1[1];

      local_74 = puVar1[2];

      if ((*(uint *)(param_1 + 0x200) >> 4 & 1) == 0) {

        local_78 = local_78 -

                   *(float *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 0xac + param_1) + 0x3c) +

                             0x4d4);

      }

      (**(code **)(**(int **)(param_1 + 0x48) + 0x18))(&local_7c);

    }

    if (*(int *)(param_1 + 0x284) != 0) {

      (**(code **)(**(int **)(param_1 + 0x48) + 0x34))();

      FUN_00567ce0(&DAT_00af0c40,*(uint32_t /* width from decompiler */ *)(param_1 + 0x11c));

      iVar2 = (**(code **)(**(int **)(param_1 + 0x280) + 0xc))();

      local_7c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90);

      local_78 = *(float *)(iVar2 + 0x94);

      local_74 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98);

      iVar2 = (**(code **)(**(int **)(param_1 + 0x280) + 0xc))();

      uStack_50 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x80);

      uStack_4c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x84);

      uStack_48 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x88);

      uStack_44 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x8c);

      FUN_004e8860(&uStack_50,&fStack_70);

      fVar7 = fStack_58 * fStack_70;

      fVar6 = fStack_68 * fStack_60;

      fVar8 = fStack_64 * fStack_5c;

      fStack_40 = fStack_54 * fStack_70 +

                  fStack_64 * fStack_60 + (fStack_58 * fStack_6c - fStack_5c * fStack_68);

      fVar5 = fStack_68 * fStack_58;

      fStack_68 = fStack_54 * fStack_68 +

                  fStack_64 * fStack_58 + (fStack_5c * fStack_70 - fStack_6c * fStack_60);

      fStack_64 = fStack_54 * fStack_64 - (fVar5 + fStack_5c * fStack_6c + fStack_70 * fStack_60);

      fStack_70 = fStack_40;

      fStack_6c = fStack_54 * fStack_6c + fVar8 + (fVar6 - fVar7);

      FUN_004e8830(&fStack_70,auStack_30);

      (**(code **)(**(int **)(param_1 + 0x284) + 0x18))(&local_7c);

      (**(code **)(**(int **)(param_1 + 0x284) + 0x14))(auStack_34);

    }

    if (*(int **)(param_1 + 0x27c) != (int *)0x0) {

      iVar2 = **(int **)(param_1 + 0x27c);

      uVar3 = FUN_0053e0b0();

      uVar3 = FUN_004e88e0(&local_7c,uVar3);

      (**(code **)(iVar2 + 0x18))(uVar3);

      if (*(int *)(param_1 + 0x48) != 0) {

        iVar2 = **(int **)(param_1 + 0x27c);

        iVar4 = FUN_0053e0b0();

        uVar3 = FUN_004e87d0(auStack_30,iVar4 + 0x10);

        (**(code **)(iVar2 + 0x14))(uVar3);

      }

    }

  }

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_1c;

  return;

}
