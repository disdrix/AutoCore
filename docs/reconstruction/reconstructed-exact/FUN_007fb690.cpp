// =============================================================================
// Client_ShowTimedProgressBar_Inferred  (Ghidra: FUN_007fb690)
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb690
// Address:   0x007fb690  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client-ui (shared timed progress chrome)
// Generated: 2026-07-23 scaffold; 2026-07-29 dual OWN-ONLY (asm ABI seal)
// Exactness: Behavior-preserving rewrite of decompiler + disassembly control flow.
//            Not modernization. Not a compile target.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Show/configure the client timed progress bar at client+0x1120.
//   Dismisses any prior bar via FUN_007fb640, then programs title, status text,
//   three color channels, start value, max=1.0, fill rate (1-start)/durationSec,
//   show, and refresh.
//
//   Multi-use chrome (not skill-only):
//     RequestCast / QB charge → "...Activating Skill..."
//     Other sites → "Working..", "Contacting INC...", "Training Discipline", "Crafting"
//
// ABI (asm Confirmed 2026-07-29):
//   - Client object in EAX on entry (prologue: PUSH ESI; MOV ESI,EAX).
//   - stdcall RET 0x20 → eight stack dwords.
//
// READABILITY (CF):
//   - Linear vtbl fan-out after dual gate (+0x1120 and +0xf40).
//   - Direct callee: FUN_007fb640 only.
//   - Return: POP ESI; RET 0x20.

#include <cstdint>

extern "C" float g_flOne; // VA 0x00a0f2a0 → 1.0f (read_memory 00 00 80 3f)

// Sibling dismiss: if client+0x1120 live and vtbl+0x3d8 truthy → detach/hide.
// Retail receives client in ESI (set by our prologue before CALL).
extern "C" void FUN_007fb640(void);

/*
 * Behavioral notes:
 * - Decompiler freeze showed 3 formals + stack0 phantoms; asm has 8 stdcall args.
 * - Rate formula uses MOVSS/SUBSS/DIVSS on arg0/arg1 with g_flOne — not integer 2.
 * - colorCh* are dwords passed by pointer into vtbl+0x15c(channel, &dword).
 * - Runtime / differential verification: OPEN.
 */

// Claim name: Client_ShowTimedProgressBar_Inferred
// Prior scaffold alias: Named_CalleeOf_Client_RequestCastSkill_007fb690
void __stdcall FUN_007fb690(
    /* EAX = client* on entry — not a stack formal */
    float startOrMode,            // [ESP+0x04] after retaddr; vtbl+0x454 + rate numerator
    float durationSec,            // rate divisor
    void* titleSrc,               // vtbl+0x468(titleSrc, 1) — cast path: skill+0x184
    char* statusText,             // vtbl+0x46c(statusText, 1)
    std::uint32_t colorCh1,       // vtbl+0x15c(1, &ch1) — often *DAT_00afdf08
    std::uint32_t colorCh0,       // vtbl+0x15c(0, &ch0) — cast path 0xFF400000
    std::uint32_t colorCh2,       // vtbl+0x15c(2, &ch2) — often 0
    std::uint32_t extra)          // vtbl+0x464(extra) — often 0
{
    // Retail prologue binds client from EAX into ESI for the whole body.
    // Model as explicit first local recovered from EAX:
    int* client = /* EAX */ nullptr; // callers: EDI / DAT_00d1a840 / EBX → EAX

    FUN_007fb640(); // ESI=client

    int* progressBar = *reinterpret_cast<int**>(reinterpret_cast<char*>(client) + 0x1120);
    int* uiHostSlot  = *reinterpret_cast<int**>(reinterpret_cast<char*>(client) + 0xf40);

    if (progressBar == nullptr || uiHostSlot == nullptr) {
        return;
    }

    // --- optional host attach when *uiHostSlot live ---
    if (*uiHostSlot != 0) {
        int* host = reinterpret_cast<int*>(*uiHostSlot);
        int* hv = reinterpret_cast<int*>(*host);
        reinterpret_cast<void(__thiscall*)(int*)>(hv[0x3ec / 4])(host);
        reinterpret_cast<void(__thiscall*)(int*, int)>(hv[0x3f4 / 4])(host, 1);
        reinterpret_cast<void(__thiscall*)(int*, int*)>(hv[0xa8 / 4])(host, progressBar);
    }

    int* bar = progressBar;
    int* bv  = reinterpret_cast<int*>(*bar);

    reinterpret_cast<void(__thiscall*)(int*)>(bv[0x43c / 4])(bar);
    reinterpret_cast<void(__thiscall*)(int*, void*, int)>(bv[0x468 / 4])(bar, titleSrc, 1);
    reinterpret_cast<void(__thiscall*)(int*, char*, int)>(bv[0x46c / 4])(bar, statusText, 1);

    // Channel order sealed by asm: (0,&arg5), (1,&arg4), (2,&arg6)
    reinterpret_cast<void(__thiscall*)(int*, int, std::uint32_t*)>(bv[0x15c / 4])(
        bar, 0, &colorCh0);
    reinterpret_cast<void(__thiscall*)(int*, int, std::uint32_t*)>(bv[0x15c / 4])(
        bar, 1, &colorCh1);
    reinterpret_cast<void(__thiscall*)(int*, int, std::uint32_t*)>(bv[0x15c / 4])(
        bar, 2, &colorCh2);

    reinterpret_cast<void(__thiscall*)(int*, float)>(bv[0x454 / 4])(bar, startOrMode);
    reinterpret_cast<void(__thiscall*)(int*, float)>(bv[0x450 / 4])(bar, 1.0f); // 0x3f800000

    // (g_flOne - startOrMode) / durationSec
    float rate = (g_flOne - startOrMode) / durationSec;
    reinterpret_cast<void(__thiscall*)(int*, float)>(bv[0x460 / 4])(bar, rate);
    reinterpret_cast<void(__thiscall*)(int*, std::uint32_t)>(bv[0x464 / 4])(bar, extra);
    reinterpret_cast<void(__thiscall*)(int*, int)>(bv[0xcc / 4])(bar, 1);
    reinterpret_cast<void(__thiscall*)(int*)>(bv[0x34c / 4])(bar);
}
