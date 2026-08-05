// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00690c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00690c70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00690c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×7, while×1, return×1.
//  - Notable callees: FUN_006a1be0×2, FUN_0056f570, FUN_00690c70, FUN_006a1cd0, FUN_006a3db0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00690c70(int param_1,float param_2)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  float *pfVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  uint uVar11;

  float *pfVar12;

  uint uVar13;

  float10 fVar14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa688;

  local_c = ExceptionList;

  iVar8 = 0;

  if (*(int *)(param_1 + 0xc) != 0) {

    iVar8 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x30;

  }

  iVar7 = *(int *)(iVar8 * 0x30 + -0x2c + *(int *)(param_1 + 0xc));

  iVar8 = iVar8 * 0x30 + -0x30 + *(int *)(param_1 + 0xc);

  uVar13 = 0;

  pfVar12 = (float *)(iVar7 + 0x3c);

  ExceptionList = &local_c;

  while( true ) {

    if (iVar7 == 0) {

      iVar9 = 0;

    }

    else {

      iVar9 = (*(int *)(iVar8 + 8) - iVar7) / 0x38;

    }

    if (iVar9 - 1U <= uVar13) break;

    pfVar1 = pfVar12 + 1;

    pfVar2 = pfVar12 + -0xd;

    fVar6 = *pfVar12;

    pfVar3 = pfVar12 + -0xe;

    pfVar4 = pfVar12 + -1;

    pfVar5 = pfVar12 + -0xf;

    uVar13 = uVar13 + 1;

    pfVar12 = pfVar12 + 0xe;

    *(float *)(iVar8 + 0x10) =

         (float)(((int)((*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) +

                       (fVar6 - *pfVar3) * (fVar6 - *pfVar3) +

                       (*pfVar4 - *pfVar5) * (*pfVar4 - *pfVar5)) >> 1) + 0x1fc00000) +

         *(float *)(iVar8 + 0x10);

  }

  FUN_006a1cd0();

  local_4 = 0;

  if ((*(int *)(param_1 + 0x44) == 0) ||

     ((*(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x44)) / 0x2c == 0)) {

    *(uint8_t *)(uVar13 * 0x30 + *(int *)(param_1 + 0xc) + 0x18) = 0;

    fVar6 = *(float *)(iVar8 + 0x10) * DAT_00a0f298;

    *(uint32_t /* width from decompiler */ *)(iVar8 + 0x1c) = 0;

    *(float *)(iVar8 + 0x14) = fVar6;

  }

  else {

    if (*(int *)(param_1 + 0x44) == 0) {

      uVar13 = 0;

    }

    else {

      uVar13 = (*(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x44)) / 0x2c;

    }

    FUN_006a1be0(0,0x47c35000);

    uVar10 = FUN_006a3db0();

    uVar11 = (uint)((ulonglong)uVar10 % (ulonglong)uVar13) & 0xff;

    *(char *)(iVar8 + 0x18) = (char)((ulonglong)uVar10 % (ulonglong)uVar13);

    fVar6 = *(float *)(uVar11 * 0x2c + *(int *)(param_1 + 0x44) + 0x1c) * *(float *)(iVar8 + 0x10) *

            DAT_00a0f298;

    *(float *)(iVar8 + 0x14) = fVar6;

    *(float *)(iVar8 + 0x14) = fVar6 * *(float *)(uVar11 * 0x2c + *(int *)(param_1 + 0x44) + 0x20);

    fVar14 = (float10)FUN_006a1be0(*(uint32_t /* width from decompiler */ *)(uVar11 * 0x2c + *(int *)(param_1 + 0x44) + 0x24),

                                   *(uint32_t /* width from decompiler */ *)(uVar11 * 0x2c + *(int *)(param_1 + 0x44) + 0x28))

    ;

    *(float *)(iVar8 + 0x1c) = (float)fVar14;

    uVar13 = 0;

    if (*(int *)(param_1 + 0xc) != 0) {

      uVar13 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x30;

    }

    if ((uVar13 & 1) != 0) {

      *(float *)(iVar8 + 0x1c) = (float)(fVar14 * (float10)DAT_00aaa668);

    }

  }

  local_4 = 0xffffffff;

  *(float *)(iVar8 + 0x20) = param_2 * *(float *)(iVar8 + 0x10);

  FUN_0056f570();

  ExceptionList = local_c;

  return;

}
