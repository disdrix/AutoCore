// =============================================================================
// FUN_00667420
// -----------------------------------------------------------------------------
// Stable ID: aa_00667420
// Address:   0x00667420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00667420 @ 0x00667420
// Stable ID: aa_00667420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: FUN_00667420.
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

void __thiscall FUN_00667420(int param_1,int param_2)



{

  short *psVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (*(char *)(param_2 + 0x9c) == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa0);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xac);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb0);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xbc);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc0);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = *(uint32_t /* width from decompiler */ *)(param_2 + 200);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xcc);

  }

  else {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c);

    *(float *)(param_1 + 0x110) =

         *(float *)(param_1 + 0x74) * *(float *)(param_1 + 0x68) -

         *(float *)(param_1 + 0x78) * *(float *)(param_1 + 100);

    *(float *)(param_1 + 0x114) =

         *(float *)(param_1 + 0x60) * *(float *)(param_1 + 0x78) -

         *(float *)(param_1 + 0x70) * *(float *)(param_1 + 0x68);

    *(float *)(param_1 + 0x118) =

         *(float *)(param_1 + 0x70) * *(float *)(param_1 + 100) -

         *(float *)(param_1 + 0x60) * *(float *)(param_1 + 0x74);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = 0;

  }

  if (*(int *)(param_2 + 0x90) != 0) {

    psVar1 = (short *)(*(int *)(param_2 + 0x90) + 6);

    *psVar1 = *psVar1 + 1;

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe0);

  if ((puVar2 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1,

     *(short *)((int)puVar2 + 6) == 0)) {

    (**(code **)*puVar2)(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x90);

  if (*(int *)(param_2 + 0x94) != 0) {

    psVar1 = (short *)(*(int *)(param_2 + 0x94) + 6);

    *psVar1 = *psVar1 + 1;

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe4);

  if ((puVar2 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1,

     *(short *)((int)puVar2 + 6) == 0)) {

    (**(code **)*puVar2)(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x94);

  if (*(int *)(param_2 + 0x98) != 0) {

    psVar1 = (short *)(*(int *)(param_2 + 0x98) + 6);

    *psVar1 = *psVar1 + 1;

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe8);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x98);

      return;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x98);

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x98);

  return;

}
