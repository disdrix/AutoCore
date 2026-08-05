// =============================================================================
// Named_CalleeOf_Named_effEffect_0043ee60
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ee60
// Callee of Named_effEffect
// Address:   0x0043ee60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: for×2, return×2, if×1.
//  - Notable callees: FUN_0043ee60.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effEffect
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_effEffect_0043ee60(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  ushort uVar2;

  int *in_EAX;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (-1 < param_1) {

    iVar1 = *(int *)(*(int *)(*in_EAX + 8) + 0x10) + param_1 * 8;

    uVar2 = *(ushort *)(iVar1 + 6);

    puVar4 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar1 + 4) + *(int *)(*in_EAX + 0xc));

    for (uVar3 = (uint)(uVar2 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {

      *param_2 = *puVar4;

      puVar4 = puVar4 + 1;

      param_2 = param_2 + 1;

    }

    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)param_2 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    }

    return 0;

  }

  return 0xffffffff;

}
