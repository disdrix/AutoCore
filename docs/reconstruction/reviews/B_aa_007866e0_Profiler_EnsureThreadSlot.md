# Review B (skeptical / adversarial): `aa_007866e0` Profiler_EnsureThreadSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_007866e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007866e0_Profiler_EnsureThreadSlot.md` |
| **Verdict** | **accept-with-gaps** on CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is mission / character helper | Body: TID walk, CS, zone alloc `"Hermann"`, vector append only | **Falsified** |
| 2 | Returns zone pointer | Returns **index** used as `idx*0xC` by enter/leave | **Falsified** |
| 3 | Slot stride 4 or 8 | Size formula `(end-begin)/0xc`; walk `iVar5 += 0xc` | **Falsified** |
| 4 | No synchronization | `EnterCriticalSection(param+0x58)` / Leave on all paths | **Falsified** |
| 5 | Always creates a new zone | Hit path returns early without alloc | **Falsified** |
| 6 | Root name is scope string from caller | Hardcoded `"Hermann"` @ `0x00a9adc4` | **Falsified** |
| 7 | ECX-thiscall with zero stack args | Callers **PUSH profiler**; decompiler `int(param_1)` | **Falsified** as ECX-this |
| 8 | Create returns 0 always | Returns **post-append count − 1** | **Falsified** |
| 9 | Divisor/QPC math owned here | Only stamps start + zeros counters; QPF in timer ctor `0x00780730` | **Overstated** if claimed here |
| 10 | Bit-exact / runtime sealed | Static dual only | **Fail** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Index return + stride 0xC | **High** | Corrupt wrong slot / AV |
| CS around table | **High** | Dual-thread table tear |
| TID at entry +0 | **High** | Cross-thread zone stack |
| Hermann root on miss | **High** | Wrong hierarchy root |
| Append via `FUN_00480ca0` | **High** (role) / **Med** (pack) | Sticky empty current |
| Product English | **Low–Med** | Naming only |
| OOM null node | **Low** | Crash path unproven |

---

## 3. Cross-check vs live decompile (2026-07-29)

| Decompiler claim | Seal |
|---|---|
| Walk until `iVar4 >= size` | Matches while-true + break |
| Match `*(base + iVar5) == tid` | High |
| Create `"Hermann"` + inline timer start | High (same field list as `FUN_00785e00`) |
| `return iVar4 + -1` after append | High = new last index |
| `FUN_00480ca0()` free | **Register ABI** — vector in EAX, value parts in regs/stack; decompiler under-specified |

CF of raw ≡ live decompile. No hidden branches in pseudocode.

---

## 4. Surviving contract for AutoCore

```
// Do not port into mission CF. Index factory only.
if profiling:
  idx = EnsureThreadSlot(g_profiler)
  // use g_profiler.slots[idx] // +0 tid, +8 current zone*
```

**Falsified port mistakes:**

- Treating return as zone* or bool.
- Skipping CS on multi-thread client.
- Assuming first enter creates named scope string (creates **Hermann** root instead).

---

## 5. Open questions (residual only)

1. Exact 12-byte pack written by `FUN_00480ca0` (`+4` field).
2. Why root is named `"Hermann"`.
3. Whether slot table ever shrinks / reuses freed TIDs.
4. Behavior if `operator_new` returns null (deref of `local_14+4`).

**Verdict:** **accept-with-gaps** — thread-slot ensure sealed for enter/leave consumers; not domain logic.
