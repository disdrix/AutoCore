// =============================================================================
// FUN_005569a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005569a0
// Address:   0x005569a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005569a0 @ 0x005569a0
// Stable ID: aa_005569a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005557a0, FUN_005558d0, FUN_00555bf0, FUN_00556880, FUN_005569a0, FUN_00558eb0, _time64.
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

uint32_t /* width from decompiler */ __thiscall FUN_005569a0(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint8_t *puVar5;

  __time64_t _Var6;

  uint local_8;

  int local_4;

  

  iVar2 = param_2;

  FUN_005557a0(*(uint8_t *)(param_2 + 4));

  FUN_00556880(*(uint8_t *)(iVar2 + 5),*(uint32_t /* width from decompiler */ *)(iVar2 + 8));

  _Var6 = _time64((__time64_t *)&local_8);

  uVar3 = (uint32_t /* width from decompiler */)_Var6;

  uVar1 = *(uint *)(iVar2 + 0x10);

  iVar4 = *(int *)(iVar2 + 0x14);

  *(uint *)(param_1 + 0x160) = local_8 - *(uint *)(iVar2 + 0x10);

  *(uint *)(param_1 + 0x164) = (local_4 - iVar4) - (uint)(local_8 < uVar1);

  iVar4 = 0;

  if (*(char *)(iVar2 + 0x18) != '\0') {

    puVar5 = (uint8_t *)(iVar2 + 0x1e);

    do {

      uVar3 = FUN_00558eb0(&param_2,puVar5);

      if (param_2 != *(int *)(param_1 + 0x174)) {

        FUN_005558d0(puVar5[-2],*puVar5);

        uVar3 = FUN_00555bf0(puVar5[-1],*(uint32_t /* width from decompiler */ *)(puVar5 + 2),*puVar5);

      }

      iVar4 = iVar4 + 1;

      puVar5 = puVar5 + 8;

    } while (iVar4 < (int)(uint)*(byte *)(iVar2 + 0x18));

  }

  return uVar3;

}
