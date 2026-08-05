// =============================================================================
// FUN_006450e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006450e0
// Address:   0x006450e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006450e0 @ 0x006450e0
// Stable ID: aa_006450e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_004ac220, FUN_00644eb0, FUN_006450e0.
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

void __thiscall FUN_006450e0(int param_1,int param_2)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ local_10;

  

  iVar3 = *(int *)(param_2 + 0x10);

  iVar7 = 1 - (int)((float)(iVar3 / *(int *)(param_1 + 4)) * DAT_00a12f70);

  fVar1 = *(float *)(param_2 + 0x18);

  iVar5 = 1 - (int)((float)(*(int *)(param_2 + 0x14) / *(int *)(param_1 + 4)) * DAT_00a12f70);

  iVar4 = *(int *)(param_2 + 0x14);

  fVar2 = *(float *)(param_2 + 0x18);

  local_10 = 0;

  if (0 < iVar5) {

    do {

      iVar6 = 0;

      if (0 < iVar7) {

        do {

          FUN_00644eb0(param_2,(float)iVar6 * (((float)iVar3 * fVar1) / (float)iVar7),

                       (float)local_10 * (((float)iVar4 * fVar2) / (float)iVar5),0);

          iVar6 = iVar6 + 1;

        } while (iVar6 < iVar7);

      }

      local_10 = local_10 + 1;

    } while (local_10 < iVar5);

  }

  FUN_004ac220();

  return;

}
