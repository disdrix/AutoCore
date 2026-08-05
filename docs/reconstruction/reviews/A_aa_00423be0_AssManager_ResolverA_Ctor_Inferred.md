# Review A (reconstruction fidelity): `aa_00423be0` AssManager_ResolverA_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423be0` |
| **VA** | `0x00423be0`–`0x00423c35` (**86 B**) |
| **Canonical name** | `AssManager_ResolverA_Ctor_Inferred` |
| **Ghidra name** | `FUN_00423be0` |
| **Review date** | `2026-07-29` (W31-G dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-G) |
| **Counterpart** | `reviews/B_aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md` |
| **System** | assets / assManager |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 86 B) + `analyze_function_complete` xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for AssManager **resolver A**:

1. SEH frame; zero `+0x04`; EH state 0.
2. Install vtbl **`PTR_FUN_00a95acc`** at `+0x00`.
3. Nested ctor **`FUN_00423cf0(this+0x08)`**.
4. **`InitializeCriticalSection(this+0x30)`**.
5. Ready flag **`*(u8*)(this+0x48)=1`**; return `this`.

Sole caller: AssManager init flag-bit0 with `operator_new(0x4c)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00423be0_FUN_00423be0.md` (+ W31-G append) |
| Annotated | `docs/reconstruction/raw/aa_00423be0_FUN_00423be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_ResolverA_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423be0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00423be0_FUN_00423be0.md` |
| Named record | `docs/reconstruction/functions/aa_00423be0_AssManager_ResolverA_Ctor_Inferred.md` |
| Live | decompile ≡ raw CF; body 86 B hex; caller `007b776c` push/call after `new(0x4c)` |
| Context | W30-D AssManager init; W29-D ReleaseOwnedResolvers self+0x08 |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
AssResolverA* AssManager_ResolverA_Ctor_Inferred(AssResolverA* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack `[esp+14]` after SEH+esi | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0xC; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

Decompiler `undefined FUN_00423be0(void)` is incomplete — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
self = stack_arg
self[+4] = 0; EH=0
*self = PTR_FUN_00a95acc
FUN_00423cf0(self+8)
InitializeCriticalSection(self+0x30)
*(u8*)(self+0x48) = 1
return self
```

| Stage | Match | Conf |
|---|---|---|
| vtbl install | **Yes** | **High** |
| nested +0x08 | **Yes** | **High** |
| CS +0x30 | **Yes** | **High** |
| ready +0x48 | **Yes** | **High** |
| Product class English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product/PDB class name for `PTR_FUN_00a95acc`.
2. Nested `FUN_00423cf0` product type (not owned).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
