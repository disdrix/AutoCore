// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004ce230
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce230
// Callee of Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x004ce230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, for×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_004ce020, FUN_004ce230, FUN_007a4200.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Server_needs_an_update
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004ce230(int param_1,int param_2)



{

  ushort uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  if (param_2 != 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x80);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x84);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x120) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x88);

    uVar1 = 0;

    if (*(short *)(param_2 + 0x8a8) != 0) {

      do {

        puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + ((uint)uVar1 * 3 + 0x117) * 8);

        puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0x950 + (uint)uVar1 * 0x18);

        *puVar4 = *puVar3;

        puVar4[1] = puVar3[1];

        puVar4[2] = puVar3[2];

        puVar4[3] = puVar3[3];

        puVar4[4] = puVar3[4];

        uVar1 = uVar1 + 1;

        puVar4[5] = puVar3[5];

      } while (uVar1 < *(ushort *)(param_2 + 0x8a8));

    }

    puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 8);

    puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0xa0);

    for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)(param_1 + 0x940) = *(uint16_t *)(param_2 + 0x8a8);

    uVar5 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = uVar5;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x948) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8b0);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x94c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8b4);

    CVOGReaction_RandomUnitScalar(uVar5);

    FUN_007a4200(uVar5);

    FUN_004ce020(param_2 + 0x1c);

    *(uint8_t *)(param_1 + 0x7c) = *(uint8_t *)(param_2 + 0x14);

  }

  return;

}
