// =============================================================================
// Named_S_01f
// -----------------------------------------------------------------------------
// Stable ID: aa_006105d0
// Address:   0x006105d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_S_01f @ 0x006105d0
// Stable ID: aa_006105d0
// Embedded strings (evidence for future rename):
//   - "Height"
//   - "%s: %.01f/%.01f"
//   - "Distance"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, for×1, return×1.
//  - Notable callees: strncat×5, FUN_007a6de0×3, sprintf×3, Named_S_01f, FUN_007a69d0.
//  - Strings: "Height"; "%s: %.01f/%.01f"; "Distance".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "%s: %.01f/%.01f"
 * Domain alias of FUN_006105d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_S_01f(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,char *param_4,size_t param_5)



{

  float *pfVar1;

  char cVar2;

  bool bVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  float fVar8;

  double dVar9;

  double dVar10;

  char local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  local_208[0] = '\0';

  local_208[1] = '\0';

  puVar7 = local_206;

  for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  *(uint16_t *)puVar7 = 0;

  FUN_007a69d0();

  pcVar4 = param_4;

  do {

    cVar2 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar2 != '\0');

  fVar8 = *(float *)(param_1 + 0x10);

  bVar3 = false;

  if (fVar8 != g_flZero) {

    pfVar1 = (float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

    if (fVar8 < *pfVar1 || fVar8 == *pfVar1) {

      fVar8 = *(float *)(param_1 + 0x10);

    }

    else {

      fVar8 = *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

    }

    dVar10 = (double)*(float *)(param_1 + 0x10);

    dVar9 = (double)fVar8;

    uVar5 = FUN_007a6de0("Height",0xffffffff);

    sprintf(local_208,"%s: %.01f/%.01f",uVar5,dVar9,dVar10);

    strncat(param_4,local_208,param_5);

    bVar3 = true;

  }

  if (*(float *)(param_1 + 0x14) != g_flZero) {

    if (bVar3) {

      strncat(param_4,", ",param_5);

    }

    pfVar1 = (float *)(param_3 + 8 + (uint)*(byte *)(param_1 + 8) * 4);

    if (*(float *)(param_1 + 0x14) < *pfVar1 || *(float *)(param_1 + 0x14) == *pfVar1) {

      fVar8 = *(float *)(param_1 + 0x14);

    }

    else {

      fVar8 = *(float *)(param_3 + 8 + (uint)*(byte *)(param_1 + 8) * 4);

    }

    dVar10 = (double)*(float *)(param_1 + 0x14);

    dVar9 = (double)fVar8;

    uVar5 = FUN_007a6de0("Distance",0xffffffff);

    sprintf(local_208,"%s: %.01f/%.01f",uVar5,dVar9,dVar10);

    strncat(param_4,local_208,param_5);

    bVar3 = true;

  }

  if (*(float *)(param_1 + 0x18) != g_flZero) {

    if (bVar3) {

      strncat(param_4,", ",param_5);

    }

    pfVar1 = (float *)(param_3 + 0xc + (uint)*(byte *)(param_1 + 8) * 4);

    if (*(float *)(param_1 + 0x18) < *pfVar1 || *(float *)(param_1 + 0x18) == *pfVar1) {

      fVar8 = *(float *)(param_1 + 0x18);

    }

    else {

      fVar8 = *(float *)(param_3 + 0xc + (uint)*(byte *)(param_1 + 8) * 4);

    }

    dVar10 = (double)*(float *)(param_1 + 0x18);

    dVar9 = (double)fVar8;

    uVar5 = FUN_007a6de0(&DAT_009c6ca0,0xffffffff);

    sprintf(local_208,"%s: %.01f/%.01f",uVar5,dVar9,dVar10);

    strncat(param_4,local_208,param_5);

  }

  do {

    cVar2 = *param_4;

    param_4 = param_4 + 1;

  } while (cVar2 != '\0');

  return (int)param_4 - (int)pcVar4;

}
