# Review A (reconstruction fidelity): `aa_004168c0` Class_00a733ec_Factory_NullFreeCallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004168c0` |
| **VA** | `0x004168c0`–`0x0041691f` inclusive (**96 B**) |
| **Canonical name** | `Class_00a733ec_Factory_NullFreeCallback_Inferred` |
| **Ghidra name** | `FUN_004168c0` |
| **Review date** | `2026-08-05` (WQ9K-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-I) |
| **Counterpart** | `reviews/B_aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md` |
| **System** | Class_00a733ec factory (null free-callback) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (96 B) + `analyze_function_complete` + bulk xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Heap-allocate and initialize a **0x14**-byte object for vtbl family `PTR_FUN_00a733ec`, with free-callback slot **null**:

```text
obj = operator_new(0x14)
if null → return null
obj.vtbl = PTR_FUN_00a733ec
obj.context (+4) = param_1
obj.+0xc = 0; obj.+0x8 = 0; obj.+0x10 = 0
return obj
```

Twin `00416830` differs only at `+0x10` (`LAB_00573240`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004168c0_FUN_004168c0.md` (+ WQ9K-I append) |
| Annotated | `docs/reconstruction/raw/aa_004168c0_FUN_004168c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a733ec_Factory_NullFreeCallback_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004168c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004168c0_FUN_004168c0.md` |
| Named record | `docs/reconstruction/functions/aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md` |
| Live | decompile ≡ CF; full body hex; `RET 4`; vtbl write `0x00a733ec` |
| Twin / dtor context | `FUN_00416830`, `Class_00a733ec_ScalarDeletingDtor_Inferred` |

---

## 3. Signature (sealed)

```c
// 1 stack arg; RET 4; EAX = object* or null
void *Class_00a733ec_Factory_NullFreeCallback_Inferred(void *context);
```

| Slot | Source | Conf |
|---|---|---|
| context | stack formal | **High** |
| return | **EAX** object\* / null | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |
| size | imm **`0x14`** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH prolog `LAB_009ab4eb` | **Yes** | **High** |
| `operator_new(0x14)` | **Yes** | **High** |
| null → EAX=0, skip field init | **Yes** | **High** |
| vtbl `0x00a733ec` | **Yes** | **High** |
| context@+4; zeros@+8/+0xc; null@+0x10 | **Yes** | **High** |
| RET 4 | **Yes** | **High** |
| Product class English | open (vtbl stamp) | **Inferred** |

---

## 5. Gaps / open

1. Product / RTTI demangle for `PTR_FUN_00a733ec` class.
2. Static callers unrecovered (Ghidra 0 xrefs — same as twin factory).
3. Twin factory dual is WQ9K-H OWN (not this agent).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

**Decision:** promote **`Class_00a733ec_Factory_NullFreeCallback_Inferred`**. Reject freelist/CNDHash; reject thiscall; reject claiming free-callback install; reject `"UNI_BUTTONS"` as sealed class name.
