// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, CVOGCharacter_WeaponAllowsKillXpBonus, context.
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_WeaponAllowsKillXpBonus
// -----------------------------------------------------------------------------
// Purpose:  Boolean gate used by kill-path XP (spree table in AddExperience) and
//           by mission bookkeeping (completed/instance hash selection).
//
// Address:  0x004ce340  (autoassault.exe, image base 0x400000)
// Stable:   aa_004ce340
// System:   missions-progression  (also kill-XP path)
//
// Convention: MSVC __thiscall (assembly: uses ECX; RET with AL)
//   this  = object with flags at +0x100 / mode int at +0xac
//           (callers pass no stack args; ECX set by caller)
//
// Returns:  1 if gate open, 0 if closed (bool in AL)
//
// Body (11 instructions, no callees):
//   LEA EAX,[ECX+0xa0]; TEST EAX,EAX; JZ fail   // this+0xa0 non-null (always for valid this)
//   CMP byte [ECX+0x100], 0; JNZ fail            // flag at +0x100 must be 0
//   CMP dword [ECX+0xac], 2; JZ fail             // mode at +0xac must not be 2
//   MOV AL,1 / XOR AL,AL
//
// Naming note: Ghidra / XP.md name implies "weapon allows kill XP bonus".
// The body has NO weapon lookup - only two object fields. Same gate is reused
// in HasCompletedMission / GiveMission as a dual-hash policy switch. Treat the
// retail name as historical; semantics = "mode / eligibility flag pair".
//
// Exactness: Control flow mirrors raw decompile + verified disassembly listing.
// =============================================================================

#include <cstdint>

// Field map on `this` (INFERRED from use; type of object not fully recovered):
//   +0x0a0  - LEA target only (null-ish check; effectively always true for live objects)
//   +0x0ac  - int mode / kind; gate closed when == 2
//   +0x100  - char flag; gate closed when != 0

// Returns non-zero (1) when kill-path weapon-bonus table path may run, and when
// mission code selects the "+0x53c" instance-style completed hash policy.
bool __thiscall CVOGCharacter_WeaponAllowsKillXpBonus(void* thisObject)
{
    // Assembly: LEA EAX,[ECX+0xa0]; TEST EAX,EAX; JZ fail
    // Ghidra surface: (param_1 + 0xa0 != 0). Preserved as written.
    if ((int)thisObject + 0xa0 == 0) {
        return false;
    }

    // Flag at +0x100 must be clear
    if (*(char*)((int)thisObject + 0x100) != '\0') {
        return false;
    }

    // Mode at +0xac must not be 2
    if (*(int*)((int)thisObject + 0xac) == 2) {
        return false;
    }

    return true;
}
