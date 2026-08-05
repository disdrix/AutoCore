# Review A (reconstruction fidelity): `aa_007647c0` Host_RegisterObjectAndAccumulateBounds

| Field | Value |
|---|---|
| **Stable ID** | `aa_007647c0` |
| **VA** | `0x007647c0`–`0x0076482d` exclusive (**109 B**) |
| **Canonical name** | `Host_RegisterObjectAndAccumulateBounds` |
| **Ghidra name** | `FUN_007647c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-L) |
| **Counterpart** | `reviews/B_aa_007647c0_Host_RegisterObjectAndAccumulateBounds.md` |
| **System** | host registration + graphics bounds |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 109 B) + callee decompile of `FUN_004406e0` / `FUN_0074c9c0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Register `object*` onto `host` (ptr-vector @ host+0xbc), run object virtual prep, resolve xform via host virt+0x0c, accumulate object local bounds (obj+0x28) into host+4 via sealed `Bounds_AccumulateTransformedLocal`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-L append) | `docs/reconstruction/raw/aa_007647c0_FUN_007647c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007647c0_FUN_007647c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_RegisterObjectAndAccumulateBounds.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007647c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007647c0_Host_RegisterObjectAndAccumulateBounds.md` |
| Live | full hex 109 B; epilogue `C2 04 00`; xref_count ≈ 37 |

---

## 3. Signature (sealed)

```c
// ECX=host*, stack0=object*, RET 4
void Host_RegisterObjectAndAccumulateBounds(HostLike* host, ObjectLike* obj);
```

| Formal | Source | Conf |
|---|---|---|
| host this | ECX → EDI | **High** |
| object* | stack0 | **High** |
| RET 4 | `C2 04 00` | **High** |
| push target | host+0xbc via `FUN_004406e0` | **High** |
| dest bounds | host+4 → ECX of `0074c9c0` | **High** |
| local bounds | object+0x28 | **High** |
| scaleSrc | object+0x64 | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Ptr-vector push | bytes + `FUN_004406e0` decompile | **High** |
| Object virt +0x20(host) | `FF 50 20` | **High** |
| Optional virt +0x80 gate | +0x58/+0x5c/+0x60 cmp | **High** |
| Optional virt +0x5c | flag bit0 @ +0xbc | **High** |
| Host virt +0x0c → xform | `FF 52 0C` | **High** |
| Bounds accumulate | call `0074c9c0` ret 12 | **High** |
| Worker (callees) | analyze complete | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (109 B) — raw W36-L append.

Entry: `53 56 57 8B F9 8D 87 BC 00 00 00 …`.  
Epilogue: `5F 5E 5B C2 04 00`.  
Pad `CC`×3.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers | multi (≈37 xrefs): TacArc mesh, HostPtrTable12 bootstrap, mesh/host helpers |
| Callees | `FUN_004406e0`, `FUN_0074c9c0`, object/host virtuals |

---

## 7. Gaps

1. Product/PDB class English for host and object.  
2. Exact semantics of object virt +0x20 / +0x5c / +0x80 and host virt +0x0c (slots only).  
3. Precise calling convention of host virt+0x0c vs stack reuse into Bounds (stack image at Bounds entry sealed; virt cleanup convention residual).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

ABI, push, offset map, and Bounds handoff sealed by full-body bytes + sealed callee. Virtual product English open → **accept-with-gaps**.
