# Review A (reconstruction fidelity): `aa_004447e0` Palantir_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004447e0` |
| **VA** | `0x004447e0`–`0x004447FE` exclusive (**30 B**) |
| **Canonical name** | `Palantir_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004447e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-J) |
| **Counterpart** | `reviews/B_aa_004447e0_Palantir_ScalarDeletingDtor.md` |
| **System** | client / Palantir host scalar deleting destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 30 B) + vtbl `0x00a9f76c` + complete dtor peer W34-K. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar deleting destructor for the Palantir host: run complete dtor (`FUN_00754320`), optionally `operator_delete(this)` when `flags&1`, return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-J append) | `docs/reconstruction/raw/aa_004447e0_FUN_004447e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004447e0_FUN_004447e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004447e0.cpp` |
| Function records | `functions/aa_004447e0_FUN_004447e0.md`, `functions/aa_004447e0_Palantir_ScalarDeletingDtor.md` |
| Complete dtor | `aa_00754320` Palantir_CompleteDtor (W34-K) |
| Live | decompile + 30 B hex + vtbl dword[0] |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this
void* __thiscall Palantir_ScalarDeletingDtor(Palantir* self, unsigned char flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| flags | stack (`F6 44 24 08 01` after PUSH ESI) | **High** |
| cleanup | `C2 04 00` | **High** |
| return | EAX = ESI = this | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = ECX
CALL FUN_00754320          // complete dtor; ECX still this
if (flags & 1) operator_delete(ESI)
EAX = ESI
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| this → ESI | `56 8B F1` | **High** |
| complete dtor | rel32 → `0x00754320` | **High** |
| flags&1 free | `TEST [ESP+8],1` | **High** |
| vtbl[0] slot | `*(0x00a9f76c) == 0x004447e0` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B) — see raw W35-J append.

```
56 8B F1 E8 38 FB 30 00 F6 44 24 08 01 74 09 56 E8 2D 50 04 00 83 C4 04 8B C6 5E C2 04 00
```

Pad: `CC CC` at `0x004447FE`; next @ `0x00444800`.

**Decompile ≢ bytes:** complete dtor shown argless; ESI save implicit. **Bytes win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | data only — `PTR_FUN_00a9f76c[0]` |
| Callees | `Palantir_CompleteDtor`, `operator_delete` |

---

## 7. Gaps

1. Exact MSVC demangle string (naming-only).  
2. Runtime / bit-exact / differential.

---

## 8. Verdict

Classic scalar-deleting pattern fully sealed by 30 B hex + vtbl + sealed complete dtor peer → **accept**.
