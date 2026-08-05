// =============================================================================
// FUN_00844b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00844b60
// Address:   0x00844b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00844b60 @ 0x00844b60
// Stable ID: aa_00844b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00844b60.
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

void __fastcall FUN_00844b60(uint8_t param_1)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int *unaff_ESI;

  

  DAT_00d1791c = param_1;

  unaff_ESI[0x146] = in_EAX;

  if (in_EAX == 0) {

    iVar2 = -1;

    iVar1 = -1;

  }

  else {

    iVar2 = *(int *)(in_EAX + 0x160);

    iVar1 = *(int *)(in_EAX + 0x164);

  }

  unaff_ESI[0x148] = iVar2;

  unaff_ESI[0x149] = iVar1;

  (**(code **)(*unaff_ESI + 0x448))();

                    /* WARNING: Could not recover jumptable at 0x00844b9e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
