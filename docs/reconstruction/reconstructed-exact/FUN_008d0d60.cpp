// =============================================================================
// FUN_008d0d60
// -----------------------------------------------------------------------------
// Stable ID: aa_008d0d60
// Address:   0x008d0d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d0d60 @ 0x008d0d60
// Stable ID: aa_008d0d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: goto×4, if×3, switch×3, return×2.
//  - Notable callees: FUN_008d0d60.
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

void __fastcall FUN_008d0d60(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  

  if (param_3 == 0) {

    switch(param_2) {

    case 0:

      *in_EAX = DAT_00aaa80c;

      in_EAX[1] = DAT_00aaa828;

      uVar1 = DAT_00aaa850;

      break;

    case 1:

      *in_EAX = DAT_00aaa84c;

      in_EAX[1] = DAT_00aaa808;

      uVar1 = DAT_00aaa804;

      break;

    case 2:

      *in_EAX = DAT_00aaa800;

      in_EAX[1] = DAT_00aaa7fc;

      uVar1 = DAT_00aaa7f8;

      break;

    case 3:

      *in_EAX = DAT_00aaa80c;

      uVar1 = DAT_00aaa834;

LAB_008d0f25:

      in_EAX[1] = uVar1;

      uVar1 = DAT_00aaa7f4;

      break;

    default:

      goto switchD_008d0d84_default;

    }

  }

  else if (param_3 == 1) {

    switch(param_2) {

    case 0:

      *in_EAX = DAT_00aaa838;

      in_EAX[1] = DAT_00aaa834;

      uVar1 = DAT_00aaa830;

      break;

    case 1:

      *in_EAX = DAT_00aaa82c;

      in_EAX[1] = DAT_00aaa828;

      uVar1 = DAT_00aaa824;

      break;

    case 2:

      *in_EAX = DAT_00aaa820;

      in_EAX[1] = DAT_00aaa81c;

      uVar1 = DAT_00aaa830;

      break;

    case 3:

      *in_EAX = DAT_00aaa818;

      in_EAX[1] = DAT_00aaa814;

      uVar1 = DAT_00aaa810;

      break;

    default:

      goto switchD_008d0d84_default;

    }

  }

  else {

    if (param_3 != 2) {

      return;

    }

    switch(param_2) {

    case 0:

      *in_EAX = DAT_00aaa858;

      in_EAX[1] = DAT_00aaa854;

      uVar1 = DAT_00aaa850;

      break;

    case 1:

      *in_EAX = DAT_00aaa84c;

      in_EAX[1] = DAT_00aaa848;

      uVar1 = DAT_00aaa844;

      break;

    case 2:

    case 3:

      *in_EAX = DAT_00aaa840;

      uVar1 = DAT_00aaa83c;

      goto LAB_008d0f25;

    default:

      goto switchD_008d0d84_default;

    }

  }

  in_EAX[2] = uVar1;

  in_EAX[3] = 0;

switchD_008d0d84_default:

  return;

}
