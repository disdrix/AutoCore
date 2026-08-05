# Review B (skeptical / adversarial): `aa_004068f0` LogicUiEventQueue_InsertOne_GrowPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_004068f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W22-I) |
| **Counterpart** | `reviews/A_aa_004068f0_LogicUiEventQueue_InsertOne_GrowPath.md` |
| **Scratch** | `tmp/a_004068f0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the primary enqueue path | **Falsified** — primary is capacity-hit path via `FUN_00409cc0` in `Client_SendLogicUiPacket`; this is overflow/grow only |
| 2 | Decompiler void / unknown ABI | **Overstated** — bytes seal `RET 0xC`, ECX=this, 3 stack formals |
| 3 | Element size 0x138 is coincidence | **Falsified** — magic div, lea chain, and caller size math all use 0x138; matches Logic-UI dispatch stride |
| 4 | Function grows capacity itself | **Partial** — grow owned by callee `FUN_004076a0`; this only saves index + rebinds out pointer |
| 5 | Multiple callers | **Falsified** — exactly 1 xref (`0x00405a70`) |
| 6 | Product name `LogicUiEventQueue_*` is retail | **Overstated** — inferred from caller + stride; Ghidra still `FUN_004068f0` |
| 7 | `param_4` is full event blob by value | **Open** — only width-4 formal at ABI; construct path in `FUN_004076a0` may expand |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Index → insert-1 → rebase CF | **High** | Broken enqueue after realloc |
| Stride 0x138 | **High** | Wrong slot / corruption |
| ABI thiscall + RET 0xC | **High** | Stack smash |
| Sole caller SendLogicUiPacket | **High** | Missed xrefs |
| Callee = insert-N grow | **High** | Wrong ownership of realloc |
| Product type English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
q = ECX; out = stack0; at = stack1; val = stack2
begin = *(q+4)
index = (begin && size) ? (at-begin)/0x138 : 0
FUN_004076a0(at, 1, val)   // this=q
*out = *(q+4) + index*0x138
RET 0xC
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean plate names grow-path role without changing CF.

---

## 4. Surviving contract for AutoCore

```
// Logic-UI event queue grow-insert (not the capacity-hit fast path)
*outSlot = LogicUiEventQueue_InsertOne_GrowPath(queue, insertAt, payload)
// after return, insertAt iterators are invalid; use *outSlot
// element size MUST remain 0x138
// do not call when capacity remains (fast path uses FUN_00409cc0 + end+=0x138)
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/stride sealed; naming is evidence-backed inference; residual is layout English only → **accept**.
