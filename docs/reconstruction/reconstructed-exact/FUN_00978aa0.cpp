// =============================================================================
// FUN_00978aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00978aa0
// Address:   0x00978aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00978aa0 @ 0x00978aa0
// Stable ID: aa_00978aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_TeleportTarget, FUN_0053d970, FUN_00560e90, FUN_00978aa0.
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

void FUN_00978aa0(void)



{

  int in_EAX;

  int iVar1;

  void *this;

  uint32_t /* width from decompiler */ *pTeleportData;

  uint32_t /* width from decompiler */ uVar2;

  

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x38) + 4) + 4) + 4 +

                               *(int *)(in_EAX + 0x38)) + 0x19c))();

  if (*(int *)(iVar1 + 8) != 0) {

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x38) + 4) + 4) + 4 +

                                 *(int *)(in_EAX + 0x38)) + 0x19c))();

    *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) + 0x28) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x40);

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x38) + 4) + 4) + 4 +

                         *(int *)(in_EAX + 0x38)) + 0x19c))();

    uVar2 = 1;

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x38) + 4) + 4) + 4 +

                                 *(int *)(in_EAX + 0x38)) + 0x19c))(1);

    FUN_00560e90(*(uint32_t /* width from decompiler */ *)(iVar1 + 8),uVar2);

    uVar2 = 0;

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x38) + 4) + 4) + 4 +

                         *(int *)(in_EAX + 0x38)) + 0x19c))(0);

    FUN_0053d970(uVar2);

    pTeleportData = (uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

    this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x38) + 4) + 4) + 4 +

                                        *(int *)(in_EAX + 0x38)) + 0x19c))();

    CVOGReaction_TeleportTarget(this,pTeleportData);

  }

  return;

}
