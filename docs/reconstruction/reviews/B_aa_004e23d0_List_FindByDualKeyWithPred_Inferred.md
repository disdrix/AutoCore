# Review B (skeptical / adversarial): `aa_004e23d0` List_FindByDualKeyWithPred_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e23d0` |
| **VA** | `0x004e23d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e23d0_List_FindByDualKeyWithPred_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a **hash map** lookup | container habit | **Falsified** — linear walk via `node+0x10`; no bucket index |
| 2 | Single **32-bit** key only | simplify | **Falsified** — both `+0x18` and `+0x1c` must match |
| 3 | `*outPred` always set to found node | off-by-one pred | **Falsified** — body assigns only while keys **mismatch**; match exits without writing found into pred |
| 4 | **void** return (decompiler) | trust void | **Falsified as product contract** — EAX holds node; 27 callers use return |
| 5 | `__cdecl` / no this | stack-only | **Falsified** — ECX head load; `ret 0xc` |
| 6 | Exclusive **SpawnObject** helper | parent-seed name | **Falsified** — 27 xrefs incl. RemoveObject, TFID resolve, map helpers |
| 7 | Key is **string** / name | UI list habit | **Falsified** — two dwords; Coid sites pass dwCoidLo/Hi |
| 8 | Product name sealed by string/RTTI | symbol inflation | **Not sealed** — **Probable / `_Inferred`** only |
| 9 | Writes payload at `+0xc` | confuse with wrappers | **Falsified** — this leaf only walks + writes pred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual-key equality walk | **High** | Wrong object resolve / double-insert |
| Pred out-param semantics | **High** | Corrupt unlink on remove paths |
| EAX node* return | **High** | Null-deref if ignored; false void ports |
| thiscall `ret 0xc` | **High** | Stack imbalance |
| Leaf purity | **High** | Over-port locks/hash |
| Product English name | **Medium** | Doc only |
| Complete caller English roles | **Low–Med** | Miss non-reaction consumers |
| Uniform payload at +0xc | **Low** | Type confusion across maps |

---

## 3. Cross-check against raw

```text
// raw aa_004e23d0 ≡ live decompile 2026-07-29
// thiscall; head=*(this+4); next=+0x10; key=(+0x18,+0x1c)

*outPred = 0
node = head
while node && (node.keyLo != keyLo || node.keyHi != keyHi):
  *outPred = node
  node = node.next
// return node  (asm EAX; decompiler void)

// NOT:
//  - hash(bucket)
//  - single-word key
//  - exclusive CVOGReaction_SpawnObject helper
```

Clean `FUN_004e23d0.cpp` ≡ raw outline + explicit `return iVar1`.

---

## 4. Surviving contract for AutoCore

```
List_FindByDualKeyWithPred_Inferred(list, keyLo, keyHi, outPred*):
  // pure leaf; thiscall; 3 stack args; ret 0xc
  node = *(list+4)
  *outPred = 0
  while node != 0 and (*(node+0x18) != keyLo or *(node+0x1c) != keyHi):
    *outPred = node
    node = *(node+0x10)
  return node   // MUST return; do not ship decompiler-void

// Known consumers (sample):
//   CVOGReaction_SpawnObject / RemoveObject
//   FUN_0092ff00 TFID→object when global bit clear
//   FUN_004e3260 wrapper → *(hit+0xc)
```

**Port tests that matter:**

* Empty list → `(0, *pred=0)`.
* Head match → `(head, *pred=0)`.
* Mid match → `(node, *pred=prev)` — **not** found written to pred.
* Miss → `(0, *pred=last)`.
* Must compare **both** dwords.
* Must **return** node pointer (EAX contract).
* Do not treat parent-seed name as sole role.

---

## 5. Open questions

1. Official product / allocator English name.
2. Payload type variance at `node+0xc` across owners.
3. Runtime CE: insert then find-with-pred on known Coid.
4. Whether any site stores non-Coid dual keys in the same shape.

**Verdict:** **accept-with-gaps** — adversarial attacks on hash, single-key, void-return, exclusive-SpawnObject, and string-key **fail**; remaining gaps are product naming / full caller English / runtime only.
