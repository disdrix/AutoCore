# Review A (reconstruction fidelity): `aa_008c2940` UI_InventorySheet_RemoveItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c2940` |
| **VA** | `0x008c2940` |
| **Canonical name** | `UI_InventorySheet_RemoveItemByCoid` |
| **Prior names** | `FUN_008c2940`, `Named_CalleeOf_Client_RecvInventoryEquip_008c2940` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_008c2940_UI_InventorySheet_RemoveItemByCoid.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**If inventory sheet is “live” (`sheet+0x580 != 0`) and item pointer non-null, remove the sheet’s tracked UI entry for that item’s COID.**

Body (bytes-sealed):

```
// ECX = inventory sheet / dialog
// EAX = item object*
push esi
mov  esi, [ecx+0x580]
test esi, esi
jz   ret
test eax, eax
jz   ret
mov  edx, [eax+0x164]   // coidHi
mov  eax, [eax+0x160]   // coidLo
push edx
push eax
call FUN_0085fcc0       // remove-by-COID on sheet (ESI implicit)
pop  esi
ret
```

**Calling convention:** dual-register — **`ECX` = sheet**, **`EAX` = item**. No stack args; `ret` (not `ret N`).

**Returns:** void.

**Side effects:** Via `FUN_0085fcc0`: lookup UI slot by COID, unbind, destroy/hide widget, decrement sheet track count (`sheet[0x140]--`). **Does not** mutate world inventory grids.

---

## 2. Inspected artifacts

| Artifact | Path / evidence |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008c2940_FUN_008c2940.md` |
| Annotated | `docs/reconstruction/raw/aa_008c2940_FUN_008c2940.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_008c2940.cpp` |
| Function record | `docs/reconstruction/functions/aa_008c2940_FUN_008c2940.md` |
| Live re-decompile | Ghidra MCP ≡ raw (ECX sheet + EAX item) |
| Bytes | `read_memory` 22 B body: `56 8B B1 80 05 00 00 … E8 … 5E C3` |
| Callee | `FUN_0085fcc0(coidLo, coidHi)` with sheet in ESI |
| Sole caller | `Client_RecvInventoryEquip` @ `0x00814078` — after cargo pull / hand resolve, before place of displaced item |

**Caller register seal (`0x00814060+`):** `mov eax, ebx` (item); `mov ecx, edi` (dialog `piVar3` from `*(client+0x1040)+0x50c`); visibility check `vtable+0x3d8` then call.

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `*(ECX+0x580) != 0` | **Yes** (bytes `cmp/test esi`) |
| Gate `EAX != 0` | **Yes** |
| Load item COID `+0x160/+0x164` | **Yes** (order: push hi then lo matches callee) |
| Call `FUN_0085fcc0` | **Yes** |
| No other branches | **Yes** |

### 3.1 Callee role (`FUN_0085fcc0`)

| Step | Evidence |
|---|---|
| Requires `sheet[0x15c]` (grid/list) non-null | callee body |
| `FUN_00413a60(coidLo, coidHi, &slot)` map lookup | callee |
| Unbind slot `vtable+0x3ac`; `FUN_007fbb70`; sheet `vtable+0xbc(slot)` | callee |
| `sheet[0x140]--` track count | callee |

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| sheet `+0x580` | ptr/flag | “sheet active / host” gate | entry load |
| item `+0x160` | i32 | COID lo | push/call |
| item `+0x164` | i32 | COID hi | push/call |
| sheet `+0x570` (`[0x15c]`) | ptr | UI inventory list (callee) | `FUN_0085fcc0` |
| sheet `+0x500` (`[0x140]`) | i32 | tracked count (callee) | decrement |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Remove inventory-sheet UI item by instance COID | **High** |
| Pair with `aa_008c3120` (add slot after place) | **High** (adjacent equip path) |
| Canonical name | **Probable** |

---

## 6. Confidence by dimension

| Dimension | Level |
|---|---|
| ABI ECX=sheet, EAX=item | **High / Sealed** (bytes + caller) |
| COID key | **High / Sealed** |
| Gate `+0x580` | **High** |
| Callee remove semantics | **High** (callee body) |
| Product dialog class | **Open** |
| Runtime | **Open** |
| Overall | **accept-with-gaps** |

## 7. Gaps

- Product name of sheet at `client+0x1040 → +0x50c`
- Whether `+0x580` is object* or non-zero flag only (used as truthy ptr in sibling add path’s sibling fields)
- Runtime after equip with open inventory UI
