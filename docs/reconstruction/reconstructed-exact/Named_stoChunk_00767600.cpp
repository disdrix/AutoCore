// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×16, return×12, switch×2, for×2, do×1, while×1, goto×1.
//  - Notable callees: ConvertToInteger, FUN_00767600, __allmul, isdigit, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"; "Invalid integer length in ConvertToInteger()".
//  - Return sites: 12.

// =============================================================================
// Named_stoChunk_00767600
// -----------------------------------------------------------------------------
// Stable ID: aa_00767600
// Address:   0x00767600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "stoChunk"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_stoChunk_00767600(uint32_t /* width from decompiler */ *param_1,uint param_2,int param_3)



{

  ulonglong uVar1;

  ulonglong uVar2;

  char cVar3;

  int in_EAX;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  uint64_t *puVar7;

  bool bVar8;

  longlong lVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint64_t local_8;

  

  uVar1 = 0;

  bVar8 = false;

  local_8._0_4_ = 0;

  local_8._4_4_ = 0;

  if (*(uint *)(in_EAX + 0x18) < 0x10) {

    pcVar6 = (char *)(in_EAX + 4);

  }

  else {

    pcVar6 = *(char **)(in_EAX + 4);

  }

  if (*pcVar6 == '\0') {

    return 0xffffffff;

  }

  if (*pcVar6 == '-') {

    bVar8 = true;

    if (param_3 == 0) {

      return 0xffffffff;

    }

    pcVar6 = pcVar6 + 1;

  }

  cVar3 = *pcVar6;

  uVar2 = 0;

  if (cVar3 != '\0') {

    do {

      iVar4 = isdigit((int)cVar3);

      if (iVar4 == 0) {

        return 0xffffffff;

      }

      lVar9 = __allmul(uVar1,10,0);

      cVar3 = pcVar6[1];

      uVar1 = (lVar9 + (int)*pcVar6) - 0x30;

      pcVar6 = pcVar6 + 1;

    } while (cVar3 != '\0');

    local_8 = uVar1;

    uVar2 = uVar1;

  }

  local_8._4_4_ = (int)(uVar2 >> 0x20);

  local_8._0_4_ = (int)uVar2;

  if (param_3 == 0) {

    switch(param_2) {

    case 1:

      if ((uVar2 & 0xffffff00) != 0 || local_8._4_4_ != 0) {

        return 0xffffffff;

      }

      break;

    case 2:

      if ((uVar2 & 0xffff0000) != 0 || local_8._4_4_ != 0) {

        return 0xffffffff;

      }

      break;

    default:

      uVar10 = 0x3ab;

LAB_007677dd:

      local_8 = uVar2;

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",uVar10,3,

                     "Invalid integer length in ConvertToInteger()");

      return 0xffffffff;

    case 4:

      if (local_8._4_4_ != 0) {

        return 0xffffffff;

      }

      break;

    case 8:

      break;

    }

  }

  else if (param_3 == 1) {

    switch(param_2) {

    case 1:

      if ((uVar2 & 0xffffff80) != 0 || local_8._4_4_ != 0) {

        return 0xffffffff;

      }

      break;

    case 2:

      if ((uVar2 & 0xffff8000) != 0 || local_8._4_4_ != 0) {

        return 0xffffffff;

      }

      break;

    default:

      uVar10 = 0x3c3;

      goto LAB_007677dd;

    case 4:

      if ((uVar2 & 0x80000000) != 0 || local_8._4_4_ != 0) {

        return 0xffffffff;

      }

      break;

    case 8:

      if ((uVar2 & 0x8000000000000000) != 0) {

        return 0xffffffff;

      }

    }

    if (bVar8) {

      bVar8 = (int)local_8 != 0;

      local_8._0_4_ = -(int)local_8;

      local_8._4_4_ = -(local_8._4_4_ + (uint)bVar8);

    }

  }

  puVar7 = &local_8;

  for (uVar5 = param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *param_1 = *(uint32_t /* width from decompiler */ *)puVar7;

    puVar7 = (uint64_t *)((int)puVar7 + 4);

    param_1 = param_1 + 1;

  }

  for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {

    *(uint8_t *)param_1 = *(uint8_t *)puVar7;

    puVar7 = (uint64_t *)((int)puVar7 + 1);

    param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

  }

  return 0;

}
