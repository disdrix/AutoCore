// =============================================================================
// FUN_00786ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00786ee0
// Address:   0x00786ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00786ee0 @ 0x00786ee0
// Stable ID: aa_00786ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, while×1, return×1.
//  - Notable callees: FUN_0042b2a0, FUN_00786ee0, free.
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

void FUN_00786ee0(void)



{

  int *piVar1;

  void *pvVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int local_c;

  

  local_c = 0;

  for (pvVar2 = g_pNetObjectDirtyListHead; pvVar2 != (void *)0x0;

      pvVar2 = *(void **)((int)pvVar2 + 0x10)) {

    FUN_0042b2a0();

    local_c = local_c + 1;

    piVar1 = (int *)(local_c * 4 + -4);

    if (piVar1 != (int *)0x0) {

      *piVar1 = (int)pvVar2;

    }

  }

  while (pvVar2 = g_pNetObjectDirtyListHead, pvVar2 != (void *)0x0) {

    uVar3 = *(uint *)((int)pvVar2 + 0x18);

    uVar4 = *(uint *)((int)pvVar2 + 0x1c);

    g_pNetObjectDirtyListHead = *(void **)((int)pvVar2 + 0x10);

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x1c) = 0;

    if (uVar3 != 0 || uVar4 != 0) {

      for (iVar5 = *(int *)((int)pvVar2 + 0x24); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x14)) {

        if (*(uint *)(iVar5 + 8) == 0 && *(uint *)(iVar5 + 0xc) == 0) {

          iVar6 = *(int *)(iVar5 + 0x1c);

          *(uint *)(iVar5 + 8) = uVar3;

          *(uint *)(iVar5 + 0xc) = uVar4;

          if (*(int *)(iVar5 + 0x34) != *(int *)(iVar6 + 0x20c)) {

            *(int *)(*(int *)(*(int *)(iVar6 + 0x208) + *(int *)(iVar6 + 0x20c) * 4) + 0x34) =

                 *(int *)(iVar5 + 0x34);

            *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + 0x208) + *(int *)(iVar5 + 0x34) * 4) =

                 *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + 0x208) + *(int *)(iVar6 + 0x20c) * 4);

            *(int *)(*(int *)(iVar6 + 0x208) + *(int *)(iVar6 + 0x20c) * 4) = iVar5;

            *(uint32_t /* width from decompiler */ *)(iVar5 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x20c);

          }

          *(int *)(iVar6 + 0x20c) = *(int *)(iVar6 + 0x20c) + 1;

        }

        else {

          *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | uVar3;

          *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | uVar4;

        }

      }

    }

  }

  g_pNetObjectDirtyListHead = (void *)0x0;

  free((void *)0x0);

  return;

}
