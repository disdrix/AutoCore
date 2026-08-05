// =============================================================================
// FUN_00971050
// -----------------------------------------------------------------------------
// Stable ID: aa_00971050
// Address:   0x00971050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00971050 @ 0x00971050
// Stable ID: aa_00971050
// Embedded strings (evidence for future rename):
//   - "Preloaded asset <%s> never loaded. Deleting and removing."
//   - "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0043d900, FUN_00457cc0, FUN_0076cec0, FUN_0096a630, FUN_00971050, vog_LogMessage.
//  - Strings: "Preloaded asset <%s> never loaded. Deleting and removing."; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp".
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

void __fastcall FUN_00971050(int param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009adb0e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = 0;

  local_2c = **(int **)(param_1 + 0x14);

  if ((int *)local_2c != *(int **)(param_1 + 0x14)) {

    do {

      if (*(uint32_t /* width from decompiler */ **)(local_2c + 0x10) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(local_2c + 0x10))(1);

      }

      iVar2 = FUN_0096a630(abStack_28);

      uStack_4 = 0;

      if (*(uint *)(iVar2 + 0x18) < 0x10) {

        iVar2 = iVar2 + 4;

      }

      else {

        iVar2 = *(int *)(iVar2 + 4);

      }

      uVar3 = FUN_0076cec0(&local_2c,"Preloaded asset <%s> never loaded. Deleting and removing.",

                           iVar2);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",0x51,2,uVar3);

      uStack_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

      FUN_00457cc0();

    } while (local_2c != *(int *)(param_1 + 0x14));

  }

  pvVar1 = *(void **)(*(int *)(param_1 + 0x14) + 4);

  if (*(char *)((int)pvVar1 + 0x19) != '\0') {

    *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);

    ExceptionList = pvStack_c;

    return;

  }

  FUN_0043d900(*(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8));

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
