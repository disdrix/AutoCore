// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×6, while×2, do×1, return×1.
//  - Notable callees: FUN_0043e750×2, FUN_0076cec0×2, vog_LogMessage×2, FUN_0043d570, FUN_0044e8c0, FUN_00457cc0, FUN_0076c330, FUN_0096a630.
//  - Strings: "PRELOAD: preloaded already loaded asset %s"; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp"; "%d\t\t%s\n".
//  - Return sites: 1.

// =============================================================================
// Named_assPreloader_00971480
// -----------------------------------------------------------------------------
// Stable ID: aa_00971480
// Address:   0x00971480  (autoassault.exe, image base 0x400000)
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

void Named_assPreloader_00971480(int param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  undefined *puVar7;

  float10 fVar8;

  int local_4c;

  int local_48;

  uint32_t /* width from decompiler */ local_44;

  int *local_40;

  float local_38;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [32];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009afdf1;

  pvStack_14 = ExceptionList;

  local_48 = param_1 + 0x4c;

  local_44 = 0;

  ExceptionList = &pvStack_14;

  cVar2 = FUN_0043e750();

  while (cVar2 != '\0') {

    iVar3 = *(int *)(param_1 + 0x110);

    FUN_0044e8c0(&local_4c);

    piVar1 = local_40;

    if ((local_4c == *(int *)(iVar3 + 8)) || (*(int *)(local_4c + 0xc) == 0)) {

      fVar8 = (float10)FUN_0076c330();

      local_38 = (float)fVar8;

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_0043d570();

      *puVar5 = piVar1;

      puVar5[1] = local_38;

      iVar3 = FUN_00970910(&local_44);

      iVar6 = (**(code **)(*piVar1 + 0x1c))();

      piVar1 = (int *)(param_1 + 0xe8 + iVar3 * 4);

      *piVar1 = *piVar1 + iVar6;

      piVar1 = (int *)(param_1 + 0xfc + iVar3 * 4);

      *piVar1 = *piVar1 + 1;

    }

    else {

      iVar3 = FUN_0096a630(local_34);

      local_c = 0;

      if (*(uint *)(iVar3 + 0x18) < 0x10) {

        iVar3 = iVar3 + 4;

      }

      else {

        iVar3 = *(int *)(iVar3 + 4);

      }

      uVar4 = FUN_0076cec0(&local_48,"PRELOAD: preloaded already loaded asset %s",iVar3);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",0xd3,1,uVar4);

      local_c = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34);

      if (local_40 != (int *)0x0) {

        (**(code **)*local_40)(1);

      }

    }

    cVar2 = FUN_0043e750();

  }

  if (DAT_00d1f618 != '\0') {

    local_4c = **(int **)(param_1 + 0x14);

    if ((int *)local_4c != *(int **)(param_1 + 0x14)) {

      do {

        puVar7 = *(undefined **)(local_4c + 0xc);

        if (*(undefined **)(local_4c + 0xc) == (undefined *)0x0) {

          puVar7 = PTR_DAT_00afa2bc;

        }

        uVar4 = (**(code **)(**(int **)(local_4c + 0x10) + 0x1c))(puVar7);

        uVar4 = FUN_0076cec0(&local_48,"%d\t\t%s\n",uVar4);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",0xe8,1,uVar4)

        ;

        FUN_00457cc0();

      } while (local_4c != *(int *)(param_1 + 0x14));

    }

    DAT_00d1f618 = '\0';

  }

  ExceptionList = pvStack_14;

  return;

}
