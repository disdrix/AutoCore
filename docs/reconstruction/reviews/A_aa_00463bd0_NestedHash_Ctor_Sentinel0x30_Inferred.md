# Review A (reconstruction fidelity): `aa_00463bd0` NestedHash_Ctor_Sentinel0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00463bd0` |
| **VA** | `0x00463bd0`–`0x00463c31` (**98 B**) |
| **Canonical name** | `NestedHash_Ctor_Sentinel0x30_Inferred` |
| **Ghidra name** | `FUN_00463bd0` |
| **Review date** | `2026-07-29` (W34-F dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-F) |
| **Counterpart** | `reviews/B_aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md` |
| **System** | shared nested hash/map shell |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 98 B) + `analyze_function_complete` xrefs + callee decompile `FUN_005b43b0` / caller `FUN_0075f7f0` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher. No parent ledger.

---

## 1. Purpose

Placement constructor for a **nested hash/map shell** (span 0x28):

1. SEH frame `LAB_009bd31b`.
2. `FUN_005b43b0()` → circular sentinel `new(0x30)` → store at **`this+0x08`**.
3. Zero **`this+0x0c`**.
4. `FUN_004646e0(this+0x10, 9, &sentinel_copy)` — 9-bucket pointer vector filled with sentinel.
5. **`this+0x20 = 1`**, **`this+0x24 = 1`**; return `this`.

Sole caller: `FUN_0075f7f0` with `operator_new(0x28)` host object.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-F append) | `docs/reconstruction/raw/aa_00463bd0_FUN_00463bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00463bd0_FUN_00463bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0x30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00463bd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00463bd0_FUN_00463bd0.md` |
| Named record | `docs/reconstruction/functions/aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md` |
| Live | decompile ≡ raw CF; full 98 B hex; sole xref `0075fa63` |
| Context | W32-D Ass NestedHash twin; W33-B PtrVecShell_InitFill; W30-O notes on `FUN_005b43b0` |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
NestedHash_Sentinel0x30* NestedHash_Ctor_Sentinel0x30_Inferred(NestedHash_Sentinel0x30* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack `[esp+0x18]` → ESI after SEH+pushes | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

Decompiler `undefined FUN_00463bd0(void)` is incomplete — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
self = stack_arg
sentinel = FUN_005b43b0()          // new(0x30) circular
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
| body 98 B / RET 4 | **Yes** | **High** |
| Product class English | shape only | **Inferred** |

Full hex: see raw W34-F append.

---

## 5. Gaps / open

1. Product/PDB type name for nested hash/map (multi-host structural name only).
2. Meaning of unwritten `+0x00/+0x04` and flags `+0x20/+0x24`.
3. Full product contract of sole host `FUN_0075f7f0` / slot `0x1d6`.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
