// =============================================================================
// FUN_00711af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00711af0
// Address:   0x00711af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711af0 @ 0x00711af0
// Stable ID: aa_00711af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×4, do×3, while×3, return×1.
//  - Notable callees: FUN_007159e0×2, FUN_00711af0, ROUND, ftol.
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

void FUN_00711af0(float param_1,int param_2,int param_3)



{

  float fVar1;

  int iVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  int *piVar6;

  float *pfVar7;

  float10 fVar8;

  float local_53c;

  float local_538 [3];

  float afStack_52c [4];

  int aiStack_51c [320];

  int local_1c;

  int local_18;

  int local_14;

  int local_10;

  float local_c;

  float local_8;

  

  local_c = (float)(param_3 + -1);

  iVar3 = ftol();

  iVar3 = iVar3 + 1;

  if (0x50 < iVar3) {

    iVar3 = 0x50;

  }

  pfVar4 = afStack_52c + iVar3;

  piVar6 = aiStack_51c + iVar3 * 2;

  local_8 = 0.0;

  if (0 < iVar3) {

    local_10 = (int)&local_53c - (int)piVar6;

    local_14 = (int)pfVar4 - (int)piVar6;

    local_1c = iVar3;

    do {

      local_18 = (int)ROUND(local_8);

      fVar8 = (float10)FUN_007159e0(*(uint32_t /* width from decompiler */ *)(param_2 + local_18 * 4));

      iVar2 = local_14;

      iVar5 = local_18;

      *(float *)(local_10 + (int)piVar6) = (float)fVar8;

      fVar1 = local_8;

      *piVar6 = iVar5;

      *(float *)(iVar2 + (int)piVar6) = fVar1;

      local_8 = local_8 + param_1;

      piVar6 = piVar6 + 1;

      local_1c = local_1c + -1;

    } while (local_1c != 0);

    local_1c = 0;

  }

  fVar8 = (float10)FUN_007159e0(*(uint32_t /* width from decompiler */ *)(param_2 + -4 + param_3 * 4));

  (&local_53c)[iVar3] = (float)fVar8;

  aiStack_51c[iVar3 * 3] = param_3;

  pfVar4[iVar3] = local_c;

  if (1 < iVar3 + 1) {

    piVar6 = aiStack_51c + iVar3 * 2 + 1;

    local_14 = (int)local_538 - (int)pfVar4;

    local_10 = (int)aiStack_51c + (iVar3 * 8 - (int)pfVar4);

    iVar5 = (int)&local_53c - (int)pfVar4;

    param_3 = iVar3;

    do {

      iVar3 = *(int *)(local_10 + (int)pfVar4);

      if (iVar3 < *piVar6) {

        pfVar7 = (float *)(param_2 + iVar3 * 4);

        do {

          fVar1 = (float)iVar3;

          iVar3 = iVar3 + 1;

          *pfVar7 = ((*(float *)(local_14 + (int)pfVar4) - *(float *)(iVar5 + (int)pfVar4)) *

                    (fVar1 - *pfVar4)) / (pfVar4[1] - *pfVar4) + *(float *)(iVar5 + (int)pfVar4);

          pfVar7 = pfVar7 + 1;

        } while (iVar3 < *piVar6);

      }

      pfVar4 = pfVar4 + 1;

      piVar6 = piVar6 + 1;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}
