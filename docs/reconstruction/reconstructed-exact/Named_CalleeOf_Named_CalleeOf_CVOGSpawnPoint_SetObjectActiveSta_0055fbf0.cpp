// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055fbf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055fbf0
// Callee of Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState
// Address:   0x0055fbf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_0055f4c0×2, FUN_006297e0×2, FUN_0055fbf0, FUN_0062d960, FUN_006caaa0, block.
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

/* WARNING: Removing unreachable block (ram,0x0055fcee) */



void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055fbf0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_38;

  int iStack_34;

  undefined **ppuStack_24;

  int iStack_20;

  uint8_t *puStack_1c;

  int iStack_18;

  int iStack_14;

  uint8_t auStack_10 [16];

  

  FUN_0062d960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

  if ((*(int *)(param_2 + 0xc) != 0) &&

     ((**(code **)(**(int **)(param_1 + 0xc4) + 0xc))(param_2 + 0x1c,&local_38), 0 < iStack_34)) {

    if (*(char *)(param_2 + 0x40) == '\0') {

      FUN_006297e0(0,0,local_38,iStack_34);

    }

    else {

      puStack_1c = auStack_10;

      ppuStack_24 = &PTR_FUN_009d2820;

      iStack_18 = 0;

      iStack_14 = -0x7ffffffc;

      *(undefined ****)(*(int *)(param_1 + 0x138) + 0x24) = &ppuStack_24;

      if (*(int *)(param_1 + 0xd0) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(param_1 + 0xd0) + 8;

      }

      iStack_20 = param_2 + 0xc;

      FUN_006caaa0(0,0,local_38,iStack_34,iVar2);

      iVar2 = 0;

      *(int *)(*(int *)(param_1 + 0x138) + 0x24) = *(int *)(param_1 + 0x138) + 0x100;

      if (0 < iStack_18) {

        do {

          iVar1 = *(int *)(puStack_1c + iVar2 * 4);

          FUN_006297e0(0,0,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x8c),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x90));

          iVar2 = iVar2 + 1;

          *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = 0;

        } while (iVar2 < iStack_18);

      }

      if (-1 < iStack_14) {

        (**(code **)(*DAT_00b05060 + 0x14))(puStack_1c,iStack_14 * 4,0x12);

        FUN_0055f4c0();

        return;

      }

    }

  }

  FUN_0055f4c0();

  return;

}
