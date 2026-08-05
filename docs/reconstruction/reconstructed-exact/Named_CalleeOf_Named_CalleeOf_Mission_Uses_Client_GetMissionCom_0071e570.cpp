// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_0071e570
// -----------------------------------------------------------------------------
// Stable ID: aa_0071e570
// Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x0071e570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0071e570.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
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

void __fastcall

Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_0071e570(char *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  

  in_EAX[0x4e] = param_8;

  in_EAX[0x4a] = param_3;

  in_EAX[0x4b] = param_4;

  in_EAX[0x4c] = param_5;

  in_EAX[0x4d] = param_6;

  in_EAX[4] = *param_2;

  in_EAX[5] = param_2[1];

  in_EAX[6] = param_2[2];

  in_EAX[7] = param_2[3];

  *in_EAX = in_XMM0_Da;

  in_EAX[1] = param_7;

  in_EAX[0x4f] = 0;

  in_EAX[0x50] = 0;

  iVar2 = 0x20 - (int)param_1;

  do {

    cVar1 = *param_1;

    param_1[(int)in_EAX + iVar2] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  in_EAX[2] = param_9;

  *(uint8_t *)(in_EAX + 0x51) = 0;

  return;

}
