// =============================================================================
// FUN_00402b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00402b30
// Address:   0x00402b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00402b30 @ 0x00402b30
// Stable ID: aa_00402b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_00403250×2, FUN_00402b30, FUN_00404290.
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

uint32_t /* width from decompiler */ * FUN_00402b30(uint32_t /* width from decompiler */ *param_1)



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
