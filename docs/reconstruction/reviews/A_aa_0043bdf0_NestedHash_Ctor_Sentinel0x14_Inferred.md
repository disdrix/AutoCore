# Review A (reconstruction fidelity): `aa_0043bdf0` NestedHash_Ctor_Sentinel0x14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bdf0` |
| **VA** | `0x0043bdf0`–`0x0043be51` (**98 B**) |
| **Canonical name** | `NestedHash_Ctor_Sentinel0x14_Inferred` |
| **Ghidra name** | `FUN_0043bdf0` |
| **Review date** | `2026-07-29` (W34-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-E) |
| **Counterpart** | `reviews/B_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md` |
| **System** | containers / nested hash bag |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 98 B) + `analyze_function_complete` xrefs + callee decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for NestedHash bag with **0x14** sentinel nodes:

1. SEH frame `LAB_009bc89b`.
2. `FUN_0043c460()` → circular sentinel `new(0x14)` → **`this+0x08`**.
3. Zero **`this+0x0c`**.
4. `FUN_004646e0(this+0x10, 9, &sentinel_copy)` — 9-bucket pointer vector filled with sentinel.
5. **`this+0x20 = 1`**, **`this+0x24 = 1`**; return `this`.

Callers: `FUN_0075d470` (NDResourceCache host / `DAT_00d1f050`) and `FUN_0074d750` (nested at `+0x34`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043bdf0_FUN_0043bdf0.md` (+ W34-E append) |
| Annotated | `docs/reconstruction/raw/aa_0043bdf0_FUN_0043bdf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0x14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043bdf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043bdf0_FUN_0043bdf0.md` |
| Named record | `docs/reconstruction/functions/aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md` |
| Live | decompile ≡ raw CF; full 98 B hex; 2 xrefs |
| Context | W32-D NestedHash 0x28; W33-B PtrVecShell_InitFill; twin W34-E 0x10 |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
NestedHash_Sentinel0x14* NestedHash_Ctor_Sentinel0x14_Inferred(NestedHash_Sentinel0x14* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack `[esp+0x18]` → ESI after SEH+pushes | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

Decompiler `undefined FUN_0043bdf0(void)` is incomplete — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
self = stack_arg
sentinel = FUN_0043c460()   // new(0x14) circular
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
| Node size 0x14 | **Yes** (callee) | **High** |
| Product class English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product/PDB type name for NestedHash / flag fields.
2. Meaning of unwritten `+0x00/+0x04`.
3. Full product contracts of unowned `FUN_0043c460` / `FUN_004646e0`.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
