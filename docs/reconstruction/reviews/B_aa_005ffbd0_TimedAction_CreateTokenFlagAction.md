# Review B (skeptical / adversarial): `aa_005ffbd0` TimedAction_CreateTokenFlagAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffbd0` |
| **VA** | `0x005ffbd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005ffbd0_TimedAction_CreateTokenFlagAction.md` |
| **Live tools** | Ghidra `decompile_function` + `force_decompile` + `read_memory` + callers (no `disassemble_bytes`) |
| **Verdict** | **accept** (trivial CF; plate overclaims vs body; sealed High) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Body loads / hardcodes period **300000** (`DAT_00af0c6c`) | **Falsified** — no data ref; `param_3` → `+0x08`; 300000 only at `0x00af0c6c` for **caller** |
| 2 | Body sets character token/flag / mask **0x100** | **Falsified as body claim** — no mask store; plate points at **vtable** `FUN_005ffc20` (`0x005ffc20` on `PTR_FUN_009dde2c`) |
| 3 | Combat-pool style `SetPeriodAndCounter(-1000, true)` | **Falsified** — machine dual `push 1` → `(1, true)` |
| 4 | Period written only via SetPeriod helper | **Falsified as sole write** — SetPeriod seeds **`+0x0C`/`+0x10`**; real pulse is explicit **`mov [esi+8], param_3`** |
| 5 | Always attaches non-null owner | **Falsified** — `test param_2; jnz` null path Attach(0) |
| 6 | `__cdecl` / more than 2 stack args | **Falsified** — `ret 8`; ECX this |
| 7 | Multiple independent callers | **Falsified** — single UNCONDITIONAL_CALL from `Vehicle_ActivateEnterWorld` @ `0x00504093` |
| 8 | Decompiler call-site `CreateTokenFlagAction(vehicle, period)` is full signature | **Falsified as complete shape** — body is thiscall on **allocated HB**; call-site decompiler often drops placement `this` (see `operator_new(0x24)` then call) |
| 9 | Body has loops / clamps / net dirty | **Falsified** — linear ctor + branch + ret |
| 10 | Vtable write after SetPeriod is required order | **Weak claim** — machine writes vtable **between** SetPeriod pushes and call; SetPeriod does not use vtable → order non-critical |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body size 78 B / dual ret 8 | **High** | Wrong port footprint |
| `(1,true)` sentinel seed | **High** | Wrong TryFire gate (combat always-ready vs token 1 ms sentinel) |
| `+0x08` = caller period ms | **High** | Miss 300000 pulse / use wrong field |
| Null-safe Attach | **High** | Crash on null owner path |
| MI adjust formula | **High** | Wrong owner base → list attach miss |
| Product “token/flag” meaning | **Probable** | Name/plate only until fire VA sealed |
| Sole-caller period always 300000 | **High at site** / **Probable forever** | Other callers if added later |
| Runtime | **Open** | Deferred |

---

## 3. Cross-check against raw / machine

Three decompiles (`decompile_function`, `force_decompile`, `analyze_function_complete`) **identical**:

```c
CVOGHBBase_ctor(param_1);
*param_1 = &PTR_FUN_009dde2c;
CVOGHBBase_SetPeriodAndCounter(param_1, 1, true);
param_1[2] = param_3;   // +0x08
if (param_2 == 0) Attach(null); else Attach(MI_adjust(param_2));
return param_1;
```

Machine CALL targets (relative `E8` decode):

| Site | Target | Symbol |
|---|---|---|
| `005ffbd3` | `0x00508200` | `CVOGHBBase_ctor` |
| `005ffbe4` | `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |
| `005ffbfb` / `005ffc13` | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` |

`DAT_00af0c6c` bytes: `E0 93 04 00` → **300000** — **not** referenced in this body.

Sibling evidence (not re-owned):

- `CVOGHBBase_SetPeriodAndCounter` sealed: writes **`+0x0C`** always, **`+0x10`** if bool — explains why this factory still needs a separate `+0x08` store for real pulse (mirrors Regeneration pattern).
- `CVOGHBBase_AttachOwnerObject` sealed: owner at **`HB+0x18`**; list via **`owner+0xB0`**.

Clean ≡ raw ≡ decompile ≡ machine CF. No invented side effects.

---

## 4. Surviving contract for AutoCore

```
TimedAction_CreateTokenFlagAction (thiscall, ret 8):
  inputs:  ECX=HB(0x24), stack: pOwnerish, nPeriodMs
  effects: base ctor; vtable=0x009DDE2C; SetPeriod(1,true);
           this[+0x08]=nPeriodMs; Attach(null | MI(pOwnerish));
  returns: this
  does NOT: load 300000; set flag mask 0x100; fire token logic

Caller (sole): Vehicle_ActivateEnterWorld after operator_new(0x24),
               period = g_dwTokenFlagActionPeriodMs (DAT_00af0c6c=300000),
               then Enqueue + Start (caller-owned).
```

Do **not** fold fire/`FUN_005ffc20` into this unit. Do **not** treat as combat pool HB.

---

## 5. Open questions

1. Seal `FUN_005ffc20` / mask `0x100` as sibling dual A/B (product token semantics).
2. Exact static type of `pOwnerish` at enter-world call (vehicle complete object vs subobject).
3. Whether any indirect/vtable call can reach this ctor (xrefs show only one direct CALL).
4. Runtime / bit-exact still deferred.

**Verdict:** **accept** (trivial CF; plate overclaims vs body; sealed High)
