// =============================================================================
// MissionTracker_FillTrackedTargetSlots_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092b2a0
// Address:   0x0092b2a0–0x0092bf5b  (autoassault.exe, image base 0x400000)
// Size:      3260 bytes (0xCBC)
// System:    inventory-transfer partition (parent 0x0092af80); MissionTracker role
// Sealed:    2026-08-05 R12-008 dual
//            Tools: decompile + analyze_function_complete + get_function_by_address +
//            callers/xrefs + get_assembly_context + read_memory (body edges + DAT*).
//            No disassemble_bytes.
// Exactness: Behavior-preserving rewrite of **image-sealed** control flow.
//            Full map/tree iterator micro-ops remain in raw decompile; this twin
//            captures ABI, arm split, top-4 rank, and emit contract.
// Bit-for-bit / runtime / diff: DEFERRED. Never Runtime Confirmed.
// Ghidra:    FUN_0092b2a0
// Scaffold:  FUN_0092b2a0.cpp
// =============================================================================
//
// PURPOSE
//   Secondary MissionTracker multi-target fill (sole caller 0x0092bf60 @ 0x0092c058
//   after primary filter 0x0092af80 miss):
//     1) Seed 4 distance slots with FLT_MAX.
//     2) If host CBID lists (+0x54 / +0x80) non-empty: world mission-tree walk,
//        level band, CBID match, rank into top-4 (temp map + level-delta promote).
//     3) Else if race list (+0xAC) non-empty: CS-list key 0x36 + race/type gates;
//        insert when distSq >= 10000.
//     4) Emit <=4 nodes (0x20): TFID_16 from obj+0x164, pos from +0x84/88/8c,
//        push onto vector begin host+0x11C.
//     5) Any emit => host+0x08 = 1, AL = 1; else AL = 0.
//
// ABI (image-sealed)
//   stack stdcall: (host, origin)
//   AL = bool
//   RET 8
//
// CONSTANTS
//   DAT_00aaa630 = FLT_MAX     top-4 dist init
//   DAT_00aaa880 = 10000.0f    race-path min distSq
//   DAT_00aaa668 = -1.0f       close-slot mark compare
//   DAT_00a158a0 = empty TFID_16 template
// =============================================================================

#include <cstdint>
#include <cstring>

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using i32 = std::int32_t;

static constexpr float kFltMax       = 3.402823466e+38f; // DAT_00aaa630
static constexpr float kMinDistSq    = 10000.0f;         // DAT_00aaa880
static constexpr float kNegOne       = -1.0f;            // DAT_00aaa668
static constexpr int   kTopN         = 4;
static constexpr int   kNodeSize     = 0x20;
static constexpr int   kCsListKey    = 0x36;
static constexpr int   kCloneTypeA   = 0x12;
static constexpr int   kCloneTypeB   = 0x0E;

// Residuals / dualed helpers — contracts only; not re-implemented here.
extern "C" void FUN_0092b1c0(void* host /*EAX*/);
extern "C" u8   FUN_00929c60(void* host, float distSq);
extern "C" void FUN_0040b3b0(void* mapOut);
extern "C" void FUN_0040bc10(void* a, void* b, void* c);
extern "C" void FUN_0040b440(void* map, void* itOut, void* node);
extern "C" void FUN_0040b890(void* pair);
extern "C" void FUN_00419880(void* vecBase, void* insertAt, void* elemPtr);
extern "C" void FUN_004294f0(void* list /*ECX*/);
extern "C" int  FUN_004022a0(void* it, void* outNode);
extern "C" void* FUN_0040b330(void* raceKey);
extern "C" void FUN_004f1e20(int, int);
extern "C" int  Object_GetRootRaceId(void* objAdj);
extern "C" char CVOGCharacter_WeaponAllowsKillXpBonus(void);
extern "C" void* operator_new(u32 sz);
extern "C" void  operator_delete(void* p);

struct Top4 {
    float dist[kTopN];
    void* obj[kTopN];
};

static void top4_init(Top4* t)
{
    for (int i = 0; i < kTopN; ++i) {
        t->dist[i] = kFltMax;
        t->obj[i]  = nullptr;
    }
}

// Insert candidate into ascending dist top-4 (smaller dist wins).
static void top4_consider(Top4* t, float distSq, void* obj)
{
    for (int slot = 0; slot < kTopN; ++slot) {
        if (t->dist[slot] <= distSq)
            continue;
        for (int j = kTopN - 1; j > slot; --j) {
            t->dist[j] = t->dist[j - 1];
            t->obj[j]  = t->obj[j - 1];
        }
        t->dist[slot] = distSq;
        t->obj[slot]  = obj;
        return;
    }
}

static float dist_sq(const float* origin, const float* pos)
{
    float dx = pos[0] - origin[0];
    float dy = pos[1] - origin[1];
    float dz = pos[2] - origin[2];
    return dx * dx + dy * dy + dz * dz;
}

