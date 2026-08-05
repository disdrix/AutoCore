# Review B (skeptical / adversarial): `aa_0042139b` OleDb_BuildBindingsAllocRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042139b` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | True standalone `void` / no args | Fail epilogue **`ret 4`**; pre-entry `mov ebx,[ebp+8]` | **Falsified** pure-void — **1 stack formal** / shared frame |
| 2 | Decompiler `return -0x7ff8fff2` is opaque | Bytes `B8 0E 00 07 80` = `0x8007000E` | **Confirmed** = **E_OUTOFMEMORY** |
| 3 | Unit is mission/net/gameplay logic | Sole caller is OLE parent alloc; continuation is CreateAccessor dual | **Reject** gameplay — **OLE DB binding build** |
| 4 | Success `call FUN_00421677` then return | Bytes: `EB 09` jmp over SEH filter to `0x00421674` | **Over-narrow decompiler call** — **jmp continuation** |
| 5 | Binding stride is 0x30 only | Binding cursor `+0x34` (13 dwords); col side `+0x30` | **Both strides sealed** |
| 6 | Name without `_Inferred` is product-proven | No RTTI/string for this VA | **Needs `_Inferred`** |
| 7 | Runtime verified | No live DB capture this dual | **Open** |
| 8 | `FUN_00422880` success sets flag on null `*ctx` literally | Decomp writes `*(*ctx)+4=1` after call that started with `*ctx==0` | **Residual** — likely call fills `*ctx`; out of OWN for callee |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| E_OUTOFMEMORY on null +0x10 | **High** | Wrong OOM port |
| DBTYPE size map cases | **High** | Wrong row layout / buffer size |
| Binding 0x34 / col 0x30 strides | **High** | Binding table overrun |
| jmp into finalize (not portable call) | **High** | Broken port wrapper / double ret |
| ret 4 / shared frame | **High** | Stack smash |
| Product names for formals | **Medium** | Doc-only |
| FUN_00422880 post-condition | **Low–Medium** | Mis-order gate flag |

---

## 3. Cross-check against raw + bytes

```
raw decompile:
  if (EBX[4]==0) cleanup; return -0x7ff8fff2
  for columns: DBTYPE switch; fill bindings; accumulate [ebp-0x24]
  if (*EBX==0) hr=FUN_00422880; fail cleanup
  rowBuf = new[]([ebp-0x24]); FUN_00421677()

bytes:
  test [ebx+0x10]; mov eax,0x8007000E; ret 4
  jumptable DBTYPE; add ecx,0x34; add esi,0x30
  call new[]; mov [ebx+8],eax; jmp 0x00421674
```

Clean named plate must document **jmp continuation** and shared EBP. Scaffold clean may keep unaff regs.

---

## 4. Surviving contract for AutoCore

```csharp
// Client/tools OLE DB path only — server AutoCore typically omits.
// After parent allocates aux/status (ctx+0x10) and temp bindings:
if (ctx.auxOrStatus == null) {
  Free(tempBindings);
  return unchecked((int)0x8007000E); // E_OUTOFMEMORY
}
// For each column: map DBTYPE → size; write binding record (0x34 stride);
// accumulate rowSize with align from FUN_00422900.
// Optional FUN_00422880 when gateObj null.
ctx.rowBuf = new byte[rowSize];
// Fall into zero-fill + CreateAccessor finalize (FUN_00421677) — same stack frame.
return FinalizeCreateAccessor(...);
```

- Do **not** treat as network packet handler.
- Do **not** invent a second `ret 4` after a portable call to finalize — image uses **jmp**.
- Do **not** invent product class names without RTTI/strings.

---

## 5. Residual risks

1. Ghidra SEH split across `00421362` / `0042139b` / `00421677` may hide one MSVC function.
2. `FUN_00422880` / `FUN_00422900` semantics not OWN.
3. Binding field English (ordinal/obValue/dwPart) Probable from OLE DB shape, not string-proven.
4. No runtime HRESULT trace in this dual.

**Verdict:** **accept-with-gaps** — adversarial pass does not break CF seal; naming stays inferred.
