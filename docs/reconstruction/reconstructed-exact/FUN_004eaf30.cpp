// =============================================================================
// FUN_004eaf30
// -----------------------------------------------------------------------------
// Stable ID: aa_004eaf30
// Address:   0x004eaf30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004eaf30 @ 0x004eaf30
// Stable ID: aa_004eaf30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004b55e0, FUN_004eaf30.
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

void __fastcall FUN_004eaf30(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  float fVar3;

  

  pvVar1 = (void *)*param_1;

  if (pvVar1 != (void *)0x0) {

    FUN_004b55e0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *param_1 = 0;

  if ((void *)param_1[1] != (void *)0x0) {

    operator_delete__((void *)param_1[1]);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[2];

  param_1[1] = 0;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

    param_1[2] = 0;

  }

  fVar3 = g_flOne;

  param_1[5] = 0;

  param_1[3] = 0;

  param_1[0xb] = 0;

  param_1[10] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[0xf] = 0;

  param_1[0xe] = 0;

  param_1[0xd] = 0;

  param_1[0xc] = 0;

  param_1[0x13] = 0;

  param_1[0x12] = 0;

  param_1[0x11] = 0;

  param_1[0x10] = 0;

  param_1[8] = fVar3;

  param_1[0xd] = fVar3;

  param_1[0x12] = fVar3;

  param_1[0x17] = 0;

  param_1[0x16] = 0;

  param_1[0x15] = 0;

  param_1[0x14] = 0;

  if ((void *)param_1[0x18] != (void *)0x0) {

    operator_delete__((void *)param_1[0x18]);

  }

  param_1[0x18] = 0;

  return;

}
