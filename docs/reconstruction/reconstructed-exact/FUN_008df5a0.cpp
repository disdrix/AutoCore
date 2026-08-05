// =============================================================================
// FUN_008df5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008df5a0
// Address:   0x008df5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008df5a0 @ 0x008df5a0
// Stable ID: aa_008df5a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×8, return×8.
//  - Notable callees: FUN_008df5a0.
//  - Return sites: 8.

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

void __fastcall FUN_008df5a0(uint32_t /* width from decompiler */ param_1,char param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  

  if (DAT_00d1b6d8 != 0) {

    cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                       DAT_00d1b6d8) + 0x3c) + 0x532);

    if (cVar1 == '\0') {

      if (param_2 != '\0') {

        *(uint8_t *)((int)in_EAX + 2) = 0x1d;

        *(uint8_t *)((int)in_EAX + 1) = 0x50;

        *(uint8_t *)in_EAX = 0xff;

        *(uint8_t *)((int)in_EAX + 3) = 0xff;

        return;

      }

      *(uint8_t *)((int)in_EAX + 2) = 10;

      *(uint8_t *)((int)in_EAX + 1) = 0x1e;

      *(uint8_t *)in_EAX = 0x62;

      *(uint8_t *)((int)in_EAX + 3) = 0xff;

      return;

    }

    if (cVar1 == '\x01') {

      if (param_2 != '\0') {

        *(uint8_t *)((int)in_EAX + 2) = 0x6b;

        *(uint8_t *)((int)in_EAX + 1) = 0xff;

        *(uint8_t *)in_EAX = 0x40;

        *(uint8_t *)((int)in_EAX + 3) = 0xff;

        return;

      }

      *(uint8_t *)((int)in_EAX + 2) = 0x2b;

      *(uint8_t *)((int)in_EAX + 1) = 100;

      *(uint8_t *)in_EAX = 0x1a;

      *(uint8_t *)((int)in_EAX + 3) = 0xff;

      return;

    }

    if (cVar1 == '\x02') {

      *(uint8_t *)((int)in_EAX + 3) = 0xff;

      if (param_2 != '\0') {

        *(uint8_t *)((int)in_EAX + 2) = 0xfb;

        *(uint8_t *)((int)in_EAX + 1) = 0x7d;

        *(uint8_t *)in_EAX = 10;

        return;

      }

      *(uint8_t *)((int)in_EAX + 2) = 100;

      *(uint8_t *)((int)in_EAX + 1) = 0x2a;

      *(uint8_t *)in_EAX = 5;

      return;

    }

  }

  if (param_2 != '\0') {

    *in_EAX = DAT_00afdf0c;

    return;

  }

  *in_EAX = DAT_00afdf00;

  return;

}
