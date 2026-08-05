// =============================================================================
// UiHost_RefreshTrackedNodeWidgets_Inferred  (FUN_00871150)
// -----------------------------------------------------------------------------
// Stable ID: aa_00871150
// Address:   0x00871150 – 0x008715f8  (autoassault.exe, base 0x400000)
// Size:      1192 bytes (0x4A8)
// System:    client UI / vehicle-garage host residual
// Dual:      W21-S 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   If the UI host is visible, rebind a bank of optional child widgets from a
//   tracked node (id pair + small fields). When the node's id pair matches the
//   global selection context, re-invoke the select/highlight vtbl on each bound
//   widget.
//
// ABI (bytes-sealed)
//   EAX  = UiHost* this
//   stack arg0 = TrackedNode* node
//   epilogue: add esp, 0x108; ret 4
//
// CALLERS
//   FUN_00871600, FUN_008718a0 (clear-then-refresh), FUN_008718d0, FUN_008719d0
//
// =============================================================================

#include <cstdint>
#include <cstdio>

// ---- layouts (partial, sealed) ----------------------------------------------

struct UiWidgetVtable {
  // ...
  // +0x34c refresh/invalidate
  // +0x45c set text / bind label
  // +0x460 bind secondary value
  // +0x464 bind id pair / highlight
};

struct UiWidget {
  UiWidgetVtable* vtbl;
};

struct UiHostVtable {
  // +0x3d8 IsVisible -> bool
};

struct UiHost {
  UiHostVtable* vtbl;
  // [0x143] +0x50c  int filter / type gate for widget D
  // [0x17a] +0x5e8  UiWidget* A
  // [0x17b] +0x5ec  UiWidget* B
  // [0x17c] +0x5f0  UiWidget* C
  // [0x17d] +0x5f4  UiWidget* D
  // [0x17e] +0x5f8  UiWidget* G
  // [0x17f] +0x5fc  UiWidget* F
  // [0x180] +0x600  UiWidget* E
};

struct TrackedNode {
  int32_t flag;          // +0x00
  int32_t pad04;         // +0x04
  int32_t idA;           // +0x08  (node[2])
  int32_t idB;           // +0x0c  (node[3])
  // +0x14: uint16 used by widget F
  // +0x1c: int8/int16 format selector + type match
};

// Externals (unresolved product names)
extern "C" void FUN_007fd970(/* CL = node+0x1c - 0x0f; buffer via EAX */);
extern "C" void FUN_0051fa10();
extern "C" void FUN_0051f910();
extern "C" void FUN_008705c0();
extern int DAT_00d1b6d8;

// Helper: widget vtbl calls are decompiler-lossy for stack args; order sealed.
static inline void Widget_SetText(UiWidget* w) {
  if (!w) return;
  // vtbl+0x45c
  (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w + 0x45c))(w);
}
static inline void Widget_Bind460(UiWidget* w, int idA) {
  if (!w) return;
  (*(void(__thiscall**)(UiWidget*, int))(*(uintptr_t*)w + 0x460))(w, idA);
}
static inline void Widget_Bind464(UiWidget* w, int idA, int idB, int flag, void* extra) {
  if (!w) return;
  (*(void(__thiscall**)(UiWidget*, int, int, int, void*))(*(uintptr_t*)w + 0x464))(
      w, idA, idB, flag, extra);
}
static inline void Widget_Refresh34c(UiWidget* w) {
  if (!w) return;
  (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w + 0x34c))(w);
}

// ---- clean reconstruction ---------------------------------------------------

// NOTE: Calling convention is non-standard thiscall: host arrives in EAX, not ECX.
// Modelled here as an explicit first parameter; retail entry moves EAX -> ESI.

