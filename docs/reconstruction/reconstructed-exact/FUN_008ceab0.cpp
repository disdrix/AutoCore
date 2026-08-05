// =============================================================================
// FUN_008ceab0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ceab0
// Address:   0x008ceab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ceab0 @ 0x008ceab0
// Stable ID: aa_008ceab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: return×9, if×3, switch×3, goto×1.
//  - Notable callees: FUN_008ceab0.
//  - Return sites: 9.

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

void FUN_008ceab0(void)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0x5a8);

  if (iVar1 == 0) {

    switch(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x5ac)) {

    case 0:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x26e6;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x26ef;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x298d;

      break;

    case 1:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x2993;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x299f;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x29ab;

      break;

    case 2:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x29b1;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x29bd;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x29c9;

      break;

    case 3:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x29d0;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x2995;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x26ea;

      break;

    default:

      goto switchD_008ceae0_default;

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x28;

  }

  else if (iVar1 == 1) {

    switch(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x5ac)) {

    case 0:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x36;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x2a16;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x272c;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x2738;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    case 1:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x36;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x2a48;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x2a54;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x2a60;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    case 2:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x36;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x273e;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x2a18;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x2a24;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    case 3:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x271e;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x2a2a;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x2a36;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x2a42;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    }

  }

  else if (iVar1 == 2) {

    switch(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x5ac)) {

    case 0:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x24;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x25d4;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x2935;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x294b;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    case 1:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x25;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x25de;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x25ee;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x2973;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    case 2:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x24;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x2965;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x295d;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x2941;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    case 3:

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = 0x24;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = 0x291f;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x580) = 0x25be;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x584) = 0x292d;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

      return;

    }

  }

switchD_008ceae0_default:

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x590) = 0;

  return;

}
