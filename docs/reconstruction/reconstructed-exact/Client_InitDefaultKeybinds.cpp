// READABILITY (auto CF):
//  - Body size: ~311 non-empty decompiler lines.
//  - Control keywords: if×36, return×1.
//  - Notable callees: FUN_007f72e0×74, Client_InitDefaultKeybinds, FUN_007f74a0, slots.
//  - Return sites: 1.

// =============================================================================
// Client_InitDefaultKeybinds
// -----------------------------------------------------------------------------
// Stable ID: aa_007f8720
// Address:   0x007f8720  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (ActionMap default DIK table)
// Generated: 2026-07-23 from raw capture
// Refined:   2026-07-23 human-refine — sectioned slot groups; pActionMap rename
//            (decomp unaff_EDI); DIK immediates documented. CF ≡ raw.
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  Write default DIK/VK codes into ActionMap action slots when the
//           per-slot "already customized" flag is clear. Slot stride 0x34.
//           Also bulk-calls FUN_007f72e0 (slot helper; args 2 or 3) and sets
//           several enable bytes late in the body.
//
// Convention: ActionMap object pointer arrives in EDI (decomp unaff_EDI → pActionMap).
//             Called from Client_ActionMap_Init after Client_InitActionDisplayNames.
//
// Per-slot write pattern (when flag@base == 0):
//   primary DIK u16  at base-6   (e.g. flag@0x5f0 → key@0x5ea)
//   secondary DIK u16 at base+0x24 (0 for unbound; 0x2a = DIK_LSHIFT often)
//   two u8 clears near flag-1 / flag-2
// Then some early slots force flag bytes to 1 after the first quartet.
//
// Notable plate defaults:
//   Inventory key DIK 0x17 (I) at +0x5ea; Shift+I at mission-inv (+0x61e / mod 0x2a)
//   QuickBar 1–10 primary DIK 2..0x0B at +0xc9e .. (QB1=2 … QB10=0x0B)
//   Shift-QB pages use primary 2..9 with mod 0x2a at higher offsets
//
// Drive thr/steer/HB defaults: not assigned as named immediates in this body —
//   FUN_007f74a0 prologue and/or FUN_007f72e0 helpers may seed them; open.
//
// Related:
//   Client_ActionMap_Init            0x007f9110
//   Client_InitActionDisplayNames    0x007f7570  (names for same slots)
//   Client_Input_DriveControlTick    0x009223b0  (consumes held flags)
//   docs/reconstruction/reviews/A_aa_007f8720_Client_InitDefaultKeybinds.md
//   docs/reconstruction/reviews/B_aa_007f8720_Client_InitDefaultKeybinds.md
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN → fixed-width; unaff_EDI → pActionMap.
 * - Section banners group UI / inventory / QB / helper bursts only.
 * - Control flow and store order preserved from authoritative raw.
 *
 * Section index:
 *   0  FUN_007f74a0 prologue
 *   1  Early system slots (Slash / Screenshot / …) + force-enable flags
 *   2  Inventory / profile / UI window binds
 *   3  Map / HUD-adjacent binds
 *   4  QuickBar 1–10 primary keys (DIK 2..0x0B)
 *   5  Shift QuickBar / page binds (mod 0x2a)
 *   6  FUN_007f72e0(…,2) burst + enable bytes
 *   7  Second FUN_007f72e0(…,2) burst + +0x450
 *   8  FUN_007f72e0(…,3) burst + return
 */

void FUN_007f74a0(void);
void FUN_007f72e0(int pActionMap, int mode);

