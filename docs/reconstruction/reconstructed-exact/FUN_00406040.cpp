// =============================================================================
// FUN_00406040
// -----------------------------------------------------------------------------
// Stable ID: aa_00406040
// Address:   0x00406040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00406040 @ 0x00406040
// Stable ID: aa_00406040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_00406c40×2, FUN_00406040, FUN_004cb4f0.
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

void __thiscall FUN_00406040(int param_1,uint32_t /* width from decompiler */ *param_2,uint *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  bool bVar5;

  

  puVar2 = param_3;

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar5 = true;

  if (*(char *)((int)puVar4[1] + 0x29) == '\0') {

    puVar3 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      puVar4 = puVar3;

      bVar5 = *param_3 < (uint)puVar4[4];

      if (bVar5) {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar4;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar4[2];

      }

    } while (*(char *)((int)puVar3 + 0x29) == '\0');

  }

  param_3 = puVar4;

  if (bVar5) {

    if (puVar4 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00406c40(&param_3,1,puVar4,puVar2);

      uVar1 = *puVar4;

      *(uint8_t *)(param_2 + 1) = 1;

      *param_2 = uVar1;

      return;

    }

    FUN_004cb4f0();

  }

  if (param_3[4] < *puVar2) {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00406c40(&param_3,bVar5,puVar4,puVar2);

    *param_2 = *puVar4;

    *(uint8_t *)(param_2 + 1) = 1;

    return;

  }

  *(uint8_t *)(param_2 + 1) = 0;

  *param_2 = param_3;

  return;

}
