// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f5690
// -----------------------------------------------------------------------------
// Stable ID: aa_005f5690
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld
// Address:   0x005f5690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_005f5690.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f5690(int param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  int iVar4;

  

  if (*(int *)(param_1 + 0x28) != *param_2) {

    *(int *)(param_1 + 0x28) = *param_2;

  }

  iVar1 = param_2[4];

  uVar3 = *(uint *)(param_1 + 0x38) & 0x7fffffff;

  if ((int)uVar3 < iVar1) {

    iVar4 = uVar3 * 2;

    if (iVar4 <= iVar1) {

      iVar4 = iVar1;

    }

    FUN_005b3300((int *)(param_1 + 0x30),iVar4,8);

  }

  iVar4 = 0;

  *(int *)(param_1 + 0x34) = iVar1;

  if (0 < param_2[4]) {

    do {

      iVar1 = *(int *)(param_1 + 0x30);

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_2[3] + iVar4 * 8 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar1 + iVar4 * 8) = *(uint32_t /* width from decompiler */ *)(param_2[3] + iVar4 * 8);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar4 * 8) = uVar2;

      iVar4 = iVar4 + 1;

    } while (iVar4 < param_2[4]);

  }

  return;

}
