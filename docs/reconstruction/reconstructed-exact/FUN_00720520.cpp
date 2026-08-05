// =============================================================================
// FUN_00720520
// -----------------------------------------------------------------------------
// Stable ID: aa_00720520
// Address:   0x00720520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00720520 @ 0x00720520
// Stable ID: aa_00720520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, do×2, while×2.
//  - Notable callees: DeleteCriticalSection×2, FUN_00720520.
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

void FUN_00720520(int param_1)



{

  int iVar1;

  int *piVar2;

  void *pvStack_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &DAT_009ab6c4;

  pvStack_c = ExceptionList;

  local_4 = 3;

  piVar2 = (int *)(param_1 + 0x80);

  iVar1 = 2;

  ExceptionList = &pvStack_c;

  do {

    if ((uint32_t /* width from decompiler */ *)*piVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)(1);

    }

    *piVar2 = 0;

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  piVar2 = (int *)(param_1 + 0x88);

  iVar1 = 2;

  do {

    if ((uint32_t /* width from decompiler */ *)*piVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)(1);

    }

    *piVar2 = 0;

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x158));

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x188) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x188))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

  if (*(void **)(param_1 + 0x74) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x74));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  if (*(void **)(param_1 + 100) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 100));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  if (*(void **)(param_1 + 0x54) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x54));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  if (*(void **)(param_1 + 0x44) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x44));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  ExceptionList = pvStack_c;

  return;

}
