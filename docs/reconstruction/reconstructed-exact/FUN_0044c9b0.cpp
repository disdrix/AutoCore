// =============================================================================
// FUN_0044c9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044c9b0
// Address:   0x0044c9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044c9b0 @ 0x0044c9b0
// Stable ID: aa_0044c9b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0044c9b0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_0044c9b0(uint32_t /* width from decompiler */ param_1,uint *param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  if (*(char *)((int)puVar1[1] + 0x21) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar1[1];

    do {

      if (((uint)puVar2[5] < param_2[1]) ||

         (((uint)puVar2[5] <= param_2[1] && ((uint)puVar2[4] <= *param_2)))) {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar2[2];

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

        puVar1 = puVar2;

      }

      puVar2 = puVar3;

    } while (*(char *)((int)puVar3 + 0x21) == '\0');

  }

  return puVar1;

}
