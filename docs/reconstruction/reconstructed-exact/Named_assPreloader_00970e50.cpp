// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00457cc0×2, FUN_0076cec0×2, vog_LogMessage×2, FUN_0043e7f0, FUN_0043e8f0, FUN_00447350, FUN_0076c330, FUN_0096a630.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_assPreloader_00970e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00970e50
// Address:   0x00970e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assPreloader"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_assPreloader_00970e50(int *param_1,float param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  float10 fVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar1 = (int)param_1;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009adafb;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  fVar3 = (float10)FUN_0076c330();

  param_1 = (int *)**(int **)(iVar1 + 0x14);

  if (param_1 != *(int **)(iVar1 + 0x14)) {

    do {

      if ((float)fVar3 - *(float *)((int)param_1 + 0x14) <= param_2) {

        FUN_00457cc0();

      }

      else {

        if (*(uint32_t /* width from decompiler */ **)((int)param_1 + 0x10) != (uint32_t /* width from decompiler */ *)0x0) {

          (**(code **)**(uint32_t /* width from decompiler */ **)((int)param_1 + 0x10))();

        }

        FUN_0096a630();

        uStack_4 = 0;

        uVar2 = FUN_0076cec0(&param_1);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",0x2a8,2,uVar2

                      );

        uStack_4 = 0xffffffff;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

        FUN_0043e8f0();

        FUN_0043e7f0();

        FUN_00457cc0();

        FUN_00447350(iVar1 + 0x10);

      }

    } while (param_1 != (int *)*(int *)(iVar1 + 0x14));

  }

  uVar2 = FUN_0076cec0(&param_1);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",0x2b7,2,uVar2);

  ExceptionList = pvStack_c;

  return;

}
