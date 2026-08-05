// =============================================================================
// Named_i_char_create_swatch_m_1
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf120
// Address:   0x008cf120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_char_create_swatch_m_1 @ 0x008cf120
// Stable ID: aa_008cf120
// Embedded strings (evidence for future rename):
//   - "i_char_create_swatch_m_1.dds"
//   - "i_char_create_swatch_m_2.dds"
//   - "i_char_create_swatch_m_3.dds"
//   - "i_char_create_swatch_h_1.dds"
//   - "i_char_create_swatch_h_2.dds"
//   - "i_char_create_swatch_h_3.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: Named_i_char_create_swatch_m_1.
//  - Strings: "i_char_create_swatch_m_1.dds"; "i_char_create_swatch_m_2.dds"; "i_char_create_swatch_m_3.dds"; "i_char_create_swatch_h_1.dds".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_char_create_swatch_m_1.dds"
 * Domain alias of FUN_008cf120 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_i_char_create_swatch_m_1(void)



{

  int *piVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  

  piVar1 = *(int **)(unaff_ESI + 0x760);

  if (in_EAX == 1) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5a8) = 1;

    iVar2 = **(int **)(unaff_ESI + 0x760);

    uVar3 = (**(code **)(iVar2 + 0x2d8))();

    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

    (**(code **)(iVar2 + 0x50))("i_char_create_swatch_m_1.dds",uVar3);

    piVar1 = *(int **)(unaff_ESI + 0x764);

    iVar2 = *piVar1;

    uVar3 = (**(code **)(iVar2 + 0x2d8))();

    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

    (**(code **)(iVar2 + 0x50))("i_char_create_swatch_m_2.dds",uVar3);

    piVar1 = *(int **)(unaff_ESI + 0x768);

    iVar2 = *piVar1;

    uVar3 = (**(code **)(iVar2 + 0x2d8))();

    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

    (**(code **)(iVar2 + 0x50))("i_char_create_swatch_m_3.dds",uVar3);

    return;

  }

  if (in_EAX != 2) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5a8) = 0;

    iVar2 = *piVar1;

    uVar3 = (**(code **)(iVar2 + 0x2d8))();

    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

    (**(code **)(iVar2 + 0x50))("i_char_create_swatch_h_1.dds",uVar3);

    piVar1 = *(int **)(unaff_ESI + 0x764);

    iVar2 = *piVar1;

    uVar3 = (**(code **)(iVar2 + 0x2d8))();

    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

    (**(code **)(iVar2 + 0x50))("i_char_create_swatch_h_2.dds",uVar3);

    piVar1 = *(int **)(unaff_ESI + 0x768);

    iVar2 = *piVar1;

    uVar3 = (**(code **)(iVar2 + 0x2d8))();

    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

    (**(code **)(iVar2 + 0x50))("i_char_create_swatch_h_3.dds",uVar3);

    return;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5a8) = 2;

  iVar2 = *piVar1;

  uVar3 = (**(code **)(iVar2 + 0x2d8))();

  uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

  (**(code **)(iVar2 + 0x50))("i_char_create_swatch_b_1.dds",uVar3);

  piVar1 = *(int **)(unaff_ESI + 0x764);

  iVar2 = *piVar1;

  uVar3 = (**(code **)(iVar2 + 0x2d8))();

  uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

  (**(code **)(iVar2 + 0x50))("i_char_create_swatch_b_2.dds",uVar3);

  piVar1 = *(int **)(unaff_ESI + 0x768);

  iVar2 = *piVar1;

  uVar3 = (**(code **)(iVar2 + 0x2d8))();

  uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

  (**(code **)(iVar2 + 0x50))("i_char_create_swatch_b_3.dds",uVar3);

  return;

}
