// =============================================================================
// Client_SetModeLatch493_ParkDriveOnClear_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Virtual thiscall on client host: set/clear mode latch +0x493.
//           On clear (enable==0) while latched: UI/camera cleanup, park drive
//           via StopHb+ZeroLongitudinal, optional cursor-host notify(0).
//           On enable while unlatched: optional cursor-host notify(1).
//           Always: zero f32 at +0x538, then FUN_007902a0(this, enable).
//
// Address:  0x00914c60  (autoassault.exe, image base 0x400000)
// Body:     0x00914c60–0x00914ce5 inclusive (134 B / 0x86); pad CC after RET 4
// Stable:   aa_00914c60
// System:   input-drive-control
// Ghidra:   FUN_00914c60
//
// ABI:      thiscall ECX = client host; stack arg enable (char low byte);
//           RET 4 (stdcall cleanup of 1 stack dword).
//           Clear-path Stop leaf: MOV EAX,EDI ; CALL 0x00914c20 (EAX host).
//           Clear-path UI helper: ESI = &DAT_00d1a840 ; CALL 0x007fb990.
//
// Does NOT: write steer/long axes itself (delegates park to 00914c20);
//           direct CALL sites (vtable DATA only @ 0x00a2f468).
//
// Parent/callee (clear path):
//   Client_Vehicle_StopHbAndZeroLongitudinal_Inferred  0x00914c20  aa_00914c20
//
// Other callees:
//   FUN_007fb990  0x007fb990  (ESI global client; residual scaffold)
//   FUN_007902a0  0x007902a0  (apply +0x493 latch; residual scaffold)
//   DAT_00d1b9a8->vtbl[+0xd0] query ; DAT_00d1b9a8->vtbl[+4] notify
//
// Exactness: CF ≡ live decompile + disassemble_function + read_memory 2026-08-05.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B R11-037: accept-with-gaps.
// =============================================================================

#include <cstdint>

extern std::uint8_t  DAT_00d1a840[];   // global client object storage
extern int*          DAT_00d1b9a8;     // cursor / UI host

// Clear-path only. Register-carried host in EAX (not ECX). Dual-sealed MEGA-098.
void Client_Vehicle_StopHbAndZeroLongitudinal_Inferred(void* /*EAX*/ host);

// ESI = &DAT_00d1a840 at call site. Residual scaffold.
void FUN_007fb990(void);

// thiscall ECX=client, stack char enable. Residual scaffold.
void __thiscall FUN_007902a0(void* /*ECX*/ client, char enable);

void __thiscall Client_SetModeLatch493_ParkDriveOnClear_Inferred(
    void* client /* ECX */,
    std::uint32_t enable_raw /* stack */)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(client);
    const char enable = static_cast<char>(enable_raw);
    unsigned notify_arg = 0;

    if (enable == 0) {
        // cmp [edi+0x493],0 / jz common
        if (base[0x493] == 0) {
            goto common;
        }
        // push esi ; mov esi, 0x00d1a840 ; call FUN_007fb990
        // (ESI host for residual helper — global client singleton)
        (void)DAT_00d1a840;
        FUN_007fb990();

        // mov eax, edi ; call Client_Vehicle_StopHbAndZeroLongitudinal_Inferred
        Client_Vehicle_StopHbAndZeroLongitudinal_Inferred(client);

        if (DAT_00d1b9a8 == nullptr) {
            goto common;
        }
        {
            auto** vtbl = reinterpret_cast<void**>(*DAT_00d1b9a8);
            using QueryFn = char(__thiscall*)(int*);
            char q = reinterpret_cast<QueryFn>(vtbl[0xd0 / 4])(DAT_00d1b9a8);
            if (q == 0) {
                goto common;
            }
            notify_arg = 0;
        }
    } else {
        // enable: require latch clear AND host present
        if (base[0x493] != 0 || DAT_00d1b9a8 == nullptr) {
            goto common;
        }
        {
            auto** vtbl = reinterpret_cast<void**>(*DAT_00d1b9a8);
            using QueryFn = char(__thiscall*)(int*);
            char q = reinterpret_cast<QueryFn>(vtbl[0xd0 / 4])(DAT_00d1b9a8);
            if (q != 0) {
                goto common;
            }
            notify_arg = 1;
        }
    }

    // mov ecx, DAT_00d1b9a8 ; call [vtbl+4](notify_arg)
    {
        auto** vtbl = reinterpret_cast<void**>(*DAT_00d1b9a8);
        using NotifyFn = void(__thiscall*)(int*, unsigned);
        reinterpret_cast<NotifyFn>(vtbl[4 / 4])(DAT_00d1b9a8, notify_arg);
    }

common:
    // xorps xmm0,xmm0 ; movss [edi+0x538], xmm0
    *reinterpret_cast<float*>(base + 0x538) = 0.0f;

    // push ebx (enable) ; mov ecx, edi ; call FUN_007902a0
    FUN_007902a0(client, enable);
    // pop edi ; pop ebx ; ret 4
}
