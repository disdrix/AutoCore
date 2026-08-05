// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×9, return×3.
//  - Notable callees: FUN_007a6de0×6, sprintf×2, Client_RecvInventoryAddItem, FUN_00513e70, FUN_00571010, FUN_00571830, FUN_007a69d0, FUN_0089c6c0.
//  - Strings: "Broken: "; "Received Loot"; "%s: %s%s"; "%s: %s%s x%d".
//  - Return sites: 3.

// =============================================================================
// Client_RecvInventoryAddItem
// -----------------------------------------------------------------------------
// Purpose:  S2C add-item notify - resolve object TFID, optionally post a loot
//           chat line, place into cargo (or re-find slot), refresh mission UI
//           and related widgets.
//
// Address:  0x008151a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008151a0
// System:   inventory-transfer
//
// Convention: client in stack arg; packet in EBX (`unaff_EBX`).
//   Prologue loads [ebx+8]/[ebx+0xc]; PacketDispatch case 0x2047 → this VA.
//
// Packet fields (decompiler offsets on EBX; wire size 0x20):
//   +0x08/+0x0c  item COID lo/hi (TFID key for resolve / find / place)
//   +0x10/+0x11  cargo X/Y on wire — NOT read by this body (client re-finds)
//   +0x12        bAddToExistingItem — non-zero + in-grid → merge place
//   +0x14        i32 quantity (loot "x%d" and FUN_00571830 delta)
//   +0x18        bWasSuccessful (zero → early return after resolve)
//
// Control flow summary:
//   1) resolve item by COID; null → return
//   2) success@+0x18 == 0 → return
//   3) optional loot chat line (qty@+0x14, Broken bit, channel 0x17)
//   4) if @+0x12==0 OR no char/vehicle OR not in grid (FUN_00571010):
//        re-find / full place FUN_00945540(client)
//      else:
//        qty merge FUN_00571830(qty, lo, hi)
//   5) refresh inventory widgets + mission-related UI
//
// Related: docs/inventory-cargo-wire-re.md (0x2047 AddItem re-finds slot)
// Exactness: Preserves loot formatting branches and place vs re-find gate.
// Dual reviews: A/B accept-with-gaps; residual 2026-07-29 reviews/a_008151a0.md
// =============================================================================

#include <cstdint>
#include <cstdio>

extern std::int32_t  DAT_00d1b8dc; // chat / combat log host
extern std::int32_t* DAT_00d1b894; // optional UI widget
extern std::uint8_t  DAT_00a1419b; // empty prefix string ""

void         FUN_007a69d0();
void*        CVOGReaction_ResolveObjectTarget(std::int32_t a, std::uint32_t lo,
                                              std::uint32_t hi);
char         FUN_00513e70();
char*        FUN_007a6de0(const char* key, std::uint32_t a);
void         FUN_008f8200(std::int32_t host, std::int32_t channel, void* prefix,
                          char* msg, std::int32_t z);
void         FUN_00945540(std::int32_t client); // re-find / full refresh place
void         FUN_00571830(std::uint32_t qty, std::uint32_t lo, std::uint32_t hi);
std::int32_t FUN_00571010(std::uint32_t lo, std::uint32_t hi); // find in grid
void         FUN_0089c6c0(std::int32_t a);
void         FUN_0092ce90();