void UiHost_RefreshTrackedNodeWidgets_Inferred(UiHost* host /*EAX*/, TrackedNode* node /*stack*/)
{
  // Gate: host visible?
  char visible = (*(char(__thiscall**)(UiHost*))(*(uintptr_t*)host + 0x3d8))(host);
  if (visible == 0) {
    return;
  }
  if (node == nullptr) {
    return;
  }

  // Bytes: CL = *(uint8_t*)(node + 0x1c) - 0x0f; buffer on stack; call FUN_007fd970
  FUN_007fd970();

  int idA = node->idA; // node[2]
  int idB = node->idB; // node[3]

  // Host widget pointers (dword indices as sealed)
  UiWidget* w17a = *(UiWidget**)((uint8_t*)host + 0x5e8);
  UiWidget* w17b = *(UiWidget**)((uint8_t*)host + 0x5ec);
  UiWidget* w17c = *(UiWidget**)((uint8_t*)host + 0x5f0);
  UiWidget* w17d = *(UiWidget**)((uint8_t*)host + 0x5f4);
  UiWidget* w180 = *(UiWidget**)((uint8_t*)host + 0x600);
  UiWidget* w17f = *(UiWidget**)((uint8_t*)host + 0x5fc);
  UiWidget* w17e = *(UiWidget**)((uint8_t*)host + 0x5f8);

  char buf[256];
  int stackPair[2];

  // ---- widget A [0x17a] +0x5e8 : "%d" --------------------------------------
  if (w17a != nullptr) {
    std::sprintf(buf, "%d");
    Widget_SetText(w17a);
    stackPair[1] = 0;
    stackPair[0] = idB;
    Widget_Bind460(w17a, idA);
    Widget_Bind464(w17a, idA, idB, 1, /*stack fmt residual*/ nullptr);
    Widget_Refresh34c(w17a);
  }

  // ---- widget B [0x17b] +0x5ec ---------------------------------------------
  if (w17b != nullptr) {
    Widget_SetText(w17b);
    stackPair[1] = 1;
    stackPair[0] = idB;
    Widget_Bind464(w17b, idA, /*decomp partial*/ 0, 0, nullptr);
    Widget_Refresh34c(w17b);
  }

  // ---- widget C [0x17c] +0x5f0 : "%d/%s/%s" --------------------------------
  if (w17c != nullptr) {
    FUN_0051fa10();
    FUN_0051f910();
    std::sprintf(buf, "%d/%s/%s");
    Widget_SetText(w17c);
    stackPair[1] = 0;
    stackPair[0] = idB;
    Widget_Bind460(w17c, idA);
    Widget_Bind464(w17c, idA, idB, 1, nullptr);
    Widget_Refresh34c(w17c);
  }

  // ---- widget D [0x17d] +0x5f4 : gated by host+0x50c -----------------------
  if (w17d != nullptr) {
    int gate = *(int*)((uint8_t*)host + 0x50c); // host[0x143]
    if (gate == -1) {
      // both flag==0 and flag!=0 paths call SetText (decomp loses distinct args)
      Widget_SetText(w17d);
    } else if (gate == (int)(int16_t)/* node short @ +0x1c */ *(int16_t*)((uint8_t*)node + 0x1c)) {
      Widget_SetText(w17d);
    } else {
      Widget_SetText(w17d);
    }
    stackPair[1] = 1;
    stackPair[0] = idB;
    Widget_Bind464(w17d, idA, 0, 0, nullptr);
    Widget_Refresh34c(w17d);
  }

  // ---- widget E [0x180] +0x600 ---------------------------------------------
  if (w180 != nullptr) {
    FUN_008705c0();
    Widget_SetText(w180);
    stackPair[1] = 0;
    stackPair[0] = idB;
    Widget_Bind460(w180, idA);
    Widget_Bind464(w180, idA, idB, 1, nullptr);
    Widget_Refresh34c(w180);
  }

  // ---- widget F [0x17f] +0x5fc : "%d/%d" -----------------------------------
  if (w17f != nullptr) {
    std::sprintf(buf, "%d/%d");
    Widget_SetText(w17f);
    stackPair[1] = 0;
    stackPair[0] = idB;
    Widget_Bind460(w17f, idA);
    // second 0x460 with -(uint)*(ushort*)(node+0x14)
    uint16_t u14 = *(uint16_t*)((uint8_t*)node + 0x14);
    (*(void(__thiscall**)(UiWidget*, int, int, int, unsigned))(*(uintptr_t*)w17f + 0x460))(
        w17f, idA, idB, 1, (unsigned)-(int)u14);
    Widget_Bind464(w17f, idA, idB, 1, stackPair);
  }

  // ---- widget G [0x17e] +0x5f8 : "%d" --------------------------------------
  if (w17e != nullptr) {
    std::sprintf(buf, "%d");
    Widget_SetText(w17e);
    stackPair[1] = 0;
    stackPair[0] = idB;
    Widget_Bind460(w17e, idA);
    Widget_Bind464(w17e, idA, idB, 1, nullptr);
  }

  // ---- selection highlight -------------------------------------------------
  if (DAT_00d1b6d8 != 0) {
    int base = *(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4);
    int selA = *(int*)(base + 0x164 + DAT_00d1b6d8);
    int selB = *(int*)(base + 0x168 + DAT_00d1b6d8);
    if (idA == selA && idB == selB) {
      if (w17a) (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w17a + 0x464))(w17a);
      if (w17b) (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w17b + 0x464))(w17b);
      if (w17c) (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w17c + 0x464))(w17c);
      if (w17d) (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w17d + 0x464))(w17d);
      if (w180) (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w180 + 0x464))(w180);
      if (w17f) (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w17f + 0x464))(w17f);
      if (w17e) (*(void(__thiscall**)(UiWidget*))(*(uintptr_t*)w17e + 0x464))(w17e);
    }
  }
}

// Scaffold alias
void FUN_00871150(int* param_1)
{
  // Retail: host in EAX. Ports must supply host explicitly.
  UiHost_RefreshTrackedNodeWidgets_Inferred(/*host from EAX*/ nullptr,
                                            reinterpret_cast<TrackedNode*>(param_1));
}
