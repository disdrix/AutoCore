// =============================================================================
// FUN_0076db40
// -----------------------------------------------------------------------------
// Stable ID: aa_0076db40
// Address:   0x0076db40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076db40 @ 0x0076db40
// Stable ID: aa_0076db40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076d8b0, FUN_0076d9d0, FUN_0076db40.
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

uint __thiscall

FUN_0076db40(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  uint in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ local_54;

  uint8_t local_50 [80];

  

  if (DAT_00d0dfb0 == 0) {

    return in_EAX & 0xffffff00;

  }

  local_54 = 0x14;

  puVar1 = &param_3;

  if (0x13 < param_3) {

    puVar1 = &local_54;

  }

  uVar2 = FUN_0076d9d0(param_1,param_2 + 1,local_50,*puVar1);

  uVar3 = FUN_0076d8b0(param_1,uVar2,local_50,param_4,param_5);

  return uVar3;

}
