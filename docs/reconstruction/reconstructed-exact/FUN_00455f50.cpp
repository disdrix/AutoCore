// =============================================================================
// FUN_00455f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00455f50
// Address:   0x00455f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00455f50 @ 0x00455f50
// Stable ID: aa_00455f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00455f50.
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

void __fastcall FUN_00455f50(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  

  if (in_EAX != 0) {

    puVar1 = param_2 + 5;

    do {

      if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

        *param_2 = *param_1;

        puVar1[-4] = param_1[1];

        puVar1[-3] = param_1[2];

        puVar1[-2] = param_1[3];

        puVar1[-1] = param_1[4];

        *puVar1 = param_1[5];

      }

      param_2 = param_2 + 6;

      puVar1 = puVar1 + 6;

      in_EAX = in_EAX + -1;

    } while (in_EAX != 0);

  }

  return;

}
