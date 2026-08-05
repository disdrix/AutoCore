// =============================================================================
// FUN_0071f4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f4d0
// Address:   0x0071f4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f4d0 @ 0x0071f4d0
// Stable ID: aa_0071f4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0071f4d0.
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

void __thiscall FUN_0071f4d0(int param_1,int *param_2,int param_3)



{

  float *pfVar1;

  int unaff_retaddr;

  

  if (0x29 < param_3) {

    param_3 = 0;

    (**(code **)(*param_2 + 0x14))(&param_3,4);

    if (0 < unaff_retaddr) {

      (**(code **)(*param_2 + 0x14))(param_1,unaff_retaddr);

    }

    (**(code **)(*param_2 + 0x14))(param_1 + 0xa5,1);

    (**(code **)(*param_2 + 0x14))(param_1 + 0xa4,1);

    (**(code **)(*param_2 + 0x14))(param_1 + 0xa0,4);

    (**(code **)(*param_2 + 0x14))(param_1 + 0x8c,4);

    (**(code **)(*param_2 + 0x14))(param_1 + 0x90,4);

    pfVar1 = (float *)(param_1 + 0x9c);

    (**(code **)(*param_2 + 0x14))(pfVar1,4);

    if (*pfVar1 <= 0.0) {

      *pfVar1 = DAT_00a110d8;

    }

    (**(code **)(*param_2 + 0x14))(param_1 + 0x80,4);

    (**(code **)(*param_2 + 0x14))(param_1 + 0x84,4);

    (**(code **)(*param_2 + 0x14))(param_1 + 0x88,4);

    (**(code **)(*param_2 + 0x14))(param_1 + 0xb8,4);

  }

  *(float *)(param_1 + 0x94) = g_flOne;

  return;

}
