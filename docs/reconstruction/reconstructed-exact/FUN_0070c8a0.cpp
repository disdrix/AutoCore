// =============================================================================
// FUN_0070c8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0070c8a0
// Address:   0x0070c8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070c8a0 @ 0x0070c8a0
// Stable ID: aa_0070c8a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0070c8a0.
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

float10 __fastcall FUN_0070c8a0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int in_EAX;

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  int unaff_EDI;

  float10 fVar4;

  

  fVar4 = (float10)g_flZero;

  if (0 < unaff_EDI) {

    iVar3 = (unaff_EDI - 1U >> 2) + 1;

    pfVar1 = (float *)(param_2 + 4);

    pfVar2 = (float *)(in_EAX + 0xc);

    do {

      iVar3 = iVar3 + -1;

      fVar4 = (float10)pfVar1[2] * (float10)*pfVar2 +

              (float10)pfVar1[1] * (float10)pfVar2[-1] +

              (float10)*(float *)((in_EAX - param_2) + -0x10 + (int)(pfVar1 + 4)) * (float10)*pfVar1

              + (float10)pfVar1[-1] * (float10)pfVar2[-3] + fVar4;

      pfVar1 = pfVar1 + 4;

      pfVar2 = pfVar2 + 4;

    } while (iVar3 != 0);

  }

  return fVar4;

}
