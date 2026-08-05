// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00680c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00680c80
// Callee of Named_CalleeOf_Named_AudioOutThread (+1 other named callers)
// Address:   0x00680c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_AudioOutThread (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, for×4, return×2.
//  - Notable callees: FUN_00680c80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_AudioOutThread (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00680c80(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (*(uint *)(param_1 + 0xc) < param_3) {

    param_3 = *(uint *)(param_1 + 0xc);

  }

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 4));

    for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

      *param_2 = *puVar3;

      puVar3 = puVar3 + 1;

      param_2 = param_2 + 1;

    }

    for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

      *(uint8_t *)param_2 = *(uint8_t *)puVar3;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    }

  }

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) - param_3;

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_3;

  uVar1 = *(uint *)(param_1 + 0xc);

  if (*(char *)(param_1 + 0x18) != '\0') {

    if (uVar1 != 0) {

      if (*(uint *)(param_1 + 0x10) <= uVar1) {

        return;

      }

      puVar3 = (uint32_t /* width from decompiler */ *)(*(uint *)(param_1 + 0x10) + (int)*(uint32_t /* width from decompiler */ **)(param_1 + 4));

      puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

      for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

        *(uint8_t *)puVar4 = *(uint8_t *)puVar3;

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      }

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  }

  return;

}
