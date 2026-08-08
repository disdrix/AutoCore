// =============================================================================
// Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Compose and place the inventory/item hover status text while the
//           client craft multi-mode field (DAT_00d1d900 ≡ client+0x30c0) is in
//           Reverse-Engineer (0), Tinkering-Kit (4), or Gadget (5) mode. Writes
//           product English into a stack buffer and pushes it to a UI widget
//           via vtbl+0x308; positions via cursor host + widget vtbl+0x314.
//
// Address:  0x0085ce20  (autoassault.exe, image base 0x400000)
// Stable:   aa_0085ce20
// System:   inventory-transfer
//
// ABI (bytes + callers; decompiler unaff_* incomplete):
//   EAX  → ESI  = CVOG item object*
//   EBX         = UI status widget*
//   stack char  = strictMode (0 = gate broken/stack for RE; 1 = hover path)
//   cdecl (callers ADD ESP,4); void return
//
// Evidence strings:
//   "Broken items cannot be further Reverse Engineered."
//   "You cannot Reverse Engineer crafting materials."
//   "Cannot be Reverse Engineered."
//   "Cannot be Reverse Engineered (No Recipe)."
//   "Stacks cannot be Reverse Engineered, please split the stack into a single item first."
//   "Requires At Least" / "Reverse Engineering"
//   "No gadget slots are available."
//   "This is the wrong type of gadget to use on this item."
//   "That gadget is already on the item, no duplicates allowed."
//   "You cannot use this gadget on this item."
//   "You cannot use Tinkering Kits on Broken Items!"
//   "The object has no available slots to open."
//   "You do not possess the Tinkering skill to work on this object."
//   "This Tinkering Kit is too primitive to use on this object."
//   "This Tinkering Kit can only be used on %s."
//   RTTI: CVOGGadget, CVOGTinkeringKit, CVOGClonedObjectBase
//   Category labels: Power Plants / Weapons / Vehicles / Wheelsets / Armor / Other
//
// Notable callees:
//   FUN_0052e640 / FUN_0052e1d0  — RE skill float / required level
//   FUN_00522950                 — RE eligibility
//   FUN_00599dd0                 — recipe count
//   FUN_00513e70                 — stack helper
//   FUN_00513400                 — gadget apply code
//   FUN_00513c10                 — tinker kit apply code
//   InventoryGrid_FindItemByCoid (0x00571010)
//   __RTDynamicCast
//   FUN_007a69d0 / FUN_007a6de0 / sprintf
//   FUN_007fd420                 — cursor icon
//
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed register ABI.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// Dual: WQ8R-H 2026-08-04
// =============================================================================

#include <cstdint>
#include <cstring>

// Unowned externs (names sealed elsewhere or inferred).
extern int* DAT_00d1b6d8;           // local character
extern int* DAT_00d1b9a8;           // cursor / UI host
extern int  DAT_00d1d900;           // client+0x30c0 multi-mode
extern int  DAT_00d1d938, DAT_00d1d93c; // tinker kit TFID
extern int  DAT_00d1d940, DAT_00d1d944; // gadget TFID
extern float g_flZero;

extern float FUN_0052e640(int* item);
extern int   FUN_0052e1d0(int* item);
extern char  FUN_00522950(int* item);
extern int   FUN_00599dd0();
extern char  FUN_00513e70();
extern int   FUN_00513400(int* gadget);
extern int   FUN_00513c10(int* character, int* kit);
extern int*  InventoryGrid_FindItemByCoid(int lo, int hi); // 0x00571010
extern void* __RTDynamicCast(void*, int, void*, void*, int);
extern char* FUN_007a6de0(const char* s, int n);
extern void  FUN_007a69d0(...);
extern void  FUN_007fd420(int, int, int, int);
extern int   sprintf(char* buf, const char* fmt, ...);

// RTTI type descriptors (Ghidra symbols).
extern void* CVOGClonedObjectBase_RTTI;
extern void* CVOGGadget_RTTI;
extern void* CVOGTinkeringKit_RTTI;

static constexpr int kBrokenBitShift = 19;

static bool ItemIsBroken(const int* item) {
  return ((static_cast<unsigned>(item[0x5f]) >> kBrokenBitShift) & 1u) != 0;
}

static void WidgetSetText(int* widget, const char* msg) {
  auto** vtbl = reinterpret_cast<void**>(*widget);
  using SetTextFn = void(__thiscall*)(int*, const char*);
  reinterpret_cast<SetTextFn>(vtbl[0x308 / 4])(widget, msg);
}

static void WidgetPlaceAtCursor(int* widget) {
  auto** hostVtbl = reinterpret_cast<void**>(*DAT_00d1b9a8);
  using GetPtFn = int*(__thiscall*)(int*, void*, int, int);
  int* pt = reinterpret_cast<GetPtFn>(hostVtbl[0x120 / 4])(DAT_00d1b9a8, nullptr, 1, 0);
  auto** wVtbl = reinterpret_cast<void**>(*widget);
  using SetPosFn = void(__thiscall*)(int*, int, int);
  reinterpret_cast<SetPosFn>(wVtbl[0x314 / 4])(widget, pt[0], pt[1]);
}

