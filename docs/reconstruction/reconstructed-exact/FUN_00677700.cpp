// =============================================================================
// FUN_00677700
// -----------------------------------------------------------------------------
// Stable ID: aa_00677700
// Address:   0x00677700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00677700 @ 0x00677700
// Stable ID: aa_00677700
// Embedded strings (evidence for future rename):
//   - "not NCI handle\n"
//   - "Incompatible handle\n"
//   - "not ENC handle\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×13, return×10.
//  - Notable callees: calloc×4, FUN_0076c130×3, CONCAT22, FUN_00677700, FUN_006799a0, FUN_007109c0, FUN_00710b20, FUN_00710d20.
//  - Strings: "not NCI handle\n"; "Incompatible handle\n"; "not ENC handle\n".
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ __thiscall

FUN_00677700(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint16_t extraout_var;

  uint8_t local_4c [48];

  ushort local_1c;

  

  FUN_00710b20(local_4c);

  if (*(int *)(param_1 + 4) == 0) {

    iVar1 = FUN_007109c0(param_1 + 0x5c);

    if (iVar1 != 0) {

      return 0xffffffff;

    }

    pvVar2 = calloc((uint)local_1c,2);

    *(void **)(param_1 + 0x2c) = pvVar2;

    pvVar2 = calloc(10,1);

    *(void **)(param_1 + 0x34) = pvVar2;

    if (*(int *)(param_1 + 0x2c) == 0) {

      return 0xffffffff;

    }

    if (pvVar2 == (void *)0x0) {

      return 0xffffffff;

    }

    *(uint16_t *)(param_1 + 0x30) = 0;

    *(uint16_t *)(param_1 + 0x38) = 10;

    *(uint16_t *)(param_1 + 0x3a) = 0;

    *(uint8_t *)(param_1 + 0x3c) = 0;

    *(uint16_t *)(param_1 + 0x3e) = 0;

    *(uint8_t *)(param_1 + 0x40) = 0;

  }

  else if (*(int *)(param_1 + 4) == 1) {

    iVar1 = FUN_00710d20(param_1 + 0x60);

    if (iVar1 != 0) {

      return 0xffffffff;

    }

    pvVar2 = calloc((uint)local_1c,2);

    *(void **)(param_1 + 0x44) = pvVar2;

    pvVar2 = calloc(10,1);

    *(void **)(param_1 + 0x4c) = pvVar2;

    if (*(int *)(param_1 + 0x44) == 0) {

      return 0xffffffff;

    }

    if (pvVar2 == (void *)0x0) {

      return 0xffffffff;

    }

    *(uint16_t *)(param_1 + 0x48) = 0;

    *(uint16_t *)(param_1 + 0x50) = 10;

    *(uint16_t *)(param_1 + 0x52) = 0;

    *(uint8_t *)(param_1 + 0x54) = 0;

    *(uint16_t *)(param_1 + 0x56) = 0;

    *(uint8_t *)(param_1 + 0x58) = 0;

  }

  if (((char)param_4 != '\0') && (*(int *)(param_1 + 4) == 0)) {

    iVar1 = FUN_00710e80(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c));

    if (iVar1 != 0) {

      if (iVar1 == 0x17d4) {

        FUN_0076c130("not NCI handle\n");

        return 0xffffffff;

      }

      if (iVar1 == 0x17d9) {

        FUN_0076c130("Incompatible handle\n");

        return 0xffffffff;

      }

      if (iVar1 == 0x17de) {

        FUN_0076c130("not ENC handle\n");

        return 0xffffffff;

      }

    }

    FUN_00710f10(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c),*(uint16_t *)(param_1 + 0x2a));

    FUN_00710f50(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c),

                 CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0x28)));

  }

  *(uint *)(param_1 + 0xc) = (uint)local_1c * 2;

  uVar3 = FUN_006799a0(param_2,0,param_4,8,8000,0x10,10);

  return uVar3;

}
