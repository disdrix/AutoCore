// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00720180
// -----------------------------------------------------------------------------
// Stable ID: aa_00720180
// Callee of Named_Client_InitInstance
// Address:   0x00720180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, return×1.
//  - Notable callees: FUN_0071f810×2, EnterCriticalSection, FUN_00720180, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_Client_InitInstance_00720180(int param_1,int param_2,char param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab67c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x158));

  local_4 = 0;

  if (*(char *)(param_1 + 0x10) != '\0') {

    if (param_2 == -1) {

      piVar4 = (int *)(param_1 + 0x80);

      iVar3 = 2;

      do {

        if (*piVar4 != 0) {

          *(uint8_t *)(*piVar4 + 0x38) = 1;

          *(uint32_t /* width from decompiler */ *)(*piVar4 + 0x1b0) = 0;

          if (param_3 != '\0') {

            FUN_0071f810();

            puVar1 = *(uint32_t /* width from decompiler */ **)(*piVar4 + 0x10);

            piVar2 = (int *)0x0;

            if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

              if (*(int *)(*piVar4 + 0x1c) == 0) {

                piVar2 = (int *)0x0;

              }

              else {

                piVar2 = (int *)*puVar1;

              }

            }

            (**(code **)(*piVar2 + 0x48))(piVar2);

          }

        }

        piVar4 = piVar4 + 1;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

    else {

      iVar3 = *(int *)(param_1 + 0x80 + param_2 * 4);

      if (iVar3 != 0) {

        *(uint8_t *)(iVar3 + 0x38) = 1;

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x80 + param_2 * 4) + 0x1b0) = 0;

        if (param_3 != '\0') {

          FUN_0071f810();

          iVar3 = *(int *)(param_1 + 0x80 + param_2 * 4);

          puVar1 = *(uint32_t /* width from decompiler */ **)(iVar3 + 0x10);

          if ((puVar1 == (uint32_t /* width from decompiler */ *)0x0) || (*(int *)(iVar3 + 0x1c) == 0)) {

            piVar4 = (int *)0x0;

          }

          else {

            piVar4 = (int *)*puVar1;

          }

          (**(code **)(*piVar4 + 0x48))(piVar4);

        }

      }

    }

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x158));

  ExceptionList = pvStack_c;

  return 0;

}
