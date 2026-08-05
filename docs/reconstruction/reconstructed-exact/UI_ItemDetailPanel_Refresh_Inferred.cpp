// =============================================================================
// UI_ItemDetailPanel_Refresh_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0084b890
// Address:   0x0084b890  (autoassault.exe, image base 0x400000)
// Body:      0x0084b890–0x0084ca69 (4569 bytes / 0x11D9)
// System:    client UI / inventory item detail panel
// Seal:      W22-K 2026-07-29 — decompile_function + read_memory
// Exactness: Stage-faithful reconstruction of CF. Large vfunc surface kept as
//            offsets. Not a line-by-line expansion of every stack temp.
// Scaffold:  docs/reconstruction/reconstructed-exact/FUN_0084b890.cpp
// =============================================================================
//
// ABI: thiscall — ECX = panel*. No stack args. ret (c3).
// Dispatch: vtbl slot @ 0x00a697e4 (DATA xref only).
// Gate: if (*(void**)(this + 0x518) == nullptr) return;
//
// Strings: "i_g_2d_overlay_broken.dds", "%.01f%% %s", "%s: %s"
// Key callees: FUN_007a69d0, FUN_0084b210, FUN_00519d20, FUN_0075bf40,
//   FUN_00845b40, FUN_00845af0, FUN_00845880, UI_BuildItemTooltipStats,
//   Math_AcosClamped (0x0040d0a0), FUN_00514050, FUN_005140d0, sprintf, …
//
// Constants (read_memory):
//   DAT_00aaa678 ≈ 0.000833  (Y scale)
//   DAT_00aaa67c ≈ 0.000625  (X scale)
//   DAT_00aaa7ac = 100.0f    (percent clamp)
//   DAT_00aaa99c ≈ 114.5916  (180/π degrees)
// =============================================================================

#include <cstdint>
#include <cstdio>

// Opaque UI / game types — widths only where sealed.
struct UiWidget;   // vfunc host
struct GameObject; // bound item/character at this+0x518

extern float DAT_00aaa678;
extern float DAT_00aaa67c;
extern float DAT_00aaa7ac;
extern float DAT_00aaa99c;
extern int   DAT_00d1e818;
extern int   DAT_00d1e81c;
extern char  DAT_00d1791c;
extern int  *DAT_00d1b6d8;

extern "C" float FUN_007a69d0(void);
extern "C" void  FUN_0084b210(void /* this context */);
extern "C" uint32_t FUN_00519d20(void *);
extern "C" void  FUN_0075bf40(void);
extern "C" char  FUN_00845b40(void);
extern "C" char  FUN_00845af0(void);
extern "C" int   FUN_00845880(void *textHost, GameObject *obj);
extern "C" void  UI_BuildItemTooltipStats(void /* ECX host */, GameObject *obj,
                                         int a, int b);
extern "C" float FUN_0040d0a0(float); // Math_AcosClamped
extern "C" void *FUN_00514050(void);
extern "C" void *FUN_005140d0(void *, uint32_t);
extern "C" float FUN_0052e640(GameObject *);
extern "C" void *FUN_007a6de0(int);
extern "C" void *FUN_007a6a30(void *);
extern "C" float FUN_00930ea0(void);
extern "C" void  FUN_00847240(GameObject *, int);
extern "C" void  FUN_008452f0(void);

// Panel layout (byte offsets sealed from decomp index * 4).
struct ItemDetailPanel {
  void *vtbl;                 // +0
  uint8_t pad_4[0x514];
  GameObject *boundObject;    // +0x518  (param_1[0x146])
  uint8_t pad_51c[0xc];
  char flag_528;              // +0x528  (param_1[0x14a] as char*)
  uint8_t pad_529[0x3];
  UiWidget *rootChrome;       // +0x52c  [0x14b]
  UiWidget *pad_530;
  UiWidget *overlayHost;      // +0x534  [0x14d]
  UiWidget *w14e;             // +0x538
  UiWidget *textHost;         // +0x53c  [0x14f]
  UiWidget *w150;             // +0x540
  UiWidget *w151;             // +0x544
  UiWidget *w152;             // +0x548
  // … additional children through +0x159 …
  UiWidget *children[/* illustrative */];
};

// Helper: call virtual at byte offset from widget vtbl (matches decomp).
template <typename R, typename... Args>
static R vcall(UiWidget *w, int voff, Args... args)
{
  auto **vt = *reinterpret_cast<void ***>(w);
  auto *fn = reinterpret_cast<R(__thiscall *)(UiWidget *, Args...)>(vt[voff / 4]);
  return fn(w, args...);
}

