// =============================================================================
// FUN_0072b9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b9b0
// Address:   0x0072b9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b9b0 @ 0x0072b9b0
// Stable ID: aa_0072b9b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: block×3, FUN_0043a1d0, FUN_00456960, FUN_0072b710, FUN_0072b9b0.
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

/* WARNING: Removing unreachable block (ram,0x0072bbff) */

/* WARNING: Removing unreachable block (ram,0x0072bc13) */

/* WARNING: Removing unreachable block (ram,0x0072bc81) */



void __thiscall FUN_0072b9b0(float *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  char cVar6;

  float *pfVar7;

  uint32_t /* width from decompiler */ *puVar8;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad4bf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pfVar7 = operator_new(0x3c);

  if (pfVar7 == (float *)0x0) {

    pfVar7 = (float *)0x0;

  }

  else {

    fVar1 = param_1[3];

    fVar2 = param_1[4];

    fVar3 = param_1[5];

    fVar4 = *param_1;

    *pfVar7 = fVar4;

    pfVar7[1] = fVar3;

    pfVar7[3] = fVar1;

    pfVar7[2] = fVar2;

    fVar5 = DAT_00a0f298;

    pfVar7[4] = (fVar4 + fVar2) * DAT_00a0f298;

    pfVar7[5] = (fVar3 + fVar1) * fVar5;

    pfVar7[6] = 1.4013e-45;

    pfVar7[7] = 0.0;

    pfVar7[8] = 0.0;

    pfVar7[9] = 0.0;

    pfVar7[10] = 0.0;

    pfVar7[0xc] = 0.0;

    pfVar7[0xd] = 0.0;

    pfVar7[0xe] = 0.0;

  }

  local_4 = 0xffffffff;

  param_1[7] = (float)pfVar7;

  pfVar7 = operator_new(0x3c);

  if (pfVar7 == (float *)0x0) {

    pfVar7 = (float *)0x0;

  }

  else {

    fVar1 = param_1[3];

    fVar2 = param_1[2];

    fVar3 = param_1[5];

    fVar4 = param_1[4];

    *pfVar7 = fVar4;

    pfVar7[1] = fVar3;

    pfVar7[3] = fVar1;

    pfVar7[2] = fVar2;

    fVar5 = DAT_00a0f298;

    pfVar7[4] = (fVar4 + fVar2) * DAT_00a0f298;

    pfVar7[5] = (fVar3 + fVar1) * fVar5;

    pfVar7[6] = 1.4013e-45;

    pfVar7[7] = 0.0;

    pfVar7[8] = 0.0;

    pfVar7[9] = 0.0;

    pfVar7[10] = 0.0;

    pfVar7[0xc] = 0.0;

    pfVar7[0xd] = 0.0;

    pfVar7[0xe] = 0.0;

  }

  local_4 = 0xffffffff;

  param_1[8] = (float)pfVar7;

  pfVar7 = operator_new(0x3c);

  if (pfVar7 == (float *)0x0) {

    pfVar7 = (float *)0x0;

  }

  else {

    fVar1 = param_1[5];

    fVar2 = param_1[4];

    fVar3 = param_1[1];

    fVar4 = *param_1;

    *pfVar7 = fVar4;

    pfVar7[1] = fVar3;

    pfVar7[3] = fVar1;

    pfVar7[2] = fVar2;

    fVar5 = DAT_00a0f298;

    pfVar7[4] = (fVar4 + fVar2) * DAT_00a0f298;

    pfVar7[5] = (fVar3 + fVar1) * fVar5;

    pfVar7[6] = 1.4013e-45;

    pfVar7[7] = 0.0;

    pfVar7[8] = 0.0;

    pfVar7[9] = 0.0;

    pfVar7[10] = 0.0;

    pfVar7[0xc] = 0.0;

    pfVar7[0xd] = 0.0;

    pfVar7[0xe] = 0.0;

  }

  local_4 = 0xffffffff;

  param_1[9] = (float)pfVar7;

  pfVar7 = operator_new(0x3c);

  if (pfVar7 == (float *)0x0) {

    pfVar7 = (float *)0x0;

  }

  else {

    fVar1 = param_1[5];

    fVar2 = param_1[2];

    fVar3 = param_1[1];

    fVar4 = param_1[4];

    *pfVar7 = fVar4;

    pfVar7[1] = fVar3;

    pfVar7[3] = fVar1;

    pfVar7[2] = fVar2;

    fVar5 = DAT_00a0f298;

    pfVar7[4] = (fVar4 + fVar2) * DAT_00a0f298;

    pfVar7[5] = (fVar3 + fVar1) * fVar5;

    pfVar7[6] = 1.4013e-45;

    pfVar7[7] = 0.0;

    pfVar7[8] = 0.0;

    pfVar7[9] = 0.0;

    pfVar7[10] = 0.0;

    pfVar7[0xc] = 0.0;

    pfVar7[0xd] = 0.0;

    pfVar7[0xe] = 0.0;

  }

  param_1[10] = (float)pfVar7;

  local_4 = 4;

  puVar8 = (uint32_t /* width from decompiler */ *)param_1[0xc];

  if (puVar8 != (uint32_t /* width from decompiler */ *)param_1[0xd]) {

    do {

      cVar6 = FUN_0072b710(*puVar8,param_2);

      if (cVar6 == '\0') {

        FUN_00456960(0);

      }

      puVar8 = puVar8 + 1;

    } while (puVar8 != (uint32_t /* width from decompiler */ *)param_1[0xd]);

  }

  if ((void *)param_1[0xc] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xc]);

  }

  param_1[0xc] = 0.0;

  param_1[0xd] = 0.0;

  param_1[0xe] = 0.0;

  FUN_0043a1d0(param_1[0xc],0,0,param_2);

  param_1[6] = 0.0;

  ExceptionList = local_c;

  return;

}
