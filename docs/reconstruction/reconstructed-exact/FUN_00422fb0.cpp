// =============================================================================
// FUN_00422fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00422fb0
// Address:   0x00422fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00422fb0 @ 0x00422fb0
// Stable ID: aa_00422fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00422fb0, FUN_00423040.
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

int __fastcall

FUN_00422fb0(uint param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ local_34;

  int local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint16_t local_4;

  uint8_t local_2;

  uint8_t local_1;

  

  local_30 = in_EAX - *(int *)(*(int *)(param_2 + 0xc) + 0x10);

  local_14 = param_1 >> 0xe & 1;

  local_10 = param_3;

  local_4 = (uint16_t)param_1;

  local_20 = 0;

  local_34 = param_4;

  local_2 = 0;

  local_1 = 0;

  local_8 = 0;

  local_2c = 0;

  local_28 = 0;

  local_24 = 0;

  local_1c = 0;

  local_c = param_5;

  local_18 = 1;

  iVar1 = FUN_00423040(&local_34);

  return (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;

}
