// =============================================================================
// FUN_0079e550
// -----------------------------------------------------------------------------
// Stable ID: aa_0079e550
// Address:   0x0079e550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079e550 @ 0x0079e550
// Stable ID: aa_0079e550
// Embedded strings (evidence for future rename):
//   - "D3DX 9.09.376.0000"
//   - "DirectX SDK version: %s \r\n"
//   - "Video card Info: \r\n  Available texture ram: %d \r\n"
//   - "  Driver version: %s \r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: _snprintf×3, FUN_0075e630, FUN_0079e550, strncpy.
//  - Strings: "D3DX 9.09.376.0000"; "DirectX SDK version: %s \r\n"; "Video card Info: \r\n  Available texture ram: %d \r\n"; "  Driver version: %s \r\n".
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

void __thiscall

FUN_0079e550(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t auStack_80c [4];

  char local_808 [2];

  uint32_t /* width from decompiler */ local_806 [254];

  char acStack_40c [4];

  char local_408 [1028];

  

  local_808[0] = '\0';

  local_808[1] = '\0';

  puVar3 = local_806;

  for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *(uint16_t *)puVar3 = 0;

  strncpy(local_808,"D3DX 9.09.376.0000",0x400);

  _snprintf(local_408,0x400,"DirectX SDK version: %s \r\n",local_808);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_2,local_408);

  uVar1 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x28) + 0x10))

                    ((int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x28));

  _snprintf(acStack_40c,0x400,"Video card Info: \r\n  Available texture ram: %d \r\n",uVar1);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_2,acStack_40c);

  FUN_0075e630(auStack_80c,0x400);

  _snprintf(acStack_40c,0x400,"  Driver version: %s \r\n",auStack_80c);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_2,acStack_40c);

  return;

}
