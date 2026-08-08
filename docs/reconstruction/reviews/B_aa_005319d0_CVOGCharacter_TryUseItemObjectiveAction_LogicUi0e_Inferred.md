# Review B (skeptical / adversarial): `aa_005319d0` CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005319d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R10-012 OWN-ONLY) |
| **Counterpart** | `reviews/A_aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` |
| **System** | missions-progression |
| **Dual status** | **Present** (A + B modern pair) |
| **Verdict** | **accept-with-gaps** on CF + ABI + offsets + sole caller; residual on product English / stage helper / runtime |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Free function / no `this` | **Falsified** — `MOV EDI, ECX`; dual-base and `+0x548` via EDI |
| 2 | Always sends LogicUI | **Falsified** — live-gate path can return **0** before send |
| 3 | Void return | **Falsified** — `B0 01` success; fail path no set-AL-1; `RET 0x18` |
| 4 | Stack arity 4 (decompiler parent surface) | **Falsified for this body** — image **`RET 0x18`** = **6** dwords |
| 5 | `param_2` is character TFID | **Falsified** — used as `CNDHash_LookupByKey` key into **active objectives** `+0x548` |
| 6 | Type `0x0C` is Kill / generic | **Falsified** — followed by RTTI cast to **`CVOGObjectiveRequirement_UseItem`** only |
| 7 | `FUN_00522b30` stages on character | **Falsified** — first arg is **`*(UseItem+0x34)`** (target), not character |
| 8 | Parent propagates this AL | **Falsified** — `FUN_0060df70` fallthrough clears AL (`& 0xffffff00` / `XOR AL`) after call |
| 9 | Multiple code callers | **Falsified** — sole xref `0x0060e04a` |
| 10 | LogicUI type is `0x22` / pool family | **Falsified** — immediate `0x0E` at pack site |
| 11 | Name without `_Inferred` is product-true | **Withdrawn** — UI type + stage helper English open |
| 12 | `+0x7E==0` means “fail closed” | **Falsified** — clear gate **skips validation and still sends** (optimistic UI path) |

---

## 2. Decisive dataflow (raw + image)

```
this (ECX) = character
  dual = *( *( *(this+4)+4 ) + this + 0xA8 )
  dual+0x7E  live/validation gate
  this+0x548 active objective def hash
  dual+0xE8B8 LogicUI queue this at send

stack:
  +04 objectiveKey
  +08 reqIndex
  +0C..+18 COID×4 (from worldObj+0x160 at sole caller)

if dual[+0x7E] != 0:
  def = hash_lookup(+0x548, key) else return 0
  n = (def+0x15c - def+0x158) >> 2   // 0 if begin null
  if index >= n: return 0
  req = *(begin + index*4)
  if req->vtbl[+0x50]() != 0x0C: return 0
  use = dynamic_cast<UseItem>(req)
  if use[+0x34] == 0: return 0
  if !FUN_00522b30(use[+0x34], coid×4, use[+0x3c]): return 0

pack type=0x0E, key, sign(key), index
SendLogicUiPacket(dual+0xE8B8, pack)
return 1
```

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Character `this` + 6-arg `RET 0x18` | **High** | Wrong port ABI |
| Active hash `+0x548` + evaluator vec | **High** | Wrong objective binding |
| Type `0x0C` + UseItem RTTI | **High** | Wrong requirement class |
| Stage on UseItem `+0x34` via `00522b30` | **High** CF | Wrong object channel |
| LogicUI type `0x0E` + queue `+0xE8B8` | **High** | Wrong UI event |
| Gate `+0x7E` skip-validate-still-send | **High** | Wrong offline/optimistic model |
| Sole caller ObjectEventDispatch packet arm | **High** | Wrong call graph |
| `FUN_00522b30` product English | **Tentative** | Wrong AutoCore name |
| LogicUI `0x0E` product English | **Tentative** | Wrong UI feature label |
| Packet interior beyond type/key/index | **Tentative** | UI desync fields |
| Runtime / bit-exact | **Open** | — |
| Clean CF ≡ raw | **High** | — |

---

## 4. Offset attack checklist (must stay body-backed)

| Offset | Attack | Result |
|--------|--------|--------|
| `char+0x548` as hash this | Invented? | **No** — decompile load |
| def `+0x158/+0x15c` evaluators | Invented? | **No** |
| vtbl `+0x50` type `0x0C` | Invented? | **No** |
| UseItem `+0x34` / `+0x3c` | Invented? | **No** |
| dual `+0x7E` gate | Invented? | **No** |
| dual `+0xE8B8` queue | Invented? | **No** — `ADD ECX,0xE8B8` |
| LogicUI type `0x0E` | Invented? | **No** — imm store |
| `char+0x55c` pending hash | Used here? | **No** |
| Pool `+0x580` / LogicUI `0x22` | Used here? | **No** |

---

## 5. Control flow: clean ≡ raw (skeptical)

| Stage | Clean invents? | Match |
|---|---|---|
| Gate skip vs validate | No | **Yes** |
| Hash + index + type + RTTI | No | **Yes** |
| Stage helper call | No (still FUN_*) | **Yes** |
| LogicUI pack + return 1 | No | **Yes** |
| Fail return 0 | No | **Yes** |

---

## 6. Naming attack

| Proposal | Attack | Result |
|---|---|---|
| `…_LogicUi0e_Inferred` | Overclaim product UI name? | **Acceptable** — type sealed; English open via `_Inferred` |
| Drop `Try` / claim always-stage | Gate can skip stage | **Keep Try** |
| `Mission_*` instead of `CVOGCharacter_*` | `this` is character (hash `+0x548`) | **Character wins** |
| Omit UseItem | RTTI + type 0xC path | **Keep UseItem** |

---

## 7. Verdict

**accept-with-gaps** — adversarial pass does not overturn CF/ABI/offsets/caller; gaps are product English for LogicUI `0x0E` and residual `FUN_00522b30`, plus runtime.
