# Review B (skeptical / adversarial): `aa_004fabc0` Character_TryEquipItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fabc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fabc0_Character_TryEquipItem.md` |
| **System** | inventory-transfer / equip |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on equip gates + type switch; **reject** “Broken-only” / “no mutation” / wrong ABI claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is read-only / no flag writes | **Falsified** — `or [esi+0x17c], 0x10` + dirty OR `0x20000` |
| 2 | Dirty only when Broken changes | **Falsified** — dirty **always** after `|0x10` (item non-null) |
| 3 | Reject code for Broken is not 9 | **Falsified** — `mov eax,9` after bit19 test |
| 4 | Broken test is mask `0x08` @ `+0x184` | **Falsified** — uses `+0x17c` / `shr 0x13` (bit 19) |
| 5 | `__cdecl` / single stack arg | **Falsified** — `ret 8` = two dwords; ECX = host |
| 6 | Type 0xe returns only helper code | **Nuance** — can return **1** / **0** / **0xe** via vehicle path |
| 7 | Types 8 and 0x32 fall through to default 8 | **Falsified** — both map index **1** → **return 0xc** |
| 8 | Only ConfirmEquip calls this | **Overstated** — inventory UI, hardpoint drop, other equip UI |
| 9 | Flag `0x10` is Broken | **Falsified** — Broken is bit19; `0x10` is bit4 |
| 10 | Ready for bit-exact / runtime seal | **Fail** — open |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = host
// [esp+4] = item*, [esp+8] = out* (optional)
// ret 8

if (item == 0) return 8
if (out) *out = 0
*(u32*)(item+0x17c) |= 0x10
FUN_00512670(item)                    // | 0x20000 chain
if ( (*(u32*)(item+0x17c) >> 19) & 1 ) return 9
if (sessionish && *(sessionish+0xf6)) return 0xf
if (!FUN_00514390(host_vtbl+0x210(0,1), 0)) return 6
switch (*(clonebase+0x38)):
  ... type helpers / fixed codes ...
```

### Byte anchors

| Addr | Bytes | Meaning |
|------|-------|---------|
| `004fabc0` | `56 8b 74 24 08` | load item from stack |
| null path | `b8 08 00 00 00 … c2 08 00` | return 8 / ret 8 |
| `004fabd6` area | `83 8e 7c 01 00 00 10` | `or [esi+0x17c],10` |
| `004FABEE` | `e8 7d 7a 01 00` | → `00512670` |
| Broken | `c1 e8 13` `a8 01` | bit 19 |
| return 9 | `b8 09 00 00 00` | equip reject |
| tables | `004fad58` / `004fad78` | jump + index |

Relative: `next(004FABF3)+0x00017a7d = 00512670` ✓

---

## 3. Relation attack: flags

| Bit / mask | Offset | This unit |
|------------|--------|-----------|
| **`0x10` bit4** | `+0x17c` | **writes** (OR) always on entry |
| **`0x80000` bit19 Broken** | `+0x17c` | **reads** → code 9 |
| **`0x20000` dirty** | `+0x17c` | via callee only |

Do not merge these three.

---

## 4. Type-table attack

Index table after `type - 6`; value **7** = default → return **8**.

Sealed non-default: 6→0, 8→1, 10→2, 0xc→3, 0xe→4, 0x10→5, 0x1c→6, 0x32→1.

Types **not** in {6,8,10,0xc,0xe,0x10,0x1c,0x32} cannot equip through this switch (code **8**), even if precheck passed.

---

## 5. Confidence table (adversarial)

| Claim | Level |
|-------|-------|
| ABI / gates / type map | **High / Sealed** |
| Broken code 9 | **High / Sealed** (this + peer Broken duals) |
| Equip-dispatcher role | **High** (callers) |
| Flag `0x10` English | **Open** |
| Code 6 / 0xc / 0xf English | **Open** |
| Helper correctness | **Out of scope** |
| Runtime / bit-exact | **Open** |

---

## 6. Verdict

**Accept-with-gaps.** Machine contract for sticky `0x10`, dirty, Broken→9, and type dispatch is sealed. Reject pure-reader or Broken-only characterizations. Residual: product strings for secondary codes and flag `0x10`.
