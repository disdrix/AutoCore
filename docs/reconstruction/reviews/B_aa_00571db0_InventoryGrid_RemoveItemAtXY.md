# Review B (skeptical / adversarial): `aa_00571db0` InventoryGrid_RemoveItemAtXY

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00571db0_InventoryGrid_RemoveItemAtXY.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** on CF/ABI/index; **reject** overclaims of known callers, full remove always, or bit-exact completeness |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is FindItemByCoid itself | **Falsified** — thin wrapper: cell→COID→Find→Remove |
| 2 | Args are row-major `(row,col)` with width as stride | **Falsified** — stride is **height** (`+0x0c`); first arg bound by **width** (`+0x08`) → `(x,y)` family matching Place/Remove |
| 3 | Always fully removes footprint | **Falsified** — calls RemoveItem with **forceFull=0** → stack peel may leave cells |
| 4 | Directly clears cells to `-1` | **Falsified** — no clear loop here; RemoveItem owns unstamp |
| 5 | `RET 0x0C` / three stack args | **Falsified** — `RET 8` / two stack bytes |
| 6 | cdecl free function | **Falsified** — `MOV ESI,ECX` thiscall |
| 7 | Well-used manager with many callers | **Fail as identity** — **0** static CALL xrefs in Ghidra |
| 8 | Scaffold clean is dual quality | **Falsified** — was auto CF only; replaced 2026-08-04 |
| 9 | Ready for bit-exact / complete | **Fail** — runtime/diff open; dead-code risk |

---

## 2. Decisive dataflow

```
grid = ECX
if x >= *(grid+0x08) or y >= *(grid+0x0c): return 0
index = *(grid+0x0c)*x + y
coid = cells[index]   // *(grid+0x28) base, 8 B
item = FindItemByCoid(grid, coid.lo, coid.hi)
return RemoveItem(grid, item, 1, /*forceFull=*/0)
```

Stack trick (not a 4-arg Find): `push 0; push 1; push hi; push lo; call Find(RET8); push item; call Remove(RET0xC)`.

---

## 3. Residual risks

1. **Unreferenced** — may be compiler leftover or data-only call; do not assume production hot path without runtime hit.
2. Empty-cell COID path not exercised here.
3. Name is **Inferred** — do not treat as PDB.

---

## 4. Verdict

**accept-with-gaps** — adversarial pass agrees with A on sealed CF/ABI/index; rejects “always full remove”, “many callers”, and completeness claims.
