// =============================================================================
// FUN_007fde80
// -----------------------------------------------------------------------------
// Stable ID: aa_007fde80
// Address:   0x007fde80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fde80 @ 0x007fde80
// Stable ID: aa_007fde80
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_007a4480, FUN_007fb7f0, FUN_007fde80, FUN_0092f000.
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

void FUN_007fde80(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,int param_5)



{

  int in_EAX;

  int *piVar1;

  

  FUN_007fb7f0();

  if ((*(char *)(in_EAX + 0x9d) == '\0') && (*(int **)(in_EAX + 0xf40) != (int *)0x0)) {

    piVar1 = *(int **)(in_EAX + 0x1124);

    if (param_5 == 2) {

      piVar1 = *(int **)(in_EAX + 0x1128);

    }

    else if (param_5 == 3) {

      piVar1 = *(int **)(in_EAX + 0x112c);

    }

    else if (param_5 == 4) {

      piVar1 = *(int **)(in_EAX + 0x1130);

    }

    else if (param_5 == 5) {

      piVar1 = *(int **)(in_EAX + 0x1134);

    }

    if (piVar1 != (int *)0x0) {

      if (**(int **)(in_EAX + 0xf40) != 0) {

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x3ec))();

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x3f4))(1);

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0xa8))(piVar1);

      }

      (**(code **)(*piVar1 + 0x43c))();

      piVar1[0x148] = param_3;

      piVar1[0x149] = param_4;

      (**(code **)(*piVar1 + 0x444))(param_1,param_2,1);

      (**(code **)(*piVar1 + 0x13c))();

      piVar1[0x146] = -1;

      piVar1[0x147] = -1;

      (**(code **)(*piVar1 + 0x34c))();

      FUN_0092f000();

      return;

    }

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  return;

}
