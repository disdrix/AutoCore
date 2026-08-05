# Review A (reconstruction fidelity): `aa_00423cf0` AssResolverA_NestedHash_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423cf0` |
| **VA** | `0x00423cf0`–`0x00423d51` (**98 B**) |
| **Canonical name** | `AssResolverA_NestedHash_Ctor_Inferred` |
| **Ghidra name** | `FUN_00423cf0` |
| **Review date** | `2026-07-29` (W32-D dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-D) |
| **Counterpart** | `reviews/B_aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md` |
| **System** | assets / assManager / resolver A nested member |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 98 B) + `analyze_function_complete` xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for AssResolverA **nested hash/map** member:

1. SEH frame `LAB_009bcd6b`.
2. `FUN_00423d60()` → circular sentinel `new(0x28)` → store at **`this+0x08`**.
3. Zero **`this+0x0c`**.
4. `FUN_004646e0(this+0x10, 9, &sentinel_copy)` — 9-bucket pointer vector filled with sentinel.
5. **`this+0x20 = 1`**, **`this+0x24 = 1`**; return `this`.

Sole caller: `AssManager_ResolverA_Ctor_Inferred` with `this+0x08`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00423cf0_FUN_00423cf0.md` (+ W32-D append) |
| Annotated | `docs/reconstruction/raw/aa_00423cf0_FUN_00423cf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssResolverA_NestedHash_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423cf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00423cf0_FUN_00423cf0.md` |
| Named record | `docs/reconstruction/functions/aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md` |
| Live | decompile ≡ raw CF; full 98 B hex; sole xref `00423c0e` |
| Context | W31-G parent AssResolverA ctor; twin `FUN_00469db0` |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
AssResolverA_NestedHash* AssResolverA_NestedHash_Ctor_Inferred(AssResolverA_NestedHash* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack `[esp+0x18]` → ESI after SEH+pushes | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

Decompiler `undefined FUN_00423cf0(void)` is incomplete — do not trust as full ABI.

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
| Product class English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product/PDB type name for nested hash/map.
2. Meaning of unwritten `+0x00/+0x04` and flags `+0x20/+0x24`.
3. Full product contracts of `FUN_00423d60` / `FUN_004646e0` (not owned).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
