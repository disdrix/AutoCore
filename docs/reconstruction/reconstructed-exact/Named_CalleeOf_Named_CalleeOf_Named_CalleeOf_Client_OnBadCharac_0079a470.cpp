// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_0079a470
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a470
// Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
// Address:   0x0079a470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, if×3, for×3, return×1.
//  - Notable callees: FUN_0079a470, fclose, fopen, strncpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_0079a470(int param_1,int param_2)



{

  char cVar1;

  char *in_EAX;

  void *pvVar2;

  char *pcVar3;

  FILE *pFVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  char *pcVar8;

  int iVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  char local_104 [4];

  char local_100 [4];

  char local_fc [4];

  char local_f8 [2];

  char local_f6;

  

  if (*(void **)(param_2 + 0x18) != (void *)0x0) {

    operator_delete__(*(void **)(param_2 + 0x18));

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = 0;

  pvVar2 = operator_new__(param_1 * 0x2c);

  *(void **)(param_2 + 0x18) = pvVar2;

  if (*(FILE **)(param_2 + 0x23c) != (FILE *)0x0) {

    fclose(*(FILE **)(param_2 + 0x23c));

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x23c) = 0;

  }

  strncpy((char *)(param_2 + 0x240),in_EAX,0x104);

  local_100[0] = s____logs_stats__00a98290[4];

  local_100[1] = s____logs_stats__00a98290[5];

  local_100[2] = s____logs_stats__00a98290[6];

  local_100[3] = s____logs_stats__00a98290[7];

  local_104[0] = s____logs_stats__00a98290[0];

  local_104[1] = s____logs_stats__00a98290[1];

  local_104[2] = s____logs_stats__00a98290[2];

  local_104[3] = s____logs_stats__00a98290[3];

  local_f6 = s____logs_stats__00a98290[0xe];

  local_fc[0] = s____logs_stats__00a98290[8];

  local_fc[1] = s____logs_stats__00a98290[9];

  local_fc[2] = s____logs_stats__00a98290[10];

  local_fc[3] = s____logs_stats__00a98290[0xb];

  local_f8[0] = s____logs_stats__00a98290[0xc];

  local_f8[1] = s____logs_stats__00a98290[0xd];

  pcVar3 = in_EAX;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar10 = &stack0xfffffefb;

  do {

    pcVar8 = pcVar10 + 1;

    pcVar10 = pcVar10 + 1;

  } while (*pcVar8 != '\0');

  pcVar8 = in_EAX;

  for (uVar5 = (uint)((int)pcVar3 - (int)in_EAX) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar8;

    pcVar8 = pcVar8 + 4;

    pcVar10 = pcVar10 + 4;

  }

  for (uVar5 = (int)pcVar3 - (int)in_EAX & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

    *pcVar10 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    pcVar10 = pcVar10 + 1;

  }

  puVar12 = (uint32_t /* width from decompiler */ *)&stack0xfffffefb;

  do {

    puVar11 = puVar12;

    puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

  } while (*(char *)((int)puVar11 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a98288;

  *(uint8_t *)((int)puVar11 + 5) = DAT_00a9828c;

  pFVar4 = fopen(local_104,"w");

  iVar9 = 0;

  *(FILE **)(param_2 + 0x23c) = pFVar4;

  *(int *)(param_2 + 0x1c) = param_1;

  if (0 < param_1) {

    iVar7 = 0;

    do {

      puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x18) + iVar7);

      for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar12 = 0;

        puVar12 = puVar12 + 1;

      }

      *(int *)(iVar7 + *(int *)(param_2 + 0x18)) = iVar9;

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x24 + *(int *)(param_2 + 0x18)) = 9999999;

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x28 + *(int *)(param_2 + 0x18)) = 9999999;

      iVar9 = iVar9 + 1;

      iVar7 = iVar7 + 0x2c;

    } while (iVar9 < *(int *)(param_2 + 0x1c));

  }

  return;

}
