// =============================================================================
// FUN_004b4e70
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4e70
// Address:   0x004b4e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4e70 @ 0x004b4e70
// Stable ID: aa_004b4e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004b4e70.
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

void __fastcall FUN_004b4e70(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  

  uVar2 = 0;

  if (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2 != 0) {

    do {

      puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x50) + uVar2 * 4);

      if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*puVar1)(1);

      }

      uVar2 = uVar2 + 1;

    } while (uVar2 < (uint)(*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

  return;

}
