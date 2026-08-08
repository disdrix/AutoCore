# Review B (adversarial): `aa_00988710` UiOwnedBlock_CompleteBeforeDelete_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00988710` |
| **VA** | `0x00988710`–`0x0098879e` (**143 B** / `0x8F`) |
| **Canonical name** | `UiOwnedBlock_CompleteBeforeDelete_Inferred` |
| **Ghidra name** | `FUN_00988710` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / claim falsification (OWN-ONLY MEGA-123) |
| **Counterpart** | `reviews/A_aa_00988710_UiOwnedBlock_CompleteBeforeDelete_Inferred.md` |
| **System** | UI owned-block complete destructor |
| **Evidence pass** | Same live Ghidra suite as Path A. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Attack surface (claims under test)

| # | Hostile claim | Result |
|---|---|---|
| H1 | This is a **scalar-deleting** dtor that frees `this` | **Falsified** |
| H2 | **stdcall / stack-this** (like UiTextLayout `RET 4`) | **Falsified** |
| H3 | Decompiler body is complete (ends at `operator_delete`) | **Falsified** |
| H4 | `operator_delete` frees the **host** block | **Falsified** |
| H5 | Product class name is demangled / RTTI-sealed | **Falsified** (gap) |
| H6 | Second iface release is a distinct second member | **Falsified** |
| H7 | Tree is isnil31 / size-0x38 family | **Falsified** |
| H8 | Skill-HB combat effect applicator (partition bucket) | **Falsified** |

---

## 2. Falsification notes

### H1 / H4 — host free

All 18 call sites load a slot pointer, call `FUN_00988710` with **ECX=block**, then `operator_delete(block)` and null the slot. Body only deletes `[this+4]` (sentinel). No `operator_delete(this)` inside.

### H2 — ABI

`MOV EDI,ECX` + bare `C3`. No stack arg load of this. Distinct from `UiTextLayout_CompleteDtor_Inferred` (`RET 4`).

### H3 — false-noreturn

`read_memory` @ `0x00988785` shows null head/size + SEH restore + `RET` after the delete call. Ghidra body end `00988784` is truncated.

### H5 — product name

No RTTI COL on this helper. Name remains **`_Inferred`**. Partition hint retained as stem.

### H6 — double release

Classic MSVC EH residual for **one** member at `+0x0C`: first path nulls; residual path is dead on normal flow. Same offset both times.

### H7 — tree family

Ctor twin sets isnil at node **`+0x25`** (not +0x31). Erase helper `FUN_0044f3c0` uses `+0x25`. Not isnil31/0x38 family.

### H8 — skills misname

Body has no skill/HB strings, no combat deltas. Only UI tree+iface teardown. Partition bucket is organizational; semantics are UI host cleanup (parent `gfxUIWindow.cpp` path).

---

## 3. Residual risks (not blockers)

| Risk | Severity | Notes |
|---|---|---|
| Product class English | Low | `_Inferred` until demangle/RTTI elsewhere |
| Tree element type | Med | Port needs payload size for node free path inside `0044f3c0` |
| Iface vtbl identity | Low | Destroy slot sealed as +8; type open |
| Runtime | Open | Terminal false by charter |

---

## 4. Verdict rationale

Adversarial path **fails** to break CF/ABI/no-host-free/false-noreturn seal. Remaining gaps are type English — accept-with-gaps consistent with Path A.
