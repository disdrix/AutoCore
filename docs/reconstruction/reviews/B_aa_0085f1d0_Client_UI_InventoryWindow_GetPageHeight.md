# Review B (skeptical / adversarial): `aa_0085f1d0` Client_UI_InventoryWindow_GetPageHeight

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f1d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085f1d0_Client_UI_InventoryWindow_GetPageHeight.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first modern A/B pair) |
| **Verdict** | **accept-with-gaps** on CF + offsets + Drop-Y pageH role; **reject** overclaims (grid math owner, retail name, typeHost RTTI, complete package) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is void / returns nothing | **Falsified** — EAX return; completeness tool warned on `undefined`, not void semantics |
| 2 | `this` in ECX (classic thiscall) | **Weak / fail as required** — decompiler shows **EAX**; no ECX load; treat as EAX-this leaf |
| 3 | Computes page height from W/H/pages | **Falsified** — pure load of `host+0x1c` |
| 4 | Writes layout / mutates window | **Falsified** — read-only leaf |
| 5 | `+0x1c` is total cells / width / type | **Falsified for consumers** — Allocate writes page height formula there; Find/Can/Drop use as pageH |
| 6 | Null host returns garbage | **Falsified** — explicit `xor eax,eax` path |
| 7 | Only used for Drop packet | **Overstated** — also 4× in `FUN_0085f220` hit-test/CanPlace path |
| 8 | typeHost **is** sealed InventoryGrid* | **Overstated** — offset family matches; English/RTTI **Probable**, not PDB |
| 9 | Name is retail | **Fail** — inferred only |
| 10 | Ready for bit-exact / complete | **Fail** — runtime/diff open |
| 11 | Page height always 13 | **Fail for unit** — cargo algebra is 13; getter returns whatever host stores |
| 12 | Signed vs unsigned return matters for wireY | **Mild residual** — Drop packs with `i8` imul/add; body returns full dword |

---

## 2. Decisive dataflow (raw + live 2026-07-29)

```
EAX = this (UI window)
EAX = *(i32*)(EAX + 0x56c)     // typeHost
if EAX == 0: return 0
return *(i32*)(EAX + 0x1c)     // pageH
```

Live decompile ≡ 2026-07-23 raw. Bytes:

```
8B806C050000 85C0 7404 8B401C C3 33C0 C3
```

No alternate paths, no stack args, no DAT_* globals.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / null gate / +0x56c / +0x1c | **High** | Wrong Drop Y / page clamp |
| Leaf no side effects | **High** | False mutation assumptions |
| Drop wireY uses this return as pageH | **High** (parent asm residual) | Multi-page Y off-by-page |
| `FUN_0085f220` uses return as page dim | **High** CF (4 calls + CanPlace product) | Hit-test Y wrong |
| typeHost == InventoryGrid | **Probable** | Wrong port type, correct offset still works |
| EAX-this ABI everywhere | **High** for observed callers | Wrong recompile ABI |
| Retail name | **Open** | Cosmetic |
| Runtime multi-page golden | **Open** | Residual parity |
| Signed pageH edge (negative host field) | **Open / mild** | Corrupt host → bad i8 wireY |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x56c` invented? | Random offset | **No** — body + Drop pack prelude `mov edx,[esi+0x56c]` + Grab type-from |
| `+0x1c` is width? | Confuse with sibling | **No** — sibling `FUN_0085f1f0` loads **`+0x18`**; Allocate writes pageH to **`+0x1c`** |
| Getter recomputes `(n/pages)/w`? | Over-attribute algebra | **No** — load only; algebra is Allocate’s job |
| Return 0 means pageH=0 safe? | Division / imul by 0 | **Callers** must tolerate 0; Drop then wireY=cellY only; hit-test may collapse bands — **not** this unit’s problem beyond returning 0 |
| Package “complete” via parent residual? | Parent sealed Y formula | **No** — parent sealed **use**; this dual seals **helper body**; runtime still open |

### Sibling contrast (must not merge)

| VA | Load | Consumer role |
|----|------|---------------|
| `0x0085f1d0` (this) | `host+0x1c` | **pageH** (Y / page bands) |
| `0x0085f1f0` | `host+0x18` | width-family (X scale in `FUN_0085f220`) |

---

## 5. Surviving contract for AutoCore

```
// Inventory UI window host
pageH = (typeHost = window.typeHost@+0x56c) != null
      ? typeHost.pageHeight@+0x1c
      : 0;

// Drop grid packet (client → sector 0x2036), not implemented here:
wireY = (int8)(pageH * pageIndex@window+0x564 + cellY);
```

Server ports that accept absolute cell Y do not need this getter, but **must** accept Y that already includes `pageH * pageIdx` when the client multi-page UI is used.

Do **not**:

- Re-derive page height inside the getter.
- Treat return as width.
- Assume type host non-null without the gate.
- Mark complete without multi-page runtime.

---

## 6. Caller evidence (adversarial sample)

| Caller | Path shape | Attack notes |
|--------|------------|--------------|
| `Client_UI_InventoryDropToGrid` | After hit-test success; grid path only | Store path (`0x2027`) does **not** need this for Y pack |
| `FUN_0085f220` | After X-side scale; multiple pageH reloads | Decompiler float mess around hit-test does **not** pollute this leaf’s CF |
| CanPlace `FUN_00570840` | Uses pageH from **grid layout**, not this getter directly | Product with pageIdx still same semantic family |

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Runtime pageIdx≠0 wireY capture | **Yes** for complete / bit-exact |
| R2 | typeHost RTTI / English class name | Mild (offsets sealed) |
| R3 | Retail symbol | Mild |
| R4 | Negative or huge `+0x1c` i8 pack behavior | Mild (corrupt/host edge) |
| R5 | Full `FUN_0085f220` float hit-test fidelity | **Out of scope** (own only this VA) |

---

## 8. Concrete checks performed

1. Live Ghidra decompile `0x0085f1d0` — match raw 2026-07-23.
2. `read_memory` full body bytes — match table in A.
3. `get_function_callers` / xrefs — 5 sites, 2 functions; leaf callees empty.
4. Cross-check sibling `0x0085f1f0` decompile — `+0x18` only.
5. Cross-check parent Drop residual Y formula (asm pack site uses this return).
6. Cross-check Allocate `+0x1c` page-height write algebra.

**Not done:** runtime, Launcher, `disassemble_bytes`, full `FUN_0085f220` dual (owned elsewhere).

---

## 9. Verdict

| Side | Result |
|------|--------|
| Mechanical CF / offsets | **Accept** (High) |
| Drop-Y pageH helper role | **Accept** (High via consumers) |
| typeHost class English / retail name / complete | **Gaps** |
| **Combined** | **accept-with-gaps** — dual quality sealed; package not complete |
