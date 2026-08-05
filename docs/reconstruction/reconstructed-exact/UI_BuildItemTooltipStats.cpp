// =============================================================================
// UI_BuildItemTooltipStats
// -----------------------------------------------------------------------------
// Stable ID: aa_00847ad0
// Address:   0x00847ad0 – 0x0084af04  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / client UI (item tooltips)
// Dual A/B:  2026-07-29 accept-with-gaps
// Exactness: Behavioral contract + sealed ABI/switch/offsets. Full decompiler
//            body lives in FUN_00847ad0.cpp / raw aa_00847ad0 (authoritative CF).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Append type-specific inventory tooltip stat lines to a UI text host.
//   Return the number of lines contributed (int in EAX).
//
// ABI (sealed):
//   ECX = tooltipHost (this)
//   stack: item*, char showDetail, char showExtra
//   epilogue: RET (C3) — caller cleans three stack dwords
//   return: int lineCount
//
// EARLY EXITS:
//   if (DAT_00d1b6d8 == 0) return 0;
//   if (FindActiveObjectiveIdForInteract(...) != 0) {
//     host.vtbl+0x224 append one line; return 1;
//   }
//
// DISPATCH:
//   itemData = *(item + 0xA8);  // item[0x2a]
//   switch (*(uint32*)(itemData + 0x38)) {
//     case 4:
//     case 0x34: break;
//     case 6:    // subtype *(short*)(*(itemData+0x3c)+0x3f4) in {8,10,0xB}
//     case 8:    // three fixed info lines
//     case 10:   // power plant — see offsets below
//     case 0x0C: // weapon / combat stats (detail flags)
//     case 0x0E: // vehicle chassis block
//     case 0x10: // tire / surface friction
//     case 0x1A: // component + skill ids via CNDHash_LookupByKey
//     case 0x1C: // armor / resist shorts
//     case 0x32: // two generic lines
//     default:   item[+0x17C] |= 0x10; FUN_00512670();
//   }
//   // optional modular/req tail if (item[+0x17C] bit19) || DAT_00d1791c
//   return lineCount;
//
// POWER PLANT (type 10) cast object offsets (sealed):
//   +0xB0 HeatMax        (dword)   "%i"
//   +0xB4 PowerMax       (dword)   "%i %s"
//   +0xB8 PowerRegenRate (short)   "%+.02f %s"
//   +0xBA CoolRate       (short)   "%.02f /%s"
//   Plate: regen/cool may display as 1/3 rate — NOT sealed multiply inside this VA.
//
// HOST VFUNCS (slots sealed, product names residual):
//   +0x224 append text; +0x250 spacing/newline; +0x22c req tail; +0x1b8 color node
//
// CALLERS: FUN_00843a60, FUN_0084b890, FUN_0088d980 (xrefs @ 843ea2, 84c0dc, 88da41, 88daf6)
//
// NOT: network equip, skill cast, server combat resolution.
// Full line-by-line port: use raw decompile; do not trust operator_delete no-return noise.
// =============================================================================

// Placeholder for ports: implement type-switch formatters against localization table.
// Authoritative control flow remains the Ghidra decompile in:
//   docs/reconstruction/raw/aa_00847ad0_FUN_00847ad0.md
//   docs/reconstruction/reconstructed-exact/FUN_00847ad0.cpp

int UI_BuildItemTooltipStats(void *tooltipHost /*ECX*/,
                             void *item,
                             char showDetail,
                             char showExtra);
