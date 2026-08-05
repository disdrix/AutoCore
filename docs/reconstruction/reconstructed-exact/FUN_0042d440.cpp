// =============================================================================
// FUN_0042d440
// -----------------------------------------------------------------------------
// Stable ID: aa_0042d440
// Address:   0x0042d440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042d440 @ 0x0042d440
// Stable ID: aa_0042d440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0042c4e0, FUN_0042d440, FUN_0042d510, FUN_00784b70, TNL_Socket_Constructor, htonl.
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

void FUN_0042d440(int param_1)



{

  int in_EAX;

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint16_t local_14;

  uint16_t local_12;

  u_long local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_0042c4e0();

  if (*(short *)(in_EAX + 0xf8) != 0) {

    pvVar1 = operator_new(0x10);

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      local_14 = 1;

      local_12 = 0;

      local_4 = 0;

      local_8 = 0;

      local_c = 0;

      local_10 = htonl(0);

      uVar2 = TNL_Socket_Constructor(pvVar1,&local_14,1000000,1000000,1,1);

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10c) = uVar2;

    FUN_00784b70(uVar2);

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1a0) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1a4) = uVar2;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1b8) = 0xb;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1b8) = 1;

  FUN_0042d510();

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1a0) = 0;

  return;

}
