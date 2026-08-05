// =============================================================================
// FUN_0090e960
// -----------------------------------------------------------------------------
// Stable ID: aa_0090e960
// Address:   0x0090e960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090e960 @ 0x0090e960
// Stable ID: aa_0090e960
// Embedded strings (evidence for future rename):
//   - "CVOGScreen::PreloadInterfaceGeos start\n"
//   - "char_h_c_m_b_1"
//   - "char_m_c_m_b_1"
//   - "char_b_c_m_b_1"
//   - "char_h_c_f_b_1"
//   - "char_m_c_f_b_1"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~178 non-empty decompiler lines.
//  - Control keywords: if×25, return×1.
//  - Notable callees: FUN_00540350×24, FUN_007a4480×2, FUN_0090e960.
//  - Strings: "CVOGScreen::PreloadInterfaceGeos start\n"; "char_h_c_m_b_1"; "char_m_c_m_b_1"; "char_b_c_m_b_1".
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

uint32_t /* width from decompiler */ FUN_0090e960(void)



{

  int iVar1;

  

  FUN_007a4480(0,"CVOGScreen::PreloadInterfaceGeos start\n");

  if (DAT_00d1a852 == '\0') {

    iVar1 = FUN_00540350("char_h_c_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099a0 = 0xffffffff;

    }

    else {

      DAT_00d099a0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_c_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099c0 = 0xffffffff;

    }

    else {

      DAT_00d099c0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_c_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099e0 = 0xffffffff;

    }

    else {

      DAT_00d099e0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_h_c_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099a4 = 0xffffffff;

    }

    else {

      DAT_00d099a4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_c_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099c4 = 0xffffffff;

    }

    else {

      DAT_00d099c4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_c_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099e4 = 0xffffffff;

    }

    else {

      DAT_00d099e4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_h_e_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099a8 = 0xffffffff;

    }

    else {

      DAT_00d099a8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_e_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099c8 = 0xffffffff;

    }

    else {

      DAT_00d099c8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_e_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099e8 = 0xffffffff;

    }

    else {

      DAT_00d099e8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_h_e_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099ac = 0xffffffff;

    }

    else {

      DAT_00d099ac = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_e_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099cc = 0xffffffff;

    }

    else {

      DAT_00d099cc = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_e_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099ec = 0xffffffff;

    }

    else {

      DAT_00d099ec = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_h_o_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099b0 = 0xffffffff;

    }

    else {

      DAT_00d099b0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_o_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099d0 = 0xffffffff;

    }

    else {

      DAT_00d099d0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_o_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099f0 = 0xffffffff;

    }

    else {

      DAT_00d099f0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_h_o_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099b4 = 0xffffffff;

    }

    else {

      DAT_00d099b4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_o_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099d4 = 0xffffffff;

    }

    else {

      DAT_00d099d4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_o_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099f4 = 0xffffffff;

    }

    else {

      DAT_00d099f4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_h_r_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099b8 = 0xffffffff;

    }

    else {

      DAT_00d099b8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_r_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099d8 = 0xffffffff;

    }

    else {

      DAT_00d099d8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_r_m_b_1");

    if (iVar1 == 0) {

      DAT_00d099f8 = 0xffffffff;

    }

    else {

      DAT_00d099f8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_h_r_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099bc = 0xffffffff;

    }

    else {

      DAT_00d099bc = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_m_r_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099dc = 0xffffffff;

    }

    else {

      DAT_00d099dc = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    iVar1 = FUN_00540350("char_b_r_f_b_1");

    if (iVar1 == 0) {

      DAT_00d099fc = 0xffffffff;

    }

    else {

      DAT_00d099fc = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    }

    DAT_00d1a852 = '\x01';

  }

  FUN_007a4480(0,"CVOGScreen::PreloadInterfaceGeos end\n");

  return 1;

}
