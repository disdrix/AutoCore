// =============================================================================
// InventoryGrid_CompleteDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_005725a0
// Address:   0x005725a0–0x0057264d inclusive (174 B / 0xAE, autoassault.exe base 0x400000)
// System:    inventory-transfer / InventoryGrid MSVC complete-object destructor
// Generated: 2026-08-05 MEGA-061 dual A/B (decompile + disassemble_function + read_memory)
// Exactness: Behavior-preserving rewrite of full-body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_005725a0 (decompiler body truncated at false-noreturn; bytes win)
// =============================================================================
//
// PURPOSE:
//   MSVC complete-object destructor for InventoryGrid (vtbl PTR_FUN_009d3390,
//   object size 0x68). Reverse of InventoryGrid_ctor_Inferred (0x00572650).
//   Sole code caller: InventoryGrid_ScalarDeletingDtor (0x00573910 / vtbl[0]).
//   Does NOT free the host heap block — scalar-deleting dtor owns that.
//
// ABI:
//   __thiscall; ECX=this; no stack formals; void; bare RET (C3).
//   Entry:  6A FF 68 42 4F 9A 00 … 8B F9
//   Exit:   5F 5E 5B 64 89 0D 00 00 00 00 83 C4 14 C3
//
// LAYOUT (dtor order):
//   +0x00  vtbl → reinstall PTR_FUN_009d3390
//   +0x28  cell array* → operator_delete[] + null
//   +0x2c  embedded list host → vtbl step 009d3384→009cb334 + FUN_004bc950×2
//   +0x30  CRITICAL_SECTION → DeleteCriticalSection
//   +0x5c  RB-map object → erase-all FUN_00573700, free sentinel, zero head/size
//   +0x60  map _Myhead (sentinel*)
//   +0x64  map _Mysize
//
// TWINS / RELATED:
//   InventoryGrid_ScalarDeletingDtor              — 0x00573910 vtbl[0] (dualed)
//   InventoryGrid_ctor_Inferred                   — 0x00572650 reverse
//   InventoryGrid_ClearItemsAndReEmptyCells_Inferred — 0x00570f70 first stage
//   InventoryGrid_AllocateCellArray_Inferred      — used by clear
// =============================================================================

#include <cstdint>
#include <windows.h>

struct InventoryGrid;
struct ListHost;
struct MapHost;

// Dualed / named elsewhere
void __fastcall InventoryGrid_ClearItemsAndReEmptyCells_Inferred(InventoryGrid* grid); // 0x00570f70

// Residual helpers (not owned by MEGA-061)
// Map erase-range: this=map@+0x5c; clears nodes [first, last)
void __thiscall FUN_00573700(MapHost* map, void* outIt, void* first, void* last);
// List drain under CS (shared list-family helper)
void __fastcall FUN_004bc950(ListHost* list);

extern "C" void operator_delete(void* p);     // 0x00489822
extern "C" void operator_delete[](void* p);   // 0x0048981c

// Retail vtable / SEH symbols (Ghidra labels)
extern "C" void* PTR_FUN_009d3390;
extern "C" void* PTR_FUN_009d3384;
extern "C" void* PTR_FUN_009cb334;
extern "C" void* LAB_009a4f42;
extern "C" void* ExceptionList;

static constexpr std::uintptr_t kOffCellArray = 0x28;
static constexpr std::uintptr_t kOffListHost  = 0x2c;
static constexpr std::uintptr_t kOffCritSec   = 0x30;
static constexpr std::uintptr_t kOffMap       = 0x5c;
static constexpr std::uintptr_t kOffMapHead   = 0x60; // map+4
static constexpr std::uintptr_t kOffMapSize   = 0x64; // map+8

/// InventoryGrid complete-object destructor (does not free host).
/// @param self  InventoryGrid* (retail this / ECX).
void __thiscall InventoryGrid_CompleteDtor(InventoryGrid* self)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(self);

    // --- SEH frame (MSVC) — preserved for exactness ---
    void* puStack_8 = &LAB_009a4f42;
    void* pvStack_c = ExceptionList;
    ExceptionList = &pvStack_c;
    (void)puStack_8;
    (void)pvStack_c;

    // Reinstall primary vtbl (standard complete-dtor prologue).
    *reinterpret_cast<void**>(base) = &PTR_FUN_009d3390;

    // 1) Destroy/queue every list-held item, drain list, re-empty cells.
    InventoryGrid_ClearItemsAndReEmptyCells_Inferred(self);

    // 2) Free cell occupancy buffer (null-safe).
    void* cells = *reinterpret_cast<void**>(base + kOffCellArray);
    if (cells != nullptr) {
        operator_delete[](cells);
    }
    *reinterpret_cast<void**>(base + kOffCellArray) = nullptr;

    // 3) Destroy RB-map at +0x5c: erase all, free sentinel, zero head/size.
    auto* map = reinterpret_cast<MapHost*>(base + kOffMap);
    void* head = *reinterpret_cast<void**>(base + kOffMapHead);
    void* begin = *reinterpret_cast<void**>(head);
    std::uint8_t outIt[4];
    FUN_00573700(map, outIt, begin, head);
    operator_delete(head);
    *reinterpret_cast<void**>(base + kOffMapHead) = nullptr;
    *reinterpret_cast<std::uint32_t*>(base + kOffMapSize) = 0;

    // 4) Destroy embedded list host at +0x2c (inheritance vtbl step).
    auto* list = reinterpret_cast<ListHost*>(base + kOffListHost);
    *reinterpret_cast<void**>(list) = &PTR_FUN_009d3384;
    FUN_004bc950(list);
    *reinterpret_cast<void**>(list) = &PTR_FUN_009cb334;
    FUN_004bc950(list);

    // 5) Tear CRITICAL_SECTION constructed at +0x30 (list+4 / grid+0x30).
    DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(base + kOffCritSec));

    // SEH restore + bare RET (machine epilogue).
    ExceptionList = pvStack_c;
}
