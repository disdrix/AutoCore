// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0076ed20
// -----------------------------------------------------------------------------
// Stable ID: aa_0076ed20
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x0076ed20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×2, while×2, for×1.
//  - Notable callees: FUN_0076dd20, FUN_0076e100, FUN_0076ed20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float * Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0076ed20(float *param_1,uint32_t /* width from decompiler */ param_2)



{

  float *extraout_ECX;

  uint uVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  bool bVar6;

  float in_XMM0_Da;

  float fVar7;

  float local_50 [4];

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  FUN_0076dd20();

  if (extraout_ECX != (float *)0x0) {

    *extraout_ECX = in_XMM0_Da;

  }

  if ((in_XMM0_Da < _DAT_00a240ec) && (DAT_00aaa640 < in_XMM0_Da)) {

    return param_1;

  }

  iVar4 = 0;

  pfVar2 = local_50;

  fVar7 = in_XMM0_Da;

  do {

    iVar3 = 0;

    do {

      FUN_0076e100(param_2,iVar3);

      uVar1 = iVar3 + iVar4 & 0x80000001;

      bVar6 = uVar1 == 0;

      if ((int)uVar1 < 0) {

        bVar6 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;

      }

      if ((!bVar6) && (fVar7 != 0.0)) {

        fVar7 = 0.0 - fVar7;

      }

      *pfVar2 = fVar7;

      iVar3 = iVar3 + 1;

      pfVar2 = pfVar2 + 1;

    } while (iVar3 < 4);

    iVar4 = iVar4 + 1;

  } while (iVar4 < 4);

  in_XMM0_Da = g_flOne / in_XMM0_Da;

  local_50[0] = in_XMM0_Da * local_50[0];

  local_50[1] = local_50[1] * in_XMM0_Da;

  local_50[2] = local_50[2] * in_XMM0_Da;

  local_50[3] = local_50[3] * in_XMM0_Da;

  local_40 = local_40 * in_XMM0_Da;

  local_3c = local_3c * in_XMM0_Da;

  local_38 = local_38 * in_XMM0_Da;

  local_34 = local_34 * in_XMM0_Da;

  local_30 = local_30 * in_XMM0_Da;

  local_2c = local_2c * in_XMM0_Da;

  local_28 = local_28 * in_XMM0_Da;

  local_24 = local_24 * in_XMM0_Da;

  local_20 = local_20 * in_XMM0_Da;

  local_1c = local_1c * in_XMM0_Da;

  local_18 = local_18 * in_XMM0_Da;

  local_14 = local_14 * in_XMM0_Da;

  pfVar2 = local_50;

  pfVar5 = param_1;

  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {

    *pfVar5 = *pfVar2;

    pfVar2 = pfVar2 + 1;

    pfVar5 = pfVar5 + 1;

  }

  return param_1;

}
