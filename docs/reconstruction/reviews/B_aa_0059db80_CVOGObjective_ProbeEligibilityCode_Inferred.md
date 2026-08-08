# Review B (skeptical / adversarial): `aa_0059db80` CVOGObjective_ProbeEligibilityCode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059db80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-091 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_0059db80_CVOGObjective_ProbeEligibilityCode_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` | Auto scaffold from parent string | **Falsified** — no VOG_DEBUG_STOP call; pure objective probe |
| 2 | Is `CVOGObjective_MatchTargetEvaluators` (`0x0059d9c0`) | Same `[+0x158,+0x15c)` walk | **Falsified** — MatchTarget uses `vtbl+0x40` boolean OR; this uses `+0x8`/`+0x58` int code |
| 3 | Is `CVOGCharacter_IsObjectiveReady` (`0x0052a020`) | Shared `+0x8` + pending hash | **Falsified** — character thiscall RET 8; AND-all bool; no `+0x58` override; different owner |
| 4 | Is parent eligibility gate `FUN_0059dc50` | Nested under MEGA-025 | **Falsified** — parent is bool gate with extra def/level checks; this returns int code |
| 5 | stdcall / no this / bare RET / void | Ghidra `undefined (void)` noise | **Falsified** — `MOV EBX,ECX`; stack char*; three `RET 4` (`c2 04 00`); EAX int |
| 6 | ECX = character | UI paths pass `DAT_00d1b6d8` | **Falsified** — ECX is objective (parent `MOV ECX,ESI` after loading objective); char is stack arg |
| 7 | Always returns `objective+0x120` only | Skim default path | **Falsified** — pending+eval path can return `vtbl+0x58` |
| 8 | `+0x8` true selects override | Sign error on ready check | **Falsified** — `TEST AL,AL` / `JNZ skip`; override only when **false** |
| 9 | Direct named callees exist | analyze leaf classification | **Falsified for named** — only indirect vcalls; classification "leaf" correct for direct |
| 10 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 11 | Product English for code is sealed | Name without `_Inferred` | **Fails (open)** — category vs zone vs state enum not product-sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 / ECX=objective | **High** | Wrong this at every call site |
| Pending hash `char+0x55c` | **High** | Probe wrong container |
| Eval false → `+0x58` override | **High** | Invert readiness semantics |
| Role under eligibility gate | **High** | Mis-port tracker filter |
| Returned code English | **Low–Med** | Doc only (`_Inferred`) |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
default = obj[+0x120]; if default==-1: default = def[+0xfc]
node = CNDHash_inline_lookup(char[+0x55c], obj[+0x10])
if !node: return default
value = node[+0x8]
for eval in [obj[+0x158], obj[+0x15c]):
  if eval.vtbl[+0x8](char, value) == false:
    code = eval.vtbl[+0x58]()
    if code != -1 and code != 0: return code
return default
```

Sibling contrast (evidence only; not OWN dual):

* `FUN_0059dc50` @ `0x0059dc50`: null-char / def flag / **`CALL 0059db80; CMP EAX,-1`** / special id band + level → bool.
* `CVOGObjective_MatchTargetEvaluators` @ `0x0059d9c0`: same evaluator vector, slot **`+0x40`**, return 0/1.
* `CVOGCharacter_IsObjectiveReady` @ `0x0052a020`: character owner, AND-all `+0x8`/`+0xc`, no category return.

Bytes seal (read_memory entry + RET):

```text
51 53 8B D9 8B 93 20 01 00 00 83 FA FF ... FF 52 08 ... FF 52 58 ... C2 04 00
PUSH ECX; PUSH EBX; MOV EBX,ECX; MOV EDX,[EBX+0x120]; CMP EDX,-1;
... CALL [EDX+8]; CALL [EDX+0x58]; RET 4; CC pad to 0059dc50
```

Xrefs (4 UNCONDITIONAL_CALL): `0059dc75`, `008a2703`, `008a3029`, `008a546d`.

---

## 4. Surviving contract for AutoCore

```
CVOGObjective_ProbeEligibilityCode_Inferred(objective, character) -> int:
  default = objective.defaultCode (+0x120)
  if default == -1: default = objective.def (+0x14c).fallbackCode (+0xfc)
  pending = lookup(character.pendingHash (+0x55c), objective.id (+0x10))
  if pending == null: return default
  for eval in objective.evaluators [+0x158, +0x15c):
    if eval.EvalProgress(+0x8)(character, pending.value) == false:
      code = eval.GetCode(+0x58)()
      if code not in {0, -1}: return code
  return default
// thiscall RET 4; never throws; no direct named callees
```

**Port tests:**

1. `+0x120 = 5`, no pending → returns 5.
2. `+0x120 = -1`, def`+0xfc = 7` → returns 7 when no override.
3. Pending present; first eval `+0x8` false and `+0x58` = 3 → returns 3.
4. All evals true (or `+0x58` trivial) → default.
5. Parent: return −1 ⇒ ineligible.
6. ABI: stack char* cleaned by callee (`RET 4`).

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on scaffold identity, MatchTarget/Ready merge, ABI noise, and ECX=character **falsified**. Remaining gaps are product English for the integer code and runtime confirmation — both explicitly open, not blocking static dual seal.
