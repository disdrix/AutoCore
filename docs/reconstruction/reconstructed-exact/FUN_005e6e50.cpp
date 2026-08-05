// =============================================================================
// FUN_005e6e50
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6e50
// Address:   0x005e6e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e6e50 @ 0x005e6e50
// Stable ID: aa_005e6e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_005e6e50.
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

uint __thiscall FUN_005e6e50(int param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  piVar1 = *(int **)(param_1 + 0x14);

  if ((*piVar1 != 0) && (piVar1[1] != 0)) {

    (**(code **)(*(int *)*piVar1 + 0x34))(param_2 + 8,param_2,param_1);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0x30))(param_2 + 0x18,param_1);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x140);

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x148);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = uVar2;

    return CONCAT31((int3)((uint)uVar2 >> 8),1);

  }

  return (uint)piVar1 & 0xffffff00;

}
