// =============================================================================
// FUN_005aed20
// -----------------------------------------------------------------------------
// Stable ID: aa_005aed20
// Address:   0x005aed20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005aed20 @ 0x005aed20
// Stable ID: aa_005aed20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_005ae4e0×2, FUN_005ae050, FUN_005aed20.
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

void __thiscall FUN_005aed20(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  bool bVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  piVar3 = param_3;

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar2 = true;

  if (*(char *)((int)puVar5[1] + 0x19) == '\0') {

    puVar4 = (uint32_t /* width from decompiler */ *)puVar5[1];

    do {

      puVar5 = puVar4;

      bVar2 = *param_3 < (int)puVar5[3];

      if (bVar2) {

        puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

      }

      else {

        puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

      }

    } while (*(char *)((int)puVar4 + 0x19) == '\0');

  }

  param_3 = puVar5;

  if (bVar2) {

    if (puVar5 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_005ae4e0(&param_3,1,puVar5,piVar3);

      uVar1 = *puVar5;

      *(uint8_t *)(param_2 + 1) = 1;

      *param_2 = uVar1;

      return;

    }

    FUN_005ae050();

  }

  if (param_3[3] < *piVar3) {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_005ae4e0(&param_3,bVar2,puVar5,piVar3);

    *param_2 = *puVar5;

    *(uint8_t *)(param_2 + 1) = 1;

    return;

  }

  *(uint8_t *)(param_2 + 1) = 0;

  *param_2 = param_3;

  return;

}
