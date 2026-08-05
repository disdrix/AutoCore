// =============================================================================
// FUN_005ffe10
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffe10
// Address:   0x005ffe10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ffe10 @ 0x005ffe10
// Stable ID: aa_005ffe10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_0065ad10×2, FUN_005ffe10, FUN_00650190, FUN_006501e0, FUN_00650420, FUN_0065acb0.
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

void __fastcall FUN_005ffe10(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uStack_4;

  

  *param_1 = &PTR_FUN_009dde58;

  uStack_4 = param_1;

  uVar1 = FUN_00650190();

  FUN_0065ad10((int)&uStack_4 + 3,uVar1);

  while (uStack_4._3_1_ != '\0') {

    uVar2 = FUN_0065acb0(uVar1);

    (**(code **)(*DAT_00b05060 + 4))(uVar2);

    uVar1 = FUN_006501e0(uVar1);

    FUN_0065ad10((int)&uStack_4 + 3,uVar1);

  }

  FUN_00650420();

  *param_1 = &PTR_LAB_009cc290;

  return;

}
