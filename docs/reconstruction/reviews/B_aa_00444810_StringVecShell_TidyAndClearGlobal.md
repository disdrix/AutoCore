# Review B (skeptical / adversarial): `aa_00444810` StringVecShell_TidyAndClearGlobal

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-K) |
| **Counterpart** | `reviews/A_aa_00444810_StringVecShell_TidyAndClearGlobal.md` |
| **Scratch** | `tmp/a_00444810.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler void / no-arg is complete | **Falsified** — SEH sites load `ECX=host+0xA0`; prolog preserves ECX into `StringVec_Tidy` |
| 2 | Only nulls global without tidy | **Falsified** — `CALL 0x00431ae0` before store |
| 3 | Tidies but leaves `DAT_00d1f1fc` live | **Falsified** — explicit `MOV [DAT_00d1f1fc],0` |
| 4 | Has stack formals / RET n | **Falsified** — bare `C3` after `ADD ESP,0xC` (SEH frame only) |
| 5 | General-purpose multi-caller util | **Weakened** — only two Unwind xrefs under Palantir dtor SEH table |
| 6 | Same as plain `StringVec_Tidy` | **Falsified** — extra global clear side effect |
| 7 | Capacity-preserving clear | **Falsified** — delegates full tidy (free+null triad) |
| 8 | Invents product class name in unit | **Rejected** — structural shell name; Palantir linkage is caller-context |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX=shell + bare RET | **High** | ABI crash / wrong shell |
| tidy then global null order | **High** | UAF / stale path list |
| not equal to bare `StringVec_Tidy` | **High** | miss global alias clear |
| SEH-only callers | **High** | over-generalize call graph |
| Product English | **Low** | naming |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00444810 (bytes)
SEH; StringVec_Tidy(ECX); DAT_00d1f1fc=0; RET

// Unwind@009afd09 / @009afd4a
ECX = frame_this + 0xA0; JMP FUN_00444810

// Normal path inside Palantir_CompleteDtor
LEA ECX,[ESI+0xA0]; CALL StringVec_Tidy; DAT_00d1f1fc=0
// (in-line twin of this helper without separate call)
```

Decompile omits ECX; SEH site memory seals shell address. Twin of normal-path tidy+clear inside `0x00754320`.

---

## 4. Surviving contract for AutoCore

```
// Port as tidy + drop published shell pointer:
void StringVecShell_TidyAndClearGlobal(StringVecShell* shell) {
  StringVec_Tidy(shell);      // full release (W33-D)
  DAT_00d1f1fc = nullptr;     // must not leave stale global
}
// Do not call without valid ECX shell.
// Do not skip global clear after tidy of the published path list.
// Palantir dtor normal path may in-line the same two steps.
```

---

## 5. Verdict

Adversarial pass confirms A: decompiler under-specified; bytes + SEH sites seal ECX ABI and tidy→clear-global. Product English open only → **accept**.
