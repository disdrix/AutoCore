# Review A (reconstruction fidelity): `aa_00581500` Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581500` |
| **VA** | `0x00581500`–`0x00581517` (**24 B** / `0x18`; pad `CC` after) |
| **Canonical name** | `Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred` (Ghidra `FUN_00581500`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W29-O) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00581500_Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.md` |
| **System** | client-fx / type-0xF stop + event-variant reload (MI public entry) |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_xrefs_to`. **No** `disassemble_bytes`. Impl dual W28-H for callee role.

---

## 1. Purpose

**Public MI/vb this-adjustor** for `Object_StopTypeF_ReloadEventVariant_Inferred` (`0x00514d80`):

1. Load pointer at `this - 0x8C`
2. Load delta dword at that pointer `+4`
3. `this' = this - 0x8C + delta`
4. Call impl (thiscall; plain ret)
5. `ret 4` (virtual ABI)

No other logic.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00581500_FUN_00581500.md` | Append re-verify |
| Annotated | `docs/reconstruction/raw/aa_00581500_FUN_00581500.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.cpp` | New |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00581500.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_00581500_Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_00581500_FUN_00581500.md` | Updated |
| Live decompile | Ghidra @ `0x00581500` | elides adjust (residual) |
| Live bytes | `read_memory` 32 B | body + pad sealed |
| Xrefs | `get_xrefs_to` / complete | 1 CALL + 7 JMP peers |

**Not performed:** Launcher, runtime golden, dual of peer adjustors / `FUN_005d49e0`.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = subobject this
// stack: 1 ignored dword
// ret 4
// void
void Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred(void *self_sub);
```

| Item | Evidence | Conf |
|---|---|---|
| Body 24 B + `CC` pad | `read_memory` | **High** |
| Adjust offsets `-0x8C` / `+4` | `8B 81 74 FF FF FF` / `8B 50 04` / `8D 8C 0A 74…` | **High** |
| Callee `0x00514d80` | relative `E8` math | **High** |
| `ret 4` | `C2 04 00` | **High** |
| Decompiler void surface alone | incomplete | **Low** as sole source |
| Name from W28-H impl role | structural `_Inferred` | **High** for role; product spelling open |

---

## 4. Control flow: clean ≡ bytes (prefer) ≡ raw append

| Stage | Match |
|---|---|
| Load vb/base @ this-0x8C | **Yes** (bytes) |
| Delta @ +4 | **Yes** |
| LEA adjusted this | **Yes** |
| Call impl | **Yes** |
| ret 4 | **Yes** |
| Decompile-only surface | **No** — must not ship as full ABI |

---

## 5. Gaps / open

1. Product/PDB method spelling.
2. Exhaustive vtable slot index list for peer JMP adjustors.
3. Runtime / bit-exact — open.

**Verdict:** **accept** — 24 B CF + ABI + adjust math + callee sealed; product spelling `_Inferred` only.
