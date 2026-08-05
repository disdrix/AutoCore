// =============================================================================
// FUN_007838a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007838a0
// Address:   0x007838a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007838a0 @ 0x007838a0
// Stable ID: aa_007838a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: FUN_0077cc20×2, FUN_0077c610, FUN_007838a0.
//  - Return sites: 1.

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

void FUN_007838a0(void)



{

  int iVar1;

  int in_EAX;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_20 [8];

  

  unaff_EBX[1] = 0;

  unaff_EBX[2] = 0;

  *unaff_EBX = &PTR_LAB_00a9b28c;

  uVar2 = *(uint *)(in_EAX + 0x10);

  if (uVar2 == 0x20) {

    FUN_0077cc20(*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),0x10,0,unaff_EBX + 0x1b);

    iVar1 = *(int *)(in_EAX + 0xc);

    unaff_EBX[7] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

    unaff_EBX[8] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14);

    unaff_EBX[9] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18);

    uVar4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c);

  }

  else {

    local_20[0] = 0;

    local_20[1] = 0;

    local_20[2] = 0;

    local_20[3] = 0;

    local_20[4] = 0;

    local_20[5] = 0;

    local_20[6] = 0;

    local_20[7] = 0;

    if (0x1f < uVar2) {

      uVar2 = 0x20;

    }

    puVar5 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0xc);

    puVar6 = local_20;

    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    }

    FUN_0077cc20(local_20,0x10,0,unaff_EBX + 0x1b);

    unaff_EBX[7] = local_20[4];

    unaff_EBX[8] = local_20[5];

    unaff_EBX[9] = local_20[6];

    uVar4 = local_20[7];

  }

  unaff_EBX[10] = uVar4;

  unaff_EBX[3] = unaff_EBX[7];

  unaff_EBX[4] = unaff_EBX[8];

  unaff_EBX[5] = unaff_EBX[9];

  unaff_EBX[6] = unaff_EBX[10];

  FUN_0077c610(unaff_EBX + 3,unaff_EBX + 0x17,unaff_EBX + 0x1b);

  unaff_EBX[0x9c] = 0;

  return;

}
