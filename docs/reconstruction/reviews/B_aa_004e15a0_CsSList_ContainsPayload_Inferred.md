# Review B (skeptical / adversarial): `aa_004e15a0` CsSList_ContainsPayload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e15a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-P) |
| **Counterpart** | `reviews/A_aa_004e15a0_CsSList_ContainsPayload_Inferred.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a host-level method taking object+queue internally | Callers load `queue = *(host+off)` into ECX then call | **Falsified** |
| 2 | Same CS policy as Append (outer only if count≤3) | Body always `lea …+0x28` Enter with no count test | **Falsified** |
| 3 | Compares node identity / vtbl, not payload | `cmp [node+4], payload` | **Falsified** |
| 4 | Singly-linked via `node+0x0C` or intrusive object next | Next load is `[node+8]` | **Falsified** |
| 5 | Returns full pointer / node* | Only AL 0/1; no pointer out | **Falsified** |
| 6 | Bare `ret` (no stack cleanup) | Both exits `c2 04 00` | **Falsified** |
| 7 | Only used by EnqueueDeferredOnce / one queue slot | QueueDelete uses `host+0xe648` (different list) | **Falsified exclusivity** |
| 8 | Auto-seed “RemoveObject chain” is product name | Structural list util; name is parent-seed | **Overstated** |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall list + ret 4 + AL bool | **High** | Wrong ABI wrappers |
| head/payload/next offsets | **High** | Misses / false hits |
| Always dual CS | **High** | Deadlock if port omits outer |
| Distinct queue slots at callers | **High** | Wrong host field |
| Product identifier spelling | **Low–Med** | Naming only |
| CS fairness vs Append gate | **Med** | Behavior residual under contention |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `53 55 8b 2d…`, ends `… b0 01 5b c2 04 00` |
| Enqueue site `004d0ea8` | **Yes** ECX=`[edi+0xe5fc]`, push obj, test AL |
| QueueDelete site `004d4840` | **Yes** ECX=`[edi+0xe648]`, push obj, test AL |
| Twin Append layout | **Yes** `aa_004024d0` sealed same fields |

**Attack on “host thiscall with embedded list”:** **Fails** — list is separate object in ECX.

**Attack on “same CS gate as Append”:** **Fails** — Contains always takes outer CS.

---

## 4. Surviving contract for AutoCore

```
// ECX = CsSList*; stack = void* payload; ret 4
// Enter CS(+0x28) then CS(+0x10)
// walk head@+4; match node.payload@+4; next@+8
// Leave +0x10 then +0x28; return AL 1 hit / 0 miss
// NO count gate; NO allocate; NO modify list
```

**Falsified port mistakes:**

- Treating as host method without loading queue into ECX.
- Applying Append’s `count≤3` outer-CS gate to Contains.
- Walking wrong next offset or comparing node address instead of payload.
- Using bare `ret` (leaks 4 B stack).

---

## 5. Open questions

1. Product/PDB symbol.  
2. Why Append gates outer CS but Contains does not.  
3. Full consumer set of each host queue slot.

**Verdict: accept** — adversarial checks reinforce sealed membership contract.
