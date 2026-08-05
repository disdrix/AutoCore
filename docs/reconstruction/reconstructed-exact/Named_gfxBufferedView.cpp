// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_0076cec0, FUN_00968720, FUN_0096a630, FUN_0096cad0, ReCreate, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBufferedView.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_gfxBufferedView
// -----------------------------------------------------------------------------
// Stable ID: aa_00968720
// Address:   0x00968720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxBufferedView"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxBufferedView(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int *piVar4;

  uint8_t local_2c [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b11e5;

  local_c = ExceptionList;

  piVar4 = (int *)*DAT_00d1ee30;

  piVar3 = DAT_00d1ee30;

  ExceptionList = &local_c;

  if (piVar4 != DAT_00d1ee30) {

    do {

      if ((piVar4[2] != 0) &&

         (iVar1 = *(int *)(piVar4[2] + 0x44), piVar3 = DAT_00d1ee30, *(int *)(iVar1 + 0x30) == 0)) {

        if ((*(uint *)(iVar1 + 0x2c) & 0x3000) == 0) {

          iVar1 = FUN_0096cad0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x24),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c),

                               *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x34),

                               *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30),*(uint32_t /* width from decompiler */ *)(iVar1 + 0xc));

          piVar3 = DAT_00d1ee30;

          if (iVar1 < 0) {

            iVar1 = FUN_0096a630(local_28);

            local_4 = 0;

            if (*(uint *)(iVar1 + 0x18) < 0x10) {

              iVar1 = iVar1 + 4;

            }

            else {

              iVar1 = *(int *)(iVar1 + 4);

            }

            uVar2 = FUN_0076cec0(local_2c,

                                 "Failure on ReCreate() of effTextureImpl %s for gfxBufferedView render target"

                                 ,iVar1);

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBufferedView.cpp",0xca

                           ,5,uVar2);

            local_4 = 0xffffffff;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

            piVar3 = DAT_00d1ee30;

          }

        }

        else {

          (**(code **)(**(int **)(iVar1 + 0x4c) + 8))();

          piVar3 = DAT_00d1ee30;

        }

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != piVar3);

  }

  ExceptionList = local_c;

  return 0;

}
