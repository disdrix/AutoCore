// =============================================================================
// FUN_00866380
// -----------------------------------------------------------------------------
// Stable ID: aa_00866380
// Address:   0x00866380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00866380 @ 0x00866380
// Stable ID: aa_00866380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00792490, FUN_00866380.
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

void __fastcall FUN_00866380(int *param_1)



{

  char cVar1;

  char *pcVar2;

  

  if ((param_1[0x144] == 2) && ((int *)param_1[0x68ad] != (int *)0x0)) {

    (**(code **)(*(int *)param_1[0x68ad] + 0x270))((int)param_1 + 0x515,0x11);

  }

  if ((int *)param_1[0x68ae] != (int *)0x0) {

    pcVar2 = (char *)((int)param_1 + 0x53a);

    (**(code **)(*(int *)param_1[0x68ae] + 0x270))(pcVar2,1000);

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    *(short *)(param_1 + 0x14e) = (short)pcVar2 - ((short)param_1 + 0x53b);

  }

  FUN_00792490();

                    /* WARNING: Could not recover jumptable at 0x008663ee. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x3ac))();

  return;

}
