# Review A (reconstruction fidelity): `aa_005b3210` CVOGHBRespawnCharacter_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3210` |
| **VA** | `0x005b3210` |
| **Body** | `0x005b3210`–`0x005b325d` (77 bytes) |
| **Canonical name** | `CVOGHBRespawnCharacter_ctor` |
| **Prior scaffold** | `FUN_005b3210` |
| **Review date** | `2026-07-29` (W23-S dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b3210_CVOGHBRespawnCharacter_ctor.md` |
| **System** | `heartbeat` / client death-respawn |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Construct thin **`CVOGHBRespawnCharacter`** HB:

1. `CVOGHBBase_ctor`
2. Vtbl `PTR_FUN_009d957c` (RTTI **CVOGHBRespawnCharacter**)
3. `SetPeriodAndCounter(1, true)` then **`this+0x08 = periodMs`**
4. AttachOwner null or MI this-adjusted object

Death UI sole caller: `new(0x24)`, ctor(`client+0xe98`, **300000**), Enqueue + Start.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005b3210` |
| Bytes | `read_memory` 128 B — body through dual `ret 8` |
| Bounds | `get_function_by_address` body `005b3210`–`005b325d` |
| Callees | `CVOGHBBase_ctor`, `SetPeriodAndCounter`, `AttachOwnerObject` |
| Callers | sole `0x00802170` LocalDeathUiSequence |
| RTTI | COL `0x00aaffac` → type_info `0x00af3e88` → `.?AVCVOGHBRespawnCharacter@@` |
| Period helper dual | `A_aa_005081a0_CVOGHBBase_SetPeriodAndCounter` |
| Attach dual | `A_aa_005083b0_CVOGHBBase_AttachOwnerObject` |
| Raw / clean | `aa_005b3210_*`, `CVOGHBRespawnCharacter_ctor.cpp` |

**Not performed:** Launcher, runtime fire of OnHeartBeat, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF base → vtbl → SetPeriod(1,true) → +0x08=period → Attach | **Confirmed** | raw ≡ live ≡ bytes |
| Class = `CVOGHBRespawnCharacter` | **Confirmed** | RTTI string |
| ABI thiscall + 2 stack args + `ret 8` | **Confirmed** | body ends |
| Dual period: `+0x0C/10`=1, pulse `+0x08` | **Confirmed** | SetPeriod dual + `mov [esi+8]` |
| Null vs adjust Attach branches | **Confirmed** | two `ret 8` arms |
| Sole caller death path period 300000 | **High** | live decompile `00802170` |
| Alloc size 0x24 | **High** | same caller |
| OnHeartBeat product behavior | **Open** | vfunc residual |
| Exact owner type after this-adjust | Tentative | expression sealed; type open |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
CVOGHBBase_ctor(this);
*this = &PTR_FUN_009d957c;
SetPeriodAndCounter(this, 1, true);
this[2] = periodMs; // +0x08
if (!pObject) AttachOwner(this, null);
else AttachOwner(this, pObject + 4 + *(*(pObject+4)+4));
return this;
```

| Stage | Match |
|---|---|
| Vtbl / RTTI | Yes |
| SetPeriod then pulse store | Yes |
| Dual Attach arms | Yes |
| ret 8 | Yes |

---

## 5. Gaps / open

1. OnHeartBeat / vtbl fire path product semantics.
2. Product type of `client+0xe98` beyond character-like object with MI layout.
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
