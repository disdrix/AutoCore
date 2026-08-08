// =============================================================================
// Client_NpcMissionDialog_InitRuntimeFields_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab0a0
// Address:   0x008ab0a0 – 0x008ab33d inclusive (670 B / 0x29E)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression (NPC mission dialog host)
// Dual:      R11-035 2026-08-05 accept-with-gaps
// Exactness: Behavior-preserving from live decompile + disassemble_function
//            + read_memory. Not modernization. Bit-for-bit: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Mid-ctor **runtime field init / sentinel pack** for the NPC mission-dialog
//   host (skin `i_d_npc.xml`). Zeros widget/chrome pointers, writes −1 into
//   TFID/id banks (8× response + 4× reward/chrome), installs three default
//   float4s, clears turn-in flag at +0x64c.
//
// ABI (sealed):
//   - thiscall: ECX = NpcMissionDialogHost*
//   - no stack args; plain RET (C3)
//   - frame: SUB ESP,0x10 / PUSH ESI … POP ESI / ADD ESP,0x10
//   - leaf: no callees
//
// Call sites:
//   - Client_NpcMissionDialogHost_Ctor_Inferred @ 008ac505 (MOV ECX,EDI)
//   - DATA: vtbl 0x00a4a51c + 0x3AC @ 0x00a4a8c8
//
// Retired scaffold: Named_CalleeOf_Mission_i_d_npc_xml_008ab0a0
// Ghidra: FUN_008ab0a0
// =============================================================================

#include <cstdint>

struct NpcMissionDialogHost; // size 0x748; vtbl @ 0x00a4a51c

// Image globals (read_memory sealed)
extern float g_flOne;              // 0x00a0f2a0 = 1.0f
extern float DAT_00a0f71c;         // 0.6f
extern float DAT_00aaa7e8;         // 0.157f
extern float DAT_00aaa7e4;         // 0.549f

// Ghidra: FUN_008ab0a0
// thiscall ECX=host; plain RET; leaf
void Client_NpcMissionDialog_InitRuntimeFields_Inferred(NpcMissionDialogHost *host)
{
    auto *b = reinterpret_cast<std::uint8_t *>(host);
    auto *d = reinterpret_cast<std::uint32_t *>(host);
    auto *f = reinterpret_cast<float *>(host);

    // Zero pack (EAX=0 path)
    d[0x4b4 / 4] = 0;
    d[0x4b8 / 4] = 0;
    d[0x4bc / 4] = 0;
    d[0x504 / 4] = 0;
    d[0x508 / 4] = 0;
    d[0x680 / 4] = 0;
    d[0x684 / 4] = 0;
    d[0x688 / 4] = 0;
    d[0x690 / 4] = 0;
    d[0x694 / 4] = 0;
    d[0x6d8 / 4] = 0;
    d[0x6dc / 4] = 0;
    d[0x6e0 / 4] = 0;
    d[0x68c / 4] = 0;
    d[0x6e4 / 4] = 0;
    d[0x6e8 / 4] = 0;
    d[0x700 / 4] = 0;
    d[0x6ec / 4] = 0;
    d[0x6f0 / 4] = 0;
    d[0x6f4 / 4] = 0;
    d[0x6f8 / 4] = 0;
    d[0x6fc / 4] = 0;
    d[0x644 / 4] = 0;
    d[0x510 / 4] = 0; // chrome mode

    // 4× reward/chrome banks: TFID pairs −1, related slots 0
    for (int i = 0; i < 4; ++i) {
        d[(0x558 + i * 8) / 4] = 0xffffffffu;
        d[(0x55c + i * 8) / 4] = 0xffffffffu;
        d[(0x6a8 + i * 4) / 4] = 0;
        d[(0x6b8 + i * 4) / 4] = 0;
        d[(0x6c8 + i * 4) / 4] = 0;
        d[(0x698 + i * 4) / 4] = 0;
    }

    // 8× response TFID pairs (−1,−1) + widget ptrs 0  (+0x518 / +0x708)
    for (int i = 0; i < 8; ++i) {
        d[(0x518 + i * 8) / 4] = 0xffffffffu;
        d[(0x51c + i * 8) / 4] = 0xffffffffu;
        d[(0x708 + i * 4) / 4] = 0;
    }
    d[0x578 / 4] = 0xffffffffu;
    d[0x57c / 4] = 0xffffffffu;

    // Three float4 defaults (image order: +0x594, then +0x584, then +0x5a4)
    f[0x594 / 4 + 0] = 0.0f;
    f[0x594 / 4 + 1] = 0.0f;
    f[0x594 / 4 + 2] = 0.0f;
    f[0x594 / 4 + 3] = DAT_00a0f71c; // 0.6f

    f[0x584 / 4 + 0] = 0.0f;
    f[0x584 / 4 + 1] = g_flOne;      // 1.0f
    f[0x584 / 4 + 2] = 0.0f;
    f[0x584 / 4 + 3] = DAT_00aaa7e8; // 0.157f

    f[0x5a4 / 4 + 0] = 0.0f;
    f[0x5a4 / 4 + 1] = g_flOne;      // 1.0f
    f[0x5a4 / 4 + 2] = 0.0f;
    f[0x5a4 / 4 + 3] = DAT_00aaa7e4; // 0.549f

    // dialogTurnInMode
    b[0x64c] = 0;
}