// ---------------------------------------------------------------------------
// Stage-faithful body (control flow; not every stack temporary)
// ---------------------------------------------------------------------------
void __fastcall UI_ItemDetailPanel_Refresh_Inferred(ItemDetailPanel *self)
{
  if (self->boundObject == nullptr) {
    return;
  }

  // --- stage: time + pre-layout ---
  float timeNow = FUN_007a69d0();
  FUN_0084b210();
  // *(overlayHost + 0x488) = 1
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self->overlayHost) + 0x488) = 1;

  // --- stage: subtype-8 skill mask vs clear overlay bind ---
  // chain: obj+0xa8 → +0x3c → short +0x3f4
  auto *obj = self->boundObject;
  // if (*(short*)(*(*(obj+0xa8)+0x3c)+0x3f4) == 8)
  //   mask = FUN_00519d20(*(obj+0xc8)); vcall(overlay, 0x1a0, mask|0xdf000000);
  // else vcall(overlay, 0x1a0, 0);
  FUN_0075bf40();

  // --- stage: normal vs broken overlay texture ---
  // if (!(obj+0x17c bit19) && !DAT_00d1791c) vcall(overlay, 0x58);
  // else vcall(..., "i_g_2d_overlay_broken.dds");
  (void)timeNow;

  char flagA = FUN_00845b40();
  char flagB = FUN_00845af0();
  (void)flagA;
  (void)flagB;

  // --- stage: scale root chrome from screen metrics ---
  // w = (int)(DAT_00d1e818 * root[+0x254] * DAT_00aaa67c)
  // h = (int)(DAT_00d1e81c * root[+0x258] * DAT_00aaa678)
  // vcall(root, 0x12c /*300*/, &size);

  // --- stage: optional percent line when DAT_00d1791c ---
  if (DAT_00d1791c != 0) {
    float pct = 0.0f;
    if (DAT_00d1b6d8 != nullptr) {
      pct = (float)FUN_0052e640(obj);
    }
    pct *= DAT_00aaa7ac;
    if (DAT_00aaa7ac < pct) {
      pct = DAT_00aaa7ac;
    }
    char buf[272];
    // sprintf(buf, "%.01f%% %s", pct, localized);
    (void)buf;
    (void)pct;
    // vcall(textHost, 0x224, buf);
  }

  // --- stage: name lines "%s: %s" / locale ---
  // vcall paths +0x15c / +0x250 with FUN_007a6de0 / FUN_007a6a30

  // --- stage: child stack layout (vfunc size queries + place) ---
  // FUN_00845880(text, obj) → if <1 hide w151 else layout cascade
  // place w14e, w150, w157, w158, w152, w155, w156, …

  UI_BuildItemTooltipStats(/* ECX = tooltip host from panel */, obj, 0, 1);

  // --- stage: optional angle gauges ---
  // nested = vcall(obj, 0x1e0); if nested:
  //   ang = Math_AcosClamped(nested[+0xdc]) * DAT_00aaa99c;
  //   vcall(w157, 0x3ac, ang); vcall(w157, 0x3b0, nested[+0xe8]);

  // --- stage: COID table may set DAT_00d1791c ---
  if (DAT_00d1b6d8 != nullptr) {
    uint32_t lo = *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(obj) + 0x160);
    uint32_t hi = *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(obj) + 0x164);
    if ((lo & hi) != 0xffffffffu) {
      for (uint32_t i = 0; (int)i < 8; ++i) {
        uint32_t *e = reinterpret_cast<uint32_t *>(
            reinterpret_cast<char *>(DAT_00d1b6d8) + 0x5a0 + (i & 0xff) * 8);
        if (e[0] == lo && e[1] == hi) {
          DAT_00d1791c = 1;
          break;
        }
      }
    }
  }

  // --- stage: footer type label ---
  // if (type at obj data +0x38 == 4) clear label via root vfunc +0x15c
  // else FUN_005140d0(subtype word) → set label
  // vcall(root, 0x34c);
  // if (!DAT_00d1791c && !flag_528) vcall(final, 0x444, obj); else vcall(final, 0xcc, 0);
}

// Ghidra surface name
void __fastcall FUN_0084b890(float *param_1)
{
  UI_ItemDetailPanel_Refresh_Inferred(reinterpret_cast<ItemDetailPanel *>(param_1));
}
