// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_0096ac60
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ac60
// Callee of Named_gfxBodyMassageMachine
// Address:   0x0096ac60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, do×2, return×1, goto×1.
//  - Notable callees: FUN_0096ac60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

void Named_CalleeOf_Named_gfxBodyMassageMachine_0096ac60(void)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  int in_EAX;

  int *piVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  

  piVar4 = *(int **)(in_EAX + 0xc);

  iVar6 = 0;

  if (piVar4 != *(int **)(in_EAX + 0x10)) {

    do {

      iVar3 = *piVar4;

      *(int *)(iVar3 + 0x144) = iVar6;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x150) = 0;

      if (-1 < *(int *)(iVar3 + 0x148)) {

        piVar2 = (int *)(*(int *)(*(int *)(in_EAX + 0xc) + *(int *)(iVar3 + 0x148) * 4) + 0x150);

        *piVar2 = *piVar2 + 1;

      }

      piVar4 = piVar4 + 1;

      iVar6 = iVar6 + 1;

    } while (piVar4 != *(int **)(in_EAX + 0x10));

  }

  uVar1 = 0;

LAB_0096acb1:

  do {

    uVar7 = uVar1;

    iVar6 = *(int *)(in_EAX + 0xc);

    if ((iVar6 == 0) || ((uint)(*(int *)(in_EAX + 0x10) - iVar6 >> 2) <= uVar7)) {

      return;

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + uVar7 * 4) + 0x14c) = 0xffffffff;

    uVar1 = uVar7 + 1;

    uVar5 = uVar1;

    while( true ) {

      if ((*(int *)(in_EAX + 0xc) == 0) ||

         ((uint)(*(int *)(in_EAX + 0x10) - *(int *)(in_EAX + 0xc) >> 2) <= uVar5))

      goto LAB_0096acb1;

      if (*(int *)(*(int *)(*(int *)(in_EAX + 0xc) + uVar5 * 4) + 0x148) ==

          *(int *)(*(int *)(*(int *)(in_EAX + 0xc) + uVar7 * 4) + 0x148)) break;

      uVar5 = uVar5 + 1;

    }

    *(uint *)(*(int *)(*(int *)(in_EAX + 0xc) + uVar7 * 4) + 0x14c) = uVar5;

  } while( true );

}
