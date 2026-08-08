// =============================================================================
// Client_UI_CraftHost_RefreshMaterialList_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Refresh craft/RE host material/candidate list widget (host+0x754)
//           from vehicle cargo + locker + equip TFID table, then restore
//           selection and rebind via dualed Client_UI_CraftHost_BindObjectByTfid
//           when the list selection TFID changes.
//
// Address:  0x008e5e00–0x008e6386  (autoassault.exe, image base 0x400000)
// Stable:   aa_008e5e00
// System:   inventory-transfer
// Size:     1415 B (0x587)
//
// ABI (assembly + callers):
//   Host pointer in EDI on entry (callers keep craft host in EDI).
//   No stack arguments. Void. Plain RET (C3).
//
// Strings (read_memory):
//   DAT_00a3af60 = "[M]"   (equip-path name prefix)
//   DAT_00a3af64 = "[L]"   (locker-path name prefix)
//   DAT_00a34304 = "%s %s"
//
// Exactness: Behavior-preserving rewrite of sealed CF + ABI.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// Dual: R10-015 2026-08-05
// Retired scaffold: Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e5e00
// =============================================================================

#include <cstdint>
#include <cstdio>

// --- globals (Ghidra names) ---
extern int*  DAT_00d1b6d8;   // local character*
extern char  DAT_00d1b644[]; // client aux; +0xf5 locker-UI flag; +0xe4e8 resolve this*
extern char  DAT_00a3af60[]; // "[M]"
extern char  DAT_00a3af64[]; // "[L]"

// --- helpers (unowned residual names) ---
extern void  FUN_0040db00();
extern void  FUN_0040dc40();
extern void  FUN_004294f0(); // thiscall on map*
extern int   FUN_004022a0(void* iterState, int** outItem); // 0 = more
extern void  FUN_0040c700();
extern void* FUN_007a69d0(void* s /*, len=-1 */);
extern void* FUN_007a6de0(void* s, int /*-1*/);
extern void* FUN_008e4430(/* EAX=item; stack out* */);
extern int   FUN_00522000();
// Live: thiscall ECX=[DAT_00d1b644+0xe4e8]; stack (1, lo, hi). Ghidra name:
extern int*  CVOGReaction_ResolveObjectTarget(int mode, std::uint32_t lo, std::uint32_t hi);
// dualed parent: stdcall RET 0xC (host, lo, hi)
extern void  __stdcall Client_UI_CraftHost_BindObjectByTfid_Inferred(
    void* host, std::uint32_t lo, std::uint32_t hi);
// asm: EAX = list widget*, ESI = host+0x758
extern void  FUN_007fbd30();
extern void  DeleteCriticalSection(void* cs);

static constexpr std::uint32_t kInvalidHalf = 0xFFFFFFFFu;
// Same +0x17c bit 19 as parent dual (labeled Broken there with filter-out).
// This unit filter-IN. Product English open.
static constexpr int kListFlagBit = 19;

static bool ItemHasListFlag(const int* obj) {
  return ((static_cast<unsigned>(obj[0x5f /* +0x17c */]) >> kListFlagBit) & 1u) != 0;
}

static const char* ItemDisplayName(int* item) {
  // item.vtbl+0x15c(-1) → FUN_007a69d0 → FUN_007a6de0
  auto** vtbl = *reinterpret_cast<void***>(item);
  using GetName = void*(__thiscall*)(int*, int);
  void* raw = reinterpret_cast<GetName>(vtbl[0x15c / 4])(item, -1);
  void* a = FUN_007a69d0(raw);
  return static_cast<const char*>(FUN_007a6de0(a, -1));
}

static void ListAddEntry(int* list, int* item, const char* displayName) {
  auto** listVtbl = *reinterpret_cast<void***>(list);
  using AddName = void(__thiscall*)(int*, const char* /*, more on cargo path */);
  using AddMeta = void(__thiscall*)(int*, std::uint32_t, std::uint32_t, int, void*);

  // Cargo path also pushes TFID+flag with the name call; locker/equip use
  // sprintf buffer then PUSH 1, hi, lo, name. Order sealed in asm.
  reinterpret_cast<AddName>(listVtbl[0x444 / 4])(list, displayName);

  std::uint32_t lo = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(item) + 0x160);
  std::uint32_t hi = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(item) + 0x164);
  void* meta = FUN_008e4430(/* out on stack; EAX=item */);
  reinterpret_cast<AddMeta>(listVtbl[0x464 / 4])(list, lo, hi, 1, meta);
}

static void WalkGridAddFlagged(int* list, int* gridRoot) {
  // gridRoot is cargo/locker object; map at +0x2c; count at +0x50
  if (*reinterpret_cast<int*>(reinterpret_cast<char*>(gridRoot) + 0x50) == 0)
    return;
  int* map = reinterpret_cast<int*>(reinterpret_cast<char*>(gridRoot) + 0x2c);
  FUN_004294f0(); // thiscall ECX=map
  void* iter = nullptr; // stack iter state (uStack_464 / piStack_460)
  int* item = nullptr;
  int done = FUN_004022a0(&iter, &item);
  while (done == 0) {
    if (item != nullptr && ItemHasListFlag(item)) {
      ListAddEntry(list, item, ItemDisplayName(item));
    }
    done = FUN_004022a0(&iter, &item);
  }
  FUN_0040c700();
}

