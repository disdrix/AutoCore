// =============================================================================
// CVOGObject_JustCreatedInit
// -----------------------------------------------------------------------------
// Stable ID: aa_005911b0
// Address:   0x005911b0 – 0x00593233  (autoassault.exe, image base 0x400000)
// System:    client object / physics-gfx spawn finalize
// Generated: 2026-07-29 W22-H dual seal (decompile + read_memory)
// Exactness: Phase-accurate control-flow reconstruction. Full 8KB body lives in
//            FUN_005911b0.cpp (raw decompiler mirror). This file documents the
//            sealed contract for ports without inventing nested physics math.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   "Just created" finalize: apply pose to gfx, skybox particles, ragdoll,
//   rigidbody build/attach, addEntity. Mode 1 = batch force; mode 0 = tick path
//   (may return 0 to defer).
//
// ABI:
//   __thiscall; stack char mode; ret 4; return 1 success/already-done, 0 abort.
//
// STRINGS (evidence):
//   "Just created", "skyboxphase", "SkyBoxParticles", "ragdoll",
//   "RagDoll file read error for <%s>, matching it up with gfxBody <%s>.",
//   "rigidbody", "addEntity", "Unknown"
// =============================================================================

#include <cstdint>

// External helpers (Ghidra names retained where not dual-sealed here)
extern "C" void FUN_0076cf00(const char* section);
extern "C" void FUN_0076cef0(void);
extern "C" void FUN_004a7a20(void** p_self);
// ... remaining callees: see raw W22-H seal / FUN_005911b0.cpp ...

// Object layout fragments (byte offsets)
//   +0x910 bit0  : just-created done latch
//   +0x90c..+0x90f: soft/spawn flags
//   +0x914       : gfx body*
//   +0x260       : rigidbody host*  (param_1[0x98] as int*)
//   +0x818..     : position triad (active/pending)

extern "C" uint32_t __thiscall CVOGObject_JustCreatedInit(void* self, char mode)
{
    // SEH frame LAB_009a595f; large stack (~0x4e8) — elided.
    FUN_0076cf00("Just created");

    auto* bytes = static_cast<uint8_t*>(self);
    auto* dwords = static_cast<uint32_t*>(self);

    // Gate: already finalized
    if ((bytes[0x910] & 1) != 0) {
        FUN_0076cef0();
        return 1;
    }

    // Tick path soft-skip → abort 0
    // Decompiler: mode==0 && (flag@+0x90d bit0 || (flag@+0x90c bit7 && global host live))
    if (mode == 0) {
        const bool soft =
            ((bytes[0x90d] & 1) != 0) ||
            (((bytes[0x90c] & 0x80) != 0) /* && DAT_00b036d4 live — see raw */);
        if (soft) {
            void* tmp = self;
            FUN_004a7a20(&tmp);
            FUN_0076cef0();
            return 0;
        }
    }

    // Copy pending position → active (dwords [0x209..0x20b] → [0x206..0x208])
    dwords[0x206] = dwords[0x209];
    dwords[0x207] = dwords[0x20a];
    dwords[0x208] = dwords[0x20b];

    // --- gfx body present (dwords[0x245] / +0x914) ---
    // orientation flags @+0x90d bits 0x20/0x40/0x80 (random axes via
    // CVOGReaction_RandomUnitScalar * DAT_00aaa638 ≈ 1/65535)
    // apply via gfx vfunc +0x10 and CVOGPhysics_SetPosition/SetRotation helpers
    // skyboxphase: particle list @ gfx+0xc0
    // optional attach FX (FUN_0096dc80) once → @+0x90f |= 1

    // --- optional template scale into dwords[0xa2] ---

    // --- ragdoll once (@+0x90d bit2 set, bit3 clear) ---
    // profile "ragdoll"; load; on failure log RagDoll error string

    // --- rigidbody path ---
    // requires flags + owner phys host; profile "rigidbody"
    // build RB (FUN_00590cb0 / FUN_0058fd30 multi); impulses; "addEntity"

    FUN_0076cef0();
    return 1; // LAB_0059320b: mov al,1; ret 4
}

// Ghidra alias
extern "C" uint32_t __thiscall FUN_005911b0(void* self, char mode)
{
    return CVOGObject_JustCreatedInit(self, mode);
}
