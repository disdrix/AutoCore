// =============================================================================
// FUN_0069e170
// -----------------------------------------------------------------------------
// Stable ID: aa_0069e170
// Address:   0x0069e170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069e170 @ 0x0069e170
// Stable ID: aa_0069e170
// Embedded strings (evidence for future rename):
//   - "malformed lighting information"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, return×2, switch×1.
//  - Notable callees: FUN_00699ee0×6, FUN_00699ed0×4, FUN_006874b0, FUN_0069e170, _CxxThrowException.
//  - Strings: "malformed lighting information".
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

void __fastcall FUN_0069e170(float *param_1)



{

  int iVar1;

  float fVar2;

  float *pfVar3;

  float10 fVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aaeb9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_00699ee0();

  do {

    switch(iVar1) {

    case 0x1f42:

      fVar2 = (float)FUN_00699ee0();

      *param_1 = fVar2;

      break;

    case 0x1f43:

      iVar1 = 0xd;

      pfVar3 = param_1;

      do {

        pfVar3 = pfVar3 + 1;

        fVar4 = (float10)FUN_00699ed0();

        *pfVar3 = (float)fVar4;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

      break;

    case 0x1f44:

      fVar2 = (float)FUN_00699ee0();

      param_1[0xe] = fVar2;

      break;

    case 0x1f45:

      pfVar3 = param_1 + 0xf;

      iVar1 = 0xd;

      do {

        fVar4 = (float10)FUN_00699ed0();

        *pfVar3 = (float)fVar4;

        pfVar3 = pfVar3 + 1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

      break;

    case 0x1f46:

      fVar4 = (float10)FUN_00699ed0();

      param_1[0x1c] = (float)fVar4;

      break;

    case 0x1f47:

      fVar2 = (float)FUN_00699ee0();

      param_1[0x1d] = fVar2;

      break;

    case 0x1f48:

      fVar2 = (float)FUN_00699ee0();

      param_1[0x1e] = fVar2;

      break;

    case 0x1f49:

      pfVar3 = param_1 + 0x1f;

      iVar1 = 0xd;

      do {

        fVar4 = (float10)FUN_00699ed0();

        *pfVar3 = (float)fVar4;

        pfVar3 = pfVar3 + 1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

      break;

    default:

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_50,"malformed lighting information");

      local_4 = 0;

      FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar1 = FUN_00699ee0();

  } while (iVar1 != 0x1f41);

  ExceptionList = local_c;

  return;

}
