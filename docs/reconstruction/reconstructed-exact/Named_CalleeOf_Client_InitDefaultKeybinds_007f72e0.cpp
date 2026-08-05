// =============================================================================
// Named_CalleeOf_Client_InitDefaultKeybinds_007f72e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007f72e0
// Callee of Client_InitDefaultKeybinds
// Address:   0x007f72e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_InitDefaultKeybinds: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: return×9, if×8, switch×1.
//  - Notable callees: CONCAT31×8, FUN_007f72e0.
//  - Return sites: 9.

/*
 * Behavioral notes:
 * Callee of Client_InitDefaultKeybinds
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Named_CalleeOf_Client_InitDefaultKeybinds_007f72e0(uint32_t /* width from decompiler */ param_1,uint16_t param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  byte bVar1;

  uint in_EAX;

  undefined3 uVar2;

  char unaff_BL;

  uint16_t unaff_SI;

  

  bVar1 = (byte)in_EAX;

  switch(param_4) {

  case 0:

    if ((bVar1 < 5) && (in_EAX = param_3 + (in_EAX & 0xff) * 0x34, *(char *)(in_EAX + 0xc) == '\0'))

    {

      uVar2 = (undefined3)(in_EAX >> 8);

      if (unaff_BL == '\0') {

        *(uint16_t *)(in_EAX + 6) = unaff_SI;

        *(uint16_t *)(in_EAX + 0x30) = param_2;

        *(uint8_t *)(in_EAX + 0xb) = 0;

        *(uint8_t *)(in_EAX + 10) = 0;

        return CONCAT31(uVar2,1);

      }

      *(uint16_t *)(in_EAX + 8) = unaff_SI;

      *(uint16_t *)(in_EAX + 0x32) = param_2;

      *(uint8_t *)(in_EAX + 0xb) = 0;

      *(uint8_t *)(in_EAX + 10) = 0;

      return CONCAT31(uVar2,1);

    }

    break;

  case 1:

    if ((bVar1 < 6) &&

       (in_EAX = param_3 + (in_EAX & 0xff) * 0x34, *(char *)(in_EAX + 0x110) == '\0')) {

      uVar2 = (undefined3)(in_EAX >> 8);

      if (unaff_BL == '\0') {

        *(uint16_t *)(in_EAX + 0x10a) = unaff_SI;

        *(uint16_t *)(in_EAX + 0x134) = param_2;

        *(uint8_t *)(in_EAX + 0x10f) = 0;

        *(uint8_t *)(in_EAX + 0x10e) = 0;

        return CONCAT31(uVar2,1);

      }

      *(uint16_t *)(in_EAX + 0x10c) = unaff_SI;

      *(uint16_t *)(in_EAX + 0x136) = param_2;

      *(uint8_t *)(in_EAX + 0x10f) = 0;

      *(uint8_t *)(in_EAX + 0x10e) = 0;

      return CONCAT31(uVar2,1);

    }

    break;

  case 2:

    if ((bVar1 < 0x78) &&

       (in_EAX = param_3 + (in_EAX & 0xff) * 0x34, *(char *)(in_EAX + 0x248) == '\0')) {

      uVar2 = (undefined3)(in_EAX >> 8);

      if (unaff_BL == '\0') {

        *(uint16_t *)(in_EAX + 0x242) = unaff_SI;

        *(uint16_t *)(in_EAX + 0x26c) = param_2;

        *(uint8_t *)(in_EAX + 0x247) = 0;

        *(uint8_t *)(in_EAX + 0x246) = 0;

        return CONCAT31(uVar2,1);

      }

      *(uint16_t *)(in_EAX + 0x244) = unaff_SI;

      *(uint16_t *)(in_EAX + 0x26e) = param_2;

      *(uint8_t *)(in_EAX + 0x247) = 0;

      *(uint8_t *)(in_EAX + 0x246) = 0;

      return CONCAT31(uVar2,1);

    }

    break;

  case 3:

    if ((bVar1 < 0x14) &&

       (in_EAX = param_3 + (in_EAX & 0xff) * 0x34, *(char *)(in_EAX + 0x1aa8) == '\0')) {

      uVar2 = (undefined3)(in_EAX >> 8);

      if (unaff_BL == '\0') {

        *(uint16_t *)(in_EAX + 0x1aa2) = unaff_SI;

        *(uint16_t *)(in_EAX + 0x1acc) = param_2;

        *(uint8_t *)(in_EAX + 0x1aa7) = 0;

        *(uint8_t *)(in_EAX + 0x1aa6) = 0;

        return CONCAT31(uVar2,1);

      }

      *(uint16_t *)(in_EAX + 0x1aa4) = unaff_SI;

      *(uint16_t *)(in_EAX + 0x1ace) = param_2;

      *(uint8_t *)(in_EAX + 0x1aa7) = 0;

      *(uint8_t *)(in_EAX + 0x1aa6) = 0;

      return CONCAT31(uVar2,1);

    }

  }

  return in_EAX & 0xffffff00;

}
