// =============================================================================
// FUN_0055b6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055b6a0
// Address:   0x0055b6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055b6a0 @ 0x0055b6a0
// Stable ID: aa_0055b6a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0055b6a0.
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

void FUN_0055b6a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_1 != param_2) {

    puVar1 = param_3 + 5;

    puVar2 = param_1 + 5;

    do {

      if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

        *param_3 = *param_1;

        puVar1[-4] = puVar2[-4];

        puVar1[-3] = puVar2[-3];

        puVar1[-2] = puVar2[-2];

        puVar1[-1] = puVar2[-1];

        *puVar1 = *puVar2;

        puVar1[1] = puVar2[1];

      }

      param_1 = param_1 + 7;

      param_3 = param_3 + 7;

      puVar1 = puVar1 + 7;

      puVar2 = puVar2 + 7;

    } while (param_1 != param_2);

  }

  return;

}