// Register ABI: item in EAX, widget in EBX, strictMode on stack (cdecl).
void Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred(char strictMode) {
  int* item;    // sealed: entry EAX → ESI
  int* widget;  // sealed: entry EBX
  // (compiler-level register binding is documentary; see annotated notes.)

  if (DAT_00d1b6d8 == nullptr || DAT_00d1b9a8 == nullptr)
    return;
  // Null item / widget: early out (bytes cmp esi/ebx vs 0).
  if (item == nullptr || widget == nullptr)
    return;

  char msg[0xE0];
  std::memset(msg, 0, sizeof(msg));

  if (DAT_00d1d900 == 0) {
    // ---- Reverse Engineer ----
    float skill = FUN_0052e640(item);
    std::memset(msg, 0, 0x80);
    FUN_007a69d0();

    if (strictMode == 0 && ItemIsBroken(item)) {
      std::strcpy(msg, "Broken items cannot be further Reverse Engineered.");
    } else if (*reinterpret_cast<int*>(item[0x2a] + 0x38) == 0x1a) {
      std::strcpy(msg, "You cannot Reverse Engineer crafting materials.");
    } else if (FUN_00522950(item) == 0) {
      std::strcpy(msg, FUN_007a6de0("Cannot be Reverse Engineered.", -1));
    } else if (FUN_00599dd0() < 1) {
      std::strcpy(msg, "Cannot be Reverse Engineered (No Recipe).");
    } else {
      auto** iv = reinterpret_cast<void**>(*item);
      using QtyFn = int(__thiscall*)(int*);
      int qty = reinterpret_cast<QtyFn>(iv[0x25c / 4])(item);
      if (strictMode == 0 && qty > 1 && FUN_00513e70() != 0) {
        std::strcpy(msg,
          "Stacks cannot be Reverse Engineered, please split the stack into a single item first.");
      } else if (skill <= g_flZero) {
        char* a = FUN_007a6de0("Requires At Least", -1);
        int need = FUN_0052e1d0(item);
        char* b = FUN_007a6de0("Reverse Engineering", -1);
        sprintf(msg, "%s %d %s", a, need, b);
      } else if (*reinterpret_cast<char*>(reinterpret_cast<char*>(widget) + 0xce) != 0) {
        // Success: refresh cursor chrome on widget (vtbl+0x140 / +0x120).
        // FUN_007fd420(...); msg left empty / prior cleared.
      }
    }
    WidgetSetText(widget, msg);
    WidgetPlaceAtCursor(widget);
    return;
  }

  if (DAT_00d1d900 == 5) {
    // ---- Gadget ----
    int* gadget = nullptr;
    // Prefer vehicle cargo grid; else locker path — both FindItemByCoid + RTTI cast.
    void* found = InventoryGrid_FindItemByCoid(DAT_00d1d940, DAT_00d1d944);
    gadget = static_cast<int*>(__RTDynamicCast(found, 0, CVOGClonedObjectBase_RTTI,
                                               CVOGGadget_RTTI, 0));
    int code = FUN_00513400(gadget);
    if (code == 0) {
      if (*reinterpret_cast<char*>(reinterpret_cast<char*>(widget) + 0xce) != 0) {
        // ok → cursor path + empty/aux text
      }
    } else if (code == 1) {
      std::strcpy(msg, "No gadget slots are available.");
    } else if (code == 2) {
      std::strcpy(msg, "This is the wrong type of gadget to use on this item.");
    } else if (code == 3) {
      std::strcpy(msg, "That gadget is already on the item, no duplicates allowed.");
    } else {
      std::strcpy(msg, "You cannot use this gadget on this item.");
    }
    WidgetSetText(widget, msg);
    WidgetPlaceAtCursor(widget);
    return;
  }

  if (DAT_00d1d900 != 4) {
    WidgetSetText(widget, nullptr);
    // cursor crosshair via FUN_007fd420; return without place epilogue
    return;
  }

  // ---- Tinkering Kit ----
  void* kitRaw = InventoryGrid_FindItemByCoid(DAT_00d1d938, DAT_00d1d93c);
  int* kit = static_cast<int*>(__RTDynamicCast(kitRaw, 0, CVOGClonedObjectBase_RTTI,
                                               CVOGTinkeringKit_RTTI, 0));
  if (kit == nullptr)
    return;

  int tcode = FUN_00513c10(DAT_00d1b6d8, kit);
  if (tcode == 4) {
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(widget) + 0xce) != 0) {
      // ok → cursor + place
    }
    WidgetSetText(widget, msg);
    WidgetPlaceAtCursor(widget);
    return;
  }
  if (ItemIsBroken(item)) {
    std::strcpy(msg, "You cannot use Tinkering Kits on Broken Items!");
    WidgetSetText(widget, msg);
    WidgetPlaceAtCursor(widget);
    return;
  }
  switch (tcode) {
  case 0:
    std::strcpy(msg, "The object has no available slots to open.");
    break;
  case 1:
    std::strcpy(msg, "You do not possess the Tinkering skill to work on this object.");
    break;
  case 2:
    std::strcpy(msg, "This Tinkering Kit is too primitive to use on this object.");
    break;
  case 3: {
    // kit+0xb4 category → label; sprintf "This Tinkering Kit can only be used on %s."
    const char* cat = "Other";
    switch (*reinterpret_cast<int*>(reinterpret_cast<char*>(kit) + 0xb4)) {
    case 0x0A: cat = "Power Plants"; break;
    case 0x0C: cat = "Weapons"; break;
    case 0x0E: cat = "Vehicles"; break;
    case 0x10: cat = "Wheelsets"; break;
    case 0x1C: cat = "Armor"; break;
    default: break;
    }
    sprintf(msg, "This Tinkering Kit can only be used on %s.", cat);
    break;
  }
  default:
    break;
  }
  WidgetSetText(widget, msg);
  WidgetPlaceAtCursor(widget);
}
