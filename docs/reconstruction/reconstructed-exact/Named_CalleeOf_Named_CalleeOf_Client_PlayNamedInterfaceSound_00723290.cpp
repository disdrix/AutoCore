// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00723290
// -----------------------------------------------------------------------------
// Stable ID: aa_00723290
// Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x00723290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×9, do×4, while×4, return×3.
//  - Notable callees: FUN_0071f700×4, EnterCriticalSection, FUN_004406e0, FUN_00456960, FUN_00723290, LeaveCriticalSection.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00723290(int param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar6 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abdfd;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x30c) == 0) {

    iVar6 = 0;

    ExceptionList = &local_c;

    if (0 < *(int *)(param_1 + 0x210)) {

      piVar5 = (int *)(param_1 + 0x31c);

      ExceptionList = &local_c;

      do {

        if (*piVar5 != 0) {

          FUN_0071f700();

        }

        iVar6 = iVar6 + 1;

        piVar5 = piVar5 + 1;

      } while (iVar6 < *(int *)(param_1 + 0x210));

    }

    piVar5 = (int *)(param_1 + 0x2a8);

    iVar6 = 5;

    do {

      if (*piVar5 != 0) {

        FUN_0071f700();

      }

      piVar5 = piVar5 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

    ExceptionList = local_c;

    return;

  }

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x3f8);

  ExceptionList = &local_c;

  EnterCriticalSection(lpCriticalSection);

  local_4 = 0;

  iVar4 = *(int *)(param_1 + 0x30c);

  if (*(void **)(iVar4 + 0x10) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x18) = 0;

    iVar4 = 0;

    if (0 < *(int *)(param_1 + 0x210)) {

      piVar5 = (int *)(param_1 + 0x31c);

      do {

        if ((*piVar5 != 0) &&

           ((cVar3 = FUN_0071f700(), cVar3 != '\0' ||

            ((*(char *)(*piVar5 + 0x3a) != '\0' && (*(char *)(*piVar5 + 0x1c4) != '\0')))))) {

          FUN_004406e0();

          *(uint8_t *)(*piVar5 + 0x1c5) = 1;

        }

        iVar4 = iVar4 + 1;

        piVar5 = piVar5 + 1;

      } while (iVar4 < *(int *)(param_1 + 0x210));

    }

    piVar5 = (int *)(param_1 + 0x2a8);

    param_1 = 5;

    do {

      if ((*piVar5 != 0) && (cVar3 = FUN_0071f700(), cVar3 != '\0')) {

        iVar4 = *(int *)(iVar6 + 0x30c);

        iVar1 = *(int *)(iVar4 + 0x10);

        if ((iVar1 == 0) ||

           ((uint)(*(int *)(iVar4 + 0x18) - iVar1 >> 2) <=

            (uint)(*(int *)(iVar4 + 0x14) - iVar1 >> 2))) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x14));

        }

        else {

          piVar2 = *(int **)(iVar4 + 0x14);

          *piVar2 = *piVar5;

          *(int **)(iVar4 + 0x14) = piVar2 + 1;

        }

      }

      piVar5 = piVar5 + 1;

      param_1 = param_1 + -1;

    } while (param_1 != 0);

    LeaveCriticalSection(lpCriticalSection);

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(iVar4 + 0x10));

}
