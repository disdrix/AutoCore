// =============================================================================
// ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred  (FUN_0083ac90)
// -----------------------------------------------------------------------------
// Stable ID: aa_0083ac90
// Address:   0x0083ac90  (autoassault.exe, image base 0x400000)
// Body:      0x0083ac90 – 0x0083aeb4 inclusive (549 B / 0x225); pad CC after RET 4
// System:    shopveh list UI — five-slot window reindex around select
// Generated: 2026-08-05 WQ9K-H dual seal (decompile + disassemble_function + read_memory)
// Exactness: Behavior-preserving rewrite from body bytes / assembly listing.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: After the list select index changes, re-align the host's five visible
// slot objects (host+0x50c[5]) so each slot's control id encodes the list index
// it should display (id = list_i + 0x9ca4). When a needed index lives in a
// different slot, swap the two objects' select-state via dualed
// ShopVehObject_SwapSelectState_ESI_EDI_Inferred (FUN_00833160) — this function
// is that swap's sole caller. Leading/trailing out-of-range window slots are
// cleared (id = -1), optionally through FUN_00833d50 when obj+0x508 is set.
//
// Host layout (partial):
//   +0x4fc  int32  list_count (exclusive upper for list_i on in-range tests)
//   +0x500  int32  select_index (written here)
//   +0x50c  void*  slots[5]    // window centered on select (select-2..select+2)
//
// ABI (bytes): EAX = select_index at entry; stack host*; RET 4 (stdcall 1 arg).
// Call sites load EAX from host/related select field then PUSH host; CALL.

#include <cstdint>

static constexpr int kWindowSlots = 5;
static constexpr int kIdBase = 0x9ca4; // 40100 decimal

// External (image)
extern "C" uint8_t ShopVehObject_SwapSelectState_ESI_EDI_Inferred(void); // ESI/EDI
extern "C" uint8_t FUN_0083a860(/* EAX = list_i */);
extern "C" void FUN_0083a880(/* EAX = slot obj */, uint8_t flag);
extern "C" void __fastcall FUN_0083abf0(int slot, int list_i, void *host);
extern "C" void FUN_00833d50(/* EDI = slot obj */);

using GetIdFn = int(__thiscall *)(void *self);
using SetIdFn = void(__thiscall *)(void *self, int id);

static int GetControlId(void *obj)
{
  auto **vtbl = *reinterpret_cast<void ***>(obj);
  return reinterpret_cast<GetIdFn>(vtbl[0x78 / 4])(obj);
}

static void SetControlId(void *obj, int id)
{
  auto **vtbl = *reinterpret_cast<void ***>(obj);
  reinterpret_cast<SetIdFn>(vtbl[0x74 / 4])(obj, id);
}

// Portable reconstruction of register-pair ABI (product uses ESI/EDI/EAX).
// select_index is the live EAX argument at the CALL site.
extern "C" void ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred(
    void *host, int select_index)
{
  auto *base = reinterpret_cast<uint8_t *>(host);
  const int count = *reinterpret_cast<int *>(base + 0x4fc);
  void **slots = reinterpret_cast<void **>(base + 0x50c);

  if (select_index < 0 || select_index > count) {
    return;
  }

  *reinterpret_cast<int *>(base + 0x500) = select_index;

  for (int list_i = select_index - 2; list_i <= select_index + 2; ++list_i) {
    if (list_i < 0 || list_i >= count) {
      continue;
    }
    const int slot = list_i - select_index + 2;
    if (slot < 0 || slot >= kWindowSlots || slots[slot] == nullptr) {
      continue;
    }

    const int cur_list = GetControlId(slots[slot]) - kIdBase;
    if (cur_list == list_i) {
      // bytes: MOV EBX,EDI; MOV EAX,EBP(host path uses list_i in EAX for probe)
      if (FUN_0083a860(/* EAX = list_i */) == 0) {
        FUN_0083abf0(slot, list_i, host);
      } else {
        FUN_0083a880(/* EAX = slots[slot] */, 0);
      }
    } else {
      bool found = false;
      for (int j = 0; j < kWindowSlots; ++j) {
        if (j == slot || slots[j] == nullptr) {
          continue;
        }
        if (GetControlId(slots[j]) - kIdBase != list_i) {
          continue;
        }
        // bytes @ 0083ad64: EDI = slots[slot]; ESI = slots[j]; CALL 00833160
        // (register-pair swap — see ShopVehObject_SwapSelectState_ESI_EDI_Inferred)
        (void)ShopVehObject_SwapSelectState_ESI_EDI_Inferred();
        {
          const int id_from_target = GetControlId(slots[slot]);
          SetControlId(slots[j], id_from_target);
        }
        FUN_0083a880(/* EAX = slots[slot] */, 0);
        // CMP EBX,5 after swap: j is always < 5 → FUN_0083abf0 branch is dead
        found = true;
        break;
      }
      if (!found) {
        FUN_0083abf0(slot, list_i, host);
      }
    }

    SetControlId(slots[slot], list_i + kIdBase);
  }

  // Leading clear: slots [0 .. 2-select) when select < 2
  {
    const int lead = 2 - select_index;
    if (lead > 0) {
      for (int i = 0; i < lead; ++i) {
        void *obj = slots[i];
        if (obj == nullptr) {
          continue;
        }
        if (*reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(obj) + 0x508) != 0) {
          FUN_00833d50(/* EDI = obj */);
        }
        SetControlId(obj, -1);
      }
    }
  }

  // Trailing clear: slots [count-select+2 .. 5)
  {
    const int start = count - select_index + 2;
    if (start < kWindowSlots) {
      for (int i = start; i < kWindowSlots; ++i) {
        void *obj = slots[i];
        if (obj == nullptr) {
          continue;
        }
        if (*reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(obj) + 0x508) != 0) {
          FUN_00833d50(/* EDI = obj */);
        }
        SetControlId(obj, -1);
      }
    }
  }
}

// Ghidra / product entry shape: EAX=select, stack host, RET 4
extern "C" void FUN_0083ac90(void *host /* + EAX select */)
{
  // Caller must place select in EAX before CALL (see assembly context at xrefs).
  ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred(host, /*select via EAX*/ 0);
}
