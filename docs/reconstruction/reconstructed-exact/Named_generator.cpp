// READABILITY (auto CF):
//  - Body size: ~223 non-empty decompiler lines.
//  - Control keywords: if×24, goto×13, for×3, return×1.
//  - Notable callees: FUN_0076cec0×7, vog_LogMessage×7, FUN_0076c3c0×4, FUN_00683e20×3, FUN_00680cf0×2, thunk_FUN_0076c4d0×2, CONCAT13, FUN_00680c30.
//  - Strings: "Shared key retrieved was zero-length?!?"; "Key exchanger said that remote public key was bad."; "

                          );

      vog_LogMessage("; "Received a garbage message waiting for key acknowledgement.".
//  - Return sites: 1.

// =============================================================================
// Named_generator
// -----------------------------------------------------------------------------
// Stable ID: aa_006840c0
// Address:   0x006840c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "generator"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Named_generator(int *param_1)



{

  bool bVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uStack_60;

  uint *local_5c;

  uint local_58;

  int local_54;

  uint8_t local_50 [4];

  uint8_t local_4c [4];

  byte local_48;

  uint8_t local_44 [12];

  uint local_38 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [20];

  int iStack_14;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9c0d;

  local_c = ExceptionList;

  uStack_60 = CONCAT13(1,(undefined3)uStack_60);

  ExceptionList = &local_c;

  FUN_00680c30();

  local_4 = 0;

  if (param_1[1] == 0) {

    cVar2 = FUN_00685210(local_44,local_4c);

    if (cVar2 == '\x01') {

      if ((local_48 == (byte)(DAT_009ea59e | DAT_009ea59d | DAT_009ea59c)) && (0xc < local_38[0])) {

        uVar7 = FUN_00680cf0(&local_5c);

        uVar4 = *local_5c;

        uVar8 = local_5c[1];

        local_58 = local_5c[2];

        if (((((uVar7 < local_58 + uVar4 + 0xc + uVar8) || (DAT_009ea768 < uVar4)) || (uVar4 == 0))

            || ((DAT_009ea764 < uVar8 || (uVar8 == 0)))) ||

           ((DAT_009ea76c < local_58 || (local_58 == 0)))) {

          uVar3 = FUN_0076cec0(local_50,

                               "Received a packet that is not large enough to contain key/prime/generator"

                              );

          vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                         ,0xb9,2,uVar3);

          bVar1 = true;

        }

        else {

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

          local_54 = (int)local_5c + uVar8 + uVar4 + 0xc;

          local_4._0_1_ = 1;

          iVar5 = (**(code **)(*(int *)param_1[4] + 0x1c))

                            ((int)local_5c + uVar4 + 0xc,uVar8,local_5c + 3,uVar4);

          iVar6 = (**(code **)(*(int *)param_1[4] + 0x20))(unaff_EBX,unaff_EBP,local_38);

          if (iVar5 == 0) {

            if (iVar6 == 0) {

              if (iStack_14 != 0) {

                (**(code **)(*(int *)param_1[3] + 4))(local_28,0);

                FUN_00683e20();

                *(uint8_t *)(param_1 + 2) = 1;

                param_1[1] = 1;

                thunk_FUN_0076c4d0();

                bVar1 = false;

                local_4 = (uint)local_4._1_3_ << 8;

                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          (local_28);

                goto LAB_00684581;

              }

              uVar3 = FUN_0076cec0(local_50,"Shared key retrieved was zero-length?!?");

              vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                             ,0xb2,2,uVar3);

            }

            else {

              if (iVar6 == 3) {

                uVar3 = FUN_0076cec0(local_50,"Key exchanger said that remote public key was bad.");

                vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                               ,0xab,2,uVar3);

              }

              uVar3 = FUN_0076cec0(local_50,

                                   "Failed retrieving shared key from exchanger, remote public key was %lu bytes"

                                   ,local_58);

              vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                             ,0xad,2,uVar3);

            }

          }

          else {

            uVar3 = FUN_0076cec0(local_50,

                                 "Failed setting prime and/or generator, prime is %lu bytes, generator is %lu bytes"

                                 ,uVar8,uVar4);

            vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                           ,0xa4,2,uVar3);

          }

          bVar1 = true;

          local_4 = (uint)local_4._1_3_ << 8;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        }

