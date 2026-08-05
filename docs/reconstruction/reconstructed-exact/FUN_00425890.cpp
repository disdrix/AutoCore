// =============================================================================
// FUN_00425890
// -----------------------------------------------------------------------------
// Stable ID: aa_00425890
// Address:   0x00425890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00425890 @ 0x00425890
// Stable ID: aa_00425890
// Embedded strings (evidence for future rename):
//   - "LogConnectionProtocol"
//   - "build hdr %d %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, while×1.
//  - Notable callees: BitStream_writeBits×8, FUN_00425890, FUN_00426760, FUN_0042b450, FUN_00783aa0, FUN_00783b60, swi.
//  - Strings: "LogConnectionProtocol"; "build hdr %d %d".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00425890(uint param_1,uint32_t /* width from decompiler */ *param_2)



{

  byte *pbVar1;

  code *pcVar2;

  int iVar3;

  char cVar4;

  int in_EAX;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  uint uVar8;

  int local_c;

  uint32_t /* width from decompiler */ *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_1;

  cVar4 = FUN_00426760(2);

  if ((cVar4 != '\0') && (param_2 == (uint32_t /* width from decompiler */ *)0x0)) {

    pcVar2 = (code *)swi(3);

    (*pcVar2)();

    return;

  }

  puVar6 = (uint32_t /* width from decompiler */ *)((*(int *)(iVar3 + 0x8c) - *(int *)(iVar3 + 0x9c)) + 7U >> 3);

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    *(int *)(iVar3 + 0x94) = *(int *)(iVar3 + 0x94) + 1;

  }

  local_8 = param_2;

  BitStream_writeBits(2,&local_8);

  local_8 = *(uint32_t /* width from decompiler */ **)(iVar3 + 0x94);

  BitStream_writeBits(5,&local_8);

  if ((*(int *)(in_EAX + 0x18) + 1U <= *(uint *)(in_EAX + 0x30)) ||

     (cVar4 = FUN_0042b450(), cVar4 != '\0')) {

    pbVar1 = (byte *)((*(uint *)(in_EAX + 0x18) >> 3) + *(int *)(in_EAX + 0xc));

    *pbVar1 = *pbVar1 | '\x01' << ((byte)*(uint *)(in_EAX + 0x18) & 7);

    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;

  }

  local_8 = (uint32_t /* width from decompiler */ *)(*(uint *)(iVar3 + 0x94) >> 5);

  BitStream_writeBits(6,&local_8);

  local_8 = *(uint32_t /* width from decompiler */ **)(iVar3 + 0x8c);

  BitStream_writeBits(10,&local_8);

  local_8 = (uint32_t /* width from decompiler */ *)0x0;

  BitStream_writeBits(0,&local_8);

  local_8 = puVar6;

  BitStream_writeBits((char)(DAT_00aaa688 >> 0x17) + -0x7e,&local_8);

  uVar7 = (int)puVar6 + 3 >> 2;

  uVar8 = 0;

  if (uVar7 != 0) {

    local_8 = (uint32_t /* width from decompiler */ *)(param_1 + 0x98);

    local_c = 0;

    do {

      if (uVar8 == uVar7 - 1) {

        uVar5 = ((int)puVar6 - local_c) * 8;

      }

      else {

        uVar5 = 0x20;

      }

      local_4 = *local_8;

      BitStream_writeBits(uVar5 & 0xff,&local_4);

      local_c = local_c + 4;

      local_8 = local_8 + 1;

      uVar8 = uVar8 + 1;

    } while (uVar8 < uVar7);

  }

  iVar3 = param_1;

  param_1 = *(int *)(*(int *)(param_1 + 0x1a8) + 0x78) - *(int *)(param_1 + 0x118);

  if (0x7ff < param_1) {

    param_1 = 0x7ff;

  }

  param_1 = param_1 >> 3;

  BitStream_writeBits(8,&param_1);

  puVar6 = param_2;

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc + (*(uint *)(iVar3 + 0x94) & 0x1f) * 4) =

         *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8c);

  }

  if ((_DAT_00d208b8 & 1) == 0) {

    _DAT_00d208b8 = _DAT_00d208b8 | 1;

    DAT_00d208b4 = FUN_00783b60("LogConnectionProtocol");

  }

  if (*(char *)(DAT_00d208b4 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d208b4;

    FUN_00783aa0("build hdr %d %d",*(uint32_t /* width from decompiler */ *)(iVar3 + 0x94),puVar6);

    DAT_00d179a0 = 0;

  }

  return;

}
