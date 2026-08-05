// =============================================================================
// FUN_009299d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009299d0
// Address:   0x009299d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009299d0 @ 0x009299d0
// Stable ID: aa_009299d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×9, return×6, for×1.
//  - Notable callees: Direct3DCreate9, FUN_00929730, FUN_009299d0, free, malloc.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ * __fastcall FUN_009299d0(uint32_t /* width from decompiler */ param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  int *piStack_188;

  int local_178;

  uint8_t auStack_174 [8];

  int iStack_16c;

  uint32_t /* width from decompiler */ local_168;

  uint32_t /* width from decompiler */ local_164 [4];

  uint32_t /* width from decompiler */ uStack_154;

  uint8_t auStack_13c [52];

  uint uStack_108;

  

  local_168 = 0;

  puVar1 = local_164;

  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  }

  if (param_2 == (int *)0x0) {

    piStack_188 = (int *)0x20;

    param_2 = (int *)Direct3DCreate9();

    if (param_2 == (int *)0x0) {

      return (uint32_t /* width from decompiler */ *)0x0;

    }

  }

  else {

    DAT_00d1773c = '\x01';

  }

  piStack_188 = &local_178;

  piVar3 = param_2;

  iVar2 = (**(code **)(*param_2 + 0x20))(param_2,0);

  if (iVar2 < 0) {

    if (DAT_00d1773c == '\0') {

      (**(code **)(*param_2 + 8))(param_2);

    }

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  puVar1 = malloc(0x28);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    if (DAT_00d1773c == '\0') {

      (**(code **)(*param_2 + 8))(param_2);

    }

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  iVar2 = FUN_00929730(local_178,puVar1);

  if (iVar2 != 0) {

    local_164[3] = param_3;

    uStack_154 = 1;

    local_164[2] = 1;

    iStack_16c = local_178;

    if ((DAT_00d1773c == '\0') &&

       (iVar2 = (**(code **)(*param_2 + 0x40))(param_2,0,1,param_3,0x20,auStack_174,&piStack_188),

       iVar2 < 0)) {

      free(puVar1);

      (**(code **)(*param_2 + 8))(param_2);

      return (uint32_t /* width from decompiler */ *)0x0;

    }

    (**(code **)(*piStack_188 + 0x1c))(piStack_188,auStack_13c);

    puVar1[9] = uStack_108 >> 8 & 1;

    *puVar1 = param_2;

    puVar1[2] = param_3;

    puVar1[1] = piVar3;

    return puVar1;

  }

  if (DAT_00d1773c == '\0') {

    (**(code **)(*param_2 + 8))(param_2);

  }

  return (uint32_t /* width from decompiler */ *)0x0;

}
