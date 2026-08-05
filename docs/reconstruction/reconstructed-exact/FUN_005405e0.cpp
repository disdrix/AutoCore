// =============================================================================
// Client_IsRequirementEventActive  (FUN_005405e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005405e0
// Address:   0x005405e0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Dual:      A/B 2026-07-29 — CF/ABI/membership sealed; product English open
// Exactness: Behavior-preserving rewrite of decompiler + assembly-backed returns.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Linear membership: is requirementEventId in global active-event vector
//   [DAT_00b04718, DAT_00b0471c)? Returns 1 if found else 0.
//   Sole caller: CheckMissionRequirements when mission+0x118 != -1.
//
// Convention: MSVC __cdecl
//   stack0 = requirementEventId (int)
//   return = bool in AL
//   bare RET (caller ADD ESP,4)

#include <cstdint>

// Global active RequirementEventId vector (begin / exclusive end).
extern int* DAT_00b04718;
extern int* DAT_00b0471c;

bool /*AL*/ __cdecl Client_IsRequirementEventActive(int requirementEventId)
{
    int* p = DAT_00b04718;
    int* end = DAT_00b0471c;

    if (p == end) {
        return false;
    }
    for (; p != end; ++p) {
        if (*p == requirementEventId) {
            return true;
        }
    }
    return false;
}

// Ghidra symbol alias (scaffold name preserved for xref search)
// Note: decompiler CONCAT31 form is noise — live returns AL only.
unsigned __cdecl FUN_005405e0(int requirementEventId)
{
    return Client_IsRequirementEventActive(requirementEventId) ? 1u : 0u;
}
