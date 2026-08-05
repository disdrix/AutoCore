// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a2810
// -----------------------------------------------------------------------------
// Stable ID: aa_006a2810
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a2810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "malformed billboard leaf". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "malformed billboard leaf"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, switch×1, goto×1, while×1.
//  - Notable callees: FUN_00699ee0×3, FUN_00699fb0×2, FUN_006874b0, FUN_00699ed0, FUN_00699ef0, FUN_006a2480, FUN_006a2810, _CxxThrowException.
//  - Strings: "malformed billboard leaf".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a2810(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t local_68 [12];

  uint8_t local_5c [12];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab304;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x4c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_006a2480();

  }

  local_4 = 0xffffffff;

  iVar3 = FUN_00699ee0();

  do {

    switch(iVar3) {

    case 0x1b5e:

      uVar4 = FUN_00699ef0();

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = uVar4;

      break;

    case 0x1b5f:

      iVar3 = *param_1;

      *param_1 = iVar3 + 1;

      *(uint8_t *)(iVar2 + 0x10) = *(uint8_t *)(param_1[2] + iVar3);

      break;

    case 0x1b60:

      iVar3 = *param_1;

      *param_1 = iVar3 + 1;

      *(uint8_t *)(iVar2 + 0x18) = *(uint8_t *)(param_1[2] + iVar3);

      break;

    default:

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_50,"malformed billboard leaf");

      local_4 = 1;

      FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

    case 0x1b62:

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_00699fb0(local_68);

      puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x1c);

      goto LAB_006a291e;

    case 0x1b63:

      iVar3 = *param_1;

      *param_1 = iVar3 + 1;

      *(uint8_t *)(iVar2 + 0x40) = *(uint8_t *)(param_1[2] + iVar3);

      break;

    case 0x1b64:

      iVar3 = *param_1;

      *param_1 = iVar3 + 1;

      *(float *)(iVar2 + 0x44) = (float)*(byte *)(param_1[2] + iVar3) * DAT_00aaa7a8;

      break;

    case 0x1b65:

      uVar4 = FUN_00699ee0();

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x48) = uVar4;

      break;

    case 0x1b67:

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_00699fb0(local_5c);

      puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);

LAB_006a291e:

      *puVar6 = *puVar5;

      puVar6[1] = puVar5[1];

      puVar6[2] = puVar5[2];

      break;

    case 0x1b68:

      FUN_00699ed0();

    }

    iVar3 = FUN_00699ee0();

    if (iVar3 == 0x1b5d) {

      ExceptionList = local_c;

      return iVar2;

    }

  } while( true );

}
