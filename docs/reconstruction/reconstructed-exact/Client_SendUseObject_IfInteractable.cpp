// =============================================================================
// Client_SendUseObject_IfInteractable
// -----------------------------------------------------------------------------
// Purpose:  Gated C2S UseObject (0x2072, size 0x20). Sends only if interact
//           block flag is clear and (FUN_00524520(character, target) returns
//           non-zero objective id OR clone type at *(obj+0xa8)+0x38 == 4).
//           Returns 1 if pack path taken (even if net null), else 0.
//
// Address:  0x00930d70  (autoassault.exe, image base 0x400000)
// Stable:   aa_00930d70
// System:   interaction-activation
// Generated: 2026-07-29 dual residual strengthen (raw 2026-07-23; bytes seal)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
//
// Convention (decompiler residuals + confirmed bytes):
//   EAX         = target world object*
//   ESI         = client / controller*
//   FUN thiscall ECX = *(client + 0xe98)   // character*  [CONFIRMED]
//
// CRITICAL — IDObjective fill:
//   After allow, body stores EAX (FUN return) to packet+0x18
//   (MOV [ESP+0x1c],EAX with packet base ESP+4). Therefore:
//     • match → wire IDObjective = returned id
//     • type-4 allow with no match → wire IDObjective = 0  (NOT −1)
//   Contrast Client_SendUseObject which writes −1 when no match.
//
// FUN_00524520: walks char active-objectives hash +0x548; match helper
//   FUN_0059d9c0 uses evaluator vtable+0x40; returns objective id (def+0x10)
//   or 0. Not a pure boolean "isInteractable" predicate.
//
// Dual reviews:
//   reviews/A_aa_00930d70_Client_SendUseObject_IfInteractable.md
//   reviews/B_aa_00930d70_Client_SendUseObject_IfInteractable.md
// =============================================================================

#include <cstdint>

// Returns objective id (u32) or 0.
// thiscall: ECX = character* = *(client+0xe98)  [bytes-confirmed at call site]
//           stack arg = target object*
int FUN_00524520(int targetObject);

std::uint32_t Client_SendUseObject_IfInteractable(void)
{
    int in_EAX;     // target object*
    int unaff_ESI;  // client*

    std::uint32_t local_20[2];
    std::uint32_t local_18;
    std::uint32_t local_14;
    std::uint32_t local_10;
    std::uint32_t local_c;
    int local_8; // FUN return → packet+0x18 IDObjective (explicit store)

    // Block flag at *(client+0xe04)+0xf6 must be clear
    if (*(char*)(*(int*)(unaff_ESI + 0xe04) + 0xf6) == '\0') {
        // Bytes: MOV ECX,[ESI+0xe98]; PUSH EDI; CALL FUN_00524520
        local_8 = FUN_00524520(in_EAX);

        // Allow: matching objective id OR clone type == 4
        if ((local_8 != 0) ||
            (*(int*)(*(int*)(in_EAX + 0xa8) + 0x38) == 4)) {

            // TFID_16 — local_8 remains objective dword (store EAX)
            local_18 = *(std::uint32_t*)(in_EAX + 0x160);
            local_14 = *(std::uint32_t*)(in_EAX + 0x164);
            local_10 = *(std::uint32_t*)(in_EAX + 0x168);
            local_c  = *(std::uint32_t*)(in_EAX + 0x16c);
            local_20[0] = 0x2072;

            if (*(int*)(unaff_ESI + 0xc78) != 0) {
                (**(void(**)(std::uint32_t, void*, std::uint32_t, std::uint32_t))(
                    **(int**)(unaff_ESI + 0xc78) + 0x18))(
                    0xffffffffu, local_20, 0x20, 0);
            }
            return 1;
        }
    }
    return 0;
}
