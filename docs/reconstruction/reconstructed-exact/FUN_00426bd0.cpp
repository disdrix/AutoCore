// =============================================================================
// FUN_00426bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00426bd0
// Address:   0x00426bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00426bd0 @ 0x00426bd0
// Stable ID: aa_00426bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00426bd0.
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

void __fastcall FUN_00426bd0(uint32_t /* width from decompiler */ param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int unaff_ESI;

  int unaff_EDI;

  

  if (param_2 < in_EAX) {

    iVar4 = param_2 * 0x14;

    iVar2 = in_EAX - param_2;

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 8) + iVar4);

      if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar4 + unaff_ESI);

        *puVar3 = *puVar1;

        puVar3[1] = puVar1[1];

        puVar3[2] = puVar1[2];

        puVar3[3] = puVar1[3];

        puVar3[4] = puVar1[4];

      }

      iVar4 = iVar4 + 0x14;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}
