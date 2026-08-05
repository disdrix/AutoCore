// =============================================================================
// StatusFlag_GetDisplayName
// -----------------------------------------------------------------------------
// Stable ID: aa_00580a20
// Address:   0x00580a20 – 0x00580ac0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / status UI
// Generated: 2026-07-29 W19-T dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prior scaffold names: FUN_00580a20, Combat_Weapons_Disabled (plate-string misname).
// =============================================================================
//
// PURPOSE: Map a single status-flag key (power-of-two bit value) to the product
// English display name used by cast-block toasts and related UI.
//
// ABI: one stack int; returns const char* in EAX; plain RET.
// Default for unknown keys: "in a world of hurt".
//
// Flag key table (value → string):
//   0x00001  GM Frozen
//   0x00002  Stunned
//   0x00004  Locked Down
//   0x00008  Silenced
//   0x00010  Weapons Disabled
//   0x00020  GM Chat Banned
//   0x00040  Afraid
//   0x00080  Confused
//   0x00200  Blind
//   0x01000  Slowed
//   0x02000  Immune to death
//   0x04000  Speeding
//   0x10000  Zombied
// =============================================================================

const char * StatusFlag_GetDisplayName(int flagValue)
{
  if (flagValue < 0x41) {
    if (flagValue == 0x40) {
      return "Afraid";
    }
    switch (flagValue) {
    case 1:
      return "GM Frozen";
    case 2:
      return "Stunned";
    case 4:
      return "Locked Down";
    case 8:
      return "Silenced";
    case 0x10:
      return "Weapons Disabled";
    case 0x20:
      return "GM Chat Banned";
    }
  }
  else if (flagValue < 0x2001) {
    if (flagValue == 0x2000) {
      return "Immune to death";
    }
    if (flagValue == 0x80) {
      return "Confused";
    }
    if (flagValue == 0x200) {
      return "Blind";
    }
    if (flagValue == 0x1000) {
      return "Slowed";
    }
  }
  else {
    if (flagValue == 0x4000) {
      return "Speeding";
    }
    if (flagValue == 0x10000) {
      return "Zombied";
    }
  }
  return "in a world of hurt";
}
