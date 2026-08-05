# Review A (reconstruction fidelity): `aa_004bd1b0` COList_ScalarDeletingDestructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bd1b0` |
| **VA** | `0x004bd1b0`–`0x004bd1cd` |
| **Canonical name** | `COList_ScalarDeletingDestructor` |
| **Ghidra name** | `FUN_004bd1b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-L) |
| **Counterpart** | `reviews/B_aa_004bd1b0_COList_ScalarDeletingDestructor.md` |
| **System** | client / COList |
| **Evidence pass** | Live Ghidra `decompile_function` + full-body `read_memory` (30 B) + `get_function_by_address` + `analyze_function_complete` + xrefs + vtbl rdata. Twins: body `COList_Destructor`, ctor `COList_Constructor`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor for **COList**: always destroy body; optionally free heap when bit0 of flags is set; return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W27-L) | `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/COList_ScalarDeletingDestructor.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bd1b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bd1b0_COList_ScalarDeletingDestructor.md` |
| Body twin | `aa_004bbc70` COList_Destructor (W26-J **accept**) |
| Live | decompile ≡ raw; 30 B; exit `C2 04 00` |

---

## 3. Signature (sealed)

```c
void* __thiscall COList_ScalarDeletingDestructor(void* self, uint8_t flags);
// ECX=this; ret 4; EAX=this
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004bd1b0`–`004bd1cd` = **30 B** | **High** |
| thiscall | `8B F1` | **High** |
| ret 4 | `C2 04 00` | **High** |
| vtbl[0] | `0x009cb448` → `0x004bd1b0` | **High** |
| Body callee | `E8` → `0x004bbc70` | **High** |

---

## 4. Control flow (sealed)

```
ESI = this
call COList_Destructor            // FUN_004bbc70
if (flags & 1):
  operator_delete(this)
return this                       // EAX = ESI; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Save this / call body | **Yes** (bytes + decompile) | **High** |
| flags bit0 gate | **Yes** (`F6 44 24 08 01` / `74 09`) | **High** |
| optional delete + ret 4 | **Yes** | **High** |
| Live decompile ≡ scaffold raw | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Full body | `56 8B F1 E8 B8 EA FF FF F6 44 24 08 01 74 09 56 E8 5D C6 FC FF 83 C4 04 8B C6 5E C2 04 00` |
| Pad | `CC CC` after body |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | DATA from `PTR_FUN_009cb448` only |
| Callees | `FUN_004bbc70`, `operator_delete` |
| Ctor twin | `FUN_004bbfb0` → `DAT_00b04830` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / CF / scalar-delete pattern | **High** |
| COList class (vtbl + body twin) | **High** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Runtime hit verification.
2. Field English deferred to ctor/body records.

---

## Verdict

**accept** — leaf wrapper fully sealed by full-body bytes + dual-sealed body dtor twin.
