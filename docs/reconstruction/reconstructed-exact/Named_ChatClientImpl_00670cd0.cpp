// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, while×1, switch×1.
//  - Notable callees: FUN_00671630×2, FUN_006716c0×2, FUN_00680220×2, FUN_00680c30×2, FUN_00680c50×2, FUN_0076cec0×2, thunk_FUN_0076c4d0×2, vog_LogMessage×2.
//  - Strings: "input thread setup."; "Uknown result: %d".
//  - Return sites: 2.

// =============================================================================
// Named_ChatClientImpl_00670cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00670cd0
// Address:   0x00670cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_ChatClientImpl_00670cd0(int param_1)



{

  int iVar1;

  void *pvVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *local_54;

  uint32_t /* width from decompiler */ local_50;

  uint8_t auStack_4c [4];

  uint8_t auStack_48 [4];

  uint8_t local_44 [28];

  uint8_t auStack_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a90c7;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x2c) != 0) {

    ExceptionList = &local_c;

    cVar3 = FUN_00680220(&local_50,&local_54);

    pvVar2 = local_54;

    while (cVar3 != '\0') {

      local_54 = pvVar2;

      switch(local_50) {

      case 1:

        uVar5 = FUN_0076cec0(auStack_4c,"input thread setup.");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                       ,0x290,1,uVar5);

        break;

      case 2:

        if (*(int *)(param_1 + 0x38) != 0) {

          if (*(char *)(param_1 + 0x184) == '\0') {

            *(uint8_t *)(param_1 + 0x184) = 1;

          }

          FUN_00680c30();

          local_4 = 1;

          if (*(int *)(param_1 + 0x1c8) == 4) {

            FUN_0067aad0(auStack_28,*(uint8_t *)(param_1 + 0xc));

          }

          else {

            *(short *)(param_1 + 0x204) = *(short *)(param_1 + 0x204) + 1;

            FUN_0067a630(auStack_28,

                         CONCAT11((char)((ushort)*(uint16_t *)(param_1 + 0x204) >> 8),

                                  *(uint8_t *)(param_1 + 0xc)),*(uint16_t *)(param_1 + 0x204));

            thunk_FUN_0076c4d0();

          }

          if (*(int *)(param_1 + 0x1c8) == 4) {

            iVar1 = *(int *)(param_1 + 0x214);

            iVar4 = FUN_00671630(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),auStack_28);

            FUN_006716c0(1);

            *(int *)(iVar1 + 4) = iVar4;

            **(int **)(iVar4 + 4) = iVar4;

          }

          else {

            (**(code **)(**(int **)(param_1 + 0x38) + 4))(auStack_28,0);

          }

          (**(code **)(**(int **)(param_1 + 0x54) + 0x20))(*(uint8_t *)(param_1 + 0xc));

          if (*(char *)(param_1 + 0x1cc) != '\0') {

            FUN_00673da0(*(uint8_t *)(param_1 + 0xc));

          }

          local_4 = 0xffffffff;

          FUN_00680c50();

        }

        break;

      case 3:

        if (*(int *)(param_1 + 0x38) != 0) {

          FUN_00680c30();

          local_4 = 0;

          if (*(int *)(param_1 + 0x1c8) == 4) {

            FUN_0067aa10(local_44,*(uint8_t *)(param_1 + 0xc),0,0);

          }

          else {

            FUN_0067a5d0(local_44,*(uint8_t *)(param_1 + 0xc));

            thunk_FUN_0076c4d0();

          }

          if (*(int *)(param_1 + 0x1c8) == 4) {

            iVar1 = *(int *)(param_1 + 0x214);

            iVar4 = FUN_00671630(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),local_44);

            FUN_006716c0(1);

            *(int *)(iVar1 + 4) = iVar4;

            **(int **)(iVar4 + 4) = iVar4;

          }

          else {

            (**(code **)(**(int **)(param_1 + 0x38) + 4))(local_44,0);

          }

          (**(code **)(**(int **)(param_1 + 0x54) + 0x24))

                    (*(uint8_t *)(param_1 + 0xc),DAT_00af5240);

          if (*(char *)(param_1 + 0x1cc) != '\0') {

            FUN_00673dc0(*(uint8_t *)(param_1 + 0xc));

          }

          local_4 = 0xffffffff;

          FUN_00680c50();

        }

        break;

      case 4:

        if ((*(char *)(param_1 + 0x58) != '\0') && (*(int *)(*(int *)(param_1 + 0x2c) + 0x164) != 0)

           ) {

          FUN_006705f0(pvVar2);

        }

        operator_delete__(*(void **)((int)pvVar2 + 4));

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      default:

        uVar5 = FUN_0076cec0(auStack_48,"Uknown result: %d",local_50);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                       ,0x294,1,uVar5);

      }

      cVar3 = FUN_00680220(&local_50,&local_54);

      pvVar2 = local_54;

    }

  }

  ExceptionList = local_c;

  return 1;

}
