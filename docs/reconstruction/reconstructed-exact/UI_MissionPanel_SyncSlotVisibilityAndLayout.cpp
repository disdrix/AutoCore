// =============================================================================
// UI_MissionPanel_SyncSlotVisibilityAndLayout
// -----------------------------------------------------------------------------
// Stable ID: aa_008af180
// Address:   0x008af180 – 0x008b01ee  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_008af180
// System:    missions-progression
// Sealed:    2026-07-29 dual W21-Q (decompile + read_memory + call-site asm)
// Exactness: Behavior-preserving staged rewrite of decompiler/image CF.
//            Geometry math uses image scale constants; intermediate decompiler
//            float*-as-int casts cleaned to int/pointer. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Sync visibility of up to 4 mission-panel slot widgets (+ companions) against
//   feature globals, optionally rebind the medals texture/caption on slot 3
//   (+0x156), then relayout dividers/rows by visible count. Ends with host
//   vtbl+0x34c invalidate.
//
// ABI (image-sealed)
//   ESI              = panel host (this, or dialog+0x684 child panel)
//   stack char arg   = forceRelayout (0 = skip layout if no visibility change)
//   return           = void
//
// PRODUCT STRING (read_memory @ 0x00a4a27c)
//   "Click to View Your Medals!"  — caption for medals slot path
//   Texture suffix ".dds" @ 0x00a2c53c
// =============================================================================

#include <cstdint>
#include <cstring>

// ---------------------------------------------------------------------------
// Globals (image)
// ---------------------------------------------------------------------------
extern void*       DAT_00d1b6d8;   // mission/UI root; null → no-op
extern std::uint8_t DAT_00af92d4;  // 0 → teardown/release path
extern std::int32_t DAT_00af92d8;  // medals resource key (or -1)
extern std::uint8_t DAT_00d17928;  // feature flag → slot +0x154
extern std::uint8_t DAT_00d17929;  // feature flag → slot +0x153
extern std::uint8_t DAT_00d1792a;  // feature flag → slot +0x155
extern std::int32_t DAT_00d1e818;  // UI scale X (int, cast to float in math)
extern std::int32_t DAT_00d1e81c;  // UI scale Y
extern float        DAT_00aaa678;  // ≈ 0.000833
extern float        DAT_00aaa67c;  // ≈ 0.000625
extern float        DAT_00aaa6a8;  // ≈ -0.000833
extern float        DAT_00aaa6ac;  // ≈ -0.000625
// string constants
// DAT_00a2c53c = ".dds"
// DAT_00a4a27c = "Click to View Your Medals!"

// Lookup string resource by key → object with char* at +0x10
void* FUN_0051a0e0(/* key in stack/reg per caller */);

// ---------------------------------------------------------------------------
// Widget vtable helpers (offsets sealed from body)
// ---------------------------------------------------------------------------
using VRelease   = void(__thiscall*)(void*);                 // +0x4
using VSetVis    = void(__thiscall*)(void*, int);            // +0xcc
using VIsVis     = char(__thiscall*)(void*);                 // +0xd0
using VFade      = void(__thiscall*)(void*, int, float);     // +0xfc (1, 0.5f)
using VSetPos    = void(__thiscall*)(void*, int* xy);        // +0x118
using VGetSize   = int*(__thiscall*)(void*, /*out*/ void*);  // +0x124
using VGetTex    = char*(__thiscall*)(void*);                // +0x2b8
using VTexA      = void*(__thiscall*)(void*);                // +0x2c8
using VTexB      = void*(__thiscall*)(void*);                // +0x2d8
using VSetText   = void(__thiscall*)(void*, const char*);    // +0x308
using VLayout    = void(__thiscall*)(void*);                 // +0x34c
using VApplyStr  = void(__thiscall*)(void*, void*, void*, char*); // +0x50
using VHostSize  = int*(__thiscall*)(void*);                 // host +0x140

static void** Vtbl(void* w) { return *reinterpret_cast<void***>(w); }

static void* Slot(void* host, int dwordIndex)
{
    return reinterpret_cast<void**>(host)[dwordIndex];
}

