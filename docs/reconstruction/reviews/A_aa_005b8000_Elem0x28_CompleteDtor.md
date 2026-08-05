# Review A (reconstruction fidelity): `aa_005b8000` Elem0x28_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b8000` |
| **VA** | `0x005b8000`–`0x005b810b` exclusive (**267 B** / `0x10B`) |
| **Canonical name** | `Elem0x28_CompleteDtor` |
| **Ghidra name** | `FUN_005b8000` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-F) |
| **Counterpart** | `reviews/B_aa_005b8000_Elem0x28_CompleteDtor.md` |
| **System** | class / cookie-vector element destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry through epilogue) + bulk xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Element **complete destructor** for **0x28-byte** vector elements used by Class_009c7a1c (and peer hosts `FUN_00494170` / `FUN_004941b0`):

1. Destroy+free owned object @ `+0x24` (`FUN_004be2a0` then `operator_delete`).
2. Destroy each list-host pointed by vector `[+0x14,+0x18)` (node payloads, empty list, free head).
3. Free vector storage; free buffer @ `+0x4`.

Not a vtbl slot; not the host complete dtor; not the scalar-deleting wrapper.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-F) | `docs/reconstruction/raw/aa_005b8000_FUN_005b8000.md` |
| Annotated | `docs/reconstruction/raw/aa_005b8000_FUN_005b8000.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Elem0x28_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b8000.cpp` |
| Function records | `functions/aa_005b8000_FUN_005b8000.md`, `functions/aa_005b8000_Elem0x28_CompleteDtor.md` |
| Host user | Class_009c7a1c_CompleteDtor (`aa_004970b0`, W28-M) |
| Live | decompile; body size via epilogue `C3`; 4 DATA xrefs; `FUN_004be2a0` ECX from `8B CE` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=element; bare RET; void
void __thiscall Elem0x28_CompleteDtor(void* elem);
```

| Formal | Source | Conf |
|---|---|---|
| elem | ECX | **High** |
| return | void | **High** |
| stride | **0x28** at all registration sites | **High** |

---

## 4. Control flow (clean ≡ raw; false-noreturn ignored)

```
SEH install (LAB_009a6b0a); state=1
if owned@+0x24:
  FUN_004be2a0(owned)   // ECX=owned
  operator_delete(owned)
owned=0
for it in [begin@+0x14, end@+0x18):
  walk list(*it): free node payloads@+8
  empty list; free nodes + head
if begin@+0x14: operator_delete(begin); zero triple
if begin@+0x4:  operator_delete(begin); zero triple
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| Owned path + zero | **Yes** | **High** |
| List-vector walk | **Yes** (decompile) | **High** |
| Buffer free | **Yes** | **High** |
| Body size / bare RET | **Yes** (bytes) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `6A FF 68 0A 6B 9A 00 64 A1 … 55 56 8B E9` |
| Owned call setup | `8B 75 24` … `8B CE E8 …` → `FUN_004be2a0` |
| Epilogue | `5F 5E 5D 64 89 0D 00 00 00 00 83 C4 10 C3` |
| Pad | `CC`…; next fn @ `0x005b8110` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs (4) | `004970ec`, `00494181`, `004941da`, `004942d6` (DATA) |
| Callees | `FUN_004be2a0`, `operator_delete` |
| Classification | worker |

---

## 7. Confidence

| Claim | Level |
|---|---|
| Element dtor / stride 0x28 | **High** |
| Offsets + free order | **High** |
| Owned dtor identity = FUN_004be2a0 | **High** (call) / product type **Low** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English / demangle for element type and owned object (`FUN_004be2a0`).
2. List node payload semantics.
3. Runtime / bit-exact / differential.
4. Clean rewrite of list-empty free loop is structural (decompiler order sealed; micro-optimal rewrite not bit-exact).

---

## Verdict

**accept-with-gaps** — element CF/ABI/stride/field free order sealed; product types residual.
