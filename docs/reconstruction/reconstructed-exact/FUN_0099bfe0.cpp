// =============================================================================
// FUN_0099bfe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099bfe0
// Address:   0x0099bfe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099bfe0 @ 0x0099bfe0
// Stable ID: aa_0099bfe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, goto×1, return×1.
//  - Notable callees: CloseHandle, FUN_005b2ba0, FUN_00744820, FUN_00766750, FUN_007669d0, FUN_007670a0, FUN_0099bfe0, strrchr.
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

bool FUN_0099bfe0(char *param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  BOOL BVar4;

  undefined **local_148;

  uint32_t /* width from decompiler */ local_144;

  HANDLE local_140;

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  undefined ***local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  char local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009add85;

  local_c = ExceptionList;

  iVar3 = -(int)param_1;

  do {

    cVar1 = *param_1;

    param_1[(int)(local_110 + iVar3)] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  ExceptionList = &local_c;

  pcVar2 = strrchr(local_110,0x2e);

  pcVar2[1] = 'c';

  pcVar2[2] = 'a';

  pcVar2[3] = 't';

  local_148 = &PTR_FUN_00a9d84c;

  local_144 = 0;

  local_140 = (HANDLE)0xffffffff;

  local_13c = 0;

  local_138 = 0;

  local_4 = 0;

  iVar3 = FUN_007669d0(local_110,6,0x8000000);

  if (iVar3 == 0) {

    local_134 = &local_148;

    local_130 = 0;

    local_128 = 0;

    local_124 = 0;

    local_120 = 0;

    local_11c = 0;

    local_4._0_1_ = 1;

    local_118 = 0;

    local_114 = 0;

    FUN_007670a0();

    local_4._0_1_ = 2;

    FUN_00744820();

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_005b2ba0();

  }

  cVar1 = (*(code *)local_148[8])();

  if (cVar1 != '\0') {

    BVar4 = CloseHandle(local_140);

    if (BVar4 == 0) goto LAB_0099c0ff;

  }

  local_140 = (HANDLE)0xffffffff;

LAB_0099c0ff:

  local_4 = 0xffffffff;

  FUN_00766750();

  ExceptionList = local_c;

  return iVar3 == 0;

}
