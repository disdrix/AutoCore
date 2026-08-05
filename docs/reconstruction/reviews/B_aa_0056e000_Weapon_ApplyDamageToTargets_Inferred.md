# Review B (skeptical / adversarial): `aa_0056e000` Weapon_ApplyDamageToTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056e000` |
| **VA** | `0x0056e000` |
| **Canonical name** | `Weapon_ApplyDamageToTargets_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056e000_Weapon_ApplyDamageToTargets_Inferred.md` |
| **System** | combat / vehicle weapon |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is the fire/resolve entry (`0056c860`) | Adjacent vtable slot; no heat gate; takes count+array | **Falsified** identity — damage loop only |
| 2 | Linear falloff `1 − dist/range` | Intercept is **1.05f**, not 1.0 | **Falsified** naive 1.0 intercept |
| 3 | Falloff always applies | Gated by `this+0xE0 != 0` and body resolve success | **Falsified always** |
| 4 | First target also falloff-scaled | `i==0` only stores anchor; scale stays 1.0 | **Falsified** first-target falloff |
| 5 | Zero damage always silent | Residual flag bytes still call `FUN_0056ff00` | **Falsified** always-silent miss |
| 6 | Crit always multiplies | Only when mult **&gt; 1.0** (`g_flOne < f`) | **Attack fails** — gated |
| 7 | Three stack arguments | Exit **`ret 8`** | **Falsified** — **two** stack formals + this |
| 8 | Direct-call leaf | DATA xrefs only (2 vtables) | **Falsified** leaf — virtual |
| 9 | Trailing multi-hit vector always used | `local_5c` never non-null in decompile | **Falsified always-used** — dead path |
| 10 | `operator_delete` does not return | Ghidra warning; free returns | **Falsified** noreturn claim |
| 11 | Product name available | No string/RTTI in this VA | **Agree leave `_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 8 / (count, targets[]) | **Confirmed** | Stack imbalance |
| Source `+0xB0` gate | **Confirmed** | Apply damage with no weapon id |
| Falloff intercept **1.05f** | **Confirmed** | Wrong splash damage curve |
| Range denom `this+0xE0` | **Confirmed** | Div0 or no falloff inverted |
| Crit gate mult &gt; 1 | **Confirmed** | Always-crit or never-crit port |
| Host required for full hit path | **Confirmed** | Offline damage without host side effects |
| Dead local_5c path | **High** | Porting phantom batch damage list |
| Damage formula inside vtbl+0x4C | **Open** | Wrong base damage numbers |
| Crit formula in 004cf080 | **Open** | Wrong crit mult distribution |
| Product class | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-07-29).
read_memory @ 0x0056e000:
  55 8B EC 83 E4 F0 6A FF 68 FC 4D 9A 00  ; SEH, and esp,-16
  ... load adj+0xB0; jz early ...
early:  32 C0 ... C2 08 00                  ; return 0, ret 8
exit:   B0 01 64 89 0D ... C2 08 00         ; return 1, ret 8
_DAT_009d3364 @ 0x009d3364: 66 66 86 3F → ~1.05f
xrefs: DATA @ 0x009d331c, 0x009ddac4
sibling: 0x0056c860 @ 0x009d3320 (same primary vtable)
callees: FUN_0056ff00×2, RandomUnitScalar, FUN_004cf080,
         FUN_0056add0×2, FUN_006335b0, CVOGHBList_Enqueue,
         CVOGHBBase_Start, FUN_004da2e0 (dead path), new/delete
```

### Falloff trap

Porting as `scale = 1.0 − dist/range` is **wrong**. Bytes force:

```
scale = 1.05f - dist / range
```

First target does **not** get falloff; it defines the origin.

### Dead-path trap

Do **not** implement a live secondary hit-vector batch through `local_5c` unless a future re-decompile shows a write. Under current live decompile it is **always null** → cleanup is dead.

### ABI trap

```
Weapon_ApplyDamageToTargets(weapon, count, targets);  // thiscall, ret 8
// NOT three stack args; NOT void-return-only
```

---

## 4. Surviving contract for AutoCore

```
Weapon_ApplyDamageToTargets(weapon, count, targets[]) -> 0|1
  // thiscall; ret 8
  // 0 if weapon adj+0xB0 source id null
  // else for each non-null target:
  //   scale = 1.0; optional falloff (1.05 - dist/range) for i>0
  //   base = target.vtbl+0x4C(...)
  //   dmg = (int)(base * scale)
  //   dmg < 1: maybe residual report
  //   else: crit scale, host-gated status/report/HB action
  // return 1

AutoCore must NOT:
  - use intercept 1.0 instead of 1.05
  - apply falloff to target[0]
  - ignore this+0xE0==0 no-falloff gate
  - always multiply crit (only mult > 1)
  - treat as fire-resolve (that is 0x0056c860)
  - rely on local_5c batch path without new evidence
  - invent product RTTI name
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Per-target damage loop | **Agree Confirmed** |
| Falloff 1.05 − dist/range; first anchors | **Agree Confirmed** |
| ret 8; count + targets[] | **Agree Confirmed** |
| Crit gated mult &gt; 1 | **Agree Confirmed** |
| Dead local_5c under current decompile | **Agree High** |
| Sibling of fire-resolve 0056c860 | **Agree Confirmed** |
| clean ≡ raw ≡ live (CF) | **Agree** |
| accept-with-gaps | **Agree** |

**Verdict:** **accept-with-gaps**
