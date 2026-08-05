# Review A (reconstruction fidelity): `aa_00996bc0` Host54_NestedHash0xC_At28_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996bc0` |
| **VA** | `0x00996bc0`–`0x00996c1e` (**94 B**) |
| **Canonical name** | `Host54_NestedHash0xC_At28_Ctor_Inferred` |
| **Ghidra name** | `FUN_00996bc0` |
| **Review date** | `2026-07-29` (W35-S dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-S) |
| **Counterpart** | `reviews/B_aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md` |
| **System** | NestedHash0xC host with prefix fields |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 94 B) + `analyze_function_complete` + caller `FUN_00989cf0` decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher. No parent ledger.

---

## 1. Purpose

Placement constructor for a **0x54-byte** host:

1. SEH `LAB_009acd74`.
2. Zero prefix dwords/`+0x0c` byte; set **`+0x10 = 8`**; zero `+0x14`, `+0x1c`, `+0x20`, `+0x24` (**skip `+0x18`**).
3. **`NestedHash_Ctor_Sentinel0xC_Inferred(self+0x28)`** (W34-F).
4. **`self+0x50 = 1`**.
5. Return self; **`RET 4`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-S append) | `docs/reconstruction/raw/aa_00996bc0_FUN_00996bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00996bc0_FUN_00996bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host54_NestedHash0xC_At28_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00996bc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00996bc0_FUN_00996bc0.md` |
| Named record | `docs/reconstruction/functions/aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md` |
| Live | decompile; full 94 B hex; xref `00989d1e`; caller places at `+0x14`, CS at `+0x68` |
| Context | W34-F NestedHash0xC; sibling host `0096eec0` |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
Host54_NestedHash0xC_At28* Host54_NestedHash0xC_At28_Ctor_Inferred(Host54_NestedHash0xC_At28* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack → ESI (`MOV ESI,[ESP+0x14]` after SEH/push) | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x0C; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
self = stack_arg
zero +0,+4,+8; byte +0xc=0; +0x10=8; +0x14=0
// +0x18 unwritten
zero +0x1c,+0x20,+0x24
NestedHash_Ctor_Sentinel0xC(self+0x28)
self[+0x50]=1
return self
```

| Stage | Match | Conf |
|---|---|---|
| Prefix stores | decompile ≡ bytes | **High** |
| NestedHash @ +0x28 | decompile ≡ bytes ≡ W34-F | **High** |
| Flag @ +0x50 | decompile ≡ bytes | **High** |
| Span 0x54 | caller `+0x68 - +0x14` | **High** |
| +0x18 skip | no store in body hex | **High** |

---

## 5. Gaps

- Product English for prefix / capacity-8.
- Intent of unwritten `+0x18`.
- Outer host `FUN_00989cf0` product plate (CS @ +0x68).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, prefix layout, NestedHash0xC at +0x28, flag +0x50, span 0x54. Residual product English → **accept-with-gaps**.
