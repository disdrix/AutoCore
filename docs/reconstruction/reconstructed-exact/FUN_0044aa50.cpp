// =============================================================================
// FUN_0044aa50
// -----------------------------------------------------------------------------
// Stable ID: aa_0044aa50
// Address:   0x0044aa50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044aa50 @ 0x0044aa50
// Stable ID: aa_0044aa50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0044aa50.
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

uint32_t /* width from decompiler */ * FUN_0044aa50(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint *unaff_EDI;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  if (*(char *)((int)puVar2[1] + 0x19) == '\0') {

    puVar1 = puVar2;

    puVar3 = (uint32_t /* width from decompiler */ *)puVar2[1];

    do {

      puVar2 = puVar3;

      if (((uint)puVar2[3] < *unaff_EDI) ||

         (((uint)puVar2[3] <= *unaff_EDI && ((uint)puVar2[4] < unaff_EDI[1])))) {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar2[2];

        puVar2 = puVar1;

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar3 + 0x19) == '\0');

  }

  return puVar2;

}
