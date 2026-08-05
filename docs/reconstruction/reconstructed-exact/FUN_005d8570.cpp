// =============================================================================
// FUN_005d8570
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8570
// Address:   0x005d8570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d8570 @ 0x005d8570
// Stable ID: aa_005d8570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0055e370, FUN_0055e410, FUN_005d8570.
//  - Return sites: 2.

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

void __fastcall FUN_005d8570(uint param_1)



{

  int iVar1;

  

  FUN_0055e410(-(uint)(param_1 != 4) & param_1);

  if (param_1 == 4) {

    iVar1 = 0;

  }

  else {

    iVar1 = param_1 + 4;

  }

  FUN_0055e370(iVar1);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  if ((uint32_t /* width from decompiler */ *)(param_1 - 4) != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x005d85b6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*(code *)**(uint32_t /* width from decompiler */ **)(param_1 - 4))();

    return;

  }

  return;

}
