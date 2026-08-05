# Review B (skeptical / adversarial): `aa_00786470` Profiler_FindOrCreateChildZone

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786470` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00786470_Profiler_FindOrCreateChildZone.md` |
| **Verdict** | **accept-with-gaps** on CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `this` is profiler manager | Enter sets `ECX` from **slot+8 current zone** | **Falsified** |
| 2 | Always creates a new node | Hit path returns `*(it+0x28)` without `operator_new` | **Falsified** |
| 3 | Linear name list only | `FUN_00430ce0` / `FUN_004309c0` are **ordered map** walks + insert | **Falsified** as linear-only |
| 4 | Returns map iterator | Hit extracts **value at +0x28**; miss returns zone* | **Falsified** |
| 5 | Mission / string table helper | No mission callees; only string map + zone ctor | **Falsified** |
| 6 | Free function, no `this` | `__thiscall` in decompiler + `MOV ECX` at site | **Falsified** |
| 7 | Multiple independent callers | Bulk xrefs: **only** `0x00786a2c` | **Confirmed single** (attack on “shared API” overstated for this build) |
| 8 | Scaffold clean alone is port-ready without map offsets | Need `+0x1c/+0x20` and hit `+0x28` | **Overstated** if offsets ignored |
| 9 | Bit-exact STL | Static dual only | **Fail** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Parent zone thiscall + name | **High** | Map on wrong object |
| Hit vs miss CF | **High** | Duplicate zones / lost timings |
| Map end sentinel `+0x20` | **High** | Infinite create |
| Value at map node `+0x28` | **High** | Wrong pointer return |
| Alloc size 0x5C | **High** | Heap corruption if resized wrong |
| Child vector exact base | **Med** | Leak of secondary list only |
| Product type names | **Low** | Naming |

---

## 3. Cross-check vs live decompile + caller asm

| Artifact | Result |
|---|---|
| Raw ≡ live decompile | **Yes** (string map + create + insert) |
| Decompiler `param_1` as “int” | **Type weak**; role = parent zone from asm |
| `FUN_00430ce0(local_64)` with map in `in_EAX` | Register map this; parent map implied by prior ECX setup inside helper convention |
| Enter ECX overwrite | **Seals** parent ≠ profiler |

**False port from raw alone:** treating `param_1` as profiler (enter dual already documented this trap).

---

## 4. Surviving contract for AutoCore

```
// Under current zone stack top only:
zone = FindOrCreateChild(parent, name)
// same name → same child node (re-enter accumulates via timer start/leave)
```

**Falsified port mistakes:**

- Passing `g_profiler` as `this`.
- Always allocating without map lookup.
- Returning map node instead of zone at `+0x28`.

---

## 5. Open questions

1. Secondary child vector offset (`FUN_004406e0` target).
2. STL map node layout across CRT versions.
3. Nested re-enter same name: nest count vs exclusive time (timer start zeros accum).
4. Runtime capture of map growth under SearchAutoMissions.

**Verdict:** **accept-with-gaps** — hierarchical find-or-create sealed; single enter caller.
