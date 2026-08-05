// =============================================================================
// FUN_0045f470
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f470
// Address:   0x0045f470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045f470 @ 0x0045f470
// Stable ID: aa_0045f470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0045f470.
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

void __fastcall FUN_0045f470(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if (param_1 != unaff_EDI) {

    puVar1 = in_EAX + 4;

    puVar2 = param_1 + 4;

    do {

      if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

        *in_EAX = *param_1;

        puVar1[-3] = puVar2[-3];

        puVar1[-2] = puVar2[-2];

        puVar1[-1] = puVar2[-1];

        *puVar1 = *puVar2;

        puVar1[1] = puVar2[1];

        puVar1[2] = puVar2[2];

        puVar1[3] = puVar2[3];

      }

      param_1 = param_1 + 8;

      in_EAX = in_EAX + 8;

      puVar1 = puVar1 + 8;

      puVar2 = puVar2 + 8;

    } while (param_1 != unaff_EDI);

  }

  return;

}
