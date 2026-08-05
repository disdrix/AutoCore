// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080fd30
// -----------------------------------------------------------------------------
// Stable ID: aa_0080fd30
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080fd30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper. Evidence string: "[System]". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "[System]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, for×1, return×1.
//  - Notable callees: Client_MaybeShowFirstTimeTip, FUN_007a69d0, FUN_007a6de0, FUN_007a75e0, FUN_0080fd30, FUN_008f8200, __RTDynamicCast, strncpy.
//  - Strings: "[System]".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080fd30(void)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  char *pcVar6;

  int unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint16_t *puVar9;

  char local_404 [20];

  uint16_t local_3f0;

  uint32_t /* width from decompiler */ local_3ee [250];

  

  if (*(int *)(unaff_EBX + 0x109c) != 0) {

    FUN_007a69d0();

    local_404[0] = '\0';

    local_404[1] = '\0';

    local_404[2] = '\0';

    local_404[3] = '\0';

    local_404[4] = '\0';

    local_404[5] = '\0';

    local_404[6] = '\0';

    local_404[7] = '\0';

    local_404[8] = '\0';

    local_404[9] = '\0';

    local_404[10] = '\0';

    local_404[0xb] = '\0';

    local_404[0xc] = '\0';

    local_404[0xd] = '\0';

    local_404[0xe] = '\0';

    local_404[0xf] = '\0';

    local_404[0x10] = 0;

    if ((char *)(unaff_ESI + 0x1a) == (char *)0x0) {

      pcVar2 = (char *)FUN_007a6de0("[System]",0xffffffff);

      pcVar6 = local_404;

      do {

        cVar1 = *pcVar2;

        *pcVar6 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

    }

    else {

      strncpy(local_404,(char *)(unaff_ESI + 0x1a),0x10);

      if (*(int *)(unaff_ESI + 4) == 2) {

        Client_MaybeShowFirstTimeTip(0x22);

      }

    }

    local_3f0 = 0;

    puVar7 = local_3ee;

    for (iVar5 = 0xf9; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

    *(uint16_t *)puVar7 = 0;

    puVar9 = &local_3f0;

    FUN_007a75e0();

    uVar3 = (uint)*(byte *)(unaff_ESI + 8);

    pcVar6 = local_404;

    uVar8 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

    uVar4 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                            &CDlgChatLog::RTTI_Type_Descriptor,0,uVar8,pcVar6,puVar9,uVar3);

    FUN_008f8200(uVar4,uVar8,pcVar6,puVar9,uVar3);

  }

  return;

}
