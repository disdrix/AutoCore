# Review A (reconstruction fidelity): `aa_004fabc0` Character_TryEquipItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fabc0` |
| **VA** | `0x004fabc0` |
| **Canonical name** | `Character_TryEquipItem` (proposed; was `FUN_004fabc0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_004fabc0_Character_TryEquipItem.md` |
| **System** | inventory-transfer / equip |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** — **Broken→9**, **`\|0x10`**, type switch **sealed** |

---

## 1. Purpose

**Equip / apply attempt on a host character.** Given non-null item: OR sticky flag **`0x10`** into `item+0x17c`, dirty via `FUN_00512670`, reject if **ItemFlag_Broken** (bit 19) with status **9**, apply session byte `+0xf6` and precheck gates, then **switch on clonebase type** (`item[0x2a]+0x38`) to type-specific equip helpers.

**Calling convention (bytes):** `this` in **ECX** (host); stack **item***, optional **out***; **`ret 8`**.

| Slot | Role | Evidence |
|------|------|----------|
| ECX | host Character* | `mov edi,ecx` after item load |
| `[esp+4]` / ESI | Item* | `mov esi,[esp+8]` after push |
| `[esp+8]` / EBX | optional out* | `mov ebx,[esp+14h]`; zero `*ebx` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fabc0_FUN_004fabc0.md` |
| Annotated | `docs/reconstruction/raw/aa_004fabc0_FUN_004fabc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_TryEquipItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fabc0_FUN_004fabc0.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x004fabc0` — **≡ raw body** |
| Live bytes | `read_memory` @ entry + `0x004facc0` + tables `0x004fad58`/`0x004fad78` |
| Bounds | `get_function_by_address` → `004fabc0`–`004fad57` |
| Dirty helper | `FUN_00512670` decompile (`| 0x20000`) |
| Broken peer | `Item_SetBroken` dual / CountItemsByCbid residual (code 9 gate) |
| Callers | ConfirmEquip, inventory UI click, hardpoint drop, others |

**Not performed:** `disassemble_bytes`, Launcher, CE, full helper duals, bit-exact.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Null item → return **8**, `ret 8` | **Yes** |
| Optional out zero | **Yes** |
| `item+0x17c \|= 0x10` | **Yes** (`83 8e 7c 01 00 00 10`) |
| `FUN_00512670` always after OR | **Yes** (rel → `00512670`) |
| Broken bit19 → return **9** | **Yes** (`shr 13` / `test al,1` / `mov eax,9`) |
| Session `+0xf6` → return **0xf** | **Yes** |
| Precheck fail → return **6** | **Yes** |
| Type switch via tables | **Yes** (dwords @ `004fad58`, index @ `004fad78`) |
| Vehicle `0xe` path codes 1 / 0 / 0xe | **Yes** |

### Sealed type map (`clonebase+0x38`)

| Type | Result path |
|-----:|-------------|
| 6 | RTDynamicCast → `FUN_004f6940` |
| 8, 0x32 | **return 0xc** |
| 10 | vtbl `+0x1f4` → `FUN_004f6840` |
| 0xc | vtbl `+0x1e0` → `FUN_004f65e0` |
| 0xe | `FUN_004ce5f0` / `FUN_004f6560` → 1 / 0 / 0xe |
| 0x10 | vtbl `+0x1f0` → `FUN_004f6890` |
| 0x1c | vtbl `+0x1f8` → `FUN_004f67e0` |
| other | **return 8** |

### Status codes (this unit)

| Code | Meaning (CF) |
|-----:|--------------|
| 0 | Vehicle helper returned false |
| 1 | Vehicle `FUN_004ce5f0` failed |
| 6 | Precheck failed |
| 8 | Null item / bad type |
| **9** | **Broken** |
| 0xc | Types 8 / 0x32 |
| 0xe | Vehicle helper success |
| 0xf | Session `+0xf6` set |

---

## 4. Dirty + Broken relation

- **Always** dirties after `|0x10` when item non-null (unlike SetBroken dirty-on-change-only).
- Broken test uses **same bit 19** as `Item_SetBroken` / CountItems — sealed by peer duals + this unit’s `shr 0x13`.
- Flag **`0x10`** is **not** Broken; separate sticky bit (equip-attempt / dirty-equip — English open).

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Boundary + `ret 8` | **High / Sealed** |
| `\|0x10` + dirty | **High / Sealed** |
| Broken → **9** | **High / Sealed** |
| Type-case map | **High / Sealed** |
| Role = equip dispatcher | **High** (callers + CF) |
| Status English / flag-0x10 name | Tentative / Open |
| Helper bodies | Out of scope |
| PDB symbol | Open |

---

## 6. Verdict

**Accept-with-gaps.** Live ≡ raw; sealed gates and type switch. Residual: product names for `0x10`, codes 6/0xc/0xf, and type-helper duals.
