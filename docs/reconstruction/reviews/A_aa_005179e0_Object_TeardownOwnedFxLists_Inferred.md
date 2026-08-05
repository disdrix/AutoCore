# Review A (reconstruction fidelity): `aa_005179e0` Object_TeardownOwnedFxLists_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005179e0` |
| **VA** | `0x005179e0`–`0x00517a6a` (**139 B / `0x8B`**) |
| **Canonical name** | `Object_TeardownOwnedFxLists_Inferred` |
| **Ghidra name** | `FUN_005179e0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W28-H) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_005179e0_Object_TeardownOwnedFxLists_Inferred.md` |
| **System** | client-fx / object-owned NDSpecialFX ptr-vector teardown |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Object-level teardown of owned SpecialFX pointer containers:

1. Nested secondary list `FUN_00516930(this, 0)` (`+0x138` family; callee **`ret 4`**).
2. If sticky `+0x130` non-null → `FUN_00517250(this, sticky)` single-remove.
3. Clear `+0x130`.
4. Walk primary vector `+0x124..+0x128` (stride 4): free when `fx+9==0` **and** sealed `NDSpecialFX_StopFinalize_Inferred` returns non-zero → `NDSpecialFX_TeardownCore_Inferred` + `operator_delete`.
5. Free vector buffer if begin non-null; **always** zero `+0x124/+0x128/+0x12c`.

Closes residual from W26-K ApplySingleFxSlot (tail-jmp here) and W27-D StopFinalize manager-caller dual.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005179e0_FUN_005179e0.md` (+ W28-H append) |
| Annotated | `docs/reconstruction/raw/aa_005179e0_FUN_005179e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005179e0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Object_TeardownOwnedFxLists_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_005179e0_*` |
| Live | decompile ≡ raw outer CF; `read_memory` full body + epilogue; bounds `005179e0`–`00517a6a` |
| Nested seals | W27-D `004ba0a0` StopFinalize; W26-K tail chain; peek `004b99c0` TeardownCore |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, dual of `00516930`/`00517250`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 139 B | **Confirmed** | `get_function_by_address` + pad `CC` |
| thiscall `mov esi,ecx` | **Confirmed** | entry bytes |
| Plain `RET` (`C3`) | **Confirmed** | epilogue |
| `FUN_00516930(this,0)` + callee `ret 4` | **Confirmed** | push 0; callee end `C2 04 00` |
| Sticky `+0x130` remove then clear | **Confirmed** | decomp ≡ bytes |
| Free gate `+9==0` && StopFinalize | **Confirmed** | `cmp [ebp+9],bl`; `test al,al` |
| TeardownCore ECX = fx | **Confirmed** | `mov ecx,ebp` (decomp drop) |
| Always zero triad after free | **Confirmed** | bytes after delete; decomp gap |
| Virtual DATA installs | **Confirmed** | 4 DATA xrefs |
| Product English | **Inferred** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Secondary list teardown | **Yes** |
| Sticky single-remove | **Yes** |
| Primary walk free gate | **Yes** |
| Buffer free | **Yes** |
| Always zero `+0x124/128/12c` | **Yes** (bytes; decomp incomplete) |

### 4.1 Sealed contract

```
// thiscall; no cleaned stack formals; plain ret
void Object_TeardownOwnedFxLists_Inferred(void *self);

// FUN_00516930(self, 0)
// if sticky=+0x130: FUN_00517250(self, sticky); sticky=0
// for fx in [+0x124, +0x128):
//   if fx+9==0 && StopFinalize(fx): TeardownCore(fx); delete fx
// if begin: delete begin
// begin=end=cap=0
```

---

## 5. Callers / callees (live)

**CODE callers:** `FUN_00518ec0` (call), `FUN_00584330` (tail jmp).  
**DATA:** four vtable slots.  
**Callees:** `FUN_00516930`, `FUN_00517250`, `FUN_004ba0a0`, `FUN_004b99c0`, `operator_delete`.

---

## 6. Gaps

1. Product C++ class / member names.  
2. Nested dual of `FUN_00516930` / `FUN_00517250` (not OWN).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — CF, ABI, free gate, always-zero triad, and caller chain sealed; product name inferred only.
