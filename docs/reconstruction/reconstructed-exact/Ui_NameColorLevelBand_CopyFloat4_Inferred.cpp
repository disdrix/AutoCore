// =============================================================================
// Ui_NameColorLevelBand_CopyFloat4_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092d580
// Address:   0x0092d580–0x0092d5fb
// Module:    autoassault.exe (image base 0x400000)
// System:    client UI / entity name-label color
// Generated: 2026-08-04 WQ9E-C dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Select a 16-byte float4 color band from host tables at +0xBE4..+0xC54
// based on signed levelDiff, and copy it to the caller's out buffer. Leaf helper
// of Ui_ResolveEntityNameColor_Inferred (level-pack path) and mission UI color
// paths (Client_NpcDialog_PrepareResponseOpcode, journal helpers).
//
// ABI (register):
//   ECX = host object (band table base)
//   EDX = int levelDiff (signed)
//   EAX = float out[4]  (16 B destination)
//   bare ret; EAX preserved as out
//
// Bands (signed levelDiff → host offset, stride 0x10):
//   <=-5 → +0xBE4 | -4..-3 → +0xBF4 | -2..-1 → +0xC04 | 0 → +0xC14
//   1..2 → +0xC24 | 3..4 → +0xC34 | 5..6 → +0xC44 | >=7 → +0xC54
//
// Parent pack (0x00930fc0): RGB channels × 255.0f (DAT_00aaa6f8), A = 0xFF.
//

#include <cstdint>

extern "C" float* __fastcall Ui_NameColorLevelBand_CopyFloat4_Inferred(
    void* host /*ECX*/,
    int levelDiff /*EDX*/,
    float* out /*EAX — nonstandard third channel*/) {
  const uint32_t* slot;
  if (levelDiff >= 7) {
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xC54);
  } else if (levelDiff >= 5) {
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xC44);
  } else if (levelDiff >= 3) {
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xC34);
  } else if (levelDiff >= 1) {
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xC24);
  } else if (levelDiff < -4) { // <= -5
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xBE4);
  } else if (levelDiff < -2) { // -4, -3
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xBF4);
  } else if (levelDiff < 0) { // -2, -1  (matches bytes: edx<=-1 → +0xC04)
    // Decompiler groups via unsigned compare; bytes:
    //   cmp edx,-1; jg → +0xC14 (only 0 remains); else +0xC04 for -2/-1
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xC04);
  } else { // 0
    slot = reinterpret_cast<const uint32_t*>(static_cast<char*>(host) + 0xC14);
  }

  auto* dst = reinterpret_cast<uint32_t*>(out);
  dst[0] = slot[0];
  dst[1] = slot[1];
  dst[2] = slot[2];
  dst[3] = slot[3];
  return out;
}
