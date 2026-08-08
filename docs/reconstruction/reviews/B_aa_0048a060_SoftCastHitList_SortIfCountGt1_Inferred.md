# Review B (skeptical / adversarial): `aa_0048a060` SoftCastHitList_SortIfCountGt1_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048a060` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-116) |
| **Counterpart** | `reviews/A_aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Free `__fastcall(uint)` / not object method | **Falsified** — body uses `[ECX+0x14]` / `[ECX+0x10]`; sole call site `LEA ECX,[hitList]; CALL` |
| 2 | Always sorts (even 0/1 hits) | **Falsified** — `CMP EAX,1` / `JLE` skip; only `count > 1` calls sort |
| 3 | Implements comparison / distance math itself | **Falsified** — sole CALL is `FUN_00489f20`; no FPU in this body |
| 4 | `RET 4` / stack arg this | **Falsified** — bare `RET` (`C3`); no stack params |
| 5 | Multiple callers / shared utility | **Falsified** — **1** xref only (`00925c3e` in hub) |
| 6 | 4th arg is live comparator context | **Weakened / preserve odd** — sort only re-pushes `[EBP+0x14]` on recurse; no compare use. Mask `this & ~0xFF` still emitted |
| 7 | Same unit as sort core `00489f20` | **Falsified** — distinct body; gate only; MEGA-115 owns sort |
| 8 | Product name without `_Inferred` | **Fails gate** — no PDB/string for class/key English |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 10 | Inventory / skill list sort | **Falsified** — call chain is interact soft-cast fill → hit walk / ForPick |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX + bare RET | **Confirmed** | Stack imbalance / wrong this |
| count@+0x14 / base@+0x10 | **Confirmed** | Wrong container layout |
| count>1 gate | **Confirmed** | Spurious O(1) sort cost / wrong empty path |
| Sole hub caller | **Confirmed** | Over-generalize system tag |
| Soft-cast hit-list role | **High** | Mis-tag system if fill helpers misread |
| Sort key = distance | **Medium** | Key is float@+0x14; product label open |
| sort_cookie semantics | **Low** | Dead retail path; do not invent meaning |
| Product English name | **Inferred** | Doc only until string/PDB |

---

## 3. Cross-check against raw / bytes

```text
raw scaffold 2026-07-23  ≡  live decompile 2026-08-05  ≡  clean named/twin

51                   PUSH ECX
8B 41 14             MOV EAX,[ECX+0x14]
83 F8 01             CMP EAX,1
C6 04 24 00          MOV byte [ESP],0
7E 14                JLE +0x14 → epilog
8B 14 24             MOV EDX,[ESP]
52                   PUSH EDX
48                   DEC EAX
50                   PUSH EAX
8B 41 10             MOV EAX,[ECX+0x10]
6A 00                PUSH 0
50                   PUSH EAX
E8 A2 FE FF FF       CALL FUN_00489f20
83 C4 10             ADD ESP,0x10
59                   POP ECX
C3                   RET

Body: 0x0048a060–0x0048a082 (35 B); next FUN_0048a083
Caller: Client_InteractWorldClickHub @ 00925c3e only
```

Reject ports that:

- Treat this as a free function taking a raw integer count/base without object layout.
- Sort on every call including empty/singleton lists.
- Inline the 0x30-stride quicksort into this unit (belongs at `00489f20`).
- Claim runtime Confirmed without Launcher evidence.
- Drop the masked 4th-arg emission if bit-exact fidelity is required.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail gate before soft-cast multi-hit walk (InteractWorldClickHub).
// Port: if (hits.Count > 1) hits.SortByKey014Ascending();

sealed class SoftCastHitList
{
    public SoftCastHit[] Array; // retail: ptr @ +0x10, stride 0x30
    public int Count;           // retail: +0x14

    public void SortIfCountGt1()
    {
        if (Count > 1)
            SoftCastHitListQsort.SortRange(Array, 0, Count - 1);
        // retail also passes (this & ~0xFFu) as unused cookie — omit in managed
        // unless bit-exact native interop requires it.
    }
}
```

Pair with:

- Fill path: `FUN_0055e1e0` / `FUN_006ca890` (soft-cast hit-list core).
- Resolve path: `FUN_0040afb0` on post-sort hits.
- Sort core dual: MEGA-115 `0x00489f20`.

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/single-caller gate. Remaining gaps are product English + sort-core residual + runtime → **accept-with-gaps**.
