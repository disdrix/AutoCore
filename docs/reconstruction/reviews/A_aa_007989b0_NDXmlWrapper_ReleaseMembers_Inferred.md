# Review A (reconstruction fidelity): `aa_007989b0` NDXmlWrapper_ReleaseMembers

| Field | Value |
|---|---|
| **Stable ID** | `aa_007989b0` |
| **VA** | `0x007989b0`–`0x007989ee` |
| **Canonical name** | `NDXmlWrapper_ReleaseMembers` (INFERRED; Ghidra `FUN_007989b0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (XML wrapper teardown) |
| **Counterpart** | `reviews/B_aa_007989b0_NDXmlWrapper_ReleaseMembers_Inferred.md` |
| **System** | shared NDXml / skills bootstrap (also UI / SpecialFX) |
| **Parent chain** | `SkillDefMap_EnsureInitialized` end-of-scope release |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Release members** of a small COM/XML wrapper object (same vtable stamp family as ctor `FUN_00799940`):

```
thiscall/fastcall ECX = wrapper*
*this = &PTR_FUN_00a98338          // vtable reset
if (this[2] != null):
    this[2]->vtable[2](this[2])    // Release @ +8 (slot 2)
    this[2] = 0
if (this[1] != null):
    this[1]->vtable[2](this[1])
    this[1] = 0
operator_delete[](this[4])         // buffer at +0x10
return
```

Bytes (`read_memory`): `mov esi,ecx`; store vtable `C7 06 38 83 A9 00`; dual Release on `[esi+8]` then `[esi+4]`; `push [esi+10h]`; `operator_delete[]`; `ret` (no stack args).

Callers span skill load (`0054b2c0`, `00517400`), NDUI XML init, NDSpecialFX script load, mission helpers, and multiple SEH unwind thunks — **shared infrastructure**, not skill-only.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_007989b0_*` |
| Live Ghidra | `decompile_function`, `read_memory`, callers |
| Twin ctor | `FUN_00799940` / dual `A_aa_00799940_*` |
| Parent skill | EnsureInitialized epilogue |

---

## 3. Signature (sealed)

```c
void __fastcall NDXmlWrapper_ReleaseMembers(NDXmlWrapper *this);
// ECX=this; plain RET; no stack formals
```

| Offset | Role |
|---|---|
| `+0` | vtable (`PTR_FUN_00a98338` after release) |
| `+4` | COM iface A (Release via vtbl+8) |
| `+8` | COM iface B (Release via vtbl+8) |
| `+0x10` | `operator_delete[]` buffer |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX this; no stack args | **Confirmed** | bytes / decompile |
| Releases `[+8]` then `[+4]` via vtbl slot 2 | **Confirmed** | `call [eax+8]` pattern |
| `delete[]` on `[+0x10]` | **Confirmed** | always (null-safe CRT) |
| Shared with UI/FX loaders | **Confirmed** | callers |
| Full C++ dtor vs partial member release | **Open** | may be dtor body without `delete this` |
| Product class name | **Open** | NDXml-ish structural |

---

## 5. Gaps

1. IID/interface identity of the two COM pointers (see ctor CoCreate).
2. Whether callers always stack-allocate wrapper (no `delete this` here).
3. Runtime seal.

**Verdict:** **accept-with-gaps**
