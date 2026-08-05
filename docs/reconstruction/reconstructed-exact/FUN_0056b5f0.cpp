// =============================================================================
// FUN_0056b5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b5f0
// Address:   0x0056b5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b5f0 @ 0x0056b5f0
// Stable ID: aa_0056b5f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0056b5f0.
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

float10 __fastcall FUN_0056b5f0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

  if (iVar3 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar3 + 0x3c);

  }

  if (iVar3 == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(iVar3 + 0x3c);

  }

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(iVar3 + 0x3c);

  }

  return ((float10)((int)*(short *)(iVar2 + 0x4fa) + (int)*(short *)(iVar2 + 0x4f8) +

                    (int)*(short *)(iVar2 + 0x4f6) + (int)*(short *)(iVar2 + 0x4f4) +

                    (int)*(short *)(iVar2 + 0x4f2) + (int)*(short *)(iVar2 + 0x4f0) +

                   (int)*(short *)(iVar1 + 0x4d6) + (int)*(short *)(iVar1 + 0x4d4) +

                   (int)*(short *)(iVar1 + 0x4d2) + (int)*(short *)(iVar1 + 0x4d0) +

                   (int)*(short *)(iVar1 + 0x4ce) + (int)*(short *)(iVar1 + 0x4cc)) *

         (float10)DAT_00a0f298) /

         ((float10)*(int *)(iVar3 + 0x514) * (float10)g_flMsToSeconds_Inferred);

}
