# Review A (reconstruction fidelity): `aa_0085fd20` Client_UI_InventorySheet_RemoveByItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fd20` |
| **VA** | `0x0085fd20`–`0x0085fd33` (**0x14** bytes) |
| **Canonical name** | `Client_UI_InventorySheet_RemoveByItem` |
| **Ghidra name** | `FUN_0085fd20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0085fd20_Client_UI_InventorySheet_RemoveByItem.md` |
| **System** | `inventory-transfer` (UI sheet) |
| **Verdict** | **accept** — pure thin wrapper; COID load + tail to sealed remove |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Thin wrapper**: load instance COID pair from an **item object** and call `Client_UI_InventorySheet_RemoveByCoid` (`FUN_0085fcc0`).

```
// EAX = item*
// ESI = inventory sheet host*  (caller-owned; unchanged by this unit)
mov ecx, [eax+0x164]   ; coidHi
mov edx, [eax+0x160]   ; coidLo
push ecx
push edx
call FUN_0085fcc0      ; ret 8 stdcall; ESI = sheet
ret
```

**Does not** touch grid/cargo arrays itself — delegates entirely to `0x0085fcc0` (already dual-sealed).

---

## 2. ABI (SEALED)

| Slot | Role |
|------|------|
| **EAX** | item* with COID at `+0x160/+0x164` |
| **ESI** | inventory sheet host* (required by callee; **not set here**) |
| stack | none on entry; pushes two dwords for callee |
| return | void |

```c
// custom registers
void Client_UI_InventorySheet_RemoveByItem(void);
// EAX = item*, ESI = InventorySheetHost*
```

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live asm | full 5-instruction body |
| Live decompile | matches (loads `+0x160/+0x164`, calls `0085fcc0`) |
| Parent dual | `A_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md` §7.1 |
| Callers | `FUN_007fee30`, `FUN_00810670`, `FUN_0093d6e0`, `FUN_00944d50` (set ESI sheet, EAX item) |

---

## 4. Callers (ESI seal samples)

| Parent | Pattern |
|---|---|
| `FUN_007fee30` | `ESI = […+0x60c]` or `[…+0x580]` then `EAX=item`, call |
| `FUN_00810670` | `ESI = [host+0x5ac]`, `EAX=item` |
| `FUN_0093d6e0` | `ESI = EBX` sheet (`+0x580`/`+0x5ac` family), item path then call |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| 5-instruction wrapper only | **Confirmed** |
| COID offsets `+0x160/+0x164` | **Confirmed** |
| ESI must be pre-set sheet | **Confirmed** (callee dual + callers) |
| No extra logic | **Confirmed** |

---

## 6. Gaps

1. None material for this leaf; residual lives in `0085fcc0` (widget free ownership, vtbl `+0x3ac` name).

**Verdict:** **accept**.
