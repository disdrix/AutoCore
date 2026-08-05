# Review B (skeptical / adversarial): `aa_0085fcc0` Client_UI_InventorySheet_RemoveByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fcc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md` |
| **Live re-decompile** | Ghidra MCP 2026-07-29 — body matches 2026-07-23 raw CF; **entry/epilogue + caller bytes override** decompiler signature noise |
| **Verdict** | **accept-with-gaps** on ABI + sheet UI remove-by-COID; **reject** pure-thiscall / grid-remove / “ESI accidental” / “void means no stack args” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `void FUN_0085fcc0(p1,p2)` with accidental `unaff_ESI` is complete ABI | **Falsified** — callers deliberately load ESI; **`ret 0x08`** seals 2 stdcall args |
| 2 | This is `InventoryGrid_RemoveItem` / world inventory mutation | **Falsified** — no `00571b80` / cell writes; only hash UI table + sheet vtbl + count |
| 3 | `unaff_ESI[0x15c]` is a mystery index, not a byte offset | **Falsified** — bytes load **`[esi+0x570]`** (`0x15c*4`); same field add twin uses as hash host |
| 4 | Function always destroys the item object | **Not sealed** — hash hands out widget*; `+0xbc` may free, but body never calls scalar deleting dtor directly |
| 5 | `FUN_00413a60` is “find only” | **Falsified** — decompile unlinks node, pools it, decrements table count; debug string `HashError:remove` |
| 6 | Args are screen coords / cell XY | **Falsified** — all sealed callers pass **`item+0x160/+0x164`** or packet COID pair |
| 7 | `FUN_007fbb70` always clears selection | **Falsified** — gated on cookie match vs `*(selectee+0x518)` (or null cookie / no selectee) |
| 8 | ESI is always the outer dialog (`ECX` of `008c2940`) | **Falsified** — `008c2940` sets **`ESI = [ECX+0x580]`**; sell path uses **`[host+0x5ac]`** |
| 9 | Ready for bit-exact / runtime seal | **Fail** — no live sheet capture; vfunc names open |

---

## 2. Decisive sealed contract (attack cannot remove)

```text
// Caller sets ESI = InventorySheetHost*
// stdcall: push coidHi, coidLo  (right-to-left) then CALL
// ret 8

if (*(ESI + 0x570) == 0) return;          // no hash host

widget = null
FUN_00413a60(coidLo, coidHi, &widget)     // EDI = *(ESI+0x570); unlinks hash node
if (widget == 0) return

cookie = widget->vtbl[+0x3ac]()           // thiscall
FUN_007fbb70 with EAX=DAT_00d1a840, EDX=cookie   // maybe clear selection
ESI->vtbl[+0xbc](widget)                  // detach from sheet UI
*(i32*)(ESI + 0x500) -= 1
return
```

### Why “sheet UI only” survives

Add twin `0x008605b0` is the inverse on the **same** count/hash/vtable family (`+0x500`, `+0x570`, attach `+0xa8` vs detach `+0xbc`). Grid stamp APIs live under `0x0057xxxx` and are not in the call graph of this body.

### Why ESI is not “outer dialog”

Parent dual `aa_008c2940` (already sealed):

```text
ESI = [ECX + 0x580]   // then call 0085fcc0
```

Sell path:

```text
ESI = [ *(client+0x105c) + 0x5ac ]
```

Both produce the **host that owns `+0x570` hash**, not the outer packet/client object.

---

## 3. Decompiler hazards (do not promote)

| Hazard | Reality |
|--------|---------|
| `unaff_ESI` “undefined register” | Required ABI; every caller sets it |
| `unaff_ESI[0x15c]` as opaque | Byte offset **`+0x570`** |
| `FUN_007fbb70()` no args | **EAX/EDX** register ABI + imm `0x00d1a840` |
| `(**(code **)(*local_4 + 0x3ac))()` void | Return value **mov edx,eax** into selection clear |
| Signature without stdcall | Epilogue **`ret 8`** |
| Clean scaffold “Notable callees: … FUN_0085fcc0” self-call | Noise; callees are `00413a60`, `007fbb70`, two vfuncs |

Prefer **entry/epilogue bytes + three call sites** over middle-body decompiler naming.

---

## 4. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall 2 COID + ESI host | **Confirmed** | Broken ports / stack smash |
| Hash at `+0x570` | **Confirmed** | Remove wrong table |
| Count `--` at `+0x500` | **Confirmed** | Sheet UI desync |
| No C2S / no grid stamp | **Confirmed** | Wrong system ownership |
| COID key from `+0x160/+0x164` | **Confirmed** | Wrong instance removed |
| `+0x3ac` = “unbind” product name | **Probable** | Misnamed only |
| Widget lifetime after `+0xbc` | **Open** | Use-after-free in ports if assumed free |
| `DAT_00d1a840` class | **Tentative** | Wrong selection root in ports |
| Runtime golden | **Open** | UI edge cases |

---

## 5. Alternate interpretations

### Minimal reading (favored)

Inventory **sheet UI** helper: pull widget by instance COID from sheet hash, optionally clear UI selection, detach widget from sheet, decrement track count. Used after equip/sell/recv paths that already mutated logical inventory.

### Competing (weaker)

1. “Logical inventory remove by COID” — **weak**: no grid/list of world items; only UI hash + sheet vtbl.
2. “Always frees widget” — **possible via `+0xbc`**, not proven in this body.
3. “ESI is InventoryGrid” — **weak**: grid duals use different offsets (`+0x08/+0x0c/+0x28` cells); this host uses `+0x570` hash + `+0x500` count + UI vtbls.

---

## 6. Gaps remaining after dual

1. Product name / vtable class of sheet host and widget (`+0x3ac` / `+0xbc`).
2. Whether `+0xbc` deletes the widget or only unlinks from parent.
3. Full type of `DAT_00d1a840` and field `+0x309c` selectee.
4. Live capture: open inventory → equip/sell → count and hash membership.
5. Bit-exact / runtime golden.

**Verdict:** **accept-with-gaps.** Skeptical pass **cannot** remove stdcall COID ABI, ESI sheet host, hash pull at `+0x570`, detach + count--. Overclaims about grid mutation and pure-thiscall **rejected**.
