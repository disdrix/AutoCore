# Review B (skeptical / adversarial): `aa_004076a0` LogicUiEventQueue_InsertN

| Field | Value |
|---|---|
| **Stable ID** | `aa_004076a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-B) |
| **Counterpart** | `reviews/A_aa_004076a0_LogicUiEventQueue_InsertN.md` |
| **Scratch** | `tmp/a_004076a0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a one-element insert | **Falsified** — `param_3` is general count; parent passes 1, but `FUN_00406840` passes `n−size` |
| 2 | Element size is 4 / dword vector | **Falsified** — magic `/0x138`, alloc `*0x138`, local 312 B, parent dual sealed 0x138 |
| 3 | Decompiler void / wrong ABI | **Overstated** — bytes seal `RET 0xC`, ECX=this, 3 stack formals on every exit |
| 4 | Grows always | **Falsified** — three paths: realloc, near-end in-place, mid in-place |
| 5 | Max size is unlimited | **Falsified** — compare vs `0x00D20D20` then `FUN_00418130` |
| 6 | Product name is retail | **Overstated** — inferred from SendLogicUiPacket chain + stride; Ghidra still `FUN_004076a0` |
| 7 | Nested helpers fully typed in this unit | **Open by design** — residual; CF uses them as black boxes with sealed arg order |
| 8 | `operator_delete` is noreturn (decomp warning) | **Decomp artifact** — MSVC EH path; normal path rebinds after delete |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-N CF (3 paths) | **High** | Buffer corruption |
| Stride 0x138 | **High** | Wrong slot / OOB |
| ABI thiscall + RET 0xC | **High** | Stack smash |
| 1.5× + exact grow | **High** | Capacity bugs |
| Callers (2 xrefs) | **High** | Missed edge |
| Product type English | **Medium** | Naming only |
| Nested helper internals | **Open** | Port of helpers |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
construct 0x138 → valueBuf
if count==0 return
size/cap /0x138; max 0x00D20D20
if need grow: 1.5x or exact; new; move+fill+move; delete; rebind
else if tail < count: near-end path
else: mid path
RET 0xC
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean plates name role without changing CF.

---

## 4. Surviving contract for AutoCore

```
// Logic-UI event queue insert-N (not the capacity-hit fast path FUN_00409cc0)
LogicUiEventQueue_InsertN(queue, insertAt, count, valueSrc)
// element size MUST remain 0x138
// after grow, all iterators into the buffer are invalid
// InsertOne wrapper (004068f0) saves index then rebinds out-slot after this returns
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/stride/growth; residuals are product English + nested helpers + runtime → **accept-with-gaps**.
