# Review A (reconstruction fidelity): `aa_0040d890` Class_009c7948_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d890` |
| **VA** | `0x0040d890`–`0x0040d8ca` (**59 B**) |
| **Canonical name** | `Class_009c7948_CompleteDtor` |
| **Ghidra name** | `FUN_0040d890` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-C) |
| **Counterpart** | `reviews/B_aa_0040d890_Class_009c7948_CompleteDtor.md` |
| **System** | MSVC derived complete dtor — `PTR_FUN_009c7948` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (body + vtbl) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Derived complete destructor for host vtbl `PTR_FUN_009c7948`: install derived vtbl, then chain base `StdTreeHost_PtrVal_CompleteDtor` (`0x0040d820`). Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-C append) | `docs/reconstruction/raw/aa_0040d890_FUN_0040d890.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d890_FUN_0040d890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7948_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0040d890.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d890_Class_009c7948_CompleteDtor.md` |
| Base complete | `aa_0040d820` StdTreeHost_PtrVal_CompleteDtor (W31-A) |
| Scalar caller | `FUN_0040d870` (vtbl[0] of `009c7948`) |
| Live | decompile ≡ scaffold; body hex 59 B; vtbl slot0=`0040d870` |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor
void __fastcall Class_009c7948_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`89 0C 24` store / thiscall) | **High** |
| epilogue | `83 C4 10; C3` | **High** |
| free this? | no | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prologue (LAB_009be2d8)
*this = PTR_FUN_009c7948          // C7 01 48 79 9C 00
EH = -1
FUN_0040d820(this)                // base complete
SEH epilogue; ADD ESP,0x10; RET
```

Base complete stages (W31-A): install `009c7938` → clear → `FUN_0040d7c0(this+4)`.

| Stage | Match | Conf |
|---|---|---|
| Derived vtbl install | Yes | **High** |
| Chain base complete only | Yes | **High** |
| Complete (no delete this) | Yes | **High** |
| SEH / ADD ESP,0x10 | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper (thin complete over base) |
| Callers | `FUN_0040d870` scalar-deleting |
| Callees | `FUN_0040d820` |

Vtbl `0x009c7948`: [0]=`0x0040d870`, [1]=`0x0074d470`, [2]=`0x0074d440`.

---

## 6. Gaps

1. Product/MSVC demangle for derived class.  
2. Vtbl slots [1]/[2] English.  
3. Derived fields beyond base (body has none).  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI/SEH, derived vtbl install, base-complete chain, and complete-vs-scalar sealed. Residual product + extra vtbl slots → **accept-with-gaps**.
