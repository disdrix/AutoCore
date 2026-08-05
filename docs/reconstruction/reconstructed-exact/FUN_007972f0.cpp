// =============================================================================
// FUN_007972f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007972f0
// Address:   0x007972f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007972f0 @ 0x007972f0
// Stable ID: aa_007972f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007972f0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_007972f0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  int *unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ac30a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            ((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

              *)(param_1 + 0xc));

  *(uint8_t *)(param_1 + 0x2e) = 0xff;

  *(uint8_t *)(param_1 + 0x2d) = 0xff;

  *(uint8_t *)(param_1 + 0x2c) = 0xff;

  *(uint8_t *)(param_1 + 0x2f) = 0xff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0;

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

  *(float *)(param_1 + 0xa0) = (float)(unaff_EDI[2] - *unaff_EDI);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  *(uint8_t *)(param_1 + 0xb4) = 1;

  *(uint8_t *)(param_1 + 0xb5) = 0;

  *(uint8_t *)(param_1 + 0xb6) = 1;

  *(float *)(param_1 + 0xb8) = fVar1;

  *(uint8_t *)(param_1 + 0xbc) = 0;

  *(uint8_t *)(param_1 + 0xc6) = 0xff;

  *(uint8_t *)(param_1 + 0xc5) = 0xff;

  *(uint8_t *)(param_1 + 0xc4) = 0xff;

  *(uint8_t *)(param_1 + 199) = 0xff;

  *(int *)(param_1 + 200) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

  *(int *)(param_1 + 4) = unaff_EDI[1];

  if (param_2 == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  }

  else {

    fVar1 = (float)*(int *)(param_2 + 0x10);

    if (*(int *)(param_2 + 0x10) < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    *(float *)(param_1 + 0xac) = fVar1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint8_t *)(param_1 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  ExceptionList = local_c;

  return param_1;

}
