// =============================================================================
// FUN_007aff60
// -----------------------------------------------------------------------------
// Stable ID: aa_007aff60
// Address:   0x007aff60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007aff60 @ 0x007aff60
// Stable ID: aa_007aff60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_0041c7e0, FUN_00797d70, FUN_007aff60.
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

void __thiscall

FUN_007aff60(int param_1,uint8_t param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            ,uint32_t /* width from decompiler */ param_6,char *param_7)



{

  char cVar1;

  void *pvVar2;

  uint8_t *puVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar3 = operator_new(0x28);

  if (puVar3 == (uint8_t *)0x0) {

    puVar3 = (uint8_t *)0x0;

  }

  else {

    puVar3[0x22] = 0xff;

    puVar3[0x21] = 0xff;

    puVar3[0x20] = 0xff;

    puVar3[0x23] = 0xff;

  }

  *puVar3 = param_2;

  *(uint32_t /* width from decompiler */ *)(puVar3 + 8) = param_3;

  *(uint32_t /* width from decompiler */ *)(puVar3 + 0xc) = param_4;

  *(uint32_t /* width from decompiler */ *)(puVar3 + 0x10) = param_5;

  *(uint32_t /* width from decompiler */ *)(puVar3 + 0x14) = param_6;

  *(uint32_t /* width from decompiler */ *)(puVar3 + 0x20) = DAT_00afdf0c;

  *(uint32_t /* width from decompiler */ *)(puVar3 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(puVar3 + 0x1c) = 0;

  if (param_7 != (char *)0x0) {

    pcVar4 = param_7;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar4 = operator_new__((uint)(pcVar4 + (1 - (int)(param_7 + 1))));

    *(char **)(puVar3 + 0x18) = pcVar4;

    do {

      cVar1 = *param_7;

      *pcVar4 = cVar1;

      param_7 = param_7 + 1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

  }

  puVar5 = operator_new(8);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = 0;

    puVar5[1] = 0;

  }

  *puVar5 = 0xd;

  puVar5[1] = puVar3;

  FUN_0041c7e0(param_1 + 0x1e8,puVar5);

  pvVar2 = *(void **)(param_1 + 0x28c);

  if (pvVar2 != (void *)0x0) {

    FUN_00797d70(pvVar2);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = 0;

  return;

}
