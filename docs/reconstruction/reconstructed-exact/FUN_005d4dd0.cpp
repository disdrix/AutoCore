// =============================================================================
// FUN_005d4dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4dd0
// Address:   0x005d4dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4dd0 @ 0x005d4dd0
// Stable ID: aa_005d4dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004e87d0, FUN_004e88e0, FUN_0053dd40, FUN_005d4dd0.
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

void __fastcall FUN_005d4dd0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  FUN_0053dd40();

  if (*(int *)(param_1 + -0xd8) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0xfc))();

    FUN_004e88e0(&uStack_1c,*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x5c + param_1);

    FUN_004e87d0(&uStack_10,*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x4c + param_1);

    (*(code *)**(uint32_t /* width from decompiler */ **)(param_1 + -0xa0))

              (1,uStack_1c,uStack_18,uStack_14,uStack_10,uStack_c,uStack_8,uStack_4,

               *(uint8_t *)(param_1 + -0x93));

    iVar1 = *(int *)(*(int *)(param_1 + -0xdc) + 4) + param_1;

    (**(code **)(*(int *)(iVar1 + -0xdc) + 0xb8))(*(uint32_t /* width from decompiler */ *)(iVar1 + -0x24));

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0x100))();

  }

  return;

}
