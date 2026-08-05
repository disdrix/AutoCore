// =============================================================================
// Net_Retrying_sector_connection
// -----------------------------------------------------------------------------
// Stable ID: aa_00807710
// Address:   0x00807710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Net_Retrying_sector_connection @ 0x00807710
// Stable ID: aa_00807710
// Embedded strings (evidence for future rename):
//   - "Retrying sector connection..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_005a1f50, FUN_0079a470, FUN_007a4480, Net_Retrying_sector_connection, FUN_00812de0, GetTickCount, Sleep.
//  - Strings: "Retrying sector connection...".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Retrying sector connection..."
 * Domain alias of FUN_00807710 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Net_Retrying_sector_connection(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  DWORD DVar3;

  int unaff_ESI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bbacc;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (DAT_00d1f0f1 == '\0') {

    DAT_00d1f0f1 = '\x01';

    ExceptionList = &local_c;

    FUN_0079a470(DAT_00d09874);

  }

  if (DAT_00d17934 == '\0') {

    DVar3 = GetTickCount();

    if (DAT_00d17930 < DVar3) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_28,PTR_DAT_00af3ddc);

      local_4 = 1;

      FUN_00812de0(unaff_ESI,0);

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    }

    else {

      FUN_007a4480(0xffffffff,"Retrying sector connection...");

      Sleep(3000);

      if (*(int **)(unaff_ESI + 0xc78) != (int *)0x0) {

        (**(code **)(**(int **)(unaff_ESI + 0xc78) + 4))();

        ExceptionList = local_c;

        return 0;

      }

    }

    ExceptionList = local_c;

    return 1;

  }

  DAT_00d17934 = '\0';

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xc78) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xc78))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc78) = 0;

  pvVar1 = operator_new(200);

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    uVar2 = FUN_005a1f50(unaff_ESI + 0xc84,param_1,param_2,0,0,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x508),

                         *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50c),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x134),0xaf,

                         0);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc78) = uVar2;

    ExceptionList = local_c;

    return 0;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc78) = 0;

  ExceptionList = local_c;

  return 0;

}
