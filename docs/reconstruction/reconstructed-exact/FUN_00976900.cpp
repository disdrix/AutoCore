// =============================================================================
// FUN_00976900
// -----------------------------------------------------------------------------
// Stable ID: aa_00976900
// Address:   0x00976900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00976900 @ 0x00976900
// Stable ID: aa_00976900
// Embedded strings (evidence for future rename):
//   - "%d , %f %f %f , %f %f %f %f , %d\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×1.
//  - Notable callees: sscanf×2, CONCAT31, FUN_00406220, FUN_007b6a20, FUN_007b7420, FUN_00976900, GetTickCount, _vbase_destructor_.
//  - Strings: "%d , %f %f %f , %f %f %f %f , %d\n".
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

int __fastcall

FUN_00976900(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,uint8_t param_4,uint32_t /* width from decompiler */ *param_5)



{

  char cVar1;

  DWORD DVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  int iStack_8c0;

  int iStack_8bc;

  uint8_t auStack_8b8 [4];

  uint32_t /* width from decompiler */ uStack_8b4;

  uint32_t /* width from decompiler */ uStack_8b0;

  uint32_t /* width from decompiler */ uStack_8ac;

  uint32_t /* width from decompiler */ uStack_8a8;

  uint32_t /* width from decompiler */ uStack_8a4;

  uint32_t /* width from decompiler */ uStack_8a0;

  float fStack_89c;

  uint8_t auStack_898 [4];

  char *pcStack_894;

  basic_istream<char,struct_std::char_traits<char>_> abStack_890 [60];

  undefined **local_854 [18];

  char acStack_80c [1024];

  char acStack_40c [1024];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b1430;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_3 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x10) = *param_1;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x14) = param_1[1];

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x18) = param_1[2];

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c) = param_1[3];

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x20) = *param_5;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x24) = param_5[1];

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x28) = param_5[2];

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c) = param_5[3];

  *(uint8_t *)(param_3 + 0x30) = param_4;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x34) = in_XMM0_Da;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x74) = 0;

  local_4 = 0;

  DVar2 = GetTickCount();

  *(DWORD *)(param_3 + 4) = DVar2;

  if (param_2 != 0) {

    FUN_007b6a20(param_2);

    piVar3 = (int *)FUN_007b7420(param_2);

    if (piVar3 != (int *)0x0) {

      std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 local_854,3);

      local_854[0] = &PTR_FUN_00a97b28;

      local_4._0_1_ = 1;

      pcVar6 = (char *)piVar3[1];

      uVar4 = (**(code **)(*piVar3 + 0x1c))();

      std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Init

                ((basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 local_854,pcVar6,uVar4,0);

      std::basic_istream<char,struct_std::char_traits<char>_>::

      basic_istream<char,struct_std::char_traits<char>_>

                (abStack_890,(basic_streambuf<char,struct_std::char_traits<char>_> *)local_854,false

                 ,false);

      local_4 = CONCAT31(local_4._1_3_,2);

      std::basic_istream<char,struct_std::char_traits<char>_>::getline

                (abStack_890,acStack_40c,0x3ff,'\n');

      iVar5 = sscanf(acStack_40c,"%d",&iStack_8bc);

      if ((iVar5 < 1) || (100000 < iStack_8bc)) {

        (**(code **)*piVar3)(1);

      }

      else {

        iStack_8c0 = 0;

        if (0 < iStack_8bc) {

          do {

            uStack_8ac = 0;

            uStack_8b0 = 0;

            uStack_8b4 = 0;

            uStack_8a0 = 0;

            uStack_8a4 = 0;

            uStack_8a8 = 0;

            fStack_89c = g_flMsToSeconds_Inferred;

            std::basic_istream<char,struct_std::char_traits<char>_>::getline

                      (abStack_890,acStack_40c,0x3ff,'\n');

            iVar5 = sscanf(acStack_40c,"%d , %f %f %f , %f %f %f %f , %d\n",auStack_8b8,&uStack_8b4,

                           &uStack_8b0,&uStack_8ac,&uStack_8a8,&uStack_8a4,&uStack_8a0,&fStack_89c,

                           auStack_898);

            if (iVar5 == 9) {

              std::basic_istream<char,struct_std::char_traits<char>_>::getline

                        (abStack_890,acStack_80c,0x3ff,'\n');

              pcVar6 = acStack_80c;

              do {

                cVar1 = *pcVar6;

                pcVar6 = pcVar6 + 1;

              } while (cVar1 != '\0');

              uVar4 = (int)pcVar6 - (int)(acStack_80c + 1);

              if (uVar4 < 2) {

                pcStack_894 = (char *)0x0;

              }

              else {

                cVar1 = *(char *)((int)local_854 + uVar4 + 0x47);

                if ((cVar1 == '\n') || (cVar1 == '\r')) {

                  *(uint8_t *)((int)local_854 + uVar4 + 0x47) = 0;

                }

                pcStack_894 = operator_new__(uVar4 + 1);

                pcVar6 = acStack_80c;

                pcVar7 = pcStack_894;

                do {

                  cVar1 = *pcVar6;

                  *pcVar7 = cVar1;

                  pcVar6 = pcVar6 + 1;

                  pcVar7 = pcVar7 + 1;

                } while (cVar1 != '\0');

              }

              FUN_00406220();

            }

            iStack_8c0 = iStack_8c0 + 1;

          } while (iStack_8c0 < iStack_8bc);

        }

        (**(code **)*piVar3)(1);

        if ((*(int *)(param_3 + 0x6c) != 0) &&

           ((*(int *)(param_3 + 0x70) - *(int *)(param_3 + 0x6c)) / 0x28 != 0)) {

          *(uint32_t /* width from decompiler */ *)(param_3 + 8) = *(uint32_t /* width from decompiler */ *)(param_3 + 4);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x10);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x14);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x18);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x20);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x24);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x58) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x28);

          *(uint32_t /* width from decompiler */ *)(param_3 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c);

        }

      }

      local_4._0_1_ = 1;

      std::basic_istream<char,struct_std::char_traits<char>_>::_vbase_destructor_(abStack_890);

      local_4 = (uint)local_4._1_3_ << 8;

      std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                ((basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 local_854);

    }

  }

  ExceptionList = local_c;

  return param_3;

}
