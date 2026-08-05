// =============================================================================
// FUN_008bd490
// -----------------------------------------------------------------------------
// Stable ID: aa_008bd490
// Address:   0x008bd490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bd490 @ 0x008bd490
// Stable ID: aa_008bd490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00791f30, FUN_008bd490.
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

void __thiscall FUN_008bd490(int *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  char cVar3;

  

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  fVar2 = DAT_00a0f298;

  if (cVar3 != '\0') {

    fVar1 = (float)param_1[0x146];

    param_1[0x146] = (int)(fVar1 + param_2);

    if (fVar2 < fVar1 + param_2) {

      (**(code **)(*param_1 + 0x448))();

      param_1[0x146] = 0;

    }

    FUN_00791f30(param_2);

  }

  return;

}
