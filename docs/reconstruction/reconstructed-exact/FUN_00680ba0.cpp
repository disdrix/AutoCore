// =============================================================================
// FUN_00680ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00680ba0
// Address:   0x00680ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680ba0 @ 0x00680ba0
// Stable ID: aa_00680ba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_006809c0, FUN_00680ba0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00680ba0(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int local_8 [2];

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      if ((int)puVar1[3] < *param_2) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar4 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x15) == '\0');

  }

  if ((puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) && ((int)puVar4[3] <= *param_2)) {

    return puVar4 + 4;

  }

  local_8[0] = *param_2;

  local_8[1] = 0;

  piVar3 = (int *)FUN_006809c0(&param_2,puVar4,local_8);

  return (uint32_t /* width from decompiler */ *)(*piVar3 + 0x10);

}
