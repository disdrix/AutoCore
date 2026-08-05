# Review B (skeptical / adversarial): `aa_00414c20` GfxVBHolder_ReplaceAndAllocate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00414c20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-L) |
| **Counterpart** | `reviews/A_aa_00414c20_GfxVBHolder_ReplaceAndAllocate.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is only a refcount AddRef/Release helper | **Falsified** — always ends in `FUN_0099a8e0` allocate |
| 2 | Pool uses holder as freelist | **Falsified** — bytes load imm `0x00d218e0` into ECX before `00414cd0` |
| 3 | Decompiler signature `void(void)` is complete | **Falsified** — `ret 0x10`, 4 stack args, EAX status |
| 4 | Function creates index buffers not vertex buffers | **Falsified** — allocate plate is `gfxVertexBufferImpl.cpp` |
| 5 | Clean invents GPU API calls (CreateVertexBuffer D3D) | **Falsified** — clean stops at sealed callees; no invented D3D |
| 6 | Returns the new VB pointer | **Falsified** — returns allocate status; VB left at `holder+4` |
| 7 | `FUN_00999960` is not a ctor | **Falsified** — zeros fields, writes vtbl `00aa161c` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slot offset +4 | **High** | Wrong object layout on port |
| Refcount protocol | **High** | Leaks / double-free |
| Allocate callee identity | **High** | Miss VB failure path (`"Failed to Allocate Vertex Buffer"`) |
| Stack formal meanings | Medium | Wrong stride/count when rehosting mesh builders |
| Null-new then allocate | Medium | Need parent null checks (terrain checks `<0`) |

---

## 3. Cross-check against raw + bytes

```
SEH → pop(DAT_00d218e0) → ctor? → addref/first-vfunc → release old(+4)
    → holder+4 = new → FUN_0099a8e0(args) → ret 0x10 (EAX status)
```

Clean must **not** invent D3D9 CreateVertexBuffer, map/lock, or index-buffer paths.

Do **not** treat decompiler `void` as authoritative for return.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client graphics only; server may omit)
int GfxVBHolder_ReplaceAndAllocate(Holder holder, int count, object format, int stride, int flags)
{
    var neu = PoolPopAndConstructVb(); // may be null
    AddRefFirst(neu);
    Release(holder.VbAtPlus4);
    holder.VbAtPlus4 = neu;
    return GfxVertexBufferImpl_Allocate(neu, count, format, stride, flags);
}
// Callers: if (status < 0) fail mesh build.
```

---

## 5. Open questions

1. Exact C++ class name of holder vs `gfxVertexBufferImpl`.
2. Whether AutoCore server needs this path (client render-only likely).

**Verdict:** **accept**
