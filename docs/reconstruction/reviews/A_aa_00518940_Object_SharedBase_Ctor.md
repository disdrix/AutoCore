# Review A (reconstruction fidelity): `aa_00518940` Object_SharedBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518940` |
| **VA** | `0x00518940`–`0x00518c14` (724 bytes) |
| **Canonical name** | `Object_SharedBase_Ctor` |
| **Prior scaffold** | `FUN_00518940` |
| **Review date** | `2026-07-29` (W22-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00518940_Object_SharedBase_Ctor.md` |
| **System** | object core / dual-base shared fields |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Construct / field-initialize the **shared object core** subobject used across Creature, Vehicle, Character, Item-related, and intermediate base ctors. Installs invalid TFIDs, default flag word, float 1.0, critical-section helper, and process instance counter.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00518940` |
| Bytes | `read_memory` entry / mid / epilogue — SEH, `mov esi,ecx`, float loads, `new 0x2c`, CS init, counter, `ret` |
| Bounds | `get_function_by_address` body `00518940`–`00518c14` |
| Callees | `get_function_callees` → `00512670`, `operator_new`, `InitializeCriticalSection` |
| Callers | `get_function_callers` / xrefs (30+) |
| Nested LEA samples | Creature `lea ecx,[esi+0x500]`; Vehicle `+0x670`; `005c82a0` `+0x110`; `005d4830` `+0xe0` |
| Globals | `read_memory` `g_flOne`, `g_abTfidInvalid_9CDF88`, CS vtbls |
| Dirty twin | `Object_PropagateDirtyBit0x20000` record |
| Raw / clean | `aa_00518940_*`, `Object_SharedBase_Ctor.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, full field English dictionary.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX=`this`; return `this`; no stack formals | **Confirmed** | `8b f1`; epilogue `83 c4 10 c3` |
| Invalid TFID @ +0x40 and +0x160 | **Confirmed** | loads from `009cdf88` |
| `+0xb8 = 1.0f` | **Confirmed** | `g_flOne` = `0000803f` |
| Flag `+0x17c` mask/or then dirty OR | **Confirmed** | decompile + `00512670` |
| CS helper `new(0x2c)` @ `+0xb0` | **Confirmed** | stage/final vtbls + `InitializeCriticalSection` |
| Instance counter `DAT_00b04200` | **Confirmed** | |
| Embedded at type-dependent offsets | **Confirmed** | multiple LEA samples |
| Complete-object primary vtbl written here | **Falsified residual** | outer ctors install vtbls |
| Product C++ class name | **Inferred** | role-sealed `Object_SharedBase_Ctor` |
| Clean ≡ raw CF | **Confirmed** | widths as `uint32_t`/`uint8_t` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + field defaults | Yes |
| TFID / flag / float | Yes |
| `FUN_00512670` | Yes (ECX=self) |
| CS helper alloc | Yes |
| Counter + first-instance zeros | Yes |
| Return this | Yes |

---

## 5. Gaps / open

1. Product English class name (CVOGObject vs lower mixin).
2. Full field dictionary / bit meanings inside `0x22210` (aside from later `0x20000`).
3. Runtime / bit-exact / differential.
4. Whether OOM null CS helper is tolerated by all callers.

**Verdict:** **accept**
