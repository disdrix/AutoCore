// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×11, return×10.
//  - Notable callees: FUN_006a5dac×5, FUN_006b7a5a×5, FUN_0076cec0×5, vog_LogMessage×5, OutputDebugStringA×3, SetCooperativeLevel×3, FUN_007965a0×2, DirectInput8Create.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDUserInterface.cpp"; "%s - %s\r\n%s"; "Failed to create an interface to the system mouse device"; "Failed to create an immediate mouse format".
//  - Return sites: 10.

// =============================================================================
// Named_NDUserInterface_00796d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00796d70
// Address:   0x00796d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "NDUserInterface"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_NDUserInterface_00796d70(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  char *pcStack_40;

  uint32_t /* width from decompiler */ **ppuStack_3c;

  uint32_t /* width from decompiler */ *puStack_1c;

  uint32_t /* width from decompiler */ *puStack_18;

  uint32_t /* width from decompiler */ *puStack_14;

  

  puVar1 = (uint32_t /* width from decompiler */ *)(in_EAX + 8);

  puStack_18 = (uint32_t /* width from decompiler */ *)&DAT_00a0d124;

  puStack_1c = (uint32_t /* width from decompiler */ *)0x800;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x80) = param_1;

  puStack_14 = puVar1;

  GetModuleHandleA((LPCSTR)0x0);

  puVar3 = (uint32_t /* width from decompiler */ *)DirectInput8Create();

  if ((int)puVar3 < 0) {

    puStack_18 = (uint32_t /* width from decompiler */ *)0x796dae;

    puStack_14 = puVar3;

    puStack_18 = (uint32_t /* width from decompiler */ *)FUN_006b7a5a();

    puStack_1c = puVar3;

    FUN_006a5dac();

    FUN_0076cec0();

    ppuStack_3c = (uint32_t /* width from decompiler */ **)0x796dd4;

    vog_LogMessage();

    return -0x7fffbffb;

  }

  puStack_14 = (uint32_t /* width from decompiler */ *)0x0;

  puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x70);

  puStack_1c = (uint32_t /* width from decompiler */ *)&DAT_00a0d074;

  puStack_18 = puVar3;

  iVar4 = (**(code **)(*(int *)*puVar1 + 0xc))();

  if (iVar4 < 0) {

    FUN_006b7a5a();

    FUN_006a5dac();

    ppuStack_3c = &puStack_14;

    pcStack_40 = (char *)0x796e1e;

    pcStack_40 = (char *)FUN_0076cec0();

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDUserInterface.cpp",0x70,3);

    return iVar4;

  }

  iVar4 = (**(code **)(*(int *)*puVar3 + 0x2c))();

  if (iVar4 < 0) {

    FUN_006b7a5a();

    ppuStack_3c = (uint32_t /* width from decompiler */ **)0x796e5e;

    ppuStack_3c = (uint32_t /* width from decompiler */ **)FUN_006a5dac();

    pcStack_40 = "%s - %s\r\n%s";

    uVar5 = FUN_0076cec0(&puStack_1c);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDUserInterface.cpp",0x7d,3,uVar5);

    return iVar4;

  }

  iVar4 = (**(code **)(*(int *)*puVar3 + 0x34))();

  if (iVar4 != -0x7fffbfff) {

    if (-1 < iVar4) {

      uVar5 = 0;

      puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x74);

      pcStack_40 = &DAT_00a0d084;

      ppuStack_3c = (uint32_t /* width from decompiler */ **)puVar3;

      iVar4 = (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1);

      if (iVar4 < 0) {

        uVar5 = FUN_006b7a5a(iVar4,"Failed to create an interface to the system mouse device");

        uVar5 = FUN_006a5dac(iVar4,uVar5);

        uVar5 = FUN_0076cec0(&stack0xffffffc8,"%s - %s\r\n%s",uVar5);

        vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDUserInterface.cpp",0x9a,3,uVar5

                      );

        return iVar4;

      }

      iVar4 = (**(code **)(*(int *)*puVar3 + 0x2c))((int *)*puVar3,&DAT_009ebb04);

      if (iVar4 < 0) {

        uVar5 = FUN_006b7a5a(iVar4,"Failed to create an immediate mouse format");

        uVar5 = FUN_006a5dac(iVar4,uVar5);

        uVar5 = FUN_0076cec0(&pcStack_40,"%s - %s\r\n%s",uVar5);

        vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDUserInterface.cpp",0xa4,3,uVar5

                      );

        return iVar4;

      }

      iVar4 = (**(code **)(*(int *)*puVar3 + 0x34))((int *)*puVar3,uVar5,6);

      if (iVar4 == -0x7fffbfff) {

        FUN_007965a0();

        OutputDebugStringA(

                          "SetCooperativeLevel() returned DIERR_UNSUPPORTED.\nFor security reasons, background exclusive mouse\naccess is not allowed."

                          );

        return -0x7fffbfff;

      }

      uVar5 = 0;

      puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x78);

      iVar6 = (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,&DAT_00a0d064,puVar3,0);

      if (-1 < iVar6) {

        iVar6 = (**(code **)(*(int *)*puVar3 + 0x2c))((int *)*puVar3,&DAT_009ebd0c);

        piVar2 = (int *)*puVar3;

        if (-1 < iVar6) {

          iVar6 = (**(code **)(*piVar2 + 0x34))(piVar2,uVar5,6);

          if (iVar6 != -0x7fffbfff) {

            iVar4 = (**(code **)(*(int *)*puVar3 + 0x10))((int *)*puVar3,&LAB_00796920);

            return iVar4;

          }

          (**(code **)(*(int *)*puVar3 + 0x20))((int *)*puVar3);

          (**(code **)(*(int *)*puVar3 + 8))((int *)*puVar3);

          *puVar3 = 0;

          OutputDebugStringA(

                            "SetCooperativeLevel() returned DIERR_UNSUPPORTED.\nFor security reasons, background exclusive joystick\naccess is not allowed."

                            );

          return iVar4;

        }

        (**(code **)(*piVar2 + 0x20))(piVar2);

        (**(code **)(*(int *)*puVar3 + 8))((int *)*puVar3);

        *puVar3 = 0;

      }

    }

    return iVar4;

  }

  FUN_007965a0();

  ppuStack_3c = (uint32_t /* width from decompiler */ **)0x796eaf;

  OutputDebugStringA(

                    "SetCooperativeLevel() returned DIERR_UNSUPPORTED.\nFor security reasons, background exclusive keyboard\naccess is not allowed."

                    );

  return -0x7fffbfff;

}
