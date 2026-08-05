# Review A (reconstruction fidelity): `aa_0073d940` MatRegistry_FindCompatibleMaterial_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d940` |
| **VA** | `0x0073d940`–`0x0073d9ab` (**108 B**) |
| **Canonical name** | `MatRegistry_FindCompatibleMaterial_Inferred` |
| **Ghidra name** | `FUN_0073d940` |
| **Review date** | `2026-08-04` (W37-X dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-X) |
| **Counterpart** | `reviews/B_aa_0073d940_MatRegistry_FindCompatibleMaterial_Inferred.md` |
| **System** | gfx material registry |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `read_memory` (108 B) + `analyze_function_complete` + `get_assembly_context` on call sites |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory (+ analyze/callers/xrefs). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Registry **lookup**: given host table + probe material, return first **non-self compatible** material in the bucket keyed by `probe+8`, else null. Callers perform refcount swap after a non-null return.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0073d940_FUN_0073d940.md` (+ W37-X full hex) |
| Annotated | `docs/reconstruction/raw/aa_0073d940_FUN_0073d940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MatRegistry_FindCompatibleMaterial_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073d940.cpp` |
| Function records | `aa_0073d940_FUN_0073d940.md`, `…_MatRegistry_FindCompatibleMaterial_Inferred.md` |
| Live | decompile ≡ 108 B hex; `RET 4`; stride `ADD EAX,0x14`; callee `FUN_00752590` |
| Call sites | e.g. `0x0099e839` `MOV ECX,[DAT_00d1f61c]`; `PUSH` material; post-call AddRef/Release |

---

## 3. Signature (sealed)

```c
void* __thiscall MatRegistry_FindCompatibleMaterial_Inferred(void* host /*ECX*/, void* probe /*stack*/);
// RET 4
```

| Slot | Source | Conf |
|---|---|---|
| host | ECX | **High** |
| probe | stack | **High** |
| return | EAX pointer or 0 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Null probe / null key+8 → 0 | **Yes** | **High** |
| Bucket walk stride 0x14 | **Yes** (`83 C0 14`) | **High** |
| Key match `entry[0] == probe+8` | **Yes** | **High** |
| Range scan `[entry+8, entry+0xC)` | **Yes** | **High** |
| Skip self; `FUN_00752590` gate | **Yes** (EAX/EDX formals in bytes) | **High** |
| No refcount mutation in body | **Yes** | **High** |
| Product English | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB English for MatRegistry / material classes.
2. Unused bucket dwords at +4 / +0x10 of 0x14 entry.
3. Full sealed dual of `FUN_00752590` (unowned).
4. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI, stride, keying, compatibility gate, and non-mutating lookup sealed; product plate residual only.
