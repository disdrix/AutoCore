# Review A (reconstruction fidelity): `aa_00968a50` GfxBufferedView_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968a50` |
| **VA** | `0x00968a50`–`0x00968b14` (**197 B**) |
| **Canonical name** | `GfxBufferedView_Ctor_Inferred` (was `FUN_00968a50`) |
| **Review date** | `2026-08-04` (W37-I) |
| **Reviewer role** | Reconstruction fidelity (gfxBufferedView complete ctor) |
| **Counterpart** | `reviews/B_aa_00968a50_GfxBufferedView_Ctor_Inferred.md` |
| **System** | palantir/graphics — gfxBufferedView |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + `get_assembly_context` (callers). Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: GfxView_Ctor W31-O, StdList_Incsize W23-E, vtbl-adjacent plates, unowned timer helpers.

---

## 1. Purpose

**Complete constructor** for product class **gfxBufferedView** on a pre-allocated **0x198** block.

Flow:

1. SEH frame; `ESI = ECX` (this).
2. `GfxView_Ctor_Inferred` (`FUN_0075ceb0`) — base **0x150**.
3. Derived vtbl `*this = PTR_FUN_00aa22a8`.
4. Timer at `this+0x150`: `FUN_0076c500(timer, 1000)` then flags `+0x180/+0x184 = 1`, then `FUN_0076c4d0(timer)`.
5. Zero derived tail: floats `+0x188/+0x18c`, bytes `+0x190/+0x191`, dword `+0x194`.
6. `std::list` insert of `this` via `FUN_006759b0` + `StdList_Incsize(1, list@0x00d1ee2c)` + link.
7. Return this.

Does **not** allocate memory, set near/far, or bind FX (callers do that after return).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00968a50_FUN_00968a50.md` (+ W37-I append) |
| Annotated | `docs/reconstruction/raw/aa_00968a50_FUN_00968a50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBufferedView_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00968a50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00968a50_FUN_00968a50.md` |
| Named record | `docs/reconstruction/functions/aa_00968a50_GfxBufferedView_Ctor_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; body `00968a50`–`00968b14`; full 197 B hex |
| Product plates | vtbl-adjacent `gfxBufferedView.cpp` + render-target string |
| Callers | 4× `new(0x198); MOV ECX,eax; CALL` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, writes to unowned VAs.

---

## 3. Signature

```c
// __fastcall / thiscall-style: ECX = this; returns this; plain RET after ADD ESP,0x14
GfxBufferedView * __fastcall GfxBufferedView_Ctor_Inferred(GfxBufferedView *self);
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX` at entry; return `MOV EAX,ESI` |
| Size | All callers `operator_new(0x198)` |
| Callees | `0075ceb0`, `0076c500`, `0076c4d0`, `006759b0`, `0043fe60` |
| Body range | Entry `00968a50`, last insn `00968b14` (`C3`) |
| Xrefs | **4** call sites / **4** caller functions |

---

## 4. Control flow (sealed)

```
SEH + ESI=this
GfxView_Ctor(this)
*this = PTR_FUN_00aa22a8
EDI = this+0x150
Timer_Init(EDI, 1000)
*(this+0x180)=1; *(this+0x184)=1
Timer_Start(EDI)
float zeros +0x188/+0x18c; byte zeros +0x190/+0x191; dword zero +0x194
node = new list node(head, head->next, this)
StdList_Incsize(1, 0x00d1ee2c)
link node after head
return this
```

---

## 5. Gaps (explicit)

- Product English for timer period / `+0x180/+0x184` flags.
- Full derived field map beyond ctor.
- Global list membership semantics.
- Runtime / bit-exact / differential.

---

## 6. Verdict rationale

**accept-with-gaps:** Class identity, ABI, size, CF, list registration, and layout zeros are sealed from decompile+bytes+callers+plates. Nested timer/list helper product English and residual field names remain open — not blocking the ctor contract.
