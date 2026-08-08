// =============================================================================
// UI_ItemTooltip_AppendTypeMetaLines_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00847240
// Address:   0x00847240  (autoassault.exe, image base 0x400000)
// Body:      0x00847240–0x008479f0 (1968 bytes / 0x7B0)
// System:    inventory-transfer / client item tooltip UI
// Seal:      R11-029 2026-08-05 — decompile_function + analyze + read_memory
//            + callers/xrefs. No disassemble_bytes.
// Exactness: Stage-faithful reconstruction of CF. Large vfunc / weapon branch
//            kept as offsets. Not modernization. Not bit-exact claim.
// Scaffold:  docs/reconstruction/reconstructed-exact/FUN_00847240.cpp
// Retired:   Mission_Mission_Object_00847240 (string-weak mis-name)
// =============================================================================
//
// ABI: cdecl — stack (Item* item, char showMeta); caller ADD ESP,8.
//      EDI  = UiTextHost* (caller-live register; vfuncs +0x250 / +0x224 / +0x22c).
//      RET  = int line-count contribution for panel layout.
//
// Callers:
//   FUN_00843a60 @ 0x00843dc1           (equipped compare; push 1, item)
//   UI_ItemDetailPanel_Refresh_Inferred @ 0x0084be00  (push 1, bound object)
//
// Key callees (dualed / residual):
//   Item_RequiresBindOrTradeLock              0x00513fc0  (customize line)
//   Item_PatenteeMatchesCharacterOrEmpty_*    0x00522950  (RE gate)
//   EnsureLootRarityTableLoaded_Inferred      0x005129b0
//   FUN_005140d0 rarity color; FUN_007a6de0 locale; FUN_007a69d0 time
//   FUN_0040da70 weapon resolve; FUN_00844fa0 slot name; FUN_00599dd0 craft count
//
// Strings (sealed): type labels, weapon prefixes, Customizes On Equip,
//   Customized For, Not Tradable, charges, Patented By:, Cannot be Reverse
//   Engineered, Cannot be Memorized.
// DAT: 00a32888="Item"; 00a34230=", "; 00d1b6d8 session; 00b04214 rarity table.
// =============================================================================

#include <cstdint>
#include <cstdio>

struct Item;
struct UiTextHost;

// Session / player host (product type open).
extern int *DAT_00d1b6d8;
// Rarity table base pointer (entries stride 0x48; name at +2).
extern char *DAT_00b04214;
// Localized "Item" key.
extern char DAT_00a32888[];
// Literal ", ".
extern char DAT_00a34230[];

extern void FUN_007a69d0();
extern const char *FUN_007a6de0(const char *key, int colorHint /* -1 */);
extern void FUN_005129b0(); // EnsureLootRarityTableLoaded_Inferred
extern int *FUN_005140d0(void *scratch, int rarityPacked);
extern char FUN_00513fc0(int coid_lo, int coid_hi); // Item_RequiresBindOrTradeLock (thiscall ECX=item omitted in decomp of callee)
extern char FUN_00522950(Item *item);               // Item_PatenteeMatchesCharacterOrEmpty_Inferred
extern int FUN_0040da70();
extern int FUN_00599dd0();
extern const char *FUN_00844fa0(int mode, int color = -1);

// EDI text host — modeled as explicit arg for readability of the port surface.
// Retail keeps EDI live from caller; clean twin FUN_00847240.cpp mirrors decomp.

static void Text_Append(UiTextHost *host, const char *s)
{
    // host->vtbl[+0x250](s)
    (void)host;
    (void)s;
}

static void Text_AppendColor(UiTextHost *host, const char *s, std::uint32_t color)
{
    // host->vtbl[+0x224](s, color)
    (void)host;
    (void)s;
    (void)color;
}

static void Text_AppendColor2(UiTextHost *host, const char *s, std::uint32_t color)
{
    // host->vtbl[+0x22c](s, color)
    (void)host;
    (void)s;
    (void)color;
}

