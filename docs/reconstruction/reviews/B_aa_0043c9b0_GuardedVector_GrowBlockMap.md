# Review B (skeptical / adversarial): `aa_0043c9b0` GuardedVector_GrowBlockMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c9b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-B) |
| **Counterpart** | `reviews/A_aa_0043c9b0_GuardedVector_GrowBlockMap.md` |
| **Scratch** | `tmp/a_0043c9b0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EBX** (`MOV EAX,[EBX+8]`) |
| 2 | cdecl plain RET | **Falsified** — `RET 0x4` |
| 3 | operator_delete noreturn ends function | **Falsified** — bytes commit capacity/slots after delete |
| 4 | Grows element storage directly | **Falsified** — grows **block map** (`capacity` slots of pointers); blocks still `operator_new(0x10)` in push helpers |
| 5 | Always grow by exactly `param_1` | **Falsified** — geometric `max(param, max(cap/2,8))` |
| 6 | Product name retail string | **Overstated** — inferred family; throw says `deque<T>` |
| 7 | Additional callers beyond push | **Falsified** — only `0043c830` / `0043ce10` xrefs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX + RET 0x4 | **High** | Stack/register corrupt at push sites |
| Growth formula | **High** | Wrong map size / OOM pattern |
| Post-delete commit | **High** | Leak or null map after grow |
| Rebalance arms | **High** | Ring begin/map desync |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Allocator edge cases |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  unaff_EBX container; min_grow geometric; memmove two arms; delete; (decomp incomplete)

bytes:
  8B 43 08 … C2 04 00
  after delete: 8B 4C 24 04 / 01 7B 08 / 89 4B 04
  FUN_00436860 → "deque<T> too long"
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Bytes **correct** decompiler noreturn mis-model.

---

## 4. Surviving contract for AutoCore

```
// Map grow for guarded deque-style container:
//   EBX = container (+0x04 slots, +0x08 map_cap, +0x0c begin)
//   stdcall (min_grow); RET 0x4
//   grow = max(min_grow, max(map_cap/2, 8)); overflow → length_error
//   rebalance block pointers; zero free map entries; capacity += grow
// Do not replace with vector-style single realloc of elements.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/growth/commit; product name residual only → **accept**.
