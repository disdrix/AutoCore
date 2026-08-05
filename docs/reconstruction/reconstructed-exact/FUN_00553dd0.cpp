// =============================================================================
// FUN_00553dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00553dd0
// Address:   0x00553dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00553dd0 @ 0x00553dd0
// Stable ID: aa_00553dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, switch×1, goto×1.
//  - Notable callees: FUN_00553dd0, _localtime64, _time64.
//  - Return sites: 4.

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



float10 __fastcall FUN_00553dd0(int param_1)



{

  float fVar1;

  tm *ptVar2;

  bool bVar3;

  float local_14;

  uint local_8;

  int local_4;

  

  if (*(float *)(param_1 + 0x24) != DAT_00aaa668) {

    return (float10)*(float *)(param_1 + 0x24);

  }

  _time64((__time64_t *)&local_8);

  bVar3 = local_8 < *(uint *)(param_1 + 0x160);

  local_8 = local_8 - *(uint *)(param_1 + 0x160);

  local_4 = (local_4 - *(int *)(param_1 + 0x164)) - (uint)bVar3;

  ptVar2 = _localtime64((__time64_t *)&local_8);

  local_14 = 0.0;

  fVar1 = (float)(ptVar2->tm_sec + ptVar2->tm_min * 0x3c);

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x154)) {

  case 0:

    local_14 = fVar1;

    break;

  case 1:

    local_14 = fVar1 - DAT_009cca58;

    break;

  case 2:

    local_14 = fVar1 - _DAT_009d25a4;

    break;

  case 3:

    local_14 = fVar1 - _DAT_009d25a0;

    break;

  default:

    goto switchD_00553e55_default;

  }

  local_14 = local_14 * DAT_00aaace0;

switchD_00553e55_default:

  if (DAT_00b04750 == fVar1) {

    fVar1 = (float)(int)(g_dwClientTickMs - _DAT_00b0474c);

    if ((int)(g_dwClientTickMs - _DAT_00b0474c) < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    local_14 = fVar1 * g_flMsToSeconds_Inferred * DAT_00aaace0 + local_14;

  }

  else {

    _DAT_00b0474c = g_dwClientTickMs;

    DAT_00b04750 = fVar1;

  }

  if (g_flOne <= local_14) {

    return (float10)g_flOne;

  }

  if (0.0 <= local_14) {

    return (float10)local_14;

  }

  return (float10)0.0;

}
