// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_004e54a0×3, FUN_004d5720, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSectorMap.cpp"; "Invalid transfer type in AddEntryPoint".
//  - Return sites: 4.

// =============================================================================
// Named_VOGSectorMap_004d5720
// -----------------------------------------------------------------------------
// Stable ID: aa_004d5720
// Address:   0x004d5720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGSectorMap"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOGSectorMap_004d5720(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char cVar5;

  int iVar6;

  

  cVar5 = *(char *)(param_2 + 0xb0);

  if (cVar5 == -1) {

    iVar6 = *(int *)(*(int *)(param_2 + 4) + 4);

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x88 + param_2);

    uVar3 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x8c + param_2);

    uVar4 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x90 + param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c0) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x84 + param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c4) = uVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c8) = uVar3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4cc) = uVar4;

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0x94 + param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d0) = *puVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d4) = puVar1[1];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d8) = puVar1[2];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4dc) = puVar1[3];

    FUN_004e54a0(&param_2);

    return;

  }

  if (cVar5 == '\0') {

    FUN_004e54a0(&param_2);

    return;

  }

  if (cVar5 == '\x05') {

    FUN_004e54a0(&param_2);

    return;

  }

  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSectorMap.cpp",0xd5e,3,

                 "Invalid transfer type in AddEntryPoint");

  return;

}
