// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0071f140
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f140
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x0071f140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper. Evidence string: "

        ;

      }

      else {

        if (iVar3 != -3) goto LAB_0071f294;

        p". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "

        ;

      }

      else {

        if (iVar3 != -3) goto LAB_0071f294;

        p"
//   - "CreateRawDataFromFile error OV_HOLE: indicates there was an interruption in the data.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, goto×1.
//  - Notable callees: _vbase_destructor_×2, FUN_0071f140, FUN_007a4480, FUN_007b6a20, FUN_007b70e0, close, open.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

uint8_t __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0071f140(char *param_1)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  char unaff_BL;

  int *piVar4;

  uint uVar5;

  int unaff_EDI;

  char *pcVar6;

  uint8_t local_bd;

  basic_ifstream<char,struct_std::char_traits<char>_> local_bc [176];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b10b8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_ifstream<char,struct_std::char_traits<char>_>::

  basic_ifstream<char,struct_std::char_traits<char>_>(local_bc);

  piVar4 = (int *)0x0;

  local_4 = 0;

  local_bd = 1;

  if (unaff_BL == '\0') {

    FUN_007b6a20(param_1);

    piVar4 = (int *)FUN_007b70e0(param_1);

    if (piVar4 == (int *)0x0) {

      local_4 = 0xffffffff;

      std::basic_ifstream<char,struct_std::char_traits<char>_>::_vbase_destructor_(local_bc);

      ExceptionList = local_c;

      return 0;

    }

    (**(code **)(*piVar4 + 8))();

    uVar5 = (**(code **)(*piVar4 + 0x1c))();

  }

  else {

    std::basic_ifstream<char,struct_std::char_traits<char>_>::open(local_bc,param_1,0x20,0x1b6);

    std::basic_istream<char,struct_std::char_traits<char>_>::seekg

              ((basic_istream<char,struct_std::char_traits<char>_> *)local_bc,0,2);

    piVar1 = (int *)std::basic_istream<char,struct_std::char_traits<char>_>::tellg

                              ((basic_istream<char,struct_std::char_traits<char>_> *)local_bc);

    uVar5 = piVar1[2] + *piVar1;

  }

  *(uint *)(unaff_EDI + 0x20) = uVar5;

  pvVar2 = operator_new__(uVar5);

  DAT_00d1a608 = DAT_00d1a608 + uVar5;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3c) = 0;

  *(void **)(unaff_EDI + 0x28) = pvVar2;

  *(uint *)(unaff_EDI + 0x30) = uVar5;

  *(int *)(unaff_EDI + 0x34) = (int)uVar5 >> 0x1f;

  *(uint8_t *)(unaff_EDI + 2) = 1;

  if (unaff_BL == '\0') {

    iVar3 = (**(code **)(*piVar4 + 0x14))(pvVar2,uVar5);

    if (iVar3 < 0) {

      if (iVar3 == -0x89) {

        pcVar6 = 

        "CreateRawDataFromFile error OV_HOLE: indicates that an invalid stream section was supplied to libvorbisfile, or the requested link is corrupt. \n"

        ;

      }

      else {

        if (iVar3 != -3) goto LAB_0071f294;

        pcVar6 = 

        "CreateRawDataFromFile error OV_HOLE: indicates there was an interruption in the data.\n";

      }

      FUN_007a4480(0,pcVar6);

      local_bd = 0;

    }

  }

  else {

    std::basic_istream<char,struct_std::char_traits<char>_>::seekg

              ((basic_istream<char,struct_std::char_traits<char>_> *)local_bc,0,0);

    std::basic_istream<char,struct_std::char_traits<char>_>::read

              ((basic_istream<char,struct_std::char_traits<char>_> *)local_bc,

               *(char **)(unaff_EDI + 0x28),uVar5);

    std::basic_ifstream<char,struct_std::char_traits<char>_>::close(local_bc);

  }

LAB_0071f294:

  if (piVar4 != (int *)0x0) {

    (**(code **)*piVar4)(1);

  }

  local_4 = 0xffffffff;

  std::basic_ifstream<char,struct_std::char_traits<char>_>::_vbase_destructor_(local_bc);

  ExceptionList = local_c;

  return local_bd;

}
