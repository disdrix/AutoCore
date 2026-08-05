// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_005070b0×2, CVOGReaction_TeleportTarget, FUN_005070d0, context, this.
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_TeleportTarget
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d790
// Address:   0x0053d790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Teleport a target to a new position.

   

   Parameters:

   this - Reaction context (offsets: +0x2=target, +0x1=source)

   pTeleportData - Teleport data array [4] (position xyz + orientation)

   

   Algorithm:

   1. Call vtable +0x40 on this (pre-teleport callback)

   2. If this+0x2 == 0 (no target):

      - Copy pTeleportData to this+0x1+0x84 (4 dwords)

   3. Else if this+0x2 != 0:

      - Check via FUN_005070b0 (validation)

      - If validation passes and +0x44 != 0: call FUN_005070d0

      - If flag +0x40 clear or +0x8 == 0:

        - Call vtable +0x40 on +0x3c with teleport data */



void __thiscall CVOGReaction_TeleportTarget(void *this,uint32_t /* width from decompiler */ *pTeleportData)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = this;

  (**(code **)(*(int *)this + 0x40))();

  iVar2 = *(int *)((int)this + 8);

  if (iVar2 == 0) {

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x84 + (int)this);

    *puVar1 = *pTeleportData;

    puVar1[1] = pTeleportData[1];

    puVar1[2] = pTeleportData[2];

    puVar1[3] = pTeleportData[3];

  }

  else {

    pcVar3 = (char *)FUN_005070b0((int)&uStack_4 + 3);

    if ((*pcVar3 == '\0') && (*(int *)(iVar2 + 0x44) != 0)) {

      FUN_005070d0();

    }

    if ((*(char *)(iVar2 + 0x40) == '\0') || (*(int *)(iVar2 + 8) == 0)) {

      (**(code **)(**(int **)(iVar2 + 0x3c) + 0x40))(pTeleportData);

      return;

    }

  }

  return;

}
