// =============================================================================
// FUN_00980250
// -----------------------------------------------------------------------------
// Stable ID: aa_00980250
// Address:   0x00980250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00980250 @ 0x00980250
// Stable ID: aa_00980250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×2.
//  - Notable callees: Client_SendSectorPacket, FUN_008073b0, FUN_00980250.
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

void FUN_00980250(uint32_t /* width from decompiler */ *param_1,char param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint in_EAX;

  uint32_t /* width from decompiler */ *buffer;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ local_30 [2];

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  

  if (DAT_00d1b6d8 != 0) {

    iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    local_28 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + DAT_00d1b6d8);

    local_24 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + DAT_00d1b6d8);

    local_20 = 0;

    local_8 = 0;

    local_30[0] = 0x20c4;

    local_18[0] = 0x8060;

    local_10 = local_28;

    local_c = local_24;

    buffer = operator_new__(in_EAX + 0x18);

    puVar3 = local_30;

    if (param_2 == '\0') {

      puVar3 = local_18;

    }

    *buffer = *puVar3;

    buffer[1] = puVar3[1];

    buffer[2] = puVar3[2];

    buffer[3] = puVar3[3];

    uVar2 = puVar3[5];

    buffer[4] = puVar3[4];

    buffer[5] = uVar2;

    puVar3 = buffer + 6;

    for (uVar4 = in_EAX >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar3 = *param_1;

      param_1 = param_1 + 1;

      puVar3 = puVar3 + 1;

    }

    for (uVar4 = in_EAX & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar3 = *(uint8_t *)param_1;

      param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

    if (param_2 != '\0') {

      Client_SendSectorPacket(&DAT_00d1a840,(short)(in_EAX + 0x18),buffer);

      operator_delete__(buffer);

      return;

    }

    FUN_008073b0(in_EAX + 0x18,buffer);

    operator_delete__(buffer);

  }

  return;

}
