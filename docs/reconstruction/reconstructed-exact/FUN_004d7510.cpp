// =============================================================================
// FUN_004d7510
// -----------------------------------------------------------------------------
// Stable ID: aa_004d7510
// Address:   0x004d7510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d7510 @ 0x004d7510
// Stable ID: aa_004d7510
// Embedded strings (evidence for future rename):
//   - "MiniCatalog.cat"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: while×2, do×1, return×1.
//  - Notable callees: CONCAT31×2, FUN_004bae00×2, FUN_0075d200×2, FUN_0075d5b0×2, FUN_004bade0, FUN_004badf0, FUN_004d7230, FUN_004d7510.
//  - Strings: "MiniCatalog.cat".
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

void FUN_004d7510(void)



{

  bool bVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  int local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint8_t local_68 [92];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2181;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0099c140("MiniCatalog.cat");

  local_4 = 0;

  local_6c = FUN_0075d200(local_68);

  *(uint8_t *)(DAT_00d1f050 + 0x68) = 1;

  FUN_0075d5b0(1);

  FUN_004bade0();

  local_74 = CONCAT31(local_74._1_3_,1);

  local_70 = 2;

  bVar1 = true;

  do {

    uVar2 = local_74;

    local_78 = 0;

    iVar3 = FUN_004bae00(local_74,&local_78);

    while (iVar3 != 0) {

      FUN_004d7230();

      iVar3 = FUN_004bae00(uVar2,&local_78);

    }

    bVar1 = !bVar1;

    local_70 = local_70 + -1;

    local_74._1_3_ = (undefined3)((uint)local_74 >> 8);

    local_74 = CONCAT31(local_74._1_3_,bVar1);

  } while (local_70 != 0);

  FUN_004badf0();

  *(uint8_t *)(DAT_00d1f050 + 0x68) = 0;

  FUN_0075d5b0(0);

  FUN_0075d200(local_6c);

  local_4 = 0xffffffff;

  FUN_0099c130();

  ExceptionList = pvStack_c;

  return;

}
