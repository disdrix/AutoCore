// =============================================================================
// FUN_00951e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00951e20
// Address:   0x00951e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00951e20 @ 0x00951e20
// Stable ID: aa_00951e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable×2, FUN_007242c0, FUN_00935110, FUN_00951e20.
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

uint32_t /* width from decompiler */ __fastcall FUN_00951e20(int param_1)



{

  int *piVar1;

  uint uVar2;

  bool bVar3;

  

  bVar3 = *(char *)(param_1 + 0x9e6) == '\0';

  *(bool *)(param_1 + 0x9e6) = bVar3;

  if (bVar3) {

    piVar1 = (int *)Client_GetMissionCompleteAudioTable();

    if (*piVar1 == 0) {

      FUN_00935110();

    }

  }

  uVar2 = (uint)*(byte *)(param_1 + 0x9e6);

  Client_GetMissionCompleteAudioTable(uVar2);

  FUN_007242c0(uVar2);

  return 1;

}
