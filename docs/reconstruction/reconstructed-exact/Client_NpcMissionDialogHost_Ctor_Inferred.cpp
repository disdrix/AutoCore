// =============================================================================
// Client_NpcMissionDialogHost_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac3f0
// Address:   0x008ac3f0 – 0x008ac53f inclusive last RET byte (336 B / 0x150)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression (client NPC mission dialog host)
// Dual:      MEGA-107 2026-08-05 accept-with-gaps
// Exactness: Behavior-preserving from live decompile + read_memory.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct the NPC mission-dialog host object later stored at
//   client+0x1058 (dialog table index 10). Sole caller FUN_0093e7e0 does
//   operator_new(0x748) then this ctor.
//
// ABI (bytes):
//   - Stack arg: MissionDialogHost* this  (loaded to EDI; not ECX thiscall)
//   - Base: FUN_0087b890(this, 0)
//   - Return: EAX = this
//   - Epilogue: RET 4
//   - SEH: LAB_009b645d
//
// Class:
//   *this = vtable 0x00a4a51c (PTR_FUN_00a4a51c)
//   Known sibling methods on same vtbl:
//     +0x43C → Client_BuildNpcMissionDialogWidgets (0x008ad240)
//     +0x440 → Client_MissionDialog_FlushPreparedResponse (0x008ab8f0)
//     +0x34C → FUN_00791dc0 (post-XML virtual called at end of this ctor)
//
// Retired name: Mission_i_d_npc_xml_008ac3f0 (string-only scaffold)

#include <cstdint>

struct NpcMissionDialogHost; // size 0x748; vtbl @ 0x00a4a51c

extern float g_flOne; // 0x00a0f2a0 = 1.0f

// Base NDUI / window host ctor (arg1 stored on base object).
extern std::uint32_t* FUN_0087b890(std::uint32_t* self, std::uint32_t arg1);

// Mission-dialog field zero / sentinel pack (ECX = self).
extern void FUN_008ab0a0();

// Reload NDUI skin from XML (string push + call 0x00792980).
extern void NDUIWindow_ReloadInterface(const char* xml_name);

// Dualed: build i_d_npc_2d_btn_response.xml grid (EDI = self).
extern void UI_MissionDialog_BuildResponseButtons_Inferred();

// Ghidra: FUN_008ac3f0
// Stack this* → EDI; RET 4; EAX = this
NpcMissionDialogHost* Client_NpcMissionDialogHost_Ctor_Inferred(
    NpcMissionDialogHost* self /* stack */)
{
    // SEH frame: local_4=-1; puStack_8=&LAB_009b645d; link ExceptionList

    FUN_0087b890(reinterpret_cast<std::uint32_t*>(self), 0);

    auto* w = reinterpret_cast<std::uint32_t*>(self);

    // Install mission-dialog vtable
    w[0] = 0x00a4a51c; // PTR_FUN_00a4a51c

    // 3×4 float basis at +0x584 (indices 0x161..0x16c): three (0,0,0,1) rows
    float* basis = reinterpret_cast<float*>(w + 0x161);
    for (int row = 0; row < 3; ++row) {
        basis[row * 4 + 0] = 0.0f;
        basis[row * 4 + 1] = 0.0f;
        basis[row * 4 + 2] = 0.0f;
        basis[row * 4 + 3] = g_flOne; // 1.0f
    }

    // Trailing dword zeros (skip 0x1ce)
    w[0x1cb] = 0; // +0x72C
    w[0x1cc] = 0; // +0x730
    w[0x1cd] = 0; // +0x734
    w[0x1cf] = 0; // +0x73C
    w[0x1d0] = 0; // +0x740
    w[0x1d1] = 0; // +0x744

    // SEH state → 2 around remaining inits
    w[0x13f] = 0x0C; // +0x4FC  dialog chrome / type id
    w[0x140] = 1;    // +0x500
    w[0x192] = 0;    // +0x648  layout mode
    w[0x143] = 0;    // +0x50C  (stored via movss 0 in image)
    w[399]   = 1;    // +0x63C
    w[400]   = 1;    // +0x640  response columns default
    w[0x145] = 0;    // +0x514
    *reinterpret_cast<std::uint8_t*>(w + 0x160) = 0; // +0x580
    w[0x1c1] = 0;    // +0x704
    w[0x170] = 0;    // +0x5C0  layout extra Y
    w[0x16f] = 0;    // +0x5BC  layout extra X

    // ECX = self for these (image: mov ecx, edi)
    FUN_008ab0a0();
    NDUIWindow_ReloadInterface("i_d_npc.xml");
    UI_MissionDialog_BuildResponseButtons_Inferred(); // EDI-this body

    // Virtual post-init: call [vtbl+0x34C] → FUN_00791dc0 (ECX = self)
    using VFn = void(__fastcall*)(NpcMissionDialogHost* /*ecx*/);
    auto** vtbl = *reinterpret_cast<VFn***>(self);
    vtbl[0x34C / 4](self);

    return self; // RET 4
}
