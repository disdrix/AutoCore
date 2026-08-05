# Review A (reconstruction fidelity): `aa_00421362` OleDb_AllocBindingsBuf_EnterBuild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421362` |
| **VA** | `0x00421362`–`0x00421391` |
| **Canonical name** | `OleDb_AllocBindingsBuf_EnterBuild_Inferred` |
| **Ghidra name** | `FUN_00421362` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-F) |
| **Counterpart** | `reviews/B_aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md` |
| **System** | COM / OLE DB accessor setup |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; sibling duals `aa_0042139b` / `aa_00421677`; parent `FUN_00421240` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

After parent allocates a temp binding-record buffer (`colCount * 0x34`), gate on that pointer: null → **E_OUTOFMEMORY** with COM Release; else SEH=4, allocate `colCount` bytes into **`ctx+0x10`**, and **jmp** into the binding-build fragment (`FUN_0042139b`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00421362_FUN_00421362.md` (+ W24-F append) |
| Annotated | `docs/reconstruction/raw/aa_00421362_FUN_00421362.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/OleDb_AllocBindingsBuf_EnterBuild_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00421362.cpp` |
| Function record | `docs/reconstruction/functions/aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md` |
| Related dual | `reviews/A_aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md` |
| Live | `decompile_function` `0x00421362`; `read_memory` pre/entry/success; `get_function_by_address`; parent `0x00421240` |

---

## 3. Signature

```c
// Ghidra: undefined4 FUN_00421362(void) with unaff_EBX=ctx*, unaff_EBP=parent frame
// Bytes:  pre-entry 0x0042135f mov ebx,[ebp+8]
// Success: jmp 0x0042139b → build → finalize → ret 4
// Fail: shared epilogue ret 4, EAX = 0x8007000E
```

| Item | Evidence | Conf |
|---|---|---|
| Shared EBP/SEH | `[ebp-4]/[ebp-0x1c]/[ebp-0x18]/[ebp-0xc]` | **High** |
| EBX = ctx | pre-entry `8B 5D 08`; `[ebx+0xc]/[ebx+0x10]` | **High** |
| Success is jmp-into-build | `EB 09` → `0x0042139b` | **High** |
| HRESULT E_OUTOFMEMORY | decompile `0x8007000e`; sibling seal | **High** |

---

## 4. Control flow (sealed from bytes + decompile)

```
SEH=0
if [ebp-0x1c] == null:
  SEH=-1; optional Release([ebp-0x18]); restore ExceptionList; return E_OUTOFMEMORY
SEH=4
[ebx+0x10] = operator_new[]([ebx+0xc])
jmp FUN_0042139b
```

| Stage | Match | Conf |
|---|---|---|
| SEH=0 then branch on temp | **Yes** (`C7 45 FC 00…` / `75 0E`) | **High** |
| Fail SEH=-1 + jmp shared | **Yes** (`C7 45 FC FF…` / `EB 40`) | **High** |
| Success SEH=4 | **Yes** (`C6 45 FC 04`) | **High** |
| new[] size from +0xc → store +0x10 | **Yes** | **High** |
| jmp into 0042139b | **Yes** (`EB 09`) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x0042135f` | `8B 5D 08` | `mov ebx,[ebp+8]` |
| `0x00421362` | `83 7D E4 00` | `cmp [ebp-0x1c],0` |
| `0x0042137d` | `C6 45 FC 04 … 89 43 10 EB 09` | SEH=4; store; jmp build |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA |
|---|---|
| `FUN_00421240` | `0x00421240` |

Xrefs: **1**.

| Callee | VA / note |
|---|---|
| `operator_new[]` | CRT |
| `FUN_0042139b` | continuation (dual sealed); **jmp** not call |

---

## 7. Confidence

| Claim | Level |
|---|---|
| CF / SEH / jmp-build / E_OUTOFMEMORY | **High** |
| Role as OLE DB alloc gate before binding build | **High** |
| Product type / formal English | **Probable / Inferred** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product class name for ctx.
2. Whether Ghidra should merge `00421362`+`0042139b`+`00421677`.
3. Exact English for `ctx+0x10` buffer contents.
4. Live HRESULT under real OLE DB load.

**Verdict:** **accept-with-gaps** — image CF, SEH, alloc, and tail-join sealed; product naming remains inferred.
