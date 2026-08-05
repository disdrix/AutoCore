// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, goto×2, do×1, switch×1, while×1.
//  - Notable callees: FUN_0063fb30×7, FUN_00652910×4, FUN_00631f10, FUN_00640010, FUN_00641250, FUN_006412c0, FUN_006413d0, FUN_00641860.
//  - Strings: "SERVER GOT GIGO...0x%x \n".
//  - Return sites: 2.

// =============================================================================
// Named_SERVER_GOT_GIGO_0x_x_006413d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006413d0
// Address:   0x006413d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "SERVER GOT GIGO...0x%x 
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_SERVER_GOT_GIGO_0x_x_006413d0(int param_1,uint8_t *param_2)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  char local_38;

  uint8_t uStack_37;

  uint8_t uStack_36;

  uint8_t uStack_35;

  uint8_t uStack_34;

  uint8_t uStack_33;

  uint8_t uStack_32;

  uint8_t uStack_31;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint8_t auStack_20 [28];

  

  if (*(int *)(param_1 + 8) == 0) {

LAB_006415b6:

    *param_2 = 1;

    return;

  }

  do {

    FUN_00652910(&local_38,1,1);

    cVar1 = local_38;

    switch(local_38) {

    case -0x60:

      if (*(int *)(param_1 + 0x14) != 0) {

        FUN_00641860(*(int *)(param_1 + 0x14),0x3fd);

      }

      FUN_0063fb30(&uStack_32);

      break;

    default:

      uVar3 = (**(code **)(*DAT_00d030e0 + 4))("SERVER GOT GIGO...0x%x \n",(int)local_38);

      FUN_00631f10(uVar3);

      goto LAB_006415b6;

    case -0x50:

      FUN_00641250();

      break;

    case -0x4f:

      FUN_00652d00(auStack_20);

      pcVar2 = (char *)FUN_0063fb30(&uStack_35);

      if ((*pcVar2 != '\0') && (*(int *)(param_1 + 0x10) != 0)) {

        FUN_006427d0(auStack_20);

      }

      break;

    case -0x4e:

      pcVar2 = (char *)FUN_0063fb30(&uStack_34);

      if ((*pcVar2 != '\0') && (*(int *)(param_1 + 0x10) != 0)) {

        FUN_006427e0();

      }

      break;

    case -0x40:

      FUN_00652910(&uStack_28,8,1);

      pcVar2 = (char *)FUN_0063fb30(&uStack_33);

      if ((*pcVar2 != '\0') && (*(int *)(param_1 + 0x18) != 0)) {

        FUN_00640010(uStack_28,uStack_24);

      }

      break;

    case -0x3f:

      FUN_006412c0();

      break;

    case -0x3e:

      FUN_00652910(&uStack_30,4,1);

      pcVar2 = (char *)FUN_0063fb30(&uStack_37);

      if ((*pcVar2 != '\0') && (*(int *)(param_1 + 0xc) != 0)) {

        (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(uStack_30);

      }

      break;

    case -0x3d:

      FUN_00652910(&uStack_2c,4,1);

      pcVar2 = (char *)FUN_0063fb30(&uStack_36);

      if ((*pcVar2 != '\0') && (*(int *)(param_1 + 0xc) != 0)) {

        (**(code **)(**(int **)(param_1 + 0xc) + 0x10))(uStack_2c);

      }

      break;

    case -0x10:

      break;

    }

    pcVar2 = (char *)FUN_0063fb30(&uStack_31);

    if (*pcVar2 == '\0') goto LAB_006415b6;

    if (cVar1 == -0x10) {

      *param_2 = 1;

      return;

    }

  } while( true );

}
