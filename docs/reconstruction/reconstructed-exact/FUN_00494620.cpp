// =============================================================================
// FUN_00494620
// -----------------------------------------------------------------------------
// Stable ID: aa_00494620
// Address:   0x00494620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00494620 @ 0x00494620
// Stable ID: aa_00494620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00494620, FUN_004fd9b0, SQRT.
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

void __thiscall FUN_00494620(int param_1,uint32_t /* width from decompiler */ param_2,float param_3,int *param_4)



{

  int iVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  

  iVar3 = (int)param_3;

  if ((param_3 != 0.0) &&

     ((*(char *)((int)param_3 + 0x2ac) == '\0' || (*(int *)((int)param_3 + 0x48) == 0)))) {

    if (0x10 < *param_4) {

      fVar4 = *(float *)(param_1 + 0x54) * (16.0 / (float)*param_4) * DAT_00a0f298;

      param_3 = DAT_00a0f524;

      if (DAT_00a0f524 <= fVar4) {

        param_3 = fVar4;

      }

      iVar1 = *(int *)(*(int *)(iVar3 + 4) + 4);

      fVar4 = *(float *)(iVar1 + 0x8c + iVar3) - *(float *)(param_1 + 0x94);

      fVar2 = *(float *)(iVar1 + iVar3 + 0x84) - *(float *)(param_1 + 0x8c);

      if ((param_3 < SQRT(fVar4 * fVar4 + fVar2 * fVar2)) && (*(char *)(iVar3 + 0x103) == '\0')) {

        return;

      }

    }

    FUN_004fd9b0(param_1 + 0xa8,param_2);

  }

  return;

}
