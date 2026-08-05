# Review A (reconstruction fidelity): `aa_007fe720` Client_UiAnnounce_TrySelectOrQueue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fe720` |
| **VA** | `0x007fe720` |
| **Canonical name** | `Client_UiAnnounce_TrySelectOrQueue_Inferred` |
| **Ghidra name** | `FUN_007fe720` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007fe720_Client_UiAnnounce_TrySelectOrQueue_Inferred.md` |
| **System** | client UI / first-time tips / announce window |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On client host (`param_1`), when the **HUD / announce host** at `+0xf38` is present and **visible** (`vtbl+0x3d8`), and its nested announce dialog at `host+0xcb4` is also visible, optionally **drain a pending ring** looking for `param_2`, then either:

- **`param_4 == 1`**: `FUN_0090b9c0` — select announce category/slot (mission/level/item/medal labels; index gated 0..4), or
- **else**: `FUN_0090bd80(param_2)` — queue/defer path that may call `0090b9c0` or push via `FUN_0040fd60`,

then invoke **`announceDlg.vtbl+0x94`** (refresh/apply).

Gates (early return):

1. `*(param_1 + 0xf38) == 0`
2. host `vtbl+0x3d8` false
3. `*(host + 0xcb4) == 0`
4. nested `vtbl+0x3d8` false

When `param_3 != 0` and nested still visible + `vtbl+0xd0` true:

- If `nested[+0x540]` (`piVar1[0x150]`) **already equals** `param_2` → return (no-op).
- Else walk ring `[0x14c..0x14f]` / index `[0x14e]`, pop entries via `FUN_0040fd60`; if any popped id matched `param_2`, return without select/queue.
- If match not found after drain, fall through to select/queue.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_007fe720_*`, `reconstructed-exact/FUN_007fe720.cpp` |
| Function record | `functions/aa_007fe720_FUN_007fe720.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x007fe720` (2026-07-29) |
| Callees | `FUN_0040fd60`, `FUN_0090b9c0`, `FUN_0090bd80` |
| Downstream | `0090b9c0` sets label dds (`i_d_announce_wnd_label_*`) + RTTI to `CDlgObjective` / `CDlgGauges` / `CDlgQuickBar` |
| Callers | `FUN_00945540`, `FUN_00946c00` (inventory-add chain residual) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Host pointer `client+0xf38` required | **Confirmed** | first gate |
| Nested announce at `host+0xcb4` | **Confirmed** | second object |
| Visibility probe `vtbl+0x3d8` | **Confirmed** | same UI family as dialogs |
| `param_4==1` → `0090b9c0` else `0090bd80` | **Confirmed** | decompile |
| Ring drain when `param_3` + `vtbl+0xd0` | **High** | body; ring math Tentative detail |
| `param_2` is announce slot / category id | **High** | matches `0090b9c0` 0..4 switch |
| Exact product English name | **Open** | inferred from labels/RTTI |
| clean ≡ raw ≡ live CF | **High** | scaffold matches |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null/visible gates on host + nested | Yes |
| Optional ring drain / early out on match | Yes |
| Branch on param_4 to 0090b9c0 / 0090bd80 | Yes |
| Final nested `vtbl+0x94` | Yes |

### Recovered CF

```c
void Client_UiAnnounce_TrySelectOrQueue(Client* c, int slotId, char doRingCheck, char forceSelect) {
  auto* host = c->ptr_f38; if (!host || !host->IsVisible()) return;
  auto* ann = host->ptr_cb4; if (!ann || !ann->IsVisible()) return;
  if (doRingCheck) {
    if (ann->IsVisible() && ann->Flag_d0()) {
      if (ann->currentSlot == slotId) return;
      // drain ring; if slotId seen, return
    }
  }
  if (forceSelect == 1) UiAnnounce_SelectCategory(ann, slotId); // 0090b9c0
  else UiAnnounce_QueueOrSelect(ann, slotId);                 // 0090bd80
  ann->vtbl[+0x94]();
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00945540`, `FUN_00946c00` | inventory / UI residual |
| Callee | `FUN_0090b9c0` | select announce category 0..4 |
| Callee | `FUN_0090bd80` | queue or select |
| Callee | `FUN_0040fd60` | pop/free ring element |
| Nested | `vtbl+0x3d8`, `+0xd0`, `+0x94` | visible / flag / refresh |

---

## 6. Gaps / open

1. Product names for host `+0xf38` and nested `+0xcb4` classes.
2. Precise ring layout (`[0x14c..0x150]`) dual.
3. Full inventory-add parent dual (callers).
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — announce select/queue CF sealed; English names Open.
