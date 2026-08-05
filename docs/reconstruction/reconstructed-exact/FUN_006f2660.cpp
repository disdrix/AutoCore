// =============================================================================
// FUN_006f2660
// -----------------------------------------------------------------------------
// Stable ID: aa_006f2660
// Address:   0x006f2660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f2660 @ 0x006f2660
// Stable ID: aa_006f2660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00646a60, FUN_006f2660.
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

void __thiscall FUN_006f2660(int param_1,int param_2,int param_3)



{

  float fVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  float *pfVar7;

  float *local_18;

  int local_10;

  

  local_18 = (float *)(param_1 + 0x60);

  piVar6 = (int *)(param_2 + 0x50);

  piVar5 = (int *)(param_3 + 0x10);

  pfVar7 = (float *)(param_2 + 0xc);

  local_10 = 3;

  do {

    fVar3 = (float)(1 << ((byte)*(uint32_t /* width from decompiler */ *)(param_3 + 0x24) & 0x1f)) /

            *(float *)(param_1 + 0x3c);

    if (fVar3 <= *(float *)(param_1 + 0x58)) {

      fVar3 = *(float *)(param_1 + 0x58);

    }

    fVar1 = *local_18;

    if ((pfVar7[1] - *pfVar7 < fVar1) && (fVar1 <= fVar3)) {

      fVar3 = fVar1;

    }

    iVar4 = FUN_00646a60(*(float *)(param_1 + 0x3c) * fVar3);

    iVar2 = *(int *)((param_3 - param_2) + (int)pfVar7);

    *piVar6 = *piVar5 + 1 + iVar4;

    piVar6[-3] = iVar2 - iVar4;

    local_18 = local_18 + 1;

    piVar6 = piVar6 + 1;

    pfVar7 = pfVar7 + 2;

    piVar5 = piVar5 + 2;

    local_10 = local_10 + -1;

  } while (local_10 != 0);

  return;

}
