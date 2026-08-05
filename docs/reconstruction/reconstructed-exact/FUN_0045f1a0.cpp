// =============================================================================
// FUN_0045f1a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f1a0
// Address:   0x0045f1a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045f1a0 @ 0x0045f1a0
// Stable ID: aa_0045f1a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_0045f1a0.
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

void __fastcall FUN_0045f1a0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  for (; param_2 != 0; param_2 = param_2 + -1) {

    if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

      *in_EAX = *param_1;

      in_EAX[1] = param_1[1];

      in_EAX[2] = param_1[2];

      in_EAX[3] = param_1[3];

      in_EAX[4] = param_1[4];

      in_EAX[5] = param_1[5];

      in_EAX[6] = param_1[6];

      in_EAX[7] = param_1[7];

    }

    in_EAX = in_EAX + 8;

  }

  return;

}
