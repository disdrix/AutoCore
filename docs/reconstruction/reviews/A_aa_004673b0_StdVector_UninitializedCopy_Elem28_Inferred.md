# Review A (reconstruction fidelity): `aa_004673b0` StdVector_UninitializedCopy_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004673b0` |
| **VA** | `0x004673b0`–`0x00467406` (**87 B**) |
| **Canonical name** | `StdVector_UninitializedCopy_Elem28_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004673b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-T) |
| **Counterpart** | `reviews/B_aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` |
| **System** | containers (shared) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (90 B) + `get_function_by_address` + `analyze_function_complete`; 4 callers / 4 xrefs; leaf. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **uninitialized_copy** for trivially copyable T size **0x1c**:

```
if first == last: return
for each element in [first, last):
  if dest: fieldwise 7-dword assign first → dest
  first += 0x1c; dest += 0x1c
```

Sole parent: `StdVector_InsertN_Elem28_CountEcx_Inferred` (`0x00466ea0`) uses this for prefix/suffix relocate on grow and hole paths.

**Not** string uninitialized_copy (`0x00431430` / `FUN_0046a2c0` ctor loop), not dword memmove, not assign-with-dtor.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004673b0_FUN_004673b0.md` (+ 2026-07-29 W35-T append) |
| Annotated | `docs/reconstruction/raw/aa_004673b0_FUN_004673b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004673b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004673b0_FUN_004673b0.md` |
| Named record | `docs/reconstruction/functions/aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; bare RET; leaf; 4 xrefs in parent only |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EAX=dest; ECX=first; stack last; bare RET
void StdVector_UninitializedCopy_Elem28_Inferred(
    Pod28* dest /*EAX*/,
    Pod28* first /*ECX*/,
    Pod28* last /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| dest | **EAX** (`LEA ECX,[EAX+0x18]`, `TEST EAX`) | **High** |
| first | **ECX** (`MOV ESI,ECX`) | **High** |
| last | stack (`CMP ESI,[ESP+8]` / `[ESP+0x14]`) | **High** |
| cleanup | bare `RET` (`C3`) | **High** |
| thiscall plate | **reject** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if first == last: return
loop:
  if dest: copy 7 dwords
  first += 0x1c; dest += 0x1c; tail cursors += 0x1c
  until first == last
```

| Stage | Match | Conf |
|---|---|---|
| Empty-range early out | **Yes** | **High** |
| 7-lane POD copy | **Yes** | **High** |
| Stride 0x1C | **Yes** | **High** |
| Null-dest skip stores | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
56 8B F1 3B 74 24 08 74 4C 53 55 8D 48 18 8D 56 18 57 85 C0 74 2A
… 83 C6 1C 83 C0 1C 83 C1 1C 83 C2 1C 3B 74 24 14 75 C0 5F 5D 5B 5E C3
```

Body length **87 B**. Full hex: raw W35-T append.

---

## 6. Gaps

- Product/PDB T English (anm residual only).
- Runtime / bit-exact.
- Null-dest path residual (unused by sole caller).

---

## 7. Verdict

ABI, empty-range gate, stride-0x1c POD copy, and sole-parent wiring sealed from live decompile + full-body `read_memory` + 4 xrefs → **accept**.
