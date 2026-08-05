# Review B (skeptical / adversarial): `aa_00514ff0` Object_PurgeSkillHBListChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514ff0` |
| **VA** | `0x00514ff0` |
| **Canonical name** | `Object_PurgeSkillHBListChain_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` |
| **System** | skills-abilities / object HB bookkeeping |
| **Wave** | W19-N OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Bare `__fastcall(int)` / no stack args” | **Falsified** — `RET 4`; stack slot used as ctx* |
| “Recursive call with `this == 0`” | **Falsified** — ECX loaded from `*(this+0xAC)` before call |
| “List embedded at `this+0xB0` (`lea ecx`)" | **Falsified** — `mov ecx,[esi+0xB0]` pointer load |
| “Generic remove-all HBs / all types” | **Falsified** — predicate requires type tag **1** + SkillBase RTTI + `+0x44` |
| “Always sets `hb+0x6a4`” | **Falsified** — only when `*ctx != 0` |
| “SiblingCastClear / skillId+TFID match” | **Falsified** — different unit `0x00514e20` / `LAB_00512bb0` |
| “Wire / packet / RPC” | **Falsified** — local list machinery only |
| Scaffold `Named_CalleeOf_…PacketDispatch…` product meaning | **Reject** — naming noise |
| Product export name without `_Inferred` | **Unproven** |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `void __fastcall FUN_00514ff0(int)` | **thiscall + 1 stack arg + RET 4** |
| `CNDDoubleList…(&LAB,…)` missing list this | **ECX = *(object+0xB0)** before call |
| `FUN_00514ff0(0)` | **ECX = *(object+0xAC)**; stack 0 |
| `FUN_004e2600` vs named util | Same VA `0x004e2600` (renamed dual) |
| Analyze `return_type undefined` | **void** in practice (no EAX product) |

---

## 3. Layout / CF challenges

| Challenge | Response | CF |
|---|---|---|
| Is `jbe` vs `je` meaningful for flag? | `cmp u8,0` / `jbe` ≡ only zero skips | **High** |
| Does recurse forward caller ctx? | **No** — always `push 0` | **High** |
| Is `+0xAC` parent or child? | **Unknown English** — only “linked object*” sealed | **Open** name |
| Is list always HB-of-SkillBase? | Predicate only matches tag 1; other nodes stay | **High** filter |
| Multi-hop chain? | Each call follows one `+0xAC`; chain if linked | **High** CF |

---

## 4. Surviving contract (minimal)

```
// __thiscall  ECX = Object* this
// stack+4    = ctx host (predicate reads *(uint8_t*)ctx)
// RET 4
void Object_PurgeSkillHBListChain_Inferred(Object* this, int ctxHost);

// if (this+0x25): CNDDoubleList_remove_match(*(this+0xB0), LAB_00512eb0, &ctxHost, 0)
// if (*(this+0xAC)): recurse(linked, 0)
// Does NOT: skillId match, TFID match, wire send, allocate HB.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| thiscall RET 4 | **Agree** |
| flag +0x25 / list* +0xB0 / link +0xAC | **Agree** |
| Predicate SkillBase stop/remove | **Agree** |
| ctx gates +0x6a4 | **Agree** |
| `_Inferred` name | **Agree** — required |
| Product English open | **Agree** |

---

## 6. Residual (honest)

1. Product method name.
2. Field English for gates/links/HB flags.
3. Full taxonomy of all 9 static callers'' object types.
4. Runtime + bit-exact image diff.
5. Formal Ghidra prototype repair (optional).

---

## 7. Verdict

### **accept-with-gaps**

ABI, offsets, list util call, predicate SkillBase role, and recurse-with-0 are **sealed**. Reject decompiler ABI, “this==0 recurse”, SiblingCastClear conflation, and product-name certainty. Dual A accept-with-gaps is appropriate.
