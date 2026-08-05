// =============================================================================
// FUN_00918db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00918db0
// Address:   0x00918db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00918db0 @ 0x00918db0
// Stable ID: aa_00918db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: ABS, CONCAT13, CONCAT22, FUN_0076f5f0, FUN_007a0120, FUN_00918db0, ROUND, SQRT.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00918db0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint16_t in_FPUControlWord;

  float10 fVar5;

  float fVar6;

  float local_5c;

  uint32_t /* width from decompiler */ local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float local_20;

  float fStack_1c;

  float fStack_18;

  

  local_5c = (float)CONCAT22(local_5c._2_2_,in_FPUControlWord);

  fVar5 = (float10)fsin((float10)*(float *)(in_EAX + 0xa50));

  local_54 = (float)(int)ROUND(ABS(fVar5) * (float10)_DAT_00aaa9b4);

  local_58 = (float)CONCAT13('f' - SUB41(local_54,0),0xc8c8ff);

  if (*(int *)(in_EAX + 0x60c) == 1) {

    iVar2 = (**(code **)(**(int **)(in_EAX + 0xc70) + 0x24))(&local_20);

    iVar3 = (**(code **)(**(int **)(in_EAX + 0xc70) + 0x24))(&fStack_34);

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(in_EAX + 0xc70) + 0x24))(&local_58);

    local_48 = (float)*puVar4;

    uStack_40 = *(uint32_t /* width from decompiler */ *)(iVar2 + 8);

    uStack_44 = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

    iVar2 = (**(code **)(**(int **)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x48) + 0xc))();

    local_48 = *(float *)(iVar2 + 0x98) - local_54;

    local_4c = *(float *)(iVar2 + 0x94) - local_5c;

    local_50 = *(float *)(iVar2 + 0x90) - fStack_3c;

    fStack_30 = local_50;

    fStack_2c = local_4c;

    fStack_28 = local_48;

  }

  local_54 = local_50 * local_50 + local_4c * local_4c + local_48 * local_48;

  FUN_0076f5f0(&local_50,&local_50);

  uVar1 = local_58;

  iVar2 = 0;

  local_54 = SQRT(local_54) * DAT_00aaa9b0;

  do {

    local_58 = (float)iVar2;

    fVar6 = local_58 * local_54;

    fStack_30 = local_50 * fVar6 + fStack_3c;

    fStack_28 = fStack_34 + local_48 * fVar6;

    fStack_2c = fStack_38 + local_4c * fVar6;

    fVar6 = g_flLevelUpUiBase_Inferred - local_58 * g_flOverheatCoolFrac;

    local_20 = fStack_30;

    fStack_1c = fStack_2c;

    fStack_18 = fStack_28;

    FUN_007a0120(2,2,4,0x1a,0,0,0x3f800000,0,fVar6,fVar6,0,uVar1,uVar1,fStack_30,fStack_2c,fStack_28

                 ,fStack_30,fStack_2c,fStack_28,DAT_00afdfc8,DAT_00afdfcc,DAT_00afdfd0,DAT_00afdfd4,

                 DAT_00afdfd8,DAT_00afdfdc,DAT_00d1a6c0,DAT_00d1a6c4,DAT_00d1a6c8,1);

    iVar2 = iVar2 + 1;

  } while (iVar2 < 6);

  return;

}
