# Review B (skeptical / adversarial): `aa_0052b350` CVOGCharacter_RewardInventoryList_PushBack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-013) |
| **Counterpart** | `reviews/A_aa_0052b350_CVOGCharacter_RewardInventoryList_PushBack_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Generic free `StdList_PushBack` with ECX=list* (same as `0x00402d10`) | **Falsified** — ECX is owner; list is `LEA [ECX+0xcc4]`; value is **by value** not `const T*` |
| 2 | Push_front / insert-at-begin | **Falsified** — BuyNode(head, head->_Prev, …) then `head->_Prev = node` is classic **push_back** (before sentinel) |
| 3 | Tree / map insert (isnil family) | **Falsified** — node size **0xC**, callees BuyNode+Incsize `"list<T> too long"`, no color/isnil |
| 4 | Vector push_back / realloc growth | **Falsified** — circular node links; no capacity/end pointers |
| 5 | `__cdecl` / no stack cleanup / decompiler `__fastcall` void | **Falsified** — epilogue **`RET 4`** (`C2 04 00`); ECX this |
| 6 | Stack arg is `const T*` (like `00402d10`) | **Falsified** — caller `PUSH ESI` (value); body takes `&stack_slot` for BuyNode |
| 7 | Multiple independent callers / shared free helper | **Falsified** — **1** xref only (`FUN_004d08c0` @ `0x004d0980`) |
| 8 | Product name "reward inventory" fully sealed | **Survives as gap** — parent reward-slot loop + partition hint only; no field string/RTTI in this unit |
| 9 | this is not a character (random owner) | **Weakened not killed** — nearby `CVOGCharacter_*` methods + CompleteObjective parent make character-class **High**, not RTTI-Confirmed |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List push_back mechanics | **Confirmed** | Wrong container family in port |
| thiscall + RET 4 + by-value dword | **Confirmed** | Stack imbalance / wrong arg shape |
| List at +0xcc4 / head at +0xcc8 | **Confirmed** | Wrong field offset |
| BuyNode `0x00418700` + Incsize `0x00404840` | **Confirmed** | Miss throw path / node size |
| Not same ABI as free `00402d10` | **Confirmed** | Incorrect merge of helpers |
| CVOGCharacter this-type | **High** | Wrong owning class name |
| "Reward inventory" English | **Tentative / Inferred** | Misleading field label |
| Runtime | **Open** | Behavioral drift unknown |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 CF
assembly corrects ABI (thiscall RET 4; &stack value)

53 56 57                                   PUSH EBX/ESI/EDI
8B B9 C8 0C 00 00                          MOV EDI,[ECX+0xcc8]
8D B1 C4 0C 00 00                          LEA ESI,[ECX+0xcc4]
… E8 … 00418700                            CALL BuyNode
6A 01 … E8 … 00404840                      PUSH 1; CALL Incsize
89 5F 04 8B 53 04 … 89 1A                  head->_Prev=node; *prev=node
C2 04 00                                   RET 4

Call site 004d0980: MOV ECX,[ESP+20]; PUSH ESI; CALL 0052b350
```

Reject ports that:

- Treat ECX as the list header (must be owner; list at +0xcc4).
- Pass value as `const T*` without taking address of a by-value slot.
- Use push_front / vector / tree insert.
- Claim product field English without `_Inferred` / gap note.
- Claim runtime Confirmed without Launcher golden.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: character-bound std::list<uint32_t /*item*/>::push_back(value)
// at owner+0xcc4 (MSVC node 0xC, sentinel head).

void RewardInventoryList_PushBack(Character owner, uint itemOrObjectPtr)
{
    // list = owner + 0xCC4
    // buy node(head, head.Prev, value); size++; splice tail
    // may throw on size overflow ("list<T> too long")
}
```

Keep distinct from free helper `StdList_PushBack_Dword_Inferred` (`0x00402d10`: ECX=list*, stack=`const uint32_t*`).

---

## 5. Verdict

Adversarial pass confirms A on CF/ABI/list family; product field English + owner class English remain residual → **accept-with-gaps**.
