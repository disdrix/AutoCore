// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_0076a900
// -----------------------------------------------------------------------------
// Stable ID: aa_0076a900
// Callee of Named_gfxBodyMassageMachine (+2 other named callers)
// Address:   0x0076a900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper. Evidence string: "CHUNK". Supports parent flow (not a free-standing entry point). Named_gfxBodyMassageMachine (+2 other named callers).
// Embedded strings (evidence):
//   - "CHUNK"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: CONCAT11, CONCAT12, CONCAT13, FUN_00436220, FUN_00767840, FUN_00769b70, FUN_0076a900, stoChunkReader_OpenChunk.
//  - Strings: "CHUNK".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine (+2 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxBodyMassageMachine_0076a900(void)



{

  uint32_t /* width from decompiler */ **ppuVar1;

  bool bVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_4c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [4];

  uint32_t /* width from decompiler */ **local_40 [4];

  int local_30;

  uint local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1357;

  local_c = ExceptionList;

  iVar5 = *(int *)(unaff_ESI + 0x1c) + *(int *)(unaff_ESI + 0x18);

  local_4c = 0;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_28,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       *)(unaff_ESI + 0x404c));

  local_4 = 0;

  if (*(int *)(unaff_ESI + 0x4044) == 0) {

    iVar3 = stoChunkReader_OpenChunk();

    if (-1 < iVar3) {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00436220();

      local_4c = *puVar4;

      if ((*(int *)(unaff_ESI + 0x4040) != 0) &&

         (iVar3 = *(int *)(unaff_ESI + 0x4040) + -1, *(int *)(unaff_ESI + 0x4040) = iVar3,

         iVar3 == 0)) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x403c) = 0;

      }

    }

  }

  else if (*(int *)(unaff_ESI + 0x4044) == 1) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    local_4._0_1_ = 1;

    iVar3 = FUN_00767840(unaff_ESI,1);

    if (iVar3 < 0) {

      local_4 = (uint)local_4._1_3_ << 8;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    }

    else {

      bVar2 = std::operator!=<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_44,"CHUNK");

      if (bVar2) {

        local_4 = (uint)local_4._1_3_ << 8;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

      }

      else {

        iVar3 = FUN_00769b70(unaff_ESI);

        if (iVar3 < 0) {

          local_4 = (uint)local_4._1_3_ << 8;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        }

        else if (local_30 == 4) {

          if (local_2c < 0x10) {

            local_40[0] = local_40;

          }

          ppuVar1 = (uint32_t /* width from decompiler */ **)*local_40[0];

          local_4c = CONCAT13((char)ppuVar1,

                              CONCAT12((char)((uint)ppuVar1 >> 8),

                                       CONCAT11((char)((uint)ppuVar1 >> 0x10),

                                                (char)((uint)ppuVar1 >> 0x18))));

          local_4 = (uint)local_4._1_3_ << 8;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        }

        else {

          local_4 = (uint)local_4._1_3_ << 8;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        }

      }

    }

  }

  if ((-1 < iVar5) && (iVar5 <= *(int *)(unaff_ESI + 0x28))) {

    iVar3 = *(int *)(unaff_ESI + 0x1c);

    if ((iVar5 < iVar3) || (*(int *)(unaff_ESI + 0x20) + iVar3 <= iVar5)) {

      *(int *)(unaff_ESI + 0x1c) = iVar5;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

    }

    else {

      *(int *)(unaff_ESI + 0x18) = iVar5 - iVar3;

    }

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_ESI + 0x404c),local_28);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return local_4c;

}
