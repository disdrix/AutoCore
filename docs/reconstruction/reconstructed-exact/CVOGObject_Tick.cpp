// =============================================================================
// CVOGObject_Tick
// -----------------------------------------------------------------------------
// Stable ID: aa_00595230
// Address:   0x00595230 – 0x005960fc  (autoassault.exe, image base 0x400000)
// System:    client object / per-frame tick
// Generated: 2026-07-29 W23-H dual seal (decompile + read_memory)
// Exactness: Phase-accurate control-flow reconstruction. Full ~3.8KB body lives
//            in FUN_00595230.cpp (raw decompiler mirror). This file documents
//            the sealed contract for ports without inventing nested quat math.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Per-frame tick for a CVOG world object:
//     - reaction/phase timer (+0x788) and optional multi-hit flush
//     - lifetime/fade timer (+0x790)
//     - parent/gfx pose sync ("Update Parent Pos")
//     - deferred Just-created init via CVOGObject_JustCreatedInit(mode=0)
//     - velocity cache + gfx writeback
//
// ABI:
//   __thiscall; stack float dt + uint32_t ctx; ret 8.
//
// STRINGS (evidence):
//   "Time etc..", "Update Parent Pos", "Geo found at 0,0,0: %d %I64d"
//
// CONSTANTS (read_memory):
//   DAT_00aaa638 @ 0x00aaa638 = 1/65535
//   DAT_009d51d8 @ 0x009d51d8 = 1e-6
//   g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0 (quat factor)
// =============================================================================

#include <cstdint>

extern "C" void FUN_0076cf00(const char* section);
extern "C" void FUN_0076cef0(void);
extern "C" void __fastcall FUN_004b6980(void* /*fx_or_obj*/);
extern "C" char __thiscall FUN_005911b0(void* self, char mode);
extern "C" void FUN_005942d0(int pulse, uint32_t ctx);
extern "C" void FUN_00593240(int pulse, float* dt_inout);
// ... remaining callees: see raw W23-H seal / FUN_00595230.cpp ...

// Object layout fragments (byte offsets) — see annotated for full table
//   +0x788  phase timer
//   +0x790  lifetime timer
//   +0x90e  soft flags (bit0 destroy, bit3 just-created, bit4 lifetime)
//   +0x911  created-complete byte
//   +0x914  gfx body*

extern "C" void __thiscall CVOGObject_Tick(void* self, float dt, uint32_t ctx)
{
    // SEH LAB_009a5a54; stack align — elided.
    auto* bytes = static_cast<uint8_t*>(self);
    auto* f32 = reinterpret_cast<float*>(self);
    auto* u32 = reinterpret_cast<uint32_t*>(self);

    // (1) stats counters on DAT_00d17958 +0x14c / +0x150 by +0x911
    // (2) optional FUN_00634c50 loop if +0x90d bit1

    int pulse = 0;
    FUN_0076cf00("Time etc..");

    // (3) phase timer
    float t = *reinterpret_cast<float*>(bytes + 0x788) - dt;
    *reinterpret_cast<float*>(bytes + 0x788) = t;
    if (t <= 0.0f) {
        pulse = 1;
        // optional multi-hit flush when reaction node flag & parent present
        // advance this+0x28 via node+0x2f4; maybe early destroy return
        // optional RNG jitter: CVOGReaction_RandomUnitScalar * DAT_00aaa638
        // latch +0x78c = +0x788
    }

    // (4) lifetime path if +0x90e & 0x10 → countdown +0x790; maybe destroy + return

    // (5) full pose path only if +0x911==0 || +0x90e & 8
    if (bytes[0x911] == 0 || (bytes[0x90e] & 0x08) != 0) {
        FUN_0076cef0();
        FUN_0076cf00("Update Parent Pos");

        // (6) pose from gfx +0x914 or parent physics (quat helpers / vfunc 0x1cc)
        // (7) zero-geo warning if |pos|^2 < 1e-6
        // (8) velocity cache +0x854.. from parent or zero

        // (9) just-created pending
        if ((bytes[0x90e] & 0x08) != 0) {
            // delay on +0xbc may copy peer pos; else:
            // char ok = CVOGObject_JustCreatedInit(self, 0);
            // if (!ok) return;
            pulse = 1;
            (void)FUN_005911b0;
        }

        // (10) gfx present: FUN_005942d0(pulse, ctx); velocity or integrate path;
        // clear +0x90e bit3
        (void)FUN_005942d0;
        (void)FUN_00593240;
        (void)f32;
        (void)u32;
        (void)pulse;
        (void)ctx;
        (void)dt;
        (void)FUN_004b6980;
        return;
    }

    FUN_0076cef0();
}
