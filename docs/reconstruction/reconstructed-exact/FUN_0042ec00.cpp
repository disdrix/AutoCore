// =============================================================================
// FUN_0042ec00
// -----------------------------------------------------------------------------
// Stable ID: aa_0042ec00
// Address:   0x0042ec00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042ec00 @ 0x0042ec00
// Stable ID: aa_0042ec00
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Sending punch packet (%s, %s) to %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×11, while×2, do×1, return×1.
//  - Notable callees: BitStream_writeBits×4, FUN_0040b290×3, FUN_00424d10×3, BitStream_writeFlag×2, FUN_0042b7d0×2, FUN_00974c00×2, FUN_0042bc80, FUN_0042ec00.
//  - Strings: "LogNetInterface"; "Sending punch packet (%s, %s) to %s".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0042ec00(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int unaff_ESI;

  uint8_t local_9bd;

  int local_9bc;

  undefined **local_9b0;

  uint32_t /* width from decompiler */ local_9ac;

  uint32_t /* width from decompiler */ local_9a8;

  int local_9a4;

  uint32_t /* width from decompiler */ local_9a0;

  uint8_t local_99c;

  undefined **local_998;

  uint32_t /* width from decompiler */ local_994;

  uint32_t /* width from decompiler */ local_990;

  int local_98c;

  uint32_t /* width from decompiler */ local_988;

  uint8_t local_984;

  undefined **local_980;

  uint32_t /* width from decompiler */ local_97c;

  uint32_t /* width from decompiler */ local_978;

  uint8_t *local_974;

  uint32_t /* width from decompiler */ local_970;

  uint8_t local_96c;

  uint local_968;

  uint8_t local_964;

  uint8_t local_963;

  uint32_t /* width from decompiler */ local_954;

  uint32_t /* width from decompiler */ local_950;

  uint32_t /* width from decompiler */ local_94c;

  uint8_t local_948;

  uint8_t local_848 [1492];

  uint8_t local_274 [4];

  uint32_t /* width from decompiler */ *local_270;

  

  local_974 = local_848;

  local_97c = 0;

  local_978 = 0;

  local_970 = 0x5d2;

  local_96c = 0;

  local_954 = 0x2e90;

  local_950 = 0x2e90;

  local_968 = 0;

  local_964 = 0;

  local_963 = 0;

  local_948 = 0;

  local_94c = 0;

  local_980 = &PTR_LAB_009d7ba4;

  local_9bd = 6;

  BitStream_writeBits(8,&local_9bd);

  if (*(char *)(unaff_ESI + 0x194) == '\0') {

    iVar7 = unaff_ESI + 0x140;

  }

  else {

    iVar7 = unaff_ESI + 0x138;

  }

  BitStream_writeBits(0x40,iVar7);

  local_968 = local_968 + 7 & 0xfffffff8;

  if (*(char *)(unaff_ESI + 0x194) == '\0') {

    BitStream_writeBits(0x40,unaff_ESI + 0x138);

    if ((*(char *)(param_1 + 0x7c) == '\0') &&

       ((*(char *)(unaff_ESI + 0x164) == '\0' || (*(int *)(param_1 + 0x3c) == 0)))) {

      uVar4 = 0;

    }

    else {

      uVar4 = 1;

    }

    cVar3 = BitStream_writeFlag(uVar4);

    if (cVar3 != '\0') {

      if ((*(char *)(unaff_ESI + 0x165) == '\0') || (*(int *)(param_1 + 0x40) == 0)) {

        uVar4 = 0;

      }

      else {

        uVar4 = 1;

      }

      cVar3 = BitStream_writeFlag(uVar4);

      if (cVar3 == '\0') {

        local_9bc = *(int *)(*(int *)(param_1 + 0x3c) + 0x18);

        if (local_9bc != 0) {

          *(int *)(local_9bc + 8) = *(int *)(local_9bc + 8) + 1;

        }

        FUN_0042b7d0();

        FUN_0040b290();

      }

      else {

        FUN_0042b7d0();

      }

    }

  }

  else {

    BitStream_writeBits(0x40,unaff_ESI + 0x140);

  }

  FUN_007838a0();

  FUN_0042bc80(5,local_274);

  local_9bc = 0;

  if (0 < *(int *)(unaff_ESI + 0x188)) {

    do {

      iVar7 = *(int *)(unaff_ESI + 0x10c);

      if (iVar7 == 0) {

        iVar7 = param_1 + 0x68;

      }

      FUN_00784d20(iVar7,local_848,local_968 + 7 >> 3);

      if ((_DAT_00d20bd0 & 1) == 0) {

        _DAT_00d20bd0 = _DAT_00d20bd0 | 1;

        DAT_00d20bcc = FUN_00783b60("LogNetInterface");

      }

      if (*(char *)(DAT_00d20bcc + 4) != '\0') {

        local_9ac = 0;

        local_9a8 = 0;

        local_9a4 = unaff_ESI + 0x140;

        local_99c = 0;

        local_9b0 = &PTR_LAB_009d7b00;

        local_9a0 = 8;

        DAT_00d179a0 = DAT_00d20bcc;

        piVar5 = (int *)FUN_00974c00(&local_9b0);

        uVar4 = *(uint32_t /* width from decompiler */ *)(*piVar5 + 0xc);

        local_98c = unaff_ESI + 0x138;

        local_994 = 0;

        local_990 = 0;

        local_998 = &PTR_LAB_009d7b00;

        local_988 = 8;

        local_984 = 0;

        piVar5 = (int *)FUN_00974c00(&local_998);

        uVar1 = *(uint32_t /* width from decompiler */ *)(*piVar5 + 0xc);

        uVar6 = FUN_007845c0();

        FUN_00783aa0("Sending punch packet (%s, %s) to %s",uVar1,uVar4,uVar6);

        FUN_0040b290();

        FUN_00424d10();

        FUN_0040b290();

        FUN_00424d10();

        DAT_00d179a0 = 0;

      }

      local_9bc = local_9bc + 1;

    } while (local_9bc < *(int *)(unaff_ESI + 0x188));

  }

  *(int *)(unaff_ESI + 0x1a0) = *(int *)(unaff_ESI + 0x1a0) + 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1a4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  while (local_270 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)local_270[2];

    *local_270 = 0;

    local_270[1] = 0;

    local_270[2] = 0;

    local_270 = puVar2;

  }

  FUN_00424d10();

  return;

}
