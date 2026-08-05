// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×11, return×7, for×1.
//  - Notable callees: FUN_00436190, FUN_00467440, FUN_004674e0, FUN_00467600, FUN_00467690, FUN_00467820, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Invalid tag [ %s ] for phyBoundingVolume"; "..\\palantir/physics/phyBoundingVolumeFactory.h".
//  - Return sites: 7.

// =============================================================================
// Named_phyBoundingVolumeFactory_00467690
// -----------------------------------------------------------------------------
// Stable ID: aa_00467690
// Address:   0x00467690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "phyBoundingVolumeFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_phyBoundingVolumeFactory_00467690(void *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be484;

  local_c = ExceptionList;

  if (param_1 == (void *)0x42565350) {

    ExceptionList = &local_c;

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00467820();

    ExceptionList = local_c;

    return puVar1;

  }

  if (param_1 == (void *)0x42564258) {

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x20);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_00467440();

      ExceptionList = local_c;

      return puVar1;

    }

  }

  else if (param_1 == (void *)0x42564350) {

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x28);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_004674e0();

      ExceptionList = local_c;

      return puVar1;

    }

  }

  else if (param_1 == (void *)0x42565346) {

    ExceptionList = &local_c;

    puVar1 = operator_new(8);

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar1[1] = 0;

      *puVar1 = &PTR_FUN_00aa5c6c;

      ExceptionList = local_c;

      return puVar1;

    }

  }

  else {

    if (param_1 != (void *)0x42565753) {

      if (param_1 == (void *)0x0) {

        ExceptionList = &local_c;

        iVar3 = FUN_00436190(local_28,0);

        local_4 = 4;

        if (*(uint *)(iVar3 + 0x18) < 0x10) {

          iVar3 = iVar3 + 4;

        }

        else {

          iVar3 = *(int *)(iVar3 + 4);

        }

        uVar4 = FUN_0076cec0(&param_1,"Invalid tag [ %s ] for phyBoundingVolume",iVar3);

        vog_LogMessage("..\\palantir/physics/phyBoundingVolumeFactory.h",0x45,3,uVar4);

        local_4 = 0xffffffff;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      }

      ExceptionList = local_c;

      return (uint32_t /* width from decompiler */ *)0x0;

    }

    ExceptionList = &local_c;

    param_1 = operator_new(0x100);

    local_4 = 3;

    if (param_1 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_00467600(param_1);

      ExceptionList = local_c;

      return puVar1;

    }

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
