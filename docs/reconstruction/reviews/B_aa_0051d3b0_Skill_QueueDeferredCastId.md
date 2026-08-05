# Review B (skeptical / adversarial): `aa_0051d3b0` Skill_QueueDeferredCastId

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d3b0` |
| **VA** | `0x0051d3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (full dual residual; prior 2026-07-23 scaffold) |
| **Counterpart** | `reviews/A_aa_0051d3b0_Skill_QueueDeferredCastId.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Executes / validates cast now | Body only map/block/store/size++ | **Falsified** |
| 2 | `this` is outer character/skill owner | Caller moves **slot** into ECX after `FUN_005169c0` | **Falsified** (outer is wrong) |
| 3 | Unbounded always-grow | Grow only when block boundary **and** mapsize ≤ (size+4)>>2 | **Falsified** (gated) |
| 4 | `(size+4U)>>2` is `size+(4>>2)` i.e. size+1 | Pcode: `INT_ADD size,4` then `INT_RIGHT 2`; asm `ADD EAX,4; SHR EAX,2` | **Falsified** — it is **(size+4)>>2** |
| 5 | Element is a struct / multi-dword | Single dword store from `*param_2` | **Falsified** (width=4) |
| 6 | Ring of fixed capacity only (no alloc) | `operator_new(0x10)` per empty map slot + map grow helper | **Falsified** |
| 7 | Multiple independent callers | Xrefs: only ClearActiveCastCounter | **Confirmed** sole caller |
| 8 | +0x10 is *only* “refcount” unrelated to queue | Same field is deque **size**; LocalCastValidate treats ≠0 as busy | **Reconciled** — shared field; dual role is real |
| 9 | `FUN_0051c3b0` is random “helper” | Overflow path throws **`"deque<T> too long"`** via `FUN_0051b5f0` | **STL deque map grow** (High) |
| 10 | Clean invents behavior beyond raw | Clean ≡ raw CF; prior scaffold spacing only | **No invention** |
| 11 | Null block store always safe | If `operator_new` returns 0, map[block]=0 then elem derived null → skip store but still size++ | **Risk sealed as gap** (OOM) |
| 12 | Ghidra signature `void()` | Asm `RET 4` + stack `pSkillId` | **Ghidra incomplete**; sealed thiscall+1 arg |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX=slot, `*pId`, RET 4 | **Confirmed** | Wrong AutoCore port / stack smash |
| Map/off/size layout +4/+8/+0xC/+0x10 | **Confirmed** | OOB write on port |
| Grow predicate | **Confirmed** | Map overflow / missed grow |
| 4-dword blocks | **Confirmed** | Wrong stride |
| Payload = skill id dword | **High** | Wrong deferred identity |
| Exact `std::deque<uint32_t>` product type | **High layout / Open name** | Naming only |
| OOM path (new fails) | **Tentative** | size++ without store |
| Interaction with Clear size-- | Out of unit (Clear dual) | Net size semantics |

---

## 3. Cross-check against raw + memory

Raw decompile (2026-07-23) matches live re-decompile (2026-07-29).

`read_memory` @ `0x0051d3b0` (120 B) closes:

```
PUSH ESI / MOV ESI,ECX
… TEST CL,3 / JNZ skip_grow
ADD EAX,4 / SHR EAX,2 / CMP [ESI+8],EAX / JA skip
PUSH 1 / MOV ECX,ESI / CALL FUN_0051c3b0
… block wrap … PUSH 0x10 / CALL operator_new …
TEST EAX / JZ skip_store / *elem=*pId
ADD [ESI+0x10],1 / POP ESI / RET 4
```

Operator-precedence trap in C rendering of raw (`a + 4U >> 2`) is **(a+4)>>2**, not `a+1` — sealed by asm/pcode.

---

## 4. Surviving contract for AutoCore

```text
// pSlot = FUN_005169c0(owner)  // 0x14 block @ owner+0x64
Skill_QueueDeferredCastId(pSlot, &skillId);

// Emulates MSVC deque-like push_back of one uint32:
//   map[+4], mapsize[+8], off[+0xC], size[+0x10]
//   block bytes 0x10 (4 elements)
// Does NOT cast, send packets, or touch outer owner fields.
// Pair: ClearActiveCastCounterAndQueueId always queues after optional size--.
// Busy: LocalCastValidate reads same +0x10 ≠ 0 → eSkillResponses 6.
```

---

## 5. Open questions

1. Seal product typename (deque vs hand-rolled twin).
2. Who **pops** front / drains the ring (consumer not this VA).
3. OOM: size++ without write — intentional?
4. Runtime verification of grow thresholds.

**Verdict:** **accept-with-gaps** — adversarial pass does not break CF/ABI/layout; product STL name + drain path + OOM remain open.
