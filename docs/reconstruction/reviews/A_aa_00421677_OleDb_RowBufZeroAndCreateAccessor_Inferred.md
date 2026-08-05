# Review A (reconstruction fidelity): `aa_00421677` OleDb_RowBufZeroAndCreateAccessor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421677` |
| **VA** | `0x00421677`–`0x00421732` |
| **Canonical name** | `OleDb_RowBufZeroAndCreateAccessor_Inferred` |
| **Ghidra name** | `FUN_00421677` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-N) |
| **Counterpart** | `reviews/B_aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md` |
| **System** | COM / OLE DB accessor finalize |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` body; parent context `FUN_0042139b`; callee dual `aa_00422830` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Finalize OLE DB accessor setup after parent allocates a row buffer: null-check → zero-fill → CreateAccessor+free-bindings → free temps → COM Release → return HRESULT. Null row buffer returns **E_OUTOFMEMORY**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00421677_FUN_00421677.md` (+ W22-N append) |
| Annotated | `docs/reconstruction/raw/aa_00421677_FUN_00421677.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/OleDb_RowBufZeroAndCreateAccessor_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00421677.cpp` |
| Function record | `docs/reconstruction/functions/aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md` |
| Related dual | `reviews/A_aa_00422830_OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred.md` |
| Live | `decompile_function` `0x00421677`; `read_memory` 200 B; `get_function_by_address`; parent `0x0042139b` |

---

## 3. Signature

```c
// Ghidra: int FUN_00421677(void) with unaff_EBX=ctx*, unaff_EBP=parent frame
// Bytes:  ret 4; pre-entry 0x00421674 mov ebx,[ebp+8]
// Return: HRESULT in EAX
```

| Item | Evidence | Conf |
|---|---|---|
| `ret 4` | `C2 04 00` at body end | **High** |
| EBX = ctx | `[ebx+8]/[ebx+0x10]/[ebx+0xc]` loads | **High** |
| Shared EBP frame | `[ebp-0x1c]/[ebp-0x24]/[ebp-0x18]/[ebp-0xc]/[ebp-4]` | **High** |
| HRESULT return | `0x8007000E` / CreateAccessor result | **High** |

---

## 4. Control flow (sealed from bytes + decompile)

```
if (ctx->rowBuf == NULL):
  delete[] tempBindings; delete[] ctx->auxBuf; SEH=-1; aux=null
  Release(iface); return E_OUTOFMEMORY
zero_fill(ctx->rowBuf, rowSize)
hr = FUN_00422830(...)   // CreateAccessor + free binding heap slots
delete[] tempBindings
if (hr < 0): delete[] ctx->auxBuf; aux=null
SEH=-1; Release(iface); return hr
```

| Stage | Match | Conf |
|---|---|---|
| Null rowBuf fail + E_OUTOFMEMORY | **Yes** (`B8 0E 00 07 80`) | **High** |
| rep stosd/stosb zero fill | **Yes** (`F3 AB` / `F3 AA`) | **High** |
| Call FUN_00422830 | **Yes** (rel32 lands on `0x00422830`) | **High** |
| Free temp; free aux on hr<0 | **Yes** | **High** |
| COM Release vtbl+8 | **Yes** | **High** |
| ret 4 epilogue | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body hex (187 B) recorded in raw W22-N append. Spot checks:

| Addr-rel | Bytes | Decode |
|---|---|---|
| +0 | `8B 7B 08 85 FF` | `mov edi,[ebx+8]; test edi,edi` |
| fail ret | `B8 0E 00 07 80` … `C2 04 00` | E_OUTOFMEMORY; ret 4 |
| zero | `F3 AB` … `F3 AA` | stosd/stosb |
| call | `E8 48 11 00 00` | call CreateAccessor helper |
| end | `5B 8B E5 5D C2 04 00` | pop ebx; leave; ret 4 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA |
|---|---|
| `FUN_0042139b` | `0x0042139b` |

Xrefs: **1**.

| Callee | VA / note |
|---|---|
| `FUN_00422830` | CreateAccessor + free binds (dual sealed) |
| `operator_delete[]` | CRT |

---

## 7. Confidence

| Claim | Level |
|---|---|
| CF / HRESULT / zero-fill / ret 4 | **High** |
| Role as CreateAccessor finalize epilogue | **High** |
| Product type / formal English names | **Probable** |
| Full CreateAccessor arg map from this call site | **Probable** (depends on `aa_00422830`) |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product class name for ctx and IAccessor formal labels.
2. Whether Ghidra should merge with `FUN_0042139b` (SEH split).
3. Live HRESULT / SEH paths under real DB load.
4. Exact meaning of `ctx+0` vs `[ebp-0x18]` in CreateAccessor register map.

**Verdict:** **accept-with-gaps** — image CF and HRESULT sealed; product naming remains inferred.
