// =============================================================================
// Named_CalleeOf_Named_gfxBody_00435df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00435df0
// Callee of Named_gfxBody (+6 other named callers)
// Address:   0x00435df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxBody (+6 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×1.
//  - Notable callees: memmove×2, FUN_00435df0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxBody (+6 other named callers)
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

void __thiscall Named_CalleeOf_Named_gfxBody_00435df0(uint32_t /* width from decompiler */ *param_1,size_t param_2)



{

  int iVar1;

  size_t sVar2;

  int *piVar3;

  size_t *psVar4;

  size_t _Size;

  

  sVar2 = param_2;

  iVar1 = param_1[2];

  if (iVar1 <= (int)param_2) {

    if ((int)param_2 < param_1[3] + iVar1) {

      _Size = param_1[3] - (param_2 - iVar1);

      memmove(param_1 + 6,(void *)((param_2 - iVar1) + 0x18 + (int)param_1),_Size);

      piVar3 = param_1 + 4;

      param_1[2] = sVar2;

      param_2 = param_1[5] - sVar2;

      if ((int)(param_1[5] - sVar2) <= *piVar3) {

        piVar3 = (int *)&param_2;

      }

      iVar1 = *piVar3;

      param_1[3] = iVar1;

      param_1[1] = 0;

      (**(code **)(*(int *)*param_1 + 4))(_Size + sVar2,0);

      (**(code **)(*(int *)*param_1 + 0x14))(_Size + 0x18 + (int)param_1,iVar1 - _Size);

      return;

    }

    if (iVar1 <= (int)param_2) goto LAB_00435ee4;

  }

  if (iVar1 <= (int)(param_1[4] + param_2)) {

    param_2 = (param_1[4] - iVar1) + param_2;

    psVar4 = param_1 + 3;

    if ((int)param_2 < (int)param_1[3]) {

      psVar4 = &param_2;

    }

    memmove((void *)((iVar1 - sVar2) + 0x18 + (int)param_1),param_1 + 6,*psVar4);

    piVar3 = param_1 + 4;

    param_1[2] = sVar2;

    param_2 = param_1[5] - sVar2;

    if ((int)(param_1[5] - sVar2) <= *piVar3) {

      piVar3 = (int *)&param_2;

    }

    param_1[3] = *piVar3;

    param_1[1] = 0;

    (**(code **)(*(int *)*param_1 + 4))(sVar2,0);

    (**(code **)(*(int *)*param_1 + 0x14))(param_1 + 6,iVar1 - sVar2);

    return;

  }

LAB_00435ee4:

  param_1[2] = param_2;

  param_1[1] = 0;

  (**(code **)(*(int *)*param_1 + 4))(param_2,0);

  piVar3 = param_1 + 4;

  if ((int)(param_1[5] - param_1[2]) <= *piVar3) {

    piVar3 = (int *)&stack0xfffffffc;

  }

  iVar1 = *piVar3;

  param_1[3] = iVar1;

  (**(code **)(*(int *)*param_1 + 0x14))(param_1 + 6,iVar1);

  return;

}
