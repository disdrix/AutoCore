# Review B (skeptical / adversarial): `aa_00560750` PhysHost_MergeSortedPairList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-S) |
| **Counterpart** | `reviews/A_aa_00560750_PhysHost_MergeSortedPairList_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Simple vector append of src onto dest | **Falsified** — full sorted merge with equal-key absorb, not append |
| 2 | thiscall ECX = dest | **Falsified** — prologue `MOV ESI,EAX`; sole caller loads dest into **EAX** |
| 3 | `in_EAX` is decompiler phantom noise | **Falsified** — `is_phantom:true` in analyze but machine/caller prove real EAX formal |
| 4 | Same as stride-8 bind pair commit (`006297e0`) | **Falsified** — different VA; this is host+0x68 list merge during host merge only |
| 5 | No equal-key side effects | **Falsified** — vtbl+0x14 and partner vtbl+0x10 on match |
| 6 | Product "constraint list" name is sealed | **Overstated** — parent called it constraint/contact family **Tentative** |
| 7 | PUSH EBP is a second formal | **Unresolved** — function uses only Stack[0x4]; caller ADD ESP,4; EBP push residual gap |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sorted merge role | **High** | Wrong island glue on host merge |
| EAX dest + stack src | **High** | ABI break |
| Dual-key order | **High** | Mis-ordered pairs / missed equals |
| Equal absorb vcalls | **High** | Leaked pair objects |
| PUSH EBP | **Medium** | Stack hygiene only at sole site |
| Product types | **Low** | Naming |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check

```
MOV ESI,EAX (dest); worklist init dest.count; copy; grow; merge; release; RET
Caller: dest=EDI+0x68 in EAX, src=ESI+0x68 on stack (after ESI=src host, EDI=dest host in MergeHosts)
```

Note: MergeHosts machine has ESI=src host, EDI=dest host (arg order vs decompiler names inverted on registers — list merge still dest←src).

Live ≡ raw CF. Closes W20-B open dual of this VA.

---

## 4. Surviving contract for AutoCore

```
// Inside PhysSim_MergeHosts when collapsing src into dest:
// EAX = &dest->pairList68; push &src->pairList68; call merge; add esp,4
// Must preserve sorted dual-key merge + equal-key absorb; not a dumb append.
```

---

## 5. Verdict

Adversarial pass confirms A; remaining gaps are product English + PUSH EBP residual → **accept-with-gaps**.
