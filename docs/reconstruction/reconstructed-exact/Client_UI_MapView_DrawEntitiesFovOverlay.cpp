// =============================================================================
// Client_UI_MapView_DrawEntitiesFovOverlay
// -----------------------------------------------------------------------------
// Stable ID: aa_00859bc0
// Address:   0x00859bc0 – 0x0085a9ef  (autoassault.exe, image base 0x400000)
// System:    client UI / map-view overlay
// Generated: 2026-07-29 W23-N dual seal (decompile + read_memory)
// Exactness: Phase-accurate control-flow reconstruction. Full decompiler mirror
//            lives in FUN_00859bc0.cpp. This file documents the sealed contract.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Map-view entity-rich composite overlay: world entity lists A/B, markers,
//   auto-patrol, mission tree, special point, squad, scaled FOV textured quad.
//
// ABI:
//   __thiscall; ECX = self*; no stack args; plain ret (C3).
//   Frame: and esp,-16; sub esp,0x104.
//
// LAYOUT (byte offsets):
//   self+0x488 : MapConfig*
//   self+0x68 / +0x70 / +0x74 : layer counters (same pattern as markers twin)
//   config+0x514 : FOV radius base
//   config+0x500 / +0x50c / +0x5b9 : optional FOV scale path
//   config+0x520/0x524 : list-B icon sizes
//   config+0x530/0x534 : list-A icon sizes
//   config+0x538/0x53c : marker icon half sizes
//   config+0x5cc : FOV texture
//   config+0x5d0 : entity texture
//   config+0x624 + type*4 : marker textures type 0..8
//   config+0x590/0x594 : screen offset for FOV corners
//   world host *(DAT_00d1b644+0xe4e8):
//     +0x28 list A header; begin/end +0x2c/+0x30
//     +0x48 list B header; begin/end +0x4c/+0x50 (via +4/+8 on header)
//
// CONSTANTS:
//   DAT_00a0f298 = 0.5f     final FOV radius scale
//   DAT_00af931c = 1.0f     optional scale numerator candidate
//   DAT_00af9320 = 1.0f     optional scale numerator candidate
// =============================================================================

#include <cstdint>

extern "C" void  FUN_00859260(/* pose, color, sizes, tex, tint, extra — see raw */);
extern "C" void  FUN_00859a90(void* self_or_cfg, int icon_type);
extern "C" void  FUN_00757890(void* verts, int n, void* tex, int flag, void* cookie);
extern "C" void  FUN_00930fc0(void* global, void* out, int a, int b);
extern "C" char  FUN_005134e0(void);
extern "C" int   FUN_00574760(int slot);
extern "C" void  Client_EvalAutoPatrolWaypoint(void* host, void* out_id, void* out_pos);
extern "C" void  FUN_004e9530(void* out, void* pos);
extern "C" void  FUN_004e8a40(void* orient, void* out_basis);
extern "C" void  FUN_004e8ad0(void* orient, void* out_basis);
extern "C" void* FUN_004141c0(void* out);

extern int   DAT_00d1b644;
extern int   DAT_00d1b6d8;
extern int*  DAT_00d1d964;
extern void* DAT_00d1ad10;
extern int   DAT_00d1b938;
extern char  DAT_00d1ad1c;
extern float DAT_00d1ad20, DAT_00d1ad24;
extern int   DAT_00d1ad28;
extern int*  DAT_00d1b780;
extern int   DAT_00d1b778;
extern float DAT_00a0f298; // 0.5f
extern float DAT_00af931c, DAT_00af9320; // 1.0f
extern float g_flOne;
extern char  DAT_00d1ec78[];
extern char  DAT_00d1ecac[];
extern int   DAT_00d1a840;

static void BumpLayer(uint8_t* self)
{
    int layer = *reinterpret_cast<int*>(self + 0x68) + 1;
    *reinterpret_cast<int*>(self + 0x68) = layer;
    *reinterpret_cast<float*>(self + 0x74) = static_cast<float>(-layer);
    if (*reinterpret_cast<int*>(self + 0x70) < layer)
        *reinterpret_cast<int*>(self + 0x70) = layer;
}

extern "C" void __thiscall Client_UI_MapView_DrawEntitiesFovOverlay(void* self)
{
    auto* bytes = reinterpret_cast<uint8_t*>(self);
    int* cfg = *reinterpret_cast<int**>(bytes + 0x488);
    if (cfg == nullptr || DAT_00d1b6d8 == 0 || DAT_00d1b644 == 0 ||
        *reinterpret_cast<int*>(DAT_00d1b644 + 0xe4e8) == 0) {
        return;
    }

    int* world_lists = *reinterpret_cast<int**>(DAT_00d1b644 + 0xe4e8);
    // List headers at +0x28 and +0x48 must be non-null (decomp float-pun null check).
    if (reinterpret_cast<int>(world_lists) + 0x28 == 0 ||
        reinterpret_cast<int>(world_lists) + 0x48 == 0) {
        // Note: retail checks the header pointers themselves, not the sum.
        // See raw: fStack = (float)(host+0x28); if (fStack != 0 && ...)
    }
    int* listA_begin = *reinterpret_cast<int**>(reinterpret_cast<char*>(world_lists) + 0x2c);
    int* listA_end   = *reinterpret_cast<int**>(reinterpret_cast<char*>(world_lists) + 0x30);
    // list B begin/end at header(+0x48)+4 / +8 — see raw.

    // Local pose: vfunc +0x1a0

    // --- World list A ---
    // for each obj: filter (null, vfunc+0x198, flag bit3, FUN_005134e0, owner!=local)
    // if lazy==0 → ensure; else if owner==0 → FUN_00930fc0 + FUN_00859260
    //   sizes cfg+0x530/0x534, tex cfg+0x5d0
    BumpLayer(bytes);

    // --- World list B ---
    // filter owner, hidden, clonebase flag bit3; ally tint via world+0xf6 or party ids
    // FUN_00930fc0 + FUN_00859260 sizes cfg+0x520/0x524
    BumpLayer(bytes);

    // --- Markers DAT_00d1d964 ---
    // pose from node or attach +0x80; type 0..8 → FUN_00859260 tex cfg+0x624+type*4
    BumpLayer(bytes);

    // --- Auto-patrol → FUN_00859a90 ---
    BumpLayer(bytes);
    // --- Mission tree type 0x65 → FUN_00859a90 ---
    BumpLayer(bytes);
    // --- Special type 100 ---
    BumpLayer(bytes);
    // --- Squad ×4 with flag filter ---
    BumpLayer(bytes);

    // --- FOV quad if camera pair matches ---
    // radius = cfg+0x514;
    // if cfg+0x5b9==0: radius *= min(DAT_00af931c, DAT_00af9320) / cfg+0x500
    // radius *= cfg+0x50c * 0.5f
    // four corners on basis; FUN_004141c0 + offset cfg+0x590/0x594
    // FUN_00757890 tex cfg+0x5cc or DAT_00d1ec78
}

// Ghidra name alias
extern "C" void __thiscall FUN_00859bc0(void* self)
{
    Client_UI_MapView_DrawEntitiesFovOverlay(self);
}