void Client_RecvInventoryAddItem(std::int32_t client)
{
    std::int32_t packet = 0; // unaff_EBX
    char         msgBuf[256];

    FUN_007a69d0();

    std::int32_t* item = reinterpret_cast<std::int32_t*>(
        CVOGReaction_ResolveObjectTarget(
            1,
            *reinterpret_cast<std::uint32_t*>(packet + 8),
            *reinterpret_cast<std::uint32_t*>(packet + 0xc)));

    std::int32_t chatHost = DAT_00d1b8dc;

    if (item == nullptr) {
        return;
    }

    // success/apply flag @ +0x18
    if (*reinterpret_cast<char*>(packet + 0x18) == '\0') {
        return;
    }

    // --- Optional "Received Loot" combat-log line ---
    if (DAT_00d1b8dc != 0) {
        char canLootLine = FUN_00513e70();
        std::uint8_t* brokenPrefix;
        char* nameStr;
        char* lootHdr;

        if (canLootLine == '\0'
            || *reinterpret_cast<std::int32_t*>(packet + 0x14) < 2) {
            // Single / no quantity suffix
            if (((static_cast<std::uint32_t>(item[0x5f]) >> 0x13) & 1u) == 0) {
                brokenPrefix = &DAT_00a1419b; // ""
            } else {
                brokenPrefix = reinterpret_cast<std::uint8_t*>(
                    FUN_007a6de0("Broken: ", 0xFFFFFFFFu));
            }
            nameStr = reinterpret_cast<char*>(
                (**(std::uint32_t(**)(std::uint32_t))(*item + 0x15c))(
                    0xFFFFFFFFu));
            nameStr = FUN_007a6de0(nameStr, 0xFFFFFFFFu);
            lootHdr = FUN_007a6de0("Received Loot", 0xFFFFFFFFu);
            std::sprintf(msgBuf, "%s: %s%s", lootHdr, brokenPrefix, nameStr);
        } else {
            // Quantity ≥ 2 → "x%d"
            if (((static_cast<std::uint32_t>(item[0x5f]) >> 0x13) & 1u) == 0) {
                brokenPrefix = &DAT_00a1419b;
            } else {
                brokenPrefix = reinterpret_cast<std::uint8_t*>(
                    FUN_007a6de0("Broken: ", 0xFFFFFFFFu));
            }
            nameStr = reinterpret_cast<char*>(
                (**(std::uint32_t(**)(std::uint32_t, std::uint32_t))(
                    *item + 0x15c))(
                    0xFFFFFFFFu,
                    *reinterpret_cast<std::uint32_t*>(packet + 0x14)));
            nameStr = FUN_007a6de0(nameStr, 0xFFFFFFFFu);
            lootHdr = FUN_007a6de0("Received Loot", 0xFFFFFFFFu);
            std::sprintf(msgBuf, "%s: %s%s x%d", lootHdr, brokenPrefix, nameStr,
                         *reinterpret_cast<std::int32_t*>(packet + 0x14));
        }

        FUN_008f8200(chatHost, 0x17, &DAT_00a1419b, msgBuf, 0);
    }

    // Optional loot-window callback
    if (*reinterpret_cast<std::int32_t*>(client + 0xf38) != 0) {
        std::int32_t* lootUi =
            *reinterpret_cast<std::int32_t**>(client + 0xf38);
        char visible =
            (**(char(**)())(*lootUi + 0x3d8))();
        if (visible != '\0'
            && *reinterpret_cast<std::int32_t*>(
                   *reinterpret_cast<std::int32_t*>(client + 0xf38) + 0xcb8)
                   != 0) {
            std::int32_t* sub =
                *reinterpret_cast<std::int32_t**>(
                    *reinterpret_cast<std::int32_t*>(client + 0xf38) + 0xcb8);
            (**(void(**)(std::int32_t*))(*sub + 0x3ac))(item);
        }
    }

    // Place into cargo when flag@+0x12 set and item already in vehicle grid;
    // otherwise re-find / full place path.
    if (*reinterpret_cast<char*>(packet + 0x12) == '\0'
        || *reinterpret_cast<std::int32_t*>(client + 0xe98) == 0
        || *reinterpret_cast<std::int32_t*>(
               *reinterpret_cast<std::int32_t*>(client + 0xe98) + 0x250)
               == 0
        || FUN_00571010(*reinterpret_cast<std::uint32_t*>(packet + 8),
                        *reinterpret_cast<std::uint32_t*>(packet + 0xc))
               == 0) {
        FUN_00945540(client);
    } else {
        FUN_00571830(*reinterpret_cast<std::uint32_t*>(packet + 0x14),
                     *reinterpret_cast<std::uint32_t*>(packet + 8),
                     *reinterpret_cast<std::uint32_t*>(packet + 0xc));
    }

    if (DAT_00d1b894 != nullptr) {
        char vis = (**(char(**)())(*DAT_00d1b894 + 0x3d8))();
        if (vis != '\0') {
            FUN_0089c6c0(1);
        }
    }

    FUN_0092ce90();
}
