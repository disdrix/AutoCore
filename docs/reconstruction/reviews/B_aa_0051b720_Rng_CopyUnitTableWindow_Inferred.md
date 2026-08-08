# Review B (skeptical / adversarial): `aa_0051b720` Rng_CopyUnitTableWindow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md` |
| **Agent** | WQ9R-A OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is `void` / no useful return | **Falsified** — EAX holds pre-increment cursor; ApplyStatusEffectLocal stores it to `packet+0x3C` |
| 2 | Advances cursor by full window (`+= nWords`) | **Falsified** — body `lea ecx,[eax+1]`; sibling CloneSeededTable also `+1` |
| 3 | Index is dword-scaled (`*4`) | **Falsified** — `lea esi,[esi+eax*2]`; wrap headroom is nWords ushorts |
| 4 | `CVOGReaction_RandomUnitScalar(600,buf)` consumes stack args | **Falsified** — getter is 0-arg singleton; stack args belong to this unit (`ret 8`) |
| 5 | This is the same function as CloneSeededTable | **Falsified** — no alloc; nWords param; returns cursor not heap |
| 6 | Copies into global table (write) | **Falsified** — `rep movs` direction is table → dst |
| 7 | Only used from ApplyStatusEffectLocal | **Falsified** — second caller `FUN_0061fdf0` |
| 8 | Product name is known retail symbol | **Unproven** — `_Inferred` required |
| 9 | Wrap threshold is `0x80000` (u32 table count) | **Falsified** — `cmp …,0x100000` (cursor+nWords vs 0x100000) |
| 10 | Runtime Confirmed without Launcher | **Rejected** — Terminal false; machine-only seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Copy size / scale `*2` | **Confirmed** | Wrong dice window / OOB |
| Wrap `0xFFFFF` / `0x100000` | **Confirmed** | OOB past 2 MiB table |
| Cursor `+1` | **Confirmed** | Desync with CloneSeededTable / unit draws |
| EAX = old cursor | **Confirmed** | Wrong lDiceSeed wiring |
| this = `DAT_00d20c1c` | **Confirmed** | Port binds wrong object |
| Product symbol | Inferred | Cosmetic rename only |
| Buffer consumer after copy | Open | Port may drop unused buf; seed path still valid |

---

## 3. Cross-check

```
0051b720 body:   wrap; src=base+cursor*2; movs nWords*2; cursor++; ret 8 (EAX=old)
007a4330:        return &DAT_00d20c1c
0058ab60:        new[] 0x4b0; force seed; wrap+600; copy 300 dwords; cursor++; return heap
007a4170:        single ushort * (1/65536) from same +8/+0xC
0051aae8 site:   push buf; push 600; call getter; mov ecx,eax; call 0051b720; mov [edi+0x3C],eax
0061ffdc site:   same (600,buf); return unused; buf overwritten with TFIDs later
```

**Attack on “seed return is decompiler accident”:** ApplyStatusEffectLocal writes `local_4fc` from the call and stores to packet `+0x3C` only on the sim branch — matches annotated `lDiceSeed` field. Bytes show `mov eax,[edx+0xC]` immediately before increment.

**Attack on “600 is special to this unit only”:** CloneSeededTable hardcodes the same 600-ushort window; both call sites of this unit push `0x258`. Coincidence rejected — shared table contract.

---

## 4. Surviving contract for AutoCore

```
// Global RNG host (DAT_00d20c1c):
//   +0x08 → uint8_t table[0x200000]
//   +0x0C → int cursor  // ushort index

uint32_t Rng_CopyUnitTableWindow_Inferred(RngHost* rng, int nWords, void* dst) {
  if (rng->cursor + nWords > 0xFFFFF)
    rng->cursor = 0;
  memcpy(dst, rng->tableBase + rng->cursor * 2, (size_t)nWords * 2);
  uint32_t seed = (uint32_t)rng->cursor;
  rng->cursor += 1;
  return seed;
}
```

Port notes:
- Keep **+1** advance even when copying large windows (sliding seed).
- Skill sim path: seed return is the product; buffer may be scratch.
- Do not merge into CloneSeededTable without preserving alloc/force-seed differences.

---

## 5. Gaps

1. Product English / MSVC demangle.
2. Post-copy buffer readers (if any) outside sealed callers.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