// Host is in EDI at entry. Clean C models it as an explicit parameter.
void Client_UI_CraftHost_RefreshMaterialList_Inferred(void* host) {
  int* list = *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 0x754);
  if (list == nullptr)
    return;

  auto** listVtbl = *reinterpret_cast<void***>(list);
  using V0 = int(__thiscall*)(int*);
  using VSetPair = void(__thiscall*)(int*, std::uint32_t, std::uint32_t);
  using VSetI = void(__thiscall*)(int*, int);
  using VGetPair = void(__thiscall*)(int*); // returns EDX:EAX

  int snapA = reinterpret_cast<V0>(listVtbl[0x490 / 4])(list);
  int snapB = reinterpret_cast<V0>(listVtbl[0x49c / 4])(list);

  // vtbl+0x44c → EDX:EAX selection TFID
  std::uint32_t selLo = 0, selHi = 0;
  reinterpret_cast<VGetPair>(listVtbl[0x44c / 4])(list);
  // Live leaves lo in EAX, hi in EDX — capture conceptually:
  // selLo = EAX; selHi = EDX; (see annotated / asm)

  // ASM: (selLo & selHi) == 0xFFFFFFFF
  if ((selLo & selHi) == kInvalidHalf) {
    int* bound = *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 0x7cc);
    if (bound != nullptr) {
      selLo = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(bound) + 0x160);
      selHi = *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(bound) + 0x164);
    }
  }

  reinterpret_cast<V0>(listVtbl[0x458 / 4])(list); // clear list

  int* character = DAT_00d1b6d8;
  if (character != nullptr) {
    // --- vehicle cargo ---
    int* veh = *reinterpret_cast<int**>(reinterpret_cast<char*>(character) + 0x250);
    if (veh != nullptr) {
      int* cargo = *reinterpret_cast<int**>(reinterpret_cast<char*>(veh) + 0x2b0);
      if (cargo != nullptr) {
        FUN_0040db00();
        WalkGridAddFlagged(list, cargo);
        FUN_0040dc40();
        // DeleteCriticalSection(&_Stack_434);
      }
    }

    // --- locker (gated by UI flag +0xf5) ---
    int* locker = *reinterpret_cast<int**>(reinterpret_cast<char*>(character) + 0xcbc);
    if (locker != nullptr && DAT_00d1b644[0xf5] != 0) {
      FUN_0040db00();
      if (*reinterpret_cast<int*>(reinterpret_cast<char*>(locker) + 0x50) != 0) {
        FUN_004294f0();
        void* iter = nullptr;
        int* item = nullptr;
        int done = FUN_004022a0(&iter, &item);
        char buf[1024];
        while (done == 0) {
          if (item != nullptr && ItemHasListFlag(item)) {
            const char* name = ItemDisplayName(item);
            // Prefix with "[L]" via string helpers then sprintf("%s %s", ...)
            void* pref = FUN_007a69d0(DAT_00a3af64);
            const char* tagged = static_cast<const char*>(FUN_007a6de0(pref, -1));
            // Live: FUN_007a69d0("[L]") then combine with item name; sprintf
            std::sprintf(buf, "%s %s", tagged, name);
            ListAddEntry(list, item, buf);
          }
          done = FUN_004022a0(&iter, &item);
        }
        FUN_0040c700();
      }
      FUN_0040dc40();
    }

    // --- equip TFID table @ char+0x5a0 ---
    int n = FUN_00522000();
    char buf[1024];
    for (int i = 0; i < n; ++i) {
      auto* base = reinterpret_cast<char*>(character) + 0x5a0 + (i & 0xff) * 8;
      std::uint32_t elo = *reinterpret_cast<std::uint32_t*>(base);
      std::uint32_t ehi = *reinterpret_cast<std::uint32_t*>(base + 4);
      if ((elo & ehi) == kInvalidHalf)
        continue;
      int* obj = CVOGReaction_ResolveObjectTarget(1, elo, ehi);
      if (obj == nullptr)
        continue;
      const char* name = ItemDisplayName(obj);
      void* pref = FUN_007a69d0(DAT_00a3af60); // "[M]"
      const char* tagged = static_cast<const char*>(FUN_007a6de0(pref, -1));
      std::sprintf(buf, "%s %s", tagged, name);
      ListAddEntry(list, obj, buf);
    }
  }

  // Restore selection
  reinterpret_cast<VSetPair>(listVtbl[0x448 / 4])(list, selLo, selHi);
  *reinterpret_cast<int*>(reinterpret_cast<char*>(list) + 0x568) = 0;
  reinterpret_cast<VSetI>(listVtbl[0x498 / 4])(list, snapB);

  std::uint32_t curLo = 0, curHi = 0;
  reinterpret_cast<VGetPair>(listVtbl[0x44c / 4])(list);
  // curLo = EAX; curHi = EDX;

  if (curLo != selLo || curHi != selHi) {
    Client_UI_CraftHost_BindObjectByTfid_Inferred(host, curLo, curHi);
  }

  if (reinterpret_cast<V0>(listVtbl[0x490 / 4])(list) != snapA) {
    FUN_007fbd30(); // EAX=list, ESI=*(host+0x758)
  }
}
