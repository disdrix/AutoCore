# Review A (reconstruction fidelity): `aa_0051d0e0` ObjectCsList_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d0e0` |
| **VA** | `0x0051d0e0`–`0x0051d107` exclusive (**39 B** / `0x27`) |
| **Canonical name** | `ObjectCsList_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_0051d0e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-R) |
| **Counterpart** | `reviews/B_aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md` |
| **System** | object core / CS-owned list teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **complete destructor** for Object SharedBase CS helper list (`core+0xB0`, `sizeof 0x2C`):

1. Install derived vtbl `PTR_FUN_009ce154` @ `this+0`.
2. `FUN_0051bc90(this)` — drain nodes under CS (no `node+4=0`).
3. Install base vtbl `PTR_FUN_009ce07c` @ `this+0`.
4. `FUN_0051bc90(this)` again.
5. `DeleteCriticalSection(this+4)`.

Does **not** free the list object (scalar wrapper `FUN_0051d0c0` / owner free).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-R) | `docs/reconstruction/raw/aa_0051d0e0_FUN_0051d0e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d0e0_FUN_0051d0e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ObjectCsList_CompleteDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051d0e0.cpp` |
| Function records | `functions/aa_0051d0e0_FUN_0051d0e0.md`, `functions/aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md` |
| Twin clear | `ObjectCsList_ClearDestroy_Inferred` W30-F |
| Base scalar | `FUN_0051bf10` (this dual pair) |
| Live | decompile ≡ raw; body hex 39 B; CODE xref only `FUN_0051d0c0` |

---

## 3. Signature (sealed)

```c
// __thiscall/__fastcall; ECX=list*; void; bare RET
void __fastcall ObjectCsList_CompleteDtor_Inferred(void *list);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX (`56 8B F1`) | **High** |
| return | void (`C3`) | **High** |
| free this | never | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
MOV ESI,ECX
*this = PTR_FUN_009ce154
CALL FUN_0051bc90          ; ECX=this
MOV ECX,ESI
*this = PTR_FUN_009ce07c
CALL FUN_0051bc90
ADD ESI,4 ; PUSH ESI
CALL [IAT DeleteCriticalSection]
POP ESI ; RET
```

| Stage | Match | Conf |
|---|---|---|
| Derived vtbl dword `54 E1 9C 00` | **Yes** | **High** |
| Base vtbl dword `7C E0 9C 00` | **Yes** | **High** |
| Dual `FUN_0051bc90` | **Yes** | **High** |
| CS @ +4 DeleteCS | **Yes** | **High** |
| No operator_delete | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `56 8B F1 C7 06 54 E1 9C 00` |
| Body | dual `E8 …` to `0051bc90`; `83 C6 04 56 FF 15 F0 61 9C 00` |
| Epilogue | `5E C3` |
| Size | **39 B** exclusive end `0x0051d107` |
| Full hex | raw W31-R append |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangle for CS-list class.
- Whether second clear is pure base-phase boilerplate vs required product work.
- Nested `FUN_0051bc90` product English (owned separately).
- Runtime / bit-exact / differential.

---

## 7. Verdict

CF, ABI, dual vtbl, DeleteCS, complete-vs-scalar sealed → **accept-with-gaps** (product English residual).
