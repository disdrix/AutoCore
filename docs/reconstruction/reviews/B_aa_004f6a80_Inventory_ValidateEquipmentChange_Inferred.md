# Review B (skeptical / adversarial): `aa_004f6a80` Inventory_ValidateEquipmentChange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f6a80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_004f6a80_Inventory_ValidateEquipmentChange_Inferred.md` |
| **System** | `inventory-transfer` |
| **Work item** | MEGA-056 OWN-ONLY dual |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on CF + ABI + multi-code gate; **reject** pure-HasSpace / wrong-this / stdcall / place-item claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is only `Inventory_HasSpaceForItem` | **Falsified** — emits 0/1/2/8/0xa/0xd/0xf; space is **one** path (ret 2) |
| 2 | `this` is the item | **Falsified** — prologue `MOV EDI,ECX` then null-tests **ESI=stack item**; callers load inventory into ECX |
| 3 | `this` is the InventoryGrid | **Falsified** — grid is `*(inv+0x2b0)` loaded into ECX only for the FindFree call |
| 4 | Places / stamps footprint | **Falsified** — no PlaceItem call; FindFree outs discarded by callers |
| 5 | Bare `RET` / stdcall | **Falsified** — every epilogue is **`RET 4`** (`C2 04 00`) |
| 6 | Returns bool only | **Falsified** — distinct imm loads 1/2/8/0xa/0xd/0xf; UI switch on EDI |
| 7 | Arena check is the only early-out | **Falsified** — null→8, arena→0xf, space→2 before type dispatch |
| 8 | Type 0xc always uses `+0x264` | **Falsified** — subtype 9 vs flags 2/0x10/4 select different slots |
| 9 | Named_CalleeOf_Unequip is complete identity | **Overstated** — also Grab_Hardpoint; role is shared gate |
| 10 | Product name sealed | **Fail** — no plate; `_Inferred` required |
| 11 | Ready for bit-exact / runtime Confirmed | **Fail** — open; Terminal false |

---

## 2. Decisive dataflow — sealed contract

```
thiscall (ECX = inventory host), ret 4

if !item: return 8
if state(inv+a8) && state.f6: return 0xf
if !FindFreeForItem(inv+0x2b0, item, outs, 1, -1): return 2

switch type(item):   // *(item+0xa8)+0x38
  0xc / 0x1c / 0xa:  related via vtbl; TFID match host slot → 0
  0x10:              match +0x258; f5 → 0 else 1
  6:                 RTTI; sub 10 → +0x26c; sub 11 → +0x270 + hazard → 0|0xd
  0xe:               no state → 1; !004ce5f0 → 1; else 0xa
default: return 8
```

**Asm seals (not decompiler-only):**

- Entry: `PUSH ECX; PUSH ESI; MOV ESI,[ESP+0xC]; TEST ESI; PUSH EDI; MOV EDI,ECX`.
- Null: `MOV EAX,8; … RET 4`.
- Arena: load `[ECX_adj+0xa8]`, `CMP byte [EAX+0xf6],0`, `MOV EAX,0xF; RET 4`.
- Space: `MOV ECX,[EDI+0x2b0]; … CALL 0x005714e0; TEST AL,AL; JZ → EAX=2`.
- Default fail: `MOV EAX,8; RET 4` @ `0x004f6ec8`.
- Pad `CC` immediately after last `RET 4`.

---

## 3. Relation attack: “is this just FindFreeForItem?”

**No.** Body size **0x452**; cyclomatic **37**; type-dispatch TFID compares dominate after the single FindFree call. FindFree failure is **necessary** for ret=2 but **not sufficient** for success — type branches must still match a host container TFID (or special OK path).

Partition hint `Inventory_HasSpaceForItem` therefore **must not** be the sole product claim. Correct inferred name scopes the **whole gate**.

---

## 4. Caller attack: “Unequip-only helper?”

**No.** Two UNCONDITIONAL_CALL xrefs:

| Caller | After nonzero | After zero |
|---|---|---|
| `Client_SendInventoryUnequip` | `00931db0` + fail | free-slot re-probe + C2S `0x203E` |
| `Client_SendInventoryGrab_Hardpoint` | `00931db0` + fail | C2S `0x2034` grab |

Both pass **inventory** in ECX and **item** on stack. Shared equipment-change gate, not unequip-private.

---

## 5. UI code map attack: “messages invent codes?”

**Opposite direction sealed:** this unit **produces** EAX codes; `00931db0` **consumes** EDI. Mapping:

| EAX | String (from 00931db0) |
|---|---|
| 1 | town-only change |
| 2 | not enough space for this equipment |
| 8 | cannot be equipped |
| 0xa | must be swapped directly |
| 0xd | Hazard Mode |
| 0xf | cannot change in an arena |

Codes 3–7,9,0xc,0xe exist in the switch for **other** producers — this unit does not emit them (no overclaim).

---

## 6. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX = inventory host | **High** | Wrong owner for slots/grid |
| Stack0 = item | **High** | Null/type on wrong object |
| RET 4 | **High** | Stack corruption on port |
| Multi-code returns | **High** | Wrong UI / wrong success |
| FindFree @ +0x2b0 | **High** | Miss space gate |
| Type slot offsets | **High** CF | Wrong hardpoint family |
| Slot product English | **Low** | Naming only |
| Retail symbol | **None** | Keep `_Inferred` |
| Runtime | **None** | No Confirmed |

---

## 7. Verdict

**accept-with-gaps** — adversarial checks **fail to break** CF/ABI/status map/callers; **reject** HasSpace-only naming, item-as-this, grid-as-this, place-item, and runtime seal claims.

Gaps remain: product English, residual `004ce5f0`, runtime/diff.
