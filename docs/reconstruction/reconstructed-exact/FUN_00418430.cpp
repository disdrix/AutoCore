// =============================================================================
// FUN_00418430
// -----------------------------------------------------------------------------
// Stable ID: aa_00418430
// Address:   0x00418430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00418430 @ 0x00418430
// Stable ID: aa_00418430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00418430.
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

void __fastcall FUN_00418430(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int unaff_ESI;

  

  if (unaff_ESI != param_1) {

    iVar3 = param_1 - (int)in_EAX;

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + -8);

      param_1 = param_1 + -8;

      puVar2 = in_EAX + -2;

      *puVar2 = *puVar1;

      in_EAX[-1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + (int)puVar2);

      in_EAX = puVar2;

    } while (param_1 != unaff_ESI);

  }

  return;

}
