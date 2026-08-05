// =============================================================================
// Character_SwitchVehicle_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Client character chassis switch: migrate cargo if new vehicle has
//           fewer inventory pages, deactivate old hardpoints, create new cargo
//           grid, optional phys/wheelset init, rebind pose/flags, activate new
//           hardpoints, then stow old vehicle into inventory (dual-fit try).
//           Failure to fit logs:
//             "switched vehicles, and no room for old vehicle in either inventory"
//             "VOG_DEBUG_STOP"
//
// Address:  0x005252f0  (autoassault.exe, image base 0x400000)
// End:      0x00525a93 exclusive (1955 / 0x7A3 bytes)
// Stable:   aa_005252f0
// Ghidra:   FUN_005252f0
// Machine:  55 8B EC 83 E4 F0 ... 33 C0 ... C2 10 00
//
// Convention: MSVC __thiscall; 4 stack formals; RET 0x10
//   ECX = Character* (vehicle at +0x250)
//   [ebp+08] = Vehicle* newVehicle
//   [ebp+0C] = Vehicle** outOld (optional)
//   [ebp+10] = uint argA
//   [ebp+14] = uint argB
// Returns:  HRESULT 0 / 0x80070057 / 0x80004005
//
// Callers:  FUN_00810360 (Client vehicle-switch packet path) @ 0x008104a4
//           FUN_0093d880 @ 0x0093d95b
// Named nested:
//   Vehicle_DeactivateHardpointWeapons_Inferred (0x004f4eb0)
//   Vehicle_ActivateHardpointWeapons_Inferred   (0x004f4f00)  [W25-E owned]
//   Vehicle_CreateCargoInventoryFromPageCount   (0x004f3a30)
//   Vehicle_SetWheelset                         (named)
//   InventoryGrid_ctor_Inferred
//
// Exactness: Stage CF from live decompile; not a line-by-line modernization.
// Bit-for-bit / runtime / differential: OPEN (large coordinator).
// Dual A/B (static): SEALED accept-with-gaps 2026-07-29 (W25-E).
// =============================================================================

#include <cstdint>

struct Character;
struct Vehicle;
struct InventoryGrid;

// Nested (declared only; duals live elsewhere)
InventoryGrid *InventoryGrid_ctor_Inferred(void *mem, int cols, int cells, int pages);
char FUN_00572360(/* InventoryGrid_RePlaceItems family */);
void Vehicle_DeactivateHardpointWeapons_Inferred(Vehicle *v);
void Vehicle_ActivateHardpointWeapons_Inferred(Vehicle *v);
void Vehicle_CreateCargoInventoryFromPageCount(Vehicle *v, short pages);
void Vehicle_SetWheelset(/* ... */);
char FUN_005714e0(/* inventory fit probe */);
void FUN_00571620(/* inventory place */);
void FUN_007a4480(const char *msg, /* ... */);

extern float g_flOne;       // 0x00a0f2a0 = 1.0f
extern float DAT_00a0f704;  // 0x00a0f704 = 0.25f

/// Switch character onto newVehicle; optionally write prior vehicle to *outOld.
/// @return 0 on success; 0x80070057 if newVehicle null; 0x80004005 on hard fail.
std::uint32_t __thiscall Character_SwitchVehicle_Inferred(
    Character *self,
    Vehicle *newVehicle,
    Vehicle **outOldVehicle,
    std::uint32_t argA,
    std::uint32_t argB)
{
    // --- Guard ---------------------------------------------------------------
    if (newVehicle == nullptr) {
        return 0x80070057u; // E_INVALIDARG
    }

    auto *self_b = reinterpret_cast<std::uint8_t *>(self);
    Vehicle *oldVehicle = *reinterpret_cast<Vehicle **>(self_b + 0x250);

    if (outOldVehicle != nullptr) {
        *outOldVehicle = oldVehicle;
    }

    auto *new_b = reinterpret_cast<std::uint8_t *>(newVehicle);
    auto *old_b = reinterpret_cast<std::uint8_t *>(oldVehicle);

    // --- Cargo shrink migrate (new pages < old pages) ------------------------
    short newPages = *reinterpret_cast<short *>(new_b + 0x1e6);
    short oldPages = *reinterpret_cast<short *>(old_b + 0x1e6);
    if (newPages < oldPages) {
        void *mem = operator new(0x68);
        InventoryGrid *grid = nullptr;
        if (mem != nullptr) {
            grid = InventoryGrid_ctor_Inferred(mem, 6, newPages * 0x0d, newPages);
        }
        if (FUN_00572360(/* migrate into temp grid */) == 0) {
            if (grid != nullptr) {
                // vtbl destroy
            }
            return 0x80004005u; // E_FAIL
        }
        // second RePlace + destroy temp grid path (see raw)
        (void)grid;
    }

    // --- Snapshot old transforms; flag; deactivate hardpoints ----------------
    // motion host via vtbl+0x1c8; copy two float4 blocks (raw uStack_40/_30)
    // set object flags | 0x10 at adjusted +0x180; FUN_00512670
    Vehicle_DeactivateHardpointWeapons_Inferred(oldVehicle); // 0x004f4eb0

    // --- New cargo + mark old ------------------------------------------------
    // clear new gate byte; create cargo from page count
    Vehicle_CreateCargoInventoryFromPageCount(newVehicle, newPages);
    *(old_b + 0x2ac) = 1;
    // FUN_00572360 with new cargo pointer; re-flag old; FUN_00512670

    // --- Optional chassis/phys @ new+0x258 -----------------------------------
    if (*reinterpret_cast<void **>(new_b + 0x258) == nullptr) {
        void *phys = operator new(0x2f0);
        // FUN_005a84f0 ctor; vtbl+8 init; fail → E_FAIL
        if ((argA & argB) == 0xFFFFFFFFu) {
            // bump 64-bit counter at host+0xe6e0 / +0xe6e4
        }
        // FUN_00512160; set +0xcc=1; vtbl+0x218; Vehicle_SetWheelset
        (void)phys;
    }

    // --- Post-bind pose/flags/nested activate --------------------------------
    // FUN_004f7690; FUN_004f7830; copy host+0xf5 → new+0x101; clear old+0x114
    // nested vtbl activates at +0x258 / +0x26c / motion slot +0x40
    // FUN_004f39c0; *(new[0xa1]+0x5c) = DAT_00a0f704 (0.25f)

    // --- Activate hardpoint weapons ------------------------------------------
    // Call site reloads ECX from character+0x250
    Vehicle *cur = *reinterpret_cast<Vehicle **>(self_b + 0x250);
    Vehicle_ActivateHardpointWeapons_Inferred(cur); // 0x004f4f00

    // --- Stow old vehicle into inventory -------------------------------------
    // FUN_005714e0 try #1 → FUN_00571620 on success
    // else FUN_005714e0 try #2 → FUN_00571620 on success
    // else FUN_007a4480("switched vehicles, and no room for old vehicle in either inventory")
    //      FUN_007a4480("VOG_DEBUG_STOP")
    (void)argA;
    (void)argB;
    (void)g_flOne;
    (void)DAT_00a0f704;

    return 0; // S_OK
}
