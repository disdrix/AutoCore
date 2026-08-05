// =============================================================================
// FUN_00409b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00409b20
// Address:   0x00409b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00409b20 @ 0x00409b20
// Stable ID: aa_00409b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: while×1, for×1, return×1.
//  - Notable callees: FUN_00409b20.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00409b20; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00409b20(undefined4 param_1,undefined4 *param_2)`.
//  - Loops: for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1); while (unaff_EBX != param_2).
//  - Returns (1 site(s)): `void`.
//  - Assign `param_2 = param_2 + -10`.
//  - Assign `in_EAX = in_EAX + -10`.




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

void __fastcall FUN_00409b20(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  while (unaff_EBX != param_2) {

    param_2 = param_2 + -10;

    in_EAX = in_EAX + -10;

    puVar2 = param_2;

    puVar3 = in_EAX;

    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

  }

  return;

}
