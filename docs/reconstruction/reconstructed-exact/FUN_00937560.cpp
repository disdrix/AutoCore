// =============================================================================
// FUN_00937560
// -----------------------------------------------------------------------------
// Stable ID: aa_00937560
// Address:   0x00937560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00937560 @ 0x00937560
// Stable ID: aa_00937560
// Embedded strings (evidence for future rename):
//   - "Attempting screen transition to bad screen %i."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, goto×1.
//  - Notable callees: FUN_007ff3d0×2, FUN_004962b0, FUN_00756c50, FUN_0075de80, FUN_007a4480, FUN_007aa3e0, FUN_007fcc80, FUN_0092f000.
//  - Strings: "Attempting screen transition to bad screen %i.".
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

void FUN_00937560(int param_1)



{

  char cVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ in_stack_ffffffe8;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  cVar1 = FUN_009321f0();

  if (cVar1 == '\0') {

    uVar3 = 0x937580;

    FUN_009349b0();

    if (in_EAX == 0) {

      if (*(int *)(param_1 + 0xf3c) == 0) goto LAB_009376f6;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xf40) = 0;

      uVar2 = DAT_00a1e868;

      uVar4 = DAT_00a1e86c;

      if (*(int *)(param_1 + 0xde8) != 0) {

        FUN_007aa3e0();

        uVar2 = in_stack_ffffffe8;

        uVar4 = uVar3;

      }

      FUN_007ff3d0(uVar2,uVar4);

      cVar1 = *(char *)(param_1 + 0xa0d);

      if ((*(char *)(param_1 + 0x11) != '\0') && (cVar1 == '\0')) {

        cVar1 = '\x01';

      }

      *(char *)(param_1 + 0xa0d) = cVar1;

      if ((*(int **)(param_1 + 0xf40) == (int *)0x0) ||

         (**(int **)(param_1 + 0xf40) != *(int *)(param_1 + 0xf38))) {

        *(bool *)(param_1 + 0xb5) = *(char *)(param_1 + 0x11) != '\0';

      }

      else {

        *(char *)(param_1 + 0xb5) = cVar1;

      }

      FUN_0075de80(0,0x41200000);

      *(int *)(param_1 + 0xf40) = param_1 + 0xf3c;

    }

    else {

      if ((in_EAX != 1) || (*(int *)(param_1 + 0xf38) == 0)) {

LAB_009376f6:

        FUN_007a4480(1,"Attempting screen transition to bad screen %i.");

        return;

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xf40) = 0;

      FUN_007fcc80(1);

      FUN_007ff3d0(in_stack_ffffffe8,uVar3);

      cVar1 = *(char *)(param_1 + 0xa0d);

      if ((*(char *)(param_1 + 0x11) != '\0') && (cVar1 == '\0')) {

        cVar1 = '\x01';

      }

      *(char *)(param_1 + 0xa0d) = cVar1;

      *(char *)(param_1 + 0xb5) = cVar1;

      *(int *)(param_1 + 0xf40) = param_1 + 0xf38;

    }

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x43c))();

    FUN_00756c50(**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40));

    if ((*(int *)(param_1 + 0xe04) != 0) && (*(int *)(*(int *)(param_1 + 0xe04) + 0xe898) != 0)) {

      FUN_004962b0();

    }

    if (*(int **)(param_1 + 0x1168) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x1168) + 4))(1);

    }

    FUN_0092f000();

  }

  return;

}
