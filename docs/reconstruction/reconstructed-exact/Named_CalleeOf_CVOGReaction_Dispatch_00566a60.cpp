// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_00566a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00566a60
// Callee of CVOGReaction_Dispatch
// Address:   0x00566a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, return×1, goto×1, while×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_00566490, FUN_00566a60, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

void __thiscall Named_CalleeOf_CVOGReaction_Dispatch_00566a60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint8_t uStack_d;

  int *local_c;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  FUN_00566490(param_2,0,0xffffffff);

  local_8 = 0;

  local_4 = param_1 + 0xb4;

  FUN_004294f0();

  iVar3 = FUN_004022a0(&local_8,&local_c);

  iVar5 = param_1 + 0xb4;

  piVar2 = local_c;

  do {

    if (iVar3 != 0) {

      if (*(char *)(iVar5 + 0x28) != '\0') {

        *(uint8_t *)(iVar5 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 4));

      }

      return;

    }

    local_c = piVar2;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar2 + 0x1c8))();

    if ((puVar4 != (uint32_t /* width from decompiler */ *)0x0) &&

       ((*(byte *)(*(int *)(puVar4[1] + 4) + 0x180 + (int)puVar4) & 1) == 0)) {

      if (((char)param_2 != '\0') &&

         (((iVar5 = (**(code **)(*(int *)(*(int *)(puVar4[1] + 4) + 4 + (int)puVar4) + 0x1d8))(),

           iVar5 != 0 &&

           (iVar5 = (**(code **)(*(int *)(*(int *)(puVar4[1] + 4) + 4 + (int)puVar4) + 0x1d8))(),

           iVar5 != 0)) && (*(char *)(iVar5 + 0x204) == '\0')))) {

        iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

        if (*(int *)(iVar5 + 0x250) == 0) {

          piVar1 = (int *)(iVar3 + 0x28);

          *piVar1 = *piVar1 + 1;

        }

        else {

          piVar1 = (int *)(iVar3 + 0x2c);

          *piVar1 = *piVar1 + 1;

        }

        *(uint8_t *)(iVar5 + 0x204) = 1;

        uStack_d = 1;

        CVOGSpawnPoint_SetObjectActiveState

                  (*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&uStack_d,0);

      }

      if (puVar4[2] == 0) {

        if (*(int *)(piVar2[0x2a] + 0x38) == 0xe) {

          iVar5 = (**(code **)(*piVar2 + 0x1d4))();

          *(uint8_t *)(iVar5 + 0x114) = 1;

        }

        else {

          iVar5 = (**(code **)(*piVar2 + 0x1d8))();

          if ((iVar5 != 0) &&

             (iVar5 = (**(code **)(*piVar2 + 0x1d8))(), *(int *)(iVar5 + 0x250) != 0))

          goto LAB_00566bcc;

        }

        (**(code **)*puVar4)

                  (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),

                   (int)puVar4 + *(int *)(puVar4[1] + 4) + 0x84,

                   (int)puVar4 + *(int *)(puVar4[1] + 4) + 0x94,0);

      }

    }

LAB_00566bcc:

    iVar3 = FUN_004022a0(&local_8,&local_c);

    iVar5 = local_4;

    piVar2 = local_c;

  } while( true );

}
