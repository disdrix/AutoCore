// READABILITY (auto CF):
//  - Body size: ~564 non-empty decompiler lines.
//  - Control keywords: if×49, return×12, goto×8, switch×1, do×1, while×1.
//  - Notable callees: FUN_0076cec0×27, vog_LogMessage×25, FUN_00681dc0×22, CONCAT31×14, FUN_0067b110×7, FUN_0067b1b0×7, FUN_0067ba30×7, FUN_00680c50×7.
//  - Strings: "TCP connection non-blocking outbound connection failed"; ");

      vog_LogMessage("; "send to %s failed"; "Error initializing encryptor - bad private key?".
//  - Return sites: 12.

// =============================================================================
// Named_netTcpConnection_00682bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00682bb0
// Address:   0x00682bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netTcpConnection"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t __fastcall Named_netTcpConnection_00682bb0(int param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  short *psVar8;

  short *psVar9;

  bool bVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint8_t local_1a9;

  int *piStack_1a8;

  char cStack_1a1;

  int *piStack_1a0;

  int *piStack_19c;

  uint8_t auStack_198 [12];

  int *piStack_18c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_17c [20];

  int iStack_168;

  uint8_t auStack_160 [4];

  uint8_t auStack_15c [4];

  int iStack_158;

  int iStack_150;

  int iStack_14c;

  uint8_t auStack_140 [16];

  uint8_t auStack_130 [16];

  uint8_t auStack_120 [16];

  uint8_t auStack_110 [16];

  uint8_t auStack_100 [16];

  uint8_t auStack_f0 [16];

  uint8_t auStack_e0 [16];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d0 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b4 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_98 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_7c [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_60 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int iStack_4;

  

  iStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a9b68;

  local_c = ExceptionList;

  local_1a9 = 1;

  if (*(int *)(param_1 + 0x18) == 7) {

    return 1;

  }

  switch(*(int *)(param_1 + 0x18)) {

  case 0:

    ExceptionList = &local_c;

    cVar1 = FUN_0067b470(&piStack_19c);

    if (cVar1 == '\0') {

      ExceptionList = local_c;

      return 1;

    }

    if (piStack_19c == (int *)0x0) {

      thunk_FUN_0076c4d0();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 4;

      ExceptionList = local_c;

      return 1;

    }

    uVar4 = FUN_0076cec0(&piStack_1a8,"TCP connection non-blocking outbound connection failed");

    uVar11 = 0x26f;

    goto LAB_00682c47;

  case 1:

    if ((*(int *)(param_1 + 0x30) == 0) || (*(int *)(param_1 + 0x2c) == 0)) {

      ExceptionList = &local_c;

      uVar4 = FUN_0076cec0(&piStack_1a8,

                           "Attempting to negotiation without a key exchanger or encryptor");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,0x27d,2,uVar4);

      FUN_00681dc0();

      ExceptionList = local_c;

      return 0;

    }

    ExceptionList = &local_c;

    cVar1 = FUN_00682850(&piStack_19c);

    if (cVar1 == '\x01') {

      thunk_FUN_0076c4d0();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 2;

    }

    else if ((piStack_19c == (int *)0x1) || (piStack_19c == (int *)0x0)) {

      FUN_0067ba30(auStack_110);

      iStack_4 = 0;

      iVar5 = FUN_0067b1b0(abStack_d0);

      iStack_4._0_1_ = 1;

      if (*(uint *)(iVar5 + 0x18) < 0x10) {

        iVar5 = iVar5 + 4;

      }

      else {

        iVar5 = *(int *)(iVar5 + 4);

      }

      uVar4 = FUN_0076cec0(&piStack_1a8,"send to %s failed",iVar5);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,0x28f,1,uVar4);

      iStack_4 = (uint)iStack_4._1_3_ << 8;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d0);

      iStack_4 = 0xffffffff;

      FUN_0067b110();

      FUN_00681dc0();

      local_1a9 = 0;

    }

    break;

  case 2:

    ExceptionList = &local_c;

    FUN_00680c30();

    iStack_4 = 2;

    cVar1 = FUN_00682390(auStack_198);

    if (cVar1 == '\x01') {

      cStack_1a1 = '\0';

      if ((int *)0x4 < piStack_18c) {

        FUN_00680d90(&piStack_19c,4);

        piVar6 = piStack_19c;

        if ((piStack_18c == piStack_19c + 1) && (piStack_19c != (int *)0x0)) {

          FUN_00680cf0(&piStack_1a0);

          piVar7 = piStack_1a0 + 1;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_17c);

          iStack_4._0_1_ = 3;

          iVar5 = (**(code **)(**(int **)(param_1 + 0x30) + 0x20))(piVar7,piVar6,abStack_17c);

          if ((iVar5 != 0) || (iStack_168 == 0)) {

            uVar4 = FUN_0076cec0(&piStack_1a8,

                                 "Error fetching private key from key exchanger, invalid public key?"

                                );

            vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                           ,0x2b7,2,uVar4);

            FUN_00681dc0();

            local_1a9 = 0;

            iStack_4 = CONCAT31(iStack_4._1_3_,2);

LAB_00682eea:

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (abStack_17c);

            goto LAB_00682ef4;

          }

          iVar5 = (**(code **)(**(int **)(param_1 + 0x2c) + 4))(abStack_17c,1);

          if (iVar5 != 0) {

            uVar4 = FUN_0076cec0(&piStack_1a8,"Error initializing encryptor - bad private key?");

            vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                           ,0x2c2,2,uVar4);

            cStack_1a1 = '\x01';

          }

          operator_delete__(piStack_1a0);

          if (*(char *)(param_1 + 0x2a) != '\0') {

            if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x30) != (uint32_t /* width from decompiler */ *)0x0) {

              (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x30))(1);

            }

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

          }

          *(uint8_t *)(param_1 + 0x28) = 1;

          iStack_4 = CONCAT31(iStack_4._1_3_,2);

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_17c)

          ;

        }

        else {

          FUN_0067ba30(auStack_120);

          iStack_4._0_1_ = 4;

          iVar5 = FUN_0067b1b0(abStack_44);

          iStack_4._0_1_ = 5;

          if (*(uint *)(iVar5 + 0x18) < 0x10) {

            iVar5 = iVar5 + 4;

          }

          else {

            iVar5 = *(int *)(iVar5 + 4);

          }

          uVar4 = FUN_0076cec0(&piStack_1a8,"bad negotiation packet from %s",iVar5);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                         ,0x2d5,1,uVar4);

          iStack_4._0_1_ = 4;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_44);

          iStack_4 = CONCAT31(iStack_4._1_3_,2);

          FUN_0067b110();

          cStack_1a1 = '\x01';

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 3;

        if (cStack_1a1 != '\0') {

          uVar4 = FUN_0076cec0(&piStack_1a8,"Received bad packet during negotiation");

          vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                         ,0x2df,2,uVar4);

          FUN_00681dc0();

          local_1a9 = 0;

        }

      }

    }

    else {

      if ((*(int **)(param_1 + 4) != (int *)0x0) && (**(int **)(param_1 + 4) != -1)) {

        iVar5 = FUN_0076c3c0();

        if ((float)iVar5 * g_flMsToSeconds_Inferred <= DAT_00aaa9f0) goto LAB_00682ef4;

        uVar4 = FUN_0076cec0(&piStack_1a8,"Negotiation timed out");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x2f8,2,uVar4);

      }

      FUN_00681dc0();

      local_1a9 = 0;

    }

    goto LAB_00682ef4;

  case 3:

    ExceptionList = &local_c;

    FUN_00680c30();

    iStack_4 = 6;

    piStack_19c = (int *)&DAT_009e9fe8;

    FUN_00681020(&piStack_19c,6,0);

    cVar1 = FUN_00682a10(abStack_17c,&piStack_1a0);

    if (cVar1 == '\x01') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 7;

      iStack_4 = 0xffffffff;

      FUN_00680c50();

    }

    else {

      if ((piStack_1a0 == (int *)0x1) || (piStack_1a0 == (int *)0x0)) {

        uVar4 = FUN_0076cec0(&piStack_1a8,"Send failed during negotiation");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x315,1,uVar4);

        FUN_00681dc0();

        local_1a9 = 0;

      }

      iStack_4 = 0xffffffff;

      FUN_00680c50();

    }

    break;

  case 4:

    if ((*(int *)(param_1 + 0x30) == 0) || (*(int *)(param_1 + 0x2c) == 0)) {

      ExceptionList = &local_c;

      uVar4 = FUN_0076cec0(&piStack_1a8,"eKeyWaiting: key exchanger or encryptor not set");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,0x321,2,uVar4);

      FUN_00681dc0();

      ExceptionList = local_c;

      return 0;

    }

    ExceptionList = &local_c;

    FUN_00680c30();

    iStack_4 = 7;

    cVar1 = FUN_00682390(auStack_198);

    if (cVar1 == '\x01') {

      if (piStack_18c < (int *)0x10) {

        FUN_0067ba30(auStack_140);

        iStack_4._0_1_ = 0xf;

        iVar5 = FUN_0067b1b0(abStack_60);

        iStack_4._0_1_ = 0x10;

        if (*(uint *)(iVar5 + 0x18) < 0x10) {

          iVar5 = iVar5 + 4;

        }

        else {

          iVar5 = *(int *)(iVar5 + 4);

        }

        uVar4 = FUN_0076cec0(&piStack_1a8,"invalid packet received during negotiation with %s",iVar5

                            );

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x3ae,1,uVar4);

        iStack_4._0_1_ = 0xf;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_60);

        iStack_4 = CONCAT31(iStack_4._1_3_,7);

        FUN_0067b110();

        FUN_00681dc0();

        local_1a9 = 0;

      }

      else {

        uVar2 = FUN_00680cf0(&piStack_1a0);

        iVar5 = *piStack_1a0;

        iVar3 = piStack_1a0[1];

        piStack_19c = (int *)piStack_1a0[2];

        piVar6 = piStack_1a0 + 3;

        if ((iVar5 + 0xeU < uVar2) && (iVar5 != 0)) {

          piStack_1a8 = piVar6;

          if (((uint)(iVar3 + 0xc + iVar5) < uVar2) && (iVar3 != 0)) {

            if ((uVar2 == (int)piStack_19c + iVar5 + iVar3 + 0xc) && (piStack_19c != (int *)0x0)) {

              iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 0x1c))

                                ((int)piVar6 + iVar5,iVar3,(int)piVar6 + iVar5 + iVar3,piStack_19c);

              if (iVar3 == 0) {

                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                          (abStack_17c);

                iStack_4._0_1_ = 0xe;

                iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 0x20))

                                  (piStack_1a8,iVar5,abStack_17c);

                operator_delete__(piStack_1a0);

                if (iVar3 == 0) {

                  iVar5 = (**(code **)(**(int **)(param_1 + 0x2c) + 4))(abStack_17c,0);

                  if (iVar5 == 0) {

                    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 5;

                    iStack_4 = CONCAT31(iStack_4._1_3_,7);

                  }

                  else {

                    uVar4 = FUN_0076cec0(&piStack_1a8,

                                         "Unable to initialize encryptor - bad private key?");

                    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                                   ,0x3a2,2,uVar4);

                    FUN_00681dc0();

                    local_1a9 = 0;

                    iStack_4 = CONCAT31(iStack_4._1_3_,7);

                  }

                }

                else if (iVar3 == 3) {

                  uVar4 = FUN_0076cec0(&piStack_1a8,

                                       "Unable to retrieve private key: bad public key (remote pubkey size %lu bytes)"

                                       ,iVar5);

                  vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                                 ,0x38a,2,uVar4);

                  FUN_00681dc0();

                  local_1a9 = 0;

                  iStack_4 = CONCAT31(iStack_4._1_3_,7);

                }

                else if (iVar3 == 4) {

                  uVar4 = FUN_0076cec0(&piStack_1a8,

                                       "Unable to retrieve private key: key exchanger not initialized with prime and generator?!?"

                                      );

                  vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                                 ,0x390,2,uVar4);

                  FUN_00681dc0();

                  local_1a9 = 0;

                  iStack_4 = CONCAT31(iStack_4._1_3_,7);

                }

                else if (iVar3 == 7) {

                  uVar4 = FUN_0076cec0(&piStack_1a8,

                                       "Unable to retrieve private key: cryptopp raised exception!")

                  ;

                  vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                                 ,0x38d,2,uVar4);

                  FUN_00681dc0();

                  local_1a9 = 0;

                  iStack_4 = CONCAT31(iStack_4._1_3_,7);

                }

                else {

                  uVar4 = FUN_0076cec0(&piStack_1a8,"Unable to retrieve private key: unknown error")

                  ;

                  vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                                 ,0x393,2,uVar4);

                  FUN_00681dc0();

                  local_1a9 = 0;

                  iStack_4 = CONCAT31(iStack_4._1_3_,7);

                }

                goto LAB_00682eea;

              }

              uVar4 = FUN_0076cec0(&piStack_1a8,

                                   "set prime and generator in key exchanger failed - bad prime?");

              vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                             ,0x375,2,uVar4);

              FUN_00681dc0();

              local_1a9 = 0;

              operator_delete__(piStack_1a0);

            }

            else {

              FUN_0067ba30(auStack_100);

              iStack_4._0_1_ = 0xc;

              iVar5 = FUN_0067b1b0(abStack_7c);

              iStack_4._0_1_ = 0xd;

              if (*(uint *)(iVar5 + 0x18) < 0x10) {

                iVar5 = iVar5 + 4;

              }

              else {

                iVar5 = *(int *)(iVar5 + 4);

              }

              uVar4 = FUN_0076cec0(&piStack_1a8,"bad generator received during negotiation with %s",

                                   iVar5);

              vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                             ,0x367,2,uVar4);

              iStack_4._0_1_ = 0xc;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (abStack_7c);

              iStack_4 = CONCAT31(iStack_4._1_3_,7);

              FUN_0067b110();

              FUN_00681dc0();

              local_1a9 = 0;

              operator_delete__(piStack_1a0);

            }

          }

          else {

            FUN_0067ba30(auStack_e0);

            iStack_4._0_1_ = 10;

            iVar5 = FUN_0067b1b0(abStack_b4);

            iStack_4._0_1_ = 0xb;

            if (*(uint *)(iVar5 + 0x18) < 0x10) {

              iVar5 = iVar5 + 4;

            }

            else {

              iVar5 = *(int *)(iVar5 + 4);

            }

            uVar4 = FUN_0076cec0(&piStack_1a8,"bad prime received during negotiation with %s",iVar5)

            ;

            vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                           ,0x357,2,uVar4);

            iStack_4._0_1_ = 10;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (abStack_b4);

            iStack_4 = CONCAT31(iStack_4._1_3_,7);

            FUN_0067b110();

            FUN_00681dc0();

            local_1a9 = 0;

            operator_delete__(piStack_1a0);

          }

        }

        else {

          FUN_0067ba30(auStack_f0);

          iStack_4._0_1_ = 8;

          iVar5 = FUN_0067b1b0(abStack_98);

          iStack_4._0_1_ = 9;

          if (*(uint *)(iVar5 + 0x18) < 0x10) {

            iVar5 = iVar5 + 4;

          }

          else {

            iVar5 = *(int *)(iVar5 + 4);

          }

          uVar4 = FUN_0076cec0(&piStack_1a8,"bad public key received during negotiation with %s",

                               iVar5);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                         ,0x347,2,uVar4);

          iStack_4._0_1_ = 8;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_98);

          iStack_4 = CONCAT31(iStack_4._1_3_,7);

          FUN_0067b110();

          FUN_00681dc0();

          local_1a9 = 0;

          operator_delete__(piStack_1a0);

        }

      }

    }

    else {

      if ((*(int **)(param_1 + 4) != (int *)0x0) && (**(int **)(param_1 + 4) != -1)) {

        iVar5 = FUN_0076c3c0();

        if ((float)iVar5 * g_flMsToSeconds_Inferred <= DAT_00aaa9f0) goto LAB_00682ef4;

        FUN_0067ba30(auStack_130);

        iStack_4._0_1_ = 0x11;

        iVar5 = FUN_0067b1b0(abStack_28);

        iStack_4._0_1_ = 0x12;

        if (*(uint *)(iVar5 + 0x18) < 0x10) {

          iVar5 = iVar5 + 4;

        }

        else {

          iVar5 = *(int *)(iVar5 + 4);

        }

        uVar4 = FUN_0076cec0(&piStack_1a8,"timeout during negotiation with %s",iVar5);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x3bf,1,uVar4);

        iStack_4._0_1_ = 0x11;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_28);

        iStack_4 = CONCAT31(iStack_4._1_3_,7);

        FUN_0067b110();

        uVar4 = FUN_0076cec0(&piStack_1a8,"Negotiation timed out.");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x3c1,2,uVar4);

      }

      FUN_00681dc0();

      local_1a9 = 0;

    }

