// =============================================================================
// FUN_00441660
// -----------------------------------------------------------------------------
// Stable ID: aa_00441660
// Address:   0x00441660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00441660 @ 0x00441660
// Stable ID: aa_00441660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_004417e0×2, FUN_00441660, FUN_00442540.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * FUN_00441660(uint32_t /* width from decompiler */ *param_1)



{

  bool bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  int *unaff_EBX;

  

  puVar2 = param_1;

  param_1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  bVar1 = true;

  if (*(char *)((int)param_1[1] + 0x1d) == '\0') {

    puVar3 = (uint32_t /* width from decompiler */ *)param_1[1];

    do {

      param_1 = puVar3;

      bVar1 = *unaff_EBX < (int)param_1[3];

      if (bVar1) {

        puVar3 = (uint32_t /* width from decompiler */ *)*param_1;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)param_1[2];

      }

    } while (*(char *)((int)puVar3 + 0x1d) == '\0');

  }

  if (bVar1) {

    if (param_1 == (uint32_t /* width from decompiler */ *)**(int **)(in_EAX + 4)) {

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_004417e0(&param_1,1,unaff_EBX);

      *puVar2 = *puVar3;

      *(uint8_t *)(puVar2 + 1) = 1;

      return puVar2;

    }

    FUN_00442540();

  }

  if ((int)param_1[3] < *unaff_EBX) {

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_004417e0(&param_1,bVar1,unaff_EBX);

    *puVar2 = *puVar3;

    *(uint8_t *)(puVar2 + 1) = 1;

    return puVar2;

  }

  *puVar2 = param_1;

  *(uint8_t *)(puVar2 + 1) = 0;

  return puVar2;

}
