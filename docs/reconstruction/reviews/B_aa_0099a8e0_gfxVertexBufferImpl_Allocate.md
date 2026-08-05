# Review B (skeptical / adversarial): `aa_0099a8e0` gfxVertexBufferImpl_Allocate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099a8e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-L) |
| **Counterpart** | `reviews/A_aa_0099a8e0_gfxVertexBufferImpl_Allocate.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the VB **constructor** / pool pop | **Falsified** — ctor is `FUN_00999960`; pool is `FUN_00414cd0` in parent |
| 2 | Decompiler `void` / zero-arg signature is complete | **Falsified** — bytes force **`ret 0x10`** and four stack loads |
| 3 | Fail returns device HR unchanged | **Falsified** — fail forces **`or eax,-1`** after log |
| 4 | Always updates stats | **Falsified** — stats only if `DAT_00d1f614 != 0` |
| 5 | Callback is thiscall on the VB | **Falsified** — ECX=callback, this pushed as stack arg |
| 6 | Many mesh call sites call this VA directly | **Falsified** — only 2 Ghidra callers; mesh sites call **holder** `00414c20` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Allocate-not-construct role | **High** | Double-ctor / wrong freelist |
| Fail → −1 + plate | **High** | Miss error path in ports |
| Field offsets | **High** | Corrupt VB layout |
| Device call = full D3D Create | Medium | `FUN_00986a60` may wrap more than CreateVB |
| Arg English labels | Medium | Misnamed formals in docs only |

---

## 3. Cross-check against raw + bytes

```
push callees / mov edi,ecx
call FUN_0099a820
store [edi+0x18],[edi+0x1c]
call FUN_00447ea0
copy format → [edi+0x34],[edi+0x38]
call FUN_00986a60
jl fail → clear + log + eax=-1 + ret 0x10
else optional callback; stats; ret 0x10
```

Clean must **not** invent D3D CreateVertexBuffer parameters beyond what this unit stores/forwards. Device details live in `FUN_00986a60` (out of owned scope).

---

## 4. Surviving contract for AutoCore

```csharp
// Port sketch — client graphics only
int gfxVertexBufferImpl_Allocate(VbImpl self, uint count, FormatDesc fmt,
                                 uint strideOrUsage, object callback)
{
    FreePrior(self);
    self.Count = count;
    self.Callback = callback;
    InitSub(self);
    self.FmtA = fmt.Field10; self.FmtB = fmt.Field14;
    int st = DeviceAllocate(g_device, self, strideOrUsage, fmt);
    if (st < 0) {
        ClearFields(self);
        CleanupSub(self);
        Log("gfxVertexBufferImpl.cpp", 0x66, 3, "Failed to Allocate Vertex Buffer");
        return -1;
    }
    if (callback != null) st = callback.Invoke(self);
    if (g_stats != null) g_stats.Account(self);
    return st;
}
// Server AutoCore typically omits this path unless hosting client-parity mesh tooling.
```

---

## 5. Open questions

1. Exact product type of `formatDesc` / callback.
2. Whether server needs any equivalent of `DAT_00d1f614` budget accounting.

**Verdict:** **accept**