// -----------------------------------------------------------------------------
// Type-class labels (holder+0x38) — sealed string table from decompile.
// -----------------------------------------------------------------------------
static const char *TypeClassLabel(int typeClass, int *holder, int *session,
                                  char *buf, UiTextHost *host)
{
    int *blob = reinterpret_cast<int *>(holder[0xf]); // holder+0x3c → index 0xf of int*
    // Note: holder is int*; +0x3c bytes = holder[0xf]. +0x38 = holder[0xe].
    (void)blob;
    switch (typeClass) {
    case 4:  return "Mission Object";
    case 6: {
        // subtype short at *(holder+0x3c)+0x3f4
        short sub = *reinterpret_cast<short *>(
            *reinterpret_cast<int *>(reinterpret_cast<char *>(holder) + 0x3c) + 0x3f4);
        switch (sub) {
        case 0:  return "Junk";
        case 7:  return "Repair Kit";
        case 8:  return "Paint Can";
        case 10: return "Ornament";
        case 11: return "Hazard Kit";
        case 16: return "Trick Material";
        case 20: return "Useable Item";
        default:
            if (session && *reinterpret_cast<int *>(reinterpret_cast<char *>(session) + 0x6b4) > 0) {
                auto u8 = FUN_007a6de0("Subtype", -1);
                auto u11 = FUN_007a6de0(&DAT_00a32888[0], -1);
                std::sprintf(buf, "%s - %s %i", u11, u8, static_cast<int>(sub));
                Text_Append(host, buf);
                return nullptr; // already emitted
            }
            return "Item";
        }
    }
    case 8:  return "Gadget";
    case 10: return "Power Plant";
    case 12: return nullptr; // weapon detail path (separate)
    case 14: return "Vehicle Chassis";
    case 16: return "Wheel Set";
    case 26: {
        int *h = holder;
        if (h == nullptr || *reinterpret_cast<int *>(reinterpret_cast<char *>(h) + 0x3c) == 0 ||
            FUN_00599dd0() < 1)
            return "Crafting Commodity";
        return "Crafting Component";
    }
    case 28: return "Armor";
    case 50: return "Tinkering Kit";
    case 52: return "Accessory";
    default: return "UNKNOWN ITEM TYPE";
    }
}

// Weapon case 0xc — flag bits at template+0x536 (sealed by decompile).
// bit0 spray, bit1 front, bit2 rear, bit4 turret, bit5 ballistic, bit6 explosion.
static void AppendWeaponDetail(Item *item, int *session, UiTextHost *host, char *buf)
{
    // Guards: session, session+0x250 chain → non-null cloneblob; then item vtbl+0x1e0;
    // FUN_0040da70 → weapon template; compare player vehicle class @ +0x714.
    // Emits Front/Turret/Rear/Melee prefixes and (Single Target)/(Ballistic)/
    // Explosion/Target Spray suffixes. Color 0xffff2020 on mount mismatch.
    (void)item;
    (void)session;
    (void)host;
    (void)buf;
    // Full branch retained in raw decompile / FUN_00847240.cpp scaffold.
}

