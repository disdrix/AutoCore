// =============================================================================
// FUN_00939fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00939fd0
// Address:   0x00939fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00939fd0 @ 0x00939fd0
// Stable ID: aa_00939fd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_00744c10, FUN_0079e7d0, FUN_007a3cb0, FUN_007aac60, FUN_007b65d0, FUN_007b6a20, FUN_0092f190, FUN_00939fd0.
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

uint32_t /* width from decompiler */ FUN_00939fd0(int param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  FUN_0092f190(0);

  if (*(int *)(param_1 + 0xde8) != 0) {

    FUN_0079e7d0(*(int *)(param_1 + 0xde8));

  }

  FUN_007aac60();

  DAT_00b04808 = 0;

  if (DAT_00b04818 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*DAT_00b04818)(1);

  }

  DAT_00b04818 = (uint32_t /* width from decompiler */ *)0x0;

  piVar3 = (int *)__RTDynamicCast(*(uint32_t /* width from decompiler */ *)(DAT_00d1f050 + 100),0,

                                  &assCatalog::RTTI_Type_Descriptor,

                                  &CNDAssetCatalog::RTTI_Type_Descriptor,0);

  iVar2 = DAT_00d1f050;

  if (piVar3 != (int *)0x0) {

    FUN_00744c10();

    piVar1 = *(int **)(iVar2 + 100);

    if (piVar3 == piVar1) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 100) = 0;

      if (piVar1 != (int *)0x0) {

        (**(code **)(*piVar1 + 4))(0);

      }

      if (*(int **)(iVar2 + 100) != (int *)0x0) {

        (**(code **)(**(int **)(iVar2 + 100) + 4))(1);

      }

    }

    (**(code **)*piVar3)(1);

  }

  FUN_007b6a20();

  FUN_007b65d0();

  if (*(int *)(param_1 + 0xde8) != 0) {

    FUN_007a3cb0();

  }

  ShowWindow(*(HWND *)(param_1 + 0x3188),0);

  return 0;

}
