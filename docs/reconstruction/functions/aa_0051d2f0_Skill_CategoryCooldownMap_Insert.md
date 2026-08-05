# Function record: Skill_CategoryCooldownMap_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d2f0` |
| **Canonical name** | `Skill_CategoryCooldownMap_Insert` |
| **Address** | `0x0051d2f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual residual sealed 2026-07-29** — accept-with-gaps; ABI + node layout + insert-or-find CF High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0051d2f0_Skill_CategoryCooldownMap_Insert.md`, `reviews/B_aa_0051d2f0_Skill_CategoryCooldownMap_Insert.md` |
| **Scratch** | `reviews/a_0051d2f0.md` |

## Purpose

MSVC red-black **insert-or-find** for the category cooldown map. New keys allocate a `0x1C` node and copy `{key, startTick, durationMs}`; existing keys return the node with `inserted=0` and **do not** rewrite value fields.

## Signature (asm-sealed)

```c
struct CategoryCooldownEntry {
    int32_t  key;
    uint32_t startTick;
    int32_t  durationMs;
};

struct InsertPair {
    void*   it;        // +0  node*
    uint8_t inserted;  // +4
};

void __thiscall Skill_CategoryCooldownMap_Insert(
    void* thisMap,                 // ECX — shell size 0x0c; head@+4, size@+8
    InsertPair* pOut,              // stack0
    const CategoryCooldownEntry* pValue); // stack1
// RET 0x8  (three sites: 0x0051d35e, 0x0051d395, 0x0051d3a6)
```

### Node layout (`FUN_005ae220`, `operator_new(0x1c)`)

| Off | Field |
|----:|-------|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | key |
| +0x10 | startTick |
| +0x14 | durationMs |
| +0x18 | color |
| +0x19 | isnil |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d2f0_Skill_CategoryCooldownMap_Insert.md`
- Annotated: `docs/reconstruction/raw/aa_0051d2f0_Skill_CategoryCooldownMap_Insert.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_CategoryCooldownMap_Insert.cpp`

## Callers / callees

**Callers (xrefs 2026-07-29):**

| Caller | Site |
|--------|------|
| `Skill_InsertCategoryCooldown` | `0x00518e23` |
| `CVOGHBOKToCastAgain_ctor` | `0x0051e361` |

**Callees:**

| VA | Role |
|----|------|
| `0x0051c1c0` | Map tree insert + RB rebalance (`"map/set<T> too long"`) |
| `0x005ae050` | Tree predecessor |
| (`0x005ae220` via insert) | Node construct `0x1c` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| ABI `RET 0x8` / out-pair | **High** |
| Node field offsets | **High** |
| Equal-key no value update | **High** |
| Helper product English names | Probable / optional rename |
| Types portable C | Probable |
| Runtime / diff | Open |
