// =============================================================================
// FUN_00409b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00409b00
// Address:   0x00409b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00409b00 @ 0x00409b00
// Stable ID: aa_00409b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: while×1, for×1, return×1.
//  - Notable callees: FUN_00409b00.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00409b00; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00409b00(undefined4 param_1,undefined4 *param_2)`.
//  - Loops: for (iVar2 = 10; in_EAX = puVar1, iVar2 != 0; iVar2 = iVar2 + -1); while (in_EAX != param_2).
//  - Returns (1 site(s)): `void`.
//  - Assign `in_EAX = puVar1, iVar2 != 0`.




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

void __fastcall FUN_00409b00(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  while (in_EAX != param_2) {

    puVar1 = in_EAX + 10;

    puVar3 = unaff_EBX;

    puVar4 = in_EAX;

    for (iVar2 = 10; in_EAX = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

  }

  return;

}
