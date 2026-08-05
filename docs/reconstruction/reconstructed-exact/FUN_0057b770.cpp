// =============================================================================
// FUN_0057b770
// -----------------------------------------------------------------------------
// Stable ID: aa_0057b770
// Address:   0x0057b770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057b770 @ 0x0057b770
// Stable ID: aa_0057b770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×2.
//  - Notable callees: FUN_0057fd40×2, FUN_0057b770.
//  - Return sites: 2.

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

void __thiscall FUN_0057b770(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  char *pcVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a52fd;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_18 = operator_new(0x20);

  puVar4 = param_2;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    local_18 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_18[4] = 0;

    local_18[5] = 0;

    local_18[6] = 0;

  }

  *local_18 = *param_2;

  local_18[1] = param_2[1];

  local_18[2] = 0;

  pcVar5 = (char *)param_2[2];

  local_4 = 0xffffffff;

  local_10 = local_18;

  if (pcVar5 != (char *)0x0) {

    pcVar6 = pcVar5 + 1;

    do {

      cVar1 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    if (0 < (int)pcVar5 - (int)pcVar6) {

      pcVar6 = operator_new__(((int)pcVar5 - (int)pcVar6) + 1);

      local_18[2] = pcVar6;

      pcVar5 = (char *)puVar4[2];

      do {

        cVar1 = *pcVar5;

        *pcVar6 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

    }

  }

  piVar7 = (int *)puVar4[4];

  if (piVar7 != (int *)puVar4[5]) {

    do {

      param_2 = operator_new(0xc);

      puVar2 = (uint32_t /* width from decompiler */ *)*piVar7;

      *param_2 = *puVar2;

      param_2[1] = puVar2[1];

      param_2[2] = puVar2[2];

      iVar3 = local_18[4];

      if ((iVar3 == 0) || ((uint)(local_18[6] - iVar3 >> 2) <= (uint)(local_18[5] - iVar3 >> 2))) {

        FUN_0057fd40(local_18[5],1,&param_2);

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)local_18[5];

        *puVar2 = param_2;

        local_18[5] = puVar2 + 1;

      }

      piVar7 = piVar7 + 1;

    } while (piVar7 != (int *)puVar4[5]);

  }

  iVar3 = *(int *)(param_1 + 0x1c);

  if ((iVar3 != 0) &&

     ((uint)(*(int *)(param_1 + 0x20) - iVar3 >> 2) < (uint)(*(int *)(param_1 + 0x24) - iVar3 >> 2))

     ) {

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20);

    *puVar4 = local_18;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar4 + 1;

    ExceptionList = local_c;

    return;

  }

  FUN_0057fd40(*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),1,&local_10);

  ExceptionList = local_c;

  return;

}
