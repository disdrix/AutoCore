# Review B (skeptical / adversarial): `aa_0075dba0` NDResourceCache_LookupOrCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dba0` |
| **VA** | `0x0075dba0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0075dba0_NDResourceCache_LookupOrCreate.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callee/caller context (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** several scaffold myths |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Thiscall / `this` in ECX is the cache | **Falsified** — first formal is stack arg; ESI loads `[esp+0x58]`; **`ret 0x14`** (5 stack args). Callers push cache explicitly (`push [DAT_00d1f050]`). |
| 2 | Always creates a new resource | **Falsified** — early return of existing `res` when type matches and hit policy allows. |
| 3 | Always allocates on miss | **Falsified** — `param5 == 1` returns **NULL** after factory loop without `operator_new`. |
| 4 | `param5` is a bool create-if-missing where any non-zero creates | **Falsified** — machine is **`cmp …, 1` / `jne do_new`**: only exact **1** blocks default create; **0** (and other ≠1) allocate. |
| 5 | `param4` always required for a hit | **Falsified** — when **`res+0x14 == 0`**, hit returns **regardless of param4** (decompiler’s dual null/non-null arms are **same** epilogue). |
| 6 | `param4` ignored always | **Falsified** — when **`res+0x14 != 0`**, NULL param4 **falls through** (does not accept hit); non-null must pass **vtbl+0x08**. |
| 7 | Type stored at resource vtbl / `+0x00` | **Falsified** — compare is **`[ebx+0x0c]`** vs type formal. |
| 8 | Default size is arbitrary / 0x40 | **Falsified** — **`push 0x3c`** before `operator_new`. |
| 9 | Function is thiscall because Ghidra sometimes shows ECX | **Overstated** — decompiler may invent register noise on callees; **this** unit’s own epilogue is definitive stdcall. |
| 10 | `cache+0x6c` is “debug only, no CF effect” | **Falsified** — gates real calls (`00971480`, `00970c00`, log trio); can return early via alternate provider. |
| 11 | Scaffold “returns existing when type matches” alone | **Incomplete** — omit predicate/`+0x14` gate and `param5==1` null path → wrong port. |
| 12 | Only one caller | **Falsified** — ≥13 unconditional call xrefs. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall 5 args `ret 0x14` | **High** | Stack imbalance / wrong wrapper |
| Hit: type `@+0x0c` | **High** | Wrong resource sharing across types |
| Hit: `+0x14==0` unconditional | **High** | Force predicate when none needed |
| Hit: `+0x14!=0` needs param4 vtbl+8 | **High** | Return wrong shared resource |
| `param5==1` → null, not create | **High** | Spurious default objects / silent NULL |
| Default `0x3c` + `PTR_FUN_00a9e850` | **High** | Layout/vtable mismatch |
| `cache+0x6c` branch exists | **High** | Miss alternate load path |
| Factory loop + list cleanup | **High** (existence); layout **Open** | Leak or wrong factory order |
| Key type / string ownership | **Open** | UAF / wrong map key |
| Semantic name of param4 | **Probable** | Misnamed “filter” vs “owner” |

---

## 3. Cross-check against raw / machine

```
// __stdcall ret 0x14
NDResource* NDResourceCache_LookupOrCreate(
    Cache* cache, KeyObj* key, TypeToken type,
    Predicate* pred /*opt*/, int noDefaultCreate /* 1 = no new */)
{
  // map find by key
  if (hit && res->type_at_0x0c == type) {
    if (res->field_0x14 == 0) return res;
    if (pred && pred->vtbl[2]() /* +8 */) return res;
  }
  if (cache->field_0x6c) {
    if (auto* a = AlternateLookup(key, type)) return a; // FUN_00970c00
  }
  for (factory : registry_copy) {
    if (auto* r = factory->vtbl[1](key, type)) return r; // +4
  }
  if (noDefaultCreate == 1) return nullptr;
  auto* r = new (0x3c) DefaultResource(key, type); // FUN_00745d70 + vtbl 00a9e850
  return r;
}
```

Wrapper residual (`NDResource_LoadByKey`, not owned): always writes `*pOut`, maps NULL → −1, then **vtbl+4** init — **separate** from this unit’s return.

Raw/annotated/clean scaffold CF ≡ live decompile on control structure. Gaps are **naming/layout**, not missing major branches. Decompiler dead-looking twin `if (param4==0) return; if (param4!=0) return;` is **not** two policies — machine collapses to one hit return when `+0x14==0`.

---

## 4. Surviving contract for AutoCore

```
// __stdcall, ret 0x14
NDResource* NDResourceCache_LookupOrCreate(
    NDResourceCache* cache,
    void* keyObj,
    void* typeToken,          // compared to resource+0x0C
    void* matchPredicateOpt,  // NULL ok; if used, vtbl+0x08 -> bool
    int noDefaultCreate);     // exactly 1 => never operator_new(0x3c)

// Hit policy:
//   type match && (res+0x14==0 || (pred && pred.vtbl[+8]()))
// Miss / reject → factories; then default unless noDefaultCreate==1

// Do NOT:
//   - treat as thiscall
//   - treat any non-zero param5 as "no create" (only 1)
//   - assume param4 always filters hits
//   - assume type lives at +0x00
```

---

## 5. Open questions

1. Identity of objects registered in the factory list (`FUN_0043c5f0` / `cache+0x28`).
2. Full meaning of `cache+0x6c` and whether shipping builds keep it non-zero.
3. Whether any caller passes `param5 == 1` (lookup-only) vs always `0` (create-default) — LoadByKey path uses wrapper formals often **0,0**.
4. C++ class name behind `PTR_FUN_00a9e850` (default NDResource).
5. Thread safety: default ctor initializes a critical section (`FUN_00745d70`); this function’s own map concurrency not sealed.

**Verdict:** **accept-with-gaps** on CF/ABI; **High** on hit policy, `param5==1` null path, and stdcall five-arg contract
