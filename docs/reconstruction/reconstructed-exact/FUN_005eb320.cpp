// =============================================================================
// FUN_005eb320
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb320
// Address:   0x005eb320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005eb320 @ 0x005eb320
// Stable ID: aa_005eb320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×8, while×1, return×1.
//  - Notable callees: FUN_005eb320, FUN_00634450, SQRT.
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

void __thiscall

FUN_005eb320(int param_1,float *param_2,float *param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_78;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float local_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  float fStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  

  *(float *)(param_1 + 0xb0) = *param_2;

  *(float *)(param_1 + 0xb4) = param_2[1];

  *(float *)(param_1 + 0xb8) = param_2[2];

  *(float *)(param_1 + 0xbc) = param_2[3];

  (**(code **)(**(int **)(param_1 + 0xc) + 0x18))

            (param_1 + 0x80,*(float *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8) + param_3[5],

             &local_60);

  fStack_3c = *param_3 - *param_2;

  fStack_38 = param_3[1] - param_2[1];

  fStack_34 = param_3[2] - param_2[2];

  fStack_30 = param_3[3] - param_2[3];

  fVar7 = 0.0;

  if (fStack_3c <= 0.0) {

    fVar7 = fStack_3c;

  }

  fStack_78 = 0.0;

  if (fStack_38 <= 0.0) {

    fStack_78 = fStack_38;

  }

  fVar12 = 0.0;

  if (fStack_34 <= 0.0) {

    fVar12 = fStack_34;

  }

  fVar11 = 0.0;

  if (fStack_30 <= 0.0) {

    fVar11 = fStack_30;

  }

  fVar8 = fStack_3c;

  if (fStack_3c < 0.0) {

    fVar8 = 0.0;

  }

  fVar10 = fStack_38;

  if (fStack_38 < 0.0) {

    fVar10 = 0.0;

  }

  fVar9 = fStack_34;

  if (fStack_34 < 0.0) {

    fVar9 = 0.0;

  }

  fVar6 = 0.0;

  if (0.0 <= fStack_30) {

    fVar6 = fStack_30;

  }

  fStack_6c = fVar7 + fStack_6c;

  fStack_68 = fStack_68 + fStack_78;

  fStack_64 = fStack_64 + fVar12;

  local_60 = local_60 + fVar11;

  fStack_5c = fStack_5c + fVar8;

  fStack_58 = fStack_58 + fVar10;

  fStack_54 = fStack_54 + fVar9;

  fStack_50 = fStack_50 + fVar6;

  FUN_00634450(&fStack_6c);

  puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 8) + 0xcc);

  uStack_4c = *puVar1;

  uStack_48 = puVar1[1];

  fStack_28 = SQRT(fStack_3c * fStack_3c + fStack_38 * fStack_38 + fStack_34 * fStack_34);

  uStack_40 = puVar1[3];

  fStack_44 = param_3[5];

  fStack_2c = param_3[4];

  iVar2 = *(int *)(param_1 + 0xc4);

  iVar3 = *(int *)(*(int *)(param_1 + 8) + 200);

  while (iVar2 = iVar2 + -1, -1 < iVar2) {

    iVar4 = *(int *)(param_1 + 0xc0);

    iVar5 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(iVar4 + iVar2 * 4) + 0x14))();

    (**(code **)(iVar3 + 0x318c + (*(int *)(param_1 + 0x54) * 0x20 + iVar5) * 4))

              (param_1 + 0xc,*(uint32_t /* width from decompiler */ *)(iVar4 + iVar2 * 4),&uStack_4c,param_4,param_5);

  }

  return;

}
