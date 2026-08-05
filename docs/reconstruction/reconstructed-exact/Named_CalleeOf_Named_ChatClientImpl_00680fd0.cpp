// =============================================================================
// Named_CalleeOf_Named_ChatClientImpl_00680fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00680fd0
// Callee of Named_ChatClientImpl
// Address:   0x00680fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ChatClientImpl: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: FUN_00680e30, FUN_00680fd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ChatClientImpl
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

int __thiscall Named_CalleeOf_Named_ChatClientImpl_00680fd0(int param_1,int param_2)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (param_1 != param_2) {

    if (*(int *)(param_2 + 0xc) != 0) {

      FUN_00680e30(*(int *)(param_2 + 0xc));

      uVar2 = *(uint *)(param_2 + 0xc);

      puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 4));

      puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

      for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(uint8_t *)puVar4 = *(uint8_t *)puVar3;

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      }

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  }

  return param_1;

}