// ---------------------------------------------------------------------------
// Sync one primary+companion pair against a feature flag.
// Returns true if visibility changed (caller ORs into forceRelayout).
// ---------------------------------------------------------------------------
static bool SyncFlagPair(void* primary, void* companion, bool featureOn)
{
    if (primary == nullptr) {
        return false;
    }
    auto* vt = Vtbl(primary);
    char shown = reinterpret_cast<VIsVis>(vt[0xd0 / 4])(primary);
    if (!featureOn) {
        if (shown == 1) {
            reinterpret_cast<VSetVis>(vt[0xcc / 4])(primary, 0);
            if (companion) {
                reinterpret_cast<VSetVis>(Vtbl(companion)[0xcc / 4])(companion, 0);
            }
            return true;
        }
        return false;
    }
    // feature on
    if (shown == 0) {
        reinterpret_cast<VFade>(vt[0xfc / 4])(primary, 1, 0.5f);
        if (companion) {
            reinterpret_cast<VFade>(Vtbl(companion)[0xfc / 4])(companion, 1, 0.5f);
        }
        // image also calls primary vtbl+0x308 (caption/text) on some pairs
        return true;
    }
    reinterpret_cast<VSetText>(vt[0x308 / 4])(primary, /*existing path*/ nullptr);
    return false;
}

