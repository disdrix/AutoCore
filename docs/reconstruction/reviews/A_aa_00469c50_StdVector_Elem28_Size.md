# Review A (reconstruction fidelity): `aa_00469c50` StdVector_Elem28_Size

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469c50` |
| **VA** | `0x00469c50`–`0x00469c70` (**33 B**) |
| **Canonical name** | `StdVector_Elem28_Size` (**Inferred**) |
| **Ghidra name** | `FUN_00469c50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-J) |
| **Counterpart** | `reviews/B_aa_00469c50_StdVector_Elem28_Size.md` |
| **System** | containers (shared) |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (64 B) + `get_function_by_address` + `analyze_function_complete`; 9 callers / 9 xrefs; leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin **`vector<T, sizeof=0x1c>::size()`** helper (`__fastcall` / thiscall on host):

```
if (*(this+4) == 0) return 0;                 // begin null
return (*(this+8) - *(this+4)) / 0x1c;        // (end - begin) / 28
```

Layout: **begin @ +4**, **end @ +8** (capacity not read). Leaf — no callees.

Multi-domain callers (9): insert/grow paths for 28-byte elements including basic_string bags (`FUN_004306b0` family) and others.

**Not** dword size (`StdVector_DwordSize` @ `0x004024b0`), not capacity, not skill-set 0x18 size.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00469c50_FUN_00469c50.md` (+ 2026-07-29 W33-J append) |
| Annotated | `docs/reconstruction/raw/aa_00469c50_FUN_00469c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Elem28_Size.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469c50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00469c50_FUN_00469c50.md` |
| Named record | `docs/reconstruction/functions/aa_00469c50_StdVector_Elem28_Size.md` |
| Live | decompile ≡ raw CF; full body hex; bare RET; leaf |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// ECX=vec; bare RET; int size in EAX
int __fastcall StdVector_Elem28_Size(void* vec /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| vec | **ECX** | **High** |
| begin | `[ECX+4]` | **High** |
| end | `[ECX+8]` | **High** |
| cleanup | bare `RET` (`C3`) | **High** |
| return | EAX element count | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if begin == 0: return 0
return (end - begin) / 0x1c   // via magic 0x92492493
```

| Stage | Match | Conf |
|---|---|---|
| Null begin early 0 | **Yes** | **High** |
| Size arithmetic /28 | **Yes** | **High** |
| No capacity read | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
8B 41 04 85 C0 75 01 C3 8B 49 08 2B C8 B8 93 24 49 92
F7 E9 03 D1 C1 FA 04 8B C2 C1 E8 1F 03 C2 C3
```

Body length **33 B**. Pad `CC` then next function ~`0x00469c80`. Full hex: raw W33-J append.

---

## 6. Gaps

- Product/PDB host English (multi-domain).
- Runtime / bit-exact.
- Whether any non-vector shares +4/+8 layout (caller-contract residual).

---

## 7. Verdict

ABI, null gate, and stride-0x1c size formula sealed from live decompile + full-body `read_memory` + 9 callers → **accept**.
