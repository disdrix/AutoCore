// =============================================================================
// FUN_005d2520
// -----------------------------------------------------------------------------
// Stable ID: aa_005d2520
// Address:   0x005d2520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d2520 @ 0x005d2520
// Stable ID: aa_005d2520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_005d2520.
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

void __fastcall FUN_005d2520(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (*(void **)(param_1 + 0x5c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x5c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  puVar2 = operator_new(0x930);

  puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2[0x1b] = 0;

    puVar2[0x1a] = 0;

    puVar2[0x19] = 0;

    puVar2[0x1e] = 0;

    puVar2[0x1d] = 0;

    puVar2[0x1c] = 0;

    puVar2[0x1f] = g_flMsToSeconds_Inferred;

    puVar4 = puVar2;

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x5c) = puVar4;

  fVar1 = g_flOne;

  for (iVar3 = 0x24c; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  iVar3 = *(int *)(param_1 + 0x5c);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x34) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x38) = 0xffffffff;

  **(uint32_t /* width from decompiler */ **)(param_1 + 0x5c) = 0x2013;

  iVar3 = *(int *)(param_1 + 0x5c);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0xffffffff;

  *(float *)(*(int *)(param_1 + 0x5c) + 0x80) = fVar1;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x5c) + 0xd0) = 0xffffffff;

  iVar3 = *(int *)(param_1 + 0x5c);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x100) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x104) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xf8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xfc) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x118) = 0xffffffff;

  return;

}
