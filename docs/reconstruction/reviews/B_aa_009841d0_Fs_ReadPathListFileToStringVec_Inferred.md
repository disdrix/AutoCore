# Review B (skeptical / adversarial): `aa_009841d0` Fs_ReadPathListFileToStringVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009841d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | thiscall method on out-vec | **Falsified** — out is stack arg; `EBP` return; no ECX host for self |
| 2 | Memory-map whole file / single fread | **Falsified** — line loop Tell/Size + `FUN_00766ee0` |
| 3 | Fail path leaves out untouched | **Falsified** — still `FUN_00469d10` assign (empty collector) |
| 4 | Multi-format / binary list | **Falsified** — char line append only; CRLF strip in readline |
| 5 | Same as dir recurse collector | **Falsified** — sole role is file line list; caller does expand |
| 6 | Wide product name sealed | **Weak** — structural Inferred name; plate is stoFileOSFile cluster only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl out+path contract | High | Wrong pack/fs API surface |
| Open-fail → empty out | High | Silent leftover contents |
| Line-oriented push | High | Wrong list grammar |
| Sole `@`-list invoker | High | Over-narrow if dynamic call appears |

---

## 3. Cross-check

```
raw decompile ≡ entry SEH + open cmp + dual assign/tidy exits.
Parent W33-E: path[0]=='@' → this(path+1) → per-line expand.
Not FUN_009839b0 (dir leaf walk). Not pack add.
```

---

## 4. Surviving contract for AutoCore

```
Fs_ReadPathListFileToStringVec(out, path):
  open text file for read
  if fail: out = empty; return out
  for each line: out_collector.push_back(line)
  out = collector; return out
```

Port as free function; preserve fail→empty and line semantics (not split on `;` etc.).

---

## 5. Open questions

1. Product symbol on stoFile stream helpers.
2. Encoding / max line assumptions in `FUN_00766ee0`.

**Verdict:** **accept-with-gaps**
