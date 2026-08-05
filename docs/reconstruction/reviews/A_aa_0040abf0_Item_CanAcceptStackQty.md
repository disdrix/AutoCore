# Review A (reconstruction fidelity): `aa_0040abf0` Item_CanAcceptStackQty

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040abf0` |
| **VA** | `0x0040abf0` |
| **Canonical name** | `Item_CanAcceptStackQty` |
| **Prior names** | `FUN_0040abf0`, `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0040abf0` |
| **Review date** | `2026-07-29` (dual A/B — seal stack capacity check) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0040abf0_Item_CanAcceptStackQty.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Predicate:** can destination item `this` absorb additional stack quantity `addQty` without exceeding max stack.

```
return (qty(this) + addQty) <= (maxStack(this) & 0xFFFF)
```

No mutation. No eligibility / Broken / CBID checks (callers gate those). Sibling **inlined** formula also appears inside `InventoryGrid_FindItemByCbid` (`aa_005710c0`); this unit is the **shared leaf** called from merge paths.

**Calling convention:** MSVC `__thiscall` — item in `ECX`; one stack arg `ushort addQty`; `ret 4`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | destination `Item*` | all 5 call sites set ECX to existing stack object |
| stack0 | `uint16_t addQty` | `movzx ecx, word [esp+8]` after `push esi` |
| AL | `bool` fits | `setle cl; mov al, cl` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040abf0_FUN_0040abf0.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_0040abf0_FUN_0040abf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_CanAcceptStackQty.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040abf0_Item_CanAcceptStackQty.md` |
| Live decompile | Ghidra `decompile_function` `0x0040abf0` (2026-07-29) ≡ raw body |
| Live bytes | `read_memory` `0x0040abf0` length 80; end `ret 4` + `int3` pad |
| Callers | `get_function_callers` + `get_function_xrefs` (4 functions / 5 sites) |
| Call-site ECX | `read_memory` at `0x004fae50`, `0x00571540`, `0x00945630`, `0x008013f0`, `0x00801580` |
| Sibling formula | dual A/B `aa_005710c0` InventoryGrid_FindItemByCbid (inlined max-stack) |
| Eligibility sibling | dual A/B `aa_00513e70` Item_IsStackEligible (**not** capacity) |

**Not performed:** `disassemble_bytes`, Launcher, live process memory, bit-exact image diff.

---

## 3. Control flow: clean ≡ raw ≡ live bytes

| Stage | Match |
|---|---|
| `clonebase = *(this+0xA8)` | **Yes** — `mov eax,[ecx+0xa8]` |
| `type = *(clonebase+0x38)` | **Yes** — `cmp dword [eax+0x38], 4` |
| type==4 → max = **999999** (`0x000F423F`) | **Yes** — `mov esi, 0x000F423F` |
| else max = `*(u16*)(*(clonebase+0x3C)+0x4BA)` | **Yes** — `mov eax,[eax+0x3c]` / `mov ax,[eax+0x4ba]` |
| max==0 → **200** | **Yes** — `test ax,ax` / `ja` / `mov esi, 0xC8` |
| `qty = vtbl[+0x25C](this)` | **Yes** — `call [edx+0x25c]` |
| `addQty = zero-extend stack ushort` | **Yes** — `movzx ecx, word [esp+8]` |
| `sum = qty + addQty` | **Yes** — `add eax, ecx` |
| effective max = **low 16 of ESI** | **Yes** — `movzx edx, si` ≡ `max & 0xFFFF` |
| return `sum <= effectiveMax` as bool AL | **Yes** — `cmp eax,edx` / `setle cl` / `mov al,cl` |
| `ret 4` | **Yes** |
| No side effects / no DAT globals | **Yes** (leaf vs caller state) |

### 3.1 Effective max width — **SEALED**

Type-4 loads **999999** then compare uses **only SI** (`movzx edx, si` → **16959 / `0x423F`**). Non-type-4 path is already a ushort; default **200** if def field is 0.

Same seal already documented for the **inlined** copy in `aa_005710c0` §3.1 — this unit is the extracted form of that predicate with `this` = destination item.

### 3.2 Decompiler noise — **SEALED as artifact**

Ghidra `CONCAT31((int3)(sum>>8), sum <= max16)` is **bool-in-AL** only. Bytes: `setle` → `mov al,cl`. Return type is **boolean**, not a packed multi-byte code.

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| item `+0xA8` | ptr | clonebase (`object[0x2a]`) | `mov eax,[ecx+0xa8]` |
| clonebase `+0x38` | i32 | type; **4** → huge-max path | `cmp [eax+0x38],4` |
| clonebase `+0x3C` | ptr | def blob | `mov eax,[eax+0x3c]` |
| def `+0x4BA` | u16 | max stack (0 → 200) | `mov ax,[eax+0x4ba]` |
| vtbl `+0x25C` | method | current quantity | `call [edx+0x25c]` |

Immediates (not DAT_*): type **4**, max **999999**, default **200**.

---

## 5. Callers (5 UNCONDITIONAL_CALL sites / 4 functions)

| Site | Function | ECX (this) | push addQty |
|------|----------|------------|-------------|
| `0x004fae64` | `Inventory_SerializeAddItemPacket` | existing stack from inventory walk | new-item `vtbl+0x25c` |
| `0x00571558` | `FUN_005714e0` (free/merge slot helper) | found item `EDI` from `FUN_005710c0` | source item qty (`ESI`) |
| `0x0094564b` | `FUN_00945540` (loot pickup merge) | existing stack `ESI` | loot item qty (`EDI`) |
| `0x00801406` | `FUN_008012f0` (equip/move UI path) | existing `EBX` | source qty (`EDI`) |
| `0x0080159c` | `FUN_008012f0` (second merge branch) | existing `EBX` | source qty (`EDI`) |

Pattern sealed: **destination stack is always `this`**; **incoming quantity is always the stack arg**. Callers perform CBID match / Broken / eligibility separately (`Item_IsStackEligible` / flags bit19).

---

## 6. Naming

| Claim | Confidence |
|---|---|
| Role = stack capacity fit predicate | **High / Sealed** |
| Canonical `Item_CanAcceptStackQty` | **Probable** (PDB unknown) |
| Distinct from `Item_IsStackEligible` (`aa_00513e70`) | **High** — eligibility has no qty math |
| Distinct from inlined gate in `InventoryGrid_FindItemByCbid` | **High** — same formula, different VA / ownership |

---

## 7. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **High** (~0x44 B to `ret 4`) |
| Signature (`__thiscall` + ushort) | **High** |
| Control flow | **High** (live ≡ raw 2026-07-29) |
| Max-stack formula + u16 mask | **High / Sealed** |
| Call-site `this` = destination | **High / Sealed** (5/5 sites) |
| Return = bool AL | **High / Sealed** |
| Product name of type class **4** | **Open** |
| Product name of def field `+0x4BA` | **Open** (role sealed as max stack) |
| Runtime / bit-exact | **Open** |
| Overall | **accept-with-gaps** |
