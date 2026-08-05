// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_004c26f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c26f0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x004c26f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: do×6, while×6, if×3, return×1.
//  - Notable callees: FUN_00787d40×2, FUN_004c22a0, FUN_004c26f0, FUN_004c2bb0, FUN_00787af0, FUN_00787c90, strncpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_004c26f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  int local_1278;

  uint32_t /* width from decompiler */ *local_1274;

  uint32_t /* width from decompiler */ local_1270;

  uint32_t /* width from decompiler */ local_126c;

  char local_1268 [20];

  uint32_t /* width from decompiler */ local_1254;

  uint32_t /* width from decompiler */ local_1250;

  uint32_t /* width from decompiler */ local_124c;

  uint32_t /* width from decompiler */ local_1240;

  uint8_t local_123c;

  uint32_t /* width from decompiler */ local_1238;

  uint32_t /* width from decompiler */ local_1234;

  uint32_t /* width from decompiler */ local_1230;

  uint32_t /* width from decompiler */ local_122c;

  uint8_t local_1228 [4];

  uint32_t /* width from decompiler */ local_1224;

  char local_1220 [51];

  char local_11ed [251];

  char local_10f2 [51];

  char local_10bf [51];

  char local_108c [52];

  uint32_t /* width from decompiler */ local_1058;

  uint32_t /* width from decompiler */ local_1054;

  uint32_t /* width from decompiler */ local_1050;

  uint32_t /* width from decompiler */ local_104c;

  int local_1048;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1ba3;

  local_c = ExceptionList;

  uStack_10 = 0x4c270f;

  ExceptionList = &local_c;

  FUN_00787c90(param_2,0x7fffffff);

  local_4 = 0;

  FUN_00787d40(local_1228,0x1e8);

  local_1278 = 0;

  if (0 < local_1048) {

    do {

      FUN_00787d40(&local_1270,0x48);

      iVar3 = FUN_004c22a0(local_1270,local_126c);

      if (iVar3 == 0) {

        puVar4 = operator_new(0x48);

        *puVar4 = local_1270;

        puVar4[1] = local_126c;

        puVar4[9] = local_124c;

        puVar4[7] = local_1254;

        puVar4[8] = local_1250;

        *(uint8_t *)(puVar4 + 0xd) = local_123c;

        puVar4[0xc] = local_1240;

        puVar4[0xe] = local_1238;

        puVar4[0xf] = local_1234;

        puVar4[0x10] = local_1230;

        puVar4[0x11] = local_122c;

        local_1274 = puVar4;

        strncpy((char *)(puVar4 + 2),local_1268,0x11);

        *(uint8_t *)(puVar4 + 6) = 0;

        iVar3 = param_1[0x79];

        if ((iVar3 == 0) ||

           ((uint)(param_1[0x7b] - iVar3 >> 2) <= (uint)(param_1[0x7a] - iVar3 >> 2))) {

          FUN_004c2bb0(param_1[0x7a],1,&local_1274);

        }

        else {

          puVar2 = (uint32_t /* width from decompiler */ *)param_1[0x7a];

          *puVar2 = puVar4;

          param_1[0x7a] = puVar2 + 1;

        }

      }

      else {

        *(uint8_t *)(iVar3 + 0x34) = local_123c;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c) = local_1254;

      }

      local_1278 = local_1278 + 1;

    } while (local_1278 < local_1048);

  }

  *param_1 = local_1224;

  param_1[0x73] = local_1058;

  param_1[0x74] = local_1054;

  param_1[0x76] = local_1050;

  pcVar5 = local_1220;

  param_1[0x77] = local_104c;

  param_1[0x75] = 0x1e;

  *(uint8_t *)(param_1 + 0x80) = 1;

  iVar3 = 4 - (int)pcVar5;

  do {

    cVar1 = *pcVar5;

    pcVar5[(int)param_1 + iVar3] = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  pcVar5 = local_11ed;

  iVar3 = 0x37 - (int)pcVar5;

  do {

    cVar1 = *pcVar5;

    pcVar5[(int)param_1 + iVar3] = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  pcVar5 = local_10f2;

  iVar3 = 0x132 - (int)pcVar5;

  do {

    cVar1 = *pcVar5;

    pcVar5[(int)param_1 + iVar3] = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  pcVar5 = local_10bf;

  iVar3 = 0x165 - (int)pcVar5;

  do {

    cVar1 = *pcVar5;

    pcVar5[(int)param_1 + iVar3] = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  pcVar5 = local_108c;

  iVar3 = 0x198 - (int)pcVar5;

  do {

    cVar1 = *pcVar5;

    pcVar5[(int)param_1 + iVar3] = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  local_4 = 0xffffffff;

  FUN_00787af0();

  ExceptionList = local_c;

  return;

}
