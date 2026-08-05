// =============================================================================
// FUN_00930040
// -----------------------------------------------------------------------------
// Stable ID: aa_00930040
// Address:   0x00930040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00930040 @ 0x00930040
// Stable ID: aa_00930040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: Character_MaybeRefreshCombatState_Inferred, FUN_004e8dc0, FUN_005360f0, FUN_00930040.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00930040(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int in_EAX;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if ((*(int *)(in_EAX + 0xe98) != 0) &&

     (iVar4 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x250), iVar4 != 0)) {

    *(uint8_t *)(iVar4 + 0x106) = *(uint8_t *)(in_EAX + 0x9c4);

  }

  _DAT_00d1f070 = *(float *)(DAT_00d09874 + 0x30) + _DAT_00d1f070;

  if (DAT_00a0f694 < _DAT_00d1f070) {

    if (*(int *)(in_EAX + 0xe98) != 0) {

      Character_MaybeRefreshCombatState_Inferred(0);

    }

    _DAT_00d1f070 = 0.0;

  }

  if (*(int *)(in_EAX + 0xe98) != 0) {

    FUN_005360f0(*(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x30));

    if (*(char *)(*(int *)(in_EAX + 0xe98) + 0x4f1) != '\0') {

      iVar4 = *(int *)(in_EAX + 0xde8);

      local_28 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x224);

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x22c);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x230);

      local_2c = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x220);

      local_30 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x21c);

      local_24 = 0;

      puVar1 = (uint32_t /* width from decompiler */ *)

               (*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0x84 +

               *(int *)(in_EAX + 0xe98));

      *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x228);

      puVar1[1] = uVar2;

      puVar1[2] = uVar3;

      puVar1[3] = 0;

      FUN_004e8dc0(&local_30,&local_20);

      puVar1 = (uint32_t /* width from decompiler */ *)

               (*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0x94 +

               *(int *)(in_EAX + 0xe98));

      *puVar1 = local_20;

      puVar1[1] = local_1c;

      puVar1[2] = local_18;

      puVar1[3] = local_14;

    }

  }

  return;

}
