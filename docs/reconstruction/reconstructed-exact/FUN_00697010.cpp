// =============================================================================
// FUN_00697010
// -----------------------------------------------------------------------------
// Stable ID: aa_00697010
// Address:   0x00697010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00697010 @ 0x00697010
// Stable ID: aa_00697010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×2, while×2, do×1, return×1.
//  - Notable callees: FUN_00697010.
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

void __thiscall FUN_00697010(int param_1,float *param_2,float param_3)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  float local_18 [6];

  

  fVar1 = *(float *)(param_1 + 0x14);

  local_18[4] = 0.0;

  local_18[3] = 0.0;

  local_18[2] = 0.0;

  local_18[1] = 0.0;

  local_18[0] = 0.0;

  local_18[5] = fVar1;

  if (5 < (int)fVar1) {

    local_18[5] = 7.00649e-45;

  }

  iVar4 = 0;

  if (3 < (int)fVar1) {

    pfVar2 = (float *)(param_1 + 8);

    iVar5 = iVar4;

    do {

      iVar4 = iVar5 + 4;

      pfVar3 = pfVar2 + 4;

      local_18[iVar5] = param_3 * pfVar2[-2];

      *(float *)(&stack0xffffffdc + iVar4 * 4) = param_3 * pfVar2[-1];

      *(float *)((int)local_18 + (-0x10 - param_1) + (int)pfVar3) = param_3 * *pfVar2;

      *(float *)(&stack0xffffffdc + -param_1 + (int)pfVar3) = param_3 * pfVar2[1];

      pfVar2 = pfVar3;

      iVar5 = iVar4;

    } while (iVar4 < (int)fVar1 + -3);

  }

  while (iVar4 < (int)fVar1) {

    iVar5 = iVar4 * 4;

    iVar4 = iVar4 + 1;

    *(float *)(&stack0xffffffe4 + iVar4 * 4) = param_3 * *(float *)(param_1 + iVar5);

  }

  *param_2 = local_18[0];

  param_2[1] = local_18[1];

  param_2[2] = local_18[2];

  param_2[3] = local_18[3];

  param_2[4] = local_18[4];

  param_2[5] = local_18[5];

  return;

}
