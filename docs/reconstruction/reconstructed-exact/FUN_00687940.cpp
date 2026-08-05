// =============================================================================
// FUN_00687940
// -----------------------------------------------------------------------------
// Stable ID: aa_00687940
// Address:   0x00687940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00687940 @ 0x00687940
// Stable ID: aa_00687940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00699c50×4, FUN_00685cf0, FUN_00687940.
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

void __fastcall FUN_00687940(int param_1)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  float10 fVar5;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar2 = *(int *)(param_1 + 4);

  if (((iVar2 != 0) && (*(int *)(param_1 + 0x5c) != 0)) && (*(int *)(param_1 + 0x50) != 0)) {

    pfVar3 = *(float **)(param_1 + 0x40);

    local_c = *pfVar3;

    local_8 = pfVar3[1];

    local_4 = pfVar3[2];

    iVar4 = *(int *)(param_1 + 0x40);

    local_18 = *(float *)(iVar4 + 0xc);

    local_14 = *(float *)(iVar4 + 0x10);

    local_10 = *(float *)(iVar4 + 0x14);

    fVar5 = (float10)FUN_00685cf0(&local_18);

    fVar1 = (float)(fVar5 * (float10)DAT_00a0f298);

    local_4 = local_10 + local_4;

    local_18 = (local_18 + local_c) * DAT_00a0f298;

    local_14 = (local_14 + local_8) * DAT_00a0f298;

    local_10 = local_4 * DAT_00a0f298;

    if (*(int *)(param_1 + 0x4c) != 0) {

      FUN_00699c50(iVar2,local_18,local_14,local_10,fVar1,*(int *)(param_1 + 0x4c) + 0x34);

      FUN_00699c50(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c),local_18,local_14,local_10,fVar1,

                   *(int *)(param_1 + 0x4c) + 0x34);

      return;

    }

    FUN_00699c50(iVar2,local_18,local_14,local_10,fVar1,0);

    FUN_00699c50(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c),local_18,local_14,local_10,fVar1,0);

  }

  return;

}
