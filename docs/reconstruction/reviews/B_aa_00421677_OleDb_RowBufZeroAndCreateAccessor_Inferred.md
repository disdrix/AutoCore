# Review B (skeptical / adversarial): `aa_00421677` OleDb_RowBufZeroAndCreateAccessor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421677` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | True standalone `void` function with no args | Epilogue **`ret 4`**; pre-entry `mov ebx,[ebp+8]` | **Falsified** pure-void — **1 stack formal** / shared frame |
| 2 | Decompiler `return -0x7ff8fff2` is opaque magic | Bytes `B8 0E 00 07 80` = `0x8007000E` | **Confirmed** = **E_OUTOFMEMORY** |
| 3 | Unit is mission/net/gameplay logic | Sole caller binding builder; callee is OleDb CreateAccessor dual | **Reject** gameplay alias — **OLE DB finalize** |
| 4 | Zero-fill is optional / debug only | Unconditional `rep stosd`/`stosb` when rowBuf non-null | **Falsified optional** — **always** |
| 5 | CreateAccessor args match decompiler `(*EBX, size)` only | Bytes push size + `[ebx]`; set EAX/ECX/EDX before call | **Over-narrow decompiler** — **custom multi-reg+stack ABI** |
| 6 | Aux free on all paths | Aux free only on null-row and `hr < 0` | **Confirmed gated** — success keeps aux |
| 7 | Name without `_Inferred` is product-proven | No RTTI/string for this VA | **Needs `_Inferred`** |
| 8 | Runtime verified | No live capture this dual | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| E_OUTOFMEMORY + null rowBuf | **High** | Wrong OOM port |
| Zero-fill size from `[ebp-0x24]` | **High** | Stale row data → DB corruption |
| Call into `0x00422830` | **High** | Miss CreateAccessor |
| ret 4 / shared frame | **High** | Stack smash if re-wrapped wrong |
| Product names for formals | **Medium** | Doc-only |
| Full parent binding layout | **Low–Medium** (out of ownership) | Mis-size row buffer in ports |

---

## 3. Cross-check against raw + bytes

```
raw decompile:
  if (EBX[2]==0) cleanup; return -0x7ff8fff2
  zero EBX[2] for size [ebp-0x24]
  hr = FUN_00422830(*EBX, size)
  delete[] [ebp-0x1c]; if (hr<0) free EBX[4]
  Release [ebp-0x18]; return hr

bytes:
  test [ebx+8]; mov eax,0x8007000E; ret 4
  rep stosd/stosb; call 0x00422830; ret 4
```

Clean named plate must not invent a portable `__thiscall` without documenting the shared EBP contract. Scaffold clean preserves unaff regs.

---

## 4. Surviving contract for AutoCore

```csharp
// Client/tools OLE DB path only — server AutoCore typically omits.
// After bindings built + rowBuf = new byte[rowSize]:
if (rowBuf == null) {
  FreeTemps();
  return unchecked((int)0x8007000E); // E_OUTOFMEMORY
}
Array.Clear(rowBuf, 0, rowSize);
int hr = CreateAccessorThenFreeBindMem(...); // FUN_00422830
Free(tempBindings);
if (hr < 0) Free(auxBuf);
Release(comIface);
return hr;
```

- Do **not** treat as network packet handler.
- Do **not** fold parent binding-size math into this unit without owning `FUN_0042139b`.

---

## 5. Residual risks

1. Ghidra function split may hide a single MSVC SEH function spanning `0042139b`–`00421732`.
2. CreateAccessor register map at this call site still inherits gaps from `aa_00422830`.
3. No runtime HRESULT trace in this dual.

**Verdict:** **accept-with-gaps** — adversarial pass does not break CF seal; naming stays inferred.
