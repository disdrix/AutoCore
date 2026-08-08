// =============================================================================
// Client_NpcMissionDialog_ApplyPanelMode_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Apply NPC mission dialog panel mode (EAX = 0/1/2/3) on the dialog
//           host (ECX). Mode 3 fills the multi-mission "Select a Mission:"
//           title panel (scale, caption, color, layout) and hides single-
//           mission / response chrome. Modes 0/3 hide chrome; 1/2 show the
//           alternate pair at dialog+0x6f8/+0x6fc and clear TFID slots.
//           Always tails into FUN_008ab340 (list-row clear) with ESI=dialog.
//
// Address:  0x008ab550  (autoassault.exe, image base 0x400000)
// Body:     0x008ab550–0x008ab799 (586 B / 0x24A)
// Stable:   aa_008ab550
// System:   missions-progression
// Ghidra:   FUN_008ab550
//
// Convention: ECX = dialog*; EAX = panelMode {0,1,2,3}; plain RET (C3).
//             No stack formals.
//
// Callers:
//   Client_ShowNpcMissionDialogUI @ 00943972 (EAX=3 multi-active)
//   Client_ShowNpcMissionDialogUI @ 00943a6c (EAX=1 single present)
//   FUN_0093e450            @ 0093e623 (EAX=0 dialog case-0)
//
// Decompiler lag: Ghidra treats mode as in_EAX after Locale_GetInstance.
//   Assembly: MOV EDI,EAX (mode); CALL 007a69d0; MOV EBP,EAX (locale);
//             MOV [ESI+0x648],EDI.
//
// Exactness: CF mirrors live Ghidra decompile 2026-08-05 + ABI corrections.
// Dual: reviews/A_aa_008ab550_* + B_aa_008ab550_*
// Bit-for-bit / runtime: DEFERRED (terminal_coverage=false).
// =============================================================================

#include <cstdint>

// Dualed callees (not redefined here)
extern "C" void *Locale_GetInstance_Inferred(); // FUN_007a69d0
extern "C" char *StringPool_ApplyModeAndRingStore_Inferred(void *pool, const char *src, int mode); // FUN_007a6de0
extern "C" void FUN_008ab340(); // residual MEGA-105 — ESI = dialog

extern float DAT_00d1e818; // runtime viewport width (static image 0)
extern float DAT_00d1e81c; // runtime viewport height (static image 0)
extern float DAT_00aaa67c; // ≈ 0.000625 (1/1600)
extern float DAT_00aaa678; // ≈ 0.000833 (1/1200)
extern std::uint32_t DAT_00afdf0c; // color pack @ 0x00afdf0c

using VtblFn_Show = void(__thiscall *)(void *self, int visible);
using VtblFn_Style = void(__thiscall *)(void *self, int style);
using VtblFn_SetText = void(__thiscall *)(void *self, char *text, int a, int b);
using VtblFn_SetColor = void(__thiscall *)(void *self, int flag, void *color);
using VtblFn_Layout = void(__thiscall *)(void *self);

static inline void **Vtbl(void *obj) { return *reinterpret_cast<void ***>(obj); }

// ECX = dialog, EAX = panelMode — register contract
void Client_NpcMissionDialog_ApplyPanelMode_Inferred(void *dialog /*ecx*/,
                                                       int panelMode /*eax*/)
{
    void *localePool = Locale_GetInstance_Inferred();
    *reinterpret_cast<int *>(static_cast<char *>(dialog) + 0x648) = panelMode;

    if (panelMode == 0 || panelMode == 3) {
        *reinterpret_cast<int *>(static_cast<char *>(dialog) + 0x670) = 0;
    } else if (panelMode == 1 || panelMode == 2) {
        *reinterpret_cast<int *>(static_cast<char *>(dialog) + 0x678) = -1;
        *reinterpret_cast<int *>(static_cast<char *>(dialog) + 0x67c) = -1;
    }

    if (panelMode == 0 || panelMode == 3) {
        *reinterpret_cast<std::uint8_t *>(static_cast<char *>(dialog) + 0x580) = 0;
        void *w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6e8);
        if (w) {
            reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 0); // vtbl+4
        }
    }

    void *title = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6dc);
    if (title) {
        reinterpret_cast<VtblFn_Show>(Vtbl(title)[1])(title, panelMode != 0);
        if (panelMode == 3) {
            void **vt = Vtbl(title);
            reinterpret_cast<VtblFn_Style>(vt[0x1b0 / 4])(title, 10);

            int baseW = *reinterpret_cast<int *>(static_cast<char *>(title) + 0x1b8);
            int baseH = *reinterpret_cast<int *>(static_cast<char *>(title) + 0x1bc);
            *reinterpret_cast<int *>(static_cast<char *>(title) + 0x170) =
                static_cast<int>(static_cast<float>(baseW) * DAT_00d1e818 * DAT_00aaa67c);
            *reinterpret_cast<int *>(static_cast<char *>(title) + 0x174) =
                static_cast<int>(static_cast<float>(baseH) * DAT_00d1e81c * DAT_00aaa678);

            // ECX = localePool (EBP from Locale_GetInstance); mode = -1
            char *caption = StringPool_ApplyModeAndRingStore_Inferred(
                localePool, "Select a Mission:", -1);
            reinterpret_cast<VtblFn_SetText>(vt[0x1d8 / 4])(title, caption, 1, 1);
            reinterpret_cast<VtblFn_SetColor>(vt[0x15c / 4])(title, 1, &DAT_00afdf0c);
            reinterpret_cast<VtblFn_Layout>(vt[0x34c / 4])(title);
        }
    }

    if (panelMode == 0 || panelMode == 3) {
        void *w;
        w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6e4);
        if (w) reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 0);
        w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x68c);
        if (w) reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 0);
        w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x690);
        if (w) reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 0);
        w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6e8);
        if (w) reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 0);

        // 4×4 widget grid: bases at +0x698 / +0x6a8 / +0x6b8 / +0x6c8
        int *slot = reinterpret_cast<int *>(static_cast<char *>(dialog) + 0x6c8);
        int remain = 4;
        do {
            if (slot[-8] != 0) {
                void *obj = reinterpret_cast<void *>(slot[-8]);
                reinterpret_cast<VtblFn_Show>(Vtbl(obj)[1])(obj, 0);
            }
            if (slot[0] != 0) {
                void *obj = reinterpret_cast<void *>(slot[0]);
                reinterpret_cast<VtblFn_Show>(Vtbl(obj)[1])(obj, 0);
            }
            if (slot[-12] != 0) {
                void *obj = reinterpret_cast<void *>(slot[-12]);
                reinterpret_cast<VtblFn_Show>(Vtbl(obj)[1])(obj, 0);
            }
            if (slot[-4] != 0) {
                void *obj = reinterpret_cast<void *>(slot[-4]);
                reinterpret_cast<VtblFn_Show>(Vtbl(obj)[1])(obj, 0);
            }
            ++slot;
            --remain;
        } while (remain != 0);

        if (panelMode == 3) {
            w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6f8);
            if (w) reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 0);
        }
        w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6fc);
        if (w) reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 0);
    } else {
        void *w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6f8);
        if (w) reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 1);
        w = *reinterpret_cast<void **>(static_cast<char *>(dialog) + 0x6fc);
        if (w) {
            reinterpret_cast<VtblFn_Show>(Vtbl(w)[1])(w, 1);
            FUN_008ab340(); // ESI still = dialog
            return;
        }
    }

    FUN_008ab340(); // ESI still = dialog
}
