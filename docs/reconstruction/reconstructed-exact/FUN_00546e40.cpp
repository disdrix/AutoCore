// =============================================================================
// FUN_00546e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00546e40
// Address:   0x00546e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00546e40 @ 0x00546e40
// Stable ID: aa_00546e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, for×1.
//  - Notable callees: FUN_00545e30, FUN_00546e40, FUN_00548210, FUN_0059dcc0.

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

void __thiscall FUN_00546e40(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4228;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_10 = param_1;

  FUN_00545e30();

  iVar2 = 0;

  puVar3 = param_2;

  puVar4 = param_1;

  for (iVar1 = 0x4e; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  param_1[0x4d] = 0;

  *(uint8_t *)(param_1 + 0x5a) = 0;

  if (*(char *)(param_1 + 0x4c) != '\0') {

    do {

      if ((param_1[0x4f] == 0) || ((int)(param_1[0x50] - param_1[0x4f]) >> 2 < 1)) {

        local_10 = operator_new(0x168);

        local_4 = 0;

        if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

          local_10 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          local_10 = (uint32_t /* width from decompiler */ *)FUN_0059dcc0(*(uint32_t /* width from decompiler */ *)(param_2[0x4d] + iVar2 * 4),param_1);

        }

        iVar1 = param_1[0x4f];

        local_4 = 0xffffffff;

        if ((iVar1 == 0) ||

           ((uint)(param_1[0x51] - iVar1 >> 2) <= (uint)(param_1[0x50] - iVar1 >> 2))) {

          FUN_00548210(param_1[0x50],1,&local_10);

        }

        else {

          puVar3 = (uint32_t /* width from decompiler */ *)param_1[0x50];

          *puVar3 = local_10;

          param_1[0x50] = puVar3 + 1;

        }

        iVar2 = iVar2 + 1;

      }

    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x4c));

  }

  do {

                    /* WARNING: Do nothing block with infinite loop */

  } while( true );

}