LAB_00684581:

        operator_delete__(local_5c);

        if (!bVar1) goto LAB_006845ff;

      }

      else if ((DAT_009ea59f & local_48) != 0) {

        (**(code **)(*param_1 + 0x48))();

        param_1[1] = 8;

        goto LAB_006845fa;

      }

    }

    iVar5 = FUN_0076c3c0();

    if (DAT_009ea5b4 < iVar5) {

      cVar2 = FUN_00683d50(&local_54);

      if ((cVar2 != '\0') || ((local_54 != 0 && (local_54 != 1)))) goto LAB_006845ff;

      (**(code **)(*param_1 + 0x48))();

    }

    else {

      iVar5 = FUN_0076c3c0();

      if (iVar5 <= DAT_009ea5b8) goto LAB_006845ff;

      (**(code **)(*param_1 + 0x48))();

    }

  }

  else {

    if (param_1[1] != 1) {

      uVar3 = FUN_0076cec0(&local_54,

                           "Danger Will Robinson!  Attempting to perform non-negotiation processing in the wrong class.  This should never be reached."

                          );

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                     ,0x16d,3,uVar3);

      goto LAB_006845ff;

    }

    cVar2 = FUN_00683f30(local_44);

    if (cVar2 == '\x01') {

      local_5c = (uint *)0x0;

      uVar4 = FUN_00680cf0(&local_5c);

      if (DAT_009ea5a4 < uVar4) {

        FUN_00685020(local_5c,local_4c);

        puVar9 = (uint32_t /* width from decompiler */ *)(uVar4 - DAT_009ea5a4);

        puVar10 = puVar9;

        local_5c = (uint *)(**(code **)(*(int *)param_1[3] + 0x10))();

        FUN_006839b0((int)local_5c + DAT_009ea5a4);

        local_58 = param_1[0x31] + DAT_009ea5a4;

        (**(code **)(*(int *)param_1[3] + 0x14))

                  (&local_58,&local_5c,uStack_60 + DAT_009ea5a4,puVar9,0);

        uVar8 = DAT_009ea5a4;

        puVar9 = (uint32_t /* width from decompiler */ *)param_1[0x31];

        for (uVar7 = DAT_009ea5a4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *puVar9 = *puVar10;

          puVar10 = puVar10 + 1;

          puVar9 = puVar9 + 1;

        }

        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint8_t *)puVar9 = *(uint8_t *)puVar10;

          puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

          puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        }

        cVar2 = (**(code **)(*(int *)param_1[3] + 0x24))

                          (param_1[0x31] + DAT_009ea5a0,(DAT_009ea5a4 + unaff_EDI) - DAT_009ea5a0,

                           *(uint32_t /* width from decompiler */ *)param_1[0x31]);

        if (cVar2 == '\0') {

          cVar2 = (**(code **)(*(int *)param_1[3] + 0x1c))

                            ((int)local_5c + DAT_009ea5a0,uVar4 - DAT_009ea5a0,*local_5c);

          if (cVar2 != '\0') {

            if (local_48 == (byte)(DAT_009ea59e | DAT_009ea59d | DAT_009ea59c)) {

              FUN_00683e20();

              operator_delete__(local_5c);

              goto LAB_006845ff;

            }

            if ((DAT_009ea59f & local_48) != 0) {

              (**(code **)(*param_1 + 0x48))();

              uStack_60 = 0;

              operator_delete__(local_5c);

              goto LAB_006845ff;

            }

            uVar3 = FUN_0076cec0(local_50,

                                 "Received a garbage message waiting for key acknowledgement.");

            vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                           ,0x146,2,uVar3);

          }

        }

        else {

          if (local_48 == (DAT_009ea59e | DAT_009ea59d)) {

            FUN_00685620();

            param_1[1] = 5;

            thunk_FUN_0076c4d0();

            operator_delete__(local_5c);

            goto LAB_006845ff;

          }

          if ((DAT_009ea59f & local_48) != 0) {

            (**(code **)(*param_1 + 0x48))();

            uStack_60 = 0;

            operator_delete__(local_5c);

            goto LAB_006845ff;

          }

        }

      }

      operator_delete__(local_5c);

      goto LAB_006845ff;

    }

    iVar5 = FUN_0076c3c0();

    if (DAT_009ea5b4 < iVar5) {

      FUN_00683e20();

      goto LAB_006845ff;

    }

    iVar5 = FUN_0076c3c0();

    if (iVar5 <= DAT_009ea5b8) goto LAB_006845ff;

    FUN_00685540(0);

    (**(code **)(*param_1 + 0x48))();

  }

LAB_006845fa:

  uStack_60 = 0;

LAB_006845ff:

  local_4 = 0xffffffff;

  FUN_00680c50();

  ExceptionList = local_c;

  return uStack_60 >> 0x18;

}
