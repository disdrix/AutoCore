// =============================================================================
// InventoryGrid_ctor_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Construct a 0x68-byte inventory grid: install vtables, init critical
//           section + RB-tree sentinel, store width/height/pages (clamped ≥1),
//           then allocate an empty cell array.
//
// Address:  0x00572650  (autoassault.exe, image base 0x400000)
// Stable:   aa_00572650
// System:   inventory-transfer
//
// Convention: MSVC __thiscall
// Name:       INFERRED — retail symbol not recovered.
//
// Parameters:
//   nWidth   cargo default 6
//   nHeight  cargo = pages * 13
//   nPages   chassis InventorySlots page count (clamped ≥1)
//
// Layout writes:
//   +0x00  vtable PTR_FUN_009d3390
//   +0x04  0
//   +0x08  width
//   +0x0C  height
//   +0x14  pages
//   +0x20..+0x22  zero bytes
//   +0x24  0
//   +0x28  cell array (via Allocate)
//   +0x2C  nested object vtable (CS host)
//   +0x30  CRITICAL_SECTION
//   +0x48..+0x54  nested zero-init
//   +0x58  0
//   +0x60  RB-tree sentinel
//   +0x64  0  (tree size)
//
// Related:  InventoryGrid_AllocateCellArray_Inferred,
//           Vehicle_CreateCargoInventoryFromPageCount
// Exactness: Preserves SEH frame shape and store order from decompiler.
// =============================================================================

#include <cstdint>
#include <windows.h>

static constexpr std::uintptr_t kOffWidth      = 0x08;
static constexpr std::uintptr_t kOffHeight     = 0x0c;
static constexpr std::uintptr_t kOffPages      = 0x14;
static constexpr std::uintptr_t kOffFlags20    = 0x20;
static constexpr std::uintptr_t kOffUnk24      = 0x24;
static constexpr std::uintptr_t kOffCellArray  = 0x28;
static constexpr std::uintptr_t kOffCsHost     = 0x2c;
static constexpr std::uintptr_t kOffCritSec    = 0x30;
static constexpr std::uintptr_t kOffCsHost48   = 0x48;
static constexpr std::uintptr_t kOffCsHost4c   = 0x4c;
static constexpr std::uintptr_t kOffCsHost50   = 0x50;
static constexpr std::uintptr_t kOffCsHost54   = 0x54;
static constexpr std::uintptr_t kOffUnk58      = 0x58;
static constexpr std::uintptr_t kOffTreeRoot   = 0x60;
static constexpr std::uintptr_t kOffTreeSize   = 0x64; // decimal 100

// Retail vtable symbols (Ghidra labels).
extern "C" void* PTR_FUN_009d3390;
extern "C" void* PTR_FUN_009cb334;
extern "C" void* PTR_FUN_009d3384;
extern "C" void* LAB_009a4f62;
extern "C" void* ExceptionList;

// Callees
std::int32_t FUN_005ae2b0(); // allocate RB-tree sentinel node
void InventoryGrid_AllocateCellArray_Inferred(void* pGrid);

struct InventoryGrid;

/// Construct inventory grid in-place (0x68 bytes).
/// @return this
void* InventoryGrid_ctor_Inferred(InventoryGrid* self,
                                  std::int32_t nWidth,
                                  std::int32_t nHeight,
                                  std::int32_t nPages)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(self);

    // --- SEH frame (MSVC) — preserved for exactness ---
    std::uint32_t nSehState = 0xFFFFFFFFu;
    void*         puStack_8 = &LAB_009a4f62;
    void*         pExceptionList = ExceptionList;
    ExceptionList = &pExceptionList;
    (void)nSehState;
    (void)puStack_8;

    // Primary vtable
    *reinterpret_cast<void**>(base) = &PTR_FUN_009d3390;

    // Nested CS-host object at +0x2C: provisional vtable, zero fields, then CS
    *reinterpret_cast<void**>(base + kOffCsHost)   = &PTR_FUN_009cb334;
    *reinterpret_cast<std::uint32_t*>(base + kOffCsHost4c) = 0;
    *reinterpret_cast<std::uint32_t*>(base + kOffCsHost48) = 0;
    *reinterpret_cast<std::uint32_t*>(base + kOffCsHost50) = 0;
    *reinterpret_cast<std::uint8_t*>(base + kOffCsHost54)  = 0;

    InitializeCriticalSection(
        reinterpret_cast<LPCRITICAL_SECTION>(base + kOffCritSec));

    // Promote nested vtable after CS init
    *reinterpret_cast<void**>(base + kOffCsHost) = &PTR_FUN_009d3384;
    nSehState = 0;

    // RB-tree sentinel: self-referential parent/left/right; black flag at +0x19
    std::int32_t pTreeSentinel = FUN_005ae2b0();
    *reinterpret_cast<std::int32_t*>(base + kOffTreeRoot) = pTreeSentinel;
    *reinterpret_cast<std::uint8_t*>(pTreeSentinel + 0x19) = 1;
    *reinterpret_cast<std::int32_t*>(pTreeSentinel + 4) = pTreeSentinel; // parent
    *reinterpret_cast<std::int32_t*>(pTreeSentinel)     = pTreeSentinel; // left
    *reinterpret_cast<std::int32_t*>(pTreeSentinel + 8) = pTreeSentinel; // right
    *reinterpret_cast<std::uint32_t*>(base + kOffTreeSize) = 0;

    // Height first (store order matches decompiler)
    *reinterpret_cast<std::int32_t*>(base + kOffHeight) = nHeight;
    nSehState = (nSehState & 0xFFFFFF00u) | 1u;

    *reinterpret_cast<std::uint32_t*>(base + 0x04)         = 0;
    *reinterpret_cast<std::uint32_t*>(base + kOffUnk24)    = 0;
    *reinterpret_cast<std::uint32_t*>(base + kOffCellArray)= 0;
    *reinterpret_cast<std::uint32_t*>(base + kOffUnk58)    = 0;
    base[kOffFlags20 + 0] = 0;
    base[kOffFlags20 + 1] = 0;
    base[kOffFlags20 + 2] = 0;

    *reinterpret_cast<std::int32_t*>(base + kOffWidth) = nWidth;
    *reinterpret_cast<std::int32_t*>(base + kOffPages) = nPages;

    // Clamp dimensions and page count to ≥ 1
    if (nPages < 1) {
        *reinterpret_cast<std::int32_t*>(base + kOffPages) = 1;
    }
    if (*reinterpret_cast<std::int32_t*>(base + kOffWidth) < 1) {
        *reinterpret_cast<std::int32_t*>(base + kOffWidth) = 1;
    }
    if (*reinterpret_cast<std::int32_t*>(base + kOffHeight) < 1) {
        *reinterpret_cast<std::int32_t*>(base + kOffHeight) = 1;
    }

    InventoryGrid_AllocateCellArray_Inferred(self);

    ExceptionList = pExceptionList;
    return self;
}
