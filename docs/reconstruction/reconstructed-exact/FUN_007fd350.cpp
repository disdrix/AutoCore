// =============================================================================
// FUN_007fd350
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd350
// Address:   0x007fd350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd350 @ 0x007fd350
// Stable ID: aa_007fd350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_007fd350, FUN_0083ee80.
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

void __fastcall

FUN_007fd350(uint32_t /* width from decompiler */ param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint8_t param_8)



{

  int *piVar1;

  int iVar2;

  uint8_t in_AL;

  int iVar3;

  int *piVar4;

  

  piVar1 = *(int **)(param_3 + 0x30a0);

  if (piVar1 != (int *)0x0) {

    iVar2 = *piVar1;

    piVar4 = piVar1 + 0x146;

    for (iVar3 = 0x18c; iVar3 != 0; iVar3 = iVar3 + -1) {

      *piVar4 = *param_2;

      param_2 = param_2 + 1;

      piVar4 = piVar4 + 1;

    }

    *(uint8_t *)((int)piVar1 + 0x4fe) = param_8;

    *(uint8_t *)(piVar1 + 0x13f) = in_AL;

    (**(code **)(iVar2 + 0x444))();

    (**(code **)(*piVar1 + 0x34c))();

    FUN_0083ee80(param_4,param_5,param_6,param_7);

    *(uint8_t *)(param_3 + 0x30b6) = 0;

    *(uint8_t *)(param_3 + 0x30b7) = 1;

  }

  return;

}
