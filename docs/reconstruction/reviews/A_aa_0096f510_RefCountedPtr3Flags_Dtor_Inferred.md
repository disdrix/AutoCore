# Review A (reconstruction fidelity): `aa_0096f510` RefCountedPtr3Flags_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f510` |
| **VA** | `0x0096f510`–`0x0096f522` exclusive (**18 B** / `0x12`) |
| **Canonical name** | `RefCountedPtr3Flags_Dtor_Inferred` |
| **Ghidra name** | `FUN_0096f510` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-H) |
| **Counterpart** | `reviews/B_aa_0096f510_RefCountedPtr3Flags_Dtor_Inferred.md` |
| **System** | shared util — RefCountedPtr3Flags dtor/release |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 18 B) + callers/xrefs. **No** `disassemble_bytes`. Peer ctor sealed W35-G. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Dtor/release for the 8-byte `RefCountedPtr3Flags` handle: release the payload via refcount at +4 and tail-call/jump to vtbl[+8] when the last reference drops. Completes the pair opened by `RefCountedPtr3Flags_DefaultCtor_Inferred` (`0x0096f530`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-H append) | `docs/reconstruction/raw/aa_0096f510_FUN_0096f510.md` |
| Annotated | `docs/reconstruction/raw/aa_0096f510_FUN_0096f510.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/RefCountedPtr3Flags_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f510.cpp` |
| Function records | `functions/aa_0096f510_FUN_0096f510.md`, `…_RefCountedPtr3Flags_Dtor_Inferred.md` |
| Peer ctor | W35-G dual @ `0x0096f530` |
| Live | decompile ≡ raw CF; hex `8b0985c9740b834104ff75058b01ff6008c3` |

---

## 3. Signature (sealed)

```c
// ECX = handle*; bare RET; void
void __fastcall RefCountedPtr3Flags_Dtor_Inferred(void* handle /*ECX*/);
```

| Formal | Source | Conf |
|---|---|---|
| ECX = handle* | `mov ecx,[ecx]` | **High** |
| no stack formals | bare `C3` | **High** |
| void | no EAX success path | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
mov ecx, [ecx]          // payload = *handle
test ecx, ecx
jz ret
add dword [ecx+4], -1   // --refcount
jnz ret
mov eax, [ecx]          // vtbl
jmp [eax+8]             // tail Release (FF 60 08)
ret
```

| Stage | Match | Conf |
|---|---|---|
| Null check | **Yes** | **High** |
| Dec ref @+4 | **Yes** | **High** |
| Tail JMP vtbl[+8] | **Yes** (bytes; decomp as call) | **High** |
| No handle clear | **Yes** | **High** |
| Body 18 B | **Yes** | **High** |
| Peer ctor size-8 pair | **Yes** (vector DATA) | **High** |

---

## 5. Gaps

- Product/RTTI English of payload type.
- Whether any host requires post-dtor null store (this unit never writes `*handle`).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals 18 B body, ABI, ref@+4 / vtbl@+0 release, tail JMP, and peer-ctor pairing. Residual product English → **accept-with-gaps**.
