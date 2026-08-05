// =============================================================================
// FUN_00697580
// -----------------------------------------------------------------------------
// Stable ID: aa_00697580
// Address:   0x00697580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00697580 @ 0x00697580
// Stable ID: aa_00697580
// Embedded strings (evidence for future rename):
//   - "malformed engine lod data"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, switch×1, while×1.
//  - Notable callees: FUN_00699ed0×5, FUN_00699ee0×4, FUN_006874b0, FUN_00697580, _CxxThrowException.
//  - Strings: "malformed engine lod data".
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

void __fastcall FUN_00697580(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  float10 fVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aaa79;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_00699ee0();

  do {

    switch(iVar1) {

    case 0x232f:

      uVar2 = FUN_00699ee0();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = uVar2;

      break;

    case 0x2330:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0xd0) = (float)fVar3;

      break;

    default:

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_50,"malformed engine lod data");

      local_4 = 0;

      FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

    case 0x2332:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0xd8) = (float)fVar3;

      break;

    case 0x2333:

      uVar2 = FUN_00699ee0();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = uVar2;

      break;

    case 0x2334:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0xd4) = (float)fVar3;

      break;

    case 0x2335:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0xdc) = (float)fVar3;

      break;

    case 0x2336:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0xe0) = (float)fVar3;

    }

    iVar1 = FUN_00699ee0();

  } while (iVar1 != 0x232e);

  ExceptionList = local_c;

  return;

}
