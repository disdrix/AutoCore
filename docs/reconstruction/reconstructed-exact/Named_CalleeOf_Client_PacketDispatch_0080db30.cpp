// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080db30
// -----------------------------------------------------------------------------
// Stable ID: aa_0080db30
// Callee of Client_PacketDispatch
// Address:   0x0080db30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "Failed to craft from memory.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Failed to craft from memory."
//   - "Item Created!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_007a6de0×2, CONCAT44, Client_RefreshOpenMissionUiWindows, FUN_0040c5c0, FUN_00524190, FUN_007a69d0, FUN_007fdfb0, FUN_0080db30.
//  - Strings: "Failed to craft from memory."; "Item Created!".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_0080db30(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char *_Source;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  size_t _Count;

  uint32_t /* width from decompiler */ uVar5;

  char local_98 [128];

  uint32_t /* width from decompiler */ local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_007a69d0();

  if (*(char *)(unaff_ESI + 0x10) == '\0') {

    uVar5 = 0;

    uVar4 = 1;

    uVar3 = 0xffffffff;

    uVar1 = FUN_007a6de0("Failed to craft from memory.",0xffffffff);

    FUN_007fdfb0(param_1,uVar1,uVar3,uVar4,uVar5);

    return;

  }

  if (DAT_00d1b6d8 != (void *)0x0) {

    CVOGCharacter_AddCredits

              (DAT_00d1b6d8,

               CONCAT44(-(*(int *)(unaff_ESI + 0x1c) + (uint)(*(int *)(unaff_ESI + 0x18) != 0)),

                        -*(int *)(unaff_ESI + 0x18)));

  }

  _Count = 0x80;

  local_18 = 0xffffffff;

  local_98[0] = '\0';

  _Source = (char *)FUN_007a6de0("Item Created!",0xffffffff);

  strncpy(local_98,_Source,_Count);

  local_18 = 0xffeee3d8;

  local_14 = g_flLevelUpUiBase_Inferred;

  local_c = 0;

  local_10 = DAT_00aaa68c;

  local_8 = 0xffffffff;

  local_4 = 0xffffffff;

  FUN_0040c5c0(local_98);

  if (DAT_00d1b6d8 != (void *)0x0) {

    iVar2 = CVOGReaction_ResolveObjectTarget

                      (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc));

    if (iVar2 != 0) {

      *(ushort *)(iVar2 + 0x180) = (ushort)*(byte *)(unaff_ESI + 0x20);

    }

    if ((*(char *)(unaff_ESI + 0x20) == '\0') && (DAT_00d1b6d8 != (void *)0x0)) {

      FUN_00524190(*(uint8_t *)(unaff_ESI + 4),0);

    }

  }

  Client_RefreshOpenMissionUiWindows(param_1);

  return;

}
