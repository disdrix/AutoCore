// =============================================================================
// FUN_00678650
// -----------------------------------------------------------------------------
// Stable ID: aa_00678650
// Address:   0x00678650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00678650 @ 0x00678650
// Stable ID: aa_00678650
// Embedded strings (evidence for future rename):
//   - "not NCI handle\n"
//   - "Incompatible handle\n"
//   - "not ENC handle\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×13, return×10.
//  - Notable callees: calloc×4, FUN_0076c130×3, CONCAT22×2, nciInitEncodeSase6500×2, FUN_00678650, FUN_006799a0, nciEnableVAD6500, nciGetInfoSase6500.
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

FUN_00678650(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  void *pvVar3;

  uint16_t extraout_var;

  uint32_t /* width from decompiler */ uVar4;

  uint16_t extraout_var_00;

  uint8_t local_4c [48];

  ushort local_1c;

  

  nciGetInfoSase6500(local_4c);

  if (*(int *)(param_1 + 4) == 0) {

    iVar2 = nciInitEncodeSase6500(param_1 + 0x5c);

    if (iVar2 != 0) {

      return 0xffffffff;

    }

    pvVar3 = calloc((uint)local_1c,2);

    *(void **)(param_1 + 0x2c) = pvVar3;

    pvVar3 = calloc(0x10,1);

    *(void **)(param_1 + 0x34) = pvVar3;

    if (*(int *)(param_1 + 0x2c) == 0) {

      return 0xffffffff;

    }

    if (pvVar3 == (void *)0x0) {

      return 0xffffffff;

    }

    *(ushort *)(param_1 + 0x30) = local_1c;

    *(uint16_t *)(param_1 + 0x38) = 0x12;

    *(uint16_t *)(param_1 + 0x3a) = 0;

    *(uint8_t *)(param_1 + 0x3c) = 0;

    *(uint16_t *)(param_1 + 0x3e) = 0;

    *(uint8_t *)(param_1 + 0x40) = 0;

  }

  else if (*(int *)(param_1 + 4) == 1) {

    iVar2 = nciInitDecodeSase6500(param_1 + 0x60);

    if (iVar2 != 0) {

      return 0xffffffff;

    }

    pvVar3 = calloc((uint)local_1c,2);

    *(void **)(param_1 + 0x44) = pvVar3;

    pvVar3 = calloc(0x10,1);

    *(void **)(param_1 + 0x4c) = pvVar3;

    if (*(int *)(param_1 + 0x44) == 0) {

      return 0xffffffff;

    }

    if (pvVar3 == (void *)0x0) {

      return 0xffffffff;

    }

    *(uint16_t *)(param_1 + 0x48) = 0;

    *(uint16_t *)(param_1 + 0x50) = 0x12;

    *(uint16_t *)(param_1 + 0x52) = 0;

    *(uint8_t *)(param_1 + 0x54) = 0;

    *(uint16_t *)(param_1 + 0x56) = 0;

    *(uint8_t *)(param_1 + 0x58) = 0;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

  nciInitEncodeSase6500(puVar1);

  if ((char)param_4 != '\0') {

    iVar2 = nciEnableVAD6500(*puVar1);

    if (iVar2 != 0) {

      if (iVar2 == 0x17d4) {

        FUN_0076c130("not NCI handle\n");

        return 0xffffffff;

      }

      if (iVar2 == 0x17d9) {

        FUN_0076c130("Incompatible handle\n");

        return 0xffffffff;

      }

      if (iVar2 == 0x17de) {

        FUN_0076c130("not ENC handle\n");

        return 0xffffffff;

      }

    }

    nciSetVADSilenceThresh6500(*puVar1,CONCAT22(extraout_var_00,*(uint16_t *)(param_1 + 0x2a)));

    nciSetVADEnergyTrigLevel6500(*puVar1,CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0x28)));

  }

  *(uint *)(param_1 + 0xc) = (uint)local_1c * 2;

  uVar4 = FUN_006799a0(param_2,0,param_4,0x10,8000,0x10,10);

  return uVar4;

}
