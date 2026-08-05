// =============================================================================
// FUN_004279b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004279b0
// Address:   0x004279b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004279b0 @ 0x004279b0
// Stable ID: aa_004279b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004279b0.
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

void FUN_004279b0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  *unaff_EBX = *in_EAX;

  unaff_EBX[1] = in_EAX[1];

  unaff_EBX[2] = in_EAX[2];

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  operator=((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *

            )(unaff_EBX + 3),

            (basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *

            )(in_EAX + 3));

  unaff_EBX[10] = in_EAX[10];

  unaff_EBX[0xb] = in_EAX[0xb];

  unaff_EBX[0xc] = in_EAX[0xc];

  unaff_EBX[0xd] = in_EAX[0xd];

  unaff_EBX[0xe] = in_EAX[0xe];

  unaff_EBX[0xf] = in_EAX[0xf];

  unaff_EBX[0x10] = in_EAX[0x10];

  unaff_EBX[0x11] = in_EAX[0x11];

  unaff_EBX[0x12] = in_EAX[0x12];

  unaff_EBX[0x13] = in_EAX[0x13];

  unaff_EBX[0x14] = in_EAX[0x14];

  unaff_EBX[0x15] = in_EAX[0x15];

  unaff_EBX[0x16] = in_EAX[0x16];

  puVar2 = in_EAX + 0x18;

  puVar3 = unaff_EBX + 0x18;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  return;

}
