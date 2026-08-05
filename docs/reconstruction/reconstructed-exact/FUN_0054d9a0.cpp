// =============================================================================
// FUN_0054d9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0054d9a0
// Address:   0x0054d9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054d9a0 @ 0x0054d9a0
// Stable ID: aa_0054d9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0054d9a0.
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

void __thiscall FUN_0054d9a0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar3[1] + 0x549) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      if ((int)puVar1[3] < *param_3) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar3 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x549) == '\0');

  }

  if ((puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) && ((int)puVar3[3] <= *param_3)) {

    *param_2 = puVar3;

    return;

  }

  *param_2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  return;

}
