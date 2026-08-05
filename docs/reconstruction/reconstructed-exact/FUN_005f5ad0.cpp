// =============================================================================
// FUN_005f5ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f5ad0
// Address:   0x005f5ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f5ad0 @ 0x005f5ad0
// Stable ID: aa_005f5ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~164 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, for×3, do×1, while×1.
//  - Notable callees: FUN_00506ee0, FUN_005f5ad0.
//  - Return sites: 5.

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

void __thiscall FUN_005f5ad0(int param_1,char param_2,char param_3)



{

  float fVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  

  if (param_2 == '\0') {

    if (*(void **)(param_1 + 0x5c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0x5c));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

    pvVar2 = operator_new(0xd78);

    if (pvVar2 == (void *)0x0) {

      puVar3 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00506ee0();

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x5c) = puVar3;

    for (iVar4 = 0x35e; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    iVar4 = *(int *)(param_1 + 0x5c);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x28) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x30) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x34) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x38) = 0xffffffff;

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x5c) = 0x201d;

    iVar4 = *(int *)(param_1 + 0x5c);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5d8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5dc) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5e0) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5e4) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5e8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x180) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x184) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x188) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x18c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 400) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x330) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x334) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x338) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x33c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x340) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 600) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x25c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x260) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x264) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x268) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x730) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x734) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x738) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x73c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x740) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x708) = 0x201c;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x70c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x480) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x484) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x488) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x48c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x490) = 0xffffffff;

    puVar3 = (uint32_t /* width from decompiler */ *)(iVar4 + 0x890);

    iVar5 = 3;

    do {

      puVar3[10] = 0xffffffff;

      puVar3[0xb] = 0xffffffff;

      puVar3[0xc] = 0xffffffff;

      puVar3[0xd] = 0xffffffff;

      puVar3[0xe] = 0xffffffff;

      *puVar3 = 0x201c;

      puVar3[1] = 0xffffffff;

      fVar1 = g_flOne;

      puVar3 = puVar3 + 0x62;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    *(uint8_t *)(iVar4 + 0xa2) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x30c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x15c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x158) = 0x2012;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x234) = 0xffffffff;

    *(float *)(iVar4 + 0x4d8) = fVar1;

    *(uint8_t *)(iVar4 + 0x4f8) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x458) = 0x201b;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5b0) = 0x2060;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5b4) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0xffffffff;

    *(float *)(iVar4 + 0x80) = fVar1;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xd0) = 0xffffffff;

    return;

  }

  if (*(void **)(param_1 + 0x60) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x60));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  if (param_3 != '\0') {

    puVar3 = operator_new(0x930);

    if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar3 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar3[0x1b] = 0;

      puVar3[0x1a] = 0;

      puVar3[0x19] = 0;

      puVar3[0x1e] = 0;

      puVar3[0x1d] = 0;

      puVar3[0x1c] = 0;

      puVar3[0x1f] = g_flMsToSeconds_Inferred;

    }

    fVar1 = g_flOne;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x60) = puVar3;

    for (iVar4 = 0x24c; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x60) = 0x2013;

    iVar4 = *(int *)(param_1 + 0x60);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0xffffffff;

    *(float *)(*(int *)(param_1 + 0x60) + 0x80) = fVar1;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x60) + 0xd0) = 0xffffffff;

    iVar4 = *(int *)(param_1 + 0x60);

    *(uint8_t *)(iVar4 + 0x10c) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x100) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x104) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x118) = 0xffffffff;

    return;

  }

  puVar3 = operator_new(0x1a8);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar3[0x1b] = 0;

    puVar3[0x1a] = 0;

    puVar3[0x19] = 0;

    puVar3[0x1e] = 0;

    puVar3[0x1d] = 0;

    puVar3[0x1c] = 0;

    puVar3[0x1f] = g_flMsToSeconds_Inferred;

  }

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x60) = puVar3;

  for (iVar4 = 0x6a; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  **(uint32_t /* width from decompiler */ **)(param_1 + 0x60) = 0x2015;

  iVar4 = *(int *)(param_1 + 0x60);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0xffffffff;

  *(float *)(*(int *)(param_1 + 0x60) + 0x80) = fVar1;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x60) + 0xd0) = 0xffffffff;

  iVar4 = *(int *)(param_1 + 0x60);

  *(byte *)(iVar4 + 0x129) = *(byte *)(iVar4 + 0x129) | 1;

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0xe0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0xe4) = 0xffffffff;

  return;

}
