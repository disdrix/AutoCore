// =============================================================================
// FUN_00659180
// -----------------------------------------------------------------------------
// Stable ID: aa_00659180
// Address:   0x00659180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00659180 @ 0x00659180
// Stable ID: aa_00659180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_0065ad10×2, FUN_00659180, FUN_0065ac90, FUN_0065acb0, FUN_0065ace0, FUN_0065af00.
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

void __fastcall FUN_00659180(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uStack_4;

  

  *param_1 = &PTR_FUN_009e5ea4;

  uStack_4 = param_1;

  uVar2 = FUN_0065ac90();

  FUN_0065ad10((int)&uStack_4 + 3,uVar2);

  while (uStack_4._3_1_ != '\0') {

    uVar3 = FUN_0065acb0(uVar2);

    (**(code **)(*DAT_00b05060 + 4))(uVar3);

    uVar2 = FUN_0065ace0(uVar2);

    FUN_0065ad10((int)&uStack_4 + 3,uVar2);

  }

  iVar1 = param_1[2];

  if (iVar1 != 0) {

    FUN_0065af00();

    (**(code **)(*DAT_00b05060 + 0x14))(iVar1,0xc,0x17);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
