# Review A (reconstruction fidelity): `aa_00489822` operator_delete

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489822` |
| **VA** | `0x00489822` |
| **Body** | `0x00489822`–`0x00489827` inclusive (**6** B / `0x6`) |
| **Canonical name** | `operator_delete` |
| **Ghidra name** | `operator_delete` |
| **Review date** | `2026-08-05` (R10-001 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00489822_operator_delete.md` |
| **System** | shared CRT import thunk (`client::crt`) |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC **IAT import thunk** for scalar C++ **`operator delete(void*)`**: one instruction jumps through the import address table slot to the bound CRT free entry. Image-wide heap free entry point.

```text
// bytes at 0x00489822
JMP dword ptr [0x009C6694]   // IAT -> CRT operator delete
// cdecl void (void *block); returns
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R10-001 re-verify) | `docs/reconstruction/raw/aa_00489822_operator_delete.md` |
| Annotated | `docs/reconstruction/raw/aa_00489822_operator_delete.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/operator_delete.cpp` |
| Function records | `functions/aa_00489822_operator_delete.md`, `functions/aa_00489822_FUN_00489822.md` |
| Live body | `read_memory` 6 B `FF 25 94 66 9C 00` |
| IAT slot | `read_memory` @ `0x009C6694` (live dword `0x006EA824` in this image) |
| Sibling array delete | `0x0048981c` (`operator_delete[]`, IAT `0x009C6698`) — not OWN |
| Parent seed only | `0x005725a0` inventory-transfer residual rank |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack `[ESP+4]` after CALL | `void *block` | Ghidra param `Stack[0x4]:4`; thousands of `PUSH ptr; CALL 00489822; ADD ESP,4` sites |
| ECX/EDX | unused by thunk | pure JMP; no register setup |
| cleanup | **cdecl** (caller) | CALL sites `ADD ESP,4` |
| return | void; **returns** | CRT free returns; Ghidra `noreturn` is false |
| thunk itself | no frame | single `FF 25` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 6 B = `JMP [0x009C6694]` | **Confirmed** | `read_memory` + `get_function_by_address` end `00489827` |
| Classification IAT thunk | **Confirmed** | Ghidra `classification: thunk`, `is_thunk: true` |
| CRT scalar `operator_delete` name | **Confirmed** | Ghidra custom name; MSVC import pattern; sibling array form adjacent |
| cdecl single pointer formal | **Confirmed** | param storage + CALL site pattern |
| Ghidra noreturn is false | **Confirmed** | known project-wide CRT contamination; free returns |
| Decompiler recursive call is false | **Confirmed** | bytes are JMP-indirect, not CALL self |
| Inventory product identity | **Rejected** | universal free; parent seed only |
| Exact CRT module/export bind | **Open** | IAT target runtime-resolved (`0x006EA824` this image) |
| Runtime / bit-exact / differential of free | **Open** | deferred; out of thunk |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Single `JMP [IAT]` | **Yes** |
| No local free body | **Yes** |
| No stack frame / no RET in thunk | **Yes** (tail transfer) |
| Decompiler "call operator_delete; return" | **Artifact only** — ignore for CF |

---

## 6. Naming gate

- Role = CRT scalar operator delete import thunk — sealed by Ghidra name + IAT pattern + sibling `operator_delete[]`.
- No product demangle required → **no `_Inferred`**.
- Inventory-transfer system label on residual partition is **parent seed**, not leaf identity.

**Verdict:** **accept**.
