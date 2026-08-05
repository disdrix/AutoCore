// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ce370
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce370
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
// Address:   0x004ce370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, for×2, return×1.
//  - Notable callees: FUN_004ce370, fclose, fopen, fread.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ce370(int param_1)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  FILE *_File;

  uint uVar4;

  char *pcVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ local_108;

  char local_104 [4];

  char local_100 [4];

  char local_fc [4];

  char local_f8 [4];

  char local_f4 [2];

  char local_f2;

  

  *(uint8_t *)(param_1 + 0xe7c8) = 0;

  if (*(char *)(param_1 + 0x7d) == '\0') {

    local_104[0] = s____maps_roadcache__009cc310[0];

    local_104[1] = s____maps_roadcache__009cc310[1];

    local_104[2] = s____maps_roadcache__009cc310[2];

    local_104[3] = s____maps_roadcache__009cc310[3];

    local_fc[0] = s____maps_roadcache__009cc310[8];

    local_fc[1] = s____maps_roadcache__009cc310[9];

    local_fc[2] = s____maps_roadcache__009cc310[10];

    local_fc[3] = s____maps_roadcache__009cc310[0xb];

    local_100[0] = s____maps_roadcache__009cc310[4];

    local_100[1] = s____maps_roadcache__009cc310[5];

    local_100[2] = s____maps_roadcache__009cc310[6];

    local_100[3] = s____maps_roadcache__009cc310[7];

    local_f8[0] = s____maps_roadcache__009cc310[0xc];

    local_f8[1] = s____maps_roadcache__009cc310[0xd];

    local_f8[2] = s____maps_roadcache__009cc310[0xe];

    local_f8[3] = s____maps_roadcache__009cc310[0xf];

    pcVar1 = (char *)(param_1 + 0xb4);

    local_f2 = s____maps_roadcache__009cc310[0x12];

    local_f4[0] = s____maps_roadcache__009cc310[0x10];

    local_f4[1] = s____maps_roadcache__009cc310[0x11];

    pcVar3 = pcVar1;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    pcVar6 = (char *)((int)&local_108 + 3);

    do {

      pcVar5 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = pcVar1;

    for (uVar4 = (uint)((int)pcVar3 - (int)pcVar1) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar6 = pcVar6 + 4;

    }

    for (uVar4 = (int)pcVar3 - (int)pcVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar6 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar6 = pcVar6 + 1;

    }

    pcVar1 = (char *)((int)&local_108 + 3);

    do {

      pcVar3 = pcVar1;

      pcVar1 = pcVar3 + 1;

    } while (pcVar3[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar3 + 1) = s__roadver_dat_009cc300._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar3 + 5) = s__roadver_dat_009cc300._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar3 + 9) = s__roadver_dat_009cc300._8_4_;

    pcVar3[0xd] = s__roadver_dat_009cc300[0xc];

    _File = fopen(local_104,"rb");

    if (_File != (FILE *)0x0) {

      local_108 = 0;

      fread(&local_108,4,1,_File);

      if (local_108 == *(int *)(*(int *)(param_1 + 0xe4f8) + 4)) {

        *(uint8_t *)(param_1 + 0xe7c8) = 1;

        *(uint8_t *)(param_1 + 0xe7c9) = 1;

      }

      fclose(_File);

    }

  }

  return;

}
