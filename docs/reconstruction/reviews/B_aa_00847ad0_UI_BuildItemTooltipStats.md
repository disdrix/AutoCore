# Review B (skeptical / adversarial): `aa_00847ad0` UI_BuildItemTooltipStats

| Field | Value |
|---|---|
| **Stable ID** | `aa_00847ad0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00847ad0_UI_BuildItemTooltipStats.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Server / packet path | No `Client_Send*`, no opcode constants, no net conn | **Falsified** — pure UI |
| 2 | Returns `int*` / pointer | Epilogue `MOV EAX,[local_9cc]`; callers `if (iVar4 != 0)`; early `return 0` / `return 1` | **Falsified pointer** — **integer line count** |
| 3 | Standard `thiscall` with `RET 0xC` | Epilogue is **`C3`** | **Falsified RET imm** — caller cleans stack args; this still in ECX |
| 4 | “Tooltip stats” invents server combat formulas | Body is `sprintf` + host vfunc append; combat math only for **display** (DPS/range formatting) | **Survives as display-only** |
| 5 | Type 10 multiplies by ⅓ in this unit | Case-10 loads `+0xB8`/`+0xBA` and sprintf; **no** multiply by `1/3` constant visible in sealed path | **Plate residual** — do **not** seal multiply inside this VA |
| 6 | `DAT_00a0f298` is “tooltip-specific half” | Same global is physics 0.5 pool | **Value sealed 0.5f**; **name not product-unique** |
| 7 | Default case “breaks” items | Only `flags \|= 0x10` + `FUN_00512670` | **Survives as flag set**, not destroy |
| 8 | `FUN_00524520` return used as bool only | Non-zero → return **1** line; function is FindActiveObjectiveId | **Truthy gate** for early tooltip line; not full objective UI |
| 9 | Body fully reconstructed line-by-line | 0x3434 bytes, 50+ callees, 70+ sprintf | **Do not claim complete English port** |
| 10 | Name wrong | Plate + call sites Inv/Drive tooltips + type switch on item | **Survives** `UI_BuildItemTooltipStats` |

---

## 2. Cross-check: live decompile ≡ raw

Live `decompile_function(0x00847ad0)` (2026-07-29):

- Entry SEH + `local_9cc = 0` + `FUN_007a69d0`
- `DAT_00d1b6d8` null → 0
- `FUN_00524520` → one line → 1
- `switch (*(item[0x2a]+0x38))` cases **4, 6, 8, 10, 0xC, 0xE, 0x10, 0x1A, 0x1C, 0x32, 0x34, default**
- Case 10 power plant field loads match plate offsets
- Tail flag `param_2[0x5f]>>0x13` / `DAT_00d1791c`
- `return local_9cc`

No material drift vs raw `aa_00847ad0_FUN_00847ad0.md`.

Entry bytes: `558bec83e4f86aff680fd29a00…81ecb80900005356578bd9…`  
Epilogue: `…8b44240c5f5e64890d000000005b8be55dc3`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Client-only tooltip builder | **High** | Wrong system ownership |
| ECX host + 3 stack args + line-count EAX | **High** | Caller ABI bugs |
| `RET` without imm (caller clean) | **High** | Stack imbalance if port assumes RET 0xC |
| Type discriminator `+0x38` via `item+0xA8` | **High** | Wrong item field |
| Power plant B0/B4/B8/BA | **High** | Wrong plant UI numbers |
| ⅓ display scale **inside** this VA | **Reject seal** | Double-scale if also applied on write |
| Full string / localization catalog | **Low** | Incomplete chrome |
| Server replication of formulas | **Reject** | Do not port to sector |

---

## 4. Surviving contract for AutoCore

```
// Client-only. No wire protocol.

// int lines = UI_BuildItemTooltipStats(hostECX, item, detailA, detailB);
// if (!g_localPlayerContext) return 0;
// if (FindActiveObjectiveIdForInteract(...)) { host.Append(...); return 1; }
// switch (item->data(+0xA8)->type(+0x38)) {
//   case PowerPlant(10): append HeatMax/PowerMax/PowerRegen/CoolRate from cast body;
//   case Weapon(0xC):    DPS/heat/range/… (detail flags);
//   case Vehicle(0xE):   chassis block;
//   case Tire(0x10):     surface coeffs;
//   case … :             as switch table;
//   default:             item.flags(+0x17C) |= 0x10; helper();
// }
// optional modular/req tail if flags bit19 or debug global;
// return linesAppended;

// Power plant offsets on cast object: +0xB0 HeatMax, +0xB4 PowerMax,
//   +0xB8 PowerRegen (short), +0xBA CoolRate (short).
// Display 1/3 scaling: plate only — verify before applying in a port.
```

---

## 5. Open questions (residual)

1. Product enum names for type ids and case-6 subtype short `+0x3f4`.
2. Full `FUN_007a6de0` key list for this function.
3. Dataflow for power-regen scale (⅓) — producer vs this consumer.
4. RTTI targets for each cast branch.
5. Whether `param_3`/`param_4` map to named UI flags in callers beyond `(1,0)`.
6. Runtime screenshot / live string verification.
7. Clean decompiler artifacts (`operator_delete` false no-return, register unaff).

---

## 6. Three-rep note

Fidelity (A) and adversarial (B) **agree** on accept-with-gaps and the same sealed ABI/switch/power-plant facts. **No third rep required** (no A/B conflict).
