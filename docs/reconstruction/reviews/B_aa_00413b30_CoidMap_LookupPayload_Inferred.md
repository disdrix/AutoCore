# Review B (skeptical / adversarial): `aa_00413b30` CoidMap_LookupPayload (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413b30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00413b30_CoidMap_LookupPayload_Inferred.md` |
| **Verdict** | **accept-with-gaps** on consumer role + EAX map host; hash internals Probable |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Pure two-arg cdecl with no this | Call site loads **EAX=`[window+0x570]`** | **Falsified** — map in EAX |
| 2 | Decompiler body is complete | Bytes show table index before `FUN_00419b40` | **Survives as incomplete decompile** — trust bytes + callee |
| 3 | Returns full node | Returns `*(node+0xc)` only | **Falsified as full node** |
| 4 | Many callers | Single xref `0x0085f4df` | **Survives** — Drop hit-test specialized |
| 5 | COID match is string/name | Callee compares dword pair at `+0x18/+0x1c` | **Falsified** |
| 6 | Always finds item | `-1` COID short-circuit at caller; null return | **Falsified as always** |
| 7 | Product name sealed | Inferred only | **Gap** |

---

## 2. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Drop hit-test COID→ptr | **High** | Wrong drag target item |
| EAX = map host `+0x570` | **High** | Crash / null map |
| Payload at `+0xc` | **High** | Type confusion |
| Hash bucket formula | **Probable** | Rare miss |
| Runtime | **Open** | Edge cells |

---

## 3. Surviving contract

```
// EAX = coidMap (from inventory window +0x570)
void* CoidMap_LookupPayload(uint32 coidLo, uint32 coidHi);
// null if missing; else *(node+0xc)
```

---

## 4. Open

1. English type of map / node.
2. Bit-exact hash path vs decompiler collapse.
3. Live hit-test capture.

**Verdict:** Consumer ABI **survives** attack. **accept-with-gaps.**
