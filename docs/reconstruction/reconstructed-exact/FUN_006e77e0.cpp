// =============================================================================
// FUN_006e77e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e77e0
// Address:   0x006e77e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e77e0 @ 0x006e77e0
// Stable ID: aa_006e77e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_006e77e0.
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

void __thiscall

FUN_006e77e0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  iVar1 = *(int *)(param_1 + 0x10);

  iVar2 = *param_2;

  local_4 = param_2;

  local_8 = param_2[2];

  iVar3 = 0;

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

  if (0 < iVar1) {

    do {

      local_10 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0xc) + iVar3 * 8);

      local_c = iVar3;

      (**(code **)(*(int *)*puVar4 + 8))(&local_10,param_3,param_4,param_5);

      puVar4 = puVar4 + 1;

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar1);

  }

  return;

}
