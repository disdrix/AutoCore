# Review A (reconstruction fidelity): `aa_008c3120` UI_InventorySheet_AddItemSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c3120` |
| **VA** | `0x008c3120` |
| **Canonical name** | `UI_InventorySheet_AddItemSlot` |
| **Prior names** | `FUN_008c3120`, `Named_CalleeOf_Client_RecvInventoryEquip_008c3120` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_008c3120_UI_InventorySheet_AddItemSlot.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**If inventory sheet is live (`sheet+0x580 != 0`) and item non-null, create/track a UI slot for that item on the open inventory sheet.**

Body (bytes-sealed):

```
// EAX = inventory sheet / dialog
// ECX = item object*
push ebx
push edi
mov  edi, [eax+0x580]
test edi, edi
mov  ebx, ecx          // item
jz   ret
test ebx, ebx
jz   ret
call FUN_008605b0      // EDI=sheet host field, EBX=item (unaff in callee)
pop  edi
pop  ebx
ret
```

**Calling convention:** dual-register — **`EAX` = sheet**, **`ECX` = item**. Symmetric swap vs sibling `0x008c2940` (which uses ECX=sheet, EAX=item).

**Side effects:** Via `FUN_008605b0`: `operator_new(0x514)` slot widget, insert into sheet list by item COID, bind graphics, `sheet[0x140]++`. **Does not** place into world cargo grid (that is `FUN_00571620` immediately before the sole call site).

---

## 2. Inspected artifacts

| Artifact | Path / evidence |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008c3120_FUN_008c3120.md` |
| Annotated | `docs/reconstruction/raw/aa_008c3120_FUN_008c3120.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_008c3120.cpp` |
| Function record | `docs/reconstruction/functions/aa_008c3120_FUN_008c3120.md` |
| Live re-decompile | Ghidra MCP ≡ raw structure |
| Bytes | `read_memory`: `53 57 8B B8 80 05 00 00 85 FF 8B D9 74 09 85 DB 74 05 E8 … 5F 5B C3` |
| Callee | `FUN_008605b0` (allocate/bind UI slot; uses EDI sheet, EBX item) |
| Sole caller | `Client_RecvInventoryEquip` @ `0x008140c5` — after `FUN_00571620` places displaced item into cargo |

**Caller register seal:** `mov ecx, [esp+0x18]` (item); `mov eax, edi` (sheet); call.

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `*(EAX+0x580) != 0` | **Yes** |
| Gate `ECX != 0` | **Yes** (`mov ebx,ecx; test ebx`) |
| Tail to `FUN_008605b0` | **Yes** |
| No COID loads in **this** unit | **Yes** — callee uses `item[0x58]/[0x59]` (COID at object base layout) |

### 3.1 Callee role (`FUN_008605b0`) — summary

| Step | Evidence |
|---|---|
| Requires `sheet[0x15b]` and item non-null | callee prologue |
| `operator_new(0x514)` + `FUN_0085e590` ctor | callee |
| `FUN_00413920(list, coidLo, coidHi, slot, 0)` insert | callee |
| On success: sheet vfunc `+0xa8(slot)`; `sheet[0x140]++`; size/pos from item vfuncs `+0x250/+0x254` | callee |
| On fail: destroy slot `(*slot)(1)` | callee |

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| sheet `+0x580` | ptr | active gate | entry load into EDI |
| item (ECX) | ptr | object to show | `mov ebx,ecx` |
| sheet `+0x56C` (`[0x15b]`) | ptr | layout/host (callee) | `FUN_008605b0` |
| sheet `+0x570` (`[0x15c]`) | ptr | list for insert (callee) | insert helper |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Add / track UI inventory slot for item | **High** |
| Symmetric counterpart of `aa_008c2940` remove | **High** |
| Canonical name | **Probable** |
| Note ABI **swap** vs remove helper | **High / Sealed** |

---

## 6. Confidence by dimension

| Dimension | Level |
|---|---|
| ABI EAX=sheet, ECX=item | **High / Sealed** |
| Gate `+0x580` | **High** |
| Callee create/bind slot | **High** |
| Not world Place | **High** (caller already placed) |
| Product class name | **Open** |
| Runtime | **Open** |
| Overall | **accept-with-gaps** |

## 7. Gaps

- Exact dialog class / XML name
- Full slot object layout `0x514`
- Runtime visual check with open inventory during equip
