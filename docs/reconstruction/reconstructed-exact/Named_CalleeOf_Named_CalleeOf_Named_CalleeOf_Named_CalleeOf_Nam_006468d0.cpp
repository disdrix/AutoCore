// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006468d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006468d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic
// Address:   0x006468d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic: callee helper. Evidence string: "unnamed_". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "unnamed_"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00632580, FUN_00638100, FUN_00646670, FUN_006468d0.
//  - Strings: "unnamed_".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic
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

int * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006468d0(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int *piVar2;

  char *pcVar3;

  int iVar4;

  int *unaff_ESI;

  

  iVar4 = param_2;

  if (*(int *)(param_2 + 0x14) != 0) {

    iVar1 = FUN_00646670(param_2,param_3);

    if (iVar1 == 0) {

      piVar2 = (int *)FUN_00632580(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x18));

      pcVar3 = (char *)FUN_00638100(&param_2,"unnamed_");

      if (*pcVar3 == '\0') {

        (**(code **)(*piVar2 + 8))(*(uint32_t /* width from decompiler */ *)(iVar4 + 0xc));

      }

      (**(code **)(*param_1 + 4))(piVar2,*(uint32_t /* width from decompiler */ *)(iVar4 + 0xc));

      *(short *)((int)piVar2 + 6) = *(short *)((int)piVar2 + 6) + -1;

      if (*(short *)((int)piVar2 + 6) == 0) {

        (**(code **)*piVar2)(1);

      }

      if (*(int *)(*(int *)(iVar4 + 0x10) + -0xc) != 0) {

        iVar4 = (**(code **)(*(int *)param_1[4] + 4))(*(int *)(iVar4 + 0x10),&stack0xfffffffc);

        if (iVar4 == 0) {

          (**(code **)(*unaff_ESI + 0x10))(piVar2);

        }

      }

      return piVar2;

    }

  }

  return (int *)0x0;

}
