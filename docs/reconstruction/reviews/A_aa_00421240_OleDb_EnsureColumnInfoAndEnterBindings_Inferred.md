# Review A (reconstruction fidelity): `aa_00421240` OleDb_EnsureColumnInfoAndEnterBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421240` |
| **VA** | `0x00421240`–`0x00421358` |
| **Canonical name** | `OleDb_EnsureColumnInfoAndEnterBindings_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OLE DB setup parent) |
| **Counterpart** | `reviews/B_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` |
| **System** | COM / OLE DB accessor setup |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` `0x00421240` + `read_memory` (body tail + IID blobs) + `analyze_function_complete` + bulk xrefs on IIDs. No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

Parent of the sealed OLE DB binding-build chain: obtain **IAccessor**, ensure **column info**, allocate temporary **DBBINDING[colCount]**, enter `OleDb_AllocBindingsBuf_EnterBuild_Inferred`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00421240_FUN_00421240.md` (+ W25-C) |
| Annotated | `docs/reconstruction/raw/aa_00421240_FUN_00421240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_EnsureColumnInfoAndEnterBindings_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` |
| Child seals | `aa_00421362`, `aa_0042139b`, `aa_00421677` |
| IID memory | `read_memory` @ `00a860ac`, `00a85ffc` |
| Live Ghidra | decompile + bounds + callees |

---

## 3. Signature

```c
HRESULT __thiscall OleDb_EnsureColumnInfoAndEnterBindings_Inferred(
    IUnknown *source, OleDbAccessorBuildCtx *ctx);
// fail: ret 4; success: jmp 0x00421362
```

| Item | Evidence |
|---|---|
| IID_IAccessor | GUID bytes @ `DAT_00a860ac`; shared with create/release duals |
| IID_IColumnsInfo | GUID bytes @ `DAT_00a85ffc` |
| GetColumnInfo slot | call `[vtbl+0x0C]` with three out ptrs at ctx+0x0C/14/18 |
| Binding stride | lea/sub/add chain ⇒ `colCount * 0x34` |
| Tail | `EB 09` → `0x00421362` |

---

## 4. Control flow (sealed)

```
QI IAccessor
if fail → Release? ret hr
if ctx.colInfo:
  flag=1 → ALLOC
else:
  QI IColumnsInfo; GetColumnInfo; on ok flag=0 → ALLOC
  on fail Release both; ret hr
ALLOC:
  SEH=2; temp = new[](colCount*0x34); jmp 00421362
```

---

## 5. Confidence

| Claim | Level |
|---|---|
| QI / GetColumnInfo CF | **High** |
| IID identities | **High** |
| `* 0x34` DBBINDING temp | **High** |
| jmp into `00421362` | **High** |
| ctx offset roles | **High** |
| Product English / callers | **Open** |
| Runtime / bit-exact | **Open** |

---

## 6. Gaps (do not block structural seal)

1. **0 Ghidra callers** — residual call-surface gap.
2. Product/PDB names for ctx and owner.
3. Later free of GetColumnInfo buffers when flag==0.
4. Runtime verification.

**Verdict: accept-with-gaps.**
