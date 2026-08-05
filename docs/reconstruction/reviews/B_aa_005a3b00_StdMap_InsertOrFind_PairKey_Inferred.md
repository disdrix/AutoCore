# Review B (skeptical / adversarial): `aa_005a3b00` StdMap_InsertOrFind_PairKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a3b00` |
| **VA** | `0x005a3b00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005a3b00_StdMap_InsertOrFind_PairKey_Inferred.md` |
| **Evidence** | Live decompile + `read_memory` + callees `005a3310`/`004cb4f0` + sole caller `005a0b30` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is only a lower_bound (never inserts) | Body calls `FUN_005a3310` on two paths | **Falsified** |
| 2 | Single int key like `StdMap_LowerBoundByIntKey` | Compares **two** dwords hi/lo | **Falsified** |
| 3 | Nil flag at `+0x1d` / `+0x15` (other map families) | Walk uses **`+0x29`** | **Falsified other families** |
| 4 | `__cdecl` free function | ECX=this; **`ret 8`** | **Falsified** |
| 5 | Always reports inserted=1 | Equal path stores **0** at `out+4` | **Falsified** |
| 6 | Caller `005a0b30` **is** this function | Thin packer only | **Falsified conflation** |
| 7 | Product name “SpatialMap” string-sealed | No string on VA | **Not sealed** — `_Inferred` only |
| 8 | Clean diverges from live | Scaffold ≡ decompile CF | **Falsified** |
| 9 | Decompiler invents recursive self-call | Plate noise; body has no self-call | **Falsified as CF** |
| 10 | Safe to ignore `FUN_004cb4f0` | Left-path pred before equal test | **Falsified skip** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert vs find polarity | **Confirmed** | Double-insert / lost hit |
| Pair-key order (hi then lo) | **Confirmed** | Wrong tree order → ghost index corruption |
| Nil `+0x29` | **Confirmed** | Infinite walk / crash |
| Out `{node*, bool}` | **Confirmed** | Caller misread (caller currently discards) |
| Map host for GhostNet | **Low–Med** | Wrong container instance |
| Key English (TFID vs spatial) | **Medium** | Doc only |
| Runtime | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
// thiscall map; ret 8
Map_InsertOrFind_PairKey(map, out8, key):
  walk RB/header tree; compare (keyHi,keyLo) at node+0x14/+0x10
  if missing: FUN_005a3310 insert (may throw "map/set<T> too long"); out.inserted=1
  else: out.node=existing; out.inserted=0
// NOT a pure lower_bound helper; NOT single-int key map family (+0x1d/+0x15)
```

Port rule: pair-key ordering must match hi-primary then lo; do not swap with int-key map helpers used by XP/skill maps.

---

## 4. Cross-check vs insert helper

`FUN_005a3310` string-seals **map/set** family and performs RB recolor/rotate. This unit is the **public insert-or-find** front; `005a3310` is the node-link + rebalance core. Predecessor `004cb4f0` is required so equal-key detection uses the correct neighbor after a left-side landing.

---

## 5. Open questions

1. GhostNet map object identity (who owns `this` at `005a0b30`).
2. Whether any other xref appears after reanalysis (today sole caller).
3. Full node value fields beyond pair key (caller stores 5 dwords into insert payload).

**Verdict:** **accept-with-gaps** — adversarial pass keeps insert-or-find + pair-key CF; host/English residual only.
