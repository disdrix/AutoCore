// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×2, FUN_00402c40, FUN_00507a40, _vbase_destructor_, close, open.
//  - Strings: "Statistics for CVOGHBList"; "-------------------------"; "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00507a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00507a40
// Address:   0x00507a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_VOG_DEBUG_STOP_00507a40(char *param_1)



{

  int iVar1;

  basic_ostream<char,struct_std::char_traits<char>_> *pbVar2;

  uint *puVar3;

  int iVar4;

  basic_ofstream<char,struct_std::char_traits<char>_> local_a8 [148];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a318c;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff4c;

  if ((DAT_00b041c4 != '\0') && (iVar4 = 0, DAT_00b041c8 != 0)) {

    ExceptionList = &local_10;

    std::basic_ofstream<char,struct_std::char_traits<char>_>::

    basic_ofstream<char,struct_std::char_traits<char>_>(local_a8);

    if (param_1 != (char *)0x0) {

      local_8 = 1;

      std::basic_ofstream<char,struct_std::char_traits<char>_>::open(local_a8,param_1,0x12,0x1b6);

      pbVar2 = std::operator<<<struct_std::char_traits<char>_>

                         ((basic_ostream<char,struct_std::char_traits<char>_> *)local_a8,

                          "Statistics for CVOGHBList");

      std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar2,endl_exref);

      pbVar2 = std::operator<<<struct_std::char_traits<char>_>

                         ((basic_ostream<char,struct_std::char_traits<char>_> *)local_a8,

                          "-------------------------");

      std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar2,endl_exref);

      std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<

                ((basic_ostream<char,struct_std::char_traits<char>_> *)local_a8,endl_exref);

      FUN_00402c40();

      while( true ) {

        iVar1 = DAT_00b041c8;

        if (*(char *)(DAT_00b041c8 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar4 == 0) {

          iVar4 = *(int *)(iVar1 + 0x14);

        }

        else {

          iVar4 = *(int *)(iVar4 + 0x14);

        }

        if (iVar4 == 0) {

          puVar3 = (uint *)0x0;

        }

        else {

          puVar3 = *(uint **)(iVar4 + 8);

        }

        if (puVar3 == (uint *)0x0) break;

        pbVar2 = std::operator<<<struct_std::char_traits<char>_>

                           ((basic_ostream<char,struct_std::char_traits<char>_> *)local_a8,

                            "There were ");

        pbVar2 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<

                           (pbVar2,puVar3[1]);

        pbVar2 = std::operator<<<struct_std::char_traits<char>_>(pbVar2," with a frequency of ");

        pbVar2 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar2,*puVar3)

        ;

        pbVar2 = std::operator<<<struct_std::char_traits<char>_>(pbVar2,".");

        std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar2,endl_exref);

      }

      *(uint8_t *)(DAT_00b041c8 + 0x1d) = 0;

      std::basic_ostream<char,struct_std::char_traits<char>_>::flush

                ((basic_ostream<char,struct_std::char_traits<char>_> *)local_a8);

      std::basic_ofstream<char,struct_std::char_traits<char>_>::close(local_a8);

    }

    local_8 = 0xffffffff;

    std::basic_ofstream<char,struct_std::char_traits<char>_>::_vbase_destructor_(local_a8);

  }

  ExceptionList = local_10;

  return;

}
