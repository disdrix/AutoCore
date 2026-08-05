// =============================================================================
// FUN_006c70a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c70a0
// Address:   0x006c70a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c70a0 @ 0x006c70a0
// Stable ID: aa_006c70a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006cb050×4, FUN_006c70a0, FUN_006d2e00, FUN_006d39e0, FUN_006d3f20, FUN_006d5960, FUN_006d7370, FUN_006de280.
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

void FUN_006c70a0(uint param_1)



{

  uint uVar1;

  

  uVar1 = param_1;

  FUN_006eedd0(param_1);

  FUN_006eed60(param_1);

  FUN_006ee470(param_1);

  FUN_006ed5e0(param_1);

  FUN_006cb050(uVar1 & 0xffffff00);

  FUN_006ec4c0(param_1);

  FUN_006cb050(1);

  uVar1 = param_1;

  FUN_006ea080(param_1);

  FUN_006cb050(uVar1 & 0xffffff00);

  FUN_006e9af0(param_1);

  FUN_006cb050(1);

  FUN_006e8de0(param_1);

  FUN_006e8240(param_1);

  FUN_006e8010(param_1);

  FUN_006e76d0(param_1);

  FUN_006e5480(param_1);

  FUN_006e4760(param_1);

  FUN_006e3d90(param_1);

  FUN_006e3780(param_1);

  FUN_006e2870(param_1);

  FUN_006e19d0(param_1);

  FUN_006df070(param_1);

  FUN_006de280(param_1);

  FUN_006d7370(param_1);

  FUN_006d5960(param_1);

  FUN_006d3f20(param_1);

  FUN_006d39e0(param_1);

  FUN_006d2e00(param_1);

  return;

}
