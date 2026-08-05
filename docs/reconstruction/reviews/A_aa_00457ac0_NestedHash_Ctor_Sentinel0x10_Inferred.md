# Review A (reconstruction fidelity): `aa_00457ac0` NestedHash_Ctor_Sentinel0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457ac0` |
| **VA** | `0x00457ac0`–`0x00457b21` (**98 B**) |
| **Canonical name** | `NestedHash_Ctor_Sentinel0x10_Inferred` |
| **Ghidra name** | `FUN_00457ac0` |
| **Review date** | `2026-07-29` (W34-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-E) |
| **Counterpart** | `reviews/B_aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md` |
| **System** | containers / nested hash bag |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 98 B) + `analyze_function_complete` xrefs + callee decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for NestedHash bag with **0x10** sentinel nodes:

1. SEH frame `LAB_009bc89b` (same as 0x14 twin).
2. `FUN_004397f0()` → circular sentinel `new(0x10)` → **`this+0x08`**.
3. Zero **`this+0x0c`**.
4. `FUN_004646e0(this+0x10, 9, &sentinel_copy)` — 9-bucket fill.
5. **`this+0x20 = 1`**, **`this+0x24 = 1`**; return `this`.

Multi-caller: three once-flag statics, one heap host (`new(0x30)`), one stack-local on gfxDeviceIB path.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00457ac0_FUN_00457ac0.md` (+ W34-E append) |
| Annotated | `docs/reconstruction/raw/aa_00457ac0_FUN_00457ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457ac0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00457ac0_FUN_00457ac0.md` |
| Named record | `docs/reconstruction/functions/aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md` |
| Live | decompile ≡ raw CF; full 98 B hex; 5 xrefs |
| Context | W34-E twin 0x14; W33-B PtrVecShell_InitFill; W32 NestedHash 0x28 |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
NestedHash_Sentinel0x10* NestedHash_Ctor_Sentinel0x10_Inferred(NestedHash_Sentinel0x10* self /*stack*/);
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
sentinel = FUN_004397f0()   // new(0x10) circular
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
| Node size 0x10 | **Yes** (callee) | **High** |
| Product English | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB type English for each static / host.
2. Unwritten `+0x00/+0x04` and flags `+0x20/+0x24`.
3. Unowned callees full contracts.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
