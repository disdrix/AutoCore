// =============================================================================
// Client_MaybeShowMultiActiveMissionTip_Inferred
// -----------------------------------------------------------------------------
// Purpose:  After mission accept, traverse the character active-mission hash
//           (singleton+0x540) under HashError traversal lock and, if two or
//           more payloads qualify (short@+0xf8==0 && int@+0xfc!=-1), maybe
//           show first-time tip id 0x20.
//
// Address:  0x008ac7a0  (autoassault.exe, image base 0x400000)
// Body:     0x008ac7a0–0x008ac884 (228 B / 0xE4)
// Stable:   aa_008ac7a0
// System:   missions-progression
// Ghidra:   FUN_008ac7a0
//
// Convention: no formals; plain ret (C3). Tip callee is thiscall on
//             DAT_00d1a840 with stack tipId.
//
// Caller (sole): Client_MissionDialogHandleButton @ call 0x008aec20
//   accept-offer path after GiveMission + Hide + MaybeShowFirstTimeTip(2).
//
// Exactness: CF mirrors live Ghidra decompile 2026-08-04; predicate pair and
// tip threshold sealed via read_memory. Product field English open → _Inferred.
// Dual: reviews/A_aa_008ac7a0_* + B_aa_008ac7a0_*
// Bit-for-bit / runtime: DEFERRED (terminal_coverage=false).
// =============================================================================

#include <cstdint>

extern int DAT_00d1b6d8; // client / character singleton (mission hash host)
extern int DAT_00d1a840; // UI host passed as this to MaybeShowFirstTimeTip

void FUN_007a4480(int channel, const char* msg);
void __thiscall Client_MaybeShowFirstTimeTip(void* uiHost, unsigned tipId);

void Client_MaybeShowMultiActiveMissionTip_Inferred(void)
{
    int hash;
    int count;
    int node;
    int payload;

    if (DAT_00d1b6d8 == 0) {
        return;
    }
    // Early gate: bit0 of byte at singleton+0xd34 must be clear
    if ((*(std::uint8_t*)(DAT_00d1b6d8 + 0xd34) & 1) != 0) {
        return;
    }

    hash  = *(int*)(DAT_00d1b6d8 + 0x540);
    count = 0;
    node  = 0;

    if (*(char*)(hash + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(std::uint8_t*)(hash + 0x1d) = 1;

    while (true) {
        hash = *(int*)(DAT_00d1b6d8 + 0x540);
        if (*(char*)(hash + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        if (node == 0) {
            node = *(int*)(hash + 0x14);
        } else {
            node = *(int*)(node + 0x14);
        }
        if (node == 0) {
            payload = 0;
        } else {
            payload = *(int*)(node + 8);
        }
        if (payload == 0) {
            break;
        }
        // Exact qualifier pair — preserve odd/strict tests
        if ((*(short*)(payload + 0xf8) == 0) &&
            (*(int*)(payload + 0xfc) != -1)) {
            count = count + 1;
        }
    }

    *(std::uint8_t*)(*(int*)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;

    // bytes: cmp count, 2 / jl skip → tip only when count >= 2
    if (count >= 2) {
        Client_MaybeShowFirstTimeTip(reinterpret_cast<void*>(static_cast<std::uintptr_t>(
            static_cast<unsigned>(DAT_00d1a840))), 0x20u);
    }
}
