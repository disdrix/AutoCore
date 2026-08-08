// =============================================================================
// RETIRED SCAFFOLD — do not use as canonical clean
// Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00402b30
// SUPERSEDED BY: StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.cpp
//                (MEGA-040 dual 2026-08-05 — xref-seed product name rejected)
// Address:   0x00402b30  (autoassault.exe, image base 0x400000)
// Kept for history only; prefer named clean + FUN_00402b30.cpp twin.
// =============================================================================

// PURPOSE (auto): Called from Client_NotifyActiveMissionChanged: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_00403250×2, FUN_00402b30, FUN_00404290.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_NotifyActiveMissionChanged
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint *unaff_EBX;

  bool bVar3;

  

  puVar1 = param_1;

  param_1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  bVar3 = true;

  if (*(char *)((int)param_1[1] + 0x31) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[1];

    do {

      param_1 = puVar2;

      bVar3 = *unaff_EBX < (uint)param_1[4];

      if (bVar3) {

        puVar2 = (uint32_t /* width from decompiler */ *)*param_1;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)param_1[2];

      }

    } while (*(char *)((int)puVar2 + 0x31) == '\0');

  }

  if (bVar3) {

    if (param_1 == (uint32_t /* width from decompiler */ *)**(int **)(in_EAX + 4)) {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00403250(&param_1,1,unaff_EBX);

      *puVar1 = *puVar2;

      *(uint8_t *)(puVar1 + 1) = 1;

      return puVar1;

    }

    FUN_00404290();

  }

  if ((uint)param_1[4] < *unaff_EBX) {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00403250(&param_1,bVar3,unaff_EBX);

    *puVar1 = *puVar2;

    *(uint8_t *)(puVar1 + 1) = 1;

    return puVar1;

  }

  *puVar1 = param_1;

  *(uint8_t *)(puVar1 + 1) = 0;

  return puVar1;

}
