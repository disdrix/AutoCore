# Review A (reconstruction fidelity): `aa_00494530` Host_ClearListTrackedOwnedInRect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494530` |
| **VA** | `0x00494530`–`0x0049459d` inclusive (**110 B** / `0x6E`) |
| **Canonical name** | `Host_ClearListTrackedOwnedInRect_Inferred` |
| **Ghidra name** | `FUN_00494530` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-D) |
| **Counterpart** | `reviews/B_aa_00494530_Host_ClearListTrackedOwnedInRect_Inferred.md` |
| **System** | host / grid owned@+0x24 rect clear |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body) + `get_xrefs_to`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

For each cell in the host half-open dirty rect, destroy and free the owned pointer at `elem+0x24` (0x28-stride grid at `host+0x28`) and null the slot.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-D append) | `docs/reconstruction/raw/aa_00494530_FUN_00494530.md` |
| Annotated | `docs/reconstruction/raw/aa_00494530_FUN_00494530.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Host_ClearListTrackedOwnedInRect_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00494530.cpp` |
| Function records | `functions/aa_00494530_FUN_00494530.md`, `functions/aa_00494530_Host_ClearListTrackedOwnedInRect_Inferred.md` |
| Owned dtor | `ListTrackedObj_CompleteDtor` (`aa_004be2a0`, W30-P) |
| Live | decompile ≡ raw CF; body 110 B; bare `C3`; wrapper @ `0x0094ece0` |

---

## 3. Signature (sealed)

```c
// ECX=host; bare RET; void
void __fastcall Host_ClearListTrackedOwnedInRect_Inferred(void* host);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`8B F1`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
x = host+0x64
if x >= host+0x6C: RET
do:
  y = host+0x68
  if y < host+0x70:
    do:
      index = *(host+4)*y + x
      elem = *(host+0x28) + index*0x28
      owned = *(elem+0x24)
      if owned:
        FUN_004be2a0(owned)   // thiscall; decompiler omits ECX
        operator_delete(owned)
      *(elem+0x24) = 0        // always (incl. null path)
      y++
    while y < host+0x70
  x++
while x < host+0x6C
RET
```

| Stage | Match | Conf |
|---|---|---|
| Half-open rect fields | **Yes** | **High** |
| Index / stride 0x28 | **Yes** | **High** |
| Dtor + delete + always-null | **Yes** (bytes; decompiler false noreturn) | **High** |
| Body size / bare RET | **Yes** | **High** |
| Wrapper host @ +0xE04→+0xE898 | **Yes** (`read_memory` @ `0x0094ece0`) | **High** |

---

## 5. Gaps

- Product/PDB host type and rect field English.
- Writer of dirty-rect fields before invoke.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, rect math, owned teardown, and wrapper path. Residual product English → **accept-with-gaps**.
