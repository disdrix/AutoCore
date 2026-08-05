# Review A (reconstruction fidelity): `aa_00467320` StdVector_UninitializedFillN_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467320` |
| **VA** | `0x00467320`–`0x0046736e` (**79 B**) |
| **Canonical name** | `StdVector_UninitializedFillN_Elem28_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00467320` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-T) |
| **Counterpart** | `reviews/B_aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` |
| **System** | containers (shared) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (80 B) + `get_function_by_address` + `analyze_function_complete`; 2 callers / 2 xrefs; leaf. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **uninitialized_fill_n** for trivially copyable T size **0x1c**:

```
if count == 0: return
for i in 0..count-1:
  if dest: fieldwise 7-dword assign *value → dest
  dest += 0x1c; count--
```

Sole parent: `StdVector_InsertN_Elem28_CountEcx_Inferred` (`0x00466ea0`) uses this for insert fill after hole open / grow.

**Not** string fill-n, not dword fill (`Mem_FillDwordN`), not assign-with-dtor.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00467320_FUN_00467320.md` (+ 2026-07-29 W35-T append) |
| Annotated | `docs/reconstruction/raw/aa_00467320_FUN_00467320.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00467320.cpp` |
| Function record | `docs/reconstruction/functions/aa_00467320_FUN_00467320.md` |
| Named record | `docs/reconstruction/functions/aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; bare RET; leaf; 2 xrefs in parent only |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// ECX=dest; EDX=value*; EAX=count; bare RET
void StdVector_UninitializedFillN_Elem28_Inferred(
    Pod28* dest /*ECX*/,
    const Pod28* value /*EDX*/,
    int count /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| dest | **ECX** (`LEA EAX,[ECX+0x18]`, loop `ADD ECX,0x1C`) | **High** |
| value* | **EDX** (`MOV EDI,EDX`) | **High** |
| count | **EAX** (`MOV ESI,EAX`; dec ESI) | **High** |
| cleanup | bare `RET` (`C3`) | **High** |
| stack args | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if count == 0: return          // TEST ESI / JBE
loop:
  if dest: copy 7 dwords from *value
  dest += 0x1c; count--
  until count == 0
```

| Stage | Match | Conf |
|---|---|---|
| Zero-count early out | **Yes** | **High** |
| 7-lane POD fill from value* | **Yes** | **High** |
| Stride 0x1C | **Yes** | **High** |
| Null-dest skip stores | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
56 8B F0 85 F6 76 46 53 55 8D 41 18 57 8D 49 00 85 C9 74 2B 8B FA
… 83 C1 1C 83 C0 1C 83 EE 01 75 C6 5F 5D 5B 5E C3
```

Body length **79 B**. Full hex: raw W35-T append.

---

## 6. Gaps

- Product/PDB T English (anm residual only).
- Runtime / bit-exact.
- Null-dest path residual (unused by sole caller).

---

## 7. Verdict

ABI (ECX/EDX/EAX), zero-count gate, stride-0x1c POD fill, and sole-parent wiring sealed from live decompile + full-body `read_memory` + 2 xrefs → **accept**.
