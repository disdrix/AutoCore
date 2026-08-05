// =============================================================================
// Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_005408f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005408f0
// Callee of Skill_Skill_d_has_invalid_frequency_d
// Address:   0x005408f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_has_invalid_frequency_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0054b480×2, FUN_00418890, FUN_004a16d0, FUN_004a6390, FUN_00540090, FUN_005408f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_has_invalid_frequency_d
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_005408f0(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int local_404;

  uint8_t local_400 [1024];

  

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0c) + 0x10) +

                           (*(uint *)(*(int *)(param_1 + 0xf0c) + 8) & param_2) * 4) + 4);

  if (iVar2 == 0) {

LAB_00540927:

    iVar2 = 0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar2 + 0x10)) {

        if (iVar2 == 0) goto LAB_00540927;

        iVar2 = *(int *)(iVar2 + 8);

        goto LAB_0054092e;

      }

      iVar2 = *(int *)(iVar2 + 0xc);

    } while (iVar2 != 0);

    iVar2 = 0;

  }

LAB_0054092e:

  if (iVar2 == 0) {

    return 0;

  }

  if (*(char *)(iVar2 + 10) == '\0') {

    puVar4 = &param_2;

    piVar3 = &local_404;

    FUN_0054b480(piVar3,puVar4);

    FUN_00418890(piVar3,puVar4);

    iVar2 = FUN_0054b480();

    if (local_404 != *(int *)(iVar2 + 4)) {

      FUN_00540090(local_404 + 0x10,local_400,0x400);

      FUN_004a6390(local_400);

    }

  }

  uVar1 = FUN_004a16d0(param_3,param_4,0xffffffff);

  return uVar1;

}
