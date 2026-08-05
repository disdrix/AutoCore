// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055fd80
// -----------------------------------------------------------------------------
// Stable ID: aa_0055fd80
// Callee of Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState
// Address:   0x0055fd80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_0055f190, FUN_0055fd80, FUN_006285a0.
//  - Return sites: 1.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055fd80(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x44);

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

  FUN_006285a0(param_2);

  if ((puVar1[9] != -1) && (puVar1[0x10] == 0)) {

    if (*(char *)((int)puVar1 + 0x29) == '\0') {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + puVar1[9] * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + -4 + *(int *)(param_1 + 0x18) * 4);

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x14) + puVar1[9] * 4) + 0x24) = puVar1[9];

      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;

    }

    else {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + puVar1[9] * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + -4 + *(int *)(param_1 + 0xc) * 4);

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + puVar1[9] * 4) + 0x24) = puVar1[9];

      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

    }

    (**(code **)*puVar1)(1);

  }

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 0x118)) {

    do {

      FUN_0055f190();

      puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x114) + iVar2 * 4);

      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

      if (*(short *)((int)puVar1 + 6) == 0) {

        (**(code **)*puVar1)(1);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < *(int *)(param_1 + 0x118));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 0;

  return;

}
