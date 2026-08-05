// =============================================================================
// FUN_005ac1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ac1d0
// Address:   0x005ac1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ac1d0 @ 0x005ac1d0
// Stable ID: aa_005ac1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_005ac1d0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_005ac1d0(int param_1,

            basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  bool bVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  cVar1 = *(char *)((int)puVar5 + 0x2d);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar1 == '\0') {

    bVar3 = std::operator<<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                      ((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                        *)(puVar5 + 3),param_2);

    if (bVar3) {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

      puVar5 = puVar2;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

    }

    puVar2 = puVar5;

    puVar5 = puVar4;

    cVar1 = *(char *)((int)puVar4 + 0x2d);

  }

  return puVar2;

}
