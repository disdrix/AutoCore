# Review B (skeptical / adversarial): `aa_0076cef0` Profiler_ScopeLeave

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-D) |
| **Counterpart** | `reviews/A_aa_0076cef0_Profiler_ScopeLeave.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Leave pops zone stack / stops QPC timer | Body is only `c3` | **Falsified** |
| 2 | Symmetric `ret 4` with enter | Enter is `c2 04 00`; leave is bare `c3` | **Falsified** |
| 3 | Gameplay / physics / AI logic helper | Zero body; physics docs say ignore | **Falsified** |
| 4 | Must port to AutoCore sector sim | Client instrumentation stub | **Falsified** as mandatory |
| 5 | Same VA as ScopeEnter | Enter is `0x0076cf00` | **Falsified** |
| 6 | Shared mass EmptyRet `0x0056f570` | Different VA | **Falsified** if conflated |
| 7 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |
| 8 | Product name sealed as ScopeLeave | Structural only; Exit/EndZone open | **Overstated** if claimed sealed spelling |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body bytes / bare ret | **High** | Wrong ABI wrappers |
| No side effects | **High** | Invented leave work |
| Twin of ScopeEnter | **High** | Mis-file system |
| Product identifier spelling | **Low–Med** | Naming only |
| Must-implement for sim | **High reject** | Wasted port |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex | `c3` via `read_memory` |
| Next leaf enter | `8b4104c20400` @ `0x0076cf00` |
| W18-G leave note | agrees bare `ret` |
| Physics drive/step/applyAction | enter/leave pair — ignore |

**Attack on “this still ends a real timer”:** **Fails** — body empty; any timing is elsewhere or compiled out.

**Attack on “leave must ret 4 because enter took a name”:** **Fails** — enter already `ret 4`.

---

## 4. Surviving contract for AutoCore

```
// call Profiler_ScopeLeave();  // bare ret; no args required
// no-op in retail body
```

**Falsified port mistakes:**

- Implementing timer stop / stack pop at this VA.
- Using `ret 4` leave wrapper.
- Treating as physics/AI domain logic.
- Conflating with enter `0x0076cf00` or other empty leaves.

---

## 5. Open questions

1. Product name / PDB.
2. Whether return of enter (timer*) is ever used with a non-empty leave path in other builds (not this VA).

**Verdict:** **accept** — empty leave stub sealed; no blocking residual.
