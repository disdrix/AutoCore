# Review A (reconstruction fidelity): `aa_00971030` AssPreloader_PendingRemoveWithSideNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971030` |
| **VA** | `0x00971030`–`0x0097104e` (**30 B**) |
| **Canonical name** | `AssPreloader_PendingRemoveWithSideNotify_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00971030` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-D) |
| **Counterpart** | `reviews/B_aa_00971030_AssPreloader_PendingRemoveWithSideNotify_Inferred.md` |
| **System** | AssPreloader / client-fx preload |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (30 B) + `get_function_by_address` + `analyze_function_complete` + xrefs; nested duals W33-N / W35-A |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Pending-side remove for AssPreloader: notify side-host with key flag0, then erase first equal from pending ring at `+0x1C`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971030_FUN_00971030.md` (+ W36-D live seal) |
| Annotated | `docs/reconstruction/raw/aa_00971030_FUN_00971030.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_PendingRemoveWithSideNotify_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971030.cpp` |
| Function record | `docs/reconstruction/functions/aa_00971030_FUN_00971030.md` |
| Named record | `docs/reconstruction/functions/aa_00971030_AssPreloader_PendingRemoveWithSideNotify_Inferred.md` |
| Nested | W33-N `00970b20`; W35-A `0043e630` |
| Caller | W35-A `004ed310` @ `004ed3a5` |

---

## 3. Signature (sealed)

```c
// ECX=AssPreloader*; stack key*; RET 0x4
void AssPreloader_PendingRemoveWithSideNotify_Inferred(
    void* preloader /*ECX*/, const int* key /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| preloader | **ECX** → ESI | **High** |
| key | Stack → EDI | **High** |
| RET | **`C2 04 00`** | **High** |

Full hex: `56578b7c240c8bf1568bcfe8e0faffff5783c61ce8e7d5acff5f5ec20400`

---

## 4. Control flow (clean ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| PushKeyFlag0(ECX=key, host=preloader) | **Yes** | **High** |
| ADD ESI,0x1C then EraseFirstEqual | **Yes** | **High** |
| Order: notify **then** erase | **Yes** | **High** |
| RET 4 | **Yes** | **High** |

---

## 5. Gaps

- Product flag0 English (event kind).  
- Erase AL ignored.  
- Runtime / bit-exact.

---

## Verdict

30 B worker fully sealed via bytes + nested duals. **accept-with-gaps**.
