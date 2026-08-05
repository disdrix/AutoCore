# Review B (skeptical / adversarial): `aa_0054f3c0` SkillRuntime_PartialCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054f3c0` |
| **VA** | `0x0054f3c0` |
| **Canonical name** | `SkillRuntime_PartialCtor` (INFERRED) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054f3c0_SkillRuntime_PartialCtor.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full skill ctor (all fields valid after return) | Only **selected** zeros; template copy fills body | **Falsified** as complete ctor |
| 2 | Target-list / resolve-targets builder | Zero loops only; no TFID list build | **Falsified** (parent name misnomer is separate) |
| 3 | Sets skill rank | Rank at **`+0x5f6`** via `Skill_SetRankAndReevaluate`; this zeros **`+0x5f0`** only nearby | **Falsified** rank-setter claim |
| 4 | `operator_new` lives inside this fn | Callers allocate; this only inits | **Falsified** |
| 5 | Decompiler `__fastcall int` is mysterious | ECX this, return this — standard leaf ctor shape | **Attack fails** on mystery; ABI sealed |
| 6 | Solely used by ResolveSkillTargets | 4 xrefs including HB skill base ctor | **Falsified** exclusive-caller |
| 7 | Copy then ctor order | Parent: **ctor then copy** | **Agree** A |
| 8 | Product name required | No strings | **Agree structural** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Partial zero-init leaf | **Confirmed** | Over-port as full ctor |
| Offset map of zeros | **Confirmed** | Miss buffer clears |
| ECX/return this | **Confirmed** | Wrong register ABI |
| Size context 0x630 | **High** | Undersize alloc |
| Semantic field names | **Open** | Misnamed ports |
| Why not memset(0,0x630) | **Open** | Over-zero if assumed |

---

## 3. Cross-check against raw / live / bytes

```
raw ≡ live decompile 2026-07-29.
entry: mov edx, ecx; mov [edx+0x5f0], 0; ...
end:   mov eax, edx; pop edi; ret
callees: none
callers: CVOGReaction_ResolveSkillTargets, CVOGHBSkillBase_ctor, FUN_00578830, FUN_008422f0
parent chain:
  new(0x630) → FUN_0054f3c0(this) → copy 0x18c dwords from node+0x10
            → Skill_SetRankAndReevaluate(this, rank)  // +0x5f6
```

### Overwrite trap

Because parent **copies 0x630 bytes from template starting at dest base**, many zeros here are **immediately overwritten**. Porting only the partial ctor without the copy is **wrong**. Porting only the copy without ctor may leave **string/buffer tails** dirty if template source does not cover them — size math says copy covers full object (`0x18c*4=0x630`), so **entire object is overwritten** in materialize path. Then partial ctor zeros are **dead** for that path unless copy source is incomplete / overlapping differently.

**Adversarial note:** If `REP MOVSD` truly copies full `0x630` from `node+0x10`, then this ctor’s zeros are **fully overwritten** on the materialize path — purpose may be (a) other callers without full copy, (b) historical, or (c) safety before copy if new fails mid-path. **Do not delete ctor from non-materialize callers** without checking.

---

## 4. Surviving contract for AutoCore

```
SkillRuntime* PartialCtor(SkillRuntime* s) {
  s->u32_5f0 = 0;
  zero(s+0x184, 8 * 4);          // through +0x1a0
  s->b_1a4 = 0;
  zero(s+0x1a5, 0x100 * 4);      // + trailing byte
  zero(s+0x5a6, 0x10 * 4);       // + trailing byte
  s->u32_170 = 0;
  s->u32_178 = 0;
  s->b_61c = 0;
  return s;
}
// Materialize: new 0x630 → PartialCtor → memcpy 0x630 from def → SetRank(+0x5f6)
```

---

## 5. Open questions

1. Are HB/UI callers full-copy or rely on zeros alone?
2. Field names for `+0x1a5` / `+0x5a6` buffers.
3. Whether full-copy path makes zeros redundant (instrumentation).
4. Runtime capture.

**Verdict:** **accept-with-gaps**
