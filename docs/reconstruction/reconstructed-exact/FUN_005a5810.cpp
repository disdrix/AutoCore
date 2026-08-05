// =============================================================================
// FUN_005a5810
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5810
// Address:   0x005a5810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a5810 @ 0x005a5810
// Stable ID: aa_005a5810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005a5810.
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

float10 __thiscall FUN_005a5810(int *param_1,int param_2,int param_3)



{

  float fVar1;

  float unaff_ESI;

  float unaff_EDI;

  float10 fVar2;

  float10 fVar3;

  float unaff_retaddr;

  

  fVar2 = (float10)(**(code **)(*param_1 + 0x30))(param_2 + 1,param_3);

  fVar1 = (float)(param_3 + 1);

  fVar3 = (float10)(**(code **)(*param_1 + 0x30))(param_2,fVar1);

  if (g_flOne < (float)fVar2 + unaff_retaddr) {

    fVar2 = (float10)(**(code **)(*param_1 + 0x30))(param_2 + 1,unaff_EDI);

    return (fVar2 - (float10)unaff_EDI) * (float10)(float)fVar3 +

           ((float10)fVar1 - (float10)g_flOne) * (fVar2 - (float10)unaff_ESI) + (float10)unaff_EDI;

  }

  fVar2 = (float10)(**(code **)(*param_1 + 0x30))(param_2,param_3);

  return ((float10)unaff_ESI - fVar2) * (float10)(float)fVar3 +

         ((float10)unaff_EDI - fVar2) * (float10)fVar1 + fVar2;

}
