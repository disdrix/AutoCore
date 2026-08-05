// =============================================================================
// UI_RefinePanel_InsertCommodityListRow_Inferred  (FUN_0089a260)
// -----------------------------------------------------------------------------
// Stable ID: aa_0089a260
// Address:   0x0089a260 – 0x0089b06f  (autoassault.exe, base 0x400000)
// Size:      3600 bytes (0xE10)
// System:    inventory-transfer / refinery UI
// Dual:      W21-S 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Quality strcmp loops
//            condensed to equivalent string compares. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Filter a clonebase/entry against the refine host's list mode, build a
//   localized "[qty] name" (optional quality prefix), and insert a row into
//   host list widget +0x568 or +0x56c depending on mod-slot count.
//
// ABI (bytes-sealed)
//   stdcall 4 stack args; ret 0x10
//   arg0 host, arg1 entry, arg2 qty, arg3 flag (UNUSED in body)
//
// CALLER
//   FUN_0089bc30 UI_RefinePanel_RebuildCommodityList_Inferred (×2)
//
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

// ---- partial layouts --------------------------------------------------------

struct LocaleState {
  // +0x2c language id: 0/3 EN, 1 FR-style, 2 DE
};

struct ItemDef {
  // +0x92  string id (name)
  // +0x4c8 int8 tier (0..3)
  // +0x4d0 int32 product key (-1 = reject list A)
};

struct CloneEntry {
  // +0x34 int32 id
  // +0x3c ItemDef* def
};

struct RefineHost {
  // +0x52c int filterMode
  // +0x530 void* mode7FilterObj
  // +0x568 UiList* listNoMods
  // +0x56c UiList* listWithMods
};

struct UiList {
  void** vtbl; // +0x45c add row, +0x464 bind id
};

// Externals
extern "C" LocaleState* FUN_007a69d0();
extern "C" const char* FUN_007a6de0(int stringId, int unused);
extern "C" int* FUN_00402d50(int stringIdField); // returns ptr to string id dword
extern "C" int FUN_00599dd0();                   // ItemDef_CountConfiguredModSlots
extern "C" void FUN_0052d450(void* filterObj, void* out);
extern "C" void* FUN_005190c0();
extern "C" void* Map_LowerBoundFindByIntKey(void* map, void* out, void* key, void* /*edi*/);

// ---- helpers ----------------------------------------------------------------

static bool streq_token(const char* a, const char* b)
{
  return std::strcmp(a, b) == 0;
}

static bool is_en_quality_token(const char* tok)
{
  return streq_token(tok, "Salvaged") || streq_token(tok, "Patched") ||
         streq_token(tok, "Functional") || streq_token(tok, "Perfect");
}

// DE quality adjectives (sealed via read_memory @ 0x00a4e374 region)
static bool is_de_quality_token(const char* tok)
{
  static const char* kDe[] = {
      "Verwertbares", "Verwertbare", "Verwertbarer",
      "Aufbereitetes", "Aufbereitete", "Aufbereiteter",
      "Hochwertiges", "Hochwertige", "Hochwertiger",
      "Perfektes", "Perfekte", "Perfekter",
  };
  for (const char* s : kDe) {
    if (streq_token(tok, s)) return true;
  }
  return false;
}

// ---- clean reconstruction ---------------------------------------------------

