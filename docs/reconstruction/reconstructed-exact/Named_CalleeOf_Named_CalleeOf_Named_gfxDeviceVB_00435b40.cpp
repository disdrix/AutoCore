// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00435b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00435b40
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x00435b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: ABS, FUN_00435b40, FUN_0076f240.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00435b40(void)



{

  bool bVar1;

  float *in_EAX;

  int iVar2;

  float *unaff_EBX;

  float *pfVar3;

  float *pfVar4;

  float fVar5;

  float local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

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

  

  fVar5 = *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1] + in_EAX[2] * in_EAX[2];

  bVar1 = DAT_00aaa664 <= ABS(fVar5 - g_flOne);

  local_50[0] = *in_EAX;

  local_50[1] = in_EAX[4];

  local_50[2] = in_EAX[8];

  local_50[3] = in_EAX[0xc];

  local_40 = in_EAX[1];

  local_3c = in_EAX[5];

  local_38 = in_EAX[9];

  local_34 = in_EAX[0xd];

  local_30 = in_EAX[2];

  local_2c = in_EAX[6];

  local_28 = in_EAX[10];

  local_24 = in_EAX[0xe];

  local_20 = in_EAX[3];

  local_1c = in_EAX[7];

  local_18 = in_EAX[0xb];

  local_14 = in_EAX[0xf];

  pfVar3 = local_50;

  pfVar4 = unaff_EBX;

  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *pfVar4 = *pfVar3;

    pfVar3 = pfVar3 + 1;

    pfVar4 = pfVar4 + 1;

  }

  unaff_EBX[3] = 0.0;

  unaff_EBX[7] = 0.0;

  unaff_EBX[0xb] = 0.0;

  if (bVar1) {

    fVar5 = g_flOne / fVar5;

    *unaff_EBX = *unaff_EBX * fVar5;

    unaff_EBX[1] = unaff_EBX[1] * fVar5;

    unaff_EBX[2] = unaff_EBX[2] * fVar5;

    unaff_EBX[4] = unaff_EBX[4] * fVar5;

    unaff_EBX[5] = unaff_EBX[5] * fVar5;

    unaff_EBX[6] = unaff_EBX[6] * fVar5;

    unaff_EBX[8] = unaff_EBX[8] * fVar5;

    unaff_EBX[9] = unaff_EBX[9] * fVar5;

    unaff_EBX[10] = unaff_EBX[10] * fVar5;

  }

  local_60 = 0.0 - in_EAX[0xc];

  local_5c = 0.0 - in_EAX[0xd];

  local_58 = 0.0 - in_EAX[0xe];

  local_54 = 0;

  FUN_0076f240(&local_60);

  unaff_EBX[0xc] = local_60;

  unaff_EBX[0xd] = local_5c;

  unaff_EBX[0xe] = local_58;

  return;

}
