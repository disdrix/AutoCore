# Review A (reconstruction fidelity): `aa_00508630` CVOGHBBase_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508630` |
| **VA** | `0x00508630` |
| **Body** | `0x00508630`–`0x00508667` (**55** bytes / `0x37`) |
| **Canonical name** | `CVOGHBBase_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00508630` |
| **Review date** | `2026-07-29` (W23-Q dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00508630_CVOGHBBase_ScalarDeletingDtor.md` |
| **System** | `heartbeat` / CVOGHBBase lifecycle |
| **Live tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC **scalar deleting destructor** for `CVOGHBBase` (base vtbl slot 0):

1. Always restore base vtbl `PTR_FUN_009cdab0` (`0x009cdab0`) at `this+0`.
2. If owner (`this+0x18`) and list manager (`*(owner+0xB0)`) both non-null → `FUN_005085b0(listMgr, this)` detach.
3. If `(flags & 1)` → `operator_delete(this)`.
4. Return `this`.

Distinct from complete body `CVOGHBBase_dtor` @ `0x00508390` (no free, no flags formal).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508630_FUN_00508630.md` (+ W23-Q seal) |
| Annotated | `docs/reconstruction/raw/aa_00508630_FUN_00508630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_ScalarDeletingDtor.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00508630.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508630_FUN_00508630.md` |
| Named record | `docs/reconstruction/functions/aa_00508630_CVOGHBBase_ScalarDeletingDtor.md` |
| Sibling duals | `A_aa_00508390_CVOGHBBase_dtor`, `A_aa_00508200_CVOGHBBase_ctor`, `A_aa_005085b0_*` |

---

## 3. Byte seal (`read_memory` full body)

```
00508630  56                 push esi
00508631  8B F1              mov  esi, ecx                 ; this
00508633  8B 46 18           mov  eax, [esi+0x18]          ; owner
00508636  85 C0              test eax, eax
00508638  C7 06 B0 DA 9C 00  mov  dword [esi], 0x009CDAB0  ; vtbl always
0050863E  74 12              jz   skip_unlink
00508640  8B 80 B0 00 00 00  mov  eax, [eax+0xB0]          ; listMgr
00508646  85 C0              test eax, eax
00508648  74 08              jz   skip_unlink
0050864A  56                 push esi                      ; HB*
0050864B  8B C8              mov  ecx, eax                 ; ECX = listMgr
0050864D  E8 5E FF FF FF     call 0x005085b0
skip_unlink:
00508652  F6 44 24 08 01     test byte [esp+8], 1          ; flags
00508657  74 09              jz   no_free
00508659  56                 push esi
0050865A  E8 ..              call operator_delete
0050865F  83 C4 04           add  esp, 4
no_free:
00508662  8B C6              mov  eax, esi
00508664  5E                 pop  esi
00508665  C2 04 00           ret  4
```

Hex: `568bf18b461885c0c706b0da9c0074128b80b000000085c07408568bc8e85efffffff644240801740956e8c311f8ff83c4048bc65ec20400`

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall`, ECX = this, **`ret 4`** | **High** | `C2 04 00` |
| Vtbl store **always** (even if owner null) | **High** | store before first jz |
| Imm `0x009cdab0` | **High** | LE `B0 DA 9C 00` |
| `HB+0x18` owner gate | **High** | `8B 46 18` |
| `owner+0xB0` listMgr gate | **High** | `8B 80 B0 00 00 00` |
| `FUN_005085b0` ECX=listMgr, stack=HB | **High** | `push esi; mov ecx,eax` |
| Relative CALL → `0x005085b0` | **High** | next-IP `0x00508652` + (−0xA2) |
| `(flags & 1)` → `operator_delete` | **High** | `test [esp+8],1` |
| EAX = this | **High** | `mov eax,esi` |
| Body 55 B / end `00508667` | **High** | `get_function_by_address` |
| Vtbl slot 0 @ `0x009cdab0` | **High** | `read_memory` vtbl LE `30865000` |
| Live decompile ≡ raw CF | **High** | side-by-side |
| Decompiler callee this wrong | **High** | machine wins (same as complete dtor dual) |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load owner | **Yes** |
| Store base vtbl | **Yes** |
| Gate detach | **Yes** |
| Callee this = listMgr | **Yes** (clean corrected) |
| Optional free | **Yes** |
| Return this | **Yes** |
| No invented fields | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Role = scalar deleting dtor | **Yes** (flags&1 free + complete body shared) |
| Class = `CVOGHBBase` | **Yes** — same base vtbl as ctor/dtor family |
| Vtbl[0] placement | **Yes** — `0x009cdab0+0` |
| Product mangled on this VA | **No** |
| Distinct from complete `0x00508390` | **Yes** |

**Decision:** promote **`CVOGHBBase_ScalarDeletingDtor`** (no `_Inferred` — class + role sealed by family duals).

---

## 6. Gaps

1. Product/PDB mangled name on this VA.
2. Runtime / bit-exact.

---

## 7. Verdict

**accept** — full body bytes, ABI, vtbl restore, owner/list unlink, and scalar free sealed. Matches complete-dtor sibling contract with free epilogue added.
