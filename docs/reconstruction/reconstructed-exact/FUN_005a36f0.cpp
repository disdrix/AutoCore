// =============================================================================
// FUN_005a36f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a36f0
// Address:   0x005a36f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a36f0 @ 0x005a36f0
// Stable ID: aa_005a36f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_005a36f0.
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

void __thiscall FUN_005a36f0(int param_1,int *param_2,uint *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      if (*param_3 < (uint)puVar1[3]) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar4 = puVar1;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x21) == '\0');

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar1[1] + 0x21) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar1[1];

    do {

      if ((uint)puVar2[3] < *param_3) {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar2[2];

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

        puVar1 = puVar2;

      }

      puVar2 = puVar3;

    } while (*(char *)((int)puVar3 + 0x21) == '\0');

  }

  *param_2 = (int)puVar1;

  param_2[1] = (int)puVar4;

  return;

}
