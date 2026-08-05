// =============================================================================
// FUN_0045f080
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f080
// Address:   0x0045f080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045f080 @ 0x0045f080
// Stable ID: aa_0045f080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0045f080.
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

void __fastcall FUN_0045f080(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  

  if (in_EAX != 0) {

    puVar1 = param_2 + 9;

    do {

      if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

        *param_2 = *param_1;

        puVar1[-8] = param_1[1];

        puVar1[-7] = param_1[2];

        puVar1[-6] = param_1[3];

        puVar1[-5] = param_1[4];

        puVar1[-4] = param_1[5];

        puVar1[-3] = param_1[6];

        puVar1[-2] = param_1[7];

        puVar1[-1] = param_1[8];

        *puVar1 = param_1[9];

        puVar1[1] = param_1[10];

      }

      param_2 = param_2 + 0xb;

      puVar1 = puVar1 + 0xb;

      in_EAX = in_EAX + -1;

    } while (in_EAX != 0);

  }

  return;

}
