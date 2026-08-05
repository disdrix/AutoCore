# Review A (reconstruction fidelity): `aa_00578830` CVOGHBSkillBase_DefaultCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578830` |
| **VA** | `0x00578830` |
| **Body** | `0x00578830`–`0x005788c8` (152 bytes) |
| **Canonical name** | `CVOGHBSkillBase_DefaultCtor` |
| **Prior scaffold** | `FUN_00578830` |
| **Review date** | `2026-07-29` (W23-S dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00578830_CVOGHBSkillBase_DefaultCtor.md` |
| **System** | `skills-abilities` / heartbeat |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Empty/default `CVOGHBSkillBase` shell for skill-element factories:

1. `CVOGHBBase_ctor`
2. Vtbl `PTR_FUN_009d3fdc` (RTTI **CVOGHBSkillBase**)
3. `FUN_0054f3c0` with ECX=`this+0x24` (skill-runtime partial)
4. Zero tails; `AttachOwner(null)`; invalid TFID sentinel at `+0x678`

Not the full cast ctor (`0x005788d0`): no blob copy, no ValidateTarget, no period, no type tag `+0x1c=1`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00578830` |
| Bytes | `read_memory` 160 B — body hex through `c3` |
| Bounds | `get_function_by_address` body `00578830`–`005788c8` |
| Callees | `CVOGHBBase_ctor`, `FUN_0054f3c0`, `CVOGHBBase_AttachOwnerObject` |
| Callers | 30+ factory / intermediate sites |
| RTTI | COL `0x00aaede0` → `.?AVCVOGHBSkillBase@@` (re-read; matches full ctor dual) |
| Sibling full ctor | `A_aa_005788d0_CVOGHBSkillBase_ctor` |
| Raw / clean | `aa_00578830_*`, `CVOGHBSkillBase_DefaultCtor.cpp` |

**Not performed:** Launcher, runtime construct, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF: base → vtbl → partial → zeros → Attach null → TFID | **Confirmed** | raw ≡ live ≡ bytes |
| Vtbl / class = `CVOGHBSkillBase` | **Confirmed** | RTTI string |
| `FUN_0054f3c0` this = `this+0x24` | **Confirmed** | `lea ecx,[esi+0x24]` in body bytes |
| AttachOwner always null | **Confirmed** | push 0 path only |
| TFID sentinel `{FFFFFFFF,FFFFFFFF,0,0}` | **Confirmed** | `DAT_009d3f88` memory |
| Body **152 bytes** / returns this | **Confirmed** | bounds + `mov eax,esi; ret` |
| Role = factory empty shell | **High** | callers overwrite vtbl after |
| Product English method name | **Open** | class Confirmed; method role High |
| Tail field product names | Tentative | offsets sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
CVOGHBBase_ctor(this);
*this = &PTR_FUN_009d3fdc;
FUN_0054f3c0(); // ECX = this+0x24
zero five dwords;
AttachOwner(this, null);
copy DAT_009d3f88..94 → this+0x678;
return this;
```

| Stage | Match |
|---|---|
| SEH + base ctor | Yes |
| Vtbl install | Yes |
| Partial skill runtime | Yes |
| Null attach + sentinel TFID | Yes |
| No ValidateTarget / SetPeriod | Yes |

---

## 5. Gaps / open

1. Product/PDB symbol string for this specific ctor overload.
2. Full semantics of zeroed tails (shared residual with `005788d0`).
3. Optional dual residual of each factory after-vtbl overwrite (out of OWN).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
