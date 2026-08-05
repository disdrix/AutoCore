# Review A (reconstruction fidelity): `aa_00457b30` NestedHashBag_Ctor_Sentinel0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457b30` |
| **VA** | `0x00457b30`–`0x00457b91` (**98 B**) |
| **Canonical name** | `NestedHashBag_Ctor_Sentinel0x18_Inferred` |
| **Ghidra name** | `FUN_00457b30` |
| **Review date** | `2026-07-29` (W34-G dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-G) |
| **Counterpart** | `reviews/B_aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md` |
| **System** | containers / NestedHashBag shell (sentinel 0x18) |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `read_memory` (full 98 B) + `analyze_function_complete` xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for NestedHash/HeadBag bag:

1. SEH frame `LAB_009bc89b`.
2. `FUN_00457c60()` → circular sentinel `new(0x18)` → **`this+0x08`**.
3. Zero **`this+0x0c`**.
4. `FUN_004646e0(this+0x10, 9, &sentinel_copy)` — 9-bucket pointer vector filled with sentinel.
5. **`this+0x20 = 1`**, **`this+0x24 = 1`**; return `this`; **`RET 4`**.

Sole caller: `FUN_0073c810` — `operator_new(0x40)` then this; zeros **+0x28..+0x3e** after return.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00457b30_FUN_00457b30.md` (+ W34-G append) |
| Annotated | `docs/reconstruction/raw/aa_00457b30_FUN_00457b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHashBag_Ctor_Sentinel0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457b30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00457b30_FUN_00457b30.md` |
| Named record | `docs/reconstruction/functions/aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md` |
| Live | decompile ≡ raw CF; full 98 B hex; sole xref `0073cae5` |
| Context | W30-E `StdList_AllocSentinel_0x18`; W33-B PtrVecShell_InitFill; Ass NestedHash family |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
NestedHashBag_Sentinel0x18* NestedHashBag_Ctor_Sentinel0x18_Inferred(
    NestedHashBag_Sentinel0x18* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack `[esp+0x18]` → ESI | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
self = stack_arg
sentinel = FUN_00457c60()   // new(0x18) circular
self[+8] = sentinel
self[+0xc] = 0
FUN_004646e0(self+0x10, 9, &sentinel)
self[+0x20] = 1
self[+0x24] = 1
return self
```

| Stage | Match | Conf |
|---|---|---|
| SEH install | decompile ≡ bytes | High |
| Sentinel + stores | decompile ≡ bytes | High |
| Fill n=9 | decompile ≡ bytes | High |
| Flags + return | decompile ≡ bytes | High |

---

## 5. Gaps

1. Product English for host bootstrap `FUN_0073c810` and outer type.  
2. Unwritten `+0x00/+0x04`; flag meaning.  
3. Tail fields **+0x28..+0x3e** owned by caller, not this unit.  
4. Runtime / bit-exact / differential — open.

---

## 6. Verdict

Fidelity pass seals ABI, layout, CF, sole caller, and 0x18 sentinel differentiator. Residual product plates → **accept-with-gaps**.
