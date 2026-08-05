// =============================================================================
// FUN_0067ed60
// -----------------------------------------------------------------------------
// Stable ID: aa_0067ed60
// Address:   0x0067ed60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067ed60 @ 0x0067ed60
// Stable ID: aa_0067ed60
// Embedded strings (evidence for future rename):
//   - "Received an invalid aggregate packet (invalid flags %x)"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, do×2, while×2, goto×1.
//  - Notable callees: FUN_0067d980, FUN_0067e2b0, FUN_0067e3a0, FUN_0067ed60, FUN_0076cec0, packet, thunk_FUN_0076c4d0, vog_LogMessage.
//  - Strings: "Received an invalid aggregate packet (invalid flags %x)".
//  - Return sites: 4.

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

char __thiscall FUN_0067ed60(int param_1,uint param_2,uint32_t /* width from decompiler */ *param_3,uint param_4)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint16_t local_8;

  ushort local_6;

  char local_4;

  uint8_t local_3;

  uint16_t local_2;

  

  cVar2 = *(char *)(param_2 + 0xd);

  if (cVar2 != '@') {

    if (cVar2 == '\0') {

      thunk_FUN_0076c4d0();

      return '\x01';

    }

    uVar4 = FUN_0076cec0(&param_2,"Received an invalid aggregate packet (invalid flags %x)",cVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x3f2,1,uVar4);

    return '\0';

  }

  if (*(int *)(param_1 + 0x2a3c) != 0) {

    piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x50);

    *piVar1 = *piVar1 + 1;

  }

  param_2 = param_4;

  puVar6 = param_3;

  do {

    if (param_2 < 0xc) {

      return '\x01';

    }

    local_10 = *puVar6;

    local_c = puVar6[1];

    local_3 = *(uint8_t *)((int)puVar6 + 0xb);

    local_6 = *(ushort *)(puVar6 + 2);

    local_4 = *(char *)((int)puVar6 + 10);

    uVar5 = (uint)local_6;

    puVar6 = puVar6 + 3;

    local_8 = 0;

    local_2 = 0;

    if (*(int *)(param_1 + 0x2a3c) != 0) {

      piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x58);

      *piVar1 = *piVar1 + 1;

    }

    if (local_4 == '\0') {

      cVar2 = FUN_0067e3a0(&local_10,puVar6,uVar5);

    }

    else if (local_4 == -2) {

      FUN_0067d980(0xfe,puVar6,uVar5);

      iVar3 = 0;

      if (*(byte *)(param_1 + 6) != 0) {

        do {

          if (*(char *)(param_1 + 7 + iVar3) == -2) goto LAB_0067ee3b;

          iVar3 = iVar3 + 1;

        } while (iVar3 < (int)(uint)*(byte *)(param_1 + 6));

      }

      *(uint8_t *)(*(byte *)(param_1 + 6) + 7 + param_1) = 0xfe;

      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';

LAB_0067ee3b:

      cVar2 = '\x01';

    }

    else if (local_4 == -1) {

      cVar2 = '\0';

    }

    else {

      cVar2 = FUN_0067e2b0(&local_10,puVar6,uVar5);

    }

    param_2 = param_2 + (-0xc - uVar5);

    puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + uVar5);

    if (cVar2 != '\x01') {

      return cVar2;

    }

  } while( true );

}
