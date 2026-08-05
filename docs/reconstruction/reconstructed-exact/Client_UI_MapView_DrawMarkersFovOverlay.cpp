// =============================================================================
// Client_UI_MapView_DrawMarkersFovOverlay
// -----------------------------------------------------------------------------
// Stable ID: aa_00851630
// Address:   0x00851630 – 0x00852428  (autoassault.exe, image base 0x400000)
// System:    client UI / map-view overlay
// Generated: 2026-07-29 W23-N dual seal (decompile + read_memory)
// Exactness: Phase-accurate control-flow reconstruction. Full decompiler mirror
//            lives in FUN_00851630.cpp. This file documents the sealed contract.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Map-view composite overlay: markers, auto-patrol, mission tree, special
//   point, squad icons, player FOV textured quad + optional radar cone.
//
// ABI:
//   __thiscall; ECX = self*; no stack args; plain ret (C3).
//   Frame: and esp,-16; sub esp,0x164.
//
// LAYOUT (byte offsets on self / config):
//   self+0x488 : MapConfig*
//   self+0x224 : optional RGBA tint cookie*
//   self+0x68  : layer counter (++ between phases)
//   self+0x70  : layer max
//   self+0x74  : (float)-layer
//   config+0x4fc : enable flag (char)
//   config+0x514 : FOV/cone angle param (float)
//   config+0x538 / +0x53c : icon half W/H
//   config+0x5a0 / +0x5a4 : FOV / cone textures
//   config+0x600 + type*4 : marker textures type 0..8
//
// CONSTANTS:
//   DAT_00aaa8a8 = 300.0f   FOV half-extent scale
//   DAT_00aaa6c4 = 2.5f     cone sin argument scale
//   DAT_00a0f694 = 30.0f    cone size scale
//   DAT_00aaa678 ≈ 1/1200   cone Y scale
//   DAT_00aaa67c ≈ 1/1600   cone X scale
// =============================================================================

#include <cstdint>

// External helpers (Ghidra names; dual out of OWN scope)
extern "C" void* FUN_0084f610(void* pose_or_out);
extern "C" void* FUN_0084f4f0(void* out);
extern "C" void  FUN_008513d0(void* map_or_cfg, void* pos, int icon_type);
extern "C" void  FUN_00758460(/* rect + texture formals — see raw */);
extern "C" void  FUN_00757890(void* verts, int n, void* tex, int flag, void* cookie);
extern "C" void  FUN_00413f50(void* xy, int* half_wh);
extern "C" void  FUN_00413680(/* textured marker formals */);
extern "C" void  Client_EvalAutoPatrolWaypoint(void* host, void* out_id, void* out_pos);
extern "C" void  FUN_0046f100(void); // RB tree step
extern "C" int   FUN_00574760(int slot);
extern "C" void  FUN_004e9530(void* out, void* pos);
extern "C" void  FUN_004e8a40(void* orient, void* out_basis);
extern "C" void  FUN_004e8ad0(void* orient, void* out_basis);
extern "C" uint8_t FUN_006a3db0(void);

// Globals (image addrs)
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
extern float DAT_00aaa8a8; // 300.f
extern float DAT_00aaa6c4; // 2.5f
extern float DAT_00a0f694; // 30.f
extern float DAT_00aaa678, DAT_00aaa67c;
extern int   DAT_00d1e818, DAT_00d1e81c;
extern float g_flOne, g_flZero;
extern char  DAT_00d1ec78[];
extern char  DAT_00d1ecac[];

static void BumpLayer(int* self_dwords)
{
    // self+0x68 / +0x70 / +0x74  ==  dwords[0x1a] / [0x1c] / [0x1d]
    int layer = self_dwords[0x1a] + 1;
    self_dwords[0x1a] = layer;
    self_dwords[0x1d] = (int)(float)(-layer);
    if (self_dwords[0x1c] < layer)
        self_dwords[0x1c] = layer;
}

extern "C" void __thiscall Client_UI_MapView_DrawMarkersFovOverlay(void* self)
{
    auto* sd = reinterpret_cast<int*>(self);
    int* cfg = reinterpret_cast<int*>(sd[0x122]); // +0x488
    if (cfg == nullptr || DAT_00d1b644 == 0 ||
        *reinterpret_cast<int*>(DAT_00d1b644 + 0xe4e8) == 0 ||
        DAT_00d1b6d8 == 0 ||
        *reinterpret_cast<char*>(reinterpret_cast<char*>(cfg) + 0x4fc) == 0) {
        return;
    }

    // Local pose snapshot: vfunc +0x1a0 on local entity (4 floats) — see raw.
    // --- Phase: marker circular list DAT_00d1d964 ---
    // for each node: optional attach vfunc +0x144; FUN_0084f610 project;
    // offset by half icon (cfg+0x538/0x53c); clamp >=0;
    // type in [0,8] + tex cfg+0x600+type*4 → FUN_00413f50/FUN_00413680
    // else FUN_00758460 default DAT_00d1ec78.
    BumpLayer(sd);

    // --- Auto-patrol (DAT_00d1ad10 vector) → FUN_008513d0 ---
    // --- Mission tree DAT_00d1b938 RB walk type 0x65 → FUN_008513d0 ---
    BumpLayer(sd);

    // --- Special point DAT_00d1ad1c → FUN_004e9530 + FUN_008513d0(..., 100) ---
    BumpLayer(sd);

    // --- Squad FUN_00574760 ×4 if *(local+0xcb0) → FUN_008513d0(..., 1) ---
    BumpLayer(sd);

    // --- FOV overlay if camera pair DAT_00d1b780 matches DAT_00d1b778 ---
    // orientation vfunc +0x1a4; FUN_004e8a40 / FUN_004e8ad0
    // tint from self+0x224 → default 0xFF32FF32
    // half = (1.0f / viewportDim) * 300.0f  (DAT_00aaa8a8)
    // four corners FUN_0084f4f0; FUN_00757890 tex cfg+0x5a0 or default
    // optional cone: sin(cfg+0x514 * 2.5f) > 0 → second quad tex cfg+0x5a4
}

// Ghidra name alias
extern "C" void __thiscall FUN_00851630(void* self)
{
    Client_UI_MapView_DrawMarkersFovOverlay(self);
}
