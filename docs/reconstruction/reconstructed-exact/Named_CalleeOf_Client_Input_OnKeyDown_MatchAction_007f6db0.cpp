// =============================================================================
// Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0
// -----------------------------------------------------------------------------
// Stable ID: aa_007f6db0
// Callee of Client_Input_OnKeyDown_MatchAction
// Address:   0x007f6db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×43, goto×16, return×12, do×4, while×4, switch×1.
//  - Notable callees: FUN_007f6db0.
//  - Return sites: 12.

/*
 * Behavioral notes:
 * Callee of Client_Input_OnKeyDown_MatchAction
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0(uint32_t /* width from decompiler */ param_1,short param_2)



{

  uint32_t /* width from decompiler */ in_EAX;

  short *psVar1;

  int iVar2;

  short unaff_SI;

  int unaff_EDI;

  

  switch(in_EAX) {

  case 0:

    iVar2 = 0;

    psVar1 = (short *)(unaff_EDI + 0x30);

    do {

      if (psVar1[-0x15] == unaff_SI) {

        if (param_2 == 0) {

          if (*psVar1 == 0) goto LAB_007f6dd2;

        }

        else if (*psVar1 != 0) goto LAB_007f6dd2;

        if ((char)psVar1[3] != '\0') {

LAB_007f6dd2:

          return unaff_EDI + 6 + iVar2 * 0x34;

        }

      }

      if (psVar1[-0x14] == unaff_SI) {

        if (param_2 == 0) {

          if (psVar1[1] == 0) goto LAB_007f6e02;

        }

        else if (psVar1[1] != 0) goto LAB_007f6e02;

        if ((char)psVar1[3] != '\0') {

LAB_007f6e02:

          return unaff_EDI + 6 + iVar2 * 0x34;

        }

      }

      iVar2 = iVar2 + 1;

      psVar1 = psVar1 + 0x1a;

    } while (iVar2 < 5);

    break;

  case 1:

    iVar2 = 0;

    psVar1 = (short *)(unaff_EDI + 0x134);

    do {

      if (psVar1[-0x15] == unaff_SI) {

        if (param_2 == 0) {

          if (*psVar1 == 0) goto LAB_007f6e48;

        }

        else if (*psVar1 != 0) goto LAB_007f6e48;

        if ((char)psVar1[3] != '\0') {

LAB_007f6e48:

          return unaff_EDI + 0x10a + iVar2 * 0x34;

        }

      }

      if (psVar1[-0x14] == unaff_SI) {

        if (param_2 == 0) {

          if (psVar1[1] == 0) goto LAB_007f6e7b;

        }

        else if (psVar1[1] != 0) goto LAB_007f6e7b;

        if ((char)psVar1[3] != '\0') {

LAB_007f6e7b:

          return unaff_EDI + 0x10a + iVar2 * 0x34;

        }

      }

      iVar2 = iVar2 + 1;

      psVar1 = psVar1 + 0x1a;

      if (5 < iVar2) {

        return 0;

      }

    } while( true );

  case 2:

    iVar2 = 0;

    psVar1 = (short *)(unaff_EDI + 0x26c);

    do {

      if (psVar1[-0x15] == unaff_SI) {

        if (param_2 == 0) {

          if (*psVar1 == 0) goto LAB_007f6ec4;

        }

        else if (*psVar1 != 0) goto LAB_007f6ec4;

        if ((char)psVar1[3] != '\0') {

LAB_007f6ec4:

          return unaff_EDI + 0x242 + iVar2 * 0x34;

        }

      }

      if (psVar1[-0x14] == unaff_SI) {

        if (param_2 == 0) {

          if (psVar1[1] == 0) goto LAB_007f6ef7;

        }

        else if (psVar1[1] != 0) goto LAB_007f6ef7;

        if ((char)psVar1[3] != '\0') {

LAB_007f6ef7:

          return unaff_EDI + 0x242 + iVar2 * 0x34;

        }

      }

      iVar2 = iVar2 + 1;

      psVar1 = psVar1 + 0x1a;

      if (0x77 < iVar2) {

        return 0;

      }

    } while( true );

  case 3:

    iVar2 = 0;

    psVar1 = (short *)(unaff_EDI + 0x1acc);

    do {

      if (psVar1[-0x15] == unaff_SI) {

        if (param_2 == 0) {

          if (*psVar1 == 0) goto LAB_007f6f41;

        }

        else if (*psVar1 != 0) goto LAB_007f6f41;

        if ((char)psVar1[3] != '\0') {

LAB_007f6f41:

          return unaff_EDI + 0x1aa2 + iVar2 * 0x34;

        }

      }

      if (psVar1[-0x14] == unaff_SI) {

        if (param_2 == 0) {

          if (psVar1[1] == 0) goto LAB_007f6f74;

        }

        else if (psVar1[1] != 0) goto LAB_007f6f74;

        if ((char)psVar1[3] != '\0') {

LAB_007f6f74:

          return unaff_EDI + 0x1aa2 + iVar2 * 0x34;

        }

      }

      iVar2 = iVar2 + 1;

      psVar1 = psVar1 + 0x1a;

      if (0x13 < iVar2) {

        return 0;

      }

    } while( true );

  }

  return 0;

}
