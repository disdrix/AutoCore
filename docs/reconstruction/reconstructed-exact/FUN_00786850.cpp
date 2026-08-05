// =============================================================================
// FUN_00786850
// -----------------------------------------------------------------------------
// Stable ID: aa_00786850
// Address:   0x00786850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00786850 @ 0x00786850
// Stable ID: aa_00786850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: DeleteCriticalSection, FUN_0042a680, FUN_00786610, FUN_00786850.
//  - Return sites: 3.

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

void FUN_00786850(int param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ace76;

  local_c = ExceptionList;

  local_4 = 0;

  local_10 = 0;

  iVar3 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x4c) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c)) / 0xc;

    }

    if (iVar2 <= local_10) break;

    pvVar1 = *(void **)(*(int *)(param_1 + 0x4c) + 4 + iVar3);

    if (pvVar1 != (void *)0x0) {

      ExceptionList = &local_c;

      FUN_00786610();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    local_10 = local_10 + 1;

    iVar3 = iVar3 + 0xc;

  }

  ExceptionList = &local_c;

  FUN_0042a680(0,0,0);

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x58));

  if (*(void **)(param_1 + 0x4c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x4c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  ExceptionList = local_c;

  return;

}
