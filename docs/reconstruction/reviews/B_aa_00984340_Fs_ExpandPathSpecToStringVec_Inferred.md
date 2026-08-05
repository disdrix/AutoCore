# Review B (skeptical / adversarial): `aa_00984340` Fs_ExpandPathSpecToStringVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-E) |
| **Counterpart** | `reviews/A_aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | First stack formal is path | **Falsified** — bytes: EDI←arg2; `CMP [EDI],'@'`; recursive call order (out, path, flag) |
| 2 | ECX-thiscall method on AssPackManager | **Falsified** — cdecl 3 stack formals; bare RET; no pack host in formals |
| 3 | Always recursive directory walk | **Falsified** — recurse gated on `param_3`; else one-level list |
| 4 | Backslash is join separator | **Falsified** for join — `DAT_00a2eb5c`=`"/"`; `\` only in split/`strrchr` |
| 5 | Opens/reads file contents into pack | **Falsified** — only path strings; content work is other units |
| 6 | Name is PDB product | **Careful** — `_Inferred` structural only |
| 7 | Has external static callers | **Open risk** — only self-xref; may be fnptr / dead / tool CLI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl (out, path, flag) + return out | **High** | Wrong ABI in port |
| Branch matrix | **High** | Wrong expansion semantics |
| Separator `/` | **High** | Wrong path join |
| Zero external xrefs | **High** (observation) | Missing runtime invoker |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Entry: SEH; SUB ESP,0x1A8; EDI = path (arg2); CMP [EDI], '@'
// @path: FUN_009841d0(path+1) → for line: FUN_00984340(temp, line, flag)
// file:  push path
// glob:  list + FUN_0076b210 + join "/"
// dir+flag: FUN_009839b0(path, &collector)
// dir!flag: one-level join push
// Exit: FUN_00469d10 → MOV EAX,EBP; ADD ESP,0x1B4; RET
// Xrefs: only 009843e5 self-call
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Body end `C3` @ `0x009847bb` (1148 B).

---

## 4. Surviving contract for AutoCore

```
// Port as free function (cdecl), not AssPackManager method:
StringVector* ExpandPathSpec(StringVector* out, const char* spec, bool recurseDirs) {
  if (spec[0] == '@') { /* read list file; Expand each line */ }
  else if (!IsDirectory(spec)) {
    if (IsRegularFile(spec)) out->push_back(spec);
    else { /* glob against parent dir */ }
  } else if (recurseDirs) {
    DirRecurseCollectLeafPaths(spec, out);
  } else {
    /* one-level children */
  }
  return out;
}
// Preserve "/" join. Do not invent pack-host this pointer.
// Invocation path open (0 static external callers).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/branch matrix/separator. Residual product English + invoker path + nested list-reader plate → **accept-with-gaps**.
