// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×2.
//  - Notable callees: FUN_008fb480.
//  - Strings: "Select Bug Type:"; "Type Bug Description:"; "Graphics Issue"; "Missions".
//  - Return sites: 2.

// =============================================================================
// Mission_Missions
// -----------------------------------------------------------------------------
// Stable ID: aa_008fb480
// Address:   0x008fb480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Missions"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_Missions(void)



{

  int in_EAX;

  int *unaff_ESI;

  char *pcVar1;

  

  if ((in_EAX == unaff_ESI[0x199]) || (4 < in_EAX)) {

    return;

  }

  unaff_ESI[0x199] = in_EAX;

  if (in_EAX == 0) {

    (**(code **)(*(int *)unaff_ESI[0x146] + 0x1d8))(&DAT_00a35580,1,1);

    (**(code **)(*(int *)unaff_ESI[0x151] + 0x1d8))("Select Bug Type:",1,1);

    (**(code **)(*(int *)unaff_ESI[0x150] + 0x1d8))("Type Bug Description:",1,1);

    (**(code **)(*(int *)unaff_ESI[0x152] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x152] + 0x1e0))("Graphics Issue");

    (**(code **)(*(int *)unaff_ESI[0x153] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x153] + 0x1e0))("Missions");

    (**(code **)(*(int *)unaff_ESI[0x154] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x154] + 0x1e0))("NPC Interaction");

    (**(code **)(*(int *)unaff_ESI[0x155] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x155] + 0x1e0))("Skills");

    (**(code **)(*(int *)unaff_ESI[0x156] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x156] + 0x1e0))("Items/Crafting");

    (**(code **)(*(int *)unaff_ESI[0x157] + 0x1d8))(&DAT_00a2a000,1,1);

    pcVar1 = "Balance/Other";

  }

  else {

    if (in_EAX == 1) {

      (**(code **)(*(int *)unaff_ESI[0x146] + 0x1d8))("Assist");

      (**(code **)(*(int *)unaff_ESI[0x151] + 0x1d8))("Select Assist Type:",1,1);

      (**(code **)(*(int *)unaff_ESI[0x150] + 0x1d8))("Type Assist Description:",1,1);

      (**(code **)(*(int *)unaff_ESI[0x152] + 0x1d8))(&DAT_00a2a000,1,1);

      (**(code **)(*(int *)unaff_ESI[0x152] + 0x1e0))("Graphics Issue");

      (**(code **)(*(int *)unaff_ESI[0x153] + 0x1d8))(&DAT_00a2a000,1,1);

      (**(code **)(*(int *)unaff_ESI[0x153] + 0x1e0))("Can\'t Continue Playing");

      (**(code **)(*(int *)unaff_ESI[0x154] + 0x1d8))(&DAT_00a2a000,1,1);

      (**(code **)(*(int *)unaff_ESI[0x154] + 0x1e0))("Don\'t Know What To Do");

      (**(code **)(*(int *)unaff_ESI[0x155] + 0x1d8))(&DAT_00a2a000,1,1);

      (**(code **)(*(int *)unaff_ESI[0x155] + 0x1e0))("Balance Issue");

      (**(code **)(*(int *)unaff_ESI[0x156] + 0x1d8))(&DAT_00a2a000,1,1);

      (**(code **)(*(int *)unaff_ESI[0x156] + 0x1e0))("Feature Not Working");

      (**(code **)(*(int *)unaff_ESI[0x157] + 0x1d8))(&DAT_00a2a000,1,1);

      (**(code **)(*(int *)unaff_ESI[0x157] + 0x1e0))("Other");

      goto LAB_008fb872;

    }

    if (in_EAX != 2) goto LAB_008fb872;

    (**(code **)(*(int *)unaff_ESI[0x146] + 0x1d8))("Suggestion",1,1);

    (**(code **)(*(int *)unaff_ESI[0x151] + 0x1d8))("Select Suggestion Type:",1,1);

    (**(code **)(*(int *)unaff_ESI[0x150] + 0x1d8))("Type Suggestion:",1,1);

    (**(code **)(*(int *)unaff_ESI[0x152] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x152] + 0x1e0))("Graphics Issue");

    (**(code **)(*(int *)unaff_ESI[0x153] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x153] + 0x1e0))("Can\'t Continue Playing");

    (**(code **)(*(int *)unaff_ESI[0x154] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x154] + 0x1e0))("Don\'t Know What To Do");

    (**(code **)(*(int *)unaff_ESI[0x155] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x155] + 0x1e0))("Balance Issue");

    (**(code **)(*(int *)unaff_ESI[0x156] + 0x1d8))(&DAT_00a2a000,1,1);

    (**(code **)(*(int *)unaff_ESI[0x156] + 0x1e0))("Feature Not Working");

    (**(code **)(*(int *)unaff_ESI[0x157] + 0x1d8))(&DAT_00a2a000,1,1);

    pcVar1 = "Other";

  }

  (**(code **)(*(int *)unaff_ESI[0x157] + 0x1e0))(pcVar1);

LAB_008fb872:

                    /* WARNING: Could not recover jumptable at 0x008fb876. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
