# Review A (reconstruction fidelity): `aa_0096f530` RefCountedPtr3Flags_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f530` |
| **VA** | `0x0096f530`–`0x0096f53f` inclusive (**16 B** / `0x10`) |
| **Canonical name** | `RefCountedPtr3Flags_DefaultCtor_Inferred` |
| **Ghidra name** | `FUN_0096f530` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-G) |
| **Counterpart** | `reviews/B_aa_0096f530_RefCountedPtr3Flags_DefaultCtor_Inferred.md` |
| **System** | shared util — refcounted handle + 3 flag bytes default ctor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Default-construct an 8-byte handle: null pointer at +0 and three flag/status bytes at +4/+5/+6. Returns `this` in EAX.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-G append) | `docs/reconstruction/raw/aa_0096f530_FUN_0096f530.md` |
| Annotated | `docs/reconstruction/raw/aa_0096f530_FUN_0096f530.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/RefCountedPtr3Flags_DefaultCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f530.cpp` |
| Function records | `functions/aa_0096f530_FUN_0096f530.md`, `…_RefCountedPtr3Flags_DefaultCtor_Inferred.md` |
| Peer dtor (context) | `decompile` + `read_memory` @ `0x0096f510` |
| Sibling | `RefCountedPtr_DefaultCtor_Inferred` @ `0x0096ef70` (W25-N) |
| Live | decompile ≡ raw CF; full 16 B hex seals stores + return-this |

---

## 3. Signature (sealed)

```c
// ECX = this; bare RET; EAX = this*
void* __fastcall RefCountedPtr3Flags_DefaultCtor_Inferred(void* self /*ECX*/);
```

| Formal | Source | Conf |
|---|---|---|
| ECX = this | `mov eax,ecx` then stores via EAX | **High** |
| return this | EAX preserved through XOR ECX path | **High** |
| no stack formals | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
mov eax, ecx
xor ecx, ecx
mov [eax], ecx          // +0 = 0
mov [eax+4], cl         // +4 = 0
mov [eax+5], cl         // +5 = 0
mov [eax+6], cl         // +6 = 0
ret                     // +7 untouched
```

| Stage | Match | Conf |
|---|---|---|
| Zero dword + 3 bytes | **Yes** | **High** |
| Body 16 B / bare `C3` | **Yes** (`read_memory`) | **High** |
| Return this (not void) | **Yes** (bytes) | **High** |
| Leaf (no callees) | **Yes** | **High** |
| Stride-8 hosts | **Yes** (vector ctor / FluidPhase) | **High** |
| Refcount role via peer | **Yes** (dtor pairing) | **High** |

---

## 5. Gaps

- Product English for payload type and three flag meanings.
- Full dual of peer dtor `0096f510`.
- Whether +7 is always padding vs latent 4th flag never zeroed.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, zero pattern, body size, return-this, and handle role vs pointer-only sibling. Residual product English → **accept-with-gaps**.
