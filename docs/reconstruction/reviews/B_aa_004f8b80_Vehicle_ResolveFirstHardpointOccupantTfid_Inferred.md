# Review B (skeptical / adversarial): `aa_004f8b80` Vehicle_ResolveFirstHardpointOccupantTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f8b80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f8b80_Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.md` |
| **Verdict** | **accept-with-gaps** |
| **Pass** | dual quality strengthen — attack table/walk residuals |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Product method name is Hardpoint Occupant | **Unproven** — no method string in body; keep `_Inferred` |
| 2 | Function finds "enemies" internally | **Partial** — enemy string is **caller** UX only (`"No enemies found."`) |
| 3 | Always vehicle this | **High** — sole caller path is player vehicle context; formal type still untyped int |
| 4 | Sentinel pointer-identical to `g_abTfidInvalid` | **False** — different DAT; content is all-ones coid pair (`read_memory`); caller uses `TFID_EqualsObjectId` |
| 5 | Table is flat `vehicle+0x260+i` | **Falsified** — asm `*( *(v+0x260) + i )` |
| 6 | `+0x260` is physics-only stabilizer array | **Falsified as exclusive identity** — equip path string **`"Tried to equip same weapon %d"`** + `Vehicle_AttachWeapon` + `Vehicle_IsAnyWeaponFiring` seal **weapon hardpoints**; airStab reuses the **same** table |
| 7 | Iterator returns object TFID at `listValue+0x160` | **Falsified** — asm takes `edi = *(listValue+4)` then `eax = edi+0x160` (one extra indirection vs some sibling list walks) |
| 8 | More than 3 hardpoint weapons in this table | **Falsified** — bound `i < 0xC` step 4; AttachWeapon slot&lt;3 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alt TFID helper for ResolveCastTarget | **Confirmed** | Miss cast path |
| 3-slot `*(v+0x260)` weapon walk | **Confirmed** | Wrong TFID source / wrong slot class |
| Occupant via `*(listValue+4)+0x160` | **Confirmed** | Off-by-indirection TFID |
| Table product word **weapon** | **Confirmed** | Cross-fn string; not body string |
| Method English HardpointOccupant | Tentative | Misleading rename if product says Station/Mount |
| `vtbl+0x40` meaning | Open | Wrong active filter |
| List element type at `+0x13c` | Open | Wrong AutoCore inventory model |

---

## 3. Surviving contract

```
// fastcall this = vehicle-like
tfid* = Vehicle_ResolveFirstHardpointOccupantTfid_Inferred(vehicle)
// Walk:
//   table = *(vehicle+0x260)           // ptr to 3 weapon* slots
//   for i in {0,4,8}:
//     slot = *(table+i)
//     if slot && slot->vtbl[0x40]() && list=slot+0x13c && list.count(+0x24)>0:
//       lock list; for each listValue:
//         obj = *(listValue+4); if obj: unlock; return &obj->tfid(+0x160)
//   return &DAT_009cd0f8   // coid lo/hi = 0xFFFFFFFF
//
// Sole consumer: ResolveCastTarget when outFlags&4 && skill+0x614&8
//   invalid TFID → client message "No enemies found."
```

Keep `_Inferred` on the **method** name until a product symbol/string names this helper. The **table** identity “weapon hardpoint array @ +0x260” is sealed without renaming this function to drop `_Inferred`.

---

## 4. Residual uncertainty

| # | Item | Blocks walk seal? | Blocks role seal? |
|---|---|---|---|
| R1 | Method product English | No | No (role OK) |
| R2 | `vtbl+0x40` product name | No | No |
| R3 | List element type (`*(value+4)` payload) | No (layout sealed) | Mild for inventory port |
| R4 | Which slot index wins when multiple occupied | No (first non-empty wins) | Mild runtime |
| R5 | DAT_009cd0f8 vs other invalid TFID templates | No | Mild |

**Prior R1 “slot table product name” reduced:** weapon identity **Confirmed** via equip string; only method-name English remains open.

---

## 5. Concrete checks performed

1. Callers = only ResolveCastTarget — **pass**.
2. Asm double-indirection vs flat offset — **pass** (falsified flat).
3. Cross-doc weapon vs stabilizer — **weapon wins**; stabilizer is alias/mislabel of same walk.
4. `read_memory` sentinel — **pass** (all-ones coid).
5. Occupant indirection `*(listValue+4)` — **pass** (adversarial catch vs naive `listValue+0x160`).
6. Equip string `FUN_004fe110` — **pass**.

---

## 6. Verdict

**accept-with-gaps** — seals the **vehicle+0x260 walk** (shape, weapon identity, first-occupant TFID path, sentinel). Leaves method product English and list-element type name open under `_Inferred`.
