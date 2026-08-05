// =============================================================================
// FUN_00783f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00783f40
// Address:   0x00783f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783f40 @ 0x00783f40
// Stable ID: aa_00783f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: setsockopt×2, FUN_00783f40.
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

void FUN_00783f40(uint param_1,uint param_2)



{

  SOCKET in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  SOCKET *unaff_EDI;

  

  *unaff_EDI = in_EAX;

  unaff_EDI[1] = 1;

  setsockopt(in_EAX,0xffff,0x1002,(char *)&param_2,4);

  setsockopt(*unaff_EDI,0xffff,0x1001,(char *)&param_1,4);

  puVar1 = operator_new(0x18);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = 0;

    puVar1[1] = 0;

    *(uint16_t *)(puVar1 + 2) = 0;

    puVar1[3] = param_1;

    *(uint8_t *)(puVar1 + 4) = 0;

    pvVar2 = operator_new__(param_1);

    puVar1[5] = pvVar2;

  }

  unaff_EDI[2] = (SOCKET)puVar1;

  puVar1 = operator_new(0x18);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = 0;

    puVar1[1] = 0;

    *(uint16_t *)(puVar1 + 2) = 0;

    puVar1[3] = param_2;

    *(uint8_t *)(puVar1 + 4) = 0;

    pvVar2 = operator_new__(param_2);

    puVar1[5] = pvVar2;

    unaff_EDI[3] = (SOCKET)puVar1;

    return;

  }

  unaff_EDI[3] = 0;

  return;

}