// =============================================================================
// Entry
// =============================================================================
int UI_ItemTooltip_AppendTypeMetaLines_Inferred(Item *item, char showMeta,
                                                UiTextHost *textHost /*EDI*/)
{
    char buf128[128];
    char bufRarity[132];
    char bufMeta[124];

    FUN_007a69d0();
    int *session = DAT_00d1b6d8;
    int *holder = *reinterpret_cast<int **>(reinterpret_cast<char *>(item) + 0xA8); // [0x2a]*4
    int typeClass = *reinterpret_cast<int *>(reinterpret_cast<char *>(holder) + 0x38);
    int *blob = *reinterpret_cast<int **>(reinterpret_cast<char *>(holder) + 0x3c);

    // ---- S2/S3 type line ----
    if (typeClass == 12 /*0xc*/) {
        AppendWeaponDetail(item, session, textHost, buf128);
    } else {
        const char *label = TypeClassLabel(typeClass, holder, session, buf128, textHost);
        if (label != nullptr) {
            Text_Append(textHost, FUN_007a6de0(label, -1));
        }
    }

    // ---- S4 rarity (skip mission object type 4) ----
    if (typeClass != 4) {
        Text_Append(textHost, &DAT_00a34230[0]); // ", "
        if (DAT_00b04214 == nullptr)
            FUN_005129b0();
        short rarity = *reinterpret_cast<short *>(reinterpret_cast<char *>(blob) + 0x4b8);
        const char *rname = FUN_007a6de0(DAT_00b04214 + 2 + rarity * 0x48, -1);
        std::sprintf(bufRarity, "%s", rname);
        int *colorWord = FUN_005140d0(nullptr, rarity);
        Text_AppendColor2(textHost, bufRarity, colorWord ? *colorWord : 0xffffffffu);
    }

    // ---- S5 meta flags ----
    if (showMeta && typeClass != 4) {
        // COID at item+0x160 / +0x164 → item[0x58], item[0x59]
        int coid_lo = *reinterpret_cast<int *>(reinterpret_cast<char *>(item) + 0x160);
        int coid_hi = *reinterpret_cast<int *>(reinterpret_cast<char *>(item) + 0x164);
        if (FUN_00513fc0(coid_lo, coid_hi)) {
            std::uint32_t flags = *reinterpret_cast<std::uint32_t *>(
                reinterpret_cast<char *>(item) + 0x17c); // item[0x5f]
            if (((flags >> 20) & 1) == 0) {
                Text_AppendColor(textHost,
                                 FUN_007a6de0("\nCustomizes On Equip", -1),
                                 0xffffffffu);
            } else {
                // Owner name via item+0xac (item[0x2b]) chain or "Owner"
                const char *owner = FUN_007a6de0("Owner", -1);
                // product chain: item[0x2b]->vtbl+0x210(0) … vtbl+0x160() when bound
                const char *tag = FUN_007a6de0("Customized For", -1);
                std::sprintf(bufMeta, "\n<%s %s>", tag, owner);
                Text_AppendColor(textHost, bufMeta, 0xffffffffu);
            }
        }
        if (*reinterpret_cast<char *>(reinterpret_cast<char *>(blob) + 0x4be) != 0) {
            auto s = FUN_007a6de0("Not Tradable", -1);
            std::sprintf(bufMeta, "\n<%s>", s);
            Text_AppendColor(textHost, bufMeta, 0xffffffffu);
        }
        std::uint16_t charges = *reinterpret_cast<std::uint16_t *>(
            reinterpret_cast<char *>(item) + 0x180);
        if (charges != 0) {
            if (*reinterpret_cast<short *>(reinterpret_cast<char *>(blob) + 0x4bc) == -1) {
                auto s = FUN_007a6de0("unlimited charges", -1);
                std::sprintf(bufMeta, "\n<%s>", s);
            } else {
                auto s = FUN_007a6de0("charges", -1);
                std::sprintf(bufMeta, "\n<%d %s>", static_cast<unsigned>(charges), s);
            }
            Text_AppendColor(textHost, bufMeta, 0xffffffffu);
        }
    }

    // ---- S6 patented by (item+0x101 C-string) ----
    const char *patentee = reinterpret_cast<const char *>(item) + 0x101;
    int patented = (patentee[0] != '\0') ? 1 : 0;
    if (patented) {
        auto prefix = FUN_007a6de0("Patented By: ", -1);
        std::sprintf(buf128, "\n%s %s", prefix, patentee);
        Text_AppendColor(textHost, buf128, 0xffaedeffu);
    }

    // ---- S7 RE / memorize ----
    if (session == nullptr)
        return patented + 1;

    if (FUN_00522950(item) == 0) {
        auto s = FUN_007a6de0("Cannot be Reverse Engineered", -1);
        std::sprintf(buf128, "\n%s", s);
        Text_AppendColor(textHost, buf128, 0xffff2020u);
        return patented + 2; // asm ADD EAX,2 path
    }
    // item+0x100 flag (decomp param_1[0x40] as char)
    if (*reinterpret_cast<char *>(reinterpret_cast<char *>(item) + 0x100) == 0)
        return patented + 1;

    {
        auto s = FUN_007a6de0("Cannot be Memorized", -1);
        std::sprintf(buf128, "\n%s", s);
        Text_AppendColor(textHost, buf128, 0xffff2020u);
        return patented + 2;
    }
}

// End UI_ItemTooltip_AppendTypeMetaLines_Inferred
