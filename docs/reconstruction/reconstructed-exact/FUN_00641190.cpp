// =============================================================================
// FUN_00641190
// -----------------------------------------------------------------------------
// Stable ID: aa_00641190
// Address:   0x00641190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00641190 @ 0x00641190
// Stable ID: aa_00641190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00641190, FUN_00652ce0.
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

void __thiscall FUN_00641190(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 8) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 8))(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  }

  if (param_2 != 0) {

    iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x15);

    *(uint16_t *)(iVar1 + 4) = 0x10;

    uVar2 = FUN_00652ce0(param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

  }

  return;

}
