// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_006065a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006065a0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x006065a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper. Evidence string: "the Human Hestia Corporation". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "the Human Hestia Corporation"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, return×4, if×3, for×1.
//  - Notable callees: FUN_006065a0.
//  - Strings: "the Human Hestia Corporation".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_006065a0(int param_1,int param_2)



{

  int iVar1;

  char *pcVar2;

  char *pcVar3;

  

  pcVar3 = (char *)(param_2 + -1);

  if (param_1 == 0) {

    do {

      pcVar2 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar2 != '\0');

    pcVar2 = "the Human Hestia Corporation";

    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar2;

      pcVar2 = pcVar2 + 4;

      pcVar3 = pcVar3 + 4;

    }

    *pcVar3 = *pcVar2;

    return;

  }

  if (param_1 != 1) {

    if (param_1 != 2) {

      do {

        pcVar2 = pcVar3;

        pcVar3 = pcVar2 + 1;

      } while (pcVar2[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar2 + 1) = s_a_rogue_faction_009de830._0_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar2 + 5) = s_a_rogue_faction_009de830._4_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar2 + 9) = s_a_rogue_faction_009de830._8_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar2 + 0xd) = s_a_rogue_faction_009de830._12_4_;

      return;

    }

    do {

      pcVar2 = pcVar3;

      pcVar3 = pcVar2 + 1;

    } while (pcVar2[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar2 + 1) = s_the_Biomek_Order_009de81c._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar2 + 5) = s_the_Biomek_Order_009de81c._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar2 + 9) = s_the_Biomek_Order_009de81c._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar2 + 0xd) = s_the_Biomek_Order_009de81c._12_4_;

    pcVar2[0x11] = s_the_Biomek_Order_009de81c[0x10];

    return;

  }

  do {

    pcVar2 = pcVar3;

    pcVar3 = pcVar2 + 1;

  } while (pcVar2[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar2 + 1) = s_the_Mutant_Tribes_009de808._0_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar2 + 5) = s_the_Mutant_Tribes_009de808._4_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar2 + 9) = s_the_Mutant_Tribes_009de808._8_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar2 + 0xd) = s_the_Mutant_Tribes_009de808._12_4_;

  *(uint16_t *)(pcVar2 + 0x11) = s_the_Mutant_Tribes_009de808._16_2_;

  return;

}
