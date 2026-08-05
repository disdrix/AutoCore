// =============================================================================
// FUN_00933480
// -----------------------------------------------------------------------------
// Stable ID: aa_00933480
// Address:   0x00933480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00933480 @ 0x00933480
// Stable ID: aa_00933480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00406220, FUN_004e9060, FUN_00933480, GetTickCount, ROUND.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00933480(void)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  int local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar1 = *(int *)(unaff_ESI + 0xe04);

  if ((iVar1 != 0) && (g_flOverheatCoolFrac < *(float *)(iVar1 + 0x70) - _DAT_00d1f09c)) {

    _DAT_00d1f09c = *(float *)(iVar1 + 0x70);

    iVar1 = *(int *)(unaff_ESI + 0xde8);

    local_30 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x22c);

    local_2c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x230);

    local_58 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x218);

    local_5c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x214);

    local_60 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x210);

    local_34 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x228);

    local_54 = 0;

    local_68 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20c);

    local_6c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x208);

    local_70 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x204);

    local_64 = 0;

    FUN_004e9060(&local_60,&local_70,&local_50);

    local_28 = local_50;

    local_24 = local_4c;

    local_20 = local_48;

    local_1c = local_44;

    local_14 = 0;

    local_18 = 0;

    local_38 = (int)ROUND((*(float *)(*(int *)(unaff_ESI + 0xe04) + 0x70) -

                          **(float **)(unaff_ESI + 0xc80)) * DAT_00a0f520);

    _DAT_00d206c4 = GetTickCount();

    FUN_00406220();

  }

  return;

}
