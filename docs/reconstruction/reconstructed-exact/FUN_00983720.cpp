// =============================================================================
// FUN_00983720
// -----------------------------------------------------------------------------
// Stable ID: aa_00983720
// Address:   0x00983720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983720 @ 0x00983720
// Stable ID: aa_00983720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, for×1, while×1.
//  - Notable callees: CloseHandle×2, block×2, EnterCriticalSection, FUN_00463e30, FUN_00719890, FUN_00983720, LeaveCriticalSection.
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

/* WARNING: Removing unreachable block (ram,0x0098384c) */

/* WARNING: Removing unreachable block (ram,0x00983850) */



void FUN_00983720(void)



{

  int *piVar1;

  int *piVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char cVar5;

  BOOL BVar6;

  int *piVar7;

  int unaff_ESI;

  int local_14;

  LPCRITICAL_SECTION local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac8c2;

  pvStack_c = ExceptionList;

  local_10 = (LPCRITICAL_SECTION)(unaff_ESI + 0x38);

  ExceptionList = &pvStack_c;

  if (*(char *)(unaff_ESI + 0x50) != '\0') {

    ExceptionList = &pvStack_c;

    EnterCriticalSection(local_10);

  }

  local_4 = 0;

  piVar1 = *(int **)(unaff_ESI + 0x30);

  for (piVar7 = *(int **)(unaff_ESI + 0x2c); piVar7 != piVar1; piVar7 = piVar7 + 1) {

    piVar2 = (int *)*piVar7;

    cVar5 = (**(code **)(*piVar2 + 0x20))();

    if ((cVar5 == '\0') || (BVar6 = CloseHandle((HANDLE)piVar2[2]), BVar6 != 0)) {

      piVar2[2] = -1;

    }

    cVar5 = (**(code **)(piVar2[5] + 0x20))();

    if ((cVar5 == '\0') || (BVar6 = CloseHandle((HANDLE)piVar2[7]), BVar6 != 0)) {

      piVar2[7] = -1;

    }

  }

  while ((*(int *)(unaff_ESI + 0x2c) != 0 &&

         (local_14 = *(int *)(unaff_ESI + 0x30) - *(int *)(unaff_ESI + 0x2c) >> 2, local_14 != 0)))

  {

    pvVar3 = *(void **)(*(int *)(unaff_ESI + 0x30) + -4);

    if (pvVar3 != (void *)0x0) {

      FUN_00719890(pvVar3);

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

    if (*(int *)(unaff_ESI + 0x2c) != 0) {

      local_14 = *(int *)(unaff_ESI + 0x30) - *(int *)(unaff_ESI + 0x2c) >> 2;

      if (local_14 != 0) {

        *(int *)(unaff_ESI + 0x30) = *(int *)(unaff_ESI + 0x30) + -4;

      }

    }

  }

  puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

  pvVar3 = (void *)*puVar4;

  *puVar4 = puVar4;

  *(int *)(*(int *)(unaff_ESI + 8) + 4) = *(int *)(unaff_ESI + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  if (pvVar3 != *(void **)(unaff_ESI + 8)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  local_14 = *(int *)(unaff_ESI + 8);

  if (*(int *)(unaff_ESI + 0x14) != *(int *)(unaff_ESI + 0x18)) {

    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x14);

  }

  FUN_00463e30(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),9,&local_14);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = 1;

  if (*(char *)&local_10[1].DebugInfo != '\0') {

    LeaveCriticalSection(local_10);

  }

  ExceptionList = pvStack_c;

  return;

}
