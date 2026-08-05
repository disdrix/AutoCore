# Review A (reconstruction fidelity): `aa_0044a0d0` NestedHashBag_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a0d0` |
| **VA** | `0x0044a0d0`–`0x0044a131` (**98 B** / `0x62`) |
| **Canonical name** | `NestedHashBag_Ctor_Inferred` |
| **Ghidra name** | `FUN_0044a0d0` |
| **Review date** | `2026-07-29` (W34-D dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-D) |
| **Counterpart** | `reviews/B_aa_0044a0d0_NestedHashBag_Ctor_Inferred.md` |
| **System** | assets / nested hash-bag (Ass-style twin) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 98 B) + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for nested hash/map bag:

1. SEH frame `LAB_009bd46b`.
2. `FUN_00423d60()` → circular sentinel `new(0x28)` → store at **`this+0x08`**.
3. Zero **`this+0x0c`**.
4. `FUN_004646e0(this+0x10, 9, &sentinel_copy)` — 9-bucket pointer vector filled with sentinel.
5. **`this+0x20 = 1`**, **`this+0x24 = 1`**; return `this`.

Sole caller: `FUN_0074d750` with nested bag at outer **`+0x0c`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-D append) | `docs/reconstruction/raw/aa_0044a0d0_FUN_0044a0d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044a0d0_FUN_0044a0d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHashBag_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044a0d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044a0d0_FUN_0044a0d0.md` |
| Named record | `docs/reconstruction/functions/aa_0044a0d0_NestedHashBag_Ctor_Inferred.md` |
| Live | decompile ≡ raw CF; full 98 B hex; sole xref `0074d786` |
| Context | W32-D / W32-E bag twins; W33-B callees |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
NestedHashBag* NestedHashBag_Ctor_Inferred(NestedHashBag* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack `[esp+0x18]` → ESI after SEH+pushes | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

Decompiler `undefined FUN_0044a0d0(void)` is incomplete — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
self = stack_arg
sentinel = FUN_00423d60()
self[+8] = sentinel
self[+0xc] = 0
FUN_004646e0(self+0x10, 9, &sentinel)
self[+0x20] = 1
self[+0x24] = 1
return self
```

| Stage | Match | Conf |
|---|---|---|
| sentinel @ +8 | **Yes** | **High** |
| size0 @ +0xc | **Yes** | **High** |
| bucket vec cap 9 | **Yes** | **High** |
| flags 1/1 | **Yes** | **High** |
| Twin of 00423cf0 / 00469db0 | **Yes** (CF + callees) | **High** |
| Product class English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product/PDB type name for bag / parent `FUN_0074d750` (vtable `PTR_FUN_00aa05cc`).
2. Meaning of unwritten `+0x00/+0x04` and flags `+0x20/+0x24`.
3. Full product contracts of callees (owned in W33-B duals; residual English).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
