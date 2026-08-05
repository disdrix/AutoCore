// =============================================================================
// FUN_006ba870
// -----------------------------------------------------------------------------
// Stable ID: aa_006ba870
// Address:   0x006ba870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ba870 @ 0x006ba870
// Stable ID: aa_006ba870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006ba750, FUN_006ba870, FUN_006bdc70, FUN_006bdd30, FUN_006c0520.
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

void FUN_006ba870(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint8_t local_445;

  uint8_t local_444 [4];

  uint32_t /* width from decompiler */ local_440;

  uint32_t /* width from decompiler */ local_43c;

  uint32_t /* width from decompiler */ local_438;

  uint32_t /* width from decompiler */ local_434;

  uint32_t /* width from decompiler */ local_430;

  uint32_t /* width from decompiler */ local_42c;

  uint32_t /* width from decompiler */ local_428;

  uint32_t /* width from decompiler */ local_424;

  uint32_t /* width from decompiler */ local_420;

  uint32_t /* width from decompiler */ local_41c;

  uint32_t /* width from decompiler */ local_418;

  uint32_t /* width from decompiler */ local_414;

  uint8_t local_410 [4];

  uint32_t /* width from decompiler */ local_40c;

  int local_404;

  

  FUN_006c0520();

  FUN_006ba750(param_1,local_410,param_2);

  FUN_006bdc70(local_410,param_2);

  local_444[0] = 1;

  local_440 = 0x37a7c5ac;

  local_43c = 0x368637bd;

  local_438 = 0x358637bd;

  local_434 = 0x3727c5ac;

  local_430 = 0x3d4ccccd;

  local_42c = 0x358637bd;

  local_428 = 0x358637bd;

  local_424 = 0x322bcc77;

  local_420 = 0x358637bd;

  local_41c = 0x38d1b717;

  local_418 = 0x3727c5ac;

  local_414 = 0x37a7c5ac;

  FUN_006bdd30(&local_445,local_444,local_410,param_2,param_3);

  if (-1 < local_404) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_40c,local_404 << 3,0x12);

  }

  return;

}
