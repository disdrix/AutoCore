// =============================================================================
// FUN_009658e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009658e0
// Address:   0x009658e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009658e0 @ 0x009658e0
// Stable ID: aa_009658e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00461190×2, FUN_00461350, FUN_009658e0.
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

void FUN_009658e0(int param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ad6bf;

  pvStack_c = ExceptionList;

  local_4 = 2;

  ExceptionList = &pvStack_c;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x34) != (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = &pvStack_c;

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x34))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  FUN_00461190();

  local_4._0_1_ = 1;

  FUN_00461350();

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_00461190();

  local_4 = 0xffffffff;

  piVar2 = *(int **)(param_1 + 0x3c);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  ExceptionList = pvStack_c;

  return;

}
