# Review A (reconstruction fidelity): `aa_0048981c` operator_delete_array

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048981c` |
| **VA** | `0x0048981c`–`0x00489821` (**6 B**) |
| **Canonical name** | `operator_delete_array` |
| **Demangle / CRT** | `operator delete[]` |
| **Ghidra name** | `operator_delete[]` |
| **Decomp alias** | `operator_delete__` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Path A — reconstruction fidelity (OWN-ONLY dual R10-010) |
| **Counterpart** | `reviews/B_aa_0048981c_operator_delete_array.md` |
| **System** | CRT universal (partition seed inventory-transfer / parent `0x005725a0`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**IAT thunk** for MSVC CRT **`operator delete[](void*)`**.

Single instruction:

```
0048981c  FF 25 98 66 9C 00   JMP dword ptr [0x009c6698]
```

No local free logic — transfer control to the import table entry for array `operator delete[]`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R10 append) | `raw/aa_0048981c_operator_delete__.md` |
| Annotated | `raw/aa_0048981c_operator_delete__.annotated.md` |
| Clean | `reconstructed-exact/operator_delete_array.cpp` |
| Twin | `reconstructed-exact/operator_delete__.cpp` |
| Live decompile | Ghidra `decompile_function` @ `0x0048981c` |
| Complete analyze | `analyze_function_complete` (thunk, cdecl, ≥100 xrefs) |
| Bytes | `read_memory` 12 B @ `0x0048981c` + 4 B IAT @ `0x009c6698` |
| Disasm | `disassemble_function` → sole `JMP [0x009c6698]` |
| Caller ABI | `get_assembly_context` @ `0x0057072d` (`PUSH; CALL; ADD ESP,4`) |
| Parent | dualed `InventoryGrid_CompleteDtor` `0x005725a0` (cells `@+0x28`) |

**Not performed:** CRT internal free algorithm; Launcher runtime; bit-exact image-wide.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body = 6 B `JMP [0x009c6698]` | **Confirmed** | `read_memory` + `disassemble_function` |
| IAT is `operator delete[]` (array) | **Confirmed** | Ghidra name `operator_delete[]`; sibling scalar at +6 |
| `__cdecl` void(void*) | **Confirmed** | signature + caller `ADD ESP,4` |
| Returns (not noreturn) | **Confirmed** | fall-through after CALL at `0x00570732` |
| Distinct from scalar `operator_delete` | **Confirmed** | different IAT `[0x009c6694]` |
| Jumptable / recursive body | **Falsified** | decomp artifacts only |
| CRT impl dualed at this VA | N/A | external import; correct scope |

---

## 4. Control flow: clean ≡ raw ≡ live bytes

| Stage | Match |
|---|---|
| Single IAT JMP | Yes (bytes) |
| No local prologue/epilogue | Yes |
| End before sibling `0x00489822` | Yes |
| Decomp recursive self-call | **Ignored** (artifact) |

### Recovered CF

```c
void __cdecl operator_delete_array(void *block) {
  (*IAT_operator_delete_array)(block);  // JMP [0x009c6698]
}
```

---

## 5. Callers / callees

| Direction | Detail |
|---|---|
| Callees | none in-image (IAT indirection only) |
| Callers | ≥100 xrefs — InventoryGrid cell free, vector/`new[]` teardown, Unwind helpers, UI/string arrays, skill/status buffers, etc. |
| Parent seed | `0x005725a0` InventoryGrid_CompleteDtor → `operator_delete[]` cells `@+0x28` |
| Sample site | `0x0057072d` AllocateCellArray free-old path |

---

## 6. Naming

| Name | Status |
|---|---|
| `operator_delete_array` | **Canonical** (filesystem-safe) |
| `operator delete[]` | CRT demangle / inventory |
| `operator_delete[]` | Ghidra function name |
| `operator_delete__` | Ghidra decomp encoding |
| `_Inferred` | **not required** — CRT identity sealed |

---

## 7. Gaps

None material on **thunk** CF/ABI/name. External CRT body and runtime Confirmed remain open by design (terminal **false**).

---

## 8. Verdict

**accept** — 6-byte IAT thunk for `operator delete[]` fully sealed; dual A agrees clean ≡ bytes; decompiler jumptable/self-call noise discarded.
