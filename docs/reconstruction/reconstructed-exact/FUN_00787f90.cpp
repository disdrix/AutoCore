// =============================================================================
// FUN_00787f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00787f90
// Address:   0x00787f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787f90 @ 0x00787f90
// Stable ID: aa_00787f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, return×2, do×1.
//  - Notable callees: CONCAT31, FUN_00787f90.
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

uint FUN_00787f90(float *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  float fVar1;

  int iVar2;

  uint uVar3;

  float fVar4;

  float fVar5;

  float local_30 [12];

  

  local_30[0] = *param_1;

  local_30[1] = (float)*param_2;

  local_30[2] = param_1[1];

  local_30[3] = (float)param_2[1];

  local_30[4] = param_1[2];

  local_30[5] = (float)param_2[2];

  local_30[6] = (float)*param_3;

  local_30[7] = (float)*param_4;

  local_30[8] = (float)param_3[1];

  local_30[9] = (float)param_4[1];

  local_30[10] = (float)param_3[2];

  local_30[0xb] = (float)param_4[2];

  iVar2 = 0;

  do {

    fVar4 = local_30[iVar2 * 2];

    fVar1 = local_30[iVar2 * 2 + 1];

    fVar5 = fVar4;

    if (fVar1 <= fVar4) {

      fVar5 = fVar1;

    }

    local_30[iVar2 * 2] = fVar5;

    if (fVar4 <= fVar1) {

      fVar4 = fVar1;

    }

    fVar1 = local_30[iVar2 * 2 + 7];

    local_30[iVar2 * 2 + 1] = fVar4;

    fVar4 = local_30[iVar2 * 2 + 6];

    fVar5 = fVar4;

    if (fVar1 <= fVar4) {

      fVar5 = fVar1;

    }

    local_30[iVar2 * 2 + 6] = fVar5;

    if (fVar4 <= fVar1) {

      fVar4 = fVar1;

    }

    local_30[iVar2 * 2 + 7] = fVar4;

    iVar2 = iVar2 + 1;

  } while (iVar2 < 3);

  uVar3 = 0;

  while ((local_30[uVar3 * 2] < local_30[uVar3 * 2 + 7] ||

          local_30[uVar3 * 2] == local_30[uVar3 * 2 + 7] &&

         (local_30[uVar3 * 2 + 6] < local_30[uVar3 * 2 + 1] ||

          local_30[uVar3 * 2 + 6] == local_30[uVar3 * 2 + 1]))) {

    uVar3 = uVar3 + 1;

    if (2 < (int)uVar3) {

      return CONCAT31((int3)(uVar3 >> 8),1);

    }

  }

  return uVar3 & 0xffffff00;

}