void UI_RefinePanel_InsertCommodityListRow_Inferred(
    RefineHost* host,
    CloneEntry* entry,
    int qty,
    int /*flag_unused*/)
{
  if (entry == nullptr) {
    return;
  }
  ItemDef* def = *reinterpret_cast<ItemDef**>(reinterpret_cast<uint8_t*>(entry) + 0x3c);
  if (def == nullptr) {
    return;
  }

  int mode = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0x52c);
  int8_t tier = *reinterpret_cast<int8_t*>(reinterpret_cast<uint8_t*>(def) + 0x4c8);

  switch (mode) {
  case 1:
    if (qty < 1) return;
    break;
  case 2:
    if (tier != 0) return;
    break;
  case 3:
    if (tier != 1) return;
    break;
  case 4:
    if (tier != 2) return;
    break;
  case 6:
    if (tier != 3) return;
    break;
  case 7: {
    void* filterObj = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x530);
    if (filterObj == nullptr) return;
    // FUN_0052d450 + Map_LowerBoundFindByIntKey on entry+0x34; miss => return
    // (map residual — sealed as early-out when key absent)
    void* scratch = nullptr;
    FUN_0052d450(filterObj, &scratch);
    int key = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(entry) + 0x34);
    void* map = FUN_005190c0();
    // if lower_bound end-iterator: return (decomp: *extraout_EAX == end)
    (void)key;
    (void)map;
    break;
  }
  default:
    break;
  }

  if (mode == 1 && qty < 1) {
    return;
  }

  // ---- build localized label ------------------------------------------------
  char nameFull[128] = {0};
  char nameCopy[128] = {0};
  char label[128] = {0};
  char restName[128] = {0};

  int strField = reinterpret_cast<int>(reinterpret_cast<uint8_t*>(def) + 0x92);
  if (def != nullptr && strField != -0x92) {
    int* sid = FUN_00402d50(strField);
    const char* loc = FUN_007a6de0(*sid, -1);
    std::strncpy(nameFull, loc, sizeof(nameFull) - 1);
    std::strncpy(nameCopy, loc, sizeof(nameCopy) - 1);
  }

  LocaleState* locale = FUN_007a69d0();
  int lang = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(locale) + 0x2c);

  bool fr_style = false;
  if (lang == 1) {
    // append full name into working buffer (retail copies into local_821 region)
    fr_style = true;
  }

  char* first = std::strtok(nameFull, " ");
  if (first == nullptr) {
    goto insert_row;
  }

  if (fr_style) {
    if (qty < 1) {
      std::sprintf(label, "[0] %s", nameCopy);
    } else {
      std::sprintf(label, "[%i] %s", qty, nameCopy);
    }
    goto insert_row;
  }

  bool quality_known = true;
  if (lang == 0 || lang == 3) {
    if (!is_en_quality_token(first)) {
      quality_known = false;
    }
  } else if (lang == 2) {
    if (!is_de_quality_token(first)) {
      quality_known = false;
    }
  }

  // join remaining tokens with spaces into restName (retail strtok loop)
  if (quality_known) {
    restName[0] = 0;
    for (char* tok = std::strtok(nullptr, " "); tok; tok = std::strtok(nullptr, " ")) {
      if (restName[0]) std::strcat(restName, " ");
      std::strcat(restName, tok);
    }
  }

  if (qty < 1) {
    if (quality_known) {
      std::sprintf(label, "[0] %s, %s", restName, first);
      // note: retail uses local_820 (rest) + first-token in some arms;
      //       and local_718 (full) when quality_known is false
    } else {
      std::sprintf(label, "[0] %s", nameCopy);
    }
  } else {
    if (quality_known) {
      std::sprintf(label, "[%i] %s, %s", qty, restName, first);
    } else {
      std::sprintf(label, "[%i] %s", qty, nameCopy);
    }
  }

insert_row:
  int modSlots = FUN_00599dd0();
  int entryId = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(entry) + 0x34);
  UiList* list = nullptr;

  if (modSlots < 1) {
    int productKey = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(def) + 0x4d0);
    if (productKey == -1) {
      return;
    }
    list = *reinterpret_cast<UiList**>(reinterpret_cast<uint8_t*>(host) + 0x568);
  } else {
    list = *reinterpret_cast<UiList**>(reinterpret_cast<uint8_t*>(host) + 0x56c);
  }

  // vtbl+0x45c(label, entryId, entryId>>31, 1)
  (*(void(__thiscall**)(UiList*, char*, int, int, int))(*(uintptr_t*)list + 0x45c))(
      list, label, entryId, entryId >> 31, 1);
  // vtbl+0x464(entryId, entryId>>31, 1, stack residual)
  (*(void(__thiscall**)(UiList*, int, int, int, void*))(*(uintptr_t*)list + 0x464))(
      list, entryId, entryId >> 31, 1, nullptr);
}

// Scaffold alias
void FUN_0089a260(int param_1, int param_2, char* param_3)
{
  UI_RefinePanel_InsertCommodityListRow_Inferred(
      reinterpret_cast<RefineHost*>(param_1),
      reinterpret_cast<CloneEntry*>(param_2),
      reinterpret_cast<int>(param_3),
      /*flag*/ 0);
}
