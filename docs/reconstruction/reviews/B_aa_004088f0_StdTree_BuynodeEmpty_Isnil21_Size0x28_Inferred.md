# Review B (skeptical / adversarial): `aa_004088f0` StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004088f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9H-I) |
| **Counterpart** | `reviews/A_aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + callers/xrefs + assembly_context. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void FUN_004088f0(void)` is complete ABI | **Falsified as return** — all 4 callers use **EAX** as node\* |
| 2 | This is `CNDHash_FreelistPop_Node0x28` | **Falsified** — freelist pops from EDI head / aligned slab; this is `operator_new(0x28)` + tree link init |
| 3 | isnil@+0x29 / Val24 family identity (`00407e30`) | **Falsified** — color@**+0x20** isnil@**+0x21**; size **0x28** not 0x30; no 5-arg value construct |
| 4 | Full value buynode with left/parent/right/value/color args | **Falsified** — zero stack formals; zeros links; peer is `00408990` |
| 5 | List/circular sentinel only (no tree) | **Falsified as sole role** — callers set **isnil** and three child/parent links circularly — classic `_Tree` head |
| 6 | thiscall ECX = tree | **Falsified** — no ECX use; pure cdecl factory |
| 7 | Scaffold GiveItemByCbid chain name is product | **Falsified as product** — one caller is deep ctor path; dual renames |
| 8 | Writes color/isnil only when node non-null always safe | **Narrowed** — decomp order can look like stores after null skip arms; live callers assume non-null; OOM edge residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + EAX node return | **High** | Lost head pointer |
| new(0x28) + isnil21 layout | **High** | Wrong map family |
| Role = empty buynode / head factory | **High** | Invented freelist |
| Product Val20 type | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
0040557d: call FUN_004088f0
00405582: mov [esi+4], eax          ; _Myhead
00405585: mov byte ptr [eax+0x21], 1
0040558c: mov [eax+4], eax          ; parent = self
00405592: mov [eax], eax            ; left = self
… right = self; size = 0
```

Same pattern at `00405d1a`, `0040611a`, `00501c4e`.

Twin contrast `FUN_00408a30`: identical CF with `new(0x30)` and isnil@+0x29 — **keep distinct names/VAs**.

---

## 4. Surviving contract for AutoCore

```csharp
// Node* StdTree_BuynodeEmpty_Isnil21_Size0x28()
// cdecl, ret 0, EAX = node
// new(0x28); links=0; color@0x20=1; isnil@0x21=0
// Head init (callers): isnil=1; L/P/R=self; size=0
```

Do **not** merge with freelist pop or isnil29 buynodes. Pair value inserts via peer `00408990` when dualed.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm empty tree buynode CF/ABI/layout. Residual demangle + peer duals + runtime. Not reject.
