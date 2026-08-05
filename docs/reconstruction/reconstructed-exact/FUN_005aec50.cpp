// =============================================================================
// FUN_005aec50
// -----------------------------------------------------------------------------
// Stable ID: aa_005aec50
// Address:   0x005aec50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005aec50 @ 0x005aec50
// Stable ID: aa_005aec50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1, goto×1.
//  - Notable callees: FUN_005adff0, FUN_005ae2f0, FUN_005aec50.
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

void __thiscall FUN_005aec50(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3)



{

  bool bVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_4;

  

  piVar2 = param_3;

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar1 = true;

  local_4 = 1;

  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {

    puVar3 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      puVar4 = puVar3;

      if ((*param_3 < (int)puVar4[3]) ||

         ((*param_3 <= (int)puVar4[3] && (param_3[1] < (int)puVar4[4])))) {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar4;

        bVar1 = true;

        local_4 = 1;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar4[2];

        bVar1 = false;

        local_4 = 0;

      }

    } while (*(char *)((int)puVar3 + 0x21) == '\0');

  }

  param_3 = puVar4;

  if (bVar1) {

    if (puVar4 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      local_4 = 1;

      goto LAB_005aecad;

    }

    FUN_005adff0();

  }

  if ((*piVar2 <= param_3[3]) && ((*piVar2 < param_3[3] || (piVar2[1] <= param_3[4])))) {

    *param_2 = param_3;

    *(uint8_t *)(param_2 + 1) = 0;

    return;

  }

LAB_005aecad:

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_005ae2f0(&param_3,local_4,puVar4,piVar2);

  *param_2 = *puVar4;

  *(uint8_t *)(param_2 + 1) = 1;

  return;

}
