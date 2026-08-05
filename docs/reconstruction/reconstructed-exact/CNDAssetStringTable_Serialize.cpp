// =============================================================================
// CNDAssetStringTable_Serialize
// -----------------------------------------------------------------------------
// Stable ID: aa_0099b8e0
// Address:   0x0099b8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CNDAssetStringTable_Serialize @ 0x0099b8e0
// Stable ID: aa_0099b8e0
// Embedded strings (evidence for future rename):
//   - "CNDAssetStringTable::Serialize"
//   - "string table size =%u"
//   - "pyramids =%u"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×12, do×4, while×4, return×1.
//  - Notable callees: FUN_007a4480×3, FUN_00430280×2, FUN_00430aa0, FUN_0044e100, CNDAssetStringTable_Serialize.
//  - Strings: "CNDAssetStringTable::Serialize"; "string table size =%u"; "pyramids =%u".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CNDAssetStringTable::Serialize"
 * Domain alias of FUN_0099b8e0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void CNDAssetStringTable_Serialize(int param_1)



{

  uint32_t /* width from decompiler */ ****ppppuVar1;

  int *piVar2;

  char *pcVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  int *unaff_ESI;

  void *pvVar6;

  uint8_t *unaff_retaddr;

  char *pcStack_4c;

  int iVar7;

  int local_3c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_38 [8];

  int local_30;

  uint32_t /* width from decompiler */ ***local_2c [4];

  int iStack_1c;

  uint uStack_18;

  int iStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = -1;

  puStack_8 = &LAB_009add17;

  pvStack_c = ExceptionList;

  pcStack_4c = "CNDAssetStringTable::Serialize";

  ExceptionList = &pvStack_c;

  FUN_007a4480(0xffffffff);

  pcStack_4c = (char *)0x99b90f;

  local_30 = FUN_0044e100();

  *(uint8_t *)(local_30 + 0x2d) = 1;

  *(int *)(local_30 + 4) = local_30;

  *(int *)local_30 = local_30;

  *(int *)(local_30 + 8) = local_30;

  local_2c[0] = (uint32_t /* width from decompiler */ ****)0x0;

  local_4 = 0;

  if (*(int *)(param_1 + 8) == 0) {

    pcStack_4c = (char *)0x0;

  }

  else {

    pcStack_4c = (char *)(*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2);

  }

  FUN_007a4480(0xffffffff,"string table size =%u");

  if (*(int *)(param_1 + 8) == 0) {

    local_3c = 0;

  }

  else {

    local_3c = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2;

  }

  pcStack_4c = (char *)0x4;

  (**(code **)(*unaff_ESI + 0x18))(&local_3c);

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  iVar7 = 0;

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

    do {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &local_30,(char *)*puVar5);

      pvStack_c._0_1_ = 1;

      ppppuVar1 = (uint32_t /* width from decompiler */ ****)local_2c[0];

      if (uStack_18 < 0x10) {

        ppppuVar1 = local_2c;

      }

      (**(code **)(*unaff_ESI + 0x18))(ppppuVar1,iStack_1c + 1);

      piVar2 = (int *)FUN_00430280();

      *piVar2 = iVar7;

      pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &local_30);

      puVar5 = puVar5 + 1;

      iVar7 = iVar7 + 1;

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(local_4 + 0xc));

  }

  if (*(int *)(unaff_retaddr + 4) == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = *(int *)(unaff_retaddr + 8) - *(int *)(unaff_retaddr + 4) >> 4;

  }

  FUN_007a4480(0xffffffff,"pyramids =%u",iVar7);

  if (*(int *)(unaff_retaddr + 4) == 0) {

    local_4 = 0;

  }

  else {

    local_4 = *(int *)(unaff_retaddr + 8) - *(int *)(unaff_retaddr + 4) >> 4;

  }

  (**(code **)(*unaff_ESI + 0x18))(&local_4,4);

  iVar7 = *(int *)(unaff_retaddr + 4);

  if (iVar7 != *(int *)(unaff_retaddr + 8)) {

    do {

      if (*(int *)(iVar7 + 4) == 0) {

        pvStack_c = (void *)0x0;

      }

      else {

        pvStack_c = (void *)(*(int *)(iVar7 + 8) - *(int *)(iVar7 + 4) >> 4);

      }

      (**(code **)(*unaff_ESI + 0x18))(&pvStack_c,4);

      pvVar6 = *(void **)(iVar7 + 4);

      pvStack_c = pvVar6;

      if (pvVar6 != *(void **)(iVar7 + 8)) {

        do {

          if (*(int *)((int)pvVar6 + 4) == 0) {

            pcStack_4c = (char *)0x0;

          }

          else {

            pcStack_4c = (char *)(*(int *)((int)pvVar6 + 8) - *(int *)((int)pvVar6 + 4) >> 3);

          }

          pvStack_c = pvVar6;

          (**(code **)(*unaff_ESI + 0x18))(&pcStack_4c,4);

          piVar2 = *(int **)((int)pvVar6 + 4);

          if (piVar2 != *(int **)((int)pvVar6 + 8)) {

            do {

              pcStack_4c = (char *)0x0;

              pcVar3 = (char *)*piVar2;

              if ((char *)*piVar2 == (char *)0x0) {

                pcVar3 = PTR_DAT_00afa2bc;

              }

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_38,pcVar3);

              iStack_14._0_1_ = 2;

              piVar4 = (int *)FUN_00430280();

              pcStack_4c = (char *)*piVar4;

              (**(code **)(*unaff_ESI + 0x18))(&pcStack_4c,4);

              (**(code **)(*unaff_ESI + 0x18))(piVar2 + 1,4);

              iStack_14 = (uint)iStack_14._1_3_ << 8;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_38);

              piVar2 = piVar2 + 2;

              pvVar6 = pvStack_c;

            } while (piVar2 != *(int **)((int)pvStack_c + 8));

          }

          pvVar6 = (void *)((int)pvVar6 + 0x10);

          unaff_retaddr = puStack_8;

          pvStack_c = pvVar6;

        } while (pvVar6 != *(void **)(iVar7 + 8));

      }

      iVar7 = iVar7 + 0x10;

    } while (iVar7 != *(int *)(unaff_retaddr + 8));

  }

  iStack_14 = 0xffffffff;

  FUN_00430aa0(&pvStack_c,*unaff_EBX,unaff_EBX);

                    /* WARNING: Subroutine does not return */

  operator_delete(unaff_EBX);

}
