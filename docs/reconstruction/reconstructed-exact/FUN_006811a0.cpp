// =============================================================================
// FUN_006811a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006811a0
// Address:   0x006811a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006811a0 @ 0x006811a0
// Stable ID: aa_006811a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×2.
//  - Notable callees: FUN_00680c80×2, FUN_006811a0.
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

void __thiscall

FUN_006811a0(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  char *pcVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  uint uVar3;

  uint uVar4;

  char *pcVar5;

  short local_48 [2];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a99a2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (1 < *(uint *)(param_1 + 0xc)) {

    ExceptionList = &local_c;

    FUN_00680c80(local_48,2);

  }

  if ((-1 < local_48[0]) && (local_48[0] < 0x401)) {

    uVar4 = (int)local_48[0] + 1;

    pcVar1 = operator_new__(uVar4);

    pcVar5 = pcVar1;

    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      pcVar5[0] = '\0';

      pcVar5[1] = '\0';

      pcVar5[2] = '\0';

      pcVar5[3] = '\0';

      pcVar5 = pcVar5 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar5 = '\0';

      pcVar5 = pcVar5 + 1;

    }

    FUN_00680c80(pcVar1,(int)local_48[0]);

    pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       (local_44,pcVar1);

    local_4 = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (param_2,pbVar2);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    operator_delete__(pcVar1);

    ExceptionList = local_c;

    return;

  }

  pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

           std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

           basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,"")

  ;

  local_4 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            (param_2,pbVar2);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return;

}
