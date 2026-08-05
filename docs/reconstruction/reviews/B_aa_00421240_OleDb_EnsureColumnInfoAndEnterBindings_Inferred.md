# Review B (skeptical / adversarial): `aa_00421240` OleDb_EnsureColumnInfoAndEnterBindings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | IIDs are custom game GUIDs | Bytes match public OLE DB IAccessor / IColumnsInfo | **Falsified** — standard OLE DB |
| 2 | Success **calls** FUN_00421362 then returns | Tail is `EB 09` jmp; shared SEH frame | **Falsified** — pure join |
| 3 | Always GetColumnInfo | `cmp [ebx+0x14],0` fast path skips | **Confirmed** optional |
| 4 | `0x34` is DBCOLUMNINFO size | 0x34 = 52 = classic x86 **DBBINDING**; child builds bindings into temp | **DBBINDING sealed by role** |
| 5 | `param_1` is ctx | thiscall ECX used as QI target; ctx is stack `param_2`/`ebx` | **source = this; ctx = stack** |
| 6 | Dead / unused function | Child `aa_00421362` documents sole parent; IID xrefs include `0042126f` | **Live parent of sealed chain**; caller catalog open |
| 7 | Name is PDB symbol | Role-inferred | **Accept as Inferred** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| QI + optional GetColumnInfo | **High** | Wrong interface / null columns |
| Binding temp stride 0x34 | **High** | Buffer overrun in child |
| Tail jmp shared frame | **High** | Broken SEH / lost pAcc |
| Direct callers | **Low/Open** | Integration map incomplete |
| Product English | **Medium** | Doc only |

---

## 3. Cross-check against raw / bytes / children

```
raw:   QI IAccessor; maybe GetColumnInfo; new[](n*0x34); enter 00421362
bytes: IID blobs; lea*0x34; EB 09 → 00421362
child: expects [ebp-0x1C] temp bindings; [ebp-0x18] COM iface; EBX=ctx
```

Clean must keep IAccessor live across join; must not invent CALL+discard of child; must not treat `*0x34` as row size for row buffer (that's later).

---

## 4. Surviving contract for AutoCore

```csharp
// Client DB load path (conceptual)
HRESULT EnsureColumnsAndEnterBindings(IUnknown source, AccessorBuildCtx ctx)
{
    var acc = source.QueryInterface<IAccessor>(); // may stay for CreateAccessor
    if (ctx.ColumnInfo == null) {
        var cols = source.QueryInterface<IColumnsInfo>();
        cols.GetColumnInfo(out ctx.ColCount, out ctx.ColumnInfo, out ctx.Strings);
        ctx.ColumnsPreSupplied = false;
    } else {
        ctx.ColumnsPreSupplied = true;
    }
    var tempBindings = new byte[ctx.ColCount * 0x34]; // DBBINDING[]
    return AllocBindingsBuf_EnterBuild(ctx, tempBindings, acc); // shared continue
}
```

**Port traps to reject:**

- Implementing success as independent call that returns without shared state.
- Skipping IAccessor QI because CreateAccessor is “later”.
- Using 0x34 as something other than per-column binding record size.
- Assuming Ghidra-empty callers means dead code (chain is live from child).

---

## 5. Residual gaps (do not block structural seal)

1. Enumerate real call sites (data/indirect).
2. Product names.
3. Full buffer free policy for GetColumnInfo outputs.
4. Runtime / bit-exact.

---

## Verdict

**accept-with-gaps** — OLE DB setup CF, IIDs, binding stride, and tail-join are solid. Gaps are caller catalog and product English, not core control flow.