LAB_00682ef4:

    iStack_4 = 0xffffffff;

    FUN_00680c50();

    break;

  case 5:

    ExceptionList = &local_c;

    cVar1 = FUN_00682a40(&piStack_1a8);

    if (cVar1 == '\x01') {

      *(uint8_t *)(param_1 + 0x28) = 1;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 6;

      if (*(char *)(param_1 + 0x2a) == '\0') {

        ExceptionList = local_c;

        return 1;

      }

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x30) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x30))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

      ExceptionList = local_c;

      return 1;

    }

    if ((piStack_1a8 != (int *)0x1) && (piStack_1a8 != (int *)0x0)) {

      ExceptionList = local_c;

      return 1;

    }

    uVar4 = FUN_0076cec0(&piStack_19c,"Send failed during negotiation: terminating");

    uVar11 = 0x3e0;

LAB_00682c47:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                   ,uVar11,1,uVar4);

    FUN_00681dc0();

LAB_00682c5b:

    local_1a9 = 0;

    break;

  case 6:

    ExceptionList = &local_c;

    FUN_00680c30();

    iStack_4 = 0x13;

    cVar1 = FUN_00682390(auStack_15c);

    if (cVar1 == '\x01') {

      if (iStack_150 != 6) {

        uVar4 = FUN_0076cec0(&piStack_1a8,"Bad OK packet received during negotiation; len=%d",

                             iStack_150);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x407,2,uVar4);

        FUN_00681dc0();

        iStack_4 = 0xffffffff;

        FUN_00680c50();

        ExceptionList = local_c;

        return 0;

      }

      iVar5 = 3;

      bVar10 = true;

      psVar8 = (short *)(iStack_14c + iStack_158);

      psVar9 = &DAT_009e9fe8;

      do {

        if (iVar5 == 0) break;

        iVar5 = iVar5 + -1;

        bVar10 = *psVar8 == *psVar9;

        psVar8 = psVar8 + 1;

        psVar9 = psVar9 + 1;

      } while (bVar10);

      if (bVar10) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 7;

        iStack_4 = 0xffffffff;

        FUN_00680c50();

        ExceptionList = local_c;

        return 1;

      }

      uVar4 = FUN_0076cec0(&piStack_1a8,"Bad OK packet received during negotiation");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,0x3fe,2,uVar4);

      FUN_00681dc0();

      iStack_4 = 0xffffffff;

      FUN_00680c50();

      ExceptionList = local_c;

      return 0;

    }

    if ((*(int **)(param_1 + 4) == (int *)0x0) || (**(int **)(param_1 + 4) == -1)) {

      uVar4 = FUN_0076cec0(auStack_160,"Socket no longer valid during negotiation: terminating");

      uVar12 = 1;

      uVar11 = 0x40e;

LAB_0068392b:

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,uVar11,uVar12,uVar4);

      FUN_00681dc0();

      local_1a9 = 0;

    }

    else {

      iVar5 = FUN_0076c3c0();

      if (DAT_00aaa9f0 < (float)iVar5 * g_flMsToSeconds_Inferred) {

        uVar4 = FUN_0076cec0(auStack_160,"Negotiation timed out.");

        uVar12 = 2;

        uVar11 = 0x419;

        goto LAB_0068392b;

      }

    }

    iStack_4 = 0xffffffff;

    FUN_00680c50();

    break;

  case 8:

    goto LAB_00682c5b;

  }

  ExceptionList = local_c;

  return local_1a9;

}
