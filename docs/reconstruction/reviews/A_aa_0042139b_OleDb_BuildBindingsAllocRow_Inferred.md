# Review A (reconstruction fidelity): `aa_0042139b` OleDb_BuildBindingsAllocRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042139b` |
| **VA** | `0x0042139b`–`0x0042166d` |
| **Canonical name** | `OleDb_BuildBindingsAllocRow_Inferred` |
| **Ghidra name** | `FUN_0042139b` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-C) |
| **Counterpart** | `reviews/B_aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md` |
| **System** | COM / OLE DB binding build + row alloc |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; parent `FUN_00421362`; continuation dual `aa_00421677` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Build per-column OLE DB-style bindings from column metadata, accumulate row byte size, allocate `ctx->rowBuf`, then continue into CreateAccessor finalize (`FUN_00421677`). Null `ctx+0x10` returns **E_OUTOFMEMORY**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0042139b_FUN_0042139b.md` (+ W23-C append) |
| Annotated | `docs/reconstruction/raw/aa_0042139b_FUN_0042139b.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/OleDb_BuildBindingsAllocRow_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0042139b.cpp` |
| Function record | `docs/reconstruction/functions/aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md` |
| Related dual | `reviews/A_aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md` |
| Live | `decompile_function` `0x0042139b`; `read_memory` entry+mid+tail; `get_function_by_address`; parent `0x00421362` |

---

## 3. Signature

```c
// Ghidra: int FUN_0042139b(void) with unaff_EBX=ctx*, unaff_EBP=parent frame
// Bytes:  fail paths ret 4; pre-entry 0x00421390 mov ebx,[ebp+8]
// Success: jmp 0x00421674 → FUN_00421677 → ret 4
// Return: HRESULT in EAX
```

| Item | Evidence | Conf |
|---|---|---|
| `ret 4` fail paths | `C2 04 00` after E_OUTOFMEMORY / FUN_00422880 fail | **High** |
| EBX = ctx | `[ebx+0x10]/[ebx+0xc]/[ebx+8]` loads; pre-entry mov | **High** |
| Shared EBP/SEH frame | `[ebp-0x1c]/[ebp-0x24]/[ebp-0x18]/[ebp-4]` | **High** |
| HRESULT return | `0x8007000E` / FUN_00422880 / FUN_00421677 | **High** |
| Success is jmp-into-finalize | `EB 09` over SEH filter to `0x00421674` | **High** |

---

## 4. Control flow (sealed from bytes + decompile)

```
SEH=0
if ctx+0x10 == null:
  delete[] tempBindings; SEH=-1; Release; return E_OUTOFMEMORY
if colCount != 0:
  align = FUN_00422900(); mask = ~(align-1)
  for each column:
    status[col]=0
    if maxPayload < cbMaxLen OR wType==0xd:
      wType=0x4082; cb=4; status=1
    else:
      map DBTYPE → size; cb = size*2+2; wType=0x82
    layout value/len/status offs; fill binding (stride 0x34); col side +=0x30
if *ctx == 0:
  hr = FUN_00422880(); if hr<0: cleanup; return hr
  *(*ctx+4) = 1
ctx->rowBuf = new[](rowSize)   // SEH=6
jmp FUN_00421677               // zero + CreateAccessor + ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Null +0x10 → E_OUTOFMEMORY | **Yes** (`B8 0E 00 07 80`) | **High** |
| DBTYPE switch size map | **Yes** (jumptable + cases) | **High** |
| Binding stride 0x34 / col 0x30 | **Yes** (`83 C1 34` / `83 C6 30`) | **High** |
| FUN_00422880 gate | **Yes** | **High** |
| operator_new[] row + store +0x08 | **Yes** | **High** |
| jmp into FUN_00421677 | **Yes** (`EB 09` … `8B 5D 08` @ `00421674`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Spot checks recorded in raw W23-C append. Highlights:

| Addr-rel | Bytes | Decode |
|---|---|---|
| pre-entry | `8B 5D 08` | `mov ebx,[ebp+8]` |
| +0 | `33 FF 89 7D FC` | SEH=0 |
| fail | `B8 0E 00 07 80` … `C2 04 00` | E_OUTOFMEMORY; ret 4 |
| tail | `89 43 08 EB 09 B8 74 16 42 00 C3` | store rowBuf; jmp; SEH filter stub |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA |
|---|---|
| `FUN_00421362` | `0x00421362` |

Xrefs: **1**.

| Callee | VA / note |
|---|---|
| `FUN_00422900` | alignment |
| `FUN_00422880` | gate when `*ctx==0` |
| `operator_new[]` / `operator_delete[]` | CRT |
| `FUN_00421677` | continuation finalize (dual sealed) |

---

## 7. Confidence

| Claim | Level |
|---|---|
| CF / HRESULT / ret 4 / jmp-finalize | **High** |
| Role as OLE DB binding builder | **High** |
| Product type / formal English | **Probable** |
| Full DBBINDING field labels | **Tentative** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product class name for ctx and exact DBBINDING member English.
2. Whether Ghidra should merge `00421362`+`0042139b`+`00421677`.
3. Product meaning of `FUN_00422880` / `FUN_00422900` (not OWN).
4. Live HRESULT under real OLE DB load.

**Verdict:** **accept-with-gaps** — image CF, HRESULT, binding loop structure, and SEH continuation sealed; product naming remains inferred.
