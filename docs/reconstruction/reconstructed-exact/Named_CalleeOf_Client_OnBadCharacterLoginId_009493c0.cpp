// =============================================================================
// Named_CalleeOf_Client_OnBadCharacterLoginId_009493c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009493c0
// Callee of Client_OnBadCharacterLoginId (+1 other named callers)
// Address:   0x009493c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnBadCharacterLoginId: auth/session helper. Evidence string: "TransferConnection_OfflineToSector()...\nINFO: DestroyCharacterArray". Supports parent flow (not a free-standing entry point). Client_OnBadCharacterLoginId (+1 other named callers).
// Embedded strings (evidence):
//   - "TransferConnection_OfflineToSector()...\nINFO: DestroyCharacterArray"
//   - "CleanupCOList"
//   - "ClearallAnimations"
//   - "InitNetworking_sector"
//   - ");

  FUN_00943db0();

  FUN_007a4480(0,"
//   - ");

  FUN_00943b80(0);

  FUN_007a4480(0,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00442fa0, FUN_004962b0, FUN_0079e7d0, FUN_00807710, FUN_00943b80, FUN_00943db0, FUN_009493c0.
//  - Strings: ");

  FUN_00943db0();

  FUN_007a4480(0,"; ");

  FUN_00943b80(0);

  FUN_007a4480(0,"; "InitNetworking_sector".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_OnBadCharacterLoginId (+1 other named callers)
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

void Named_CalleeOf_Client_OnBadCharacterLoginId_009493c0(void)



{

  int in_EAX;

  DWORD DVar1;

  

  FUN_0079e7d0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0xde8));

  FUN_007a4480(0,"TransferConnection_OfflineToSector()...\nINFO: DestroyCharacterArray");

  FUN_00943db0();

  FUN_007a4480(0,"CleanupCOList");

  FUN_00943b80(0);

  FUN_007a4480(0,"ClearallAnimations");

  FUN_00442fa0(0,0,0,0,0);

  *(uint8_t *)(*(int *)(*(int *)(in_EAX + 0xe04) + 0xe894) + 0x8c) = 0;

  if ((*(int *)(in_EAX + 0xe04) != 0) && (*(int *)(*(int *)(in_EAX + 0xe04) + 0xe898) != 0)) {

    FUN_004962b0();

  }

  FUN_007a4480(0,"InitNetworking_sector");

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc0) = 1;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc4) = 3;

  DVar1 = GetTickCount();

  DAT_00d17930 = DVar1 + 60000;

  DAT_00d17934 = 1;

  FUN_00807710(in_EAX + 0x618,0x6979);

  return;

}
