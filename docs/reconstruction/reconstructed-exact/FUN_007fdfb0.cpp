// =============================================================================
// FUN_007fdfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fdfb0
// Address:   0x007fdfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fdfb0 @ 0x007fdfb0
// Stable ID: aa_007fdfb0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_007a4480, FUN_007a69d0, FUN_007a6de0, FUN_007fc360, FUN_007fdfb0, FUN_008a6fd0, FUN_008a7090, FUN_008a7100.
//  - Strings: "VOG_DEBUG_STOP".
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

void FUN_007fdfb0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ uVar3;

  

  FUN_007fc360();

  piVar1 = *(int **)(param_1 + 0xf40);

  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

    (**(code **)(*(int *)*piVar1 + 0x3ec))();

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x3f4))(1);

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0xa8))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x1118));

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0xf40) + 0x514) =

         *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0xf40) + 0x498);

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0xf40) + 0x498) = in_EAX;

    *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0xf40) + 0x518) =

         *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0xf40) + 0x49c);

    if (param_3 < 0) {

      *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0xf40) + 0x49c) = in_EAX;

    }

    else {

      *(int *)(**(int **)(param_1 + 0xf40) + 0x49c) = param_3;

    }

    if (*(int **)(param_1 + 0x1118) == (int *)0x0) {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    else {

      (**(code **)(**(int **)(param_1 + 0x1118) + 0x43c))();

      FUN_008a7090();

      iVar2 = **(int **)(param_1 + 0x1118);

      uVar3 = 0xffffffff;

      FUN_007a69d0(unaff_retaddr,0xffffffff);

      uVar3 = FUN_007a6de0(unaff_retaddr,uVar3);

      (**(code **)(iVar2 + 0x444))(uVar3);

      FUN_008a7150();

      FUN_008a7100();

      FUN_008a6fd0(param_2);

      (**(code **)(**(int **)(param_1 + 0x1118) + 0x34c))();

    }

    piVar1 = *(int **)(param_1 + 0xf38);

    if (piVar1 != (int *)0x0) {

      if (*(char *)(param_1 + 0x31d9) != '\0') {

        *(uint8_t *)(param_1 + 0x31d8) = *(uint8_t *)((int)piVar1 + 0x493);

        (**(code **)(*piVar1 + 0x3c4))(1);

        return;

      }

      *(uint8_t *)(param_1 + 0x31d8) = 1;

      (**(code **)(*piVar1 + 0x3c4))(1);

    }

  }

  return;

}
