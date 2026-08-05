# Review B (skeptical / adversarial): `aa_00970910` AssPreloader_ExtBucketFromPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970910` |
| **VA** | `0x00970910` |
| **Canonical name** | `AssPreloader_ExtBucketFromPath_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00970910_AssPreloader_ExtBucketFromPath_Inferred.md` |
| **System** | AssPreloader extension bucket |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Scans all five strings including OTHER via strstr | Loop bound returns 4 before OTHER slot | **Falsified** OTHER-search claim |
| 2 | Returns void / no value | Callers `mov edi,eax` then index `+e8/+fc` | **Falsified** |
| 3 | Thiscall ECX = preloader | No ECX setup; stack push of name holder | **Falsified** |
| 4 | cdecl plain ret | Bytes `C2 04 00` | **Falsified** plain-ret |
| 5 | Suffix-only / path parser | Uses CRT `strstr` (substring) | **Agree** not suffix-only |
| 6 | Case-insensitive | CRT strstr is case-sensitive | **Agree** case-sensitive |
| 7 | Named solely from `.xml` plate | Five lits + 5-slot callers | **Falsified** Named_xml sole plate |
| 8 | Domain load / I/O | Pure classify; no file ops | **Falsified** I/O claim |
| 9 | Dynamic extension list | Static once-init table | **Falsified** |
| 10 | Product name required | No symbol on VA | **Agree** structural `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 / one stack formal | **Confirmed** | Stack imbalance |
| Bucket 0..4 mapping | **Confirmed** | Wrong tally slot |
| OTHER default without strstr | **Confirmed** | Expect match on literal "OTHER" in path |
| Caller tally role | **High** | Mis-attribute host layout |
| Product English | **Open** | Naming only |
| Runtime | **Open** | No live capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04);
once: DAT_00d1f87c bit0; five basic_string; atexit;
loop: ESI = &DAT_00d1f7f4, stride 0x1c, EDI index;
strstr via IAT; fail → mov eax,4; ret 4;
match → mov eax,edi; ret 4.
```

### OTHER trap

Do **not** model `strstr(path, "OTHER")`. Paths that literally contain `"OTHER"` still return 4 only because no prior ext matched — coincidence, not string search.

### Haystack trap

Arg is **pointer-to-pointer** (or string object whose first field is c_str). Callers pass `&local_string` / object whose `+0` is char*. Null `*arg` becomes empty string, not crash.

### Substring trap

`foo.geometry` would match `.geo` — port must preserve CRT `strstr` unless product proof of suffix policy exists (none owned).

---

## 4. Surviving contract for AutoCore

```
AssPreloader_ExtBucketFromPath_Inferred(name_holder*):
  once-init table if needed
  hay = *name_holder || ""
  for i in 0..3:
    if strstr(hay, table[i].c_str()) return i
  return 4
  ret 4
```

Port as pure function over path string → enum/bucket. Wire to preloader tallies as index 0..4 only.

---

## 5. Open questions

1. Retail symbol.  
2. Intentional mid-path matches.  
3. Runtime.

**Verdict:** **accept-with-gaps**. Reject I/O / thiscall / OTHER-strstr / Named_xml-only overclaims.
