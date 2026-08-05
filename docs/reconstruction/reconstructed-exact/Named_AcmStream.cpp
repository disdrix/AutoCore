// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×7, for×4, return×3, goto×1.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_00679ae0, acmFormatSuggest, acmStreamOpen, acmStreamPrepareHeader, acmStreamSize, free.
//  - Strings: "Invalid stream action"; "bad handle"; "bad flag"; "bad param".
//  - Return sites: 3.

// =============================================================================
// Named_AcmStream
// -----------------------------------------------------------------------------
// Stable ID: aa_00679ae0
// Address:   0x00679ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AcmStream"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_AcmStream(int param_1,int param_2,uint *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  void *pvVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint uVar10;

  uint uVar11;

  uint16_t local_14;

  uint16_t local_12;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint16_t local_8;

  uint16_t local_6;

  uint16_t local_4;

  

  local_14 = *(uint16_t *)(param_1 + 0x39c);

  local_4 = 0x12;

  local_10 = 8000;

  local_12 = 1;

  local_6 = 8;

  local_8 = 1;

  local_c = 8000;

  puVar3 = malloc(0x400);

  puVar6 = puVar3;

  for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *(uint16_t *)puVar3 = *(uint16_t *)(param_1 + 0x3a0);

  iVar8 = acmFormatSuggest(0,&local_14,puVar3,0x400,0x10000);

  if (iVar8 == 0) {

LAB_00679baf:

    if (param_2 == 0) {

      puVar6 = (uint32_t /* width from decompiler */ *)&local_14;

      puVar9 = puVar3;

    }

    else {

      if (param_2 != 1) {

        uVar5 = FUN_0076cec0(&param_2,"Invalid stream action");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AcmStream.cpp"

                       ,0x5e,3,uVar5);

        return -1;

      }

      puVar6 = puVar3;

      puVar9 = (uint32_t /* width from decompiler */ *)&local_14;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x3a8);

    iVar8 = acmStreamOpen(puVar1,0,puVar6,puVar9,0,0,0,0);

    free(puVar3);

    if (iVar8 == 0) {

      puVar2 = (uint *)(param_1 + 0x41c);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x418) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3a4);

      acmStreamSize(*puVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x3a4),puVar2,0);

      *param_3 = *puVar2;

      pvVar7 = operator_new(*(uint *)(param_1 + 0x418));

      *(void **)(param_1 + 0x420) = pvVar7;

      pvVar7 = operator_new(*puVar2);

      uVar11 = *(uint *)(param_1 + 0x418);

      *(void **)(param_1 + 0x424) = pvVar7;

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x420);

      for (uVar10 = uVar11 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

        *puVar6 = 0x7f7f7f7f;

        puVar6 = puVar6 + 1;

      }

      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint8_t *)puVar6 = 0x7f;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      }

      puVar6 = (uint32_t /* width from decompiler */ *)(param_1 + 0x3ac);

      puVar3 = puVar6;

      for (iVar8 = 0x15; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      *puVar6 = 0x54;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3b8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x420);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3bc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x418);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x424);

      *(uint *)(param_1 + 0x3cc) = *puVar2;

      iVar8 = acmStreamPrepareHeader(*puVar1,puVar6,0);

      return -(uint)(iVar8 != 0);

    }

  }

  else {

    if (iVar8 == 5) {

      pcVar4 = "bad handle";

    }

    else if (iVar8 == 10) {

      pcVar4 = "bad flag";

    }

    else {

      if (iVar8 != 0xb) goto LAB_00679baf;

      pcVar4 = "bad param";

    }

    uVar5 = FUN_0076cec0(&param_2,"ACM Stream error: %s",pcVar4);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AcmStream.cpp"

                   ,0x4a,3,uVar5);

  }

  return -1;

}
