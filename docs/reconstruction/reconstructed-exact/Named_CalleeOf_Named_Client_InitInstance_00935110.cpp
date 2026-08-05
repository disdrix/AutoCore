// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00935110
// -----------------------------------------------------------------------------
// Stable ID: aa_00935110
// Callee of Named_Client_InitInstance
// Address:   0x00935110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: Client_GetMissionCompleteAudioTable×13, FUN_00720d40×4, CONCAT31×2, FUN_007242c0×2, FUN_00721250, FUN_00724180, FUN_007244a0, FUN_00724790.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

/* WARNING: Removing unreachable block (ram,0x00935250) */



uint32_t /* width from decompiler */ Named_CalleeOf_Named_Client_InitInstance_00935110(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar5;

  

  if ((*(char *)(unaff_ESI + 0x9e6) == '\0') && (*(char *)(unaff_ESI + 0x9e7) == '\0')) {

    return 0;

  }

  piVar2 = (int *)Client_GetMissionCompleteAudioTable();

  if (*piVar2 != 0) {

    Client_GetMissionCompleteAudioTable();

    FUN_00724790();

  }

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3188);

  iVar3 = Client_GetMissionCompleteAudioTable();

  if (((*(char *)(iVar3 + 600) != '\0') || (iVar3 = FUN_00720d40(), *(char *)(iVar3 + 0x10) != '\0')

      ) && (iVar3 = FUN_00724180(uVar5,2), iVar3 < 0)) {

    uVar5 = 0;

    *(uint8_t *)(unaff_ESI + 0x9e6) = 0;

    Client_GetMissionCompleteAudioTable(0);

    FUN_007242c0(uVar5);

  }

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9f4);

  iVar3 = Client_GetMissionCompleteAudioTable();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c8) = uVar5;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9f8);

  iVar3 = Client_GetMissionCompleteAudioTable();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2cc) = uVar5;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9fc);

  iVar3 = Client_GetMissionCompleteAudioTable();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2d0) = uVar5;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa00);

  iVar3 = Client_GetMissionCompleteAudioTable();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2d4) = uVar5;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa04);

  iVar3 = Client_GetMissionCompleteAudioTable();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2d8) = uVar5;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa08);

  iVar3 = Client_GetMissionCompleteAudioTable();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2dc) = uVar5;

  puVar1 = (uint32_t /* width from decompiler */ *)cpuid_Version_info(1);

  if ((byte)((uint)puVar1[1] >> 0x10) < 2) {

    uVar5 = CONCAT31((int3)((uint)puVar1[3] >> 8),*(uint8_t *)(unaff_ESI + 0x9e6));

    Client_GetMissionCompleteAudioTable(uVar5);

    FUN_007242c0(uVar5);

  }

  else {

    uVar5 = CONCAT31((int3)((uint)*puVar1 >> 8),*(uint8_t *)(unaff_ESI + 0x9e6));

    Client_GetMissionCompleteAudioTable(uVar5);

    FUN_007244a0(uVar5);

  }

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9ec);

  iVar3 = FUN_00720d40();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20) = uVar5;

  uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9f0);

  iVar3 = FUN_00720d40();

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24) = uVar5;

  piVar2 = (int *)Client_GetMissionCompleteAudioTable();

  if (*piVar2 != 0) {

    uVar4 = (uint)*(byte *)(unaff_ESI + 0x9e7);

    FUN_00720d40(uVar4);

    FUN_00721250(uVar4);

  }

  return 0;

}
