// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a4480×2, FUN_00508d40, FUN_0050f0b0, FUN_007b7df0, FUN_007ca4e0, FUN_007e1d80, ReadLootTables.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00508d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00508d40
// Address:   0x00508d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_00508d40(int param_1)



{

  int iVar1;

  

  FUN_007e1d80();

  FUN_0050f0b0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 4));

  *(int *)(*(int *)(param_1 + 0xb4) + 4) = *(int *)(param_1 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4);

  *(int *)(*(int *)(param_1 + 0xb4) + 8) = *(int *)(param_1 + 0xb4);

  iVar1 = FUN_007ca4e0(param_1 + 0xb0);

  if (iVar1 < 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    FUN_007a4480(1,"CVOGLootGenerator::LoadLootTables call to ReadLootTables() failed: %x\n",iVar1);

  }

  FUN_007b7df0();

  return;

}
