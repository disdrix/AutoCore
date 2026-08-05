# Review B (skeptical / adversarial): `aa_009698a0` AssPathList_ListBasenames_FilterPush_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009698a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-B) |
| **Counterpart** | `reviews/A_aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md` |
| **Scratch** | `tmp/a_009698a0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `unaff_EDI` is decompiler noise / unused | **Falsified** — body reads `[edi+4/8/c]`; wrapper `mov edi,[esp+0x10]` |
| 2 | cdecl with only 3 args, no register formal | **Falsified** — `RET 0xC` + EDI out; wrapper preserves/restores EDI |
| 3 | Recurses directories | **Falsified** — only `FUN_0076b3f0` (flat basenames; W33-C sealed no recurse) |
| 4 | Pattern is `"/*"` like list-dir | **Falsified** — `DAT_00aa1d38` = `"*.*"` |
| 5 | Always pushes every basename | **Falsified** — filter gate on `type_filter` / class_id |
| 6 | `operator_delete` aborts function | **Falsified** — false-noreturn; continues outer loop / epilogue present |
| 7 | Path list is stack-only (no global) | **Partial** — body takes formal; wrapper injects `*DAT_00d1f1fc` |
| 8 | Pushes full paths | **Falsified** — basenames only then resolve to handle |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI out-vec ABI | **High** | Missed results / wrong register contract |
| RET 0xC / 3 stack args | **High** | Stack corruption |
| `"*.*"` + list basenames | **High** | Wrong enumeration |
| Filter polarity (`0` = all) | **High** | Over/under collect |
| Classifier product English | **Low** | Naming only |
| Handle type from 00989e00 | **Med** | Port type width |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against wrapper + body

```
// 0x00996aa0 thin wrapper:
mov  eax, [esp+8]          ; type_filter
mov  ecx, [esp+4]          ; classifier
mov  edx, [DAT_00d1f1fc]   ; path list global *
push edi
mov  edi, [esp+0x10]       ; out vec
push eax
push ecx
push edx
call FUN_009698a0
pop  edi
ret  0xC
```

Body capacity gate uses EDI shell layout matching MSVC `vector<void*>`-style dword vec (+4/+8/+0xc).

---

## 4. Surviving contract for AutoCore

```
// Port:
//   path_list: StringVec (stride 0x1c)
//   classifier: object with virtual Classify(handle*, int* out) @ vtbl+0x10
//   type_filter: 0 = accept all
//   out_ids: vector<handle> passed in EDI at call (wrapper sets from stack)
uint32_t AssPathList_ListBasenames_FilterPush(
    StringVecShell* path_list, void* classifier, int type_filter,
    PtrVecShell* out_ids /*EDI*/) {
  for (path : path_list) {
    auto names = ListDirBasenames(path + "*.*");
    for (name : names) {
      handle = ResolveName(0x00d1eac8, name);
      int class_id = classifier->Classify(handle);
      if (type_filter == 0 || class_id == type_filter)
        out_ids->push_back(handle);
    }
  }
  return 0;
}
// Do not invent recurse or full-path join inside this VA.
```

---

## 5. Verdict

**accept-with-gaps** — adversarial probes confirm EDI ABI and filter/list stages; product plates for classifier/resolve remain open (non-blocking for port skeleton).
