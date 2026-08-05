// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, do×1, while×1.
//  - Notable callees: FUN_0067c430, FUN_0067de40, FUN_0067dea0, FUN_0067f930, FUN_0076cec0, memmove, send, vog_LogMessage.
//  - Return sites: 5.

// =============================================================================
// Named_netSession_0067dea0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067dea0
// Address:   0x0067dea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netSession"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_netSession_0067dea0(int param_1,int *param_2,uint *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int local_4;

  

  piVar4 = param_2;

  *param_3 = 0;

  local_4 = 0;

  if (*(int *)(param_1 + 0x2a24) != 0) {

    do {

      if ((*(int *)(param_1 + 0x2968) == 0) ||

         (param_2 = (int *)(*(int *)(param_1 + 0x296c) - *(int *)(param_1 + 0x2968) >> 2),

         param_2 == (int *)0x0)) {

        FUN_0067de40();

      }

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2968);

      if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

        return local_4;

      }

      if (*(int *)(param_1 + 0x296c) - (int)puVar1 >> 2 == 0) {

        return local_4;

      }

      piVar2 = (int *)*puVar1;

      iVar6 = (-(uint)(local_4 != 0) & 0xfffffffc) + 0x10;

      if (*piVar2 != 0) {

        iVar6 = iVar6 + *(int *)(*piVar2 + 0xc);

      }

      param_2 = piVar2;

      if (*(uint *)(param_1 + 0x2a28) < *param_3 + iVar6) {

        if (local_4 != 0) {

          return local_4;

        }

        uVar5 = FUN_0076cec0(&param_3,

                             "Session %lu: Packet on front of send queue is too large to send (%lu / %lu data, max %lu)"

                             ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),iVar6,*(uint32_t /* width from decompiler */ *)(*piVar2 + 0xc)

                             ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a28));

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x83f,3,uVar5);

        FUN_0067c430();

        return 0;

      }

      memmove(puVar1,puVar1 + 1,(*(int *)(param_1 + 0x296c) - (int)(puVar1 + 1) >> 2) * 4);

      *(int *)(param_1 + 0x296c) = *(int *)(param_1 + 0x296c) + -4;

      iVar3 = piVar4[1];

      if ((iVar3 == 0) || ((uint)(piVar4[3] - iVar3 >> 2) <= (uint)(piVar4[2] - iVar3 >> 2))) {

        FUN_0067f930(piVar4[2],1,&param_2);

      }

      else {

        puVar1 = (uint32_t /* width from decompiler */ *)piVar4[2];

        *puVar1 = piVar2;

        piVar4[2] = (int)(puVar1 + 1);

      }

      if (local_4 == 1) {

        *param_3 = *param_3 + 0xc;

      }

      *param_3 = *param_3 + iVar6;

      local_4 = local_4 + 1;

    } while (*param_3 < *(uint *)(param_1 + 0x2a24));

  }

  return local_4;

}
