# Review B (skeptical / adversarial): `aa_0076b3f0` Fs_ListDirBasenames_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b3f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-C) |
| **Counterpart** | `reviews/A_aa_0076b3f0_Fs_ListDirBasenames_Inferred.md` |
| **Scratch** | `tmp/a_0076b3f0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Single formal (path only) as decompiler shows | **Falsified** — callers pass 2 args; ECX load for `FUN_004301f0` is out vector |
| 2 | Pushes full joined paths | **Falsified** — only `cFileName` basenames; join is caller (`009839b0`) |
| 3 | Recurses into subdirs | **Falsified** — flat FindNext loop only; recurse is `009839b0` |
| 4 | Always appends `"/*"` | **Falsified** — only when `FUN_0076adc0(path)` true |
| 5 | Filters directories out of listing | **Falsified** — no `dwFileAttributes` gate; dirs and files both pushed |
| 6 | `operator+=` uses `"\*"` Windows sep | **Falsified** — literal `"/*"` at `0x00a9d210` |
| 7 | Product name sealed | **Careful** — structural `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| FindFirst/Next CF + skip `.`/`..` | **High** | Wrong listing |
| cdecl (path, out_vec) | **High** | Missing out / ABI crash |
| basename-only push | **High** | Double-join / wrong paths |
| no dir/file filter | **High** | Drop dirs from recurse listing |
| `"/*"` only if is_dir | **High** | Broken non-dir patterns |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0076ba10: FUN_0076b3f0(param_1, local_70);
// W32-D 009839b0: FUN_0076b3f0(path, &listing); then join path+"/"+entry
// W32-D plate already documented string stride 0x1c on listing
// SEH LAB_009acd96; body 351 B; ADD ESP,0x184; RET
// Live decompile 2026-07-29 ≡ raw 2026-07-23 CF (1-arg gap remains in decompiler)
```

---

## 4. Surviving contract for AutoCore

```
// Port as flat basename enumerator:
void Fs_ListDirBasenames(const char* path, StringVec* out) {
  string pattern = path;
  if (Fs_PathIsDirectory_Stat(path)) pattern += "/*";
  // FindFirst/Next; skip "." / ".."; out->push_back(cFileName);
  // Do NOT join parent path. Do NOT filter directories.
  // Do NOT recurse (caller 009839b0 owns that).
}
// cdecl 2 args. Pair is_dir 0076adc0 + push 004301f0.
```

---

## 5. Verdict

Adversarial pass confirms A on 2-arg ABI, flat basename push, and non-recursive CF. Residual product/SSO → **accept-with-gaps**.
