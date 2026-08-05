// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_007231a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007231a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn
// Address:   0x007231a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: EnterCriticalSection, FUN_0071f010, FUN_0071f810, FUN_007231a0, LeaveCriticalSection.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_007231a0(void)



{

  void *pvVar1;

  int unaff_EBX;

  int iVar2;

  int *piVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abdeb;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x3f8));

  iVar2 = 0;

  local_4 = 0;

  if (0 < *(int *)(unaff_EBX + 0x210)) {

    piVar3 = (int *)(unaff_EBX + 0x31c);

    do {

      if ((*piVar3 != 0) && (*(int *)(*piVar3 + 0x30) == *(int *)(unaff_EBX + 0x414))) {

        FUN_0071f810();

        if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

        }

        *piVar3 = 0;

      }

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar2 < *(int *)(unaff_EBX + 0x210));

  }

  iVar2 = *(int *)(unaff_EBX + 0x70 + *(int *)(unaff_EBX + 0x414) * 4);

  if (*(int *)(iVar2 + 0x108) == 2) {

    *(int *)(unaff_EBX + 0x20c) =

         *(int *)(unaff_EBX + 0x20c) - *(int *)(*(int *)(iVar2 + 0x104) + 0x20);

  }

  pvVar1 = *(void **)(*(int *)(unaff_EBX + 0x70 + *(int *)(unaff_EBX + 0x414) * 4) + 0x104);

  if (pvVar1 == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 0x70 + *(int *)(unaff_EBX + 0x414) * 4) + 0x104) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x3f8));

    ExceptionList = pvStack_c;

    return;

  }

  FUN_0071f010();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