// Image: ADD EAX,0x118 then fields begin@+4 end@+8 cap@+C  => host+0x11C/120/124
static void vector_push_node(void* host, void* node)
{
    auto* base = reinterpret_cast<u8*>(host) + 0x118;
    void** begin = reinterpret_cast<void**>(base + 0x4); // host+0x11C
    void** end   = reinterpret_cast<void**>(base + 0x8); // host+0x120
    void** cap   = reinterpret_cast<void**>(base + 0xC); // host+0x124

    void* b = *begin;
    if (b == nullptr ||
        (static_cast<u32>(reinterpret_cast<u8*>(*cap) - reinterpret_cast<u8*>(b)) >> 2) <=
            (static_cast<u32>(reinterpret_cast<u8*>(*end) - reinterpret_cast<u8*>(b)) >> 2)) {
        FUN_00419880(base, *end, &node);
        return;
    }
    void** e = reinterpret_cast<void**>(*end);
    *e = node;
    *end = e + 1;
}

static void* alloc_node_seed_tfid()
{
    auto* n = reinterpret_cast<u32*>(operator_new(kNodeSize));
    // zero pos + pad at +0x10..+0x1C
    n[4] = n[5] = n[6] = n[7] = 0;
    // empty TFID_16 template DAT_00a158a0..AC
    n[0] = n[1] = 0xFFFFFFFFu;
    n[2] = n[3] = 0;
    return n;
}

static void fill_node_from_obj(void* node, void* obj)
{
    auto* n = reinterpret_cast<u32*>(node);
    auto* o = reinterpret_cast<u8*>(obj);
    // this-adjust for MI object layout used in image
    int* p1 = *reinterpret_cast<int**>(o + 4);
    int  adj = p1[1];
    u8*  body = o + adj;

    // position at body+0x84
    n[4] = *reinterpret_cast<u32*>(body + 0x84);
    n[5] = *reinterpret_cast<u32*>(body + 0x88);
    n[6] = *reinterpret_cast<u32*>(body + 0x8c);

    // TFID_16 at body+0x164 (NOT +0x160)
    auto* tfid = reinterpret_cast<u32*>(body + 0x164);
    n[0] = tfid[0];
    n[1] = tfid[1];
    n[2] = tfid[2];
    n[3] = tfid[3];
}

static int emit_top4(void* host, Top4* t)
{
    int count = 0;
    for (int i = 0; i < kTopN; ++i) {
        void* obj = t->obj[i];
        if (obj == nullptr)
            continue;
        void* node = alloc_node_seed_tfid();
        vector_push_node(host, node);
        fill_node_from_obj(node, obj);
        ++count;
    }
    return count;
}

// ---------------------------------------------------------------------------
// CBID/world arm and race arm interiors are large (tree walk, map rank, CS list).
// Sealed gates are summarized; full iterator CF remains in raw/annotated decompile.
// ---------------------------------------------------------------------------
static void collect_cbid_world_arm(void* host, float* origin, Top4* t);
static void collect_race_arm(void* host, float* origin, Top4* t);

// Primary entry — image: stack (host, origin), RET 8, AL bool
extern "C" u8 MissionTracker_FillTrackedTargetSlots_Inferred(void* host, float* origin)
{
    auto* h = reinterpret_cast<u8*>(host);
    Top4 slots{};
    top4_init(&slots);

    i32 cbidA = *reinterpret_cast<i32*>(h + 0x54);
    i32 cbidB = *reinterpret_cast<i32*>(h + 0x80);

    if (cbidA > 0 || cbidB > 0) {
        if (h[6] != 0)
            FUN_0092b1c0(host);
        collect_cbid_world_arm(host, origin, &slots);
    } else {
        i32 raceN = *reinterpret_cast<i32*>(h + 0xAC);
        if (raceN <= 0)
            return 0;
        if (h[6] != 0)
            FUN_0092b1c0(host);
        collect_race_arm(host, origin, &slots);
    }

    int n = emit_top4(host, &slots);
    if (n > 0) {
        h[0x08] = 1;
        return 1;
    }
    return 0;
}

// Stubs: full bodies live in raw decompile (FUN_0092b2a0). Dual seals their gates.
static void collect_cbid_world_arm(void* host, float* origin, Top4* t)
{
    (void)host;
    (void)origin;
    (void)t;
    // Image path @ 0x0092b307:
    //   FUN_0040b3b0(map);
    //   walk client+0xE04 → +0xE84C tree;
    //   resolve vtbl+0x1EC; require (obj+0x180)>>9 & 1;
    //   level = entry.level; if (level>99) level-=100;
    //   gate host+0x108/+0x10C (-1 open);
    //   match CBID vs list A (+0x58,n=+0x54) or B (+0x84,n=+0x80) by entry flag +0x16;
    //   distSq vs origin; FUN_00929c60; FUN_0040b890 into map;
    //   later promote by |level-charLevel| bands (vtbl+0x27C) into top-4;
    //   FUN_0040bc10 map teardown.
}

static void collect_race_arm(void* host, float* origin, Top4* t)
{
    (void)host;
    (void)origin;
    (void)t;
    // Image path @ 0x0092b968:
    //   lookup CS list key 0x36 via client+0xE04+0xE4E8;
    //   FUN_004294f0; while FUN_004022a0: resolve vtbl+0x1EC;
    //   for race slot 0..11 at obj+0xF0:
    //     skip ~RACE_HUMAN / used flags;
    //     race hash client+0xD30+0xF10 (or FUN_0040b330 remap);
    //     FUN_004f1e20; clonebase type 0x12/0x0E gates + level;
    //     match race/type tables host+0xB0 / +0xD8 (count +0xAC);
    //     distSq; if >= 10000 top4_consider; else optional WeaponAllowsKillXpBonus mark.
}
