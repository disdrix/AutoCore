// =============================================================================
// FUN_00797a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00797a60
// Address:   0x00797a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00797a60 @ 0x00797a60
// Stable ID: aa_00797a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×9, for×1, return×1.
//  - Notable callees: FUN_00426ff0×2, FUN_00797440×2, FUN_004270d0, FUN_00797530, FUN_00797a60.
//  - Return sites: 1.

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

void FUN_00797a60(int param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float fVar4;

  float fVar5;

  uint32_t /* width from decompiler */ local_20 [8];

  

  if (param_1 != 0) {

    if (*(float *)(in_EAX + 0xa8) != 0.0) {

      *(float *)(in_EAX + 0xa4) = *(float *)(in_EAX + 0xa8) + *(float *)(in_EAX + 0xa4);

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0xa8) = 0;

    }

    if (*(char *)(in_EAX + 0xb4) != '\0') {

      *(uint8_t *)(in_EAX + 0xb4) = 0;

      FUN_00797440();

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc0) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc4) = DAT_00afdf0c;

    *(uint8_t *)(in_EAX + 0xbc) = 0;

    puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x60);

    puVar3 = local_20;

    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

    FUN_004270d0();

    fVar4 = (float)(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8));

    if (*(float *)(in_EAX + 0xac) <= fVar4 && fVar4 != *(float *)(in_EAX + 0xac)) {

      *(float *)(in_EAX + 0xac) = fVar4;

    }

    fVar4 = (float)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4) + *(int *)(param_1 + 0x24));

    if (*(float *)(in_EAX + 0xa0) <= fVar4 && fVar4 != *(float *)(in_EAX + 0xa0)) {

      *(float *)(in_EAX + 0xa0) = fVar4;

    }

    fVar5 = *(float *)(in_EAX + 0xa4) + fVar4;

    if (*(float *)(in_EAX + 0xa0) <= fVar5 && fVar5 != *(float *)(in_EAX + 0xa0)) {

      if ((*(int *)(in_EAX + 0x94) != 0) &&

         ((*(int *)(in_EAX + 0x98) - *(int *)(in_EAX + 0x94)) / 0x60 != 0)) {

        FUN_00426ff0();

      }

      FUN_00797530(0);

    }

    if (*(char *)(in_EAX + 0xb4) != '\0') {

      *(uint8_t *)(in_EAX + 0xb4) = 0;

      FUN_00797440();

      if ((*(int *)(in_EAX + 0x94) != 0) &&

         ((*(int *)(in_EAX + 0x98) - *(int *)(in_EAX + 0x94)) / 0x60 != 0)) {

        FUN_00426ff0();

      }

    }

    *(float *)(in_EAX + 0xa4) = *(float *)(in_EAX + 0xa8) + *(float *)(in_EAX + 0xa4) + fVar4;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xa8) = 0;

  }

  return;

}
