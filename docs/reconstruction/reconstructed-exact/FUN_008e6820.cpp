// =============================================================================
// FUN_008e6820
// -----------------------------------------------------------------------------
// Stable ID: aa_008e6820
// Address:   0x008e6820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e6820 @ 0x008e6820
// Stable ID: aa_008e6820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, return×5, switch×1.
//  - Notable callees: func_0x008e4730×2, FUN_007fd420, FUN_008e6820, func_0x008e65a0.
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

void __fastcall FUN_008e6820(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint8_t auStack_10 [16];

  

  switch(param_1) {

  case 5:

    param_2 = param_2 + in_EAX * 5;

    if (*(int *)(param_3 + 0x61c + param_2 * 4) == 0) {

      func_0x008e4730(1);

      return;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)

             (**(code **)(**(int **)(param_3 + 0x5b8 + param_2 * 4) + 0x140))(auStack_10,1);

    puVar2 = (uint32_t /* width from decompiler */ *)

             (**(code **)(**(int **)(param_3 + 0x5b8 + param_2 * 4) + 0x120))(auStack_10,1,1);

    FUN_007fd420(*puVar2,puVar2[1],*puVar1,puVar1[1]);

    break;

  case 6:

    param_2 = param_2 + in_EAX * 5;

    if (*(int *)(param_3 + 0x61c + param_2 * 4) != 0) {

      DAT_00d1d8f4 = 1;

      DAT_00d1d8f5 = 0;

      if (DAT_00d1d8dc != (int *)0x0) {

        (**(code **)(*DAT_00d1d8dc + 4))(0);

      }

      if (*(int *)(param_3 + 0x61c + param_2 * 4) != 0) {

        return;

      }

    }

    func_0x008e4730(0);

    return;

  case 8:

  case 0x14:

  case 0x15:

    if (*(char *)(in_EAX + 0x7db + param_3) == '\0') {

      func_0x008e65a0(param_3,param_3 + in_EAX * 0x14 + 0x5b8);

      return;

    }

  }

  return;

}
