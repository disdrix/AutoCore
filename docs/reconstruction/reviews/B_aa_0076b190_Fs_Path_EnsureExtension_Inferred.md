# Review B (skeptical / adversarial): `aa_0076b190` Fs_Path_EnsureExtension_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b190` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-P) |
| **Counterpart** | `reviews/A_aa_0076b190_Fs_Path_EnsureExtension_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always forces extension to ESI | **Falsified** — only when `ext[0]==0`; non-empty ext preserved |
| 2 | ECX=path thiscall sole formal | **Falsified** — stack path+out; ESI default ext; path loaded from stack into ECX only for nested split |
| 3 | `unaff_ESI` is decompiler garbage | **Falsified** — both callers `mov esi, "glm"` before call |
| 4 | Returns path pointer in EAX | **Falsified** — void; no EAX result store |
| 5 | stdcall RET 8 | **Falsified** — bare `C3`; Compact does `add esp,8` |
| 6 | AssPackManager method | **Falsified** — free fs helper; packers are callers only |
| 7 | Product PDB name sealed | **Careful** — `_Inferred` from CF + call sites |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack path/out + ESI ext | **High** | Wrong formals |
| Ensure-not-replace CF | **High** | Wrong path rewrite |
| `"glm"` evidence | **High** | Misread pack ext |
| Nested split/make exact CRT | **Med** | Port buffer sizes |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// entry: sub esp,0x304
// split: push &ext,&fname; mov ecx,path; push &dir; lea eax,drive; call FUN_0076af70; add esp,0xc
// ensure: cmp byte [ext],0; jnz skip; strcpy(ext, ESI)
// make:  push &ext,&fname,out; lea ecx,dir; lea eax,drive; call FUN_0076aba0
// epi:   add esp,0x310; ret
// Compact @0098503d: push out; push path; mov esi,00aa61bc ("glm"); call; add esp,8
// 0071a9d0 @0071a9ee: same "glm" imm; shared add esp,0xc with prior strdup push
```

---

## 4. Surviving contract for AutoCore

```
// Port as ensure-extension path rewrite (not replace-always):
void EnsureExt(const char* path, char* out, const char* defaultExt /*retail: ESI*/) {
  // split path → drive, dir, fname, ext
  // if ext empty: ext = defaultExt;  // e.g. "glm"
  // makepath(out, drive, dir, fname, ext);
}
// Call from CompactPackFile before open. Do not clobber existing extensions.
// Nested split/make remain residual units.
```

---

## 5. Verdict

Adversarial pass confirms A on formals, ensure CF, `"glm"` sites, void cdecl. Nested helper plates residual → **accept-with-gaps**.