void Client_InitDefaultKeybinds(void)
{
  int pActionMap; /* decomp unaff_EDI — ActionMap* */

  // ---------------------------------------------------------------------------
  // SECTION 0: Prologue helper (may seed base slots / drive defaults — body open)
  // ---------------------------------------------------------------------------
  FUN_007f74a0();

  // ---------------------------------------------------------------------------
  // SECTION 1: Early system slots (flag@+0x40, +0x74, +0xa8, +0xdc)
  // DIK: 0x35, 0xb7, 0xb5, 0x4e — plate: Slash / Screenshot family (Probable)
  // ---------------------------------------------------------------------------
  if (*(char *)(pActionMap + 0x40) == '\0') {
    *(uint16_t *)(pActionMap + 0x3a) = 0x35;
    *(uint16_t *)(pActionMap + 100) = 0;
    *(uint8_t *)(pActionMap + 0x3f) = 0;
    *(uint8_t *)(pActionMap + 0x3e) = 0;
  }
  if (*(char *)(pActionMap + 0x74) == '\0') {
    *(uint16_t *)(pActionMap + 0x6e) = 0xb7;
    *(uint16_t *)(pActionMap + 0x98) = 0;
    *(uint8_t *)(pActionMap + 0x73) = 0;
    *(uint8_t *)(pActionMap + 0x72) = 0;
  }
  if (*(char *)(pActionMap + 0xa8) == '\0') {
    *(uint16_t *)(pActionMap + 0xa2) = 0xb5;
    *(uint16_t *)(pActionMap + 0xcc) = 0;
    *(uint8_t *)(pActionMap + 0xa7) = 0;
    *(uint8_t *)(pActionMap + 0xa6) = 0;
  }
  if (*(char *)(pActionMap + 0xdc) == '\0') {
    *(uint16_t *)(pActionMap + 0xd6) = 0x4e;
    *(uint16_t *)(pActionMap + 0x100) = 0;
    *(uint8_t *)(pActionMap + 0xdb) = 0;
    *(uint8_t *)(pActionMap + 0xda) = 0;
  }
  *(uint8_t *)(pActionMap + 0x40) = 1;
  *(uint8_t *)(pActionMap + 0x74) = 1;
  *(uint8_t *)(pActionMap + 0xa8) = 1;
  *(uint8_t *)(pActionMap + 0xdc) = 1;
  *(uint8_t *)(pActionMap + 0x9e) = 1;

  // ---------------------------------------------------------------------------
  // SECTION 2: Inventory / mission-inv / character / research / locker / medals
  // Inventory DIK 0x17 (I) @ +0x5ea; Shift+I mission inv (mod 0x2a @ +0x648)
  // ---------------------------------------------------------------------------
  if (*(char *)(pActionMap + 0x5f0) == '\0') {
    *(uint16_t *)(pActionMap + 0x5ea) = 0x17;
    *(uint16_t *)(pActionMap + 0x614) = 0;
    *(uint8_t *)(pActionMap + 0x5ef) = 0;
    *(uint8_t *)(pActionMap + 0x5ee) = 0;
  }
  if (*(char *)(pActionMap + 0x624) == '\0') {
    *(uint16_t *)(pActionMap + 0x61e) = 0x17;
    *(uint16_t *)(pActionMap + 0x648) = 0x2a;
    *(uint8_t *)(pActionMap + 0x623) = 0;
    *(uint8_t *)(pActionMap + 0x622) = 0;
  }
  if (*(char *)(pActionMap + 0x6c0) == '\0') {
    *(uint16_t *)(pActionMap + 0x6ba) = 0x19;
    *(uint16_t *)(pActionMap + 0x6e4) = 0;
    *(uint8_t *)(pActionMap + 0x6bf) = 0;
    *(uint8_t *)(pActionMap + 0x6be) = 0;
  }
  if (*(char *)(pActionMap + 0x7c4) == '\0') {
    *(uint16_t *)(pActionMap + 0x7be) = 0x21;
    *(uint16_t *)(pActionMap + 0x7e8) = 0;
    *(uint8_t *)(pActionMap + 0x7c3) = 0;
    *(uint8_t *)(pActionMap + 0x7c2) = 0;
  }
  if (*(char *)(pActionMap + 0x75c) == '\0') {
    *(uint16_t *)(pActionMap + 0x756) = 0x2c;
    *(uint16_t *)(pActionMap + 0x780) = 0;
    *(uint8_t *)(pActionMap + 0x75b) = 0;
    *(uint8_t *)(pActionMap + 0x75a) = 0;
  }
  if (*(char *)(pActionMap + 0x68c) == '\0') {
    *(uint16_t *)(pActionMap + 0x686) = 0x18;
    *(uint16_t *)(pActionMap + 0x6b0) = 0;
    *(uint8_t *)(pActionMap + 0x68b) = 0;
    *(uint8_t *)(pActionMap + 0x68a) = 0;
  }
  if (*(char *)(pActionMap + 0x6f4) == '\0') {
    *(uint16_t *)(pActionMap + 0x6ee) = 0x27;
    *(uint16_t *)(pActionMap + 0x718) = 0;
    *(uint8_t *)(pActionMap + 0x6f3) = 0;
    *(uint8_t *)(pActionMap + 0x6f2) = 0;
  }
  if (*(char *)(pActionMap + 0x728) == '\0') {
    *(uint16_t *)(pActionMap + 0x722) = 0x25;
    *(uint16_t *)(pActionMap + 0x74c) = 0;
    *(uint8_t *)(pActionMap + 0x727) = 0;
    *(uint8_t *)(pActionMap + 0x726) = 0;
  }
  if (*(char *)(pActionMap + 0x7f8) == '\0') {
    *(uint16_t *)(pActionMap + 0x7f2) = 0x23;
    *(uint16_t *)(pActionMap + 0x81c) = 0x2a;
    *(uint8_t *)(pActionMap + 0x7f7) = 0;
    *(uint8_t *)(pActionMap + 0x7f6) = 0;
  }
  if (*(char *)(pActionMap + 0x860) == '\0') {
    *(uint16_t *)(pActionMap + 0x85a) = 0x23;
    *(uint16_t *)(pActionMap + 0x884) = 0;
    *(uint8_t *)(pActionMap + 0x85f) = 0;
    *(uint8_t *)(pActionMap + 0x85e) = 0;
  }
  if (*(char *)(pActionMap + 0x82c) == '\0') {
    *(uint16_t *)(pActionMap + 0x826) = 0x24;
    *(uint16_t *)(pActionMap + 0x850) = 0;
    *(uint8_t *)(pActionMap + 0x82b) = 0;
    *(uint8_t *)(pActionMap + 0x82a) = 0;
  }

  // ---------------------------------------------------------------------------
  // SECTION 3: Map / minimap-adjacent (DIK 0x32 = M family; 0x4a)
  // ---------------------------------------------------------------------------
  if (*(char *)(pActionMap + 0x8c8) == '\0') {
    *(uint16_t *)(pActionMap + 0x8c2) = 0x32;
    *(uint16_t *)(pActionMap + 0x8ec) = 0;
    *(uint8_t *)(pActionMap + 0x8c7) = 0;
    *(uint8_t *)(pActionMap + 0x8c6) = 0;
  }
  if (*(char *)(pActionMap + 0xb04) == '\0') {
    *(uint16_t *)(pActionMap + 0xafe) = 0x32;
    *(uint16_t *)(pActionMap + 0xb28) = 0x2a;
    *(uint8_t *)(pActionMap + 0xb03) = 0;
    *(uint8_t *)(pActionMap + 0xb02) = 0;
  }
  if (*(char *)(pActionMap + 0xc70) == '\0') {
    *(uint16_t *)(pActionMap + 0xc6a) = 0x4a;
    *(uint16_t *)(pActionMap + 0xc94) = 0;
    *(uint8_t *)(pActionMap + 0xc6f) = 0;
    *(uint8_t *)(pActionMap + 0xc6e) = 0;
  }

  // ---------------------------------------------------------------------------
  // SECTION 4: QuickBar slots 1–10 — primary DIK 2..0x0B at +0xc9e..
  // (held/edge pair pattern used later by PollBoundActions / OnKeyDown)
  // ---------------------------------------------------------------------------
  if (*(char *)(pActionMap + 0xca4) == '\0') {
    *(uint16_t *)(pActionMap + 0xc9e) = 2;
    *(uint16_t *)(pActionMap + 0xcc8) = 0;
    *(uint8_t *)(pActionMap + 0xca3) = 0;
    *(uint8_t *)(pActionMap + 0xca2) = 0;
  }
  if (*(char *)(pActionMap + 0xcd8) == '\0') {
    *(uint16_t *)(pActionMap + 0xcd2) = 3;
    *(uint16_t *)(pActionMap + 0xcfc) = 0;
    *(uint8_t *)(pActionMap + 0xcd7) = 0;
    *(uint8_t *)(pActionMap + 0xcd6) = 0;
  }
  if (*(char *)(pActionMap + 0xd0c) == '\0') {
    *(uint16_t *)(pActionMap + 0xd06) = 4;
    *(uint16_t *)(pActionMap + 0xd30) = 0;
    *(uint8_t *)(pActionMap + 0xd0b) = 0;
    *(uint8_t *)(pActionMap + 0xd0a) = 0;
  }
  if (*(char *)(pActionMap + 0xd40) == '\0') {
    *(uint16_t *)(pActionMap + 0xd3a) = 5;
    *(uint16_t *)(pActionMap + 0xd64) = 0;
    *(uint8_t *)(pActionMap + 0xd3f) = 0;
    *(uint8_t *)(pActionMap + 0xd3e) = 0;
  }
  if (*(char *)(pActionMap + 0xd74) == '\0') {
    *(uint16_t *)(pActionMap + 0xd6e) = 6;
    *(uint16_t *)(pActionMap + 0xd98) = 0;
    *(uint8_t *)(pActionMap + 0xd73) = 0;
    *(uint8_t *)(pActionMap + 0xd72) = 0;
  }
  if (*(char *)(pActionMap + 0xda8) == '\0') {
    *(uint16_t *)(pActionMap + 0xda2) = 7;
    *(uint16_t *)(pActionMap + 0xdcc) = 0;
    *(uint8_t *)(pActionMap + 0xda7) = 0;
    *(uint8_t *)(pActionMap + 0xda6) = 0;
  }
  if (*(char *)(pActionMap + 0xddc) == '\0') {
    *(uint16_t *)(pActionMap + 0xdd6) = 8;
    *(uint16_t *)(pActionMap + 0xe00) = 0;
    *(uint8_t *)(pActionMap + 0xddb) = 0;
    *(uint8_t *)(pActionMap + 0xdda) = 0;
  }
  if (*(char *)(pActionMap + 0xe10) == '\0') {
    *(uint16_t *)(pActionMap + 0xe0a) = 9;
    *(uint16_t *)(pActionMap + 0xe34) = 0;
    *(uint8_t *)(pActionMap + 0xe0f) = 0;
    *(uint8_t *)(pActionMap + 0xe0e) = 0;
  }
  if (*(char *)(pActionMap + 0xe44) == '\0') {
    *(uint16_t *)(pActionMap + 0xe3e) = 10;
    *(uint16_t *)(pActionMap + 0xe68) = 0;
    *(uint8_t *)(pActionMap + 0xe43) = 0;
    *(uint8_t *)(pActionMap + 0xe42) = 0;
  }
  if (*(char *)(pActionMap + 0xe78) == '\0') {
    *(uint16_t *)(pActionMap + 0xe72) = 0xb;
    *(uint16_t *)(pActionMap + 0xe9c) = 0;
    *(uint8_t *)(pActionMap + 0xe77) = 0;
    *(uint8_t *)(pActionMap + 0xe76) = 0;
  }

  // ---------------------------------------------------------------------------
  // SECTION 5: Shift QuickBar / page binds (primary 2..9 + mod DIK_LSHIFT 0x2a)
  // ---------------------------------------------------------------------------
  if (*(char *)(pActionMap + 0xeac) == '\0') {
    *(uint16_t *)(pActionMap + 0xea6) = 2;
    *(uint16_t *)(pActionMap + 0xed0) = 0x2a;
    *(uint8_t *)(pActionMap + 0xeab) = 0;
    *(uint8_t *)(pActionMap + 0xeaa) = 0;
  }
  if (*(char *)(pActionMap + 0xee0) == '\0') {
    *(uint16_t *)(pActionMap + 0xeda) = 3;
    *(uint16_t *)(pActionMap + 0xf04) = 0x2a;
    *(uint8_t *)(pActionMap + 0xedf) = 0;
    *(uint8_t *)(pActionMap + 0xede) = 0;
  }
  if (*(char *)(pActionMap + 0xf14) == '\0') {
    *(uint16_t *)(pActionMap + 0xf0e) = 4;
    *(uint16_t *)(pActionMap + 0xf38) = 0x2a;
    *(uint8_t *)(pActionMap + 0xf13) = 0;
    *(uint8_t *)(pActionMap + 0xf12) = 0;
  }
  if (*(char *)(pActionMap + 0xf48) == '\0') {
    *(uint16_t *)(pActionMap + 0xf42) = 5;
    *(uint16_t *)(pActionMap + 0xf6c) = 0x2a;
    *(uint8_t *)(pActionMap + 0xf47) = 0;
    *(uint8_t *)(pActionMap + 0xf46) = 0;
  }
  if (*(char *)(pActionMap + 0xf7c) == '\0') {
    *(uint16_t *)(pActionMap + 0xf76) = 6;
    *(uint16_t *)(pActionMap + 4000) = 0x2a; /* 4000 decimal == 0xfa0 — keep decomp form */
    *(uint8_t *)(pActionMap + 0xf7b) = 0;
    *(uint8_t *)(pActionMap + 0xf7a) = 0;
  }
  if (*(char *)(pActionMap + 0xfb0) == '\0') {
    *(uint16_t *)(pActionMap + 0xfaa) = 7;
    *(uint16_t *)(pActionMap + 0xfd4) = 0x2a;
    *(uint8_t *)(pActionMap + 0xfaf) = 0;
    *(uint8_t *)(pActionMap + 0xfae) = 0;
  }
  if (*(char *)(pActionMap + 0xfe4) == '\0') {
    *(uint16_t *)(pActionMap + 0xfde) = 8;
    *(uint16_t *)(pActionMap + 0x1008) = 0x2a;
    *(uint8_t *)(pActionMap + 0xfe3) = 0;
    *(uint8_t *)(pActionMap + 0xfe2) = 0;
  }
  if (*(char *)(pActionMap + 0x1018) == '\0') {
    *(uint16_t *)(pActionMap + 0x1012) = 9;
    *(uint16_t *)(pActionMap + 0x103c) = 0x2a;
    *(uint8_t *)(pActionMap + 0x1017) = 0;
    *(uint8_t *)(pActionMap + 0x1016) = 0;
  }

  // ---------------------------------------------------------------------------
  // SECTION 6: FUN_007f72e0(pActionMap, 2) × 31 then enable bytes (+0x2da..)
  // Helper semantics unresolved — preserve call count/order exactly.
  // ---------------------------------------------------------------------------
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  *(uint8_t *)(pActionMap + 0x2da) = 1;
  *(uint8_t *)(pActionMap + 0x30e) = 1;
  *(uint8_t *)(pActionMap + 0x342) = 1;
  *(uint8_t *)(pActionMap + 0x376) = 1;
  *(uint8_t *)(pActionMap + 0x3aa) = 1;
  *(uint8_t *)(pActionMap + 0x2a6) = 1;
  *(uint8_t *)(pActionMap + 0x3de) = 1;

  // ---------------------------------------------------------------------------
  // SECTION 7: Second FUN_007f72e0(…,2) × 24 then +0x450 = 1
  // ---------------------------------------------------------------------------
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  FUN_007f72e0(pActionMap,2);
  *(uint8_t *)(pActionMap + 0x450) = 1;

  // ---------------------------------------------------------------------------
  // SECTION 8: FUN_007f72e0(…,3) × 19 then return
  // ---------------------------------------------------------------------------
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  FUN_007f72e0(pActionMap,3);
  return;
}
