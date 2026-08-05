// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00687e40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00687e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "malformed lod info". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "malformed lod info"
//   - "premature end of file reached parsing new lod info"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, while×1, switch×1.
//  - Notable callees: FUN_00699ed0×3, FUN_00699ee0×3, FUN_006874b0×2, _CxxThrowException×2, FUN_00687e40, FUN_00697580.
//  - Strings: "malformed lod info"; "premature end of file reached parsing new lod info".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687e40(int param_1,uint *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  float10 fVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];

  uint8_t local_5c [40];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9fc5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_00699ee0();

  while( true ) {

    switch(iVar1) {

    case 0x232a:

      uVar2 = FUN_00699ee0();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = uVar2;

      break;

    case 0x232b:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0x1c) = (float)fVar3;

      break;

    case 0x232c:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0x20) = (float)fVar3;

      break;

    case 0x232d:

      FUN_00697580(param_2);

      break;

    default:

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed lod info");

      local_4 = 0;

      FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

    case 0x2331:

      fVar3 = (float10)FUN_00699ed0();

      *(float *)(param_1 + 0x24) = (float)fVar3;

    }

    if ((param_2[2] == 0) || (param_2[3] - param_2[2] <= *param_2)) break;

    iVar1 = FUN_00699ee0();

    if (iVar1 == 0x2329) {

      ExceptionList = local_c;

      return;

    }

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_78,"premature end of file reached parsing new lod info");

  local_4 = 1;

  FUN_006874b0(local_78,0);

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(local_5c,(ThrowInfo *)&DAT_00ac9e00);

}
