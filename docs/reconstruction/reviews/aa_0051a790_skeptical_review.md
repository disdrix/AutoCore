# Skeptical / adversarial review: `Skill_LocalCastValidate` @ `0x0051a790`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a790` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Local pre-cast validation unit, eSkillResponses claims, signature |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_0051a790_Skill_LocalCastValidate.md` | Body |
| `raw/aa_0051a790_Skill_LocalCastValidate.annotated.md` | Plate + scaffold |
| `reconstructed-exact/Skill_LocalCastValidate.cpp` | Clean |
| `functions/aa_0051a790_Skill_LocalCastValidate.md` | Record |
| Call sites in RequestCast / QuickBarActivate | Arg pattern |
| `docs/topic-extractions/skill-cast.md` | Response code table (`0` ok, `4` power, `6` busy, `7` recharge, `13` range, `14` target) |

**Not performed:** assembly of prologue/formals, FormatFailureMessage string table dump, runtime.

---

## 2. Evidence used

### Body-derived return map (from raw)

| Code | Trigger in body (summary) |
|-----:|---------------------------|
| 5 | `this+0xb4 & 2`, or flag8 + mode `0x14` |
| 3 | vtable power/vehicle checks fail |
| 6 | busy helper `FUN_005169c0()+0x10 != 0` when skip formal is 0 |
| 4 | power short vs skill cost short |
| 7 | `skill+0x628` or category CD remaining ≠ 0 |
| 10 | helper + skill flag `+0x615 & 2` |
| 0xc (12) | vehicle flag path / skill `+0x614 & 0x4000` |
| 0xb (11) | fallthrough after vehicle/range gating fails |
| range helper | `Skill_LocalRangeTargetCheck` return |
| 0 | success / or skill formal null after early gates |

### Call-site pattern

```
Skill_LocalCastValidate(entity, 0, (char)skill, 0)
```

---

## 3. Attack results

### Claim 1 — Signature is `(this=pCaster, pCaster, bSkipBusyCheck, pSkill)`

| Sub-claim | Attack result |
|-----------|----------------|
| `this` is caster-like object | **Survives** (vtable + `+0xb4` flags on `this`) |
| First stack arg is pCaster object | **BROKEN.** Body tests `(char)pCaster == 0` as skip/busy gate — boolean, not object |
| `bSkipBusyCheck` is char skip flag | **BROKEN.** `_bSkipBusyCheck` is used with skill runtime offsets |
| `pSkill` is skill runtime | **Unused** in body — dead formal |
| Call-site `(char)skill` is intentional retail | **Almost certainly decompiler damage** — truncating pointer then using as pointer elsewhere is inconsistent |

**Corrected working hypothesis (not sealed):**

```
// this = caster entity
// arg0 = bSkipBusyCheck (char)  // callers pass 0
// arg1 = pSkill (pointer)       // decompiler typed as char
// arg2 = unused/padding
```

Until assembly, treat plate names as **false**.

---

### Claim 2 — Returns complete eSkillResponses including range=13 target=14

| Sub-claim | Attack result |
|-----------|----------------|
| Some codes match topic table (`0,4,6,7`) | **Probable** |
| This function itself returns 13/14 | **Not shown.** Those appear as `0xd/0xe` in CastSkillOnTarget target-resolve mapping, not here |
| Codes `3,5,10,11,12` meanings | **Named only by number** — plate claims FormatFailureMessage verification but this body does not call it |
| “VERIFIED” plate stamp | **Overclaim** without committed string-table evidence in this unit pack |

---

### Claim 3 — Null skill means “lightweight check” that can still succeed

| Sub-claim | Attack result |
|-----------|----------------|
| Plate: pSkill may be null for lightweight check | Matches early `return 0` when skill formal null after busy gates |
| Callers pass truncated skill always | Callers always pass skill pointer (as char) — null skill path may be rare/other callers |
| Lightweight path still enforces power/CD | **Falsified** — power/CD live under skill formal non-null |

---

### Claim 4 — Fully validates cast readiness for network send

| Sub-claim | Attack result |
|-----------|----------------|
| Several local gates | **Holds** |
| Target legality complete | **Delegated** to `Skill_LocalRangeTargetCheck` only on some branches |
| Server authority | Correctly not claimed |
| Active cast binding must be invalid to enter skill checks | **Holds as CF** (`TFID_NotEquals` with invalid → char==0 path) — polarity of TFID helpers needs care |

---

### Claim 5 — Clean is port-ready validation module

| Sub-claim | Attack result |
|-----------|----------------|
| CF copy of raw | **Holds** |
| Compilable sealed API | **Fails** (`_bSkipBusyCheck`, unaff, wrong types) |
| Enum-named returns | **Fails** — magic numbers only |

---

## 4. Alternate interpretations

### Minimal reading

Caster entity gates → optional busy gate → if skill present and no active binding conflict: power, casting flag, category CD, vehicle/mode flags, maybe range helper → eSkillResponses-shaped int.

### What the name oversells

“LocalCastValidate” suggests complete local cast rules. Body is a **partial gate ladder** with multiple unresolved helpers (`FUN_005169c0`, `FUN_00518c20`, range check).

---

## 5. What was confirmed despite skepticism

1. Integer reject codes as listed in §2 from body structure.
2. Skill object field offsets used when skill formal non-null.
3. Callers treat `0` as success to continue cast send.
4. Clean did not invent a modern validator API.
5. Plate formal names do **not** match body uses (negative finding confirmed).

---

## 6. Critical contradictions found

### C1 — Plate formals vs body uses vs call sites

Three-way inconsistency: comments, body, callers. **Highest priority seal gap in the cast graph.**

### C2 — “VERIFIED” response codes without in-unit evidence

Topic extraction + plate claim verification via FormatFailureMessage; this function pack has no string table attachment.

### C3 — Range/target codes attributed to LocalCastValidate in broad docs

13/14 appear elsewhere in the cast pipeline; attributing them as LocalCastValidate returns without range-helper seal is sloppy.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | True prototype | **Yes** — critical |
| R2 | Full enum ↔ string map | Yes for UX parity |
| R3 | Flag meanings on caster/skill | Yes |
| R4 | TFID helper polarity | Yes for busy/active-cast gate |
| R5 | Runtime each code | Yes |

---

## 8. Concrete checks performed

1. Listed every `return` constant in raw.
2. Mapped offsets on `_bSkipBusyCheck` → skill-like fields.
3. Mapped `(char)pCaster` uses → boolean busy skip.
4. Compared to both client call sites (identical broken pattern).
5. Cross-checked topic codes 13/14 against this body — absent.
6. Verified clean is textual CF match, not an ABI repair.

---

## 9. Verdict

### **`needs-more-evidence`**

The mechanical gate ladder exists, but the **signature and naming package is actively wrong** relative to body evidence. Cannot port from plate comments.

### Acceptance bar later

1. Assembly of formals / register assignment at `0x0051a790`.
2. Commit FormatFailureMessage string table for each code.
3. Rename formals in annotated layer to match body (skill vs skip).
4. Re-decompile callers after prototype correction.

### Port guidance

- Do **not** implement plate signature as written.
- Treat return ints as opaque until string table sealed.
- Keep call-site success test `== 0`.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Plate signature | **Falsified** |
| 2 | Full eSkillResponses here | **Partial / overclaim** |
| 3 | Null skill lightweight design | **Weak** |
| 4 | Complete cast validation | **Overclaim** |
| 5 | Port-ready clean | **Fails** |

**Final verdict: `needs-more-evidence`**
