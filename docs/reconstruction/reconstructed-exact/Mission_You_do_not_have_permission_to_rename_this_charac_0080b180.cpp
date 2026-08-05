// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: return×6, if×4, do×2, while×1, switch×1, for×1.
//  - Notable callees: FUN_007fdfb0×5, FUN_0051fae0, FUN_007fc360, FUN_0080b180, FUN_008cc2b0.
//  - Strings: "That Name Is Already Taken.  Please Select Another:"; "That Name Is Invalid.  Please Select Another:"; "You do not have permission to rename this character."; "Could not rename character.  Please try again later.".
//  - Return sites: 6.

// =============================================================================
// Mission_You_do_not_have_permission_to_rename_this_charac_0080b180
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b180
// Address:   0x0080b180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "You do not have permission to rename this character."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_You_do_not_have_permission_to_rename_this_charac_0080b180(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  int iVar3;

  int unaff_EDI;

  

  FUN_007fc360();

  if (*(int *)(in_EAX + 0x34) == 0) {

    iVar3 = 0;

    do {

      if ((&DAT_00d1b6dc)[iVar3] != 0) {

        iVar1 = (&DAT_00d1b6dc)[iVar3];

        iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

        if ((*(int *)(iVar2 + 0x164 + iVar1) == *(int *)(in_EAX + 8)) &&

           (*(int *)(iVar2 + 0x168 + iVar1) == *(int *)(in_EAX + 0xc))) {

          FUN_0051fae0(in_EAX + 0x22);

          break;

        }

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < 0xc);

    iVar3 = *(int *)(unaff_EDI + 0xf3c);

    if ((((iVar3 != 0) && (*(int **)(unaff_EDI + 0xf40) != (int *)0x0)) &&

        (**(int **)(unaff_EDI + 0xf40) == iVar3)) &&

       ((*(int *)(iVar3 + 0xa90) == 2 && (*(int *)(iVar3 + 0xa7c) != 0)))) {

      FUN_008cc2b0();

      return;

    }

  }

  else {

    switch(*(int *)(in_EAX + 0x34)) {

    case 1:

      FUN_007fdfb0(&DAT_00d1a840,"That Name Is Already Taken.  Please Select Another:",0x4e23,1,1);

      break;

    case 2:

      FUN_007fdfb0(&DAT_00d1a840,"That Name Is Invalid.  Please Select Another:",0x4e23,1,1);

      return;

    case 3:

      FUN_007fdfb0(&DAT_00d1a840,"You do not have permission to rename this character.",0xffffffff,1

                   ,0);

      return;

    default:

      FUN_007fdfb0(&DAT_00d1a840,"Could not rename character.  Please try again later.",0xffffffff,1

                   ,0);

      return;

    case 6:

      FUN_007fdfb0(&DAT_00d1a840,

                   "That character is still logged in.  Please wait for them to disconnect before trying again."

                   ,0xffffffff,1,0);

      return;

    }

  }

  return;

}
