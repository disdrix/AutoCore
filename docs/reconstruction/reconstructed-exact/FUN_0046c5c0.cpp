// =============================================================================
// FUN_0046c5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c5c0
// Address:   0x0046c5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046c5c0 @ 0x0046c5c0
// Stable ID: aa_0046c5c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1, goto×1.
//  - Notable callees: FUN_0043c2e0, FUN_0044aa90, FUN_0046c5c0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * FUN_0046c5c0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *unaff_EBX;

  bool bVar4;

  

  puVar1 = param_1;

  puVar3 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  bVar4 = true;

  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      puVar3 = puVar2;

      bVar4 = (*unaff_EBX << 0x10 | unaff_EBX[1]) < (int)(puVar3[3] << 0x10 | puVar3[4]);

      if (bVar4) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

      }

    } while (*(char *)((int)puVar2 + 0x19) == '\0');

  }

  param_1 = puVar3;

  if (bVar4) {

    if (puVar3 == (uint32_t /* width from decompiler */ *)**(int **)(in_EAX + 4)) {

      bVar4 = true;

      goto LAB_0046c649;

    }

    FUN_0044aa90();

  }

  if ((*unaff_EBX << 0x10 | unaff_EBX[1]) <= (int)(param_1[3] << 0x10 | param_1[4])) {

    *puVar1 = param_1;

    *(uint8_t *)(puVar1 + 1) = 0;

    return puVar1;

  }

LAB_0046c649:

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043c2e0(&param_1,bVar4,puVar3,unaff_EBX);

  *puVar1 = *puVar3;

  *(uint8_t *)(puVar1 + 1) = 1;

  return puVar1;

}
