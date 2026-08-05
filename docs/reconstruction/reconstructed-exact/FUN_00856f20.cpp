// =============================================================================
// FUN_00856f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00856f20
// Address:   0x00856f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00856f20 @ 0x00856f20
// Stable ID: aa_00856f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, goto×4, switch×1.
//  - Notable callees: FUN_00856f20.
//  - Return sites: 5.

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

void __fastcall FUN_00856f20(int param_1,int param_2)



{

  float fVar1;

  float *in_EAX;

  uint32_t /* width from decompiler */ unaff_ESI;

  

  switch(unaff_ESI) {

  case 0:

    if (param_2 == 1) {

LAB_00856f7d:

      *in_EAX = (float)*(int *)(param_1 + 0x5a0);

      in_EAX[1] = (float)*(int *)(param_1 + 0x5a4);

      in_EAX[4] = g_flOne;

      in_EAX[5] = 0.0;

      return;

    }

    if (param_2 != 3) {

      return;

    }

    goto LAB_00856fea;

  case 1:

    if (param_2 == 0) goto LAB_00856f7d;

    if (param_2 == 2) goto LAB_00856f51;

    break;

  case 2:

    param_2 = param_2 + -1;

    if (param_2 == 0) {

LAB_00856f51:

      *in_EAX = (float)*(int *)(param_1 + 0x5a8);

      in_EAX[1] = (float)*(int *)(param_1 + 0x5ac);

      fVar1 = g_flOne;

      in_EAX[4] = g_flOne;

      in_EAX[5] = fVar1;

      return;

    }

LAB_00856fb1:

    if (param_2 == 2) {

      *in_EAX = (float)*(int *)(param_1 + 0x5b0);

      in_EAX[1] = (float)*(int *)(param_1 + 0x5b4);

      in_EAX[4] = 0.0;

      in_EAX[5] = g_flOne;

      return;

    }

    break;

  case 3:

    if (param_2 != 0) goto LAB_00856fb1;

LAB_00856fea:

    *in_EAX = (float)*(int *)(param_1 + 0x598);

    in_EAX[1] = (float)*(int *)(param_1 + 0x59c);

    in_EAX[4] = 0.0;

    in_EAX[5] = 0.0;

  }

  return;

}
