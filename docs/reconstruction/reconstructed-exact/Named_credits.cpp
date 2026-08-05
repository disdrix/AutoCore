// =============================================================================
// Named_credits
// -----------------------------------------------------------------------------
// Stable ID: aa_005465c0
// Address:   0x005465c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_credits @ 0x005465c0
// Stable ID: aa_005465c0
// Embedded strings (evidence for future rename):
//   - "[$name]"
//   - "[$class]"
//   - "[$race]"
//   - "[$credits]"
//   - "%I64d"
//   - "[$level]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×5, do×5, while×5, return×1.
//  - Notable callees: find×10, sprintf×2, FUN_00521800, FUN_00521900, Named_credits.
//  - Strings: "[$name]"; "[$class]"; "[$race]"; "[$credits]".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "[$credits]"
 * Domain alias of FUN_005465c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_credits(int param_1,

                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                 *param_2)



{

  uint uVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  char acStack_40 [64];

  

  uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::find

                    (param_2,"[$name]",0);

  if (*(uint *)npos_exref != uVar1) {

    do {

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$name]",0);

      pcVar2 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) +

                                   0x160))();

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::replace

                (param_2,uVar1,7,pcVar2);

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$name]",0);

    } while (*(uint *)npos_exref != uVar1);

  }

  uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::find

                    (param_2,"[$class]",0);

  if (*(uint *)npos_exref != uVar1) {

    do {

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$class]",0);

      pcVar2 = (char *)FUN_00521900();

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::replace

                (param_2,uVar1,8,pcVar2);

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$class]",0);

    } while (*(uint *)npos_exref != uVar1);

  }

  uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::find

                    (param_2,"[$race]",0);

  if (*(uint *)npos_exref != uVar1) {

    do {

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$race]",0);

      pcVar2 = (char *)FUN_00521800();

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::replace

                (param_2,uVar1,7,pcVar2);

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$race]",0);

    } while (*(uint *)npos_exref != uVar1);

  }

  uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::find

                    (param_2,"[$credits]",0);

  if (*(uint *)npos_exref != uVar1) {

    do {

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$credits]",0);

      sprintf(acStack_40,"%I64d",*(uint *)(param_1 + 0x720) - *(uint *)(param_1 + 0x728),

              (*(int *)(param_1 + 0x724) - *(int *)(param_1 + 0x72c)) -

              (uint)(*(uint *)(param_1 + 0x720) < *(uint *)(param_1 + 0x728)));

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::replace

                (param_2,uVar1,10,acStack_40);

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$credits]",0);

    } while (*(uint *)npos_exref != uVar1);

  }

  uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::find

                    (param_2,"[$level]",0);

  if (*(uint *)npos_exref != uVar1) {

    do {

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$level]",0);

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

      sprintf(acStack_40,"%i",uVar3);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::replace

                (param_2,uVar1,8,acStack_40);

      uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(param_2,"[$level]",0);

    } while (*(uint *)npos_exref != uVar1);

  }

  return;

}
