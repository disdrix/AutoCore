// =============================================================================
// FUN_0073c270
// -----------------------------------------------------------------------------
// Stable ID: aa_0073c270
// Address:   0x0073c270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073c270 @ 0x0073c270
// Stable ID: aa_0073c270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×11, return×3.
//  - Notable callees: FUN_0073c1d0, FUN_0073c270, FUN_0098dd70, FUN_0098fc40.
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

void FUN_0073c270(void)



{

  void *pvVar1;

  int *in_EAX;

  

  pvVar1 = (void *)in_EAX[10];

  if (pvVar1 != (void *)0x0) {

    FUN_0098dd70(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  in_EAX[10] = 0;

  pvVar1 = (void *)in_EAX[9];

  if (pvVar1 != (void *)0x0) {

    FUN_0098fc40(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  in_EAX[9] = 0;

  if ((uint32_t /* width from decompiler */ *)*in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)*in_EAX)(1);

  }

  *in_EAX = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[1] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[1])(1);

  }

  in_EAX[1] = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[2] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[2])(1);

  }

  in_EAX[2] = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[3] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[3])(1);

  }

  in_EAX[3] = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[4] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[4])(1);

  }

  in_EAX[4] = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[5] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[5])(1);

  }

  in_EAX[5] = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[6] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[6])(1);

  }

  in_EAX[6] = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[7] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[7])(1);

  }

  in_EAX[7] = 0;

  if ((uint32_t /* width from decompiler */ *)in_EAX[0xb] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)in_EAX[0xb])(1);

  }

  in_EAX[0xb] = 0;

  in_EAX[0xc] = 0;

  in_EAX[0x11] = 0;

  FUN_0073c1d0();

  return;

}
