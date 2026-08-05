# Review B (skeptical / adversarial): `aa_005070b0` CVOGPhysics_ProbeReadyFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_005070b0` |
| **VA** | `0x005070b0` |
| **Review type** | Skeptical / adversarial (OWN-ONLY) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005070b0_CVOGPhysics_ProbeReadyFlag.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function **prepares** / attaches physics (`5070d0` role) | Confuse probe with prepare sibling | **Falsified** — leaf; only writes `*out`; no call |
| 2 | Returns ready flag **in AL/EAX as value** | Over-read decompiler `void` vs callers | **Partially true form** — EAX is **out pointer**, not the flag; flag is `*EAX` / `*out` |
| 3 | Reads flag at `this+0x29` | Skip host indirection | **Falsified** — flag is on `*(this+0x44)+0x29` |
| 4 | Null host is undefined / crash | Defensive-port fear | **Falsified** — explicit `*out=0` then ret |
| 5 | Writes host or clears dirty bits | “dirty guard” folklore | **Falsified for this VA** — no store except `*out` |
| 6 | Math / float ready threshold | Physics-math overfit | **Falsified** — pure pointer + byte load |
| 7 | `stdcall` / no stack cleanup | Convention guess | **Falsified** — `ret 4` thiscall |
| 8 | Decompiler `param_1` is out-ptr | Arg swap | **Falsified** — ECX=`this`, `[esp+4]`=out* |
| 9 | Name is string-proven Havok API | Symbol inflation | **Not sealed** — **Probable** usage name only |
| 10 | Flag `1` always means “ready forever” | Polarity absolute | **Not sealed** — callers treat `0` as not-ready; producers open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null `+0x44` → out `0` | **High** | Wrong gate → always prepare / never prepare |
| Load `host+0x29` | **High** | Read wrong field; silent always-ready |
| Leaf (no callees) | **High** | Invent side effects in port |
| EAX = out* | **High** | Port returns flag in AL; callers that `CMP [EAX]` break if rewritten naively |
| English type of host / flag | **Low–Med** | Naming only |
| Universal “physics ready” product term | **Med** | Doc only; may be attach/enable bit |

---

## 3. Cross-check against raw / live / bytes

```text
// raw aa_005070b0 ≡ force_decompile ≡ live decompile 2026-07-29
if (*(int*)(this+0x44) == 0) {
  *out = 0;
  return;
}
*out = *(uint8_t*)(*(int*)(this+0x44) + 0x29);

// bytes seal (OWN VA):
// 8B 41 44  85 C0  75 0A  8B 44 24 04  C6 00 00  C2 04 00
// 8A 48 29  8B 44 24 04  88 08  C2 04 00
```

Clean scaffold `FUN_005070b0.cpp` matches this CF (typed as `uint8_t *param_2`). No invent prepare or host mutation.

---

## 4. Surviving contract for AutoCore

```
// Physics ready probe (OWN contract only)
outReady = CVOGPhysics_ProbeReadyFlag(obj, &out):
  host = obj.field_44          // pointer at +0x44
  if host == null:
      *out = 0
  else:
      *out = host.byte_29      // byte at host+0x29
  // machine also leaves EAX = out (for CMP [EAX],0 idioms)

// Typical caller pattern (context; not owned here):
//   ProbeReadyFlag(phys, &b)
//   if (b == 0 && phys.field_44 != null)
//       FUN_005070d0(phys)    // prepare sibling — separate dual
//   then body vtbl write ...
```

**Port tests that matter:**

* Must **not** call prepare (`5070d0`) inside this unit.
* Must **not** read `this+0x29` (wrong object).
* Null host → out **0**, not crash, not leave out uninitialized.
* Only side effect: write exactly one byte to `*out`.
* Prefer modeling **out-param** (and optional EAX alias), not “returns bool in AL” alone.

---

## 5. Open questions

1. Type plate for host at `+0x44` and name of `+0x29`.
2. Dual / seal of prepare sibling `FUN_005070d0`.
3. Full producer set for the flag byte (who sets ready).
4. Whether non-physics objects share the same layout under other English names.

**Verdict:** **accept-with-gaps** — adversarial attacks on prepare-confusion, wrong offset, and invented side effects **fail**; remaining gaps are type English and sibling dual only.
