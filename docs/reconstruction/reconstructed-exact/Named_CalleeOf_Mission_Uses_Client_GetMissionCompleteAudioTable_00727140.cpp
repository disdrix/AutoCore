// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00727140
// -----------------------------------------------------------------------------
// Stable ID: aa_00727140
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00727140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, do×1, while×1, switch×1, return×1.
//  - Notable callees: EnterCriticalSection, FUN_00724870, FUN_00726070, FUN_00727140, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
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

void __thiscall

Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00727140(int param_1,char *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint8_t param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ param_9)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *local_12c;

  LPCRITICAL_SECTION local_128;

  uint32_t /* width from decompiler */ local_124;

  uint16_t local_120;

  uint32_t /* width from decompiler */ local_11e [66];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b1dcd;

  local_14 = ExceptionList;

  local_128 = (LPCRITICAL_SECTION)(param_1 + 0x3f8);

  ExceptionList = &local_14;

  EnterCriticalSection(local_128);

  local_c = 0;

  local_120 = 0;

  puVar3 = local_11e;

  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *(uint16_t *)puVar3 = 0;

  local_12c = (uint32_t /* width from decompiler */ *)0x0;

  local_124 = 0;

  cVar1 = FUN_00724870(param_1,&local_120,&local_124);

  if ((cVar1 != '\0') &&

     (iVar2 = FUN_00726070(&local_12c,(uint)(*(char *)(param_1 + 0x25a) != '\0') * 4 + 0xa4,

                           DAT_00aa9110,DAT_00aa9114,DAT_00aa9118,DAT_00aa911c,0,param_5,0,

                           0xffffffff,0,local_124), iVar2 == 0)) {

    *(uint8_t *)((int)local_12c + 0x36) = param_7;

    local_12c[0x6e] = param_8;

    iVar2 = 0x48 - (int)param_2;

    do {

      cVar1 = *param_2;

      param_2[(int)local_12c + iVar2] = cVar1;

      param_2 = param_2 + 1;

    } while (cVar1 != '\0');

    local_12c[100] = param_6;

    local_12c[0xb] = param_5;

    local_12c[0x6f] = param_9;

    local_12c[0x10] = param_3;

    local_12c[0x11] = param_4;

    switch(param_5) {

    case 0x14:

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x2ac) = local_12c;

      break;

    case 0x15:

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x2b0) = local_12c;

      break;

    case 0x16:

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x2b4) = local_12c;

      break;

    case 0x17:

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x2b8) = local_12c;

      break;

    case 0x18:

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x2a8) = local_12c;

      break;

    default:

      (**(code **)*local_12c)(1);

    }

  }

  LeaveCriticalSection(local_128);

  ExceptionList = local_14;

  return;

}
