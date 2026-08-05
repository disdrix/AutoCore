// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_hkWorld_005d4050
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4050
// Callee of Named_CalleeOf_Named_hkWorld
// Address:   0x005d4050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_005d4050, FUN_0063f400.
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_hkWorld_005d4050(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if ((*(int **)(param_1 + 0x54) != (int *)0x0) &&

     (iVar2 = (**(code **)(**(int **)(param_1 + 0x54) + 0x1c))(), iVar2 == param_2)) {

    return;

  }

  if (param_2 == 1) {

    _DAT_00af4f8e = _DAT_00af4f8e + 1;

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

    if ((puVar3 != (uint32_t /* width from decompiler */ *)0x0) &&

       (*(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1,

       *(short *)((int)puVar3 + 6) == 0)) {

      (**(code **)*puVar3)(1);

    }

    *(undefined ***)(param_1 + 0x54) = &PTR_PTR_00af4f88;

  }

  else if (param_2 == 2) {

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x60,0x26);

    *(uint16_t *)(iVar2 + 4) = 0x60;

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0063f400(param_1);

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;

    }

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

    if ((puVar1 != (uint32_t /* width from decompiler */ *)0x0) &&

       (*(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1,

       *(short *)((int)puVar1 + 6) == 0)) {

      (**(code **)*puVar1)(1);

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x54) = puVar3;

    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

    if (*(short *)((int)puVar3 + 6) == 0) {

      (**(code **)*puVar3)(1);

      return;

    }

  }

  return;

}
