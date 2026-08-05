// =============================================================================
// FUN_004bfa80
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfa80
// Address:   0x004bfa80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bfa80 @ 0x004bfa80
// Stable ID: aa_004bfa80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004bfa80, FUN_005c6b40, FUN_005c7be0, FUN_005c7df0.
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

void FUN_004bfa80(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_a4 [34];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a191b;

  local_1c = ExceptionList;

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

  ExceptionList = &local_1c;

  FUN_005c6b40(param_1,iVar1 + 0x84,iVar1 + 0x94,1,0,0);

  local_14 = 0;

  local_a4[0] = DAT_00aaaafc;

  FUN_005c7df0(local_a4,1);

  local_14 = 0xffffffff;

  FUN_005c7be0();

  ExceptionList = local_1c;

  return;

}
