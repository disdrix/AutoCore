# Review B (skeptical / adversarial): `aa_0076cf00` Profiler_ScopeEnter

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cf00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076cf00_Profiler_ScopeEnter.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Body starts QPC / pushes zone stack | Body is only load `[ecx+4]` + `ret 4` | **Falsified** |
| 2 | Name string is hashed or stored | No read of stack arg | **Falsified** |
| 3 | Pure `__fastcall` one-arg, no stack | `ret 4` + call-site `push` name | **Falsified** incomplete decompiler view |
| 4 | ECX is the name pointer | Callers set ECX from `DAT_00d1f040`, name on stack | **Falsified** |
| 5 | Gameplay / physics math helper | High fan-in with zone name strings; leave is no-op | **Falsified** |
| 6 | Must port to AutoCore sector sim | Explicit ignore in drive/step notes; client only | **Falsified** as mandatory |
| 7 | Returns void | `mov eax,[ecx+4]` | **Falsified** |
| 8 | Scaffold `Named_CalleeOf_CVOGHBAIDriver_*` is product name | Xref-weak auto alias only | **Overstated** |
| 9 | `FUN_0076cef0` cleans stack args | Leave is bare `c3` | **Falsified** if claimed symmetric ret N |
| 10 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body bytes / ret 4 | **High** | Wrong ABI in wrappers |
| Return = timer at +4 | **High** | Mis-linked to wrong object field |
| Name unused | **High** | Wasted port work on string table |
| Profiler family | **High** | Mis-file under wrong system |
| Product identifier spelling | **Low–Med** | Naming only |
| Exact dynamic type of global | **Med** | Only +4 slot sealed here |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex | `8b4104c20400` via `read_memory` |
| Leave | `c3` at `0x0076cef0` |
| Call-site global | `8b 35 40 f0 d1 00` / `8b 2d 40 f0 d1 00` patterns |
| Zone timer at +4 | Zone ctor dual stores `new(0x30)` timer at `+4` |
| Physics docs label | enter/leave pair — role agrees; body is stub not full enter |

**Attack on “this is still a full profiler enter”:** **Survives only as ABI/name shell** — timing work is compiled out.

**Attack on “returns zone object”:** **Weak** — returns `*(ctx+4)`, which zone ctor defines as **timer**, not self.

---

## 4. Surviving contract for AutoCore

```
// ECX = *DAT_00d1f040
// push name; call; ret 4
// EAX = *(ECX+4)  // timer*
// name ignored; no QPC; leave is ret
```

**Falsified port mistakes:**

- Treating as physics/AI logic.
- Assuming name is recorded.
- Calling without ECX = profiler ctx.
- Expecting leave to `ret 4`.
- Using return as zone* instead of timer*.

---

## 5. Open questions

1. Product name / PDB.
2. Full Hermann / thread-slot object around `DAT_00d1f040`.
3. Whether any path still starts timers via return value + other helpers.

**Verdict:** **accept** — stub ABI and role sealed; no blocking residual.
