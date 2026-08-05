// =============================================================================
// FUN_0074eb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0074eb20
// Address:   0x0074eb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074eb20 @ 0x0074eb20
// Stable ID: aa_0074eb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00456780, FUN_00745ea0, FUN_0074eb20.
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

void __fastcall FUN_0074eb20(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  uint uVar3;

  

  if (*(int *)(param_1 + 4) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;

  }

  uVar3 = 0;

  if (uVar2 != 0) {

    do {

      puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + uVar3 * 4);

      if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*puVar1)(1);

      }

      uVar3 = uVar3 + 1;

    } while (uVar3 < uVar2);

  }

  FUN_00456780(0);

  if (*(int *)(param_1 + 0x70) != 0) {

    FUN_00745ea0();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  }

  return;

}
