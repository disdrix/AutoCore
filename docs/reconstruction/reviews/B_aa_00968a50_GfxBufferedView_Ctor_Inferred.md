# Review B (skeptical / adversarial): `aa_00968a50` GfxBufferedView_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968a50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-I) |
| **Counterpart** | `reviews/A_aa_00968a50_GfxBufferedView_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ caller assembly context + vtbl plates). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Plain GfxView ctor (size 0x150) | Callers `new(0x198)`; derived vtbl; fields past 0x150 | **Falsified** — **extended** GfxView / gfxBufferedView |
| 2 | Stack formals / stdcall RET N | Epilogue `ADD ESP,0x14; RET`; callers only set ECX | **Falsified** — ECX this, plain RET |
| 3 | `FUN_0076c500` runs on whole object | Bytes `LEA EDI,[ESI+0x150]; MOV ECX,EDI` | **Falsified** — timer at **`+0x150`** |
| 4 | `+0x188/+0x18c` are integer zeros | `XORPS` + `MOVSS` | **Clarify** — **float** zeros (same bits) |
| 5 | Scaffold NDRiver callee-of name is product role | Plates are gfxBufferedView.cpp; multi-domain callers | **Over-narrow** — **reject** scaffold |
| 6 | Allocates itself | No `operator_new` in body | **Falsified** — complete ctor on pre-alloc |
| 7 | List insert is optional | Always builds node + Incsize + link | **Falsified** — always registers |
| 8 | Same as Palantir env 0x198 ctor `00492dd0` | Different callees/vtbl/list | **Falsified** — distinct type |
| 9 | Decompiler void/undefined signature | Returns ESI/this; 4 callers use EAX | **No** — return this sealed |
| 10 | Class name only Inferred | Path + strings at vtbl neighborhood | **Strengthen** — class product-sealed; method English Inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + return this | **High** | Ports pass stack this → crash |
| Size 0x198 | **High** | Truncate base/timer/tail |
| Derived vtbl `00aa22a8` | **High** | Wrong virtuals / dtor |
| Timer at `+0x150` period 1000 | **High** | Mis-init subobject |
| List registration always | **High** | Miss global iteration |
| gfxBufferedView class name | **High** | Doc only if path disputed |
| Timer/flag product English | **Low** | Wrong port comments only |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  GfxView_Ctor(); *this = vtbl; Timer(1000); flags; zeros; list insert; return this

bytes refine:
  EDI = this+0x150 for both timer calls
  MOVSS float zeros at +0x188/+0x18c
  Incsize ECX=1, EDX=0x00d1ee2c
  epilogue ADD ESP,0x14; RET; pad CC
```

Clean must **not** invent:

- `operator_new` inside ctor
- near/far/FX bind (caller responsibility)
- Palantir-env 0x198 layout from W31-P
- Skipping list insert
- Stack `this` parameter

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x00968a50
// pre-allocated 0x198 block; ECX = this
static GfxBufferedView GfxBufferedView_Ctor(GfxBufferedView self)
{
    GfxView_Ctor(self);                 // 0x0075ceb0
    self.Vtbl = GfxBufferedView_Vtbl; // PTR_FUN_00aa22a8
    Timer_Init(self + 0x150, 1000);
    WriteU32(self + 0x180, 1);
    WriteU32(self + 0x184, 1);
    Timer_Start(self + 0x150);
    WriteF32(self + 0x188, 0);
    WriteF32(self + 0x18c, 0);
    WriteU8(self + 0x190, 0);
    WriteU8(self + 0x191, 0);
    WriteU32(self + 0x194, 0);
    ListPushFrontPayload(g_BufferedViewList, self); // DAT_00d1ee30 family
    return self;
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks strengthen (not weaken) the ctor contract; residual gaps are product English / nested helpers, not ABI/CF.
