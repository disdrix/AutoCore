// =============================================================================
// FUN_00884380
// -----------------------------------------------------------------------------
// Stable ID: aa_00884380
// Address:   0x00884380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00884380 @ 0x00884380
// Stable ID: aa_00884380
// Embedded strings (evidence for future rename):
//   - "Trade"
//   - "%s - %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_00884210, FUN_00884380, sprintf.
//  - Strings: "Trade"; "%s - %s".
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

void __fastcall FUN_00884380(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  char acStack_200 [512];

  

  FUN_00884210(param_1);

  if ((*(int *)(param_1 + 0x52c) != 0) && (*(int *)(param_1 + 0x510) != 0)) {

    uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x510) + 4) + 4) + 4 +

                                 *(int *)(param_1 + 0x510)) + 0x160))();

    uVar3 = 0xffffffff;

    pcVar2 = "Trade";

    FUN_007a69d0("Trade",0xffffffff,uVar1);

    uVar1 = FUN_007a6de0(pcVar2,uVar3);

    sprintf(acStack_200,"%s - %s",uVar1);

    (**(code **)(**(int **)(param_1 + 0x52c) + 0x1d8))(acStack_200,1,1);

    (**(code **)(**(int **)(param_1 + 0x52c) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x578) != 0) {

    (**(code **)(**(int **)(param_1 + 0x578) + 0x3c8))(*(uint8_t *)(param_1 + 0x50c),1);

    (**(code **)(**(int **)(param_1 + 0x578) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x580) != 0) {

    (**(code **)(**(int **)(param_1 + 0x580) + 0x3c8))(*(uint8_t *)(param_1 + 0x50c),1);

    (**(code **)(**(int **)(param_1 + 0x580) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x584) != 0) {

    (**(code **)(**(int **)(param_1 + 0x584) + 0x3c8))(*(uint8_t *)(param_1 + 0x50d),1);

    (**(code **)(**(int **)(param_1 + 0x584) + 0x34c))();

  }

  return;

}
