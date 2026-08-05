// =============================================================================
// FUN_00491140
// -----------------------------------------------------------------------------
// Stable ID: aa_00491140
// Address:   0x00491140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00491140 @ 0x00491140
// Stable ID: aa_00491140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0049c5f0×2, memmove×2, FUN_00491140.
//  - Return sites: 2.

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

void __thiscall FUN_00491140(int param_1,int *param_2)



{

  size_t sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  int iStack_4;

  

  iStack_4 = param_1;

  iVar2 = (**(code **)(*param_2 + 0x24))();

  if (iVar2 == 0) {

    pvVar4 = *(void **)(param_1 + 0x148);

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0049c5f0(&iStack_4,*(uint32_t /* width from decompiler */ *)(param_1 + 0x144),pvVar4,&param_2);

    if ((void *)*puVar3 != pvVar4) {

      sVar1 = (*(int *)(param_1 + 0x148) - (int)pvVar4 >> 2) * 4;

      pvVar4 = memmove((void *)*puVar3,pvVar4,sVar1);

      *(void **)(param_1 + 0x148) = (void *)((int)pvVar4 + sVar1);

    }

  }

  else {

    pvVar4 = *(void **)(param_1 + 0x158);

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0049c5f0(&iStack_4,*(uint32_t /* width from decompiler */ *)(param_1 + 0x154),pvVar4,&param_2);

    if ((void *)*puVar3 != pvVar4) {

      sVar1 = (*(int *)(param_1 + 0x158) - (int)pvVar4 >> 2) * 4;

      pvVar4 = memmove((void *)*puVar3,pvVar4,sVar1);

      *(void **)(param_1 + 0x158) = (void *)((int)pvVar4 + sVar1);

      return;

    }

  }

  return;

}
