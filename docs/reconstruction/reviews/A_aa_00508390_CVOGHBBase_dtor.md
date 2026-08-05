# Review A (reconstruction fidelity): `aa_00508390` CVOGHBBase_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508390` |
| **VA** | `0x00508390` |
| **Body** | `0x00508390`–`0x005083af` (32 bytes) |
| **Canonical name** | `CVOGHBBase_dtor` |
| **Ghidra name** | `FUN_00508390` |
| **Review date** | `2026-07-29` (W21-A dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00508390_CVOGHBBase_dtor.md` |
| **System** | `heartbeat` / CVOGHBBase lifecycle |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Complete object destructor body** for `CVOGHBBase`:

1. Always restore base vtbl `PTR_FUN_009cdab0` (`0x009cdab0`) at `this+0`.
2. If owner (`this+0x18`) and list manager (`*(owner+0xB0)`) are both non-null → `FUN_005085b0(listMgr, this)` detach.

Not the scalar deleting dtor (`FUN_00508630`), which adds optional `operator_delete`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508390_FUN_00508390.md` |
| Annotated | `docs/reconstruction/raw/aa_00508390_FUN_00508390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_dtor.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00508390.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508390_CVOGHBBase_dtor.md` |
| Sibling duals | `A_aa_005083b0_CVOGHBBase_AttachOwnerObject`, `A_aa_005085b0_*`, `A_aa_00508200_CVOGHBBase_ctor`, `A_aa_00512060_*` |

---

## 3. Byte seal (`read_memory` @ `0x00508390`, 32 B)

```
8B C1                 mov  eax, ecx
8B 48 18              mov  ecx, [eax+0x18]
85 C9                 test ecx, ecx
C7 00 B0 DA 9C 00     mov  dword [eax], 0x009CDAB0
74 10                 jz   +0x10
8B 89 B0 00 00 00     mov  ecx, [ecx+0xB0]
85 C9                 test ecx, ecx
74 06                 jz   +0x06
50                    push eax
E8 01 02 00 00        call 0x005085b0
C3                    ret
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall`, ECX = this, bare `ret` | **High** | no stack arg loads; `C3` |
| Vtbl store **always** (even if owner null) | **High** | store between first `test` and `jz` |
| Imm `0x009cdab0` | **High** | LE `B0 DA 9C 00` |
| `HB+0x18` owner gate | **High** | `8B 48 18` |
| `owner+0xB0` listMgr gate | **High** | `8B 89 B0 00 00 00` |
| `FUN_005085b0` ECX=listMgr, stack=HB | **High** | ECX left as listMgr; `push eax` |
| Relative CALL target | **High** | next-IP `0x005083af` + `0x201` = `0x005085b0` |
| Body 32 B | **High** | `get_function_by_address` |
| Live decompile ≡ raw CF | **High** | side-by-side |
| Decompiler callee this wrong | **High** | machine wins (same as AttachOwnerObject dual) |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load owner | **Yes** |
| Store base vtbl | **Yes** |
| Gate detach | **Yes** |
| Callee this = listMgr | **Yes** (clean corrected) |
| No free | **Yes** |
| No invented fields | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Role = complete dtor body | **Yes** (vtbl restore + teardown; called from complete dtors) |
| Class = `CVOGHBBase` | **Yes** — same base vtbl as ctor; RTTI family elsewhere |
| Product mangled on this VA | **No** |
| Distinct from scalar `0x00508630` | **Yes** |

**Decision:** promote **`CVOGHBBase_dtor`** (no `_Inferred` — class + role sealed by family duals).

---

## 6. Gaps

1. PDB / mangled complete-dtor symbol.
2. Exhaustive derived complete-dtor chain audit.
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
