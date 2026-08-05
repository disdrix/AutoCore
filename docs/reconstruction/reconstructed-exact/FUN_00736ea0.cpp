// =============================================================================
// FUN_00736ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00736ea0
// Address:   0x00736ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00736ea0 @ 0x00736ea0
// Stable ID: aa_00736ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_00736ea0.
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

void FUN_00736ea0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *unaff_EDI;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009af8c2;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00aa4b14;

  local_4 = 0;

  uVar1 = param_1[0x4e];

  local_10 = uVar1;

  CVOGReaction_FailMissionNotify(&local_10);

  (**(code **)(*(int *)*DAT_00d1f044 + 0xd4))((int *)*DAT_00d1f044,uVar1,0);

  *param_1 = &PTR_LAB_009d45f0;

  ExceptionList = unaff_EDI;

  return;

}
