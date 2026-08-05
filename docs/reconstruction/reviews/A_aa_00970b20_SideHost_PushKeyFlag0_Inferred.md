# Review A (reconstruction fidelity): `aa_00970b20` SideHost_PushKeyFlag0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970b20` |
| **VA** | `0x00970b20`–`0x00970b55` (**54 B**) |
| **Canonical name** | `SideHost_PushKeyFlag0_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00970b20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-N) |
| **Counterpart** | `reviews/B_aa_00970b20_SideHost_PushKeyFlag0_Inferred.md` |
| **System** | Side-host key-event push |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (54 B) + `get_function_by_address` + `analyze_function_complete` + xrefs/call-site `read_memory` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Record a key event with **flag 0** onto the optional side-host object:

1. Key = first dword of ECX key holder.
2. Build `PodU32U8{key, 0}` via stack adapter `FUN_0043e8f0` → `PodU32U8_StoreSplit`.
3. `GuardedVector_PushBackLocked_Stride2_U32U8(pod*, host+0xAC)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00970b20_FUN_00970b20.md` (+ W33-N live seal) |
| Annotated | `docs/reconstruction/raw/aa_00970b20_FUN_00970b20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SideHost_PushKeyFlag0_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970b20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00970b20_FUN_00970b20.md` |
| Named record | `docs/reconstruction/functions/aa_00970b20_SideHost_PushKeyFlag0_Inferred.md` |
| Nested | W32-N `GuardedVector_PushBackLocked_Stride2_U32U8`; W32-M `PodU32U8_StoreSplit` |
| Call sites | `read_memory` @ `0075e320`, `00971030` |

---

## 3. Signature (sealed)

```c
// ECX=keyHolder*; stack host*; RET 0x4
void SideHost_PushKeyFlag0_Inferred(void* keyHolder /*ECX*/, void* host /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| keyHolder | **ECX** (`8B 11` → key) | **High** |
| host | Stack formal; `MOV EDI,[esp+0x1c]` | **High** |
| container | **EDI = host + 0xAC** | **High** |
| flag | **`6A 00`** | **High** |
| cleanup | **`RET 0x4`** | **High** |

Decompiler void/no-args plate is incomplete — **bytes win**.

---

## 4. Control flow (clean ≡ bytes)

```
SUB ESP,8; push ESI/EDI
PUSH 0; materialize key=*ECX onto stack
LEA ESI, local_pod; CALL FUN_0043e8f0   // store split into pod
ADD ESP,8; PUSH EAX(=pod*)
MOV EDI, host; ADD EDI, 0xAC
CALL FUN_0043e7f0                       // locked U32U8 push
pop EDI/ESI; ADD ESP,8; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| flag imm 0 | **Yes** | **High** |
| host+0xAC | **Yes** | **High** |
| nested locked push | **Yes** | **High** |
| two call sites setup | **Yes** | **High** |

---

## 5. Gaps (accepted)

- Product/PDB English for host / event flag 0.
- Nested adapter `0043e8f0` not dual-owned here.
- Runtime / bit-exact.

---

## 6. Verdict rationale

Structural ABI + twin delta + sealed nested push are fully evidenced by bytes and call-site memory. Residual is naming/product English only → **accept-with-gaps**.
