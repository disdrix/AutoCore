// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_RandomUnitScalar_007a4200
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4200
// Callee of Named_CalleeOf_CVOGReaction_RandomUnitScalar
// Address:   0x007a4200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_RandomUnitScalar: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004248c0×2, FUN_00424890, FUN_007a4200.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_RandomUnitScalar
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_RandomUnitScalar_007a4200(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint uVar4;

  int iVar5;

  

  iVar5 = 0;

  if (*(void **)(param_1 + 8) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  pvVar3 = operator_new__(0x200000);

  *(void **)(param_1 + 8) = pvVar3;

  if (pvVar3 != (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = param_2;

    FUN_00424890();

    FUN_004248c0();

    iVar1 = *(int *)(param_1 + 8);

    do {

      iVar2 = *(int *)(param_1 + 0x14);

      if (*(int *)(iVar2 + 0x9c4) == 0) {

        FUN_004248c0();

      }

      *(int *)(iVar2 + 0x9c4) = *(int *)(iVar2 + 0x9c4) + -1;

      uVar4 = **(uint **)(iVar2 + 0x9c0);

      *(uint **)(iVar2 + 0x9c0) = *(uint **)(iVar2 + 0x9c0) + 1;

      uVar4 = uVar4 ^ uVar4 >> 0xb;

      uVar4 = uVar4 ^ (uVar4 & 0xff3a58ad) << 7;

      uVar4 = uVar4 ^ (uVar4 & 0xffffdf8c) << 0xf;

      *(uint *)(iVar1 + iVar5 * 4) = uVar4 >> 0x12 ^ uVar4;

      iVar5 = iVar5 + 1;

    } while (iVar5 < 0x80000);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    *(uint8_t *)(param_1 + 4) = 1;

  }

  return;

}
