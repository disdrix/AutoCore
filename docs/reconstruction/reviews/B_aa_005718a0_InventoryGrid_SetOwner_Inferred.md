# Review B (skeptical / adversarial): `aa_005718a0` InventoryGrid_SetOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005718a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ8R-A dual) |
| **Counterpart** | `reviews/A_aa_005718a0_InventoryGrid_SetOwner_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + ABI + vtbl slot; **reject** overclaims of product English / runtime Confirmed |
| **Terminal** | **false** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function only stores `+0x24` (no side effects) | **Falsified** — also rebinds every list item via vtbl+0x158 |
| 2 | This is `SetOwnerFlag` (`+0x4`) | **Falsified** — different unit `0x00570600`; this unit never writes `+0x4` |
| 3 | Direct CALL graph callers exist | **Falsified** — Ghidra callers empty; only DATA vtable xref |
| 4 | Owner English proven from strings | **Fail** — no string refs; name remains `_Inferred` |
| 5 | Clean “separate cursor” changes behavior | **Fail as attack** — owner is stored before walk; vfunc arg reloads `+0x24`; stack reuse is artifact |
| 6 | List lock is on grid root vtbl object | **Overstated** — CS/flag offsets match **embedded list** at `+0x2c` (list+4 / list+0x28) |
| 7 | Ready for Terminal / runtime Confirmed | **Fail** — no Launcher; Terminal false |
| 8 | Wave 2026-07-23 scaffold was a dual seal | **Falsified** — scaffold only; this dual supersedes |

---

## 2. Decisive dataflow (SEALED)

```
*(grid+0x24) = owner
BeginTraversal(list = grid+0x2c)
while Next(list, &iter, &item) == 0:
  item->vtbl[0x158/4](item, *(grid+0x24))
if *(grid+0x54): *(grid+0x54)=0; LeaveCriticalSection(grid+0x30)
return  // RET 4
```

Live 2026-08-04 decompile matches 2026-07-23 raw capture. Vtable dword at `0x009d33a8` = `0x005718a0` = `PTR_FUN_009d3390 + 0x18`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store + rebind CF | **High** | Broken cargo/owner bind |
| RET 4 / thiscall | **High** | Stack imbalance |
| vtbl slot +0x18 | **High** | Wrong virtual dispatch |
| Owner type English | **Tentative** | Port naming only |
| Item +0x158 semantics | **Probable** | Wrong rebind port |
| Runtime golden | **Open** | Residual parity |

---

## 4. Surviving contract for AutoCore

```
InventoryGrid.SetOwner(owner):
  grid.OwnerObject = owner          // +0x24
  for item in grid.Items:           // locked list walk
    item.BindOwner(owner)           // vtbl+0x158
  // does NOT set OwnerFlag (+0x4) — separate API
```

Ports that only write `+0x24` without rebinding list items will diverge from client cargo create.

---

## 5. Residual gaps

- Product symbol / owner type English.
- Nested list helper duals (`004294f0`, `004022a0`) not owned here.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
