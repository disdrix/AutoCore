// =============================================================================
// FUN_00409f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00409f30
// Address:   0x00409f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00409f30 @ 0x00409f30
// Stable ID: aa_00409f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00409f30.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00409f30; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00409f30(undefined4 param_1,undefined4 *param_2)`.
//  - Loops: for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1).
//  - Branches: if (in_EAX != 0x0).
//  - Returns (1 site(s)): `void`.




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

void __fastcall FUN_00409f30(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  

  if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {

      *in_EAX = *param_2;

      param_2 = param_2 + 1;

      in_EAX = in_EAX + 1;

    }

  }

  return;

}
