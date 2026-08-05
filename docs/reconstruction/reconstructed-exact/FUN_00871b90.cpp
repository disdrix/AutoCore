// =============================================================================
// FUN_00871b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00871b90
// Address:   0x00871b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00871b90 @ 0x00871b90
// Stable ID: aa_00871b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_00870290, FUN_00870320, FUN_008703b0, FUN_008717d0, FUN_00871b90.
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

void FUN_00871b90(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  FUN_008703b0();

  FUN_00870320();

  FUN_00870290();

  iVar1 = 0;

  *(uint16_t *)(in_EAX + 0x510) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x51c);

  do {

    puVar2[-1] = 0xffffffff;

    if ((void *)*puVar2 != (void *)0x0) {

      operator_delete__((void *)*puVar2);

    }

    *puVar2 = 0;

    puVar2[1] = 0;

    iVar1 = iVar1 + 1;

    puVar2 = puVar2 + 3;

  } while (iVar1 < 4);

  FUN_008717d0();

  *(uint16_t *)(in_EAX + 0x510) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x50c) = 0xffffffff;

  *(uint8_t *)(in_EAX + 0x548) = 1;

  return;

}
