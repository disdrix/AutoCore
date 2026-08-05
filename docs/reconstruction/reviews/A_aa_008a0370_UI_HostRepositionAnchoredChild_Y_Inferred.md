# Review A (reconstruction fidelity): `aa_008a0370` UI_HostRepositionAnchoredChild_Y_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0370` |
| **VA** | `0x008a0370` |
| **Canonical name** | `UI_HostRepositionAnchoredChild_Y_Inferred` |
| **Ghidra** | `FUN_008a0370` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — CharSheet CreateChildWidgets residual) |
| **Counterpart** | `reviews/B_aa_008a0370_UI_HostRepositionAnchoredChild_Y_Inferred.md` |
| **System** | client UI / CharSheet host layout |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Y-reposition** of host child at `host+0x684` relative to anchor widgets, then apply via child vtbl **`+0x118`** (set position).

```text
// EAX = host / dialog*
// early out if *(host+0x684) == 0

if (*(host+0x520)==0 || *(host+0x664)==0):
  // simple path — needs +0x624
  if *(host+0x624)==0: return
  pad = (float)DAT_00d1e81c * DAT_00aaa7b8     // ~ screenH * 0.02f
  yRef = child(+0x624)->vtbl[+0x120]()        // get rect/pos
  ySelf = child(+0x684)->vtbl[+0x140]()
  newY = (yRef.y - ySelf.y) + (int)pad
else:
  // centered path using +0x664 mid widget
  pad = (float)DAT_00d1e81c * DAT_00aaa7e0     // ~ screenH * 0.0175f
  // newY = (anchorY - midH/2 - selfH) + pad   (from decompile)
apply:
  cur = child(+0x684)->vtbl[+0x120]()          // current x retained
  child(+0x684)->vtbl[+0x118]({x: cur.x, y: newY})
```

**CreateChildWidgets residual:** called from `UI_HostRefreshBoundChrome_Inferred` (`008a05a0`) and CharSheet open/refresh family (`008a04b0`, `008a16b0`, `008b*`), plus `Client_RecvCompleteDynamicObjective`.

**Not** widget construction. **Not** network.

---

## 2. Host offsets (this unit)

| Offset | Role |
|-------:|------|
| +0x520 | mode/flag byte (select layout branch) |
| +0x624 | anchor/ref widget* (required simple path) |
| +0x664 | optional mid/center widget* |
| +0x684 | target child* to move |

Vfuncs: `+0x120` get pos/rect, `+0x140` get size-ish, `+0x118` set pos.

---

## 3. Constants

| Symbol | LE float | Role |
|---|---|---|
| `DAT_00aaa7b8` | ≈ **0.02f** | simple-path Y pad × `DAT_00d1e81c` |
| `DAT_00aaa7e0` | ≈ **0.0175f** | centered-path Y pad |
| `DAT_00d1e81c` | screen metric (shared UI scale) | |

---

## 4. Confidence

| Claim | Conf |
|---|---|
| Role = Y-reposition of +0x684 child | **High** |
| Two layout branches on +0x520/+0x664 | **High** |
| EAX host ABI | **High** (`in_EAX`) |
| Exact product widget names at slots | **Open** |
| Full rect struct of vtbl+0x120 | **Probable** (uses `+4` as Y) |

**Verdict:** **accept-with-gaps**
