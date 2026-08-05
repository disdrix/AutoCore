# Review A (reconstruction fidelity): `aa_005d49e0` Object_CompositeStopTypeF_MIEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d49e0` |
| **VA** | `0x005d49e0`–`0x005d4a01` (**34 B** / `0x22`; pad `CC` after) |
| **Canonical name** | `Object_CompositeStopTypeF_MIEntry_Inferred` (Ghidra `FUN_005d49e0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W30-K) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md` |
| **System** | object stop / type-0xF reload (composite MI public entry) |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_xrefs_to`. **No** `disassemble_bytes`. Sibling dual W29-O for `00581500`.

---

## 1. Purpose

Public MI composite stop entry:

1. `FUN_0053d4b0(this - 0x90, param)` — if `*(adj - 0x48) != 0` call `FUN_005070d0`; `ret 4`.
2. `Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred(this - 0x10, param)` (W29-O) → further vb adjust → type-0xF impl.

No other logic. Entry via four MI JMP adjustors only.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005d49e0_FUN_005d49e0.md` | Append live re-verify |
| Annotated | `docs/reconstruction/raw/aa_005d49e0_FUN_005d49e0.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_CompositeStopTypeF_MIEntry_Inferred.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d49e0.cpp` | Refined |
| Function named | `docs/reconstruction/functions/aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_005d49e0_FUN_005d49e0.md` | Updated |
| Live decompile | Ghidra @ `0x005d49e0` | elides adjusts (residual) |
| Live bytes | `read_memory` 64 B | body + pad + sibling stub |
| Xrefs | 4 JMP adjustors | sealed |

**Not performed:** Launcher, runtime golden, dual of `FUN_0053d4b0` / `FUN_005070d0` / adjustor stubs.

---

## 3. Signature (image-sealed)

```c
// __thiscall ECX=this_entry; stack (param); ret 4; void
void __thiscall Object_CompositeStopTypeF_MIEntry_Inferred(void *self, uint32_t param);
```

| Item | Evidence | Conf |
|---|---|---|
| Body 34 B + `ret 4` | `read_memory` / `C2 04 00` | **High** |
| Adjusts `−0x90` / `−0x10` | `8D 8E 70 FF FF FF` / `8D 4E F0` | **High** |
| Callees `0053d4b0` / `00581500` | relative `E8` math | **High** |
| Sole CALL of `00581500` is this unit | W29-O + site `0x005d49f8` | **High** |
| 4 JMP-only xrefs | adjustor prologues | **High** |
| Product spelling | structural `_Inferred` | **Low** |
| Decompiler surface alone | incomplete | **Low** as sole source |

---

## 4. Control flow: clean ≡ bytes (prefer) ≡ raw append

| Stage | Match |
|---|---|
| ESI=this, EDI=param | **Yes** (bytes) |
| call 0053d4b0(this-0x90) | **Yes** |
| call 00581500(this-0x10) | **Yes** |
| ret 4 | **Yes** |
| No extra branches | **Yes** |

---

## 5. Gaps

- Product/PDB method English.
- Nested semantics of `0053d4b0` / `005070d0` (not OWN).
- Exhaustive vtable slot catalog for 4 adjustors.
- Runtime / bit-exact open.

---

## 6. Verdict

CF + ABI + callee adjusts fully sealed against bytes; only product English residual → **accept** (gaps are non-blocking for structural seal).
