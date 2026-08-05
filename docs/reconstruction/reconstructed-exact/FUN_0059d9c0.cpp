// =============================================================================
// FUN_0059d9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0059d9c0
// Address:   0x0059d9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059d9c0 @ 0x0059d9c0
// Stable ID: aa_0059d9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0059d9c0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0059d9c0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x158);

  if (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x15c)) {

    do {

      cVar1 = (**(code **)(*(int *)*puVar2 + 0x40))(param_2,param_3);

      if (cVar1 != '\0') {

        return 1;

      }

      puVar2 = puVar2 + 1;

    } while (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x15c));

  }

  return 0;

}
