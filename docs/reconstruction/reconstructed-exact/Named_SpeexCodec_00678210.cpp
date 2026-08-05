// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×2, while×2.
//  - Notable callees: FUN_00678210, FUN_00702930, FUN_00702ea0, FUN_00702f60, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Codec cannot encode".
//  - Return sites: 3.

// =============================================================================
// Named_SpeexCodec_00678210
// -----------------------------------------------------------------------------
// Stable ID: aa_00678210
// Address:   0x00678210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "SpeexCodec"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall Named_SpeexCodec_00678210(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  

  iVar5 = param_2;

  if (*(int *)(param_1 + 4) != 0) {

    uVar1 = FUN_0076cec0(&param_2,"Codec cannot encode");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\SpeexCodec.cpp"

                   ,0x66,3,uVar1);

    return 0xffffffff;

  }

  iVar4 = param_1 + 0x2c;

  FUN_00702f60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),param_2,iVar4);

  uVar1 = FUN_00702ea0(iVar4,param_3,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  *param_4 = uVar1;

  FUN_00702930(iVar4);

  if (*(char *)(param_1 + 0x16) != '\0') {

    if ((_DAT_00d06a98 & 1) == 0) {

      _DAT_00d06a98 = _DAT_00d06a98 | 1;

      DAT_00d06a94 = 4;

    }

    iVar4 = 1;

    iVar7 = 0;

    if (*(int *)(param_1 + 0xc) / 2 != 1) {

      do {

        uVar2 = (uint)*(ushort *)(iVar5 + iVar4 * 2) - (uint)*(ushort *)(iVar5 + -2 + iVar4 * 2);

        uVar6 = (int)uVar2 >> 0x1f;

        iVar4 = iVar4 + 1;

        iVar7 = iVar7 + ((uVar2 ^ uVar6) - uVar6);

      } while (iVar4 != *(int *)(param_1 + 0xc) / 2);

    }

    *(int *)(param_1 + 0x8c + *(int *)(param_1 + 0x88) * 4) = iVar7;

    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;

    if (0x13 < *(int *)(param_1 + 0x88)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

    }

    iVar4 = 0;

    piVar3 = (int *)(param_1 + 0x8c);

    iVar5 = 0x14;

    do {

      if (10000 < *piVar3) {

        iVar4 = iVar4 + 1;

      }

      piVar3 = piVar3 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    if (*(char *)(param_1 + 0x15) == '\0') {

      if (DAT_00d06a94 < iVar4) {

        *(uint8_t *)(param_1 + 0x15) = 1;

      }

    }

    else if (iVar4 < DAT_00d06a94) {

      *(uint8_t *)(param_1 + 0x15) = 0;

      return 0;

    }

  }

  return 0;

}
