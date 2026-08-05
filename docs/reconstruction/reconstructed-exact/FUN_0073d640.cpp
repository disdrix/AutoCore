// =============================================================================
// FUN_0073d640
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d640
// Address:   0x0073d640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073d640 @ 0x0073d640
// Stable ID: aa_0073d640
// Embedded strings (evidence for future rename):
//   - "%u%u%u"
//   - "%u%u%u%u"
//   - "%u%u"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: _snprintf×5, FUN_0073d640.
//  - Strings: "%u%u%u"; "%u%u%u%u"; "%u%u".
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

void FUN_0073d640(int param_1)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;

  char local_80 [128];

  

  iVar2 = DAT_00d1f044;

  _snprintf(local_80,0x80,"%u%u%u",*(uint32_t /* width from decompiler */ *)(DAT_00d1f044 + 0x728),

            (uint)*(ushort *)(DAT_00d1f044 + 0x72c),(uint)*(ushort *)(DAT_00d1f044 + 0x72e));

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (unaff_EDI,local_80);

  _snprintf(local_80,0x80,"%u%u%u%u",(uint)*(byte *)(iVar2 + 0x730),(uint)*(byte *)(iVar2 + 0x731),

            (uint)*(byte *)(iVar2 + 0x732),(uint)*(byte *)(iVar2 + 0x733));

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (unaff_EDI,local_80);

  _snprintf(local_80,0x80,"%u%u%u%u",(uint)*(byte *)(iVar2 + 0x734),(uint)*(byte *)(iVar2 + 0x735),

            (uint)*(byte *)(iVar2 + 0x736),(uint)*(byte *)(iVar2 + 0x737));

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (unaff_EDI,local_80);

  _snprintf(local_80,0x80,"%u%u",0x900,0x20);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (unaff_EDI,local_80);

  _snprintf(local_80,0x80,"%u%u",0x902,0x1b);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (unaff_EDI,local_80);

  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3 != 0)) {

    for (uVar3 = 0;

        (iVar2 = *(int *)(param_1 + 4), iVar2 != 0 &&

        (uVar3 < (uint)(*(int *)(param_1 + 8) - iVar2 >> 3))); uVar3 = uVar3 + 1) {

      iVar1 = uVar3 * 8;

      if ((*(int *)(iVar1 + iVar2) != 0) && (*(int *)(iVar1 + 4 + iVar2) != 0)) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        operator+=(unaff_EDI,*(char **)(iVar1 + iVar2));

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        operator+=(unaff_EDI,*(char **)(*(int *)(param_1 + 4) + iVar1 + 4));

      }

    }

  }

  return;

}
