# Review A (reconstruction fidelity): `aa_00416830` Class_00a733ec_Factory_WithFreeCallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416830` |
| **VA** | `0x00416830`–`0x00416892` inclusive (**99 B** / `0x63`) |
| **Canonical name** | `Class_00a733ec_Factory_WithFreeCallback_Inferred` |
| **Ghidra name** | `FUN_00416830` |
| **Review date** | `2026-08-05` (WQ9K-H dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-H) |
| **Counterpart** | `reviews/B_aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md` |
| **System** | Class_00a733ec heap factory |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body + vtbl + free cb) + bulk xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Heap factory for objects whose primary vtbl is `PTR_FUN_00a733ec`. Allocates **0x14** bytes, installs vtbl + context + zero pair + free-callback `LAB_00573240`. Twin `FUN_004168c0` sets free-callback null.

```text
p = operator_new(0x14)
if !p: return null
p->vtbl = PTR_FUN_00a733ec
p->context = arg
p->+8 = p->+0xc = 0
p->free_cb = LAB_00573240
return p
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9K-H append) | `docs/reconstruction/raw/aa_00416830_FUN_00416830.md` |
| Annotated | `docs/reconstruction/raw/aa_00416830_FUN_00416830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a733ec_Factory_WithFreeCallback_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00416830.cpp` |
| Function record | `docs/reconstruction/functions/aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md` |
| Dualed dtor | `aa_00416f00` WQ9J-E |
| Live | body hex; vtbl dword `0x00416f00` @ `0x00a733ec`; free-cb bytes @ `0x00573240` |

---

## 3. Signature (sealed)

```c
// stack context; RET 4; returns object* or null
void *Class_00a733ec_Factory_WithFreeCallback_Inferred(void *context);
```

| Slot | Source | Conf |
|---|---|---|
| context | stack (`MOV EDX,[ESP+0x14]` after SEH) | **High** |
| return | **EAX** = p or 0 | **High** |
| cleanup | **`RET 4`** | **High** |
| thiscall | **No** (no ECX this) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH frame | **Yes** | **High** |
| `operator_new(0x14)` | **Yes** (`6A 14`) | **High** |
| null → EAX=0 | **Yes** | **High** |
| vtbl write `0x00a733ec` | **Yes** | **High** |
| +4 context / +8+0xc zero / +0x10=0x00573240 | **Yes** | **High** |
| free cb scalar-delete context | **Yes** (bytes) | **High** |
| vtbl[0] = dualed dtor `0x00416f00` | **Yes** | **High** |
| Product English | open | **Inferred** |

---

## 5. Gaps / open

1. Product / RTTI demangle.  
2. Zero CALL xrefs — reachability unknown.  
3. Twin factory dual is WQ9K-I (not OWN).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
