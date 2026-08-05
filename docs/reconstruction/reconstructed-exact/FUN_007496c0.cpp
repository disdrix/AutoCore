// =============================================================================
// FUN_007496c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007496c0
// Address:   0x007496c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007496c0 @ 0x007496c0
// Stable ID: aa_007496c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, while×1.
//  - Notable callees: FUN_00436f10×2, FUN_00769e40×2, FUN_0076a200×2, FUN_00989e00×2, FUN_00437050, FUN_0044c270, FUN_007496c0, FUN_007689e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_007496c0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ ***pppuVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  uint local_48;

  uint32_t /* width from decompiler */ local_44;

  uint8_t local_40 [12];

  char local_34;

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1aa1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  uVar6 = 0;

  local_4 = 0;

  if ((local_30 == 0x55534441) && (local_2c == 1)) {

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00437050(&local_48);

    }

    else {

      FUN_007689e0(&local_48);

    }

    uVar3 = local_48;

    FUN_0044c270(0,0);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4._0_1_ = 1;

    if (uVar3 != 0) {

      do {

        if (*(int *)(param_1 + 0x4044) == 0) {

          FUN_00436f10();

        }

        else {

          FUN_0076a200();

        }

        pppuVar4 = (uint32_t /* width from decompiler */ ***)local_24[0];

        if (local_10 < 0x10) {

          pppuVar4 = local_24;

        }

        FUN_00989e00(&local_44,pppuVar4);

        if (*(int *)(param_1 + 0x4044) == 0) {

          FUN_00436f10();

        }

        else {

          FUN_0076a200();

        }

        pppuVar4 = (uint32_t /* width from decompiler */ ***)local_24[0];

        if (local_10 < 0x10) {

          pppuVar4 = local_24;

        }

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40,pppuVar4);

        uVar1 = *puVar5;

        iVar2 = *(int *)(param_2 + 0x9c);

        *(uint32_t /* width from decompiler */ *)(iVar2 + uVar6 * 8) = local_44;

        *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + uVar6 * 8) = uVar1;

        uVar6 = uVar6 + 1;

      } while (uVar6 < local_48);

    }

    local_4 = (uint)local_4._1_3_ << 8;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0;

  }

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
