// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055fa40
// -----------------------------------------------------------------------------
// Stable ID: aa_0055fa40
// Callee of Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState
// Address:   0x0055fa40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_0055f4c0×2, FUN_006297e0×2, FUN_0055fa40, FUN_0062d960, FUN_006caaa0, block.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState
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

/* WARNING: Removing unreachable block (ram,0x0055fb6c) */



void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055fa40(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  float fVar3;

  uint8_t auStack_6c [12];

  uint8_t local_60 [20];

  undefined **ppuStack_4c;

  uint32_t /* width from decompiler */ *puStack_48;

  uint8_t *puStack_44;

  int iStack_40;

  int iStack_3c;

  uint8_t auStack_38 [52];

  

  if (*(int *)(param_2 + 0xc) != 0) {

    FUN_0062d960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

    fVar3 = *(float *)(*(int *)(param_1 + 0xcc) + 8) * DAT_00a0f298;

    iVar1 = *(int *)(param_2 + 0x14) + 0x20;

    (**(code **)(**(int **)(param_2 + 0xc) + 0x18))(iVar1,fVar3,local_60);

    (**(code **)(**(int **)(param_1 + 0xc4) + 4))(param_2 + 0x1c,auStack_6c,&stack0xffffff80);

    if (0 < (int)fVar3) {

      if (*(char *)(param_2 + 0x40) == '\0') {

        FUN_006297e0(iVar1,fVar3,0,0);

      }

      else {

        puStack_44 = auStack_38;

        ppuStack_4c = &PTR_FUN_009d2820;

        iStack_40 = 0;

        iStack_3c = -0x7ffffffc;

        *(undefined ****)(*(int *)(param_1 + 0x138) + 0x24) = &ppuStack_4c;

        if (*(int *)(param_1 + 0xd0) == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 0xd0) + 8;

        }

        puStack_48 = (uint32_t /* width from decompiler */ *)(param_2 + 0xc);

        FUN_006caaa0(iVar1,fVar3,0,0,iVar2);

        *(int *)(*(int *)(param_1 + 0x138) + 0x24) = *(int *)(param_1 + 0x138) + 0x100;

        if (0 < iStack_40) {

          iVar1 = 0;

          do {

            iVar2 = *(int *)(puStack_44 + iVar1 * 4);

            FUN_006297e0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x80),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x84),0,0);

            iVar1 = iVar1 + 1;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x84) = 0;

          } while (iVar1 < iStack_40);

        }

        if (-1 < iStack_3c) {

          (**(code **)(*DAT_00b05060 + 0x14))(puStack_44,iStack_3c * 4,0x12);

          FUN_0055f4c0();

          return;

        }

      }

    }

    FUN_0055f4c0();

  }

  return;

}
