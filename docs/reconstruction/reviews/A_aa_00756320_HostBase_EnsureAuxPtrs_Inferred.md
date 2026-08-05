# Review A (reconstruction fidelity): `aa_00756320` HostBase_EnsureAuxPtrs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756320` |
| **VA** | `0x00756320`–`0x007563bf` exclusive (**159 B** / `0x9F`) |
| **Canonical name** | `HostBase_EnsureAuxPtrs_Inferred` |
| **Ghidra name** | `FUN_00756320` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-Q) |
| **Counterpart** | `reviews/B_aa_00756320_HostBase_EnsureAuxPtrs_Inferred.md` |
| **System** | client / host base (`FUN_007560d0` family) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

One-shot ensure of host base aux pointers after `FUN_007560d0` zeros them:

1. If `host+4` **or** `host+8` non-null → return **`0xFFFFFFFF`**.
2. If `(flags & 1)` → `FUN_00986070` (EBX=`*DAT_00d1f624`) → store `host+4`.
3. Always `operator_new(0x14)` + `FUN_00442c80` (`PTR_FUN_00a9f49c`) → `host+8` (null on OOM).
4. Return **0** (success or OOM path).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-Q) | `docs/reconstruction/raw/aa_00756320_FUN_00756320.md` |
| Annotated | `docs/reconstruction/raw/aa_00756320_FUN_00756320.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/HostBase_EnsureAuxPtrs_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00756320.cpp` |
| Function records | `functions/aa_00756320_FUN_00756320.md`, `functions/aa_00756320_HostBase_EnsureAuxPtrs_Inferred.md` |
| Related | base `FUN_007560d0`; phase `PalantirEnv_InitPhases_Inferred`; small ctor `FUN_00442c80` |
| Live | SEH `LAB_009afd8d`; all paths `C2 04 00`; 6 callers |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=host*; stack flags; RET 4
uint32_t __thiscall HostBase_EnsureAuxPtrs_Inferred(void *host, uint32_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`8B F1`) | **High** |
| flags | stack `[esp+4]` after entry frame | **High** |
| return | 0 / `0xFFFFFFFF` | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009afd8d
if [host+4] || [host+8]: return -1
if (flags & 1):
  ebx = *DAT_00d1f624
  [host+4] = FUN_00986070()
raw = operator_new(0x14)
if raw:
  [host+8] = FUN_00442c80(raw); return 0
[host+8] = 0; return 0
```

| Stage | Match | Conf |
|---|---|---|
| Body size 0x9F / RET 4 | **Yes** | **High** |
| Idempotent early fail | **Yes** | **High** |
| Flag bit0 only | **Yes** | **High** |
| Small object 0x14 + vtbl | **Yes** (`FUN_00442c80`) | **High** |
| Six static callers | **Yes** | **High** |

---

## 5. Gaps

- Product / PDB host base class English (`FUN_007560d0` plate).
- Product role of `FUN_00986070` and `DAT_00d1f624` pool/context.
- Product identity of 0x14-byte object (`PTR_FUN_00a9f49c`).
- Meaning of flag bits beyond bit0 (untested).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, idempotence, flag bit0, and slot construction. Residual product English on nested allocators → **accept-with-gaps**.
