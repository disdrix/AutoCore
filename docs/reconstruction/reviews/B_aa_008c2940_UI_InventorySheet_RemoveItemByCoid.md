# Review B (skeptical / adversarial): `aa_008c2940` UI_InventorySheet_RemoveItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c2940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008c2940_UI_InventorySheet_RemoveItemByCoid.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on ABI + COID remove; **reject** world-inventory mutation |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Removes item from cargo grid (`InventoryGrid_*`) | **Falsified** — only UI sheet track list via `FUN_0085fcc0` |
| 2 | Matches by CBID | **Falsified** — loads `item+0x160/+0x164` only |
| 3 | `this` in ECX is vehicle | **Falsified** — equip caller uses inventory dialog `piVar3`; gate `+0x580` is sheet field |
| 4 | Item is stack arg | **Falsified** — bytes use EAX; caller `mov eax,ebx` |
| 5 | Same as PlaceFootprint | **Falsified** — no place/x/y |
| 6 | Always runs | **Falsified** — dual null gates + caller visibility gate |
| 7 | Bit-exact ready | **Fail** — runtime open |

---

## 2. Decisive dataflow (SEALED)

```
if sheet[+0x580] == 0: return
if item == 0: return
FUN_0085fcc0(item[+0x160], item[+0x164])  // ESI = sheet from caller of 0085fcc0
```

Bytes: `mov esi,[ecx+0x580]`; `test esi`; `test eax`; push `[eax+0x164]`, `[eax+0x160]`; `call FUN_0085fcc0`; `ret`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI-only remove | **High** | Wrong layer port (server grid delete) |
| COID key | **High** | Remove wrong stack |
| ECX/EAX ABI | **High** | Silent no-op / crash |
| Pair with 008c3120 | **High** | Equip UI desync |
| Runtime | **Open** | Residual |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x160` is CBID | Compatible? | **No** — FindItemByCoid seals COID pair; CBID is clonebase path |
| Hidden grid Place | Hidden? | **No** — single call |
| Fastcall only ECX | Compatible? | **No** — EAX required |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `Client_RecvInventoryEquip` | Sole caller — before `FUN_00571620` place of displaced item |
| `FUN_008c3120` | **Sibling add** after place |
| `FUN_0085fcc0` | Actual remove implementation |
| `InventoryGrid_FindItemByCoid` | Same COID key class; different container |

---

## 6. Verdict

**accept-with-gaps.** Tiny dual-register helper; ABI and COID remove path are **sealed**. Not a world-inventory operator.