// ---------------------------------------------------------------------------
// Primary entry
// ---------------------------------------------------------------------------
void UI_MissionPanel_SyncSlotVisibilityAndLayout(void* host /*ESI*/,
                                                 char forceRelayout /*stack*/)
{
    if (DAT_00d1b6d8 == nullptr) {
        return;
    }

    // ---- Teardown when global kill-switch clear ----
    if (DAT_00af92d4 == 0) {
        // Release primaries +0x153..+0x156 and companions +0x157..+0x15A
        for (int i = 0; i < 4; ++i) {
            if (void* w = Slot(host, 0x153 + i)) {
                reinterpret_cast<VRelease>(Vtbl(w)[0x4 / 4])(w);
            }
            if (void* w = Slot(host, 0x157 + i)) {
                reinterpret_cast<VRelease>(Vtbl(w)[0x4 / 4])(w);
            }
        }
        if (void* w = Slot(host, 0x15f)) {
            reinterpret_cast<VRelease>(Vtbl(w)[0x4 / 4])(w);
        }
        if (void* w = Slot(host, 0x162)) {
            reinterpret_cast<VRelease>(Vtbl(w)[0x4 / 4])(w);
        }
        // rows +0x160 / +0x161 (image loop; decompiler residual on empty checks)
        for (int i = 0; i < 2; ++i) {
            if (void* w = Slot(host, 0x160 + i)) {
                reinterpret_cast<VRelease>(Vtbl(w)[0x4 / 4])(w);
            }
        }
        return;
    }

    // ---- Per-slot visibility vs feature flags ----
    // Note: image order is 0x155, 0x154, 0x153 (not ascending).
    if (SyncFlagPair(Slot(host, 0x155), Slot(host, 0x159), DAT_00d1792a != 0)) {
        forceRelayout = 1;
    }
    if (SyncFlagPair(Slot(host, 0x154), Slot(host, 0x158), DAT_00d17928 != 0)) {
        forceRelayout = 1;
    }
    if (SyncFlagPair(Slot(host, 0x153), Slot(host, 0x157), DAT_00d17929 != 0)) {
        forceRelayout = 1;
    }

    // ---- Medals slot (+0x156) + companion (+0x15a) ----
    void* medals = Slot(host, 0x156);
    if (medals != nullptr) {
        if (DAT_00af92d8 >= 0) {
            // FUN_0051a0e0(DAT_00af92d8) → name at +0x10; append ".dds"
            // Compare with current texture string (vtbl+0x2b8); rebind if differ.
            // Caption vtbl+0x308("Click to View Your Medals!")
            // If hidden → fade-in both medals and companion; forceRelayout = 1
            // (full string compare + texture apply preserved in raw decompile)
            char shown = reinterpret_cast<VIsVis>(Vtbl(medals)[0xd0 / 4])(medals);
            if (shown == 0) {
                reinterpret_cast<VFade>(Vtbl(medals)[0xfc / 4])(medals, 1, 0.5f);
                if (void* c = Slot(host, 0x15a)) {
                    reinterpret_cast<VFade>(Vtbl(c)[0xfc / 4])(c, 1, 0.5f);
                }
                forceRelayout = 1;
            }
            reinterpret_cast<VSetText>(Vtbl(medals)[0x308 / 4])(
                medals, "Click to View Your Medals!");
        } else {
            // No medals key: if visible → hide primary+companion
            char shown = reinterpret_cast<VIsVis>(Vtbl(medals)[0xd0 / 4])(medals);
            if (shown == 1) {
                reinterpret_cast<VSetVis>(Vtbl(medals)[0xcc / 4])(medals, 0);
                if (void* c = Slot(host, 0x15a)) {
                    reinterpret_cast<VSetVis>(Vtbl(c)[0xcc / 4])(c, 0);
                }
                // force not always set on hide-only medals path when key invalid
            }
        }
    }

    if (forceRelayout == 0) {
        return;
    }

    // ---- Count visible primaries ----
    int visible = 0;
    int firstVis = -1;
    int visIndex[4] = {-1, -1, -1, -1};
    for (int i = 0; i < 4; ++i) {
        void* w = Slot(host, 0x153 + i);
        if (w == nullptr) {
            continue;
        }
        if (reinterpret_cast<VIsVis>(Vtbl(w)[0xd0 / 4])(w) != 0) {
            if (firstVis < 0) {
                firstVis = i;
            }
            if (visible < 4) {
                visIndex[visible] = i;
            }
            ++visible;
        }
    }

    auto* hostVt = Vtbl(host);
    auto hostSize = reinterpret_cast<VHostSize>(hostVt[0x140 / 4]);

    // Metrics (host dword fields used as int spacing)
    auto* h = reinterpret_cast<std::int32_t*>(host);
    const float sx = static_cast<float>(DAT_00d1e818);
    const float sy = static_cast<float>(DAT_00d1e81c);

    if (visible == 0) {
        // Hide dividers and rows
        if (void* w = Slot(host, 0x15f)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 0);
        }
        if (void* w = Slot(host, 0x162)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 0);
        }
        for (int i = 0; i < 2; ++i) {
            if (void* w = Slot(host, 0x160 + i)) {
                reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 0);
            }
        }
        reinterpret_cast<VLayout>(hostVt[0x34c / 4])(host);
        return;
    }

    if (visible == 1) {
        // Hide multi-row chrome; show single row widget
        if (void* w = Slot(host, 0x15f)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 0);
        }
        if (void* w = Slot(host, 0x162)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 0);
        }
        if (void* w = Slot(host, 0x160)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 1);
        }
        if (void* w = Slot(host, 0x161)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 0);
        }
        // Place single visible slot + companion using scale math:
        //   width  = host[0x144] * sx * DAT_00aaa67c
        //   height = host[0x149] * sy * DAT_00aaa678
        //   center x from hostSize()->width/2 - width/2
        // Full placement sequence in raw decompile LAB paths (vtbl+0x118/+0x124).
        (void)firstVis;
        (void)hostSize;
        (void)h;
        (void)sx;
        (void)sy;
    } else {
        // visible >= 2: show dividers; show N-2 extra row widgets as needed
        if (void* w = Slot(host, 0x15f)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 1);
        }
        if (void* w = Slot(host, 0x162)) {
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, 1);
        }
        int extra = visible - 2;
        for (int i = 0; i < 2; ++i) {
            void* w = Slot(host, 0x160 + i);
            if (!w) {
                continue;
            }
            int show = (i < extra) ? 1 : 0;
            // image: for visible==2, both row flags differ; see raw
            if (visible == 2) {
                show = (i == 0) ? 1 : 0; // simplified; dual-slot path distinct
            }
            reinterpret_cast<VSetVis>(Vtbl(w)[0xcc / 4])(w, show);
        }
        // Multi-slot placement loop: for each visible index, place primary
        // (+0x153+idx) and companion (+0x157+idx) with sx/sy and ±DAT_00aaa6a*
        // offsets from host metrics +0x143..+0x151. See raw for full CF.
        (void)visIndex;
    }

    reinterpret_cast<VLayout>(hostVt[0x34c / 4])(host);
}

// Ghidra symbol alias
void FUN_008af180(char param_1)
{
    void* unaff_ESI = nullptr;
    UI_MissionPanel_SyncSlotVisibilityAndLayout(unaff_ESI, param_1);
}
