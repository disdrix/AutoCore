// =============================================================================
// FUN_00675970
// -----------------------------------------------------------------------------
// Stable ID: aa_00675970
// Address:   0x00675970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00675970 @ 0x00675970
// Stable ID: aa_00675970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00675970.
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

void __fastcall FUN_00675970(int param_1)



{

  int *piVar1;

  uint uVar2;

  

  if (*(int *)(param_1 + 0x10) != 0) {

    uVar2 = *(int *)(param_1 + 0x10) + -1 + *(int *)(param_1 + 0xc);

    if (*(uint *)(param_1 + 8) <= uVar2) {

      uVar2 = uVar2 - *(uint *)(param_1 + 8);

    }

    (**(code **)**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + uVar2 * 4))(0);

    piVar1 = (int *)(param_1 + 0x10);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    }

  }

  return;

}
