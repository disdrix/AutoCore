// =============================================================================
// FUN_00710610
// -----------------------------------------------------------------------------
// Stable ID: aa_00710610
// Address:   0x00710610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710610 @ 0x00710610
// Stable ID: aa_00710610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×6, if×5.
//  - Notable callees: FUN_00702de0×5, FUN_00702cb0, FUN_00710610.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ FUN_00710610(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  code *pcVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar2 = FUN_00702cb0(param_1,4);

  param_2 = param_2 + iVar2 * 0x14;

  pcVar1 = *(code **)(param_2 + 4);

  if (pcVar1 != (code *)0x0) {

    uVar3 = (*pcVar1)(param_1,param_3,*(uint32_t /* width from decompiler */ *)(param_2 + 8));

    return uVar3;

  }

  if (iVar2 < 2) {

    FUN_00702de0(param_1,1);

    return 0;

  }

  if (iVar2 < 8) {

    FUN_00702de0(param_1,4);

    return 0;

  }

  if (iVar2 < 10) {

    FUN_00702de0(param_1,8);

    return 0;

  }

  if (iVar2 < 0xc) {

    FUN_00702de0(param_1,0x10);

    return 0;

  }

  FUN_00702de0(param_1,((0xd < iVar2) - 1 & 0xffffffe0) + 0x40);

  return 0;

}
