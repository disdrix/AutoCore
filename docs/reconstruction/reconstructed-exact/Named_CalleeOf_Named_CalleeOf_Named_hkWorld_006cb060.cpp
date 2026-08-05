// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_hkWorld_006cb060
// -----------------------------------------------------------------------------
// Stable ID: aa_006cb060
// Callee of Named_CalleeOf_Named_hkWorld
// Address:   0x006cb060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006cb060.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_hkWorld
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_hkWorld_006cb060(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  

  piVar2 = (int *)(param_3 * 0x20 + 0xc + param_1);

  piVar4 = (int *)(param_1 + 0xc + param_3 * 4);

  iVar3 = 8;

  do {

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

    puVar1 = (uint32_t /* width from decompiler */ *)*piVar4;

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

    *piVar4 = param_2;

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

    puVar1 = (uint32_t /* width from decompiler */ *)*piVar2;

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

    *piVar2 = param_2;

    piVar2 = piVar2 + 1;

    piVar4 = piVar4 + 8;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
