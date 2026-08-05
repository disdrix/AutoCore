// =============================================================================
// FUN_00861c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00861c60
// Address:   0x00861c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00861c60 @ 0x00861c60
// Stable ID: aa_00861c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00861c60.
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

void __thiscall FUN_00861c60(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int unaff_ESI;

  

  if ((int *)param_1[0x13f] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x13f] + 0x1d8))(param_2,1);

    if (unaff_ESI == 0) {

      (**(code **)(*(int *)param_1[0x13f] + 0x15c))(1,param_1 + 0x144);

    }

    else {

      (**(code **)(*(int *)param_1[0x13f] + 0x154))(1,unaff_ESI);

    }

    (**(code **)(*param_1 + 4))(1);

    (**(code **)(*(int *)param_1[0x13f] + 0xfc))(1,param_1[0x149]);

    param_1[0x142] = 0;

    *(uint8_t *)(param_1 + 0x143) = 0;

  }

  return;

}
