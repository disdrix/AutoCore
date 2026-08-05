// =============================================================================
// FUN_008d1370
// -----------------------------------------------------------------------------
// Stable ID: aa_008d1370
// Address:   0x008d1370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d1370 @ 0x008d1370
// Stable ID: aa_008d1370
// Embedded strings (evidence for future rename):
//   - "Commando"
//   - "Terminator"
//   - "Champion"
//   - "Engineer"
//   - "Shaman"
//   - "Constructor"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×27, goto×14, switch×1, return×1.
//  - Notable callees: FUN_008cf8a0, FUN_008d1370.
//  - Strings: "Commando"; "Terminator"; "Champion"; "Engineer".
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

void __fastcall FUN_008d1370(int param_1)



{

  int in_EAX;

  int unaff_EBX;

  char *pcVar1;

  

  switch(unaff_EBX) {

  case 0:

    if (in_EAX == 0) {

      if (*(int *)(param_1 + 0x66c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))("Commando",1,1);

        goto LAB_008d155f;

      }

    }

    else {

      if (in_EAX != 1) {

        if (in_EAX == 2) {

          if (*(int *)(param_1 + 0x66c) == 0) break;

          (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))("Terminator",1,1);

        }

        goto LAB_008d155f;

      }

      if (*(int *)(param_1 + 0x66c) != 0) {

        pcVar1 = "Champion";

        goto LAB_008d1551;

      }

    }

    break;

  case 1:

    if (in_EAX == 0) {

      if (*(int *)(param_1 + 0x66c) != 0) {

        pcVar1 = "Engineer";

LAB_008d1551:

        (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))(pcVar1,1,1);

        goto LAB_008d155f;

      }

    }

    else if (in_EAX == 1) {

      if (*(int *)(param_1 + 0x66c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))("Shaman",1,1);

        goto LAB_008d155f;

      }

    }

    else if (in_EAX == 2) {

      if (*(int *)(param_1 + 0x66c) != 0) {

        pcVar1 = "Constructor";

        goto LAB_008d1551;

      }

    }

    else {

LAB_008d155f:

      if (*(int *)(param_1 + 0x66c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x66c) + 0x34c))();

      }

    }

    break;

  case 2:

    if (in_EAX == 0) {

      if (*(int *)(param_1 + 0x66c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))("Lieutenant",1,1);

        goto LAB_008d155f;

      }

    }

    else {

      if (in_EAX != 1) {

        if (in_EAX == 2) {

          if (*(int *)(param_1 + 0x66c) == 0) break;

          (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))("MasterMind",1,1);

        }

        goto LAB_008d155f;

      }

      if (*(int *)(param_1 + 0x66c) != 0) {

        pcVar1 = "Archon";

        goto LAB_008d1551;

      }

    }

    break;

  case 3:

    if (in_EAX == 0) {

      if (*(int *)(param_1 + 0x66c) != 0) {

        pcVar1 = "Bounty Hunter";

        goto LAB_008d1551;

      }

    }

    else if (in_EAX == 1) {

      if (*(int *)(param_1 + 0x66c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))("Avenger",1,1);

        goto LAB_008d155f;

      }

    }

    else {

      if (in_EAX != 2) goto LAB_008d155f;

      if (*(int *)(param_1 + 0x66c) != 0) {

        pcVar1 = "Agent";

        goto LAB_008d1551;

      }

    }

    break;

  default:

    goto switchD_008d137f_default;

  }

  if ((*(int *)(param_1 + 0x670) != 0) &&

     ((**(code **)(**(int **)(param_1 + 0x670) + 0x1d8))

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0x5e8 + unaff_EBX * 4 + in_EAX * 0x14),1,1),

     *(int *)(param_1 + 0x670) != 0)) {

    (**(code **)(**(int **)(param_1 + 0x670) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x674) != 0) {

    (**(code **)(**(int **)(param_1 + 0x674) + 0x454))(0,1);

  }

  FUN_008cf8a0(param_1 + 0x678);

switchD_008d137f_default:

  return;

}
