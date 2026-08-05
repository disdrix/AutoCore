// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_netSession_00680e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00680e80
// Callee of Named_CalleeOf_Named_netSession
// Address:   0x00680e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_netSession: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×2.
//  - Notable callees: FUN_00680e80, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_netSession
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_netSession_00680e80(int param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if (*(uint *)(param_1 + 8) < param_2) {

    if ((char)param_2 != '\0') {

      param_2 = ((param_2 >> 8) + 1) * 0x100;

    }

    puVar1 = operator_new__(param_2);

    uVar3 = *(uint *)(param_1 + 0xc);

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10));

    puVar5 = puVar1;

    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

    *(uint *)(param_1 + 8) = param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    operator_delete__(*(void **)(param_1 + 4));

    *(uint32_t /* width from decompiler */ **)(param_1 + 4) = puVar1;

  }

  else if (*(int *)(param_1 + 0x10) != 0) {

    memmove(*(void **)(param_1 + 4),

            (void *)(*(int *)(param_1 + 0x10) + (int)*(void **)(param_1 + 4)),

            *(size_t *)(param_1 + 0xc));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    return;

  }

  return;

}
