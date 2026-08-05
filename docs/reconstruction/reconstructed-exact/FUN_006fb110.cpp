// =============================================================================
// FUN_006fb110
// -----------------------------------------------------------------------------
// Stable ID: aa_006fb110
// Address:   0x006fb110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fb110 @ 0x006fb110
// Stable ID: aa_006fb110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_006f7eb0, FUN_006fb110.
//  - Return sites: 3.

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

int __thiscall FUN_006fb110(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  

  puVar3 = param_4;

  iVar2 = *(int *)(param_1 + 0x54);

  if (8 < iVar2) {

    return -1;

  }

  pcVar4 = (char *)FUN_006f7eb0(&param_4,param_4);

  if ((*pcVar4 == '\0') && (iVar2 < 8)) {

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x20 + iVar2 * 6);

    *puVar1 = *puVar3;

    *(uint16_t *)(puVar1 + 1) = *(uint16_t *)(puVar3 + 1);

    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;

    return iVar2;

  }

  return -1;

}
